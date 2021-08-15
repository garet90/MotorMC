#pragma once
#include "../main.h"
#include "../listening/listening.h"
#include "../io/packet/packet.h"

typedef enum {

	job_keep_alive,
	job_global_chat_message,
	job_player_join,
	job_player_leave,
	job_send_update_pings,

	job_count

} job_type_t;

typedef struct {

	job_type_t type;
	bool_t repeating : 1;

} job_work_t;

typedef bool_t (*job_handler_t) (job_work_t*);

static inline void job_init_work(job_work_t* work, job_type_t type) {
	work->type = type;
	work->repeating = false;
}

void job_add_handler(job_type_t, job_handler_t);
void job_handle(job_work_t*);
void job_add(job_work_t*);

job_work_t* job_get();

void job_work();
