#define _POSIX_C_SOURCE 200809L

#include <time.h>
#include <curl/curl.h>
#include "motor.h"
#include <signal.h>
#include "jobs/board.h"
#include "jobs/handlers.h"
#include "jobs/scheduler/scheduler.h"
#include "util/ansi_escapes.h"
#include "util/util.h"
#include "plugin/manager.h"
#include "io/chat/chat.h"
#include "io/filesystem/filesystem.h"
#include "io/json/mjson.h"
#include "world/world.h"
#include "world/material/material.h"
#include "test/tests.h"

sky_main_t sky_main = {
	.protocol = __MC_PRO__,
	.version = UTL_CSTRTOSTR(__MOTOR_VER__),
	.mcver = UTL_CSTRTOSTR(__MC_VER__),
	.console = {
		.type = cmd_console,
		.op = 4
	},
	.workers = {
		.count = 4,
		.vector = UTL_VECTOR_INITIALIZER(sky_worker_t*)
	},
	.status = sky_starting,
	
	.world = {
		.name = UTL_CSTRTOSTR("world"),
		.seed = 0
	},

	.difficulty = sky_easy,
	.hardcore = false,

	.render_distance = 10,

	.network_compression_threshold = 256,
	.online_mode = true,
	.prevent_proxy_connections = false,

	// listener
	.listener = {
		.address = {
			.port = 25565
		},
		.clients = {
			.lock = PTHREAD_MUTEX_INITIALIZER,
			.vector = UTL_ID_VECTOR_INITIALIZER(ltg_client_t*)
		},
		.online = {
			.lock = PTHREAD_MUTEX_INITIALIZER,
			.vector = UTL_ID_VECTOR_INITIALIZER(ltg_client_t*),
			.max = 20
		}
	}

};

// signal handlers
void sky_handle_signal_terminate(__attribute__((unused)) int signal) {
	exit(0);
}

void sky_handle_signal_crash(int signal) {
	log_error("!!!!THE SERVER HAS CRASHED FATALLY!!!!");
	log_error("BEGIN CRASH REPORT");
	log_error("\tVERSION " __MOTOR_VER__);
	log_error("\tMCVER " __MC_VER__);
	log_error("\tCOMPILED " __DATE__ " " __TIME__);
	log_error("\tCODE 0x%04x", signal);
	switch (signal) {
		case SIGFPE: {
			log_error("\t\tFLOATING POINT EXCEPTION");
		} break;
		case SIGILL: {
			log_error("\t\tILLEGAL INSTRUCTION");
		} break;
		case SIGSEGV: {
			log_error("\t\tSEGMENTATION FAULT");
		} break;
		default: {
			// Do nothing
		} break;
	}
	log_error("\tTHREAD #%llx", pthread_self());
	if (pthread_self() == sky_get_console_thread()) {
		log_error("\t\tCONSOLE THREAD");
	} else if (pthread_self() == sky_get_main_thread()) {
		log_error("\t\tMAIN THREAD");
	} else if (pthread_self() == ltg_get_thread(sky_get_listener())) {
		log_error("\t\tLISTENER THREAD");
	} else {
		for (size_t i = 0; i < sky_main.workers.vector.size; ++i) {
			sky_worker_t* worker = UTL_VECTOR_GET_AS(sky_worker_t*, &sky_main.workers.vector, i);
			if (pthread_self() == worker->thread) {
				log_error("\t\tWORKER #%lld", i);
				log_error("\tJOB TYPE %d", job_get_type(worker->job));
				goto identified;
			}
		}

		for (size_t i = 0; i < ltg_get_client_count(sky_get_listener()); ++i) {
			ltg_client_t* client = ltg_get_client_by_id(sky_get_listener(), i);
			if (client != NULL && pthread_self() == ltg_client_get_thread(client)) {
				log_error("\t\tCLIENT #%lld", i);
				log_error("\tCLIENT STATE %u", ltg_client_get_state(client));
				log_error("\tENCRYPTION ENABLED %d", ltg_client_is_encryption_enabled(client));
				goto identified;
			}
		}

		log_error("\t\tUNKNOWN THREAD");
	}

	identified: {
		log_error("REPORT THIS CRASH TO MOTORMC ALONG WITH THE STEPS TO REPRODUCE IT");
		abort();
	}
}

