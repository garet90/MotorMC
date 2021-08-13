#include "board.h"
#include "../motor.h"
#include "../util/linked_list.h"
#include "../util/vector.h"
#include "handlers.h"
#include <pthread.h>

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

utl_vector_t* job_handlers[job_count] = {
	&job_keep_alive_handlers_vector,
	&job_global_chat_message_handlers_vector,
	&job_player_join_handlers_vector,
	&job_player_leave_handlers_vector,
	&job_send_update_pings_handlers_vector
};

struct {
	pthread_cond_t cond;
	pthread_mutex_t lock;
} job_wait = {
	.cond = PTHREAD_COND_INITIALIZER,
	.lock = PTHREAD_MUTEX_INITIALIZER
};

struct {
	pthread_mutex_t lock;
	utl_linked_list_t list;
} job_board = {
	.lock = PTHREAD_MUTEX_INITIALIZER,
	.list = {
		.length = 0
	}
};

void job_init_work(job_work_t* job, uint32_t id) {

	job->type = id;
	for (size_t i = 0; i < sizeof(job->flags); ++i) {
		job->flags[i] = 0;
	}

}

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

	if (!utl_test_bit(work->flags, job_flag_repeating)) {
		free(work);
	}

}

void job_add(job_work_t* work) {

	if (work != NULL) {
		pthread_mutex_lock(&job_board.lock);

		utl_list_push(&job_board.list, work);

		pthread_mutex_unlock(&job_board.lock);
		
		pthread_cond_signal(&job_wait.cond);
	} else {
		pthread_cond_broadcast(&job_wait.cond);
	}

}

job_work_t* job_get() {

	pthread_mutex_lock(&job_board.lock);
	if (job_board.list.first == NULL) {
		pthread_mutex_unlock(&job_board.lock);

		// wait for jobs
		pthread_mutex_lock(&job_wait.lock);

		while (job_board.list.first == NULL) {
		
			if (sky_main.status == sky_stopping) {

				pthread_mutex_unlock(&job_wait.lock);

				return NULL;

			}

			pthread_cond_wait(&job_wait.cond, &job_wait.lock);
		
		}

		pthread_mutex_unlock(&job_wait.lock);

		if (sky_main.status == sky_stopping) {

			return NULL;

		}

		pthread_mutex_lock(&job_board.lock);
	}

	job_work_t* job = utl_list_shift(&job_board.list);
	pthread_mutex_unlock(&job_board.lock);

	return job;

}

void job_work() {

	job_handle(job_get());

}
