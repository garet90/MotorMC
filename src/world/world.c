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
	
	uint16_t id = 0;

	with_lock (&wld_worlds.lock) {
		id = utl_id_vector_add(&wld_worlds.worlds, &world);
	}

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
	pthread_mutex_init(&world->lock, NULL);

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
	pthread_mutex_init(&world->lock, NULL);

	// TODO

	wld_prepare_spawn(world);

	return world;

}

void wld_prepare_spawn(wld_world_t* world) {
	
	const wld_chunk_t* spawn_chunk = wld_gen_chunk(wld_get_region_at(world, world->spawn.x, world->spawn.z), world->spawn.x & 0x1F, world->spawn.z & 0x1F, WLD_TICKET_TICK_ENTITIES);

	// prepare spawn region
	for (int32_t x = -11; x <= 11; ++x) {
		for (int32_t z = -11; z <= 11; ++z) {
			wld_gen_relative_chunk(spawn_chunk, x, z, UTL_MAX(14 - (11 - UTL_ABS(x)), 14 - (11 - UTL_ABS(z))));
		}
	}

}

uint16_t wld_get_count() {
	
	uint16_t count = 0;

	with_lock (&wld_worlds.lock) {
		count = wld_worlds.worlds.size;
	}

	return count;

}

wld_world_t* wld_get_world(uint16_t world_id) {

	wld_world_t* world = NULL;

	with_lock (&wld_worlds.lock) {
		world = UTL_ID_VECTOR_GET_AS(wld_world_t*, &wld_worlds.worlds, world_id);
	}

	return world;

}

