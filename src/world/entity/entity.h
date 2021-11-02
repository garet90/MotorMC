#pragma once
#include <pthread.h>
#include "../../main.h"
#include "../../io/chat/chat.h"
#include "../../util/lock_util.h"
#include "../positions.h"

typedef enum {

	ent_standing,
	ent_fall_flying,
	ent_sleeping,
	ent_spin_attack,
	ent_sneaking,
	ent_dying

} ent_pose_t;

typedef enum {

	ent_player

} ent_type_t;

typedef struct {

	wld_position_t position;
	wld_chunk_t* _Atomic chunk;
	uint32_t _Atomic chunk_node;

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

} ent_entity_t;

extern uint32_t ent_register_entity(ent_entity_t* entity);
extern ent_entity_t* ent_get_entity_by_id(uint32_t id);

static inline void ent_remove_chunk(ent_entity_t* entity) {

	if (entity->chunk != NULL) {

		with_lock (&entity->chunk->lock) {
			utl_dll_remove(&entity->chunk->entities, entity->chunk_node);
		}
		entity->chunk = NULL;

	}

}

extern void ent_destroy_entity(uint32_t client_id, void* entity);
extern void ent_send_entity(uint32_t client_id, void* entity);

extern void ent_set_chunk(ent_entity_t* entity);

static inline void ent_on_ground(ent_entity_t* entity, bool on_ground) {
	
	entity->on_ground = on_ground;

}

extern void ent_free_entity(ent_entity_t* entity);
