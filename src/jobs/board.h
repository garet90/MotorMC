#pragma once
#include "../main.h"
#include "../motor.h"
#include "../listening/listening.h"
#include "../io/packet/packet.h"

#define JOB_NORMAL 0x00
#define JOB_REPEATING 0x01

typedef struct {

	uint32_t type;
	uint32_t header;

} job_work_t;

typedef bool_t (*job_handler_t) (sky_worker_t*, job_work_t*);

job_work_t* job_create_work(uint32_t);
void job_init_work(job_work_t*, uint32_t);

void job_add_handler(uint32_t, job_handler_t);
void job_handle(sky_worker_t*, job_work_t*);
void job_add(job_work_t*);

job_work_t* job_get();

void job_work(sky_worker_t*);
