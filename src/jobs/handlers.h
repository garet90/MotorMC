#pragma once
#include "../main.h"
#include "jobs.h"

extern bool_t job_handle_keep_alive(sky_worker_t*, job_keep_alive_t*);
extern bool_t job_handle_global_chat_message(sky_worker_t*, job_global_chat_message_t*);
extern bool_t job_handle_player_join(sky_worker_t*, job_player_join_t*);
extern bool_t job_handle_player_leave(sky_worker_t*, job_player_leave_t*);