int main(int argc, char* argv[]) {

	// add signal handlers
	signal(SIGFPE, sky_handle_signal_crash);
	signal(SIGILL, sky_handle_signal_crash);
	signal(SIGINT, sky_handle_signal_terminate);
	signal(SIGSEGV, sky_handle_signal_crash);
	signal(SIGTERM, sky_handle_signal_terminate);
#ifdef SIGPIPE
	signal(SIGPIPE, SIG_IGN);
#endif

	sky_main.console_thread = pthread_self();

	struct timespec start;
	clock_gettime(CLOCK_REALTIME, &start);

	utl_setup_console();

	log_info("//      //  //////  //////  //////  //////");
	log_info("////  ////  //  //    //    //  //  //  //");
	log_info("// //// //  //  //    //    //  //  //////");
	log_info("//  //  //  //  //    //    //  //  // // ");
	log_info("//      //  //////    //    //////  //  MC");
	log_info(__MOTOR_VER__);
	log_info("");

	/*
		The MotorMC project was started officially on June 2, 2021
		by Garet Halliday
	*/

#ifdef __MOTOR_UNSAFE__
	log_warn("You are using an unsafe version of MotorMC! This version may have game breaking bugs or experimental features and should not be used for production servers!");
	log_info("");
#endif

	// encryption / login setup
	curl_global_init(CURL_GLOBAL_DEFAULT);

	// run tests if args includes "test"
	for (int i = 1; i < argc; ++i) {
		switch (utl_hash(argv[i])) {
			case 0x7c9e6865: {
				return test_run_all();
			} break;
			default: {
				// do nothing
				log_warn("Unknown argument: %s", argv[i]);
			} break;
		}
	}

	// use sky_term at exit, makes it so exit can be called anywhere easily
	atexit(sky_term);

	if (fs_file_exists("server.json")) {

		sky_load_server_json();

	} else {
		// generate server.json

		log_info("server.json not found! Generating one...");
		
		sky_gen_server_json();

	}

	// setup motd if null
	if (sky_main.motd == NULL) {

		sky_main.motd = cht_alloc();
		sky_main.motd->text = UTL_CSTRTOSTR("A Minecraft server");

	}

	// load startup plugins
	plg_on_startup();

	// load main world
	if (fs_dir_exists(UTL_STRTOCSTR(sky_main.world.name))) {
		log_info("Loading world \"%s\"...", UTL_STRTOCSTR(sky_main.world.name));
		wld_load(sky_main.world.name);
	} else {
		log_info("Generating world \"%s\"...", UTL_STRTOCSTR(sky_main.world.name));
		wld_new(sky_main.world.name, (sky_main.world.seed == 0 ? time(NULL) : sky_main.world.seed), mat_dimension_overworld);
	}

	// load postworld plugins
	plg_on_postworld();

	// initiate socket
	ltg_init(sky_get_listener());

	// we're ready for takeoff
	sky_main.status = sky_running;

	// start main thread
	pthread_create(&sky_main.thread, NULL, t_sky_main, NULL);

	// create worker threads
	for (size_t i = 0; i < sky_main.workers.count; ++i) {

		sky_worker_t* worker = malloc(sizeof(sky_worker_t));
		worker->id = i;

		utl_vector_push(&sky_main.workers.vector, &worker);

		pthread_create(&worker->thread, NULL, t_sky_worker, worker);

	}

	struct timespec time_now;
	clock_gettime(CLOCK_REALTIME, &time_now);
	log_info("Done (%.3fs)! For help type 'help'", ((time_now.tv_sec * SKY_NANOS_PER_SECOND + time_now.tv_nsec) - (start.tv_sec * SKY_NANOS_PER_SECOND + start.tv_nsec)) / 1000000000.0f);

	// enter console loop, threads are started and such, nothing else needs to be done on this thread
	char in[256];
	for (;;) {
		if (fgets(in, 256, stdin) != NULL) {

			cmd_handle(in, &sky_main.console);

		}
	}

}

