#pragma once
#include <pthread.h>
#include "main.h"
#include "listening/listening.h"
#include "io/commands/commands.h"

typedef struct {

	pthread_t thread;
	uint16_t id;

} sky_worker_t;

typedef enum {
	sky_starting = 0,
	sky_running = 1,
	sky_stopping = 2,
	sky_stopped = 3
} sky_status_t;

typedef enum {
	sky_peaceful = 0,
	sky_easy = 1,
	sky_normal = 2,
	sky_hard = 3
} sky_difficulty_t;

typedef struct {

	pthread_t console_thread;
	pthread_t thread;

	/* workers */
	struct {
		size_t count;
		utl_vector_t vector;
	} workers;

	const char* version;
	const char* mcver;
	cht_component_t* motd;
	
	cmd_sender_t console;
	
	/* Default world */
	struct {
		const char* name;
		int64_t seed;
		uint16_t max_height;
	} world;

	const uint16_t protocol;

	uint32_t max_tick_time;
	
	/* listener */
	ltg_main_t listener;
	
	uint8_t render_distance;

	sky_status_t status : 2;
	cmd_op_level_t op_permission_level : 3;

	struct {
		sky_difficulty_t level : 2;
		bool_t hardcore : 1;
	} difficulty;

	bool_t enable_respawn_screen : 1;
	bool_t enforce_whitelist : 1;
	bool_t enable_command_block : 1;
	bool_t pvp : 1;
	bool_t reduced_debug_info : 1;
	
	ent_gamemode_t gamemode : 2;

} sky_main_t;

extern sky_main_t sky_main;

int main(int, char*[]);

#define SKY_NANOS_PER_TICK 0x2FAF080
#define SKY_NANOS_PER_SECOND 0x3B9ACA00
#define SKY_SKIP_TICKS 25
extern void* t_sky_main(void*);
extern void* t_sky_worker(void*);

extern void __attribute__((noreturn)) sky_term();

static inline uint64_t sky_to_nanos(const struct timespec time) {
	return (time.tv_sec * SKY_NANOS_PER_SECOND) + time.tv_nsec;
}