#include "scheduler.h"
#include "../board_private.h"
#include "../../motor.h"
#include "../../util/id_vector.h"
#include "../../util/vector.h"
#include <pthread.h>

struct {

	pthread_mutex_t lock;
	utl_vector_t tape;

} sch_scheduler = {
	.tape = {
		.bytes_per_element = sizeof(utl_vector_t)
	}
};

void sch_push_l(job_work_t* work, uint32_t delay) {

	if (delay >= sch_scheduler.tape.size) { // fill up to the delay with empty vectors

		utl_vector_t empty = {
			.bytes_per_element = sizeof(job_work_t*)
		};

		while (delay >= sch_scheduler.tape.size) {
			utl_vector_push(&sch_scheduler.tape, &empty);
		}
	
	}

	utl_vector_t* vector = utl_vector_get(&sch_scheduler.tape, delay);

	utl_vector_push(vector, &work);

}

inline void sch_push(job_work_t* work, uint32_t delay) {

	with_lock (&sch_scheduler.lock) {

		sch_push_l(work, delay);
		
	}

}

job_work_t* sch_schedule(job_work_t* job, uint32_t delay) {

	assert(delay != 0);

	sch_push(job, delay - 1);

	return job;

}

job_work_t* sch_schedule_repeating(job_work_t* job, uint32_t delay, uint32_t interval) {

	assert(delay != 0);
	assert(interval != 0);

	job->repeat = interval;
	
	sch_push(job, delay - 1);

	return job;

}

void sch_cancel(job_work_t* work) {

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

		with_lock (&job_board.lock) {

			for (uint32_t i = 0; i < vector->size; ++i) {

				job_work_t* scheduled = UTL_VECTOR_GET_AS(job_work_t*, vector, i);

				if (!scheduled->canceled) {

					utl_list_push(&job_board.list, scheduled);

					if (scheduled->repeat) {

						sch_push_l(scheduled, scheduled->repeat);

					}

				} else {

					scheduled->repeat = 0;
					job_free(scheduled);

				}

			}

			pthread_cond_broadcast(&job_board.wait);

		}

		utl_vector_term(vector);
		utl_vector_shift(&sch_scheduler.tape);

	}

}
