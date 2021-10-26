#pragma once
#include <pthread.h>
#include <math.h>
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

	bool digging_block : 1;
	uint32_t digging;

	itm_item_t inventory[27];
	itm_item_t hotbar[9];
	itm_item_t carried;

	struct {
		itm_item_t* elements[90];
		uint8_t count;
	} paint;

	// for parrots
	ent_living_entity_t* left_shoulder;
	ent_living_entity_t* right_shoulder;

} ent_player_t;

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

extern void ent_set_chunk(ent_entity_t* entity);

static inline void ent_move(ent_entity_t* entity, float64_t x, float64_t y, float64_t z, bool on_ground) {

	entity->position.x = x;
	entity->position.y = y;
	entity->position.z = z;

	entity->on_ground = on_ground;
	
	if (wld_get_chunk_x(entity->chunk) != (((int64_t) floor(x)) >> 4) || wld_get_chunk_z(entity->chunk) != (((int64_t) floor(z)) >> 4)) {

		ent_set_chunk(entity);

	}

}

static inline void ent_look(ent_living_entity_t* entity, float32_t pitch, float32_t yaw, bool on_ground) {
	
	entity->entity.on_ground = on_ground;
	entity->rotation.pitch = pitch;
	entity->rotation.yaw = yaw;

}

static inline void ent_move_look(ent_living_entity_t* entity, float64_t x, float64_t y, float64_t z, float32_t yaw, float32_t pitch, bool on_ground) {

	ent_move(&entity->entity, x, y, z, on_ground);
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

static inline void ent_on_ground(ent_entity_t* entity, bool on_ground) {
	
	entity->on_ground = on_ground;

}

static inline bool ent_player_is_best_tool(const mat_block_t* block, const mat_item_t* item) {

	if (block->mineable) {

		if (item->tool) {

			if (
				(block->mineable_axe && item->tool_axe) ||
				(block->mineable_hoe && item->tool_hoe) ||
				(block->mineable_pickaxe && item->tool_pickaxe) ||
				(block->mineable_shovel && item->tool_shovel)
			) {
				return true;
			}

		}

		return false;
	}

	return true;

}

static inline bool ent_player_can_harvest(const mat_block_t* block, const mat_item_t* item) {

	if (block->needs) {

		if (item->tool) {

			if (
				(block->needs_wooden_tool && item->least_wooden_tool) ||
				(block->needs_stone_tool && item->least_stone_tool) ||
				(block->needs_iron_tool && item->least_iron_tool) ||
				(block->needs_diamond_tool && item->least_diamond_tool)
			) {
				return true;
			}

		}

		return false;

	}

	return true;

}

// player specific functions
static inline uint16_t ent_player_get_break_speed(ent_player_t* player, mat_block_type_t block) {

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

	return ceil(1 / damage);

}

extern void ent_free_player(ent_player_t* entity);
extern void ent_free_entity(ent_entity_t* entity);
