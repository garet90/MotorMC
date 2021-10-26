#pragma once
#include <pthread.h>
#include <assert.h>
#include "../main.h"
#include "../util/dll.h"
#include "../util/id_vector.h"
#include "../util/bit_vector.h"
#include "../util/tree.h"
#include "../util/lock_util.h"
#include "../util/util.h"
#include "material/material.h"

typedef struct wld_world wld_world_t;
typedef struct wld_region wld_region_t;
typedef struct wld_chunk wld_chunk_t;
typedef struct wld_chunk_section wld_chunk_section_t;

struct wld_chunk_section {

	// block map
	mat_block_protocol_id_t blocks[16 * 16 * 16];
	int16_t entity_idx[16 * 16 * 16];

	uint16_t block_count;

	// biome map
	uint8_t biome[4 * 4 * 4];

};

#define WLD_TICKET_TICK_ENTITIES 12
#define WLD_TICKET_TICK 13
#define WLD_TICKET_BORDER 14
#define WLD_TICKET_INACCESSIBLE 15
#define WLD_TICKET_MAX 15

struct wld_chunk {

	wld_region_t* const region;

	pthread_mutex_t lock;

	// subscribers are "subscribed" to updates in the chunk
	utl_bit_vector_t subscribers;

	// players
	// useful when calculating the chunk ticket (chunk ticket should be recalculated every time this list is updated)
	utl_bit_vector_t players;

	utl_id_vector_t block_entities;
	utl_dll_t entities;

	// highest blocks
	struct {

		int16_t motion_blocking[16 * 16];
		int16_t world_surface[16 * 16];

	} highest;

	const uint8_t x : 5;
	const uint8_t z : 5;

	atomic_uint_least8_t ticket;
	const uint8_t max_ticket;

	wld_chunk_section_t sections[]; // y = section index * 16, count of sections = World.height / 16

};

struct wld_region {
	
	wld_world_t* const world; // typeof wld_world_t*

	uint32_t tick;

	// chunks
	wld_chunk_t* _Atomic chunks[32 * 32];

	// relative regions
	struct {

		wld_region_t* _Atomic north;
		wld_region_t* _Atomic east;
		wld_region_t* _Atomic south;
		wld_region_t* _Atomic west;

	} relative;

	atomic_uint_least16_t loaded_chunks;

	const int16_t x;
	const int16_t z;
};

struct wld_world {

	pthread_mutex_t lock;

	const int64_t seed;
	atomic_uint_least64_t time;

	const string_t name;

	// regions
	utl_tree_t regions;

	const struct {

		int32_t x;
		int32_t z;

	} spawn;
	
	const uint16_t id;

	const bool debug : 1;
	const bool flat : 1;

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
// This is fast for short distances (within regions to a few regions over), but for long distances this is excruciatingly slow
extern wld_chunk_t* wld_relative_chunk(const wld_chunk_t* chunk, int32_t x, int32_t z);

static inline int32_t wld_get_chunk_x(const wld_chunk_t* chunk) {
	return (chunk->region->x << 5) + chunk->x;
}
static inline int32_t wld_get_chunk_z(const wld_chunk_t* chunk) {
	return (chunk->region->z << 5) + chunk->z;
}

static inline void wld_subscribe_chunk(wld_chunk_t* chunk, uint32_t client_id) {
	with_lock (&chunk->lock) {
		utl_bit_vector_set_bit(&chunk->subscribers, client_id);
	}
}

static inline void wld_unsubscribe_chunk(wld_chunk_t* chunk, uint32_t client_id) {
	with_lock (&chunk->lock) {
		utl_bit_vector_reset_bit(&chunk->subscribers, client_id);
	}
}

extern void wld_set_chunk_ticket(wld_chunk_t* chunk, uint8_t ticket);

static inline void wld_add_player_chunk(wld_chunk_t* chunk, uint32_t client_id, uint8_t ticket) {
	with_lock (&chunk->lock) {
		utl_bit_vector_set_bit(&chunk->players, client_id);
	}
	ticket = UTL_MIN(chunk->ticket, ticket);
	wld_set_chunk_ticket(chunk, ticket);
}

extern void wld_calc_player_ticket(uint32_t client_id, wld_chunk_t* chunk);

static inline void wld_recalc_chunk_ticket_l(wld_chunk_t* chunk) {
	uint8_t old_ticket = chunk->ticket;
	chunk->ticket = WLD_TICKET_MAX;
	utl_bit_vector_foreach(&chunk->players, (void (*) (uint32_t, void*)) wld_calc_player_ticket, chunk);
	uint8_t new_ticket = chunk->ticket;
	chunk->ticket = old_ticket;
	wld_set_chunk_ticket(chunk, new_ticket);
}

static inline void wld_recalc_chunk_ticket(wld_chunk_t* chunk) {
	with_lock (&chunk->lock) {
		wld_recalc_chunk_ticket_l(chunk);
	}
}

static inline void wld_remove_player_chunk(wld_chunk_t* chunk, uint32_t client_id) {
	with_lock (&chunk->lock) {
		utl_bit_vector_reset_bit(&chunk->players, client_id);
		wld_recalc_chunk_ticket_l(chunk);
	}
}

static inline mat_block_protocol_id_t wld_get_block_at(wld_chunk_t* chunk, int32_t x, int16_t y, int32_t z) {

	wld_chunk_t* block_chunk = wld_relative_chunk(chunk, x >> 4, z >> 4);
	const uint16_t sub_chunk = y >> 4;

	mat_block_protocol_id_t ret = mat_block_air;
	with_lock (&block_chunk->lock) {
		ret = block_chunk->sections[sub_chunk].blocks[((y & 0xF) << 8) | ((z & 0xF) << 4) | (x & 0xF)];
	}

	return ret;

}

static inline mat_block_type_t wld_get_block_type_at(wld_chunk_t* chunk, int32_t x, int16_t y, int32_t z) {

	return mat_get_block_type_by_protocol_id(wld_get_block_at(chunk, x, y, z));

}

static inline void wld_set_block_at(wld_chunk_t* chunk, uint8_t x, int16_t y, uint8_t z, mat_block_protocol_id_t type) {

	assert(z <= 0xF && x <= 0xF);

	const uint16_t sub_chunk = y >> 4;

	with_lock (&chunk->lock) {
		const mat_block_protocol_id_t old_type = chunk->sections[sub_chunk].blocks[((y & 0xF) << 8) | (z << 4) | x];
		const bool old_type_air = mat_get_block_by_type(mat_get_block_type_by_protocol_id(old_type))->air;
		const bool type_air = mat_get_block_by_type(mat_get_block_type_by_protocol_id(type))->air;
		if (old_type_air && !type_air) {
			chunk->sections[sub_chunk].block_count++;
		} else if (!old_type_air && type_air) {
			chunk->sections[sub_chunk].block_count--;
		}
		chunk->sections[sub_chunk].blocks[((y & 0xF) << 8) | (z << 4) | x] = type;
	}

}

static inline void wld_set_block_type_at(wld_chunk_t* chunk, uint8_t x, int16_t y, uint8_t z, mat_block_type_t type) {

	wld_set_block_at(chunk, x, y, z, mat_get_block_default_protocol_id_by_type(type));

}

extern void wld_unload_region(wld_region_t* region);
extern void wld_free_region(wld_region_t* region);
extern void wld_unload(wld_world_t* world);
extern void wld_unload_all();