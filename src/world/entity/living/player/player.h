#pragma once
#include "../../../../main.h"
#include "../living.h"

typedef enum {

	ent_survival = 0,
	ent_creative = 1,
	ent_adventure = 2,
	ent_spectator = 3

} ent_gamemode_t;

typedef struct {

	ent_living_entity_t living_entity;
	
	const byte_t* uuid;

	float32_t additional_hearts;
	int32_t score;
	
	uint32_t digging;

	byte_t displayed_skin_parts;

	uint8_t held_item : 4;
	byte_t main_hand : 1;

	ent_gamemode_t gamemode : 2;

	bool digging_block : 1;

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


// player specific functions
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

extern uint16_t ent_player_get_break_speed(ent_player_t* player, mat_block_type_t block);

extern void ent_free_player(ent_player_t* entity);