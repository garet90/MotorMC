#include "world_private.h"
#include "../util/vector.h"
#include "../util/id_vector.h"
#include "../listening/listening.h"
#include "../io/logger/logger.h"
#include "entity/entity.h"
#include <stdlib.h>

struct {

	pthread_mutex_t lock;
	utl_id_vector_t worlds;

} wld_worlds = {
	.lock = PTHREAD_MUTEX_INITIALIZER,
	.worlds = {
		.bytes_per_element = sizeof(wld_world_t*),
	}
};

uint16_t wld_add(wld_world_t* world) {
	
	pthread_mutex_lock(&wld_worlds.lock);

	uint16_t id = utl_id_vector_add(&wld_worlds.worlds, &world);

	pthread_mutex_unlock(&wld_worlds.lock);

	return id;

}

wld_world_t* wld_new(const string_t name, int64_t seed, mat_dimension_type_t environment) {

	wld_world_t* world = calloc(1, sizeof(wld_world_t));
	srand(seed);
	wld_world_t world_init = {
		.seed = seed,
		.environment = environment,
		.name = name,
		.id = wld_add(world),
		.spawn = {
			.x = (rand() % 254) - 254,
			.z = (rand() % 254) - 254
		}
	};
	memcpy(world, &world_init, sizeof(wld_world_t));

	wld_prepare_spawn(world);

	return world;

}

wld_world_t* wld_load(const string_t name) {

	wld_world_t* world = calloc(1, sizeof(wld_world_t));
	wld_world_t world_init = {
		.name = name,
		.id = wld_add(world)
	};
	memcpy(world, &world_init, sizeof(wld_world_t));

	// TODO

	wld_prepare_spawn(world);

	return world;

}

void wld_prepare_spawn(wld_world_t* world) {
	
	const int32_t spawn_cx = world->spawn.x >> 5;
	const int32_t spawn_cz = world->spawn.z >> 5;

	// prepare spawn region
	for (int32_t x = spawn_cx - 11; x <= spawn_cx + 11; ++x) {
		for (int32_t z = spawn_cz - 11; z <= spawn_cz + 11; ++z) {
			wld_chunk_t* chunk = wld_get_chunk(world, x, z);
			chunk->max_ticket = UTL_MAX(14 - (11 - UTL_ABS(x - spawn_cx)), 14 - (11 - UTL_ABS(z - spawn_cz)));
		}
	}

}

uint16_t wld_get_count() {
	
	pthread_mutex_lock(&wld_worlds.lock);
	
	uint16_t count = wld_worlds.worlds.size;

	pthread_mutex_unlock(&wld_worlds.lock);

	return count;

}

wld_world_t* wld_get_world(uint16_t world_id) {

	pthread_mutex_lock(&wld_worlds.lock);

	wld_world_t* world = UTL_ID_VECTOR_GET_AS(wld_world_t*, &wld_worlds.worlds, world_id);

	pthread_mutex_unlock(&wld_worlds.lock);

	return world;

}

wld_region_t* wld_gen_region(wld_world_t* world, int16_t x, int16_t z) {

	wld_region_t* region = calloc(1, sizeof(wld_region_t));

	const int64_t key = ((uint64_t) x << 16) + x;
	wld_region_t region_init = {
		.world = world,
		.x = x,
		.z = z,
		.relative = {
			.north = utl_tree_get(&world->regions, key - 1),
			.south = utl_tree_get(&world->regions, key + 1),
			.west = utl_tree_get(&world->regions, key - (1 << 16)),
			.east = utl_tree_get(&world->regions, key + (1 << 16))
		},
		.lock = PTHREAD_MUTEX_INITIALIZER
	};
	memcpy(region, &region_init, sizeof(wld_region_t));

	if (region->relative.north != NULL) {
		pthread_mutex_lock(&region->relative.north->lock);
		region->relative.north->relative.south = region;
		pthread_mutex_unlock(&region->relative.north->lock);
	}
	if (region->relative.south != NULL) {
		pthread_mutex_lock(&region->relative.south->lock);
		region->relative.south->relative.north = region;
		pthread_mutex_unlock(&region->relative.south->lock);
	}
	if (region->relative.west != NULL) {
		pthread_mutex_lock(&region->relative.west->lock);
		region->relative.west->relative.east = region;
		pthread_mutex_unlock(&region->relative.west->lock);
	}
	if (region->relative.east != NULL) {
		pthread_mutex_lock(&region->relative.east->lock);
		region->relative.east->relative.west = region;
		pthread_mutex_unlock(&region->relative.east->lock);
	}

	pthread_mutex_lock(&world->lock);
	utl_tree_put(&world->regions, ((int64_t) x << 16) + z, region);
	pthread_mutex_unlock(&world->lock);

	return region;

}

