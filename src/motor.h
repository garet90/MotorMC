#pragma once
#include <pthread.h>
#include "main.h"
#include "listening/listening.h"
#include "io/commands/commands.h"

typedef struct {

	uint8_t instruction;

} sky_instruction_t;

typedef struct {

	pthread_t thread;
	pthread_mutex_t world_lock;
	uint16_t id;

} sky_worker_t;

typedef enum {
	sky_starting = 0,
	sky_running = 1,
	sky_stopping = 2,
	sky_stopped = 3
} sky_status_t;

typedef struct {

	pthread_t thread;

	/* instructions */
	struct {
		pthread_mutex_t lock;
		utl_vector_t vector;
	} instructions;

	/* entities */
	struct {
		utl_vector_t vector;
		/* next entity id */
		utl_vector_t nextID;
	} entities;

	/* workers */
	struct {
		size_t count;
		utl_vector_t vector;
	} workers;

	const char* version;
	const char* mcver;
	cht_component_t* motd;
	
	/* worlds */
	utl_vector_t worlds;
	
	cmd_sender_t console;
	
	/* Default world */
	struct {
		const char* name;
		int64_t seed;
		uint16_t max_height;
	} world;

	const uint16_t protocol;

	sky_status_t status;
	cmd_op_level_t op_permission_level;

	bool_t hardcore;
	uint8_t gamemode;
	uint8_t render_distance;
	bool_t reduced_debug_info;

	uint32_t max_tick_time;

	bool_t enable_respawn_screen;
	bool_t enforce_whitelist;
	bool_t enable_command_block;
	bool_t pvp;
	
	/* listener */
	ltg_main_t listener;

} sky_main_t;

extern sky_main_t sky_main;

int main(int, char*[]);

#define SKY_NANOS_PER_TICK 0x2FAF080
#define SKY_NANOS_PER_SECOND 0x3B9ACA00
#define SKY_SKIP_TICKS 25
extern void* t_sky_main(void*);
extern void* t_sky_worker(void*);

extern void __attribute__ ((noreturn)) sky_term();

static inline uint64_t sky_toNanos(const struct timespec time) {
	return (time.tv_sec * SKY_NANOS_PER_SECOND) + time.tv_nsec;
}