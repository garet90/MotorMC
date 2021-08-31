#pragma once
#include "../main.h"

typedef enum {

	job_keep_alive,
	job_global_chat_message,
	job_player_join,
	job_player_leave,
	job_send_update_pings,
	job_tick_chunk,
	job_unload_region,

	job_count

} job_type_t;

typedef struct {

	const job_type_t type : 8;
	uint8_t _Atomic repeat;
	uint8_t _Atomic on_board;
	uint8_t _Atomic canceled;

} job_work_t;

typedef bool_t (*job_handler_t) (job_work_t*);

extern void job_add_handler(job_type_t, job_handler_t);
extern void job_handle(job_work_t*);
extern void job_add(job_work_t*);
extern void job_free(job_work_t*);

extern job_work_t* job_get();

extern size_t job_get_count();

extern void job_work();