void* t_sky_main(__attribute__((unused)) void* input) {

	// schedule update pings job
	sch_schedule_repeating(job_new(job_send_update_pings, (job_payload_t) {}), 200, 200);

	struct timespec nextTick, currentTime, sleepTime;

	clock_gettime(CLOCK_MONOTONIC, &nextTick);

	while (sky_main.status == sky_running) {

		clock_gettime(CLOCK_MONOTONIC, &currentTime);

		// sleep for correct time to next tick
		if (sky_to_nanos(currentTime) < sky_to_nanos(nextTick)) {
			sleepTime.tv_sec = nextTick.tv_sec - currentTime.tv_sec;
			sleepTime.tv_nsec = nextTick.tv_nsec - currentTime.tv_nsec;
			if (sleepTime.tv_nsec < 0) {
				sleepTime.tv_nsec += SKY_NANOS_PER_SECOND;
				sleepTime.tv_sec -= 1;
			}
		} else {
			sleepTime.tv_sec = 0;
			sleepTime.tv_nsec = 0;
			if ((sky_to_nanos(currentTime) - sky_to_nanos(nextTick)) / SKY_NANOS_PER_TICK > SKY_SKIP_TICKS) {
				log_warn("Can't keep up! Is the server overloaded? Running %lums or %d ticks behind", (sky_to_nanos(currentTime) - sky_to_nanos(nextTick)) / 1000000, (sky_to_nanos(currentTime) - sky_to_nanos(nextTick)) / SKY_NANOS_PER_TICK);
				clock_gettime(CLOCK_MONOTONIC, &nextTick);
			}
		}

		nextTick.tv_nsec = nextTick.tv_nsec + SKY_NANOS_PER_TICK;
		if (nextTick.tv_nsec > SKY_NANOS_PER_SECOND) {
			nextTick.tv_nsec -= SKY_NANOS_PER_SECOND;
			nextTick.tv_sec += 1;
		}

		nanosleep(&sleepTime, NULL);

		// do tick stuff
		sch_tick();

	}

	return NULL;

}

void* t_sky_worker(void* args) {

	sky_worker_t* worker = args;

	while (sky_main.status != sky_stopping) {

		// do work
		job_work(worker);

	}

	return NULL;

}

