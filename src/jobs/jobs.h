#pragma once
#include "../main.h"
#include "board.h"

#define JOB_CREATE_WORK(name, job_type) job_type ##_t* name = malloc(sizeof(job_type ##_t)); job_init_work((job_work_t*) name, job_type);

typedef struct {

	job_work_t header;

	ltg_client_t* client;

} job_keep_alive_t;

typedef struct {
	
	job_work_t header;

	ltg_client_t* sender;

	struct {
		
		char value[1025];
		size_t length : 10;

	} message;

} job_global_chat_message_t;

typedef struct {

	job_work_t header;

	ltg_client_t* player;

} job_player_join_t;

typedef struct {

	job_work_t header;

	ltg_uuid_t uuid;
	char username[17];

} job_player_leave_t;

typedef struct {

	job_work_t header;

} job_send_update_pings_t;