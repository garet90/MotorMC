#pragma once
#include <assert.h>
#include <pthread.h>

#include "board.d.h"
#include "../motor.d.h"
#include "../world/entity/entity.d.h"
#include "../world/entity/living/living.d.h"
#include "../world/world.d.h"
#include "../listening/listening.d.h"

#include "../main.h"
#include "../util/list.h"

struct job_board {

	struct {
		pthread_mutex_t lock;
		pthread_cond_t wait;
		utl_list_t list;
	} queue;

	struct {
		pthread_mutex_t lock;
		utl_id_vector_t jobs;
	} heap;

};

extern job_board_t job_board;

union job_payload {

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
		int32_t x;
		int32_t z;

	} dig_block;

	wld_region_t* region;

	struct {

		ent_entity_t* entity;
		
		wld_chunk_t* initial_chunk;

		float64_t d_x;
		float64_t d_y;
		float64_t d_z;

		bool on_ground;

	} entity_move;

	struct {

		ent_entity_t* entity;
		
		wld_chunk_t* initial_chunk;

		wld_world_t* world;

		float64_t x;
		float64_t y;
		float64_t z;

	} entity_teleport;

	struct {

		ent_living_entity_t* entity;

		float32_t yaw;
		float32_t pitch;

		bool on_ground;

	} living_entity_look;

	struct {

		ent_living_entity_t* entity;
		
		wld_chunk_t* initial_chunk;

		float64_t d_x;
		float64_t d_y;
		float64_t d_z;

		float32_t yaw;
		float32_t pitch;

		bool on_ground;

	} living_entity_move_look;

	struct {

		ent_living_entity_t* entity;
		
		wld_chunk_t* initial_chunk;

		wld_world_t* world;

		float64_t x;
		float64_t y;
		float64_t z;

		float32_t yaw;
		float32_t pitch;

	} living_entity_teleport_look;

};

struct job_work {

	const job_type_t type : 4;
	uint8_t repeat;
	uint8_t on_board;
	bool canceled;

	job_payload_t payload;

};

extern uint32_t job_new(job_type_t type, job_payload_t payload);

typedef bool (*job_handler_t) (job_payload_t* payload);

extern void job_add_handler(job_type_t type, job_handler_t handler);
extern void job_handle(uint32_t id);
extern void job_add(uint32_t id);
extern void job_resume();

extern void job_free(uint32_t id);

extern uint32_t job_get();

extern size_t job_get_count();
extern job_type_t job_get_type(uint32_t job);

extern void job_work(sky_worker_t* worker);