void sky_load_server_json() {

	mjson_doc* server = mjson_read_file("server.json");

	if (server) {

		mjson_val* server_obj = mjson_get_root(server);
		const uint32_t server_obj_size = mjson_get_size(server_obj);
		for (uint32_t i = 0; i < server_obj_size; ++i) {
			mjson_property key_val = mjson_obj_get(server_obj, i);
			const char* key = mjson_get_string(key_val.label);
			uint32_t hash = utl_hash(key);
			switch (hash) {
				case 0x574c2735: { // "worker_count"
					sky_main.workers.count = mjson_get_int(key_val.value);
				} break;
				case 0x6f29f27f: { // "max-tick-time"
					sky_main.max_tick_time = mjson_get_int(key_val.value);
				} break;
				case 0xfdabc3d: { // "level"
					const uint32_t key_val_size = mjson_get_size(key_val.value);
					for (uint32_t j = 0; j < key_val_size; ++j) {
						mjson_property level = mjson_obj_get(key_val.value, j);
						const char* l_key = mjson_get_string(level.label);
						const int32_t l_hash = utl_hash(l_key);
						switch (l_hash) {
							case 0x7c9b0c46: { // "name"
								sky_main.world.name.length = mjson_get_size(level.value);
								sky_main.world.name.value = malloc(sky_main.world.name.length + 1);
								memcpy(sky_main.world.name.value, mjson_get_string(level.value), sky_main.world.name.length + 1);
							} break;
							case 0x59e62b73: { // "max-size"
								// TODO
							} break;
							case 0x641f5542: { // "spawn-protection"
								// TODO
							} break;
							case 0xd8c37ac: { // "generator"
								// TODO
							} break;
							default: {
								log_warn("Unknown value '%s' in server.json! (%x)", l_key, l_hash);
							} break;
						}
					}
				} break;
				case 0xbaa497e4: { // "gamemode"
					const uint32_t key_val_size = mjson_get_size(key_val.value);
					for (uint32_t j = 0; j < key_val_size; ++j) {
						mjson_property gamemode = mjson_obj_get(key_val.value, j);
						const char* g_key = mjson_get_string(gamemode.label);
						const int32_t g_hash = utl_hash(g_key);
						switch (g_hash) {
							case 0x885548a: {
								const char* gamemode_val = mjson_get_string(gamemode.value);
								const int32_t gamemode_hash = utl_hash(gamemode_val);
								switch (gamemode_hash) {
									case 0xde22a921: {
										sky_main.gamemode = ent_survival;
									} break;
									case 0x134d6598: {
										sky_main.gamemode = ent_creative;
									} break;
									case 0xcdf3b093: {
										sky_main.gamemode = ent_adventure;
									} break;
									case 0xf0e3665a: {
										sky_main.gamemode = ent_spectator;
									} break;
									default: {
										log_warn("Unknown gamemode '%s' in server.json! (%x)", gamemode_val, gamemode_hash);
									} break;
								}
							} break;
							case 0xf7393b4: {
								sky_main.force_gamemode = mjson_get_boolean(gamemode.value);
							} break;
							default: {
								log_warn("Unknown value '%s' in server.json! (%x)", g_key, g_hash);
							} break;
						}
					}
				} break;
				case 0x5af71738: { // "difficulty"
					const uint32_t key_val_size = mjson_get_size(key_val.value);
					for (uint32_t j = 0; j < key_val_size; ++j) {
						mjson_property difficulty = mjson_obj_get(key_val.value, j);
						const char* d_key = mjson_get_string(difficulty.label);
						const int32_t d_hash = utl_hash(d_key);
						switch (d_hash) {
							case 0xfdabc3d: { // level
								const char* l_key = mjson_get_string(difficulty.value);
								int32_t l_hash = utl_hash(l_key);
								switch (l_hash) {
									case 0x20b7672a: {
										sky_main.difficulty = sky_peaceful;
									} break;
									case 0x7c961db7: {
										sky_main.difficulty = sky_easy;
									} break;
									case 0x108f79ae: {
										sky_main.difficulty = sky_normal;
									} break;
									case 0x7c97c2a4: {
										sky_main.difficulty = sky_hard;
									} break;
									default: {
										log_warn("Unknown difficulty level '%s'! (%x)", l_key, l_hash);
									} break;
								}
							} break;
							case 0xb278a56d: { // hardcore
								sky_main.hardcore = mjson_get_boolean(difficulty.value);
							} break;
							default: {
								log_warn("Unknown value '%s' in server.json! (%x)", d_key, d_hash);
							} break;
						}
					}
				} break;
				case 0xc865ee91: { // "enforce-whitelist"
					sky_main.enforce_whitelist = mjson_get_boolean(key_val.value);
				} break;
				case 0x2e5c5d10: { // "enable-command-block"
					sky_main.enable_command_block = mjson_get_boolean(key_val.value);
				} break;
				case 0xe526df8: { // "max-players"
					sky_main.listener.online.max = mjson_get_int(key_val.value);
				} break;
				case 0x105f18ee: { // "spawn"
					// TODO
				} break;
				case 0xbe5ede5d: { // "render-distance"
					sky_main.render_distance = mjson_get_int(key_val.value);
				} break;
				case 0x55e4fdff: { // "op-permission-level"
					sky_main.op_permission_level = mjson_get_int(key_val.value);
				} break;
				case 0xb889efb: { // "pvp"
					sky_main.pvp = mjson_get_boolean(key_val.value);
				} break;
				case 0x1b84769c: { // "server"
					// TODO
				} break;
				case 0x4e682648: { // "prevent-proxy-connections"
					sky_main.prevent_proxy_connections = mjson_get_boolean(key_val.value);
				} break;
				case 0xbb97de68: { // "network-compression-threshold"
					sky_main.network_compression_threshold = mjson_get_int(key_val.value);
				} break;
				case 0xa009ab4e: { // "reduced-debug-info"
					sky_main.reduced_debug_info = mjson_get_boolean(key_val.value);
				} break;
				case 0x7c9c614a: { // "port"
					sky_main.listener.address.port = mjson_get_int(key_val.value);
				} break;
				case 0x8931d3dc: { // "online-mode"
					sky_main.online_mode = mjson_get_boolean(key_val.value);
				} break;
				case 0x7c9abc59: { // "motd"
					sky_main.motd = cht_from_json(key_val.value);
				} break;
				default: {
					log_warn("Unknown value '%s' in server.json! (%x)", key, hash);
				} break;
			}
		}

	} else {

		log_error("Could not read server.json file!! Is the format correct?");

	}

	mjson_free(server);

}

