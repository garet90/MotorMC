#include "world_private.h"
#include "../util/vector.h"
#include "../util/id_vector.h"
#include "../listening/listening.h"
#include "../io/logger/logger.h"
#include "../motor.h"
#include "../jobs/jobs.h"
#include "../jobs/scheduler/scheduler.h"
#include "entity/entity.h"
#include <stdlib.h>

utl_id_vector_t wld_worlds = UTL_ID_VECTOR_INITIALIZER(wld_world_t*);

uint16_t wld_add(wld_world_t* world) {
	
	uint16_t id = 0;

	id = utl_id_vector_push(&wld_worlds, &world);

	return id;

}

wld_world_t* wld_new(const string_t name, int64_t seed, mat_dimension_type_t environment) {

	wld_world_t* world = calloc(1, sizeof(wld_world_t));
	srand(seed);
	wld_world_t world_init = {
		.lock = PTHREAD_MUTEX_INITIALIZER,
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
		.lock = PTHREAD_MUTEX_INITIALIZER,
		.name = name,
		.id = wld_add(world)
	};
	memcpy(world, &world_init, sizeof(wld_world_t));

	// TODO

	wld_prepare_spawn(world);

	return world;

}

void wld_prepare_spawn(wld_world_t* world) {
	
	const wld_chunk_t* spawn_chunk = wld_gen_chunk(wld_get_region_at(world, world->spawn.x, world->spawn.z), (world->spawn.x >> 4) & 0x1F, (world->spawn.z >> 4) & 0x1F, 3);

	// prepare spawn region
	for (int32_t x = -11; x <= 11; ++x) {
		for (int32_t z = -11; z <= 11; ++z) {
			assert(UTL_MAX(14 - (11 - UTL_ABS(x)), 14 - (11 - UTL_ABS(z))) != WLD_TICKET_INACCESSIBLE);
			wld_gen_relative_chunk(spawn_chunk, x, z, UTL_MAX(14 - (11 - UTL_ABS(x)), 14 - (11 - UTL_ABS(z))));
		}
	}

}

uint16_t wld_get_count() {

	return wld_worlds.array.size;

}

wld_world_t* wld_get_world(uint16_t world_id) {

	return UTL_ID_VECTOR_GET_AS(wld_world_t*, &wld_worlds, world_id);

}

