#include "scheduler.h"
#include "../board_private.h"
#include "../../motor.h"
#include "../../util/id_vector.h"
#include "../../util/vector.h"
#include <pthread.h>

typedef struct {

	job_work_t* job;

	uint16_t interval;
	bool_t repeat;
	bool_t cancel;

} sch_scheduled_t;

struct {

	pthread_mutex_t lock;
	utl_vector_t tape;
	utl_id_vector_t elements;

} sch_scheduler = {
	.tape = {
		.bytes_per_element = sizeof(utl_vector_t)
	},
	.elements = {
		.bytes_per_element = sizeof(sch_scheduled_t)
	}
};

void sch_push_l(uint32_t id, uint32_t delay) {

	if (delay >= sch_scheduler.tape.size) { // fill up to the delay with empty vectors

		utl_vector_t empty = {
			.bytes_per_element = sizeof(uint32_t)
		};

		while (delay >= sch_scheduler.tape.size) {
			utl_vector_push(&sch_scheduler.tape, &empty);
		}
	
	}

	utl_vector_t* vector = utl_vector_get(&sch_scheduler.tape, delay);

	utl_vector_push(vector, &id);

}

inline void sch_push(uint32_t id, uint32_t delay) {

	with_lock (&sch_scheduler.lock) {

		sch_push_l(id, delay);
		
	}

}

sch_scheduled_t* sch_new_l(int32_t* id, sch_scheduled_t scheduled) {

	*id = utl_id_vector_add(&sch_scheduler.elements, &scheduled);

	return utl_id_vector_get(&sch_scheduler.elements, *id);

}

inline sch_scheduled_t* sch_new(int32_t* id, sch_scheduled_t scheduled) {

	sch_scheduled_t* ptr = NULL;

	with_lock (&sch_scheduler.lock) {
		ptr = sch_new_l(id, scheduled);
	}

	return ptr;

}

int32_t sch_schedule(job_work_t* job, uint32_t delay) {

	int32_t id = -1;
	with_lock (&sch_scheduler.lock) {
		sch_new_l(&id, (sch_scheduled_t) {
			.job = job,
			.repeat = false,
			.cancel = false
		});

		sch_push_l(id, delay);
	}

	return id;

}

int32_t sch_schedule_repeating(job_work_t* job, uint32_t delay, uint32_t interval) {

	job->repeating = true;
	
	int32_t id = -1;
	with_lock (&sch_scheduler.lock) {
		sch_new_l(&id, (sch_scheduled_t) {
			.job = job,
			.repeat = true,
			.interval = interval,
			.cancel = false
		});

		sch_push_l(id, delay);
	}

	return id;

}

void sch_cancel(int32_t id) {

	if (id < 0) return;

	with_lock (&sch_scheduler.lock) {
	
		sch_scheduled_t* scheduled = utl_id_vector_get(&sch_scheduler.elements, id);
		scheduled->cancel = true;
		
	}

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

				int32_t id = UTL_VECTOR_GET_AS(int32_t, vector, i);
				sch_scheduled_t* scheduled = utl_id_vector_get(&sch_scheduler.elements, i);

				if (!scheduled->cancel) {

					utl_list_push(&job_board.list, scheduled->job);

					if (scheduled->repeat) {

						sch_push_l(id, scheduled->interval);

					} else {

						utl_id_vector_remove(&sch_scheduler.elements, id);

					}

				} else {

					utl_id_vector_remove(&sch_scheduler.elements, id);

				}

			}

			pthread_cond_broadcast(&job_board.wait);

		}

		utl_vector_term(vector);
		utl_vector_shift(&sch_scheduler.tape);

	}

}
