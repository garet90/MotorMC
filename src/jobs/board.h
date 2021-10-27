#pragma once
#include <assert.h>
#include <pthread.h>
#include "../main.h"
#include "../util/list.h"
#include "../listening/listening.h"

typedef struct {

	struct {
		pthread_mutex_t lock;
		pthread_cond_t wait;
		utl_list_t list;
	} queue;

	struct {
		pthread_mutex_t lock;
		utl_id_vector_t jobs;
	} heap;

} job_board_t;

extern job_board_t job_board;

typedef enum {

	job_keep_alive,
	job_global_chat_message,
	job_player_join,
	job_player_leave,
	job_send_update_pings,
	job_tick_region,
	job_unload_region,
	job_dig_block,

	job_count

} job_type_t;

typedef union {

	ltg_client_t* client;

	struct {

		ltg_client_t* client;
		string_t message;

	} global_chat_message;

	struct {

		ltg_uuid_t uuid;
		char username[17];
		uint8_t username_length: 5;

	} player_leave;

	struct {

		ltg_client_t* client;
		wld_chunk_t* chunk;
		int16_t y;
		uint8_t x : 4;
		uint8_t z : 4;

	} dig_block;

	wld_region_t* region;

} job_payload_t;

typedef struct {

	const job_type_t type : 4;
	uint8_t repeat;
	uint8_t on_board;
	bool canceled;

	job_payload_t payload;

} job_work_t;

extern uint32_t job_new(job_type_t type, job_payload_t payload);

typedef bool (*job_handler_t) (job_payload_t* payload);

extern void job_add_handler(job_type_t type, job_handler_t handler);
extern void job_handle(uint32_t id);
extern void job_add(uint32_t id);
extern void job_resume();

extern void job_free(uint32_t id);

extern uint32_t job_get();

extern size_t job_get_count();

extern void job_work();
