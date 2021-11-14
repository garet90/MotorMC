#pragma once

typedef struct sky_worker sky_worker_t;

/*
	Starting = before done message
	Running  = after done message, before stop command
	Stopping = after stop command or failure
	Stopped  = after the server has been completely stopped
*/
typedef enum {
	sky_starting,
	sky_running,
	sky_stopping,
	sky_stopped
} sky_status_t;

typedef enum {
	sky_peaceful,
	sky_easy,
	sky_normal,
	sky_hard
} sky_difficulty_t;

typedef struct sky_main sky_main_t;