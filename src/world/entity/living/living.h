#pragma once
#include "../../../main.h"
#include "../entity.h"
#include "../../item/item.h"

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