#include "world_private.h"
#include "../util/vector.h"
#include "../util/id_vector.h"
#include "../listening/listening.h"
#include "entity/entity.h"
#include <stdlib.h>
#include <string.h>

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

wld_world_t* wld_new(const char* name, int64_t seed, mat_dimension_type_t environment) {

	wld_world_t* world = calloc(1, sizeof(wld_world_t));
	world->seed = seed;
	world->environment = environment;
	world->name.value = name;
	world->name.length = strlen(name);

	world->id = wld_add(world);

	srand(seed);
	world->spawn.x = (rand() % 254) - 254;
	world->spawn.z = (rand() % 254) - 254;

	int32_t spawn_cx = world->spawn.x >> 5;
	int32_t spawn_cz = world->spawn.z >> 5;
	// generate spawn regions
	for (int32_t x = spawn_cx - 12; x <= spawn_cx + 12; ++x) {
		for (int32_t z = spawn_cz - 12; z <= spawn_cz + 12; ++z) {
			wld_get_chunk(world, x, z);
		}
	}

	return world;

}

wld_world_t* wld_load(const char* name) {

	wld_world_t* world = calloc(1, sizeof(wld_world_t));
	world->name.value = name;
	world->name.length = strlen(name);

	world->id = wld_add(world);

	// TODO

	return world;

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

inline void wld_set_relatives(wld_world_t* world, wld_region_t* region) {
    
	const int64_t key = ((uint64_t) region->x << 16) + region->z;
	region->relative.north = utl_tree_get(&world->regions, key - 1);
	if (region->relative.north != NULL) {
		region->relative.north->relative.south = region;
	}
	region->relative.south = utl_tree_get(&world->regions, key + 1);
	if (region->relative.south != NULL) {
		region->relative.south->relative.north = region;
	}
	region->relative.west = utl_tree_get(&world->regions, key - (1 << 16));
	if (region->relative.west != NULL) {
		region->relative.west->relative.east = region;
	}
	region->relative.east = utl_tree_get(&world->regions, key + (1 << 16));
	if (region->relative.east != NULL) {
		region->relative.east->relative.west = region;
	}

}

wld_region_t* wld_gen_region(wld_world_t* world, int16_t x, int16_t z) {

	wld_region_t* region = calloc(1, sizeof(wld_region_t));
	region->world = world;
	region->x = x;
	region->z = z;
	wld_set_relatives(world, region);

	pthread_mutex_lock(&world->lock);
	utl_tree_put(&world->regions, ((int64_t) x << 16) + z, region);
	pthread_mutex_unlock(&world->lock);

	return region;

}

wld_region_t* wld_get_region(wld_world_t* world, int16_t x, int16_t z) {

	pthread_mutex_lock(&world->lock);
	wld_region_t* region = utl_tree_get(&world->regions, ((int64_t) x << 16) + z);
	pthread_mutex_unlock(&world->lock);

	if (region == NULL) {
		region = wld_gen_region(world, x, z);
	}

	return region;

}

wld_chunk_t* wld_gen_chunk(wld_region_t* region, uint16_t idx) {

	const mat_dimension_t* dimension = mat_get_dimension_by_type(region->world->environment);
	const uint16_t dimension_height = (dimension->height - dimension->min_y) >> 4;

	wld_chunk_t* chunk = calloc(1, sizeof(wld_chunk_t) + sizeof(wld_chunk_section_t) * dimension_height);
	chunk->region = region;
	chunk->block_entities.bytes_per_element = sizeof(void*); // TODO block entity struct
	chunk->idx = idx;

	region->chunks[idx] = chunk;

	return chunk;

}

wld_chunk_t* wld_get_chunk(wld_world_t* world, int32_t x, int32_t z) {

	wld_region_t* region = wld_get_region(world, x >> 5, z >> 5);
	const uint16_t idx = ((x & 0x1F) << 5) + (z & 0x1F);

	wld_chunk_t* chunk = region->chunks[idx];

	if (chunk == NULL) {

		chunk = wld_gen_chunk(region, idx);
		region->chunks[idx] = chunk;

	}

	return chunk;

}

void wld_unload(wld_world_t* world) {
	
	pthread_mutex_lock(&wld_worlds.lock);

	utl_id_vector_remove(&wld_worlds.worlds, world->id);

	pthread_mutex_unlock(&wld_worlds.lock);

	free(world);

}