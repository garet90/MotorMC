#pragma once
#include "../../main.h"
#include "../../util/vector.h"

typedef struct mat_hitbox mat_hitbox_t;

typedef struct mat_modifier mat_modifier_t;

typedef struct mat_block_entity mat_block_entity_t;
typedef struct mat_block mat_block_t;

typedef enum mat_tool_type {

	mat_none = 0,
	mat_shears,
	mat_hoe,
	mat_axe,
	mat_pickaxe,
	mat_shovel,
	mat_sword

} mat_tool_type_t;

typedef uint8_t mat_hitbox_id_t;
typedef uint8_t mat_modifier_id_t;
typedef uint8_t mat_block_entity_id_t;
typedef uint8_t mat_block_id_t;

/*
#define MAT_ITEMTYPE_NONE 0
#define MAT_ITEMTYPE_FOOD 1
#define MAT_ITEMTYPE_ARMOR 2
#define MAT_ITEMTYPE_TOOL 3

#define MAT_ARMORTYPE_HELMET 0
#define MAT_ARMORTYPE_CHESTPLATE 1
#define MAT_ARMORTYPE_LEGGINGS 2
#define MAT_ARMORTYPE_BOOTS 3

#define MAT_TOOLTYPE_MISC 0
#define MAT_TOOLTYPE_SHEARS 1
#define MAT_TOOLTYPE_HOE 2
#define MAT_TOOLTYPE_AXE 3
#define MAT_TOOLTYPE_PICKAXE 4
#define MAT_TOOLTYPE_SHOVEL 5
#define MAT_TOOLTYPE_SWORD 6

typedef struct {

	uint8_t maxStackSize;
	uint8_t itemType;

	union {

		struct {

			uint16_t data;

		} none;

		struct {

			uint16_t food;
			float32_t saturation;

		} food;

		struct {

			uint8_t type;
			uint8_t toughness;
			uint16_t defense;
			uint16_t maxDurability;
			float32_t knockbackResistance;

		} armor;

		struct {

			uint8_t type;
			uint8_t toolPowerLevel;
			float32_t attackDamage;
			float32_t attackSpeed;
			float32_t toolSpeed;
			uint32_t maxDurability;

		} tool;

	} typeData;

} mat_item_t;
*/

struct mat_hitbox {

	float32_t x;
	float32_t y;
	float32_t z;
	float32_t width;
	float32_t height;
	float32_t length;

};

struct mat_modifier {

	size_t properties_size;

	struct {

		mat_hitbox_id_t hitbox;

	} properties[];

};

struct mat_block_entity {
	void* null; // todo
};

struct mat_block {

	float32_t blast_resistance;
	float32_t hardness;

	// light
	uint8_t light; // first 4 bits is how much light it blocks, last 4 is how much it emanates

	// tool
	mat_tool_type_t tool;
	uint8_t tool_power; // required tool power to drop item

	// block entity
	mat_block_entity_id_t entity;

	// optional, used if flammable
	uint8_t encouragement; // first bit determines whether can catch from lava
	uint8_t flamability;   // first bit determines whether can burn away

	// state modifiers
	size_t modifier_count;
	mat_modifier_id_t modifiers[];

};
