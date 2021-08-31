#pragma once
#include "../main.h"
#include "../listening/listening.h"
#include "board.h"

#define JOB_CREATE_WORK(name, job_type) job_type ##_t* name = malloc(sizeof(job_type ##_t)); job_work_t name ##_init = { .type = job_type }; memcpy(name, &name ##_init, sizeof(job_work_t));

typedef struct {

	job_work_t header;

	ltg_client_t* client;

} job_keep_alive_t;

typedef struct {
	
	job_work_t header;

	ltg_client_t* sender;

	string_t message;

} job_global_chat_message_t;

typedef struct {

	job_work_t header;

	ltg_client_t* player;

} job_player_join_t;

typedef struct {

	job_work_t header;

	ltg_uuid_t uuid;
	string_t username;

} job_player_leave_t;

typedef struct {

	job_work_t header;

} job_send_update_pings_t;

typedef struct {

	job_work_t header;
	wld_chunk_t* chunk;

} job_tick_chunk_t;

typedef struct {

	job_work_t header;
	wld_region_t* region;

} job_unload_region_t;