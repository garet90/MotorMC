#include <pthread.h>
#include <stdlib.h>
#include "entity.h"
#include "../../util/id_vector.h"
#include "../../util/lock_util.h"
#include "../../motor.h"
#include "../../jobs/scheduler/scheduler.h"

utl_id_vector_t ent_entities = UTL_ID_VECTOR_INITIALIZER(ent_entity_t*);

uint32_t ent_register_entity(ent_entity_t* entity) {
	
	uint32_t id = utl_id_vector_push(&ent_entities, &entity);
	memcpy((uint32_t*) &entity->id, &id, sizeof(id));

	pthread_mutex_init(&entity->lock, NULL);
	
	ent_set_chunk(entity);

	return entity->id;

}

ent_entity_t* ent_get_entity_by_id(uint32_t id) {

	ent_entity_t* entity = UTL_ID_VECTOR_GET_AS(ent_entity_t*, &ent_entities, id);

	return entity;

}

void ent_set_chunk(ent_entity_t* entity) {

	wld_chunk_t* chunk = NULL;

	const int64_t f_x = utl_int_floor(entity->position.x);
	const int64_t f_z = utl_int_floor(entity->position.z);

	if (entity->chunk != NULL) {

		// try relative
		int32_t o_x = wld_get_chunk_x(entity->chunk);
		int32_t o_z = wld_get_chunk_z(entity->chunk);
		int32_t n_x = f_x >> 4;
		int32_t n_z = f_z >> 4;

		if (UTL_ABS(n_x - o_x) < sky_main.render_distance && UTL_ABS(n_z - o_z) < sky_main.render_distance) {
			
			chunk = wld_relative_chunk(entity->chunk, n_x - o_x, n_z - o_z);
			
		} else { // set absolute (o(logn))

			chunk = wld_get_chunk_at(entity->position.world, f_x, f_z);
		}
		ent_remove_chunk(entity);
	} else {
		// set absolute (o(logn))
		chunk = wld_get_chunk_at(entity->position.world, f_x, f_z);
	}

	assert(chunk != NULL);

	entity->chunk_node = utl_dll_push(&chunk->entities, entity);

	entity->chunk = chunk;

}

uint16_t ent_player_get_break_speed(ent_player_t* player, mat_block_type_t block) {

	float32_t speed_multiplier = 1;

	const mat_block_t* block_data = mat_get_block_by_type(block);

	itm_item_t* held = &player->hotbar[player->held_item];
	const mat_item_t* held_data = mat_get_item_by_type(held->type);

	const bool is_best_tool = ent_player_is_best_tool(block_data, held_data);
	const bool can_harvest = ent_player_can_harvest(block_data, held_data);
	
	if (is_best_tool) {
		// TODO speed_multiplier = tool_power;
		if (!can_harvest) {
			speed_multiplier = 1;
		}
		// TODO efficiency
	}

	float32_t damage = speed_multiplier / block_data->hardness;

	if (can_harvest) {
		damage /= 30;
	} else {
		damage /= 100;
	}

	// instant break
	if (damage > 1) {
		return 0;
	}

	return utl_int_ceil(1 / damage);

}

void ent_free_player(ent_player_t* entity) {

	if (entity->digging_block) {
		sch_cancel(entity->digging);
	}

	ent_free_entity((ent_entity_t*) entity);

}

void ent_free_entity(ent_entity_t* entity) {

	ent_remove_chunk(entity);

	utl_id_vector_remove(&ent_entities, entity->id);

	pthread_mutex_destroy(&entity->lock);

	free(entity);

}