wld_region_t* wld_gen_region(wld_world_t* world, int16_t x, int16_t z) {

	wld_region_t* region = calloc(1, sizeof(wld_region_t));

	const int64_t key = ((uint64_t) x << 16) + z;
	with_lock (&wld_worlds.lock) {
		wld_region_t region_init = (wld_region_t) {
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
	}

	if (region->relative.north != NULL) {
		with_lock (&region->relative.north->lock) {
			region->relative.north->relative.south = region;
		}
	}
	if (region->relative.south != NULL) {
		with_lock (&region->relative.south->lock) {
			region->relative.south->relative.north = region;
		}
	}
	if (region->relative.west != NULL) {
		with_lock (&region->relative.west->lock) {
			region->relative.west->relative.east = region;
		}
	}
	if (region->relative.east != NULL) {
		with_lock (&region->relative.east->lock) {
			region->relative.east->relative.west = region;
		}
	}

	with_lock (&world->lock) {
		utl_tree_put(&world->regions, key, region);
	}

	return region;

}

wld_region_t* wld_get_region(wld_world_t* world, int16_t x, int16_t z) {

	wld_region_t* region = NULL;
	with_lock (&world->lock) {
		region = utl_tree_get(&world->regions, ((uint64_t) x << 16) + z);
	}

	if (region == NULL) {
		region = wld_gen_region(world, x, z);
	}

	return region;

}

wld_chunk_t* wld_gen_chunk(wld_region_t* region, int8_t x, int8_t z, uint8_t max_ticket) {

	wld_chunk_t* chunk = calloc(1, sizeof(wld_chunk_t) + sizeof(wld_chunk_section_t) * mat_get_chunk_height(region->world->environment));
	wld_chunk_t chunk_init = {
		.region = region,
		.block_entities = {
			.bytes_per_element = sizeof(void*) // TODO block entity struct
		},
		.x = x,
		.z = z,
		.max_ticket = max_ticket
	};
	memcpy(chunk, &chunk_init, sizeof(wld_chunk_t));

	pthread_mutex_init(&chunk->lock, NULL);

	region->chunks[(x << 5) + z] = chunk;

	return chunk;

}

wld_chunk_t* wld_get_chunk(wld_world_t* world, int32_t x, int32_t z) {

	wld_region_t* region = wld_get_region(world, x >> 5, z >> 5);

	wld_chunk_t* chunk = region->chunks[(x << 5) + z];

	if (chunk == NULL) {

		chunk = wld_gen_chunk(region, x, z, WLD_TICKET_MAX);

	}

	return chunk;

}

wld_chunk_t* wld_relative_chunk(const wld_chunk_t* chunk, int32_t x, int32_t z) {

	x += chunk->x;
	z += chunk->z;

	int16_t r_x = x >> 5;
	int16_t r_z = z >> 5;

	x &= 0x1F;
	z &= 0x1F;

	wld_region_t* region = chunk->region;

	while (r_x < 0) {
		if (region->relative.west == NULL) {
			region = wld_get_region(region->world, region->x - 1, region->z);
		} else {
			region = region->relative.west;
		}
		r_x++;
	}
	while (r_x > 0) {
		if (region->relative.east == NULL) {
			region = wld_get_region(region->world, region->x + 1, region->z);
		} else {
			region = region->relative.east;
		}
		r_x--;
	}

	while (r_z < 0) {
		if (region->relative.north == NULL) {
			region = wld_get_region(region->world, region->x, region->z - 1);
		} else {
			region = region->relative.north;
		}
		r_z++;
	}
	while (r_z > 0) {
		if (region->relative.south == NULL) {
			region = wld_get_region(region->world, region->x, region->z + 1);
		} else {
			region = region->relative.south;
		}
		r_z--;
	}

	if (region->chunks[(x << 5) + z] == NULL) {
		wld_gen_chunk(region, x, z, WLD_TICKET_MAX);
	}
	return region->chunks[(x << 5) + z];

}

wld_chunk_t* wld_gen_relative_chunk(const wld_chunk_t* chunk, int16_t x, int16_t z, uint8_t max_ticket) {
	
	x += chunk->x;
	z += chunk->z;

	int16_t r_x = x >> 5;
	int16_t r_z = z >> 5;

	x &= 0x1F;
	z &= 0x1F;

	wld_region_t* region = chunk->region;

	while (r_x < 0) {
		if (region->relative.west == NULL) {
			return wld_gen_chunk(wld_get_region(chunk->region->world, region->x - 1, region->z), x, z, max_ticket);
		}
		region = region->relative.west;
		r_x++;
	}
	while (r_x > 0) {
		if (region->relative.east == NULL) {
			return wld_gen_chunk(wld_get_region(chunk->region->world, region->x + 1, region->z), x, z, max_ticket);
		}
		region = region->relative.east;
		r_x--;
	}

	while (r_z < 0) {
		if (region->relative.north == NULL) {
			return wld_gen_chunk(wld_get_region(chunk->region->world, region->x, region->z - 1), x, z, max_ticket);
		}
		region = region->relative.north;
		r_z++;
	}
	while (r_z > 0) {
		if (region->relative.south == NULL) {
			return wld_gen_chunk(wld_get_region(chunk->region->world, region->x, region->z + 1), x, z, max_ticket);
		}
		region = region->relative.south;
		r_z--;
	}

	if (region->chunks[(x << 5) + z] == NULL) {
		wld_gen_chunk(region, x, z, max_ticket);
	}
	return region->chunks[(x << 5) + z];

}

void wld_free_region(wld_region_t* region) {
	
	pthread_mutex_destroy(&region->lock);

	if (region->relative.north != NULL) {
		with_lock (&region->relative.north->lock) {
			region->relative.north->relative.south = NULL;
		}
	}
	if (region->relative.south != NULL) {
		with_lock (&region->relative.south->lock) {
			region->relative.south->relative.north = NULL;
		}
	}
	if (region->relative.west != NULL) {
		with_lock (&region->relative.west->lock) {
			region->relative.west->relative.east = NULL;
		}
	}
	if (region->relative.east != NULL) {
		with_lock (&region->relative.east->lock) {
			region->relative.east->relative.west = NULL;
		}
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
	
	with_lock (&wld_worlds.lock) {
		utl_id_vector_remove(&wld_worlds.worlds, world->id);
	}

	pthread_mutex_destroy(&world->lock);

	wld_region_t* region;
	while ((region = utl_tree_shift(&world->regions)) != NULL) {
		wld_free_region(region);
	}
	utl_tree_term(&world->regions);

	free(world);

}

void wld_unload_all() {

	with_lock (&wld_worlds.lock) {

		for (uint32_t i = 0; i < wld_worlds.worlds.size; ++i) {
			wld_world_t* world = UTL_ID_VECTOR_GET_AS(wld_world_t*, &wld_worlds.worlds, i);
			utl_id_vector_remove(&wld_worlds.worlds, i);
			
			pthread_mutex_destroy(&world->lock);

			wld_region_t* region;
			while ((region = utl_tree_shift(&world->regions)) != NULL) {
				wld_free_region(region);
			}
			utl_tree_term(&world->regions);

			free(world);
		}

	}

}