#pragma once
#include "../main.h"
#include "jobs.h"

bool_t job_handle_keep_alive(sky_worker_t*, job_keep_alive_t*);
bool_t job_handle_global_chat_message(sky_worker_t*, job_global_chat_message_t*);