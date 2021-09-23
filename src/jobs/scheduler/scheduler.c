#include "scheduler.h"
#include "../board.h"
#include "../../motor.h"
#include "../../util/id_vector.h"
#include "../../util/vector.h"
#include <pthread.h>

struct {

	pthread_mutex_t lock;
	utl_vector_t tape;

} sch_scheduler = {
	.lock = PTHREAD_MUTEX_INITIALIZER,
	.tape = UTL_VECTOR_INITIALIZER(utl_vector_t)
};

static inline void sch_push_l(uint32_t id, uint32_t delay) {

	const utl_vector_t empty = UTL_VECTOR_INITIALIZER(uint32_t);

	while (delay >= sch_scheduler.tape.size) { // fill up to the delay with empty vectors

		utl_vector_push(&sch_scheduler.tape, &empty);
	
	}

	utl_vector_t* vector = utl_vector_get(&sch_scheduler.tape, delay);

	utl_vector_push(vector, &id);

}

static inline void sch_push(uint32_t id, uint32_t delay) {

	with_lock (&sch_scheduler.lock) {

		sch_push_l(id, delay);
		
	}

}

uint32_t sch_schedule(uint32_t id, uint32_t delay) {

	assert(delay != 0);

	sch_push(id, delay - 1);

	return id;

}

uint32_t sch_schedule_repeating(uint32_t id, uint32_t delay, uint32_t interval) {

	assert(delay != 0);
	assert(interval != 0);

	job_work_t* job = utl_id_vector_get(&job_board.heap.jobs, id);

	job->repeat = interval;

	sch_push(id, delay - 1);

	return id;

}

void sch_cancel(uint32_t id) {

	job_work_t* work = utl_id_vector_get(&job_board.heap.jobs, id);

	if (work == NULL) return;

	work->canceled = 1;

}

void sch_tick() {
	
	with_lock (&sch_scheduler.lock) {

		// get schedule
		if (sch_scheduler.tape.size == 0) {
			pthread_mutex_unlock(&sch_scheduler.lock);
			return;
		}

		utl_vector_t* vector = utl_vector_get(&sch_scheduler.tape, 0);

		if (vector->size > 0) {

			with_lock (&job_board.queue.lock) {

				for (uint32_t i = 0; i < vector->size; ++i) {

					uint32_t id = UTL_VECTOR_GET_AS(uint32_t, vector, i);

					job_work_t* scheduled = utl_id_vector_get(&job_board.heap.jobs, id);

					if (!scheduled->canceled) {

						utl_list_push(&job_board.queue.list, &id);

						if (scheduled->repeat) {

							sch_push_l(id, scheduled->repeat);

						}

					} else {

						scheduled->repeat = 0;
						job_free(id);

					}

				}

			}

			job_resume();

		}

		utl_term_vector(vector);
		utl_vector_shift(&sch_scheduler.tape);

	}

}
