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
	_Atomic mat_block_protocol_id_t blocks[16 * 16 * 16];
	atomic_uint_least16_t entity_idx[16 * 16 * 16];

	atomic_uint_fast16_t block_count;

	// biome map
	atomic_uint_least8_t biome[4 * 4 * 4];

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

		_Atomic uint16_t motion_blocking[16 * 16];
		_Atomic uint16_t world_surface[16 * 16];

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

	atomic_uint_fast16_t loaded_chunks;

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

extern void wld_prepare_spawn(wld_world_t* world);
extern wld_world_t* wld_new(const string_t name, int64_t seed, mat_dimension_type_t environment);
extern wld_world_t* wld_load(const string_t name);

extern uint16_t wld_get_count();
extern wld_world_t* wld_get_world(uint16_t world_id);

static inline wld_world_t* wld_get_default() {
	return wld_get_world(0);
}

static inline mat_dimension_type_t wld_get_environment(wld_world_t* world) {
	return world->environment;
}

extern wld_region_t* wld_gen_region(wld_world_t* world, int16_t x, int16_t z);
extern wld_region_t* wld_get_region(wld_world_t* world, int16_t x, int16_t z);
static inline wld_region_t* wld_get_region_at(wld_world_t* world, int32_t x, int32_t z) {
	return wld_get_region(world, x >> 9, z >> 9);
}

static inline wld_world_t* wld_region_get_world(wld_region_t* region) {
	return region->world;
}

static inline int16_t wld_region_get_x(wld_region_t* region) {
	return region->x;
}

static inline int16_t wld_region_get_z(wld_region_t* region) {
	return region->z;
}

extern wld_chunk_t* wld_gen_chunk(wld_region_t* region, uint8_t x, uint8_t z, uint8_t max_ticket);
extern wld_chunk_t* wld_get_chunk(wld_world_t* world, int32_t x, int32_t z);
static inline wld_chunk_t* wld_get_chunk_at(wld_world_t* world, int32_t x, int32_t z) {
	return wld_get_chunk(world, x >> 4, z >> 4);
}

static inline wld_region_t* wld_chunk_get_region(const wld_chunk_t* chunk) {
	return chunk->region;
}

static inline wld_world_t* wld_chunk_get_world(const wld_chunk_t* chunk) {
	return wld_region_get_world(wld_chunk_get_region(chunk));
}

static inline void wld_chunk_remove_entity(wld_chunk_t* chunk, uint32_t entity) {

	with_lock (&chunk->lock) {
		utl_dll_remove(&chunk->entities, entity);
	}

}

extern wld_chunk_t* wld_gen_relative_chunk(const wld_chunk_t* chunk, int16_t x, int16_t z, uint8_t max_ticket);

// This is fast for short distances (within regions to a few regions over), but for long distances this is excruciatingly slow
static inline wld_chunk_t* wld_relative_chunk(const wld_chunk_t* chunk, int32_t x, int32_t z) {

	return wld_gen_relative_chunk(chunk, x, z, WLD_TICKET_MAX);

}

static inline int32_t wld_get_chunk_x(const wld_chunk_t* chunk) {
	return (wld_region_get_x(wld_chunk_get_region(chunk)) << 5) | chunk->x;
}
static inline int32_t wld_get_chunk_z(const wld_chunk_t* chunk) {
	return (wld_region_get_z(wld_chunk_get_region(chunk)) << 5) | chunk->z;
}

static inline bool wld_in_chunk(const wld_chunk_t* chunk, int32_t x, int32_t z) {
	return (wld_get_chunk_x(chunk) == (x >> 4) && wld_get_chunk_z(chunk) == (z >> 4));
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

static inline wld_chunk_section_t* wld_get_chunk_section(wld_chunk_t* chunk, uint16_t index) {
	return &chunk->sections[index];
}

static inline void wld_chunk_subscribers_xor_foreach(wld_chunk_t* c1, wld_chunk_t* c2, void (*const function) (uint32_t, void*), void* args) {
	utl_bit_vector_xor_foreach(&c1->subscribers, &c2->subscribers, &c1->lock, &c2->lock, function, args);
}

static inline void wld_chunk_subscribers_foreach(wld_chunk_t* chunk, void (*const function) (uint32_t, void*), void* args) {
	utl_bit_vector_lock_foreach(&chunk->subscribers, &chunk->lock, function, args);
}

static inline utl_dll_iterator_t wld_chunk_get_entity_iterator(wld_chunk_t* chunk) {
	
	utl_dll_iterator_t iterator;

	with_lock (&chunk->lock) {
		iterator = UTL_DLL_ITERATOR_INITIALIZER(&chunk->entities);
	}
	
	return iterator;
	
}

static inline void* wld_chunk_entity_iterator_next(wld_chunk_t* chunk, utl_dll_iterator_t* iterator) {

	void* ent = NULL;

	with_lock (&chunk->lock) {
		ent = utl_dll_iterator_next(iterator);
	}

	return ent;

}

static inline mat_block_protocol_id_t wld_get_block_at(wld_chunk_t* chunk, int32_t x, int16_t y, int32_t z) {

	wld_chunk_t* block_chunk = wld_relative_chunk(chunk, (x >> 4) - wld_get_chunk_x(chunk), (z >> 4) - wld_get_chunk_z(chunk));
	wld_chunk_section_t* section = wld_get_chunk_section(block_chunk, y >> 4);

	return section->blocks[((y & 0xF) << 8) | ((z & 0xF) << 4) | (x & 0xF)];

}

static inline mat_block_type_t wld_get_block_type_at(wld_chunk_t* chunk, int32_t x, int16_t y, int32_t z) {

	return mat_get_block_type_by_protocol_id(wld_get_block_at(chunk, x, y, z));

}

extern void wld_set_block_at(wld_chunk_t* chunk, int32_t x, int16_t y, int32_t z, mat_block_protocol_id_t type);

static inline void wld_set_block_type_at(wld_chunk_t* chunk, int32_t x, int16_t y, int32_t z, mat_block_type_t type) {

	wld_set_block_at(chunk, x, y, z, mat_get_block_default_protocol_id_by_type(type));

}

extern void wld_unload_region(wld_region_t* region);
extern void wld_free_region(wld_region_t* region);
extern void wld_unload(wld_world_t* world);
extern void wld_unload_all();