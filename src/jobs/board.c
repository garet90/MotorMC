#include "board_private.h"
#include "handlers.h"
#include "../motor.h"
#include "../util/vector.h"

// vector of vectors that point to job handlers, the index is the job
job_handler_t job_keep_alive_handlers[] = {
	(job_handler_t) job_handle_keep_alive
};
utl_vector_t job_keep_alive_handlers_vector = {
	.bytes_per_element = sizeof(job_handler_t),
	.size = 1,
	.array = (byte_t*) job_keep_alive_handlers
};

job_handler_t job_global_chat_message_handlers[] = {
	(job_handler_t) job_handle_global_chat_message
};
utl_vector_t job_global_chat_message_handlers_vector = {
	.bytes_per_element = sizeof(job_handler_t),
	.size = 1,
	.array = (byte_t*) job_global_chat_message_handlers
};

job_handler_t job_player_join_handlers[] = {
	(job_handler_t) job_handle_player_join
};
utl_vector_t job_player_join_handlers_vector = {
	.bytes_per_element = sizeof(job_handler_t),
	.size = 1,
	.array = (byte_t*) job_player_join_handlers
};

job_handler_t job_player_leave_handlers[] = {
	(job_handler_t) job_handle_player_leave
};
utl_vector_t job_player_leave_handlers_vector = {
	.bytes_per_element = sizeof(job_handler_t),
	.size = 1,
	.array = (byte_t*) job_player_leave_handlers
};

job_handler_t job_send_update_pings_handlers[] = {
	(job_handler_t) job_handle_send_update_pings
};
utl_vector_t job_send_update_pings_handlers_vector = {
	.bytes_per_element = sizeof(job_handler_t),
	.size = 1,
	.array = (byte_t*) job_send_update_pings_handlers
};

job_handler_t job_tick_chunk_handlers[] = {
	(job_handler_t) job_handle_tick_chunk
};
utl_vector_t job_tick_chunk_handlers_vector = {
	.bytes_per_element = sizeof(job_handler_t),
	.size = 1,
	.array = (byte_t*) job_tick_chunk_handlers
};

job_handler_t job_unload_region_handlers[] = {
	(job_handler_t) job_unload_region
};
utl_vector_t job_unload_region_handlers_vector = {
	.bytes_per_element = sizeof(job_handler_t),
	.size = 1,
	.array = (byte_t*) job_unload_region_handlers
};

utl_vector_t* job_handlers[job_count] = {
	&job_keep_alive_handlers_vector,
	&job_global_chat_message_handlers_vector,
	&job_player_join_handlers_vector,
	&job_player_leave_handlers_vector,
	&job_send_update_pings_handlers_vector,
	&job_tick_chunk_handlers_vector,
	&job_unload_region_handlers_vector
};

job_board_t job_board = {
	.lock = PTHREAD_MUTEX_INITIALIZER,
	.wait = PTHREAD_COND_INITIALIZER,
	.list = {
		.length = 0
	}
};

void job_add_handler(job_type_t job, job_handler_t handler) {
	
	if (job_handlers[job] == NULL) {
		job_handlers[job] = utl_create_vector(sizeof(job_handler_t), 2);
	}

	utl_vector_push(job_handlers[job], &handler);

}

void job_handle(job_work_t* work) {

	if (work == NULL) return;

	utl_vector_t* work_handlers = job_handlers[work->type];

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
	
		while (job_board.list.first == NULL) {
		
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
