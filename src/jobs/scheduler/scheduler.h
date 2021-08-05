#pragma once
#include "../../main.h"
#include "../board.h"

typedef struct {

	job_work_t* job;
	int32_t repeat;
	bool_t cancel;

} sch_scheduled_t;

extern void sch_push(sch_scheduled_t*, uint32_t);

extern sch_scheduled_t* sch_schedule(job_work_t*, uint32_t);
extern sch_scheduled_t* sch_schedule_repeating(job_work_t*, uint32_t, uint32_t);

extern void sch_tick();
