#pragma once
#include "../../main.h"
#include "../board.h"

extern int32_t sch_schedule(job_work_t*, uint32_t);
extern int32_t sch_schedule_repeating(job_work_t*, uint32_t, uint32_t);

extern void sch_cancel(int32_t);

extern void sch_tick();
