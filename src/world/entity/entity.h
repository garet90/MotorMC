#pragma once
#include <pthread.h>

#include "entity.d.h"

#include "../../main.h"
#include "../../io/chat/chat.h"
#include "../../util/lock_util.h"
#include "../../jobs/board.h"
#include "../positions.h"

struct ent_entity {

	wld_position_t position;
	
	wld_chunk_t* chunk;
	uint32_t chunk_node;

	const uint32_t id;
	const ent_type_t type;

	pthread_mutex_t lock;

	cht_component_t custom_name;
	uint16_t air_ticks;
	ent_pose_t pose : 5;

	bool on_fire : 1;
	bool crouching : 1;
	bool sprinting : 1;
	bool swimming : 1;
	bool invisible : 1;
	bool glowing : 1;
	
	bool flying_with_elytra : 1;
	bool custom_name_visible : 1;
	bool silent : 1;
	bool no_gravity : 1;
	bool on_ground : 1;
	uint8_t powder_snow_ticks;

};

extern uint32_t ent_register_entity(ent_entity_t* entity);
extern ent_entity_t* ent_get_entity_by_id(uint32_t id);

static inline uint32_t ent_get_id(ent_entity_t* entity) {
	return entity->id;
}

static inline ent_type_t ent_get_type(ent_entity_t* entity) {
	return entity->type;
}

static inline float64_t ent_get_x(ent_entity_t* entity) {
	return entity->position.x;
}

static inline int64_t ent_get_block_x(ent_entity_t* entity) {
	return utl_int_floor(entity->position.x);
}

static inline float64_t ent_get_y(ent_entity_t* entity) {
	return entity->position.y;
}

static inline int64_t ent_get_block_y(ent_entity_t* entity) {
	return utl_int_floor(entity->position.y);
}

static inline float64_t ent_get_z(ent_entity_t* entity) {
	return entity->position.z;
}

static inline uint64_t ent_get_block_z(ent_entity_t* entity) {
	return utl_int_floor(entity->position.z);
}

static inline wld_chunk_t* ent_get_chunk(ent_entity_t* entity) {
	
	wld_chunk_t* chunk = NULL;

	with_lock (&entity->lock) {
		chunk = entity->chunk;
	}

	return chunk;
	
}

static inline wld_world_t* ent_get_world(ent_entity_t* entity) {
	return entity->position.world;
}

static inline bool ent_is_on_ground(ent_entity_t* entity) {
	return entity->on_ground;
}

static inline void ent_set_crouching(ent_entity_t* entity, bool crouching) {
	// TODO maybe lock
	entity->crouching = crouching;
}

static inline void ent_set_sprinting(ent_entity_t* entity, bool sprinting) {
	entity->sprinting = sprinting;
}

static inline void ent_set_flying_with_elytra(ent_entity_t* entity, bool flying_with_elytra) {
	entity->flying_with_elytra = flying_with_elytra;
}

static inline void ent_remove_chunk(ent_entity_t* entity) {

	with_lock (&entity->lock) {

		if (entity->chunk != NULL) {

			wld_chunk_remove_entity(entity->chunk, entity->chunk_node);
			entity->chunk = NULL;

		}

	}

}

static inline void ent_move(ent_entity_t* entity, float64_t d_x, float64_t d_y, float64_t d_z, bool on_ground) {
	job_add(job_new(job_entity_move, (job_payload_t) { .entity_move = { .entity = entity, .initial_chunk = ent_get_chunk(entity), .d_x = d_x, .d_y = d_y, .d_z = d_z, .on_ground = on_ground } }));
}

extern void ent_set_chunk(ent_entity_t* entity);

static inline void ent_set_on_ground(ent_entity_t* entity, bool on_ground) {
	
	with_lock (&entity->lock) {
		entity->on_ground = on_ground;
	}

}

static inline bool ent_is_le(ent_entity_t* entity) {

	const uint8_t le_map[ent_type_count] = {
		false, false, false, false, false, false, false, false, false, false,
		false, false, false, false, false, false, false, false, false, false,
		false, false, false, false, false, false, false, false, false, false,
		false, false, false, false, false, false, false, false, false, false,
		false, false, false, false, false, false, false, false, false, false,
		false, false, false, false, false, false, false, false, false, false,
		false, false, false, false, false, false, false, false, false, false,
		false, false, false, false, false, false, false, false, false, false,
		false, false, false, false, false, false, false, false, false, false,
		false, false, false, false, false, false, false, false, false, false,
		false, false, false, false, false, false, false, false, false, false,
		false, true , false
	};

	return le_map[entity->type];
}

extern void ent_free_entity(ent_entity_t* entity);
extern void ent_free(ent_entity_t* entity);