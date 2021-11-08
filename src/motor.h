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
	ltg_listener_t listener;
	
	uint16_t network_compression_threshold;
	
	uint8_t render_distance : 6;
	
	const uint16_t protocol : 10;

	sky_status_t status : 2;

	uint8_t op_permission_level : 3;

	sky_difficulty_t difficulty : 2;
	
	bool hardcore : 1;

	bool enable_respawn_screen : 1;
	bool enforce_whitelist : 1;
	bool enable_command_block : 1;
	bool pvp : 1;
	bool reduced_debug_info : 1;
	bool force_gamemode : 1;

	bool online_mode : 1;
	bool prevent_proxy_connections : 1;
	
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

static inline cht_component_t* sky_get_motd() {
	return sky_main.motd;
}

static inline void sky_set_motd(cht_component_t* component) {
	if (sky_main.motd != NULL) {
		cht_free(sky_main.motd);
	}
	sky_main.motd = component;
}

static inline cmd_sender_t sky_get_console() {
	return sky_main.console;
}

static inline ltg_listener_t* sky_get_listener() {
	return &sky_main.listener;
}

static inline uint8_t sky_get_render_distance() {
	return sky_main.render_distance;
}

static inline uint16_t sky_get_protocol() {
	return sky_main.protocol;
}

static inline sky_status_t sky_get_status() {
	return sky_main.status;
}

static inline uint8_t sky_get_op_permission_level() {
	return sky_main.op_permission_level;
}

static inline sky_difficulty_t sky_get_difficulty() {
	return sky_main.difficulty;
}

static inline void sky_set_difficulty(sky_difficulty_t difficulty) {
	sky_main.difficulty = difficulty;
}

static inline bool sky_is_hardcore() {
	return sky_main.hardcore;
}

static inline void sky_set_hardcore(bool hardcore) {
	sky_main.hardcore = hardcore;
}

static inline ent_gamemode_t sky_get_default_gamemode() {
	return sky_main.gamemode;
}

static inline bool sky_is_force_gamemode() {
	return sky_main.force_gamemode;
}

static inline bool sky_is_reduced_debug_info() {
	return sky_main.reduced_debug_info;
}

static inline bool sky_is_enabled_respawn_screen() {
	return sky_main.enable_respawn_screen;
}

static inline pthread_t sky_get_main_thread() {
	return sky_main.thread;
}

static inline pthread_t sky_get_console_thread() {
	return sky_main.console_thread;
}

static inline bool sky_is_online_mode() {
	return sky_main.online_mode;
}

static inline bool sky_is_prevent_proxy_connections() {
	return sky_main.prevent_proxy_connections;
}

static inline uint16_t sky_get_network_compression_threshold() {
	return sky_main.network_compression_threshold;
}