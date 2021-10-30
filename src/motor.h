#pragma once
#include <pthread.h>
#include "main.h"
#include "listening/listening.h"
#include "io/commands/commands.h"

// Workers do all the dirty work, all the things on the job board and the scheduler, but are not guaranteed any time to happen
typedef struct {

	pthread_t thread;
	uint16_t id;

} sky_worker_t;

/*
	Where we hold all the big bad information
*/
typedef struct {

	pthread_t console_thread;
	pthread_t thread;

	/* workers */
	struct {
		size_t count;
		utl_vector_t vector;
	} workers;

	string_t version;
	string_t mcver;
	cht_component_t* motd;
	
	cmd_sender_t console;
	
	/* Default world */
	struct {
		string_t name;
		int64_t seed;
		int16_t max_height;
	} world;

	uint32_t max_tick_time;
	
	/* listener */
	ltg_main_t listener;
	
	uint8_t render_distance : 6;
	
	const uint16_t protocol : 10;

	/*
		Starting = before done message
		Running  = after done message, before stop command
		Stopping = after stop command or failure
		Stopped  = after the server has been completely stopped
	*/
	enum {
		sky_starting,
		sky_running,
		sky_stopping,
		sky_stopped
	} status : 2;

	uint8_t op_permission_level : 3;

	enum {
		sky_peaceful,
		sky_easy,
		sky_normal,
		sky_hard
	} difficulty : 2;
	
	bool hardcore : 1;

	bool enable_respawn_screen : 1;
	bool enforce_whitelist : 1;
	bool enable_command_block : 1;
	bool pvp : 1;
	bool reduced_debug_info : 1;
	bool force_gamemode : 1;
	
	ent_gamemode_t gamemode : 2;

} sky_main_t;

extern sky_main_t sky_main;

int main(int, char*[]);

#define SKY_NANOS_PER_TICK 0x2FAF080
#define SKY_NANOS_PER_SECOND 0x3B9ACA00
#define SKY_SKIP_TICKS 25
extern void* t_sky_main(void*);
extern void* t_sky_worker(void*);

extern void sky_load_server_json();
extern void sky_gen_server_json();

extern void sky_term();

static inline uint64_t sky_to_nanos(const struct timespec time) {
	return (time.tv_sec * SKY_NANOS_PER_SECOND) + time.tv_nsec;
}