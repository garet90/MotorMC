#include "scheduler.h"
#include "../../motor.h"
#include "../../util/id_vector.h"
#include "../../util/vector.h"
#include "../../util/linked_list.h"
#include <pthread.h>

typedef struct {

	job_work_t* job;
	int32_t repeat;
	bool_t cancel : 1;

} sch_scheduled_t;

utl_vector_t sch_board = {
	.bytes_per_element = sizeof(utl_linked_list_t*)
};

utl_id_vector_t sch_scheduled = {
	.bytes_per_element = sizeof(sch_scheduled_t*)
};

void sch_push(sch_scheduled_t* scheduled, uint32_t delay) {

	const void* null = NULL;
	while (sch_board.size < delay) {
		utl_vector_push(&sch_board, &null);
	}

	if (sch_board.size == delay) {
		utl_linked_list_t* list = utl_create_list();
		utl_vector_push(&sch_board, &list);
	}

	utl_linked_list_t* list = UTL_VECTOR_GET_AS(utl_linked_list_t*, &sch_board, delay);

	if (list == NULL) {
		list = utl_create_list();
		utl_vector_set(&sch_board, delay, &list);
	}

	utl_list_push(list, scheduled);

}

sch_scheduled_t* sch_new(int32_t* id) {

	sch_scheduled_t* scheduled = malloc(sizeof(sch_scheduled_t));

	*id = utl_id_vector_add(&sch_scheduled, &scheduled);

	return scheduled;

}

int32_t sch_schedule(job_work_t* job, uint32_t delay) {

	int32_t id = -1;
	sch_scheduled_t* scheduled = sch_new(&id);
	scheduled->job = job;
	scheduled->repeat = -1;
	scheduled->cancel = false;

	sch_push(scheduled, delay);

	return id;

}

int32_t sch_schedule_repeating(job_work_t* job, uint32_t delay, uint32_t interval) {

	job->repeating = true;
	
	int32_t id = -1;
	sch_scheduled_t* scheduled = sch_new(&id);
	scheduled->job = job;
	scheduled->repeat = interval;
	scheduled->cancel = false;

	sch_push(scheduled, delay);

	return id;

}

void sch_cancel(int32_t id) {

	if (id < 0) return;

	sch_scheduled_t* scheduled = UTL_ID_VECTOR_GET_AS(sch_scheduled_t*, &sch_scheduled, id);
	scheduled->cancel = true;

	utl_id_vector_remove(&sch_scheduled, id);

}

void sch_tick() {

	utl_linked_list_t* list = NULL;
		
	// get schedule
	if (sch_board.size == 0) {	
		return;
	}

	list = UTL_VECTOR_GET_AS(utl_linked_list_t*, &sch_board, 0);
	utl_vector_shift(&sch_board);

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
