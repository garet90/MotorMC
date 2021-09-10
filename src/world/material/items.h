#pragma once

/*
	Equipment
	Equipment are used to determine breaking speed and drops
	They:
	- Have a max durability
	- Only appear in stacks of one
*/

typedef enum {

	mat_equipment_type_any = 0,

	mat_equipment_type_sword,
	mat_equipment_type_axe,
	mat_equipment_type_pickaxe,
	mat_equipment_type_shovel,
	mat_equipment_type_hoe,
	
	// shears do no additional damage but have breaking time boosts
	mat_equipment_type_shears,
	
	// tridents have no breaking time benefit but still do melee damage
	mat_equipment_type_trident,

	mat_equipment_type_bow,
	mat_equipment_type_crossbow,
	mat_equipment_type_fishing_rod,
	mat_equipment_type_flint_and_steel,

	// everything helmet and above has different properties
	// (instead of attack speed and damage, armor toughness and defense)

	mat_equipment_type_helmet,
	mat_equipment_type_chestplate,
	mat_equipment_type_leggings,
	mat_equipment_type_boots,
	mat_equipment_type_shield

} mat_equipment_type_t;

typedef enum {

	mat_equipment_tier_any = 0,

	mat_equipment_tier_leather,
	mat_equipment_tier_wood,
	mat_equipment_tier_stone,
	mat_equipment_tier_gold,
	mat_equipment_tier_iron,
	mat_equipment_tier_diamond,
	mat_equipment_tier_netherite

} mat_equipment_tier_t;

/*
	ITEMS
*/

typedef enum {

	mat_item_air = 0,
	mat_item_stone_block = 1

} mat_item_type_t;