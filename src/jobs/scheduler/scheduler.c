#include "scheduler.h"
#include "../../motor.h"
#include "../../util/id_vector.h"
#include "../../util/vector.h"
#include "../../util/linkedlist.h"
#include <pthread.h>

typedef struct {

	job_work_t* job;
	int32_t repeat;
	bool_t cancel;

} sch_scheduled_t;

struct {
	utl_vector_t elements;
	pthread_mutex_t lock;
} sch_board = {
	.elements = {
		.bytes_per_element = sizeof(utl_linked_list_t*)
	},
	.lock = PTHREAD_MUTEX_INITIALIZER
};

struct {
	utl_id_vector_t elements;
	pthread_mutex_t lock;
} sch_scheduled = {
	.elements = {
		.bytes_per_element = sizeof(sch_scheduled_t*)
	},
	.lock = PTHREAD_MUTEX_INITIALIZER
};

void sch_push(sch_scheduled_t* scheduled, uint32_t delay) {

	pthread_mutex_lock(&sch_board.lock);

	void* null = NULL;
	while (sch_board.elements.size < delay) {
		utl_vector_push(&sch_board.elements, &null);
	}

	if (sch_board.elements.size == delay) {
		utl_linked_list_t* list = utl_create_list();
		utl_vector_push(&sch_board.elements, &list);
	}

	utl_linked_list_t* list = UTL_VECTOR_GET_AS(utl_linked_list_t*, &sch_board.elements, delay);

	if (list == NULL) {
		list = utl_create_list();
		utl_vector_set(&sch_board.elements, delay, &list);
	}

	utl_list_push(list, scheduled);

	pthread_mutex_unlock(&sch_board.lock);

}

sch_scheduled_t* sch_new(int32_t* id) {

	sch_scheduled_t* scheduled = malloc(sizeof(sch_scheduled_t));

	pthread_mutex_lock(&sch_scheduled.lock);

	*id = utl_id_vector_add(&sch_scheduled.elements, &scheduled);

	pthread_mutex_unlock(&sch_scheduled.lock);

	return scheduled;

}

int32_t sch_schedule(job_work_t* job, uint32_t delay) {

	int32_t id;
	sch_scheduled_t* scheduled = sch_new(&id);
	scheduled->job = job;
	scheduled->repeat = -1;
	scheduled->cancel = false;

	sch_push(scheduled, delay);

	return id;

}

int32_t sch_schedule_repeating(job_work_t* job, uint32_t delay, uint32_t interval) {

	utl_set_bit(job->flags, job_flag_repeating);

	int32_t id;
	sch_scheduled_t* scheduled = sch_new(&id);
	scheduled->job = job;
	scheduled->repeat = interval;
	scheduled->cancel = false;

	sch_push(scheduled, delay);

	return id;

}

void sch_cancel(int32_t id) {

	if (id < 0) return;

	pthread_mutex_lock(&sch_scheduled.lock);

	sch_scheduled_t* scheduled = UTL_ID_VECTOR_GET_AS(sch_scheduled_t*, &sch_scheduled.elements, id);
	scheduled->cancel = true;

	utl_id_vector_remove(&sch_scheduled.elements, id);

	pthread_mutex_unlock(&sch_scheduled.lock);

}

void sch_tick() {

	pthread_mutex_lock(&sch_board.lock);

	// get schedule
	if (sch_board.elements.size == 0) {
		pthread_mutex_unlock(&sch_board.lock);	
		return;
	}

	utl_linked_list_t* list = UTL_VECTOR_GET_AS(utl_linked_list_t*, &sch_board.elements, 0);
	utl_vector_shift(&sch_board.elements);

	pthread_mutex_unlock(&sch_board.lock);

	if (list == NULL) {
		return;
	}

	for (uint32_t i = 0; i < list->length; ++i) {

		sch_scheduled_t* scheduled = utl_list_shift(list);

		if (!scheduled->cancel) {

			if (scheduled->repeat >= 0) {

				job_add(scheduled->job);
				sch_push(scheduled, scheduled->repeat);

			} else {

				job_add(scheduled->job);
				free(scheduled);

			}

		} else {

			free(scheduled->job);
			free(scheduled);

		}

	}

	free(list);

}