wld_region_t* wld_gen_region(wld_world_t* world, int16_t x, int16_t z) {

	wld_region_t* region = calloc(1, sizeof(wld_region_t));
	const int64_t key = ((uint64_t) x << 16) + z;

	// tick job
	JOB_CREATE_WORK(tick_job, job_tick_region);
	tick_job->region = region;

	with_lock (&world->lock) {
		wld_region_t region_init = (wld_region_t) {
			.world = world,
			.tick = sch_schedule_repeating(&tick_job->header, 1, 1),
			.x = x,
			.z = z,
			.relative = {
				.north = utl_tree_get(&world->regions, key - 1),
				.south = utl_tree_get(&world->regions, key + 1),
				.west = utl_tree_get(&world->regions, key - (1 << 16)),
				.east = utl_tree_get(&world->regions, key + (1 << 16))
			}
		};
		memcpy(region, &region_init, sizeof(wld_region_t));

		if (region->relative.north != NULL) {
			region->relative.north->relative.south = region;
		}
		if (region->relative.south != NULL) {
			region->relative.south->relative.north = region;
		}
		if (region->relative.west != NULL) {
			region->relative.west->relative.east = region;
		}
		if (region->relative.east != NULL) {
			region->relative.east->relative.west = region;
		}
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

	assert(x < 32 && z < 32);

	wld_chunk_t* chunk = calloc(1, sizeof(wld_chunk_t) + sizeof(wld_chunk_section_t) * mat_get_chunk_height(region->world->environment));
	
	wld_chunk_t chunk_init = {
		.region = region,
		.lock = PTHREAD_MUTEX_INITIALIZER,
		.block_entities = UTL_ID_VECTOR_INITIALIZER(void*), // TODO block entity struct
		.entities = UTL_DLL_INITIALIZER,
		.x = x,
		.z = z,
		.max_ticket = max_ticket,
		.ticket = max_ticket
	};
	for (uint32_t i = 0; i < 256; ++i) {
		chunk_init.highest.motion_blocking[i] = 2;
		chunk_init.highest.world_surface[i] = 2;
	}
	memcpy(chunk, &chunk_init, sizeof(wld_chunk_t));

	region->chunks[(x << 5) + z] = chunk;

	// TODO generate actual chunk
	for (uint32_t g_x  = 0; g_x < 16; ++g_x) {
		for (uint32_t g_z = 0; g_z < 16; ++g_z) {
			chunk->sections[0].blocks[(g_z << 4) + g_x] = mat_get_block_default_protocol_id_by_type(mat_block_stone);
			chunk->sections[0].block_count += 1;
		}
	}

	if (max_ticket < WLD_TICKET_INACCESSIBLE) {
		region->loaded_chunks += 1;
	}

	return chunk;

}

wld_chunk_t* wld_get_chunk(wld_world_t* world, int32_t x, int32_t z) {

	wld_region_t* region = wld_get_region(world, x >> 5, z >> 5);

	x &= 0x1F;
	z &= 0x1F;

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

void wld_set_chunk_ticket(wld_chunk_t* chunk, uint8_t ticket) {
	ticket = UTL_MIN(chunk->max_ticket, ticket);
	if (chunk->ticket == WLD_TICKET_INACCESSIBLE && ticket < WLD_TICKET_INACCESSIBLE) {
		// loading chunk
		chunk->region->loaded_chunks += 1;
	} else if (chunk->ticket < WLD_TICKET_INACCESSIBLE && ticket == WLD_TICKET_INACCESSIBLE) {
		// unloading chunk
		chunk->region->loaded_chunks -= 1;
		if (chunk->region->loaded_chunks == 0) {
			JOB_CREATE_WORK(unload_job, job_unload_region);
			unload_job->region = chunk->region;
			sch_schedule(&unload_job->header, 100); // set to try unload in 5 seconds
		}
	}
	chunk->ticket = ticket;
}

void wld_calc_player_ticket(uint32_t client_id, wld_chunk_t* chunk) {
	
	const ent_player_t* player = ltg_get_client_by_id(client_id)->entity;
	const int32_t c_x = wld_get_chunk_x(chunk);
	const int32_t c_z = wld_get_chunk_z(chunk);
	const wld_chunk_t* player_chunk = player->living_entity.entity.chunk;
	const int32_t p_x = wld_get_chunk_x(player_chunk);
	const int32_t p_z = wld_get_chunk_z(player_chunk);

	const uint32_t distance = UTL_MIN(UTL_ABS(c_x - p_x), UTL_ABS(c_z - p_z));

	if (distance < sky_main.render_distance) {
		chunk->ticket = UTL_MIN(chunk->ticket, WLD_TICKET_TICK_ENTITIES);
	} else {
		chunk->ticket = UTL_MIN(chunk->ticket, distance - sky_main.render_distance + WLD_TICKET_TICK_ENTITIES);
		// TODO if greater should do nothing
	}

}

void wld_unload_region(wld_region_t* region) {

	with_lock (&region->world->lock) {
		utl_tree_remove(&region->world->regions, ((uint64_t) region->x << 16) + region->z);
	}

	wld_free_region(region);

}

void wld_free_region(wld_region_t* region) {

	if (region->relative.north != NULL) {
		region->relative.north->relative.south = NULL;
	}
	if (region->relative.south != NULL) {
		region->relative.south->relative.north = NULL;
	}
	if (region->relative.west != NULL) {
		region->relative.west->relative.east = NULL;
	}
	if (region->relative.east != NULL) {
		region->relative.east->relative.west = NULL;
	}
	
	sch_cancel(region->tick);

	for (size_t i = 0; i < 32 * 32; ++i) {
		if (region->chunks[i] != NULL) {
			pthread_mutex_destroy(&region->chunks[i]->lock);
			utl_bit_vector_term(&region->chunks[i]->subscribers);
			utl_bit_vector_term(&region->chunks[i]->players);
			free(region->chunks[i]);
		}
	}

	free(region);

}

void wld_unload(wld_world_t* world) {
	
	utl_id_vector_remove(&wld_worlds, world->id);

	with_lock (&world->lock) {
		wld_region_t* region;
		while ((region = utl_tree_shift(&world->regions)) != NULL) {
			wld_free_region(region);
		}
		utl_tree_term(&world->regions);
	}
	
	pthread_mutex_destroy(&world->lock);

	free(world);

}

void wld_unload_all() {

	for (uint32_t i = 0; i < wld_worlds.array.size; ++i) {
		wld_world_t* world = UTL_ID_VECTOR_GET_AS(wld_world_t*, &wld_worlds, i);
		utl_id_vector_remove(&wld_worlds, i);

		with_lock (&world->lock) {
			wld_region_t* region;
			while ((region = utl_tree_shift(&world->regions)) != NULL) {
				wld_free_region(region);
			}
			utl_tree_term(&world->regions);
		}

		pthread_mutex_destroy(&world->lock);

		free(world);
	}

}