#include "board.h"
#include "../util/linkedlist.h"
#include "../util/vector.h"
#include <pthread.h>

// vector of vectors that point to job handlers, the index is the job
utl_vector_t job_handlers = {
		.bytes_per_element = sizeof(utl_vector_t*)
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

job_work_t* job_createWork(uint32_t job) {

	job_work_t* work = malloc(sizeof(job_work_t));
	job_initWork(work, job);

	return work;

}

void job_initWork(job_work_t* job, uint32_t id) {

	job->type = id;
	job->header = JOB_NORMAL;

}

void job_addHandler(uint32_t job, job_handler_t handler) {

	while (job_handlers.size <= job) {
		utl_vector_t* handlers = utl_createVector(sizeof(job_handler_t), 2);
		utl_vectorPush(&job_handlers, &handlers);
	}

	utl_vector_t* handlers = utl_vectorGetAs(utl_vector_t*, &job_handlers, job);
	utl_vectorPush(handlers, &handler);

}

void job_handle(sky_worker_t* worker, job_work_t* work) {

	if (work == NULL) return;

	utl_vector_t* handlers = utl_vectorGetAs(utl_vector_t*, &job_handlers, work->type);

	if (handlers != NULL) {

		for (uint32_t i = 0; i < handlers->size; ++i) {

			job_handler_t handler = utl_vectorGetAs(job_handler_t, handlers, i);
			if (!handler(worker, work)) {
				break;
			}

		}

	}

	if (!(work->header & JOB_REPEATING)) {
		free(work);
	}

}

void job_add(job_work_t* work) {

	if (work != NULL) {
		pthread_mutex_lock(&job_board.lock);

		utl_listPush(&job_board.list, work);

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

	job_work_t* job = utl_listShift(&job_board.list);
	pthread_mutex_unlock(&job_board.lock);

	return job;

}

void job_work(sky_worker_t* worker) {

	job_handle(worker, job_get());

}
