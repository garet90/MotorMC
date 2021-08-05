#include "scheduler.h"
#include "../../motor.h"
#include "../../util/vector.h"
#include "../../util/linkedlist.h"

utl_vector_t sch_board = {
	.bytes_per_element = sizeof(utl_linked_list_t*)
};

void sch_push(sch_scheduled_t* scheduled, uint32_t delay) {

	void* null = NULL;
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

sch_scheduled_t* sch_schedule(job_work_t* job, uint32_t delay) {

	sch_scheduled_t* scheduled = malloc(sizeof(sch_scheduled_t));
	scheduled->job = job;
	scheduled->repeat = -1;
	scheduled->cancel = false;

	sch_push(scheduled, delay);

	return scheduled;

}

sch_scheduled_t* sch_schedule_repeating(job_work_t* job, uint32_t delay, uint32_t interval) {

	job->header |= JOB_REPEATING;

	sch_scheduled_t* scheduled = malloc(sizeof(sch_scheduled_t));
	scheduled->job = job;
	scheduled->repeat = interval;
	scheduled->cancel = false;

	sch_push(scheduled, delay);

	return scheduled;

}

void sch_tick() {

	// get schedule
	if (sch_board.size == 0) return;

	utl_linked_list_t* list = UTL_VECTOR_GET_AS(utl_linked_list_t*, &sch_board, 0);
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
