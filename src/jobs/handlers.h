#pragma once
#include "../main.h"
#include "jobs.h"

extern bool job_handle_keep_alive(job_keep_alive_t*);
extern bool job_handle_global_chat_message(job_global_chat_message_t*);
extern bool job_handle_player_join(job_player_join_t*);
extern bool job_handle_player_leave(job_player_leave_t*);
extern bool job_handle_send_update_pings(job_send_update_pings_t*);
extern bool job_handle_tick_chunk(job_tick_chunk_t*);
extern bool job_handle_unload_region(job_unload_region_t*);