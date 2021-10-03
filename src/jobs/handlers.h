#pragma once
#include "../main.h"
#include "board.h"

extern bool job_handle_keep_alive(job_payload_t* payload);
extern bool job_handle_global_chat_message(job_payload_t* payload);
extern bool job_handle_player_join(job_payload_t* payload);
extern bool job_handle_player_leave(job_payload_t* payload);
extern bool job_handle_send_update_pings(job_payload_t* payload);
extern bool job_handle_tick_region(job_payload_t* payload);
extern bool job_handle_unload_region(job_payload_t* payload);
extern bool job_handle_dig_block(job_payload_t* payload);