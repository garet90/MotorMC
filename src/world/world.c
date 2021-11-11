#include "world.h"
#include "../util/vector.h"
#include "../util/id_vector.h"
#include "../listening/listening.h"
#include "../io/logger/logger.h"
#include "../motor.h"
#include "../jobs/scheduler/scheduler.h"
#include "entity/entity.h"
#include <stdlib.h>

// worlds global vector
utl_id_vector_t wld_worlds = UTL_ID_VECTOR_INITIALIZER(wld_world_t*);

uint16_t wld_add(wld_world_t* world) {
	
	uint16_t id = 0;

	id = utl_id_vector_push(&wld_worlds, &world);

	return id;

}

wld_world_t* wld_new(const string_t name, int64_t seed, mat_dimension_type_t environment) {

	wld_world_t* world = calloc(1, sizeof(wld_world_t));
	srand(seed); // seed the random with the world seed (to choose spawn position)
	wld_world_t world_init = {
		.lock = PTHREAD_MUTEX_INITIALIZER,
		.seed = seed,
		.environment = environment,
		.name = name,
		.regions = UTL_TREE_INITIALIZER,
		.id = wld_add(world),
		.spawn = {
			.x = (rand() % 512) - 256,
			.z = (rand() % 512) - 256
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
		.regions = UTL_TREE_INITIALIZER,
		.id = wld_add(world)
	};
	memcpy(world, &world_init, sizeof(wld_world_t));

	// TODO load world

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
	const int64_t key = ((uint64_t) (uint16_t) x << 16) | (uint16_t) z;

	// tick job
	uint32_t tick_job = job_new(job_tick_region, (job_payload_t) { .region = region });

	with_lock (&world->lock) {
		wld_region_t region_init = (wld_region_t) {
			.world = world,
			.x = x,
			.z = z,
			.relative = {
				.north = utl_tree_get(&world->regions, ((uint64_t) (uint16_t) x << 16) | (uint16_t) (z - 1)),
				.south = utl_tree_get(&world->regions, ((uint64_t) (uint16_t) x << 16) | (uint16_t) (z + 1)),
				.west = utl_tree_get(&world->regions, ((uint64_t) (uint16_t) (x - 1) << 16) | (uint16_t) z),
				.east = utl_tree_get(&world->regions, ((uint64_t) (uint16_t) (x + 1) << 16) | (uint16_t) z)
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
		
		region->tick = sch_schedule_repeating(tick_job, 1, 1);
	}

	return region;

}

wld_region_t* wld_get_region(wld_world_t* world, int16_t x, int16_t z) {

	wld_region_t* region = NULL;

	with_lock (&world->lock) {
		region = utl_tree_get(&world->regions, ((uint64_t) (uint16_t) x << 16) | (uint16_t) z);
	}

	if (region == NULL) {
		region = wld_gen_region(world, x, z);
	}

	return region;

}

wld_chunk_t* wld_gen_chunk(wld_region_t* region, uint8_t x, uint8_t z, uint8_t max_ticket) {

	assert(x < 32 && z < 32);

	const uint16_t chunk_height = mat_get_chunk_height(region->world->environment);
	wld_chunk_t* chunk = malloc(sizeof(wld_chunk_t) + sizeof(wld_chunk_section_t) * chunk_height);
	
	wld_chunk_t chunk_init = {
		.region = region,
		.lock = PTHREAD_MUTEX_INITIALIZER,
		.block_entities = UTL_ID_VECTOR_INITIALIZER(void*), // TODO block entity struct
		.entities = UTL_DLL_INITIALIZER,
		.players = UTL_BIT_VECTOR_INITIALIZER,
		.subscribers = UTL_BIT_VECTOR_INITIALIZER,
		.x = x,
		.z = z,
		.max_ticket = max_ticket,
		.ticket = max_ticket
	};
	memcpy(chunk, &chunk_init, sizeof(wld_chunk_t)); // coppy init to chunk
	memset(chunk->sections, 0, sizeof(wld_chunk_section_t) * chunk_height); // set chunk sections to 0

	region->chunks[(x << 5) | z] = chunk;

	// TODO generate actual chunk
	for (uint32_t g_x  = 0; g_x < 16; ++g_x) {
		for (uint32_t g_z = 0; g_z < 16; ++g_z) {
			chunk->sections[(g_x + g_z) >> 4].blocks[(((g_x + g_z) & 0xF) << 8) | (g_z << 4) | g_x] = mat_get_block_default_protocol_id_by_type(mat_block_dirt);
			chunk->sections[(g_x + g_z) >> 4].block_count++;
		}
	}

	// add region
	if (max_ticket < WLD_TICKET_INACCESSIBLE) {
		region->loaded_chunks += 1;
	}

	return chunk;

}

wld_chunk_t* wld_get_chunk(wld_world_t* world, int32_t x, int32_t z) {

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

wld_chunk_t* wld_gen_relative_chunk(const wld_chunk_t* chunk, int16_t x, int16_t z, uint8_t max_ticket) {
	
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

void wld_set_chunk_ticket(wld_chunk_t* chunk, uint8_t ticket) {
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

void wld_calc_player_ticket(uint32_t client_id, wld_chunk_t* chunk) {
	
	const ent_player_t* player = ltg_get_entity(ltg_get_client_by_id(sky_get_listener(), client_id));
	const int32_t c_x = wld_get_chunk_x(chunk);
	const int32_t c_z = wld_get_chunk_z(chunk);
	const wld_chunk_t* player_chunk = player->living_entity.entity.chunk;
	const int32_t p_x = wld_get_chunk_x(player_chunk);
	const int32_t p_z = wld_get_chunk_z(player_chunk);

	const uint32_t distance = UTL_MIN(UTL_ABS(c_x - p_x), UTL_ABS(c_z - p_z));

	const uint8_t server_render_distance = sky_get_render_distance();

	if (distance < server_render_distance) {
		chunk->ticket = UTL_MIN(chunk->ticket, WLD_TICKET_TICK_ENTITIES);
	} else {
		chunk->ticket = UTL_MIN(chunk->ticket, distance - server_render_distance + WLD_TICKET_TICK_ENTITIES);
	}

}

void wld_set_block_send(uint32_t client_id, void* arg) {

	pck_packet_t* packet = arg;
	ltg_client_t* client = ltg_get_client_by_id(sky_get_listener(), client_id);

	ltg_send(client, packet);

}

void wld_set_block_at(wld_chunk_t* chunk, int32_t x, int16_t y, int32_t z, mat_block_protocol_id_t type) {

	wld_chunk_t* block_chunk = wld_relative_chunk(chunk, (x >> 4) - wld_get_chunk_x(chunk), (z >> 4) - wld_get_chunk_z(chunk));
	wld_chunk_section_t* section = wld_chunk_get_section(block_chunk, y >> 4);

	const uint8_t s_x = x & 0xF;
	const uint8_t s_y = y & 0xF;
	const uint8_t s_z = z & 0xF;

	const mat_block_protocol_id_t old_type = section->blocks[(s_y << 8) | (s_z << 4) | s_x];
	const bool old_type_air = mat_get_block_by_type(mat_get_block_type_by_protocol_id(old_type))->air;
	const bool type_air = mat_get_block_by_type(mat_get_block_type_by_protocol_id(type))->air;
	if (old_type_air && !type_air) {
		section->block_count++;

		if (block_chunk->highest.motion_blocking[(s_z << 4) | s_x] < y) {
			block_chunk->highest.motion_blocking[(s_z << 4) | s_x] = y;
		}
	} else if (!old_type_air && type_air) {
		section->block_count--;

		if (block_chunk->highest.motion_blocking[(s_z << 4) | s_x] == y) {
			// TODO calculate new highest motion_blocking block
		}
	}
	section->blocks[(s_y << 8) | (s_z << 4) | s_x] = type;

	// send block to player
	PCK_INLINE(packet, 14, io_big_endian);
	pck_write_var_int(packet, 0x0C);
	pck_write_position(packet, (pck_position_t) {
		.x = x,
		.y = y,
		.z = z
	});
	pck_write_var_int(packet, type);

	utl_bit_vector_foreach(&block_chunk->subscribers, wld_set_block_send, packet);

}

void wld_unload_region(wld_region_t* region) {

	with_lock (&region->world->lock) {
		utl_tree_remove(&region->world->regions, ((uint64_t) wld_region_get_x(region) << 16) | (uint64_t) wld_region_get_z(region));
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
			utl_term_bit_vector(&region->chunks[i]->subscribers);
			utl_term_bit_vector(&region->chunks[i]->players);
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
		utl_term_tree(&world->regions);
	}
	
	pthread_mutex_destroy(&world->lock);

	free(world);

}

void wld_unload_all() {

	for (uint32_t i = 0; i < wld_worlds.array.size; ++i) {
		wld_world_t* world = UTL_ID_VECTOR_GET_AS(wld_world_t*, &wld_worlds, i);
		wld_unload(world);
	}

}
