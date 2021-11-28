#pragma once
#include <pthread.h>
#include <assert.h>

#include "world.d.h"
#include "entity/entity.d.h"

#include "../main.h"
#include "../util/id_vector.h"
#include "../util/bit_vector.h"
#include "../util/tree.h"
#include "../util/lock_util.h"
#include "../util/util.h"
#include "../jobs/board.h"
#include "../jobs/scheduler/scheduler.h"
#include "material/material.h"

struct wld_chunk_section {

	// block map
	_Atomic mat_block_protocol_id_t blocks[16 * 16 * 16];
	_Atomic uint16_t entity_idx[16 * 16 * 16];

	atomic_uint_fast16_t block_count;

	// biome map
	_Atomic uint8_t biome[4 * 4 * 4];

};

struct wld_chunk {

	wld_region_t* const region;

	pthread_mutex_t lock;

	// subscribers are "subscribed" to updates in the chunk
	utl_bit_vector_t subscribers;

	// players
	// useful when calculating the chunk ticket (chunk ticket should be recalculated every time this list is updated)
	utl_bit_vector_t players;

	utl_id_vector_t block_entities;
	utl_id_vector_t entities;

	// highest blocks
	struct {

		_Atomic int16_t motion_blocking[16 * 16];
		_Atomic int16_t world_surface[16 * 16];

	} highest;

	const uint8_t x : 5;
	const uint8_t z : 5;

	_Atomic uint8_t subtick;

	_Atomic uint8_t ticket;
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
	const uint64_t seed_hash;

	_Atomic uint64_t age;

	const string_t name;

	// regions
	utl_tree_t regions;

	const struct {

		int32_t x;
		int32_t z;

	} spawn;
	
	uint32_t tick;
	
	_Atomic uint16_t time;
	const uint16_t id;

	bool time_progressing : 1;
	const bool debug : 1;
	const bool flat : 1;

	const mat_dimension_type_t environment : 6;

};

extern wld_world_t* wld_new(const string_t name, int64_t seed, mat_dimension_type_t environment);
extern wld_world_t* wld_load(const string_t name);

static inline int64_t wld_get_seed(wld_world_t* world) {
	return world->seed;
}

static inline uint64_t wld_get_seed_hash(wld_world_t* world) {
	return world->seed_hash;
}

static inline int32_t wld_get_spawn_x(wld_world_t* world) {
	return world->spawn.x;
}

static inline int32_t wld_get_spawn_z(wld_world_t* world) {
	return world->spawn.z;
}

static inline bool wld_is_debug(wld_world_t* world) {
	return world->debug;
}

static inline bool wld_is_flat(wld_world_t* world) {
	return world->flat;
}

static inline mat_dimension_type_t wld_get_environment(wld_world_t* world) {
	return world->environment;
}

static inline uint64_t wld_get_age(wld_world_t* world) {
	return world->age;
}

static inline uint16_t wld_get_time(wld_world_t* world) {
	return world->time;
}

static inline bool wld_is_time_progressing(wld_world_t* world) {
	return world->time_progressing;
}

extern uint16_t wld_get_count();
extern uint16_t wld_get_length();
extern wld_world_t* wld_get_world(uint16_t world_id);

static inline wld_world_t* wld_get_default() {
	return wld_get_world(0);
}

extern wld_region_t* wld_gen_region(wld_world_t* world, int16_t x, int16_t z);

static inline wld_region_t* wld_get_region(wld_world_t* world, int16_t x, int16_t z) {

	wld_region_t* region = NULL;

	with_lock (&world->lock) {
		region = utl_tree_get(&world->regions, ((uint64_t) (uint16_t) x << 16) | (uint16_t) z);
	}

	if (region == NULL) {
		region = wld_gen_region(world, x, z);
	}

	return region;

}

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

static inline wld_chunk_t* wld_region_get_chunk_by_idx(wld_region_t* region, uint16_t idx) {
	return region->chunks[idx];
}

static inline wld_chunk_t* wld_region_get_chunk(wld_region_t* region, uint8_t x, uint8_t z) {
	return region->chunks[((uint16_t) x << 5) | z];
}

