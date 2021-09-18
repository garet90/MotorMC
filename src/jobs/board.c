#include "board_private.h"
#include "handlers.h"
#include "../motor.h"
#include "../util/vector.h"

UTL_VECTOR_DEFAULT(job_keep_alive_handlers, job_handler_t, 
	(job_handler_t) job_handle_keep_alive
);
UTL_VECTOR_DEFAULT(job_global_chat_message_handlers, job_handler_t,
	(job_handler_t) job_handle_global_chat_message
);
UTL_VECTOR_DEFAULT(job_player_join_handlers, job_handler_t,
	(job_handler_t) job_handle_player_join
);
UTL_VECTOR_DEFAULT(job_player_leave_handlers, job_handler_t,
	(job_handler_t) job_handle_player_leave
);
UTL_VECTOR_DEFAULT(job_send_update_pings_handlers, job_handler_t,
	(job_handler_t) job_handle_send_update_pings
);
UTL_VECTOR_DEFAULT(job_tick_region_handlers, job_handler_t,
	(job_handler_t) job_handle_tick_region
);
UTL_VECTOR_DEFAULT(job_unload_region_handlers, job_handler_t,
	(job_handler_t) job_handle_unload_region,
);

UTL_VECTOR_DEFAULT(job_handlers, utl_vector_t*,
	&job_keep_alive_handlers,
	&job_global_chat_message_handlers,
	&job_player_join_handlers,
	&job_player_leave_handlers,
	&job_send_update_pings_handlers,
	&job_tick_region_handlers,
	&job_unload_region_handlers
);

job_board_t job_board = {
	.lock = PTHREAD_MUTEX_INITIALIZER,
	.wait = PTHREAD_COND_INITIALIZER,
	.list = UTL_LIST_INITIALIZER
};

void job_add_handler(job_type_t job, job_handler_t handler) {
	
	utl_vector_push(utl_vector_get(&job_handlers, job), &handler);

}

void job_handle(job_work_t* work) {

	if (work == NULL) return;

	utl_vector_t* work_handlers = UTL_VECTOR_GET_AS(utl_vector_t*, &job_handlers, work->type);

	if (work_handlers != NULL) {

		for (size_t i = 0; i < work_handlers->size; ++i) {

			job_handler_t handler = UTL_VECTOR_GET_AS(job_handler_t, work_handlers, i);
			if (!handler(work)) {
				break;
			}

		}

	}

	work->on_board--;

	job_free(work);

}

void job_add(job_work_t* work) {

	if (work != NULL) {

		work->on_board++;

		with_lock (&job_board.lock) {
			utl_list_push(&job_board.list, work);
		}

		pthread_cond_signal(&job_board.wait);
		
	} else {

		pthread_cond_broadcast(&job_board.wait);
	
	}

}

void job_free(job_work_t* work) {

	if (work->repeat) {
		return;
	}

	if (work->on_board != 0) {
		return;
	}

	free(work);

}

job_work_t* job_get() {

	job_work_t* job = NULL;

	// wait for jobs
	with_lock (&job_board.lock) {
	
		while (job_board.list.length == 0) {
		
			if (sky_main.status == sky_stopping) {

				pthread_mutex_unlock(&job_board.lock);

				return NULL;

			}

			pthread_cond_wait(&job_board.wait, &job_board.lock);
		
		}

		job = utl_list_shift(&job_board.list);

	}

	return job;

}

size_t job_get_count() {

	size_t length = 0;

	with_lock (&job_board.lock) {
		length = job_board.list.length;
	}

	return length;

}

void job_work() {

	job_handle(job_get());

}
