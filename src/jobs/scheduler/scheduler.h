#pragma once
#include "../../main.h"

/*
Schedule a job to be done at a specific time
1 delay = next available tick
*/
extern uint32_t sch_schedule(uint32_t id, uint32_t delay);
/*
Schedule a job to be repeated every 'repeat' ticks
1 delay = next available tick
*/
extern uint32_t sch_schedule_repeating(uint32_t id, uint32_t delay, uint32_t repeat);

extern void sch_cancel(uint32_t id);

extern void sch_tick();
