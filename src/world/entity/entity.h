#pragma once
#include <pthread.h>
#include "../../main.h"
#include "../../io/chat/chat.h"
#include "../positions.h"

typedef enum {
	
	ent_on_fire,
	ent_crouching,
	ent_sprinting,
	ent_swimming,
	ent_invisible,
	ent_glowing_effect,
	ent_flying_elytra,
	ent_custom_name_visible,
	ent_silent,
	ent_no_gravity,
	ent_on_ground,

	ent_status_length

} ent_status_t;

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

	pthread_mutex_t lock;

	wld_position_t position;
	wld_chunk_t* chunk;

	uint32_t id;

	cht_component_t custom_name;
	uint16_t air_ticks;
	uint8_t pose;
	uint8_t type;
	utl_bitset(ent_status_length, status);
	uint8_t powder_snow_ticks;

} ent_entity_t;

static inline bool_t ent_is_sneaking(ent_entity_t* entity) {
	return utl_test_bit(entity->status, ent_crouching);
}

static inline void ent_start_sneaking(ent_entity_t* entity) {
	utl_set_bit(entity->status, ent_crouching);
}

static inline void ent_stop_sneaking(ent_entity_t* entity) {
	utl_reset_bit(entity->status, ent_crouching);
}

static inline bool_t ent_is_sprinting(ent_entity_t* entity) {
	return utl_test_bit(entity->status, ent_sprinting);
}

static inline void ent_start_sprinting(ent_entity_t* entity) {
	utl_set_bit(entity->status, ent_sprinting);
}

static inline void ent_stop_sprinting(ent_entity_t* entity) {
	utl_reset_bit(entity->status, ent_sprinting);
}

static inline bool_t ent_is_flying_with_elytra(ent_entity_t* entity) {
	return utl_test_bit(entity->status, ent_flying_elytra);
}

static inline void ent_start_flying_with_elytra(ent_entity_t* entity) {
	utl_set_bit(entity->status, ent_flying_elytra);
}

static inline void ent_stop_flying_with_elytra(ent_entity_t* entity) {
	utl_reset_bit(entity->status, ent_flying_elytra);
}

typedef enum {

	ent_hand_active,
	ent_active_hand,
	ent_riptide_spin_attack,
	ent_potion_effect_ambient,
	ent_sleeping_in_bed,

	ent_living_status_length

} ent_living_status_t;

typedef struct {

	ent_entity_t entity;

	wld_rotation_t rotation;

	float32_t health;

	uint8_t potion_effect_color;
	uint8_t arrows;
	uint8_t bee_stings;

	wld_block_position_t sleeping_bed;

	utl_bitset(ent_living_status_length, living_status);

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

	uint8_t held_item;

	byte_t displayed_skin_parts;
	byte_t main_hand;

	uint8_t gamemode;

	// for parrots
	ent_living_entity_t* left_shoulder;
	ent_living_entity_t* right_shoulder;

} ent_player_t;

extern uint32_t ent_register_entity(ent_entity_t* entity);
extern ent_entity_t* ent_get_entity_by_id(uint32_t id);

extern void ent_free_entity(ent_entity_t* entity);