wld_region_t* wld_get_region(wld_world_t* world, int16_t x, int16_t z) {

	pthread_mutex_lock(&world->lock);
	wld_region_t* region = utl_tree_get(&world->regions, (x << 16) + z);
	pthread_mutex_unlock(&world->lock);

	if (region == NULL) {
		region = wld_gen_region(world, x, z);
	}

	return region;

}

wld_chunk_t* wld_gen_chunk(wld_region_t* region, int8_t x, int8_t z) {

	wld_chunk_t* chunk = calloc(1, sizeof(wld_chunk_t) + sizeof(wld_chunk_section_t) * mat_get_chunk_height(region->world->environment));
	wld_chunk_t chunk_init = {
		.region = region,
		.block_entities = {
			.bytes_per_element = sizeof(void*) // TODO block entity struct
		},
		.x = x,
		.z = z,
		.lock = PTHREAD_MUTEX_INITIALIZER,
		.max_ticket = 15
	};
	memcpy(chunk, &chunk_init, sizeof(wld_chunk_t));

	region->chunks[chunk_init.idx] = chunk;

	return chunk;

}

wld_chunk_t* wld_get_chunk(wld_world_t* world, int32_t x, int32_t z) {

	wld_region_t* region = wld_get_region(world, x >> 5, z >> 5);

	union {

		uint16_t idx: 10;

		struct {

			uint8_t x : 5;
			uint8_t z : 5;

		};

	} chunk_loc = {
		.x = x,
		.z = z
	};

	wld_chunk_t* chunk = region->chunks[chunk_loc.idx];

	if (chunk == NULL) {

		chunk = wld_gen_chunk(region, x, z);

	}

	return chunk;

}

wld_chunk_t* wld_relative_chunk(const wld_chunk_t* chunk, int16_t x, int16_t z) {

	x += chunk->x;
	z += chunk->z;

	int16_t r_x = x >> 5;
	int16_t r_z = z >> 5;

	x &= 0x1F;
	z &= 0x1F;

	wld_region_t* region = chunk->region;

	while (r_x < 0) {
		region = region->relative.west;
		r_x++;
		if (region == NULL) {
			return wld_get_chunk(chunk->region->world, wld_get_chunk_x(chunk) + x, wld_get_chunk_z(chunk) + z);
		}
	}
	while (r_x > 0) {
		region = region->relative.east;
		r_x--;
		if (region == NULL) {
			return wld_get_chunk(chunk->region->world, wld_get_chunk_x(chunk) + x, wld_get_chunk_z(chunk) + z);
		}
	}

	while (r_z < 0) {
		region = region->relative.north;
		r_z++;
		if (region == NULL) {
			return wld_get_chunk(chunk->region->world, wld_get_chunk_x(chunk) + x, wld_get_chunk_z(chunk) + z);
		}
	}
	while (r_z > 0) {
		region = region->relative.south;
		r_z--;
		if (region == NULL) {
			return wld_get_chunk(chunk->region->world, wld_get_chunk_x(chunk) + x, wld_get_chunk_z(chunk) + z);
		}
	}

	union {

		uint16_t idx: 10;

		struct {

			uint8_t x : 5;
			uint8_t z : 5;

		};

	} chunk_loc = {
		.x = x,
		.z = z
	};

	if (region->chunks[chunk_loc.idx] == NULL) {
		wld_gen_chunk(region, x, z);
	}
	return region->chunks[chunk_loc.idx];

}

void wld_free_region(wld_region_t* region) {
	
	pthread_mutex_destroy(&region->lock);

	if (region->relative.north != NULL) {
		pthread_mutex_lock(&region->relative.north->lock);
		region->relative.north->relative.south = NULL;
		pthread_mutex_unlock(&region->relative.north->lock);
	}
	if (region->relative.south != NULL) {
		pthread_mutex_lock(&region->relative.south->lock);
		region->relative.south->relative.north = NULL;
		pthread_mutex_unlock(&region->relative.south->lock);
	}
	if (region->relative.west != NULL) {
		pthread_mutex_lock(&region->relative.west->lock);
		region->relative.west->relative.east = NULL;
		pthread_mutex_unlock(&region->relative.west->lock);
	}
	if (region->relative.east != NULL) {
		pthread_mutex_lock(&region->relative.east->lock);
		region->relative.east->relative.west = NULL;
		pthread_mutex_unlock(&region->relative.east->lock);
	}

	for (size_t i = 0; i < 1024; ++i) {
		if (region->chunks[i] != NULL) {
			pthread_mutex_destroy(&region->chunks[i]->lock);
			free(region->chunks[i]);
		}
	}

	free(region);

}

void wld_unload(wld_world_t* world) {
	
	pthread_mutex_lock(&wld_worlds.lock);

	utl_id_vector_remove(&wld_worlds.worlds, world->id);

	pthread_mutex_unlock(&wld_worlds.lock);

	pthread_mutex_destroy(&world->lock);

	wld_region_t* region;
	while ((region = utl_tree_shift(&world->regions)) != NULL) {
		wld_free_region(region);
	}
	utl_tree_term(&world->regions);

	free(world);

}