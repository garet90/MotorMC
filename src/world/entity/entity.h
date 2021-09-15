#pragma once
#include <pthread.h>
#include "../../main.h"
#include "../../io/chat/chat.h"
#include "../../util/lock_util.h"
#include "../positions.h"
#include "../item/item.h"

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
	utl_doubly_linked_node_t* _Atomic chunk_node;

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

typedef struct {

	ent_entity_t entity;

	wld_rotation_t rotation;

	float32_t health;

	uint8_t potion_effect_color;
	uint8_t arrows;
	uint8_t bee_stings;

	wld_block_position_t sleeping_bed;

	itm_item_t armor[4];
	itm_item_t off_hand;
	itm_item_t main_hand; // unused for player

	uint8_t hand : 1;
	bool hand_active : 1;
	bool riptide_spin_attack : 1;
	bool potion_effect_ambient : 1;
	bool sleeping_in_bed : 1;

} ent_living_entity_t;

typedef enum {

	ent_survival = 0,
	ent_creative = 1,
	ent_adventure = 2,
	ent_spectator = 3

} ent_gamemode_t;

typedef struct {

	ent_living_entity_t living_entity;
	float32_t additional_hearts;
	int32_t score;

	byte_t displayed_skin_parts;

	uint8_t held_item : 4;
	byte_t main_hand : 1;

	ent_gamemode_t gamemode : 2;

	itm_item_t inventory[27];
	itm_item_t hotbar[9];
	itm_item_t carried;

	// for parrots
	ent_living_entity_t* left_shoulder;
	ent_living_entity_t* right_shoulder;

} ent_player_t;

extern uint32_t ent_register_entity(ent_entity_t* entity);
extern ent_entity_t* ent_get_entity_by_id(uint32_t id);

static inline void ent_remove_chunk(ent_entity_t* entity) {

	if (entity->chunk != NULL) {

		with_lock (&entity->chunk->lock) {
			utl_dllist_remove_by_reference(&entity->chunk->entities, entity->chunk_node);
		}
		entity->chunk_node = NULL;
		entity->chunk = NULL;

	}

}

extern void ent_set_chunk(ent_entity_t* entity);

static inline void ent_move(ent_entity_t* entity, float64_t x, float64_t y, float64_t z, bool on_ground) {

	if (((uint64_t) entity->position.x >> 4) != ((uint64_t) x >> 4) || ((uint64_t) entity->position.z >> 4) != ((uint64_t) z >> 4)) {

		entity->position.x = x;
		entity->position.y = y;
		entity->position.z = z;
		ent_set_chunk(entity);

	} else {

		entity->position.x = x;
		entity->position.y = y;
		entity->position.z = z;

	}

	entity->on_ground = on_ground;

}

static inline void ent_look(ent_living_entity_t* entity, float32_t pitch, float32_t yaw, bool on_ground) {
	
	entity->entity.on_ground = on_ground;
	entity->rotation.pitch = pitch;
	entity->rotation.yaw = yaw;

}

static inline void ent_move_look(ent_living_entity_t* entity, float64_t x, float64_t y, float64_t z, float32_t yaw, float32_t pitch, bool on_ground) {

	if (((uint64_t) entity->entity.position.x >> 4) != ((uint64_t) x >> 4) || ((uint64_t) entity->entity.position.z >> 4) != ((uint64_t) z >> 4)) {

		entity->entity.position.x = x;
		entity->entity.position.y = y;
		entity->entity.position.z = z;
		ent_set_chunk(&entity->entity);

	} else {

		entity->entity.position.x = x;
		entity->entity.position.y = y;
		entity->entity.position.z = z;

	}

	ent_look(entity, pitch, yaw, on_ground);

}

static inline void ent_teleport(ent_entity_t* entity, wld_world_t* world, float64_t x, float64_t y, float64_t z) {

	entity->position.world = world;
	entity->position.x = x;
	entity->position.y = y;
	entity->position.z = z;
	
	ent_set_chunk(entity);

}

static inline void ent_teleport_look(ent_living_entity_t* entity, wld_world_t* world, float64_t x, float64_t y, float64_t z, float32_t yaw, float32_t pitch) {

	entity->entity.position.world = world;
	entity->entity.position.x = x;
	entity->entity.position.y = y;
	entity->entity.position.z = z;
	entity->rotation.pitch = pitch;
	entity->rotation.yaw = yaw;

	ent_set_chunk(&entity->entity);

}

extern void ent_free_entity(ent_entity_t* entity);
