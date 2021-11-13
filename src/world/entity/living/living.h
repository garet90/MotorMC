#pragma once
#include "living.d.h"

#include "../../../main.h"
#include "../../item/item.h"
#include "../entity.h"

struct ent_living_entity {

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

};

static inline ent_entity_t* ent_living_entity_get_entity(ent_living_entity_t* living_entity) {
	return &living_entity->entity;
}

static inline void ent_living_entity_look(ent_living_entity_t* entity, float32_t yaw, float32_t pitch, bool on_ground) {
	job_add(
		job_new(
			job_living_entity_look,
			(job_payload_t) {
				.living_entity_look = {
					.entity = entity,
					.yaw = yaw,
					.pitch = pitch,
					.on_ground = on_ground
				}
			}
		)
	);
}

static inline void ent_living_entity_move_look(ent_living_entity_t* entity, float64_t d_x, float64_t d_y, float64_t d_z, float32_t yaw, float32_t pitch, bool on_ground) {
	job_add(
		job_new(
			job_living_entity_move_look,
			(job_payload_t) {
				.living_entity_move_look = {
					.entity = entity,
					.initial_chunk = ent_get_chunk(ent_living_entity_get_entity(entity)),
					.d_x = d_x,
					.d_y = d_y,
					.d_z = d_z,
					.yaw = yaw,
					.pitch = pitch,
					.on_ground = on_ground
			 	}
			}
		)
	);
}