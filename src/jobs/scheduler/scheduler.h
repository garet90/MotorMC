#pragma once
#include "../../main.h"
#include "../board.h"

/*
Schedule a job to be done at a specific time
1 delay = next available tick
*/
extern job_work_t* sch_schedule(job_work_t* work, uint32_t delay);
/*
Schedule a job to be repeated every 'repeat' ticks
1 delay = next available tick
*/
extern job_work_t* sch_schedule_repeating(job_work_t* work, uint32_t delay, uint32_t repeat);

extern void sch_cancel(job_work_t* work);

extern void sch_tick();