void sky_gen_server_json() {

	const byte_t server_json[] = {
		0x7b, 0x0d, 0x0a, 0x09, 0x22, 0x77, 0x6f, 0x72, 0x6b, 0x65, 0x72, 0x2d,
		0x63, 0x6f, 0x75, 0x6e, 0x74, 0x22, 0x3a, 0x20, 0x34, 0x2c, 0x0d, 0x0a,
		0x09, 0x22, 0x6d, 0x61, 0x78, 0x2d, 0x74, 0x69, 0x63, 0x6b, 0x2d, 0x74,
		0x69, 0x6d, 0x65, 0x22, 0x3a, 0x20, 0x36, 0x30, 0x30, 0x30, 0x30, 0x2c,
		0x0d, 0x0a, 0x09, 0x22, 0x6c, 0x65, 0x76, 0x65, 0x6c, 0x22, 0x3a, 0x20,
		0x7b, 0x0d, 0x0a, 0x09, 0x09, 0x22, 0x6e, 0x61, 0x6d, 0x65, 0x22, 0x3a,
		0x20, 0x22, 0x77, 0x6f, 0x72, 0x6c, 0x64, 0x22, 0x2c, 0x0d, 0x0a, 0x09,
		0x09, 0x22, 0x6d, 0x61, 0x78, 0x2d, 0x73, 0x69, 0x7a, 0x65, 0x22, 0x3a,
		0x20, 0x32, 0x39, 0x39, 0x39, 0x39, 0x39, 0x38, 0x34, 0x2c, 0x0d, 0x0a,
		0x09, 0x09, 0x22, 0x73, 0x70, 0x61, 0x77, 0x6e, 0x2d, 0x70, 0x72, 0x6f,
		0x74, 0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x22, 0x3a, 0x20, 0x31, 0x36,
		0x2c, 0x0d, 0x0a, 0x09, 0x09, 0x22, 0x67, 0x65, 0x6e, 0x65, 0x72, 0x61,
		0x74, 0x6f, 0x72, 0x22, 0x3a, 0x20, 0x7b, 0x0d, 0x0a, 0x09, 0x09, 0x09,
		0x22, 0x74, 0x79, 0x70, 0x65, 0x22, 0x3a, 0x20, 0x22, 0x64, 0x65, 0x66,
		0x61, 0x75, 0x6c, 0x74, 0x22, 0x2c, 0x0d, 0x0a, 0x09, 0x09, 0x09, 0x22,
		0x73, 0x65, 0x74, 0x74, 0x69, 0x6e, 0x67, 0x73, 0x22, 0x3a, 0x20, 0x22,
		0x22, 0x2c, 0x0d, 0x0a, 0x09, 0x09, 0x09, 0x22, 0x73, 0x74, 0x72, 0x75,
		0x63, 0x74, 0x75, 0x72, 0x65, 0x73, 0x22, 0x3a, 0x20, 0x74, 0x72, 0x75,
		0x65, 0x2c, 0x0d, 0x0a, 0x09, 0x09, 0x09, 0x22, 0x73, 0x65, 0x65, 0x64,
		0x22, 0x3a, 0x20, 0x30, 0x0d, 0x0a, 0x09, 0x09, 0x7d, 0x0d, 0x0a, 0x09,
		0x7d, 0x2c, 0x0d, 0x0a, 0x09, 0x22, 0x67, 0x61, 0x6d, 0x65, 0x6d, 0x6f,
		0x64, 0x65, 0x22, 0x3a, 0x20, 0x7b, 0x0d, 0x0a, 0x09, 0x09, 0x22, 0x64,
		0x65, 0x66, 0x61, 0x75, 0x6c, 0x74, 0x22, 0x3a, 0x20, 0x22, 0x73, 0x75,
		0x72, 0x76, 0x69, 0x76, 0x61, 0x6c, 0x22, 0x2c, 0x0d, 0x0a, 0x09, 0x09,
		0x22, 0x66, 0x6f, 0x72, 0x63, 0x65, 0x22, 0x3a, 0x20, 0x74, 0x72, 0x75,
		0x65, 0x0d, 0x0a, 0x09, 0x7d, 0x2c, 0x0d, 0x0a, 0x09, 0x22, 0x64, 0x69,
		0x66, 0x66, 0x69, 0x63, 0x75, 0x6c, 0x74, 0x79, 0x22, 0x3a, 0x20, 0x7b,
		0x0d, 0x0a, 0x09, 0x09, 0x22, 0x6c, 0x65, 0x76, 0x65, 0x6c, 0x22, 0x3a,
		0x20, 0x22, 0x65, 0x61, 0x73, 0x79, 0x22, 0x2c, 0x0d, 0x0a, 0x09, 0x09,
		0x22, 0x68, 0x61, 0x72, 0x64, 0x63, 0x6f, 0x72, 0x65, 0x22, 0x3a, 0x20,
		0x66, 0x61, 0x6c, 0x73, 0x65, 0x0d, 0x0a, 0x09, 0x7d, 0x2c, 0x0d, 0x0a,
		0x09, 0x22, 0x65, 0x6e, 0x66, 0x6f, 0x72, 0x63, 0x65, 0x2d, 0x77, 0x68,
		0x69, 0x74, 0x65, 0x6c, 0x69, 0x73, 0x74, 0x22, 0x3a, 0x20, 0x66, 0x61,
		0x6c, 0x73, 0x65, 0x2c, 0x0d, 0x0a, 0x09, 0x22, 0x65, 0x6e, 0x61, 0x62,
		0x6c, 0x65, 0x2d, 0x63, 0x6f, 0x6d, 0x6d, 0x61, 0x6e, 0x64, 0x2d, 0x62,
		0x6c, 0x6f, 0x63, 0x6b, 0x22, 0x3a, 0x20, 0x66, 0x61, 0x6c, 0x73, 0x65,
		0x2c, 0x0d, 0x0a, 0x09, 0x22, 0x6d, 0x61, 0x78, 0x2d, 0x70, 0x6c, 0x61,
		0x79, 0x65, 0x72, 0x73, 0x22, 0x3a, 0x20, 0x32, 0x30, 0x2c, 0x0d, 0x0a,
		0x09, 0x22, 0x73, 0x70, 0x61, 0x77, 0x6e, 0x22, 0x3a, 0x20, 0x7b, 0x0d,
		0x0a, 0x09, 0x09, 0x22, 0x6d, 0x6f, 0x6e, 0x73, 0x74, 0x65, 0x72, 0x73,
		0x22, 0x3a, 0x20, 0x74, 0x72, 0x75, 0x65, 0x2c, 0x0d, 0x0a, 0x09, 0x09,
		0x22, 0x6e, 0x70, 0x63, 0x73, 0x22, 0x3a, 0x20, 0x74, 0x72, 0x75, 0x65,
		0x0d, 0x0a, 0x09, 0x7d, 0x2c, 0x0d, 0x0a, 0x09, 0x22, 0x72, 0x65, 0x6e,
		0x64, 0x65, 0x72, 0x2d, 0x64, 0x69, 0x73, 0x74, 0x61, 0x6e, 0x63, 0x65,
		0x22, 0x3a, 0x20, 0x31, 0x30, 0x2c, 0x0d, 0x0a, 0x09, 0x22, 0x6f, 0x70,
		0x2d, 0x70, 0x65, 0x72, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x2d,
		0x6c, 0x65, 0x76, 0x65, 0x6c, 0x22, 0x3a, 0x20, 0x34, 0x2c, 0x0d, 0x0a,
		0x09, 0x22, 0x70, 0x76, 0x70, 0x22, 0x3a, 0x20, 0x74, 0x72, 0x75, 0x65,
		0x2c, 0x0d, 0x0a, 0x09, 0x22, 0x73, 0x65, 0x72, 0x76, 0x65, 0x72, 0x22,
		0x3a, 0x20, 0x7b, 0x0d, 0x0a, 0x09, 0x09, 0x22, 0x61, 0x64, 0x64, 0x72,
		0x65, 0x73, 0x73, 0x22, 0x3a, 0x20, 0x22, 0x22, 0x2c, 0x0d, 0x0a, 0x09,
		0x09, 0x22, 0x70, 0x6f, 0x72, 0x74, 0x22, 0x3a, 0x20, 0x32, 0x35, 0x35,
		0x36, 0x35, 0x0d, 0x0a, 0x09, 0x7d, 0x2c, 0x0d, 0x0a, 0x09, 0x22, 0x70,
		0x72, 0x65, 0x76, 0x65, 0x6e, 0x74, 0x2d, 0x70, 0x72, 0x6f, 0x78, 0x79,
		0x2d, 0x63, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x73,
		0x22, 0x3a, 0x20, 0x74, 0x72, 0x75, 0x65, 0x2c, 0x0d, 0x0a, 0x09, 0x22,
		0x6e, 0x65, 0x74, 0x77, 0x6f, 0x72, 0x6b, 0x2d, 0x63, 0x6f, 0x6d, 0x70,
		0x72, 0x65, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x2d, 0x74, 0x68, 0x72, 0x65,
		0x73, 0x68, 0x6f, 0x6c, 0x64, 0x22, 0x3a, 0x20, 0x32, 0x35, 0x36, 0x2c,
		0x0d, 0x0a, 0x09, 0x22, 0x72, 0x65, 0x64, 0x75, 0x63, 0x65, 0x64, 0x2d,
		0x64, 0x65, 0x62, 0x75, 0x67, 0x2d, 0x69, 0x6e, 0x66, 0x6f, 0x22, 0x3a,
		0x20, 0x66, 0x61, 0x6c, 0x73, 0x65, 0x2c, 0x0d, 0x0a, 0x09, 0x22, 0x6f,
		0x6e, 0x6c, 0x69, 0x6e, 0x65, 0x2d, 0x6d, 0x6f, 0x64, 0x65, 0x22, 0x3a,
		0x20, 0x74, 0x72, 0x75, 0x65, 0x2c, 0x0d, 0x0a, 0x09, 0x22, 0x6d, 0x6f,
		0x74, 0x64, 0x22, 0x3a, 0x20, 0x7b, 0x0d, 0x0a, 0x09, 0x09, 0x22, 0x74,
		0x65, 0x78, 0x74, 0x22, 0x3a, 0x20, 0x22, 0x41, 0x20, 0x4d, 0x69, 0x6e,
		0x65, 0x63, 0x72, 0x61, 0x66, 0x74, 0x20, 0x73, 0x65, 0x72, 0x76, 0x65,
		0x72, 0x22, 0x0d, 0x0a, 0x09, 0x7d, 0x0d, 0x0a, 0x7d
	};

	FILE* file = fopen("server.json", "wb");

	if (file) {

		fwrite(server_json, sizeof(server_json), 1, file);
		fclose(file);

	} else {

		log_error("Could not open 'server.json' for writing!");

	}

}

void sky_term() {

	// we're stopping
	sky_main.status = sky_stopping;

	log_info("Stopping the server...");

	// stop listening
	ltg_term(sky_get_listener());

	// join main thread
	pthread_join(sky_main.thread, NULL);

	// join to each worker
	// resume workers waiting for jobs
	job_resume();

	for (size_t i = 0; i < sky_main.workers.vector.size; ++i) {

		sky_worker_t* worker = UTL_VECTOR_GET_AS(sky_worker_t*, &sky_main.workers.vector, i);

		if (pthread_self() != worker->thread) {
			pthread_join(worker->thread, NULL);
		}

	}

	wld_unload_all();

	// disable plugins
	plg_on_disable();

	// we've stopped
	sky_main.status = sky_stopped;

	curl_global_cleanup();

	utl_restore_console();

}
