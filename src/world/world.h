#pragma once
#include <pthread.h>
#include "../main.h"
#include "../util/doubly_linked_list.h"
#include "../util/id_vector.h"
#include "../util/bit_vector.h"
#include "../util/tree.h"
#include "material/material.h"

typedef struct wld_world wld_world_t;
typedef struct wld_region wld_region_t;
typedef struct wld_chunk wld_chunk_t;
typedef struct wld_chunk_section wld_chunk_section_t;

struct wld_chunk_section {

	// block map
	struct {

		uint16_t state;
		uint16_t entity;

	} blocks[16 * 16 * 16];

	uint16_t block_count: 12;

	// biome map
	uint8_t biome[4 * 4 * 4];

};

#define WLD_TICKET_TICK_ENTITIES 12
#define WLD_TICKET_TICK 13
#define WLD_TICKET_BORDER 14
#define WLD_TICKET_INACCESSIBLE 15

struct wld_chunk {

	wld_region_t* region;

	pthread_mutex_t lock;

	// subscribers are "subscribed" to updates in the chunk
	// they also are useful when calculating the chunk ticket
	utl_bit_vector_t subscribers;

	utl_id_vector_t block_entities;
	utl_doubly_linked_list_t entities;

	// highest blocks
	struct {

		int16_t motion_blocking;
		int16_t world_surface;

	} highest[16 * 16];
	
	const union {

		uint16_t idx: 10;

		struct {

			uint8_t x : 5;
			uint8_t z : 5;

		};

	};

	uint8_t ticket : 4;
	uint8_t max_ticket : 4;

	wld_chunk_section_t sections[]; // y = section index * 16, count of sections = World.height / 16

};

struct wld_region {
	
	wld_world_t* world; // typeof wld_world_t*

	pthread_mutex_t lock;

	// chunks
	wld_chunk_t* chunks[32 * 32];

	// relative regions
	struct {

		wld_region_t* north;
		wld_region_t* east;
		wld_region_t* south;
		wld_region_t* west;

	} relative;

	const union {

		uint32_t idx;

		struct {

			int16_t x;
			int16_t z;

		};

	};

};

struct wld_world {

	const int64_t seed;
	uint64_t time;

	const string_t name;

	// lock for updating non const variables
	pthread_mutex_t lock;

	// regions
	utl_tree_t regions;

	const struct {

		int32_t x;
		int32_t z;

	} spawn;
	
	const uint16_t id;

	const bool_t debug : 1;
	const bool_t flat : 1;

	const mat_dimension_type_t environment : 6;

};

extern uint16_t wld_add(wld_world_t* world);

extern wld_world_t* wld_new(const string_t name, int64_t seed, mat_dimension_type_t environment);
extern wld_world_t* wld_load(const string_t name);

extern uint16_t wld_get_count();
extern wld_world_t* wld_get_world(uint16_t world_id);

static inline wld_world_t* wld_get_default() {
	return wld_get_world(0);
}

extern wld_region_t* wld_get_region(wld_world_t* world, int16_t x, int16_t z);
static inline wld_region_t* wld_get_region_at(wld_world_t* world, int32_t x, int32_t z) {
	return wld_get_region(world, x >> 9, z >> 9);
}

extern wld_chunk_t* wld_get_chunk(wld_world_t* world, int32_t x, int32_t z);
static inline wld_chunk_t* wld_get_chunk_at(wld_world_t* world, int32_t x, int32_t z) {
	return wld_get_chunk(world, x >> 4, z >> 4);
}
extern wld_chunk_t* wld_relative_chunk(const wld_chunk_t* chunk, int16_t x, int16_t z);

static inline int32_t wld_get_chunk_x(const wld_chunk_t* chunk) {
	return (chunk->region->x << 5) + chunk->x;
}
static inline int32_t wld_get_chunk_z(const wld_chunk_t* chunk) {
	return (chunk->region->z << 5) + chunk->z;
}

static inline void wld_subscribe_chunk(wld_chunk_t* chunk, uint32_t client_id) {
	pthread_mutex_lock(&chunk->lock);
	utl_bit_vector_set_bit(&chunk->subscribers, client_id);
	pthread_mutex_unlock(&chunk->lock);
}
static inline void wld_unsubscribe_chunk(wld_chunk_t* chunk, uint32_t client_id) {
	pthread_mutex_lock(&chunk->lock);
	utl_bit_vector_reset_bit(&chunk->subscribers, client_id);
	pthread_mutex_unlock(&chunk->lock);
}

extern void wld_free_region(wld_region_t* region);
extern void wld_unload(wld_world_t* world);
extern void wld_unload_all();