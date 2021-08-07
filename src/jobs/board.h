#pragma once
#include "../main.h"
#include "../motor.h"
#include "../listening/listening.h"
#include "../io/packet/packet.h"
#include "../util/bitset.h"

typedef enum {

	job_flag_repeating,

	job_flag_count

} job_flags_t;

typedef enum {

	job_keep_alive,

	job_count

} job_type_t;

typedef struct {

	job_type_t type;
	utl_bitset(job_flag_count, flags);

} job_work_t;

typedef struct {

	job_work_t header;

	ltg_client_t* client;

} job_keep_alive_t;

#define JOB_CREATE_WORK(name, job_type) job_type ##_t* name = malloc(sizeof(job_type ##_t)); name->header.type = job_type; memset(name->header.flags, 0, sizeof(name->header.flags));

typedef bool_t (*job_handler_t) (sky_worker_t*, job_work_t*);

void job_init_work(job_work_t*, uint32_t);

void job_add_handler(job_type_t, job_handler_t);
void job_handle(sky_worker_t*, job_work_t*);
void job_add(job_work_t*);

job_work_t* job_get();

void job_work(sky_worker_t*);