static inline uint_fast16_t wld_region_get_loaded_chunks(wld_region_t* region) {
	return region->loaded_chunks;
}

extern wld_chunk_t* wld_gen_chunk(wld_region_t* region, uint8_t x, uint8_t z, uint8_t max_ticket);

static inline wld_chunk_t* wld_get_chunk(wld_world_t* world, int32_t x, int32_t z) {

	wld_region_t* region = wld_get_region(world, x >> 5, z >> 5);

	const uint8_t c_x = x & 0x1F;
	const uint8_t c_z = z & 0x1F;

	wld_chunk_t* chunk = region->chunks[(c_x << 5) | c_z];

	if (chunk == NULL) {

		chunk = wld_gen_chunk(region, c_x, c_z, WLD_TICKET_MAX);

	}

	assert(chunk != NULL);

	return chunk;

}

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
		utl_id_vector_remove(&chunk->entities, entity);
	}

}

static inline bool wld_chunk_has_subscriber(wld_chunk_t* chunk, uint32_t client) {
	
	bool has_subscriber = false;

	with_lock (&chunk->lock) {
		has_subscriber = utl_bit_vector_test_bit(&chunk->subscribers, client);
	}

	return has_subscriber;

}

static inline uint8_t wld_chunk_get_ticket(const wld_chunk_t* chunk) {
	return chunk->ticket;
}

static inline int32_t wld_get_chunk_x(const wld_chunk_t* chunk) {
	return (wld_region_get_x(wld_chunk_get_region(chunk)) << 5) | chunk->x;
}
static inline int32_t wld_get_chunk_z(const wld_chunk_t* chunk) {
	return (wld_region_get_z(wld_chunk_get_region(chunk)) << 5) | chunk->z;
}

static inline wld_chunk_t* wld_gen_relative_chunk(const wld_chunk_t* chunk, int16_t x, int16_t z, uint8_t max_ticket) {
	
	const int32_t f_x = x + wld_get_chunk_x(chunk);
	const int32_t f_z = z + wld_get_chunk_z(chunk);

	const int32_t c_x = x + chunk->x;
	const int32_t c_z = z + chunk->z;

	int16_t r_x = c_x >> 5;
	int16_t r_z = c_z >> 5;

	const uint16_t i_x = c_x & 0x1F;
	const uint16_t i_z = c_z & 0x1F;
	const uint16_t idx = (i_x << 5) | i_z;

	wld_region_t* region = wld_chunk_get_region(chunk);
	wld_world_t* world = region->world;

	while (r_x < 0) {
		region = region->relative.west;
		if (region == NULL) {
			return wld_get_chunk(world, f_x, f_z);
		}
		r_x++;
	}
	while (r_x > 0) {
		region = region->relative.east;
		if (region == NULL) {
			return wld_get_chunk(world, f_x, f_z);
		}
		
		r_x--;
	}

	while (r_z < 0) {
		region = region->relative.north;
		if (region == NULL) {
			return wld_get_chunk(world, f_x, f_z);
		}
		r_z++;
	}
	while (r_z > 0) {
		region = region->relative.south;
		if (region == NULL) {
			return wld_get_chunk(world, f_x, f_z);
		}
		r_z--;
	}

	wld_chunk_t* found_chunk = region->chunks[idx];
	if (found_chunk == NULL) {
		found_chunk = wld_gen_chunk(region, i_x, i_z, max_ticket);
	}

	assert(found_chunk != NULL);

	return found_chunk;

}

