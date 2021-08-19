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
	
	uint16_t idx : 10; // index of chunk in region (used for finding chunk x and y)
	uint8_t ticket : 7;
	uint8_t min_ticket : 7;

	wld_chunk_section_t sections[]; // y = section index * 16, count of sections = World.height / 16

};

struct wld_region {
	
	wld_world_t* world; // typeof wld_world_t*

	// chunks
	wld_chunk_t* chunks[32 * 32];

	// relative regions
	struct {
		wld_region_t* north;
		wld_region_t* east;
		wld_region_t* south;
		wld_region_t* west;
	} relative;

	int16_t x;
	int16_t z;

};

struct wld_world {

	int64_t seed;
	uint64_t time;

	string_t name;

	// lock for adding and removing regions
	pthread_mutex_t lock;

	// regions
	utl_tree_t regions;

	struct {
		int32_t x;
		int32_t z;
	} spawn;
	
	uint16_t id;

	bool_t debug : 1;
	bool_t flat : 1;

	mat_dimension_type_t environment : 6;

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

static inline int32_t wld_get_chunk_x(wld_chunk_t* chunk) {
	int32_t x = chunk->region->x << 5; // region x * 32
	x += chunk->idx >> 5;
	return x;
}
static inline int32_t wld_get_chunk_z(wld_chunk_t* chunk) {
	int32_t z = chunk->region->z << 5; // region z * 32
	z += chunk->idx & 0x1F;
	return z;
}

static inline void wld_subscribe_chunk(wld_chunk_t* chunk, uint32_t client_id) {
	utl_bit_vector_set_bit(&chunk->subscribers, client_id);
}
static inline void wld_unsubscribe_chunk(wld_chunk_t* chunk, uint32_t client_id) {
	utl_bit_vector_reset_bit(&chunk->subscribers, client_id);
}

extern void wld_unload(wld_world_t* world);
