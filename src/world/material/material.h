#pragma once
#include "../../main.h"

/*
	HITBOX
	Hitboxes are used for physics to determine collisions
*/

typedef enum {

	mat_hitbox_none = -1

} mat_hitbox_id_t;

typedef struct {

	size_t count;

	struct {

		float32_t x, y, z, width, height, depth;
	
	} hitbox[];

} mat_hitbox_t;

extern const mat_hitbox_t* mat_hitboxes;

/*
	STATE MODIFIERS
	State modifiers are used to determine the state
*/

typedef enum {

	_mat_state_modifier_end = 0,
	mat_state_modifier_facing_cardinal,
	mat_state_modifier_bamboo_age,
	mat_state_modifier_bamboo_leaves,
	mat_state_modifier_bamboo_state
	// TODO automatically generate this

} mat_state_modifier_type_t;

typedef struct {

	size_t count;

	struct {

		mat_hitbox_id_t hitbox;

	} state[];

} mat_state_modifier_t;

extern const mat_state_modifier_t* mat_modifiers;

/*
	TOOLS
	Tools are used to determine breaking speed and drops
	They:
	- Can be enchanted
	- Have a max durability (exception: enchanted books)
	- Only appear in stacks of one
*/

typedef enum {

	mat_tool_type_any = 0,
	mat_tool_type_sword,
	mat_tool_type_bow,
	mat_tool_type_crossbow,
	mat_tool_type_trident,
	mat_tool_type_shield,
	mat_tool_type_fishing_rod,
	mat_tool_type_flint_and_steel,
	mat_tool_type_helmet,
	mat_tool_type_chestplate,
	mat_tool_type_leggings,
	mat_tool_type_boots,
	mat_tool_type_axe,
	mat_tool_type_pickaxe,
	mat_tool_type_shears,
	mat_tool_type_shovel,
	mat_tool_type_hoe,
	mat_tool_type_none

} mat_tool_type_t;

typedef enum {

	mat_tool_power_any = 0,
	mat_tool_power_wood,
	mat_tool_power_stone,
	mat_tool_power_gold,
	mat_tool_power_iron,
	mat_tool_power_diamond,
	mat_tool_power_netherrite

} mat_tool_power_t;

typedef struct {

	mat_tool_type_t type;
	mat_tool_power_t power;

	uint32_t max_durability;

} mat_tool_t;

extern const mat_tool_t* mat_tools;

/*
	BLOCK ENTITIES
	Block entities are used to store extra information that couldn't be stored in states
*/

typedef enum {
	mat_block_entity_type_sign,
	mat_block_entity_type_banner,
	mat_block_entity_type_storage,
	mat_block_entity_type_furnace,
	mat_block_entity_type_brewing_stand,
	mat_block_entity_type_hopper,
	mat_block_entity_type_chest,
	mat_block_entity_type_beacon,
	mat_block_entity_type_monster_spawner,
	mat_block_entity_type_note_block,
	mat_block_entity_type_piston,
	mat_block_entity_type_jukebox,
	mat_block_entity_type_enchantment_table,
	mat_block_entity_type_particle,
	mat_block_entity_type_mob_head,
	mat_block_entity_type_command_block,
	mat_block_entity_type_end_gateway,
	mat_block_entity_type_structure_block,
	mat_block_entity_type_daylight_sensor,
	mat_block_entity_type_flower_pot,
	mat_block_entity_type_redstone_comparator
} mat_block_entity_type_t;

/*
	BLOCKS
	Blocks are the basic building blocks of the world
*/

typedef enum {

	mat_block_id_air = 0

} mat_block_id_t;

typedef struct {

	float32_t resistance;
	float32_t hardness;

	uint8_t light;
		// First 4 bits: luminance (0 = no light)
		// Last 4 bits: transparency (0 = blocks all light)

	uint8_t encouragement;
		// most significant bit = can catch fire from lava
	uint8_t flammability;
		// most significant bit = can burn away

	struct {
		
		mat_tool_type_t type;
		mat_tool_power_t power;

	} best_tool;

	mat_block_entity_type_t entity;

	struct {

		size_t count;
		mat_state_modifier_type_t modifier[];

	} modifiers;

} mat_block_t;

extern const mat_block_t* mat_blocks;

static inline uint8_t mat_getLuminance(const mat_block_t* block) {

	return block->light >> 4;

}

static inline uint8_t mat_getTransparency(const mat_block_t* block) {

	return block->light & 0xF;

}

static inline bool_t utl_catchesFireFromLava(const mat_block_t* block) {

	return (block->encouragement & 0x80) ? true : false;

}

static inline bool_t utl_canBurnAway(const mat_block_t* block) {

	return (block->flammability & 0x80) ? true : false;

}

static inline uint8_t utl_getEncouragement(const mat_block_t* block) {

	return block->encouragement & 0x7F;

}

static inline uint8_t utl_getFlammability(const mat_block_t* block) {

	return block->flammability & 0x7F;

}

/*
	ITEMS
*/

typedef enum {

	mat_item_id_dirt

} mat_item_id_t;

typedef enum {

	mat_item_type_item = 0,
	mat_item_type_tool,
	mat_item_type_block,
	mat_item_type_food,
	mat_item_type_consumable

} mat_item_type_t;

typedef union {

	mat_item_type_t type;

	struct {

		uint8_t max_stack_size;

	} item;

	struct {

		mat_tool_type_t type;

	} tool;

	struct {

		mat_block_id_t id;

	} block;

	struct {



	} food;

	struct {



	} consumable;

} mat_item_t;

extern const mat_item_t* items;