// This is fast for short distances (within regions to a few regions over), but for long distances this is excruciatingly slow
static inline wld_chunk_t* wld_relative_chunk(const wld_chunk_t* chunk, int32_t x, int32_t z) {

	return wld_gen_relative_chunk(chunk, x, z, WLD_TICKET_MAX);

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

static inline void wld_set_chunk_ticket(wld_chunk_t* chunk, uint8_t ticket) {
	ticket = UTL_MIN(chunk->max_ticket, ticket);
	if (chunk->ticket == WLD_TICKET_INACCESSIBLE && ticket < WLD_TICKET_INACCESSIBLE) {
		// loading chunk
		wld_chunk_get_region(chunk)->loaded_chunks += 1;
	} else if (chunk->ticket < WLD_TICKET_INACCESSIBLE && ticket == WLD_TICKET_INACCESSIBLE) {
		// unloading chunk
		wld_chunk_get_region(chunk)->loaded_chunks -= 1;
		if (wld_chunk_get_region(chunk)->loaded_chunks == 0) {
			sch_schedule(job_new(job_unload_region, (job_payload_t) { .region = wld_chunk_get_region(chunk) }), 100); // set to try unload in 5 seconds
		}
	}
	chunk->ticket = ticket;
}

static inline void wld_add_player_chunk(wld_chunk_t* chunk, uint32_t client_id, uint8_t ticket) {
	with_lock (&chunk->lock) {
		utl_bit_vector_set_bit(&chunk->players, client_id);
	}
	ticket = UTL_MIN(chunk->ticket, ticket);
	wld_set_chunk_ticket(chunk, ticket);
}

extern void wld_recalc_chunk_ticket_l(wld_chunk_t* chunk);

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

static inline wld_chunk_section_t* wld_chunk_get_section(wld_chunk_t* chunk, uint16_t index) {
	return &chunk->sections[index];
}

static inline uint_fast16_t wld_chunk_section_get_block_count(wld_chunk_section_t* section) {
	return section->block_count;
}

static inline uint_least8_t wld_chunk_section_get_biome(wld_chunk_section_t* section, uint8_t x, uint8_t y, uint8_t z) {
	return section->biome[(x << 4) + (z << 2) + y];
}

static inline mat_block_protocol_id_t* wld_chunk_section_get_blocks(wld_chunk_section_t* section) {
	return (mat_block_protocol_id_t*) section->blocks;
}

static inline void wld_chunk_subscribers_xor_foreach(wld_chunk_t* c1, wld_chunk_t* c2, void (*const function) (uint32_t, void*), void* args) {
	utl_bit_vector_xor_foreach(&c1->subscribers, &c2->subscribers, &c1->lock, &c2->lock, function, args);
}

static inline void wld_chunk_subscribers_foreach(wld_chunk_t* chunk, void (*const function) (uint32_t, void*), void* args) {
	utl_bit_vector_lock_foreach(&chunk->subscribers, &chunk->lock, function, args);
}

static inline int16_t* wld_chunk_get_highest_motion_blocking(wld_chunk_t* chunk) {
	return (int16_t*) chunk->highest.motion_blocking;
}

static inline int16_t* wld_chunk_get_highest_world_surface(wld_chunk_t* chunk) {
	return (int16_t*) chunk->highest.world_surface;
}

static inline uint32_t wld_chunk_add_entity(wld_chunk_t* chunk, ent_entity_t* entity) {
	
	uint32_t chunk_node = 0;
	with_lock (&chunk->lock) {
		chunk_node = utl_id_vector_push(&chunk->entities, &entity);
	}
	return chunk_node;
	
}

static inline uint32_t wld_chunk_get_entity_count(wld_chunk_t* chunk) {
	uint32_t count = 0;
	with_lock (&chunk->lock) {
		count = utl_id_vector_count(&chunk->entities);
	}
	return count;
}

static inline uint32_t wld_chunk_get_entity_length(wld_chunk_t* chunk) {
	uint32_t length = 0;
	with_lock (&chunk->lock) {
		length = utl_id_vector_length(&chunk->entities);
	}
	return length;
}

static inline ent_entity_t* wld_chunk_get_entity(wld_chunk_t* chunk, uint32_t idx) {
	ent_entity_t* entity = NULL;
	with_lock (&chunk->lock) {
		entity = UTL_ID_VECTOR_GET_AS(ent_entity_t*, &chunk->entities, idx);
	}
	return entity;
}

static inline mat_block_protocol_id_t wld_get_block_at(wld_chunk_t* chunk, int32_t x, int16_t y, int32_t z) {

	wld_chunk_t* block_chunk = wld_relative_chunk(chunk, (x >> 4) - wld_get_chunk_x(chunk), (z >> 4) - wld_get_chunk_z(chunk));
	wld_chunk_section_t* section = wld_chunk_get_section(block_chunk, y >> 4);

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