#pragma once
#include "../../main.h"
#include "../../util/bitset.h"

/*
	DIMENSIONS
*/

enum mat_dimension_type {

	mat_dimension_overworld,
	mat_dimension_nether,
	mat_dimension_end,

	mat_dimension_count

};

typedef uint8_t mat_dimension_type_t;

typedef enum {

	mat_dimension_piglin_safe,
	mat_dimension_natural,
	mat_dimension_respawn_anchor,
	mat_dimension_skylight,
	mat_dimension_bed,
	mat_dimension_raids,
	mat_dimension_ultrawarm,
	mat_dimension_ceiling,

	mat_dimension_properties_count

} mat_dimension_properties_t;

typedef struct {

	const char* name;
	const char* effects;
	float32_t ambient_light;
	float32_t coordinate_scale;
	uint16_t fixed_time; // 0xFFFF = no fixed time
	uint16_t min_y;
	uint16_t height;
	uint16_t logical_height;
	uint16_t name_length;
	uint16_t effects_length;
	utl_bitset(mat_dimension_properties_count, properties);

} mat_dimension_t;

extern const mat_dimension_t* mat_dimensions[];

static inline const mat_dimension_t* mat_get_dimension_by_type(mat_dimension_type_t type) {
	return mat_dimensions[type];
}

static inline bool_t mat_dimension_is_piglin_safe(mat_dimension_type_t dimension) {
	return utl_test_bit(mat_get_dimension_by_type(dimension)->properties, mat_dimension_piglin_safe);
}

static inline bool_t mat_dimension_is_natural(mat_dimension_type_t dimension) {
	return utl_test_bit(mat_get_dimension_by_type(dimension)->properties, mat_dimension_natural);
}

static inline bool_t mat_dimension_respawn_anchor_works(mat_dimension_type_t dimension) {
	return utl_test_bit(mat_get_dimension_by_type(dimension)->properties, mat_dimension_respawn_anchor);
}

static inline bool_t mat_dimension_has_skylight(mat_dimension_type_t dimension) {
	return utl_test_bit(mat_get_dimension_by_type(dimension)->properties, mat_dimension_skylight);
}

static inline bool_t mat_dimension_bed_works(mat_dimension_type_t dimension) {
	return utl_test_bit(mat_get_dimension_by_type(dimension)->properties, mat_dimension_bed);
}

static inline bool_t mat_dimension_has_raids(mat_dimension_type_t dimension) {
	return utl_test_bit(mat_get_dimension_by_type(dimension)->properties, mat_dimension_raids);
}

static inline bool_t mat_dimension_is_ultrawarm(mat_dimension_type_t dimension) {
	return utl_test_bit(mat_get_dimension_by_type(dimension)->properties, mat_dimension_ultrawarm);
}

static inline bool_t mat_dimension_has_ceiling(mat_dimension_type_t dimension) {
	return utl_test_bit(mat_get_dimension_by_type(dimension)->properties, mat_dimension_ceiling);
}

static inline bool_t mat_dimension_has_fixed_time(mat_dimension_type_t dimension) {
	return mat_get_dimension_by_type(dimension)->fixed_time == 0xFFFF ? false : true;
}

static inline uint16_t mat_dimension_get_fixed_time(mat_dimension_type_t dimension) {
	return mat_get_dimension_by_type(dimension)->fixed_time;
}

/*
	BIOMES
*/

enum mat_biome_type {

	mat_biome_badlands,
	mat_biome_badlands_plateau,
	mat_biome_bamboo_jungle,
	mat_biome_bamboo_jungle_hills,
	mat_biome_basalt_deltas,
	mat_biome_beach,
	mat_biome_birch_forest,
	mat_biome_birch_forest_hills,
	mat_biome_cold_ocean,
	mat_biome_crimson_forest,
	mat_biome_dark_forest,
	mat_biome_dark_forest_hills,
	mat_biome_deep_cold_ocean,
	mat_biome_deep_frozen_ocean,
	mat_biome_deep_lukewarm_ocean,
	mat_biome_deep_ocean,
	mat_biome_deep_warm_ocean,
	mat_biome_desert,
	mat_biome_desert_hills,
	mat_biome_desert_lakes,
	mat_biome_dripstone_caves,
	mat_biome_end_barrens,
	mat_biome_end_highlands,
	mat_biome_end_midlands,
	mat_biome_eroded_badlands,
	mat_biome_flower_forest,
	mat_biome_forest,
	mat_biome_frozen_ocean,
	mat_biome_frozen_river,
	mat_biome_giant_spruce_taiga,
	mat_biome_giant_spruce_taiga_hills,
	mat_biome_giant_tree_taiga,
	mat_biome_giant_tree_taiga_hills,
	mat_biome_gravelly_mountains,
	mat_biome_ice_spikes,
	mat_biome_jungle,
	mat_biome_jungle_edge,
	mat_biome_jungle_hills,
	mat_biome_lukewarm_ocean,
	mat_biome_lush_caves,
	mat_biome_modified_badlands_plateau,
	mat_biome_modified_gravelly_mountains,
	mat_biome_modified_jungle,
	mat_biome_modified_jungle_edge,
	mat_biome_modified_wooded_badlands_plateau,
	mat_biome_mountain_edge,
	mat_biome_mountains,
	mat_biome_mushroom_field_shore,
	mat_biome_mushroom_fields,
	mat_biome_nether_wastes,
	mat_biome_ocean,
	mat_biome_plains,
	mat_biome_river,
	mat_biome_savanna,
	mat_biome_savanna_plateau,
	mat_biome_shattered_savanna,
	mat_biome_shattered_savanna_plateau,
	mat_biome_small_end_islands,
	mat_biome_snowy_beach,
	mat_biome_snowy_mountains,
	mat_biome_snowy_taiga,
	mat_biome_snowy_taiga_hills,
	mat_biome_snowy_taiga_mountains,
	mat_biome_snowy_tundra,
	mat_biome_soul_sand_valley,
	mat_biome_stone_shore,
	mat_biome_sunflower_plains,
	mat_biome_swamp,
	mat_biome_swamp_hills,
	mat_biome_taiga,
	mat_biome_taiga_hills,
	mat_biome_taiga_mountains,
	mat_biome_tall_birch_forest,
	mat_biome_tall_birch_hills,
	mat_biome_the_end,
	mat_biome_the_void,
	mat_biome_warm_ocean,
	mat_biome_warped_forest,
	mat_biome_wooded_badlands_plateau,
	mat_biome_wooded_hills,
	mat_biome_wooded_mountains,

	mat_biome_count

};

typedef uint8_t mat_biome_type_t;

typedef enum {

	mat_precipitation_rain,
	mat_precipitation_snow,
	mat_precipitation_none

} mat_precipitation_type_t;

static inline const char* mat_precipitation_type_string(mat_precipitation_type_t type) {

	const char* types[] = {
		"rain",
		"snow",
		"none"
	};

	return types[type];

}

static inline uint16_t mat_precipitation_type_length(mat_precipitation_type_t type) {

	const uint16_t types[] = {
		4,
		4,
		4
	};

	return types[type];

}

typedef enum {

	mat_biome_category_none,
	mat_biome_category_ocean,
	mat_biome_category_plains,
	mat_biome_category_desert,
	mat_biome_category_forest,
	mat_biome_category_extreme_hills,
	mat_biome_category_taiga,
	mat_biome_category_swamp,
	mat_biome_category_river,
	mat_biome_category_nether,
	mat_biome_category_the_end,
	mat_biome_category_icy,
	mat_biome_category_mushroom,
	mat_biome_category_beach,
	mat_biome_category_jungle,
	mat_biome_category_mesa,
	mat_biome_category_savanna,
	mat_biome_category_underground,

} mat_biome_category_t;

static inline const char* mat_biome_category_string(mat_biome_category_t category) {

	const char* categories[] = {
		"none",
		"ocean",
		"plains",
		"desert",
		"forest",
		"extreme_hills",
		"taiga",
		"swamp",
		"river",
		"nether",
		"the_end",
		"icy",
		"mushroom",
		"beach",
		"jungle",
		"mesa",
		"savanna",
		"underground",
	};

	return categories[category];

}

static inline uint16_t mat_biome_category_length(mat_biome_category_t category) {

	const uint16_t categories[] = {
		4,
		5,
		6,
		6,
		6,
		13,
		5,
		5,
		5,
		6,
		7,
		3,
		8,
		5,
		6,
		4,
		7,
		11
	};

	return categories[category];

}

typedef enum {

	mat_grass_color_modifier_none,
	mat_grass_color_modifier_swamp,
	mat_grass_color_modifier_dark_forest

} mat_grass_color_modifier_t;

static inline const char* mat_grass_color_modifier_string(mat_grass_color_modifier_t modifier) {

	const char* modifiers[] = {
		NULL,
		"swamp",
		"dark_forest"
	};

	return modifiers[modifier];

}

static inline uint16_t mat_grass_color_modifier_length(mat_grass_color_modifier_t modifier) {

	const uint16_t modifiers[] = {
		0,
		5,
		11
	};
	
	return modifiers[modifier];

}

typedef enum {

	mat_temperature_modifier_none,
	mat_temperature_modifier_frozen
	
} mat_temperature_modifier_t;

static inline const char* mat_temperature_modifier_string(mat_temperature_modifier_t modifier) {

	const char* modifiers[] = {
		NULL,
		"frozen"
	};

	return modifiers[modifier];

}

static inline uint16_t mat_temperature_modifier_length(mat_temperature_modifier_t modifier) {
	
	const uint16_t modifiers[] = {
		0,
		6
	};

	return modifiers[modifier];

}

typedef struct {

	const char* name;
	uint32_t name_length;
	mat_precipitation_type_t precipitation;
	float32_t depth;
	float32_t temperature;
	mat_temperature_modifier_t temperature_modifier;
	float32_t scale;
	float32_t downfall;
	mat_biome_category_t category;

	struct {

		uint32_t sky_color;
		uint32_t water_fog_color;
		uint32_t fog_color;
		uint32_t water_color;
		uint32_t foliage_color; // 0xFFFFFFFF if no foliage color
		uint32_t grass_color; // 0xFFFFFFFF if no grass color
		mat_grass_color_modifier_t grass_color_modifier;

		struct {

			uint32_t sound_length;
			const char* sound;
			uint32_t max_delay;
			uint32_t min_delay;
			bool_t replace_current_music;
		
		} music;

		const char* ambient_sound;
		uint32_t ambient_sound_length;

		struct {
		
			uint32_t sound_length;
			const char* sound;
			float64_t tick_chance;
		
		} additions_sound;

		struct {
		
			const char* sound;
			float64_t offset;
			uint32_t tick_delay;
			uint32_t block_search_extent;
			uint32_t sound_length;
		
		} mood_sound;

	} effects;

	struct {
		
		float32_t probability;
		struct {
			uint32_t type_length;
			const char* type;
		} options;

	} particle;

} mat_biome_t;

extern const mat_biome_t* mat_biomes[];

static inline const mat_biome_t* mat_get_biome_by_type(mat_biome_type_t type) {
	return mat_biomes[type];
}

static inline bool_t mat_biome_has_foliage_color(mat_biome_type_t type) {
	return mat_get_biome_by_type(type)->effects.foliage_color == 0xFFFFFFFF ? false : true;
}

static inline bool_t mat_biome_has_grass_color(mat_biome_type_t type) {
	return mat_get_biome_by_type(type)->effects.grass_color == 0xFFFFFFFF ? false : true;
}

/*
	CODEC
*/

typedef struct {

	size_t size;
	byte_t bytes[];

} mat_codec_t;

extern mat_codec_t* mat_get_codec();

extern mat_codec_t* mat_get_dimension_codec(mat_dimension_type_t dimension);

/*
	STATE MODIFIERS
	State modifiers are used to determine the state
*/

enum mat_state_modifier_type {

		// north
		// south
		// east
		// west
	mat_state_modifier_facing_cardinal,
		
		// down
		// east
		// north
		// south
		// up
		// west
	mat_state_modifier_facing,
		
		// 0 - 15
	mat_state_modifier_rotation,
		
		// true
		// false
	mat_state_modifier_open,
		
		// true
		// false
	mat_state_modifier_powered,
		
		// true
		// false
	mat_state_modifier_lit,
		
		// x
		// y
		// z
	mat_state_modifier_axis,
		
		// x
		// z
	mat_state_modifier_cardinal_axis,
		
		// ceiling
		// floor
		// wall
	mat_state_modifier_face,
		
		// true
		// false
	mat_state_modifier_waterlogged,
		
		// true
		// false
	mat_state_modifier_down,
		
		// true
		// false
	mat_state_modifier_east,
		
		// true
		// false
	mat_state_modifier_north,
		
		// true
		// false
	mat_state_modifier_south,
		
		// true
		// false
	mat_state_modifier_up,
		
		// true
		// false
	mat_state_modifier_west,
		
		// 0 - 15
	mat_state_modifier_power,
		
		// true
		// false
	mat_state_modifier_triggered,
		
		// 0 - 7
	mat_state_modifier_crop_age,
		
		// 0 - 7
	mat_state_modifier_distance,
		
		// 0 - 15
	mat_state_modifier_stock_age,
		
		// 0 - 15
	mat_state_modifier_liquid_level,
		
		// lower
		// upper
	mat_state_modifier_plant_half,
	
		// 0 or 1
	mat_state_modifier_bamboo_age,
		
		// large
		// none
		// small
	mat_state_modifier_bamboo_leaves,
		
		// 0 or 1
	mat_state_modifier_bamboo_stage,
		
		// true
		// false
	mat_state_modifier_bed_occupied,
		
		// foot
		// head
	mat_state_modifier_bed_part,
		
		// 0 - 5
	mat_state_modifier_hive_honey_level,
		
		// 0 - 3
	mat_state_modifier_beetroot_age,
		
		// true
		// false
	mat_state_modifier_brewing_stand_has_bottle_0,
		
		// true
		// false
	mat_state_modifier_brewing_stand_has_bottle_1,
		
		// true
		// false
	mat_state_modifier_brewing_stand_has_bottle_2,
		
		// true
		// false
	mat_state_modifier_bubble_column_drag,
		
		// true
		// false
	mat_state_modifier_campfire_signal,
		
		// 0 - 6
	mat_state_modifier_cake_bites,
		
		// 0 - 3
	mat_state_modifier_cauldron_level,
		
		// left
		// right
		// single
	mat_state_modifier_chest_type,
		
		// 0 - 5
	mat_state_modifier_chorus_flower_age,
		
		// 0 - 2
	mat_state_modifier_cocoa_age,
		
		// true
		// false
	mat_state_modifier_command_block_conditional,
		
		// 0 - 8
	mat_state_modifier_composter_level,

		// true
		// false
	mat_state_modifier_daylight_detector_inverted,
		
		// lower
		// upper
	mat_state_modifier_door_half,
		
		// left
		// right
	mat_state_modifier_door_hinge,
		
		// true
		// false
	mat_state_modifier_door_open,
		
		// true
		// false
	mat_state_modifier_end_portal_frame_eye,
		
		// 0 - 7
	mat_state_modifier_farmland_moisture,
		
		// true
		// false
	mat_state_modifier_fencegate_in_wall,
		
		// 0 - 15
	mat_state_modifier_fire_age,
		
		// 0 - 3
	mat_state_modifier_frosted_ice_age,
		
		// true
		// false
	mat_state_modifier_grass_snowy,
		
		// true
		// false
	mat_state_modifier_hopper_enabled,
		
		// down_east
		// down_north
		// down_south
		// down_west
		// east_up
		// north_up
		// south_up
		// up_east
		// up_north
		// up_south
		// up_west
		// west_up
	mat_state_modifier_jigsaw_facing,
		
		// true
		// false
	mat_state_modifier_jukebox_has_record,

		// 0 - 25
	mat_state_modifier_vine_age,
		
		// 0 - 1
	mat_state_modifier_lantern_hanging,
		
		// true
		// false
	mat_state_modifier_leaves_persistant,
		
		// true
		// false
	mat_state_modifier_lectern_has_book,
		
		// 0 - 3
	mat_state_modifier_nether_wart_age,
		
		// banjo
		// basedrum
		// base
		// bell
		// bit
		// chime
		// cow_bell
		// didgeridoo
		// flute
		// guitar
		// harp
		// hat
		// iron_xylophone
		// pling
		// snare
		// xylophone
	mat_state_modifier_note_block_instrument,
		
		// 0 - 24
	mat_state_modifier_note_block_note,
		
		// true
		// false
	mat_state_modifier_piston_extended,

		// normal or sticky
	mat_state_modifier_piston_type,
		
		// true
		// false
	mat_state_modifier_piston_short,
		
		// east_west
		// north_east
		// north_south
		// north_west
		// south_east
		// south_west
		// ascending_east
		// ascending_north
		// ascending_south
		// ascending_west
	mat_state_modifier_rail_shape,
		
		// east_west
		// north_south
		// ascending_east
		// ascending_north
		// ascending_south
		// ascending_west
	mat_state_modifier_special_rail_shape,
		
		// compare
		// subtract
	mat_state_modifier_comparator_mode,
		
		// none
		// side
		// up
	mat_state_modifier_redstone_east,
		
		// none
		// side
		// up
	mat_state_modifier_redstone_north,
		
		// none
		// side
		// up
	mat_state_modifier_redstone_south,
		
		// none
		// side
		// up
	mat_state_modifier_redstone_west,
		
		// 1 - 4
	mat_state_modifier_repeater_delay,
		
		// true
		// false
	mat_state_modifier_repeater_locked,
		
		// 0 - 4
	mat_state_modifier_respawn_anchor_charges,
		
		// 0
		// 1
	mat_state_modifier_sapling_stage,
		
		// true
		// false
	mat_state_modifier_scaffolding_bottom,
		
		// 1 - 4
	mat_state_modifier_sea_pickle_pickles,
		
		// bottom
		// top
		// double
	mat_state_modifier_slab_type,
		
		// 1 - 8
	mat_state_modifier_snow_layers,
		
		// bottom
		// top
	mat_state_modifier_stairs_half,
		
		// inner_left
		// inner_right
		// outer_left
		// outer_right
		// straight
	mat_state_modifier_stairs_shape,
		
		// corner
		// data
		// load
		// save
	mat_state_modifier_structure_block_mode,

		// 0 - 3
	mat_state_modifier_sweet_berry_bush_age,

		// true
		// false
	mat_state_modifier_tnt_unstable,

		// bottom
		// top
	mat_state_modifier_trapdoor_half,
		
		// true
		// false
	mat_state_modifier_trapdoor_open,
		
		// true
		// false
	mat_state_modifier_tripwire_attached,
		
		// true
		// false
	mat_state_modifier_tripwire_disarmed,

		// 1 - 4
	mat_state_modifier_turtle_egg_eggs,

		// 0 - 2
	mat_state_modifier_turtle_egg_hatch,

		// low
		// none
		// tall
	mat_state_modifier_wall_east,

		// low
		// none
		// tall
	mat_state_modifier_wall_north,

		// low
		// none
		// tall
	mat_state_modifier_wall_south,

		// low
		// none
		// tall
	mat_state_modifier_wall_west,

		// floor
		// seiling
		// double_wall
		// single_wall
	mat_state_modifier_bell_attachment,

		// down
		// east
		// north
		// south
		// west
	mat_state_modifier_hopper_facing,

		// 0 - 15
	mat_state_modifier_light_level,

		// 0 - 7
	mat_state_modifier_scaffolding_distance,

		// 1 - 4
	mat_state_modifier_candle_candles,

		// inactive
		// active
		// cooldown
	mat_state_modifier_sculk_sensor_phase,

		// tip_merge
		// tip
		// frustum
		// middle
		// base
	mat_state_modifier_dripstone_thickness,

		// up
		// down
	mat_state_modifier_dripstone_direction,

		// true
		// false
	mat_state_modifier_cave_vines_berries,

		// none
		// unstable
		// partial
		// full
	mat_state_modifier_dripleaf_tilt,

};

typedef uint8_t mat_state_modifier_type_t;

typedef struct {

	uint8_t count;

} mat_state_modifier_t;

extern const mat_state_modifier_t* mat_modifiers[];

static inline const mat_state_modifier_t* mat_get_state_modifier_by_type(mat_state_modifier_type_t type) {
	return mat_modifiers[type];
}

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
	BLOCK ENTITIES
	Block entities are used to store extra information that couldn't be stored in states
*/

typedef enum {

	mat_block_entity_none = 0,
	mat_block_entity_bees, // store bees in a block
	mat_block_entity_sign, // store sign text
	mat_block_entity_banner, // store patterns

	mat_block_entity_container, // store inventory slots
		mat_block_entity_furnace, // store time until current item is smelted and time until fuel is exhausted
		mat_block_entity_brewing, // store brewing time
		mat_block_entity_hopper, // store time until next transfer
		mat_block_entity_locational_container, // store location for opening and closing
		mat_block_entity_lectern, // store current page

	mat_block_entity_beacon, // store pyramid leve, active effects, contents, and beacon beam position
	mat_block_entity_spawner, // store spawner information
	mat_block_entity_piston_extension, // store the blocks they are moving
	mat_block_entity_jukebox, // store music disks
	mat_block_entity_enchanting_table, // to store the floating book
	mat_block_entity_end_particles, // to store particles for end chests and portalls
	mat_block_entity_head, // store the head type
	mat_block_entity_command, // store command text
	mat_block_entity_gateway, // store teleport location
	mat_block_entity_structure, // to store structure info
	mat_block_entity_jigsaw, // to store structure pool
	mat_block_entity_daylight, // to force output signal
	mat_block_entity_comparator, // to store output strength
	mat_block_entity_bed, // for rendering
	mat_block_entity_conduit, // to check activation
	mat_block_entity_bell // to render bell sway

} mat_block_entity_type_t;

/*
	BLOCKS
	Blocks are the basic building blocks of the world
*/

enum mat_block_type {

	mat_block_air,
	mat_block_acacia_button,
	mat_block_acacia_door,
	mat_block_acacia_fence,
	mat_block_acacia_fence_gate,
	mat_block_acacia_leaves,
	mat_block_acacia_log,
	mat_block_acacia_planks,
	mat_block_acacia_pressure_plate,
	mat_block_acacia_sapling,
	mat_block_acacia_sign,
	mat_block_acacia_slab,
	mat_block_acacia_stairs,
	mat_block_acacia_trapdoor,
	mat_block_acacia_wood,
	mat_block_activator_rail,
	mat_block_allium,
	mat_block_amethyst_cluster,
	mat_block_ancient_debris,
	mat_block_andesite,
	mat_block_andesite_slab,
	mat_block_andesite_stairs,
	mat_block_andesite_wall,
	mat_block_anvil,
	mat_block_azalea,
	mat_block_azalea_leaves,
	mat_block_azure_bluet,
	mat_block_bamboo,
	mat_block_bamboo_sapling,
	mat_block_beetroots,
	mat_block_barrel,
	mat_block_barrier,
	mat_block_basalt,
	mat_block_beacon,
	mat_block_bedrock,
	mat_block_beehive,
	mat_block_bee_nest,
	mat_block_bell,
	mat_block_big_dripleaf,
	mat_block_birch_button,
	mat_block_birch_door,
	mat_block_birch_fence,
	mat_block_birch_fence_gate,
	mat_block_birch_leaves,
	mat_block_birch_log,
	mat_block_birch_planks,
	mat_block_birch_pressure_plate,
	mat_block_birch_sapling,
	mat_block_birch_sign,
	mat_block_birch_slab,
	mat_block_birch_stairs,
	mat_block_birch_trapdoor,
	mat_block_birch_wood,
	mat_block_black_banner,
	mat_block_black_bed,
	mat_block_black_candle,
	mat_block_black_carpet,
	mat_block_black_concrete,
	mat_block_black_concrete_powder,
	mat_block_black_glazed_terracotta,
	mat_block_black_shulker_box,
	mat_block_black_stained_glass,
	mat_block_black_stained_glass_pane,
	mat_block_black_terracotta,
	mat_block_black_wool,
	mat_block_blackstone,
	mat_block_blackstone_slab,
	mat_block_blackstone_stairs,
	mat_block_blackstone_wall,
	mat_block_blast_furnace,
	mat_block_amethyst_block,
	mat_block_coal_block,
	mat_block_copper_block,
	mat_block_diamond_block,
	mat_block_emerald_block,
	mat_block_gold_block,
	mat_block_iron_block,
	mat_block_lapis_block,
	mat_block_netherite_block,
	mat_block_quartz_block,
	mat_block_raw_copper_block,
	mat_block_raw_gold_block,
	mat_block_raw_iron_block,
	mat_block_redstone_block,
	mat_block_blue_banner,
	mat_block_blue_bed,
	mat_block_blue_candle,
	mat_block_blue_carpet,
	mat_block_blue_concrete,
	mat_block_blue_concrete_powder,
	mat_block_blue_glazed_terracotta,
	mat_block_blue_ice,
	mat_block_blue_orchid,
	mat_block_blue_shulker_box,
	mat_block_blue_stained_glass,
	mat_block_blue_stained_glass_pane,
	mat_block_blue_terracotta,
	mat_block_blue_wool,
	mat_block_bone_block,
	mat_block_bookshelf,
	mat_block_brain_coral,
	mat_block_brain_coral_block,
	mat_block_brain_coral_fan,
	mat_block_brewing_stand,
	mat_block_brick_slab,
	mat_block_brick_stairs,
	mat_block_brick_wall,
	mat_block_bricks,
	mat_block_brown_banner,
	mat_block_brown_bed,
	mat_block_brown_candle,
	mat_block_brown_carpet,
	mat_block_brown_concrete,
	mat_block_brown_concrete_powder,
	mat_block_brown_glazed_terracotta,
	mat_block_brown_mushroom,
	mat_block_brown_mushroom_block,
	mat_block_brown_shulker_box,
	mat_block_brown_stained_glass,
	mat_block_brown_stained_glass_pane,
	mat_block_brown_terracotta,
	mat_block_brown_wool,
	mat_block_bubble_coral,
	mat_block_bubble_coral_block,
	mat_block_bubble_coral_fan,
	mat_block_budding_amethyst,
	mat_block_cactus,
	mat_block_cake,
	mat_block_calcite,
	mat_block_campfire,
	mat_block_candle,
	mat_block_carrots,
	mat_block_cartography_table,
	mat_block_carved_pumpkin,
	mat_block_cauldron,
	mat_block_cave_vines,
	mat_block_chain,
	mat_block_chain_command_block,
	mat_block_chest,
	mat_block_chipped_anvil,
	mat_block_chiseled_deepslate,
	mat_block_chiseled_nether_bricks,
	mat_block_chiseled_polished_blackstone,
	mat_block_chiseled_quartz_block,
	mat_block_chiseled_red_sandstone,
	mat_block_chiseled_sandstone,
	mat_block_chiseled_stone_bricks,
	mat_block_chorus_flower,
	mat_block_chorus_plant,
	mat_block_clay,
	mat_block_coal_ore,
	mat_block_coarse_dirt,
	mat_block_cobbled_deepslate,
	mat_block_cobbled_deepslate_slab,
	mat_block_cobbled_deepslate_stairs,
	mat_block_cobbled_deepslate_wall,
	mat_block_cobblestone,
	mat_block_cobblestone_slab,
	mat_block_cobblestone_stairs,
	mat_block_cobblestone_wall,
	mat_block_cobweb,
	mat_block_cocoa,
	mat_block_command_block,
	mat_block_composter,
	mat_block_conduit,
	mat_block_copper_ore,
	mat_block_cornflower,
	mat_block_cracked_deepslate_bricks,
	mat_block_cracked_deepslate_tiles,
	mat_block_cracked_nether_bricks,
	mat_block_cracked_polished_blackstone_bricks,
	mat_block_cracked_stone_bricks,
	mat_block_crafting_table,
	mat_block_creeper_head,
	mat_block_crimson_button,
	mat_block_crimson_door,
	mat_block_crimson_fence,
	mat_block_crimson_fence_gate,
	mat_block_crimson_fungus,
	mat_block_crimson_hyphae,
	mat_block_crimson_nylium,
	mat_block_crimson_planks,
	mat_block_crimson_pressure_plate,
	mat_block_crimson_roots,
	mat_block_crimson_sign,
	mat_block_crimson_slab,
	mat_block_crimson_stairs,
	mat_block_crimson_stem,
	mat_block_crimson_trapdoor,
	mat_block_crying_obsidian,
	mat_block_cut_copper,
	mat_block_cut_copper_slab,
	mat_block_cut_copper_stairs,
	mat_block_cut_red_sandstone,
	mat_block_cut_red_sandstone_slab,
	mat_block_cut_sandstone,
	mat_block_cut_sandstone_slab,
	mat_block_cyan_banner,
	mat_block_cyan_bed,
	mat_block_cyan_candle,
	mat_block_cyan_carpet,
	mat_block_cyan_concrete,
	mat_block_cyan_concrete_powder,
	mat_block_cyan_glazed_terracotta,
	mat_block_cyan_shulker_box,
	mat_block_cyan_stained_glass,
	mat_block_cyan_stained_glass_pane,
	mat_block_cyan_terracotta,
	mat_block_cyan_wool,
	mat_block_damaged_anvil,
	mat_block_dandelion,
	mat_block_dark_oak_button,
	mat_block_dark_oak_door,
	mat_block_dark_oak_fence,
	mat_block_dark_oak_fence_gate,
	mat_block_dark_oak_leaves,
	mat_block_dark_oak_log,
	mat_block_dark_oak_planks,
	mat_block_dark_oak_pressure_plate,
	mat_block_dark_oak_sapling,
	mat_block_dark_oak_sign,
	mat_block_dark_oak_slab,
	mat_block_dark_oak_stairs,
	mat_block_dark_oak_trapdoor,
	mat_block_dark_oak_wood,
	mat_block_dark_prismarine,
	mat_block_dark_prismarine_slab,
	mat_block_dark_prismarine_stairs,
	mat_block_daylight_detector,
	mat_block_dead_brain_coral,
	mat_block_dead_brain_coral_block,
	mat_block_dead_brain_coral_fan,
	mat_block_dead_bubble_coral,
	mat_block_dead_bubble_coral_block,
	mat_block_dead_bubble_coral_fan,
	mat_block_dead_bush,
	mat_block_dead_fire_coral,
	mat_block_dead_fire_coral_block,
	mat_block_dead_fire_coral_fan,
	mat_block_dead_horn_coral,
	mat_block_dead_horn_coral_block,
	mat_block_dead_horn_coral_fan,
	mat_block_dead_tube_coral,
	mat_block_dead_tube_coral_block,
	mat_block_dead_tube_coral_fan,
	mat_block_deepslate,
	mat_block_deepslate_bricks,
	mat_block_deepslate_brick_slab,
	mat_block_deepslate_brick_stairs,
	mat_block_deepslate_brick_wall,
	mat_block_deepslate_coal_ore,
	mat_block_deepslate_copper_ore,
	mat_block_deepslate_diamond_ore,
	mat_block_deepslate_emerald_ore,
	mat_block_deepslate_gold_ore,
	mat_block_deepslate_iron_ore,
	mat_block_deepslate_lapis_ore,
	mat_block_deepslate_redstone_ore,
	mat_block_deepslate_tiles,
	mat_block_deepslate_tile_slab,
	mat_block_deepslate_tile_stairs,
	mat_block_deepslate_tile_wall,
	mat_block_detector_rail,
	mat_block_diamond_ore,
	mat_block_diorite,
	mat_block_diorite_slab,
	mat_block_diorite_stairs,
	mat_block_diorite_wall,
	mat_block_dirt,
	mat_block_dirt_path,
	mat_block_dispenser,
	mat_block_dragon_egg,
	mat_block_dragon_head,
	mat_block_kelp,
	mat_block_dripstone_block,
	mat_block_dropper,
	mat_block_emerald_ore,
	mat_block_enchanting_table,
	mat_block_end_portal_frame,
	mat_block_end_rod,
	mat_block_end_stone,
	mat_block_end_stone_brick_slab,
	mat_block_end_stone_brick_stairs,
	mat_block_end_stone_brick_wall,
	mat_block_end_stone_bricks,
	mat_block_ender_chest,
	mat_block_exposed_copper,
	mat_block_exposed_cut_copper,
	mat_block_exposed_cut_copper_slab,
	mat_block_exposed_cut_copper_stairs,
	mat_block_farmland,
	mat_block_fern,
	mat_block_fire,
	mat_block_fire_coral,
	mat_block_fire_coral_block,
	mat_block_fire_coral_fan,
	mat_block_fletching_table,
	mat_block_flower_pot,
	mat_block_flowering_azalea,
	mat_block_flowering_azalea_leaves,
	mat_block_furnace,
	mat_block_gilded_blackstone,
	mat_block_glass,
	mat_block_glass_pane,
	mat_block_glow_lichen,
	mat_block_glowstone,
	mat_block_gold_ore,
	mat_block_granite,
	mat_block_granite_slab,
	mat_block_granite_stairs,
	mat_block_granite_wall,
	mat_block_grass,
	mat_block_grass_block,
	mat_block_gravel,
	mat_block_gray_banner,
	mat_block_gray_bed,
	mat_block_gray_candle,
	mat_block_gray_carpet,
	mat_block_gray_concrete,
	mat_block_gray_concrete_powder,
	mat_block_gray_glazed_terracotta,
	mat_block_gray_shulker_box,
	mat_block_gray_stained_glass,
	mat_block_gray_stained_glass_pane,
	mat_block_gray_terracotta,
	mat_block_gray_wool,
	mat_block_green_banner,
	mat_block_green_bed,
	mat_block_green_candle,
	mat_block_green_carpet,
	mat_block_green_concrete,
	mat_block_green_concrete_powder,
	mat_block_green_glazed_terracotta,
	mat_block_green_shulker_box,
	mat_block_green_stained_glass,
	mat_block_green_stained_glass_pane,
	mat_block_green_terracotta,
	mat_block_green_wool,
	mat_block_grindstone,
	mat_block_hanging_roots,
	mat_block_hay_block,
	mat_block_heavy_weighted_pressure_plate,
	mat_block_honey_block,
	mat_block_honeycomb_block,
	mat_block_hopper,
	mat_block_horn_coral,
	mat_block_horn_coral_block,
	mat_block_horn_coral_fan,
	mat_block_ice,
	mat_block_infested_chiseled_stone_bricks,
	mat_block_infested_cobblestone,
	mat_block_infested_cracked_stone_bricks,
	mat_block_infested_deepslate,
	mat_block_infested_mossy_stone_bricks,
	mat_block_infested_stone,
	mat_block_infested_stone_bricks,
	mat_block_iron_bars,
	mat_block_iron_door,
	mat_block_iron_ore,
	mat_block_iron_trapdoor,
	mat_block_jack_o_lantern,
	mat_block_jigsaw,
	mat_block_jukebox,
	mat_block_jungle_button,
	mat_block_jungle_door,
	mat_block_jungle_fence,
	mat_block_jungle_fence_gate,
	mat_block_jungle_leaves,
	mat_block_jungle_log,
	mat_block_jungle_planks,
	mat_block_jungle_pressure_plate,
	mat_block_jungle_sapling,
	mat_block_jungle_sign,
	mat_block_jungle_slab,
	mat_block_jungle_stairs,
	mat_block_jungle_trapdoor,
	mat_block_jungle_wood,
	mat_block_kelp_plant,
	mat_block_ladder,
	mat_block_lantern,
	mat_block_lapis_ore,
	mat_block_large_amethyst_bud,
	mat_block_large_fern,
	mat_block_lava,
	mat_block_lectern,
	mat_block_lever,
	mat_block_light,
	mat_block_light_blue_banner,
	mat_block_light_blue_bed,
	mat_block_light_blue_candle,
	mat_block_light_blue_carpet,
	mat_block_light_blue_concrete,
	mat_block_light_blue_concrete_powder,
	mat_block_light_blue_glazed_terracotta,
	mat_block_light_blue_shulker_box,
	mat_block_light_blue_stained_glass,
	mat_block_light_blue_stained_glass_pane,
	mat_block_light_blue_terracotta,
	mat_block_light_blue_wool,
	mat_block_light_gray_banner,
	mat_block_light_gray_bed,
	mat_block_light_gray_candle,
	mat_block_light_gray_carpet,
	mat_block_light_gray_concrete,
	mat_block_light_gray_concrete_powder,
	mat_block_light_gray_glazed_terracotta,
	mat_block_light_gray_shulker_box,
	mat_block_light_gray_stained_glass,
	mat_block_light_gray_stained_glass_pane,
	mat_block_light_gray_terracotta,
	mat_block_light_gray_wool,
	mat_block_light_weighted_pressure_plate,
	mat_block_lightning_rod,
	mat_block_lilac,
	mat_block_lily_of_the_valley,
	mat_block_lily_pad,
	mat_block_lime_banner,
	mat_block_lime_bed,
	mat_block_lime_candle,
	mat_block_lime_carpet,
	mat_block_lime_concrete,
	mat_block_lime_concrete_powder,
	mat_block_lime_glazed_terracotta,
	mat_block_lime_shulker_box,
	mat_block_lime_stained_glass,
	mat_block_lime_stained_glass_pane,
	mat_block_lime_terracotta,
	mat_block_lime_wool,
	mat_block_lodestone,
	mat_block_loom,
	mat_block_magenta_banner,
	mat_block_magenta_bed,
	mat_block_magenta_candle,
	mat_block_magenta_carpet,
	mat_block_magenta_concrete,
	mat_block_magenta_concrete_powder,
	mat_block_magenta_glazed_terracotta,
	mat_block_magenta_shulker_box,
	mat_block_magenta_stained_glass,
	mat_block_magenta_stained_glass_pane,
	mat_block_magenta_terracotta,
	mat_block_magenta_wool,
	mat_block_magma_block,
	mat_block_medium_amethyst_bud,
	mat_block_melon,
	mat_block_melon_stem,
	mat_block_moss_block,
	mat_block_moss_carpet,
	mat_block_mossy_cobblestone,
	mat_block_mossy_cobblestone_slab,
	mat_block_mossy_cobblestone_stairs,
	mat_block_mossy_cobblestone_wall,
	mat_block_mossy_stone_brick_slab,
	mat_block_mossy_stone_brick_stairs,
	mat_block_mossy_stone_brick_wall,
	mat_block_mossy_stone_bricks,
	mat_block_mushroom_stem,
	mat_block_mycelium,
	mat_block_nether_brick_fence,
	mat_block_nether_brick_slab,
	mat_block_nether_brick_stairs,
	mat_block_nether_brick_wall,
	mat_block_nether_bricks,
	mat_block_nether_gold_ore,
	mat_block_nether_quartz_ore,
	mat_block_nether_sprouts,
	mat_block_nether_wart,
	mat_block_nether_wart_block,
	mat_block_netherrack,
	mat_block_note_block,
	mat_block_oak_button,
	mat_block_oak_door,
	mat_block_oak_fence,
	mat_block_oak_fence_gate,
	mat_block_oak_leaves,
	mat_block_oak_log,
	mat_block_oak_planks,
	mat_block_oak_pressure_plate,
	mat_block_oak_sapling,
	mat_block_oak_sign,
	mat_block_oak_slab,
	mat_block_oak_stairs,
	mat_block_oak_trapdoor,
	mat_block_oak_wood,
	mat_block_observer,
	mat_block_obsidian,
	mat_block_orange_banner,
	mat_block_orange_bed,
	mat_block_orange_candle,
	mat_block_orange_carpet,
	mat_block_orange_concrete,
	mat_block_orange_concrete_powder,
	mat_block_orange_glazed_terracotta,
	mat_block_orange_shulker_box,
	mat_block_orange_stained_glass,
	mat_block_orange_stained_glass_pane,
	mat_block_orange_terracotta,
	mat_block_orange_tulip,
	mat_block_orange_wool,
	mat_block_oxeye_daisy,
	mat_block_oxidized_copper,
	mat_block_oxidized_cut_copper,
	mat_block_oxidized_cut_copper_slab,
	mat_block_oxidized_cut_copper_stairs,
	mat_block_packed_ice,
	mat_block_peony,
	mat_block_petrified_oak_slab,
	mat_block_pink_banner,
	mat_block_pink_bed,
	mat_block_pink_candle,
	mat_block_pink_carpet,
	mat_block_pink_concrete,
	mat_block_pink_concrete_powder,
	mat_block_pink_glazed_terracotta,
	mat_block_pink_shulker_box,
	mat_block_pink_stained_glass,
	mat_block_pink_stained_glass_pane,
	mat_block_pink_terracotta,
	mat_block_pink_tulip,
	mat_block_pink_wool,
	mat_block_piston,
	mat_block_player_head,
	mat_block_podzol,
	mat_block_pointed_dripstone,
	mat_block_polished_andesite,
	mat_block_polished_andesite_slab,
	mat_block_polished_andesite_stairs,
	mat_block_polished_basalt,
	mat_block_polished_blackstone,
	mat_block_polished_blackstone_brick_slab,
	mat_block_polished_blackstone_brick_stairs,
	mat_block_polished_blackstone_brick_wall,
	mat_block_polished_blackstone_bricks,
	mat_block_polished_blackstone_button,
	mat_block_polished_blackstone_pressure_plate,
	mat_block_polished_blackstone_slab,
	mat_block_polished_blackstone_stairs,
	mat_block_polished_blackstone_wall,
	mat_block_polished_diorite,
	mat_block_polished_diorite_slab,
	mat_block_polished_diorite_stairs,
	mat_block_polished_granite,
	mat_block_polished_granite_slab,
	mat_block_polished_granite_stairs,
	mat_block_polished_deepslate,
	mat_block_polished_deepslate_slab,
	mat_block_polished_deepslate_stairs,
	mat_block_polished_deepslate_wall,
	mat_block_poppy,
	mat_block_potatoes,
	mat_block_powder_snow,
	mat_block_powered_rail,
	mat_block_prismarine,
	mat_block_prismarine_brick_slab,
	mat_block_prismarine_brick_stairs,
	mat_block_prismarine_bricks,
	mat_block_prismarine_slab,
	mat_block_prismarine_stairs,
	mat_block_prismarine_wall,
	mat_block_pumpkin,
	mat_block_pumpkin_stem,
	mat_block_purple_banner,
	mat_block_purple_bed,
	mat_block_purple_candle,
	mat_block_purple_carpet,
	mat_block_purple_concrete,
	mat_block_purple_concrete_powder,
	mat_block_purple_glazed_terracotta,
	mat_block_purple_shulker_box,
	mat_block_purple_stained_glass,
	mat_block_purple_stained_glass_pane,
	mat_block_purple_terracotta,
	mat_block_purple_wool,
	mat_block_purpur_block,
	mat_block_purpur_pillar,
	mat_block_purpur_slab,
	mat_block_purpur_stairs,
	mat_block_quartz_bricks,
	mat_block_quartz_pillar,
	mat_block_quartz_slab,
	mat_block_quartz_stairs,
	mat_block_rail,
	mat_block_red_banner,
	mat_block_red_bed,
	mat_block_red_candle,
	mat_block_red_carpet,
	mat_block_red_concrete,
	mat_block_red_concrete_powder,
	mat_block_red_glazed_terracotta,
	mat_block_red_mushroom,
	mat_block_red_mushroom_block,
	mat_block_red_nether_brick_slab,
	mat_block_red_nether_brick_stairs,
	mat_block_red_nether_brick_wall,
	mat_block_red_nether_bricks,
	mat_block_red_sand,
	mat_block_red_sandstone,
	mat_block_red_sandstone_slab,
	mat_block_red_sandstone_stairs,
	mat_block_red_sandstone_wall,
	mat_block_red_shulker_box,
	mat_block_red_stained_glass,
	mat_block_red_stained_glass_pane,
	mat_block_red_terracotta,
	mat_block_red_tulip,
	mat_block_red_wool,
	mat_block_comparator,
	mat_block_redstone_lamp,
	mat_block_redstone_ore,
	mat_block_repeater,
	mat_block_redstone_torch,
	mat_block_redstone_wire,
	mat_block_repeating_command_block,
	mat_block_respawn_anchor,
	mat_block_rooted_dirt,
	mat_block_rose_bush,
	mat_block_sand,
	mat_block_sandstone,
	mat_block_sandstone_slab,
	mat_block_sandstone_stairs,
	mat_block_sandstone_wall,
	mat_block_scaffolding,
	mat_block_sculk_sensor,
	mat_block_sea_lantern,
	mat_block_sea_pickle,
	mat_block_seagrass,
	mat_block_shroomlight,
	mat_block_shulker_box,
	mat_block_skeleton_skull,
	mat_block_slime_block,
	mat_block_small_amethyst_bud,
	mat_block_small_dripleaf,
	mat_block_smithing_table,
	mat_block_smoker,
	mat_block_smooth_basalt,
	mat_block_smooth_quartz,
	mat_block_smooth_quartz_slab,
	mat_block_smooth_quartz_stairs,
	mat_block_smooth_red_sandstone,
	mat_block_smooth_red_sandstone_slab,
	mat_block_smooth_red_sandstone_stairs,
	mat_block_smooth_sandstone,
	mat_block_smooth_sandstone_slab,
	mat_block_smooth_sandstone_stairs,
	mat_block_smooth_stone,
	mat_block_smooth_stone_slab,
	mat_block_snow,
	mat_block_snow_block,
	mat_block_soul_campfire,
	mat_block_soul_fire,
	mat_block_soul_lantern,
	mat_block_soul_sand,
	mat_block_soul_soil,
	mat_block_soul_torch,
	mat_block_spawner,
	mat_block_sponge,
	mat_block_spore_blossom,
	mat_block_spruce_button,
	mat_block_spruce_door,
	mat_block_spruce_fence,
	mat_block_spruce_fence_gate,
	mat_block_spruce_leaves,
	mat_block_spruce_log,
	mat_block_spruce_planks,
	mat_block_spruce_pressure_plate,
	mat_block_spruce_sapling,
	mat_block_spruce_sign,
	mat_block_spruce_slab,
	mat_block_spruce_stairs,
	mat_block_spruce_trapdoor,
	mat_block_spruce_wood,
	mat_block_sticky_piston,
	mat_block_stone,
	mat_block_stone_brick_slab,
	mat_block_stone_brick_stairs,
	mat_block_stone_brick_wall,
	mat_block_stone_bricks,
	mat_block_stone_button,
	mat_block_stone_pressure_plate,
	mat_block_stone_slab,
	mat_block_stone_stairs,
	mat_block_stonecutter,
	mat_block_stripped_acacia_log,
	mat_block_stripped_acacia_wood,
	mat_block_stripped_birch_log,
	mat_block_stripped_birch_wood,
	mat_block_stripped_crimson_hyphae,
	mat_block_stripped_crimson_stem,
	mat_block_stripped_dark_oak_log,
	mat_block_stripped_dark_oak_wood,
	mat_block_stripped_jungle_log,
	mat_block_stripped_jungle_wood,
	mat_block_stripped_oak_log,
	mat_block_stripped_oak_wood,
	mat_block_stripped_spruce_log,
	mat_block_stripped_spruce_wood,
	mat_block_stripped_warped_hyphae,
	mat_block_stripped_warped_stem,
	mat_block_structure_block,
	mat_block_structure_void,
	mat_block_sugar_cane,
	mat_block_sunflower,
	mat_block_sweet_berry_bush,
	mat_block_tall_grass,
	mat_block_tall_seagrass,
	mat_block_target,
	mat_block_terracotta,
	mat_block_tinted_glass,
	mat_block_tnt,
	mat_block_torch,
	mat_block_trapped_chest,
	mat_block_tripwire,
	mat_block_tripwire_hook,
	mat_block_tube_coral,
	mat_block_tube_coral_block,
	mat_block_tube_coral_fan,
	mat_block_tuff,
	mat_block_turtle_egg,
	mat_block_twisting_vines,
	mat_block_vine,
	mat_block_warped_button,
	mat_block_warped_door,
	mat_block_warped_fence,
	mat_block_warped_fence_gate,
	mat_block_warped_fungus,
	mat_block_warped_hyphae,
	mat_block_warped_nylium,
	mat_block_warped_planks,
	mat_block_warped_pressure_plate,
	mat_block_warped_roots,
	mat_block_warped_sign,
	mat_block_warped_slab,
	mat_block_warped_stairs,
	mat_block_warped_stem,
	mat_block_warped_trapdoor,
	mat_block_warped_wart_block,
	mat_block_water,
	mat_block_waxed_copper_block,
	mat_block_waxed_cut_copper,
	mat_block_waxed_cut_copper_slab,
	mat_block_waxed_cut_copper_stairs,
	mat_block_waxed_exposed_copper,
	mat_block_waxed_exposed_cut_copper,
	mat_block_waxed_exposed_cut_copper_slab,
	mat_block_waxed_exposed_cut_copper_stairs,
	mat_block_waxed_oxidized_copper,
	mat_block_waxed_oxidized_cut_copper,
	mat_block_waxed_oxidized_cut_copper_slab,
	mat_block_waxed_oxidized_cut_copper_stairs,
	mat_block_waxed_weathered_copper,
	mat_block_waxed_weathered_cut_copper,
	mat_block_waxed_weathered_cut_copper_slab,
	mat_block_waxed_weathered_cut_copper_stairs,
	mat_block_weathered_copper,
	mat_block_weathered_cut_copper,
	mat_block_weathered_cut_copper_slab,
	mat_block_weathered_cut_copper_stairs,
	mat_block_weeping_vines,
	mat_block_wet_sponge,
	mat_block_wheat,
	mat_block_white_banner,
	mat_block_white_bed,
	mat_block_white_candle,
	mat_block_white_carpet,
	mat_block_white_concrete,
	mat_block_white_concrete_powder,
	mat_block_white_glazed_terracotta,
	mat_block_white_shulker_box,
	mat_block_white_stained_glass,
	mat_block_white_stained_glass_pane,
	mat_block_white_terracotta,
	mat_block_white_tulip,
	mat_block_white_wool,
	mat_block_wither_rose,
	mat_block_wither_skeleton_skull,
	mat_block_yellow_banner,
	mat_block_yellow_bed,
	mat_block_yellow_candle,
	mat_block_yellow_carpet,
	mat_block_yellow_concrete,
	mat_block_yellow_concrete_powder,
	mat_block_yellow_glazed_terracotta,
	mat_block_yellow_shulker_box,
	mat_block_yellow_stained_glass,
	mat_block_yellow_stained_glass_pane,
	mat_block_yellow_terracotta,
	mat_block_yellow_wool,
	mat_block_zombie_head,
	mat_block_end_portal,
	mat_block_frosted_ice,
	mat_block_piston_head,
	mat_block_nether_portal,
	mat_block_end_gateway,
	mat_block_big_dripleaf_stem,
	mat_block_bubble_column,
	mat_block_moving_piston,
	mat_block_wall_torch,
	mat_block_oak_wall_sign,
	mat_block_spruce_wall_sign,
	mat_block_birch_wall_sign,
	mat_block_acacia_wall_sign,
	mat_block_jungle_wall_sign,
	mat_block_dark_oak_wall_sign,
	mat_block_redstone_wall_torch,
	mat_block_soul_wall_torch,
	mat_block_attached_pumpkin_stem,
	mat_block_attached_melon_stem,
	mat_block_water_cauldron,
	mat_block_lava_cauldron,
	mat_block_powder_snow_cauldron,
	mat_block_potted_oak_sapling,
	mat_block_potted_spruce_sapling,
	mat_block_potted_birch_sapling,
	mat_block_potted_jungle_sapling,
	mat_block_potted_acacia_sapling,
	mat_block_potted_dark_oak_sapling,
	mat_block_potted_fern,
	mat_block_potted_dandelion,
	mat_block_potted_poppy,
	mat_block_potted_blue_orchid,
	mat_block_potted_allium,
	mat_block_potted_azure_bluet,
	mat_block_potted_red_tulip,
	mat_block_potted_orange_tulip,
	mat_block_potted_white_tulip,
	mat_block_potted_pink_tulip,
	mat_block_potted_oxeye_daisy,
	mat_block_potted_cornflower,
	mat_block_potted_lily_of_the_valley,
	mat_block_potted_wither_rose,
	mat_block_potted_red_mushroom,
	mat_block_potted_brown_mushroom,
	mat_block_potted_dead_bush,
	mat_block_potted_cactus,
	mat_block_skeleton_wall_skull,
	mat_block_wither_skeleton_wall_skull,
	mat_block_zombie_wall_head,
	mat_block_player_wall_head,
	mat_block_creeper_wall_head,
	mat_block_dragon_wall_head,
	mat_block_white_wall_banner,
	mat_block_orange_wall_banner,
	mat_block_magenta_wall_banner,
	mat_block_light_blue_wall_banner,
	mat_block_yellow_wall_banner,
	mat_block_lime_wall_banner,
	mat_block_pink_wall_banner,
	mat_block_gray_wall_banner,
	mat_block_light_gray_wall_banner,
	mat_block_cyan_wall_banner,
	mat_block_purple_wall_banner,
	mat_block_blue_wall_banner,
	mat_block_brown_wall_banner,
	mat_block_green_wall_banner,
	mat_block_red_wall_banner,
	mat_block_black_wall_banner,
	mat_block_dead_tube_coral_wall_fan,
	mat_block_dead_brain_coral_wall_fan,
	mat_block_dead_bubble_coral_wall_fan,
	mat_block_dead_fire_coral_wall_fan,
	mat_block_dead_horn_coral_wall_fan,
	mat_block_tube_coral_wall_fan,
	mat_block_brain_coral_wall_fan,
	mat_block_bubble_coral_wall_fan,
	mat_block_fire_coral_wall_fan,
	mat_block_horn_coral_wall_fan,
	mat_block_potted_bamboo,
	mat_block_void_air,
	mat_block_cave_air,
	mat_block_weeping_vines_plant,
	mat_block_twisting_vines_plant,
	mat_block_crimson_wall_sign,
	mat_block_warped_wall_sign,
	mat_block_potted_crimson_fungus,
	mat_block_potted_warped_fungus,
	mat_block_potted_crimson_roots,
	mat_block_potted_warped_roots,
	mat_block_candle_cake,
	mat_block_white_candle_cake,
	mat_block_orange_candle_cake,
	mat_block_magenta_candle_cake,
	mat_block_light_blue_candle_cake,
	mat_block_yellow_candle_cake,
	mat_block_lime_candle_cake,
	mat_block_pink_candle_cake,
	mat_block_gray_candle_cake,
	mat_block_light_gray_candle_cake,
	mat_block_cyan_candle_cake,
	mat_block_purple_candle_cake,
	mat_block_blue_candle_cake,
	mat_block_brown_candle_cake,
	mat_block_green_candle_cake,
	mat_block_red_candle_cake,
	mat_block_black_candle_cake,
	mat_block_cave_vines_plant,
	mat_block_potted_azalea_bush,
	mat_block_potted_flowering_azalea_bush,
	mat_block_dried_kelp_block,

	mat_block_count

};

typedef uint16_t mat_block_type_t;
typedef uint16_t mat_block_protocol_id_t;

typedef enum {

	mat_block_tag_catches_fire_from_lava,

	mat_block_tag_light_filtering,
	mat_block_tag_transparent,

	mat_block_tag_max

} mat_block_tag_t;

typedef struct {

	float32_t resistance;
		// blast resistance

	float32_t hardness;
		// hardness value for calculating break times

	utl_bitset(mat_block_tag_max - 1, tags);

	uint8_t luminance;
	uint8_t encouragement;
	uint8_t flammability;

	struct {
		
		uint8_t type;
		uint8_t tier;

	} best_tool;

	uint8_t entity;

	uint8_t modifiers_count;
	mat_state_modifier_type_t modifiers[];

} mat_block_t;

extern const mat_block_t* mat_blocks[];
extern const mat_block_protocol_id_t mat_blocks_protocol[];
extern const mat_block_protocol_id_t mat_blocks_base_protocol[];

static inline const mat_block_t* mat_get_block_by_id(mat_block_type_t id) {
	return mat_blocks[id];
}

static inline mat_block_type_t mat_get_block_id_by_protocol_id(mat_block_protocol_id_t protocol) {
	return mat_blocks_protocol[protocol];
}

static inline mat_block_protocol_id_t mat_get_block_base_protocol_id_by_id(mat_block_protocol_id_t id) {
	return mat_blocks_base_protocol[id];
}

/*
Read the value of a state field of a block with certain protocol
*/
static inline uint8_t mat_get_block_state_value(mat_block_protocol_id_t block_protocol, mat_state_modifier_type_t field) {

	mat_block_type_t block_id = mat_get_block_id_by_protocol_id(block_protocol);
	mat_block_protocol_id_t block_state = block_protocol - mat_get_block_base_protocol_id_by_id(block_id);
	const mat_block_t* block_data = mat_get_block_by_id(block_id);

	for (int32_t i = block_data->modifiers_count; i >= 0; --i) {

		if (block_data->modifiers[i] != field) {

			block_state /= mat_get_state_modifier_by_type(block_data->modifiers[i])->count;

		} else {

			return block_state % mat_get_state_modifier_by_type(field)->count;

		}

	}

	return 0;

}

/*
Set a state field for a particular block
*/
static inline mat_block_protocol_id_t mat_set_block_state_value(mat_block_protocol_id_t block_protocol, mat_state_modifier_type_t field, uint8_t value) {

	mat_block_type_t block_id = mat_get_block_id_by_protocol_id(block_protocol);
	mat_block_protocol_id_t block_state = block_protocol - mat_get_block_base_protocol_id_by_id(block_id);
	int32_t state_add = 1;
	const mat_block_t* block_data = mat_get_block_by_id(block_id);

	for (int32_t i = block_data->modifiers_count; i >= 0; --i) {

		const mat_state_modifier_t* modifier = mat_get_state_modifier_by_type(block_data->modifiers[i]);

		if (block_data->modifiers[i] != field) {

			block_state /= modifier->count;
			state_add *= modifier->count;

		} else {

			block_state %= modifier->count;
			state_add *= (int32_t) value - block_state;

			return block_protocol + state_add;

		}

	}

	return block_protocol;

}

static inline bool_t mat_catches_fire_from_lava(const mat_block_t* block) {

	return utl_test_bit(block->tags, mat_block_tag_catches_fire_from_lava);

}

static inline bool_t mat_can_burn_away(const mat_block_t* block) {

	return block->flammability > 0 ? true : false;

}

/*
	ITEMS
	Every single item in minecraft
*/

typedef enum {

	mat_item_acacia_boat,
	mat_item_armor_stand,
	mat_item_beetroot_seeds,
	mat_item_birch_boat,
	mat_item_bottle_o_enchanting,
	mat_item_bow,
	mat_item_bucket,
	mat_item_bucket_of_axolotl,
	mat_item_bucket_of_cod,
	mat_item_bucket_of_pufferfish,
	mat_item_bucket_of_salmon,
	mat_item_bucket_of_tropical_fish,
	mat_item_carrot,
	mat_item_cocoa_beans,
	mat_item_crossbow,
	mat_item_dark_oak_boat,
	mat_item_egg,
	mat_item_end_crystal,
	mat_item_ender_pearl,
	mat_item_eye_of_ender,
	mat_item_fire_charge,
	mat_item_firework_rocket,
	mat_item_fishing_rod,
	mat_item_flint_and_steel,
	mat_item_glow_berries,
	mat_item_glow_item_frame,
	mat_item_item_frame,
	mat_item_jungle_boat,
	mat_item_kelp,
	mat_item_lava_bucket,
	mat_item_lead,
	mat_item_lingering_potion,
	mat_item_melon_seeds,
	mat_item_minecart,
	mat_item_minecart_with_chest,
	mat_item_minecart_with_command_block,
	mat_item_minecart_with_furnace_,
	mat_item_minecart_with_hopper,
	mat_item_minecart_with_tnt,
	mat_item_oak_boat,
	mat_item_painting,
	mat_item_potato,
	mat_item_powder_snow_bucket,
	mat_item_pumpkin_seeds,
	mat_item_redstone_dust,
	mat_item_snowball,
	mat_item_splash_potion,
	mat_item_spruce_boat,
	mat_item_string,
	mat_item_sweet_berries,
	mat_item_trident,
	mat_item_water_bucket,
	mat_item_wheat_seeds,
	mat_item_apple,
	mat_item_arrow,
	mat_item_baked_potato,
	mat_item_beetroot,
	mat_item_beetroot_soup,
	mat_item_black_dye,
	mat_item_blue_dye,
	mat_item_bone,
	mat_item_bone_meal,
	mat_item_book_and_quill,
	mat_item_bowl,
	mat_item_bread,
	mat_item_brown_dye,
	mat_item_bundle,
	mat_item_carrot_on_a_stick,
	mat_item_chainmail_boots,
	mat_item_chainmail_chestplate,
	mat_item_chainmail_helmet,
	mat_item_chainmail_leggings,
	mat_item_chorus_fruit,
	mat_item_compass,
	mat_item_cooked_chicken,
	mat_item_cooked_cod,
	mat_item_cooked_mutton,
	mat_item_cooked_porkchop,
	mat_item_cooked_rabbit,
	mat_item_cooked_salmon,
	mat_item_cookie,
	mat_item_cyan_dye,
	mat_item_debug_stick_,
	mat_item_diamond_axe,
	mat_item_diamond_boots,
	mat_item_diamond_chestplate,
	mat_item_diamond_helmet,
	mat_item_diamond_hoe,
	mat_item_diamond_horse_armor,
	mat_item_diamond_leggings,
	mat_item_diamond_pickaxe,
	mat_item_diamond_shovel,
	mat_item_diamond_sword,
	mat_item_dried_kelp,
	mat_item_elytra,
	mat_item_empty_map,
	mat_item_enchanted_golden_apple,
	mat_item_goat_horn_,
	mat_item_glass_bottle,
	mat_item_glow_ink_sac,
	mat_item_gold_ingot,
	mat_item_golden_apple,
	mat_item_golden_axe,
	mat_item_golden_boots,
	mat_item_golden_carrot,
	mat_item_golden_chestplate,
	mat_item_golden_helmet,
	mat_item_golden_hoe,
	mat_item_golden_horse_armor,
	mat_item_golden_leggings,
	mat_item_golden_pickaxe,
	mat_item_golden_shovel,
	mat_item_golden_sword,
	mat_item_gray_dye,
	mat_item_green_dye,
	mat_item_honeycomb,
	mat_item_honey_bottle,
	mat_item_ink_sac,
	mat_item_iron_axe,
	mat_item_iron_boots,
	mat_item_iron_chestplate,
	mat_item_iron_helmet,
	mat_item_iron_hoe,
	mat_item_iron_horse_armor,
	mat_item_iron_ingot,
	mat_item_iron_leggings,
	mat_item_iron_pickaxe,
	mat_item_iron_shovel,
	mat_item_iron_sword,
	mat_item_knowledge_book_,
	mat_item_leather_boots,
	mat_item_leather_cap,
	mat_item_leather_horse_armor,
	mat_item_leather_pants,
	mat_item_leather_tunic,
	mat_item_light_blue_dye,
	mat_item_light_gray_dye,
	mat_item_lime_dye,
	mat_item_magenta_dye,
	mat_item_map_or_explorer_map,
	mat_item_melon_slice,
	mat_item_milk_bucket,
	mat_item_mushroom_stew,
	mat_item_music_disc_11,
	mat_item_music_disc_13,
	mat_item_music_disc_blocks,
	mat_item_music_disc_cat,
	mat_item_music_disc_chirp,
	mat_item_music_disc_far,
	mat_item_music_disc_mall,
	mat_item_music_disc_mellohi,
	mat_item_music_disc_pigstep,
	mat_item_music_disc_stal,
	mat_item_music_disc_strad,
	mat_item_music_disc_wait,
	mat_item_music_disc_ward,
	mat_item_name_tag,
	mat_item_netherite_axe,
	mat_item_netherite_boots,
	mat_item_netherite_chestplate,
	mat_item_netherite_helmet,
	mat_item_netherite_hoe,
	mat_item_netherite_leggings,
	mat_item_netherite_pickaxe,
	mat_item_netherite_shovel,
	mat_item_netherite_sword,
	mat_item_orange_dye,
	mat_item_pink_dye,
	mat_item_poisonous_potato,
	mat_item_potions,
	mat_item_pufferfish,
	mat_item_pumpkin_pie,
	mat_item_purple_dye,
	mat_item_rabbit_stew,
	mat_item_raw_beef,
	mat_item_raw_chicken,
	mat_item_raw_cod,
	mat_item_raw_mutton,
	mat_item_raw_porkchop,
	mat_item_raw_rabbit,
	mat_item_raw_salmon,
	mat_item_red_dye,
	mat_item_rotten_flesh,
	mat_item_saddle,
	mat_item_shears,
	mat_item_shield,
	mat_item_spectral_arrow_,
	mat_item_spider_eye,
	mat_item_spyglass,
	mat_item_steak,
	mat_item_stone_axe,
	mat_item_stone_hoe,
	mat_item_stone_pickaxe,
	mat_item_stone_shovel,
	mat_item_stone_sword,
	mat_item_sugar,
	mat_item_suspicious_stew,
	mat_item_tipped_arrow,
	mat_item_totem_of_undying,
	mat_item_tropical_fish,
	mat_item_turtle_shell,
	mat_item_warped_fungus_on_a_stick,
	mat_item_wheat,
	mat_item_white_dye,
	mat_item_wooden_axe,
	mat_item_wooden_hoe,
	mat_item_wooden_pickaxe,
	mat_item_wooden_shovel,
	mat_item_wooden_sword,
	mat_item_written_book,
	mat_item_yellow_dye,
	mat_item_amethyst_shard,
	mat_item_banner_pattern_creeper_charge,
	mat_item_banner_pattern_flower_charge,
	mat_item_banner_pattern_globe,
	mat_item_banner_pattern_skull_charge,
	mat_item_banner_pattern_snout,
	mat_item_banner_pattern_thing,
	mat_item_blaze_powder,
	mat_item_blaze_rod,
	mat_item_book,
	mat_item_brick,
	mat_item_charcoal,
	mat_item_clay_ball,
	mat_item_clock,
	mat_item_coal,
	mat_item_copper_ingot,
	mat_item_diamond,
	mat_item_dragon_breath,
	mat_item_emerald,
	mat_item_enchanted_book,
	mat_item_feather,
	mat_item_fermented_spider_eye,
	mat_item_firework_star,
	mat_item_flint,
	mat_item_ghast_tear,
	mat_item_glistering_melon_slice,
	mat_item_glowstone_dust,
	mat_item_gold_nugget,
	mat_item_gunpowder,
	mat_item_heart_of_the_sea,
	mat_item_iron_nugget,
	mat_item_lapis_lazuli,
	mat_item_leather,
	mat_item_magma_cream,
	mat_item_nautilus_shell,
	mat_item_nether_brick,
	mat_item_nether_quartz,
	mat_item_nether_star,
	mat_item_netherite_ingot,
	mat_item_netherite_scrap,
	mat_item_paper,
	mat_item_phantom_membrane,
	mat_item_popped_chorus_fruit,
	mat_item_prismarine_crystals,
	mat_item_prismarine_shard,
	mat_item_rabbit_hide,
	mat_item_rabbit_foot,
	mat_item_raw_copper,
	mat_item_raw_gold,
	mat_item_raw_iron,
	mat_item_scute,
	mat_item_shulker_shell,
	mat_item_slimeball,
	mat_item_stick,
	mat_item_spawn_eggs,
	mat_item_axolotl_spawn_egg,
	mat_item_bat_spawn_egg,
	mat_item_bee_spawn_egg,
	mat_item_blaze_spawn_egg,
	mat_item_cat_spawn_egg,
	mat_item_cave_spider_spawn_egg,
	mat_item_chicken_spawn_egg,
	mat_item_cod_spawn_egg,
	mat_item_cow_spawn_egg,
	mat_item_creeper_spawn_egg,
	mat_item_dolphin_spawn_egg,
	mat_item_donkey_spawn_egg,
	mat_item_drowned_spawn_egg,
	mat_item_elder_guardian_spawn_egg,
	mat_item_enderman_spawn_egg,
	mat_item_endermite_spawn_egg,
	mat_item_evoker_spawn_egg,
	mat_item_fox_spawn_egg,
	mat_item_ghast_spawn_egg,
	mat_item_glow_squid_spawn_egg,
	mat_item_goat_spawn_egg,
	mat_item_guardian_spawn_egg,
	mat_item_hoglin_spawn_egg,
	mat_item_horse_spawn_egg,
	mat_item_husk_spawn_egg,
	mat_item_llama_spawn_egg,
	mat_item_magma_cube_spawn_egg,
	mat_item_mooshroom_spawn_egg,
	mat_item_mule_spawn_egg,
	mat_item_ocelot_spawn_egg,
	mat_item_panda_spawn_egg,
	mat_item_parrot_spawn_egg,
	mat_item_phantom_spawn_egg,
	mat_item_pig_spawn_egg,
	mat_item_piglin_spawn_egg,
	mat_item_piglin_brute_spawn_egg,
	mat_item_pillager_spawn_egg,
	mat_item_polar_bear_spawn_egg,
	mat_item_pufferfish_spawn_egg,
	mat_item_rabbit_spawn_egg,
	mat_item_ravager_spawn_egg,
	mat_item_salmon_spawn_egg,
	mat_item_sheep_spawn_egg,
	mat_item_shulker_spawn_egg,
	mat_item_silverfish_spawn_egg,
	mat_item_skeleton_horse_spawn_egg,
	mat_item_skeleton_spawn_egg,
	mat_item_slime_spawn_egg,
	mat_item_spider_spawn_egg,
	mat_item_squid_spawn_egg,
	mat_item_stray_spawn_egg,
	mat_item_strider_spawn_egg,
	mat_item_trader_llama_spawn_egg,
	mat_item_tropical_fish_spawn_egg,
	mat_item_turtle_spawn_egg,
	mat_item_vex_spawn_egg,
	mat_item_villager_spawn_egg,
	mat_item_vindicator_spawn_egg,
	mat_item_wandering_trader_spawn_egg,
	mat_item_witch_spawn_egg,
	mat_item_wither_skeleton_spawn_egg,
	mat_item_wolf_spawn_egg,
	mat_item_zoglin_spawn_egg,
	mat_item_zombie_horse_spawn_egg,
	mat_item_zombie_spawn_egg,
	mat_item_zombie_villager_spawn_egg,
	mat_item_zombified_piglin_spawn_egg,
	mat_item_acacia_button,
	mat_item_acacia_door,
	mat_item_acacia_fence,
	mat_item_acacia_fence_gate,
	mat_item_acacia_leaves,
	mat_item_acacia_log,
	mat_item_acacia_planks,
	mat_item_acacia_pressure_plate,
	mat_item_acacia_sapling,
	mat_item_acacia_sign,
	mat_item_acacia_slab,
	mat_item_acacia_stairs,
	mat_item_acacia_trapdoor,
	mat_item_acacia_wood,
	mat_item_activator_rail,
	mat_item_allium,
	mat_item_amethyst_cluster,
	mat_item_ancient_debris,
	mat_item_andesite,
	mat_item_andesite_slab,
	mat_item_andesite_stairs,
	mat_item_andesite_wall,
	mat_item_anvil,
	mat_item_azalea,
	mat_item_azalea_leaves,
	mat_item_azure_bluet,
	mat_item_bamboo,
	mat_item_bamboo_sapling,
	mat_item_beetroots,
	mat_item_barrel,
	mat_item_barrier,
	mat_item_basalt,
	mat_item_beacon,
	mat_item_bedrock,
	mat_item_beehive,
	mat_item_bee_nest,
	mat_item_bell,
	mat_item_big_dripleaf,
	mat_item_birch_button,
	mat_item_birch_door,
	mat_item_birch_fence,
	mat_item_birch_fence_gate,
	mat_item_birch_leaves,
	mat_item_birch_log,
	mat_item_birch_planks,
	mat_item_birch_pressure_plate,
	mat_item_birch_sapling,
	mat_item_birch_sign,
	mat_item_birch_slab,
	mat_item_birch_stairs,
	mat_item_birch_trapdoor,
	mat_item_birch_wood,
	mat_item_black_banner,
	mat_item_black_bed,
	mat_item_black_candle,
	mat_item_black_carpet,
	mat_item_black_concrete,
	mat_item_black_concrete_powder,
	mat_item_black_glazed_terracotta,
	mat_item_black_shulker_box,
	mat_item_black_stained_glass,
	mat_item_black_stained_glass_pane,
	mat_item_black_terracotta,
	mat_item_black_wool,
	mat_item_blackstone,
	mat_item_blackstone_slab,
	mat_item_blackstone_stairs,
	mat_item_blackstone_wall,
	mat_item_blast_furnace,
	mat_item_block_of_amethyst,
	mat_item_block_of_coal,
	mat_item_block_of_copper,
	mat_item_block_of_diamond,
	mat_item_emerald_block,
	mat_item_gold_block,
	mat_item_iron_block,
	mat_item_block_of_lapis_lazuli,
	mat_item_block_of_netherite,
	mat_item_block_of_quartz,
	mat_item_raw_copper_block,
	mat_item_block_of_raw_gold,
	mat_item_block_of_raw_iron,
	mat_item_block_of_redstone,
	mat_item_blue_banner,
	mat_item_blue_bed,
	mat_item_blue_candle,
	mat_item_blue_carpet,
	mat_item_blue_concrete,
	mat_item_blue_concrete_powder,
	mat_item_blue_glazed_terracotta,
	mat_item_blue_ice,
	mat_item_blue_orchid,
	mat_item_blue_shulker_box,
	mat_item_blue_stained_glass,
	mat_item_blue_stained_glass_pane,
	mat_item_blue_terracotta,
	mat_item_blue_wool,
	mat_item_bone_block,
	mat_item_bookshelf,
	mat_item_brain_coral,
	mat_item_brain_coral_block,
	mat_item_brain_coral_fan,
	mat_item_brewing_stand,
	mat_item_brick_slab,
	mat_item_brick_stairs,
	mat_item_brick_wall,
	mat_item_bricks,
	mat_item_brown_banner,
	mat_item_brown_bed,
	mat_item_brown_candle,
	mat_item_brown_carpet,
	mat_item_brown_concrete,
	mat_item_brown_concrete_powder,
	mat_item_brown_glazed_terracotta,
	mat_item_brown_mushroom,
	mat_item_brown_mushroom_block,
	mat_item_brown_shulker_box,
	mat_item_brown_stained_glass,
	mat_item_brown_stained_glass_pane,
	mat_item_brown_terracotta,
	mat_item_brown_wool,
	mat_item_bubble_coral,
	mat_item_bubble_coral_block,
	mat_item_bubble_coral_fan,
	mat_item_budding_amethyst,
	mat_item_cactus,
	mat_item_cake,
	mat_item_calcite,
	mat_item_campfire,
	mat_item_candle,
	mat_item_carrots,
	mat_item_cartography_table,
	mat_item_carved_pumpkin,
	mat_item_cauldron,
	mat_item_cave_vines,
	mat_item_chain,
	mat_item_chain_command_block,
	mat_item_chest,
	mat_item_chipped_anvil,
	mat_item_chiseled_deepslate,
	mat_item_chiseled_nether_bricks,
	mat_item_chiseled_polished_blackstone,
	mat_item_chiseled_quartz_block,
	mat_item_chiseled_red_sandstone,
	mat_item_chiseled_sandstone,
	mat_item_chiseled_stone_bricks,
	mat_item_chorus_flower,
	mat_item_chorus_plant,
	mat_item_clay,
	mat_item_coal_ore,
	mat_item_coarse_dirt,
	mat_item_cobbled_deepslate,
	mat_item_cobbled_deepslate_slab,
	mat_item_cobbled_deepslate_stairs,
	mat_item_cobbled_deepslate_wall,
	mat_item_cobblestone,
	mat_item_cobblestone_slab,
	mat_item_cobblestone_stairs,
	mat_item_cobblestone_wall,
	mat_item_cobweb,
	mat_item_cocoa,
	mat_item_command_block,
	mat_item_composter,
	mat_item_conduit,
	mat_item_copper_ore,
	mat_item_cornflower,
	mat_item_cracked_deepslate_bricks,
	mat_item_cracked_deepslate_tiles,
	mat_item_cracked_nether_bricks,
	mat_item_cracked_polished_blackstone_bricks,
	mat_item_cracked_stone_bricks,
	mat_item_crafting_table,
	mat_item_creeper_head,
	mat_item_crimson_button,
	mat_item_crimson_door,
	mat_item_crimson_fence,
	mat_item_crimson_fence_gate,
	mat_item_crimson_fungus,
	mat_item_crimson_hyphae,
	mat_item_crimson_nylium,
	mat_item_crimson_planks,
	mat_item_crimson_pressure_plate,
	mat_item_crimson_roots,
	mat_item_crimson_sign,
	mat_item_crimson_slab,
	mat_item_crimson_stairs,
	mat_item_crimson_stem,
	mat_item_crimson_trapdoor,
	mat_item_crying_obsidian,
	mat_item_cut_copper,
	mat_item_cut_copper_slab,
	mat_item_cut_copper_stairs,
	mat_item_cut_red_sandstone,
	mat_item_cut_red_sandstone_slab,
	mat_item_cut_sandstone,
	mat_item_cut_sandstone_slab,
	mat_item_cyan_banner,
	mat_item_cyan_bed,
	mat_item_cyan_candle,
	mat_item_cyan_carpet,
	mat_item_cyan_concrete,
	mat_item_cyan_concrete_powder,
	mat_item_cyan_glazed_terracotta,
	mat_item_cyan_shulker_box,
	mat_item_cyan_stained_glass,
	mat_item_cyan_stained_glass_pane,
	mat_item_cyan_terracotta,
	mat_item_cyan_wool,
	mat_item_damaged_anvil,
	mat_item_dandelion,
	mat_item_dark_oak_button,
	mat_item_dark_oak_door,
	mat_item_dark_oak_fence,
	mat_item_dark_oak_fence_gate,
	mat_item_dark_oak_leaves,
	mat_item_dark_oak_log,
	mat_item_dark_oak_planks,
	mat_item_dark_oak_pressure_plate,
	mat_item_dark_oak_sapling,
	mat_item_dark_oak_sign,
	mat_item_dark_oak_slab,
	mat_item_dark_oak_stairs,
	mat_item_dark_oak_trapdoor,
	mat_item_dark_oak_wood,
	mat_item_dark_prismarine,
	mat_item_dark_prismarine_slab,
	mat_item_dark_prismarine_stairs,
	mat_item_daylight_detector,
	mat_item_dead_brain_coral,
	mat_item_dead_brain_coral_block,
	mat_item_dead_brain_coral_fan,
	mat_item_dead_bubble_coral,
	mat_item_dead_bubble_coral_block,
	mat_item_dead_bubble_coral_fan,
	mat_item_dead_bush,
	mat_item_dead_fire_coral,
	mat_item_dead_fire_coral_block,
	mat_item_dead_fire_coral_fan,
	mat_item_dead_horn_coral,
	mat_item_dead_horn_coral_block,
	mat_item_dead_horn_coral_fan,
	mat_item_dead_tube_coral,
	mat_item_dead_tube_coral_block,
	mat_item_dead_tube_coral_fan,
	mat_item_deepslate,
	mat_item_deepslate_bricks,
	mat_item_deepslate_brick_slab,
	mat_item_deepslate_brick_stairs,
	mat_item_deepslate_brick_wall,
	mat_item_deepslate_coal_ore,
	mat_item_deepslate_copper_ore,
	mat_item_deepslate_diamond_ore,
	mat_item_deepslate_emerald_ore,
	mat_item_deepslate_gold_ore,
	mat_item_deepslate_iron_ore,
	mat_item_deepslate_lapis_lazuli_ore,
	mat_item_deepslate_redstone_ore,
	mat_item_deepslate_tiles,
	mat_item_deepslate_tile_slab,
	mat_item_deepslate_tile_stairs,
	mat_item_deepslate_tile_wall,
	mat_item_detector_rail,
	mat_item_diamond_ore,
	mat_item_diorite,
	mat_item_diorite_slab,
	mat_item_diorite_stairs,
	mat_item_diorite_wall,
	mat_item_dirt,
	mat_item_dirt_path,
	mat_item_dispenser,
	mat_item_dragon_egg,
	mat_item_dragon_head,
	mat_item_dried_kelp_block,
	mat_item_dripstone_block,
	mat_item_dropper,
	mat_item_emerald_ore,
	mat_item_enchanting_table,
	mat_item_end_portal_frame,
	mat_item_end_rod,
	mat_item_end_stone,
	mat_item_end_stone_brick_slab,
	mat_item_end_stone_brick_stairs,
	mat_item_end_stone_brick_wall,
	mat_item_end_stone_bricks,
	mat_item_ender_chest,
	mat_item_exposed_copper,
	mat_item_exposed_cut_copper,
	mat_item_exposed_cut_copper_slab,
	mat_item_exposed_cut_copper_stairs,
	mat_item_farmland,
	mat_item_fern,
	mat_item_fire,
	mat_item_fire_coral,
	mat_item_fire_coral_block,
	mat_item_fire_coral_fan,
	mat_item_fletching_table,
	mat_item_flower_pot,
	mat_item_flowering_azalea,
	mat_item_flowering_azalea_leaves,
	mat_item_furnace,
	mat_item_gilded_blackstone,
	mat_item_glass,
	mat_item_glass_pane,
	mat_item_glow_lichen,
	mat_item_glowstone,
	mat_item_gold_ore,
	mat_item_granite,
	mat_item_granite_slab,
	mat_item_granite_stairs,
	mat_item_granite_wall,
	mat_item_grass,
	mat_item_grass_block,
	mat_item_gravel,
	mat_item_gray_banner,
	mat_item_gray_bed,
	mat_item_gray_candle,
	mat_item_gray_carpet,
	mat_item_gray_concrete,
	mat_item_gray_concrete_powder,
	mat_item_gray_glazed_terracotta,
	mat_item_gray_shulker_box,
	mat_item_gray_stained_glass,
	mat_item_gray_stained_glass_pane,
	mat_item_gray_terracotta,
	mat_item_gray_wool,
	mat_item_green_banner,
	mat_item_green_bed,
	mat_item_green_candle,
	mat_item_green_carpet,
	mat_item_green_concrete,
	mat_item_green_concrete_powder,
	mat_item_green_glazed_terracotta,
	mat_item_green_shulker_box,
	mat_item_green_stained_glass,
	mat_item_green_stained_glass_pane,
	mat_item_green_terracotta,
	mat_item_green_wool,
	mat_item_grindstone,
	mat_item_hanging_roots,
	mat_item_hay_bale,
	mat_item_heavy_weighted_pressure_plate,
	mat_item_honey_block,
	mat_item_honeycomb_block,
	mat_item_hopper,
	mat_item_horn_coral,
	mat_item_horn_coral_block,
	mat_item_horn_coral_fan,
	mat_item_ice,
	mat_item_infested_chiseled_stone_bricks,
	mat_item_infested_cobblestone,
	mat_item_infested_cracked_stone_bricks,
	mat_item_infested_deepslate,
	mat_item_infested_mossy_stone_bricks,
	mat_item_infested_stone,
	mat_item_infested_stone_bricks,
	mat_item_iron_bars,
	mat_item_iron_door,
	mat_item_iron_ore,
	mat_item_iron_trapdoor,
	mat_item_jack_o_lantern,
	mat_item_jigsaw_block,
	mat_item_jukebox,
	mat_item_jungle_button,
	mat_item_jungle_door,
	mat_item_jungle_fence,
	mat_item_jungle_fence_gate,
	mat_item_jungle_leaves,
	mat_item_jungle_log,
	mat_item_jungle_planks,
	mat_item_jungle_pressure_plate,
	mat_item_jungle_sapling,
	mat_item_jungle_sign,
	mat_item_jungle_slab,
	mat_item_jungle_stairs,
	mat_item_jungle_trapdoor,
	mat_item_jungle_wood,
	mat_item_ladder,
	mat_item_lantern,
	mat_item_lapis_lazuli_ore,
	mat_item_large_amethyst_bud,
	mat_item_large_fern,
	mat_item_lava,
	mat_item_lectern,
	mat_item_lever,
	mat_item_light_block,
	mat_item_light_blue_banner,
	mat_item_light_blue_bed,
	mat_item_light_blue_candle,
	mat_item_light_blue_carpet,
	mat_item_light_blue_concrete,
	mat_item_light_blue_concrete_powder,
	mat_item_light_blue_glazed_terracotta,
	mat_item_light_blue_shulker_box,
	mat_item_light_blue_stained_glass,
	mat_item_light_blue_stained_glass_pane,
	mat_item_light_blue_terracotta,
	mat_item_light_blue_wool,
	mat_item_light_gray_banner,
	mat_item_light_gray_bed,
	mat_item_light_gray_candle,
	mat_item_light_gray_carpet,
	mat_item_light_gray_concrete,
	mat_item_light_gray_concrete_powder,
	mat_item_light_gray_glazed_terracotta,
	mat_item_light_gray_shulker_box,
	mat_item_light_gray_stained_glass,
	mat_item_light_gray_stained_glass_pane,
	mat_item_light_gray_terracotta,
	mat_item_light_gray_wool,
	mat_item_light_weighted_pressure_plate,
	mat_item_lightning_rod,
	mat_item_lilac,
	mat_item_lily_of_the_valley,
	mat_item_lily_pad,
	mat_item_lime_banner,
	mat_item_lime_bed,
	mat_item_lime_candle,
	mat_item_lime_carpet,
	mat_item_lime_concrete,
	mat_item_lime_concrete_powder,
	mat_item_lime_glazed_terracotta,
	mat_item_lime_shulker_box,
	mat_item_lime_stained_glass,
	mat_item_lime_stained_glass_pane,
	mat_item_lime_terracotta,
	mat_item_lime_wool,
	mat_item_lodestone,
	mat_item_loom,
	mat_item_magenta_banner,
	mat_item_magenta_bed,
	mat_item_magenta_candle,
	mat_item_magenta_carpet,
	mat_item_magenta_concrete,
	mat_item_magenta_concrete_powder,
	mat_item_magenta_glazed_terracotta,
	mat_item_magenta_shulker_box,
	mat_item_magenta_stained_glass,
	mat_item_magenta_stained_glass_pane,
	mat_item_magenta_terracotta,
	mat_item_magenta_wool,
	mat_item_magma_block,
	mat_item_medium_amethyst_bud,
	mat_item_melon,
	mat_item_melon_stem,
	mat_item_moss_block,
	mat_item_moss_carpet,
	mat_item_mossy_cobblestone,
	mat_item_mossy_cobblestone_slab,
	mat_item_mossy_cobblestone_stairs,
	mat_item_mossy_cobblestone_wall,
	mat_item_mossy_stone_brick_slab,
	mat_item_mossy_stone_brick_stairs,
	mat_item_mossy_stone_brick_wall,
	mat_item_mossy_stone_bricks,
	mat_item_mushroom_stem,
	mat_item_mycelium,
	mat_item_nether_brick_fence,
	mat_item_nether_brick_slab,
	mat_item_nether_brick_stairs,
	mat_item_nether_brick_wall,
	mat_item_nether_bricks,
	mat_item_nether_gold_ore,
	mat_item_nether_quartz_ore,
	mat_item_nether_sprouts,
	mat_item_nether_wart,
	mat_item_nether_wart_block,
	mat_item_netherrack,
	mat_item_note_block,
	mat_item_oak_button,
	mat_item_oak_door,
	mat_item_oak_fence,
	mat_item_oak_fence_gate,
	mat_item_oak_leaves,
	mat_item_oak_log,
	mat_item_oak_planks,
	mat_item_oak_pressure_plate,
	mat_item_oak_sapling,
	mat_item_oak_sign,
	mat_item_oak_slab,
	mat_item_oak_stairs,
	mat_item_oak_trapdoor,
	mat_item_oak_wood,
	mat_item_observer,
	mat_item_obsidian,
	mat_item_ominous_banner,
	mat_item_orange_banner,
	mat_item_orange_bed,
	mat_item_orange_candle,
	mat_item_orange_carpet,
	mat_item_orange_concrete,
	mat_item_orange_concrete_powder,
	mat_item_orange_glazed_terracotta,
	mat_item_orange_shulker_box,
	mat_item_orange_stained_glass,
	mat_item_orange_stained_glass_pane,
	mat_item_orange_terracotta,
	mat_item_orange_tulip,
	mat_item_orange_wool,
	mat_item_oxeye_daisy,
	mat_item_oxidized_copper,
	mat_item_oxidized_cut_copper,
	mat_item_oxidized_cut_copper_slab,
	mat_item_oxidized_cut_copper_stairs,
	mat_item_packed_ice,
	mat_item_peony,
	mat_item_petrified_oak_slab,
	mat_item_pink_banner,
	mat_item_pink_bed,
	mat_item_pink_candle,
	mat_item_pink_carpet,
	mat_item_pink_concrete,
	mat_item_pink_concrete_powder,
	mat_item_pink_glazed_terracotta,
	mat_item_pink_shulker_box,
	mat_item_pink_stained_glass,
	mat_item_pink_stained_glass_pane,
	mat_item_pink_terracotta,
	mat_item_pink_tulip,
	mat_item_pink_wool,
	mat_item_piston,
	mat_item_player_head,
	mat_item_podzol,
	mat_item_pointed_dripstone,
	mat_item_polished_andesite,
	mat_item_polished_andesite_slab,
	mat_item_polished_andesite_stairs,
	mat_item_polished_basalt,
	mat_item_polished_blackstone,
	mat_item_polished_blackstone_brick_slab,
	mat_item_polished_blackstone_brick_stairs,
	mat_item_polished_blackstone_brick_wall,
	mat_item_polished_blackstone_bricks,
	mat_item_polished_blackstone_button,
	mat_item_polished_blackstone_pressure_plate,
	mat_item_polished_blackstone_slab,
	mat_item_polished_blackstone_stairs,
	mat_item_polished_blackstone_wall,
	mat_item_polished_diorite,
	mat_item_polished_diorite_slab,
	mat_item_polished_diorite_stairs,
	mat_item_polished_granite,
	mat_item_polished_granite_slab,
	mat_item_polished_granite_stairs,
	mat_item_polished_deepslate,
	mat_item_polished_deepslate_slab,
	mat_item_polished_deepslate_stairs,
	mat_item_polished_deepslate_wall,
	mat_item_poppy,
	mat_item_potatoes,
	mat_item_powder_snow,
	mat_item_powered_rail,
	mat_item_prismarine,
	mat_item_prismarine_brick_slab,
	mat_item_prismarine_brick_stairs,
	mat_item_prismarine_bricks,
	mat_item_prismarine_slab,
	mat_item_prismarine_stairs,
	mat_item_prismarine_wall,
	mat_item_pumpkin,
	mat_item_pumpkin_stem,
	mat_item_purple_banner,
	mat_item_purple_bed,
	mat_item_purple_candle,
	mat_item_purple_carpet,
	mat_item_purple_concrete,
	mat_item_purple_concrete_powder,
	mat_item_purple_glazed_terracotta,
	mat_item_purple_shulker_box,
	mat_item_purple_stained_glass,
	mat_item_purple_stained_glass_pane,
	mat_item_purple_terracotta,
	mat_item_purple_wool,
	mat_item_purpur_block,
	mat_item_purpur_pillar,
	mat_item_purpur_slab,
	mat_item_purpur_stairs,
	mat_item_quartz_bricks,
	mat_item_quartz_pillar,
	mat_item_quartz_slab,
	mat_item_quartz_stairs,
	mat_item_rail,
	mat_item_red_banner,
	mat_item_red_bed,
	mat_item_red_candle,
	mat_item_red_carpet,
	mat_item_red_concrete,
	mat_item_red_concrete_powder,
	mat_item_red_glazed_terracotta,
	mat_item_red_mushroom,
	mat_item_red_mushroom_block,
	mat_item_red_nether_brick_slab,
	mat_item_red_nether_brick_stairs,
	mat_item_red_nether_brick_wall,
	mat_item_red_nether_bricks,
	mat_item_red_sand,
	mat_item_red_sandstone,
	mat_item_red_sandstone_slab,
	mat_item_red_sandstone_stairs,
	mat_item_red_sandstone_wall,
	mat_item_red_shulker_box,
	mat_item_red_stained_glass,
	mat_item_red_stained_glass_pane,
	mat_item_red_terracotta,
	mat_item_red_tulip,
	mat_item_red_wool,
	mat_item_comparator,
	mat_item_redstone_lamp,
	mat_item_redstone_ore,
	mat_item_repeater,
	mat_item_redstone_torch,
	mat_item_redstone_wire,
	mat_item_repeating_command_block,
	mat_item_respawn_anchor,
	mat_item_rooted_dirt,
	mat_item_rose_bush,
	mat_item_sand,
	mat_item_sandstone,
	mat_item_sandstone_slab,
	mat_item_sandstone_stairs,
	mat_item_sandstone_wall,
	mat_item_scaffolding,
	mat_item_sculk_sensor,
	mat_item_sea_lantern,
	mat_item_sea_pickle,
	mat_item_seagrass,
	mat_item_shroomlight,
	mat_item_shulker_box,
	mat_item_skeleton_skull,
	mat_item_slime_block,
	mat_item_small_amethyst_bud,
	mat_item_small_dripleaf,
	mat_item_smithing_table,
	mat_item_smoker,
	mat_item_smooth_basalt,
	mat_item_smooth_quartz_block,
	mat_item_smooth_quartz_slab,
	mat_item_smooth_quartz_stairs,
	mat_item_smooth_red_sandstone,
	mat_item_smooth_red_sandstone_slab,
	mat_item_smooth_red_sandstone_stairs,
	mat_item_smooth_sandstone,
	mat_item_smooth_sandstone_slab,
	mat_item_smooth_sandstone_stairs,
	mat_item_smooth_stone,
	mat_item_smooth_stone_slab,
	mat_item_snow,
	mat_item_snow_block,
	mat_item_soul_campfire,
	mat_item_soul_fire,
	mat_item_soul_lantern,
	mat_item_soul_sand,
	mat_item_soul_soil,
	mat_item_soul_torch,
	mat_item_spawner,
	mat_item_sponge,
	mat_item_spore_blossom,
	mat_item_spruce_button,
	mat_item_spruce_door,
	mat_item_spruce_fence,
	mat_item_spruce_fence_gate,
	mat_item_spruce_leaves,
	mat_item_spruce_log,
	mat_item_spruce_planks,
	mat_item_spruce_pressure_plate,
	mat_item_spruce_sapling,
	mat_item_spruce_sign,
	mat_item_spruce_slab,
	mat_item_spruce_stairs,
	mat_item_spruce_trapdoor,
	mat_item_spruce_wood,
	mat_item_sticky_piston,
	mat_item_stone,
	mat_item_stone_brick_slab,
	mat_item_stone_brick_stairs,
	mat_item_stone_brick_wall,
	mat_item_stone_bricks,
	mat_item_stone_button,
	mat_item_stone_pressure_plate,
	mat_item_stone_slab,
	mat_item_stone_stairs,
	mat_item_stonecutter,
	mat_item_stripped_acacia_log,
	mat_item_stripped_acacia_wood,
	mat_item_stripped_birch_log,
	mat_item_stripped_birch_wood,
	mat_item_stripped_crimson_hyphae,
	mat_item_stripped_crimson_stem,
	mat_item_stripped_dark_oak_log,
	mat_item_stripped_dark_oak_wood,
	mat_item_stripped_jungle_log,
	mat_item_stripped_jungle_wood,
	mat_item_stripped_oak_log,
	mat_item_stripped_oak_wood,
	mat_item_stripped_spruce_log,
	mat_item_stripped_spruce_wood,
	mat_item_stripped_warped_hyphae,
	mat_item_stripped_warped_stem,
	mat_item_structure_block,
	mat_item_structure_void,
	mat_item_sugar_cane,
	mat_item_sunflower,
	mat_item_sweet_berry_bush,
	mat_item_tall_grass,
	mat_item_tall_seagrass,
	mat_item_target,
	mat_item_terracotta,
	mat_item_tinted_glass,
	mat_item_tnt,
	mat_item_torch,
	mat_item_trapped_chest,
	mat_item_tripwire,
	mat_item_tripwire_hook,
	mat_item_tube_coral,
	mat_item_tube_coral_block,
	mat_item_tube_coral_fan,
	mat_item_tuff,
	mat_item_turtle_egg,
	mat_item_twisting_vines,
	mat_item_vines,
	mat_item_warped_button,
	mat_item_warped_door,
	mat_item_warped_fence,
	mat_item_warped_fence_gate,
	mat_item_warped_fungus,
	mat_item_warped_hyphae,
	mat_item_warped_nylium,
	mat_item_warped_planks,
	mat_item_warped_pressure_plate,
	mat_item_warped_roots,
	mat_item_warped_sign,
	mat_item_warped_slab,
	mat_item_warped_stairs,
	mat_item_warped_stem,
	mat_item_warped_trapdoor,
	mat_item_warped_wart_block,
	mat_item_water,
	mat_item_waxed_block_of_copper,
	mat_item_waxed_cut_copper,
	mat_item_waxed_cut_copper_slab,
	mat_item_waxed_cut_copper_stairs,
	mat_item_waxed_exposed_copper,
	mat_item_waxed_exposed_cut_copper,
	mat_item_waxed_exposed_cut_copper_slab,
	mat_item_waxed_exposed_cut_copper_stairs,
	mat_item_waxed_oxidized_copper,
	mat_item_waxed_oxidized_cut_copper,
	mat_item_waxed_oxidized_cut_copper_slab,
	mat_item_waxed_oxidized_cut_copper_stairs,
	mat_item_waxed_weathered_copper,
	mat_item_waxed_weathered_cut_copper,
	mat_item_waxed_weathered_cut_copper_slab,
	mat_item_waxed_weathered_cut_copper_stairs,
	mat_item_weathered_copper,
	mat_item_weathered_cut_copper,
	mat_item_weathered_cut_copper_slab,
	mat_item_weathered_cut_copper_stairs,
	mat_item_weeping_vines,
	mat_item_wet_sponge,
	mat_item_wheat_crops,
	mat_item_white_banner,
	mat_item_white_bed,
	mat_item_white_candle,
	mat_item_white_carpet,
	mat_item_white_concrete,
	mat_item_white_concrete_powder,
	mat_item_white_glazed_terracotta,
	mat_item_white_shulker_box,
	mat_item_white_stained_glass,
	mat_item_white_stained_glass_pane,
	mat_item_white_terracotta,
	mat_item_white_tulip,
	mat_item_white_wool,
	mat_item_wither_rose,
	mat_item_wither_skeleton_skull,
	mat_item_yellow_banner,
	mat_item_yellow_bed,
	mat_item_yellow_candle,
	mat_item_yellow_carpet,
	mat_item_yellow_concrete,
	mat_item_yellow_concrete_powder,
	mat_item_yellow_glazed_terracotta,
	mat_item_yellow_shulker_box,
	mat_item_yellow_stained_glass,
	mat_item_yellow_stained_glass_pane,
	mat_item_yellow_terracotta,
	mat_item_yellow_wool,
	mat_item_zombie_head

} mat_item_id_t;

typedef enum {

	mat_item_tag_equipment, // equipment tag
		mat_item_tag_weapon, // weapon tag
			mat_item_tag_tier, // tier tag

		mat_item_tag_armor, // armor tag

	mat_item_tag_stacks,
		mat_item_tag_stacks_16,

	mat_item_tag_block, // block tag

	mat_item_tag_food, // food tag

	mat_item_tag_entity, // entity tag
		mat_item_tag_entity_place, // throw_speed tag

	mat_item_tag_max

} mat_item_tag_t;

typedef struct {

	utl_bitset(mat_item_tag_max - 1, tags_set);

	union {

		struct {

			mat_equipment_type_t type;
			uint32_t max_durability;

		} equipment;

		struct {
			
			float32_t attack_speed;
			float32_t damage;

		} weapon;

		mat_equipment_tier_t tier;

		struct {

			uint8_t defense;
			uint8_t toughness;
			uint8_t knockback_resistance;

		} armor;

		mat_block_type_t block;

		struct {

			float32_t saturation;

			uint8_t speed; // how fast you eat it
			uint8_t food; // how much hunger it restores

		} food;

		uint32_t entity;

		float32_t throw_speed;

	} tags[];

} mat_item_t;

extern const mat_item_t* mat_items[];
extern const mat_item_id_t mat_items_protocol[];

static inline const mat_item_t* mat_get_item_by_id(mat_item_id_t id) {
	return mat_items[id];
}

static inline bool_t mat_is_equipment(const mat_item_t* item) {
	return utl_test_bit(item->tags_set, mat_item_tag_equipment);
}

static inline mat_equipment_type_t mat_get_equipment_type(const mat_item_t* item) {
	return item->tags[0].equipment.type;
}

static inline uint32_t mat_get_max_durability(const mat_item_t* item) {
	return item->tags[0].equipment.max_durability;
}

static inline bool_t mat_is_weapon(const mat_item_t* item) {
	return utl_test_bit(item->tags_set, mat_item_tag_weapon);
}

static inline float32_t mat_get_attack_speed(const mat_item_t* item) {
	return item->tags[1].weapon.attack_speed;
}

static inline float32_t mat_get_damage(const mat_item_t* item) {
	return item->tags[1].weapon.damage;
}

static inline bool_t mat_is_tiered(const mat_item_t* item) {
	return utl_test_bit(item->tags_set, mat_item_tag_tier);
}

static inline mat_equipment_tier_t mat_get_tier(const mat_item_t* item) {
	return item->tags[2].tier;
}

static inline bool_t mat_is_armor(const mat_item_t* item) {
	return utl_test_bit(item->tags_set, mat_item_tag_armor);
}

static inline uint8_t mat_get_defense(const mat_item_t* item) {
	return item->tags[1].armor.defense;
}

static inline uint8_t mat_get_toughness(const mat_item_t* item) {
	return item->tags[1].armor.toughness;
}

static inline uint8_t mat_get_knockback_resistance(const mat_item_t* item) {
	return item->tags[1].armor.knockback_resistance;
}

static inline bool_t mat_item_stacks(const mat_item_t* item) {
	return utl_test_bit(item->tags_set, mat_item_tag_stacks);
}

static inline bool_t mat_item_stacks_16(const mat_item_t* item) {
	return utl_test_bit(item->tags_set, mat_item_tag_stacks_16);
}

static inline bool_t mat_is_block(const mat_item_t* item) {
	return utl_test_bit(item->tags_set, mat_item_tag_block);
}

static inline mat_block_type_t mat_get_block_id(const mat_item_t* item) {
	return item->tags[0].block;
}

static inline bool_t mat_is_food(const mat_item_t* item) {
	return utl_test_bit(item->tags_set, mat_item_tag_food);
}

static inline float32_t mat_get_saturation(const mat_item_t* item) {
	return item->tags[0].food.saturation;
}

static inline uint8_t mat_get_food(const mat_item_t* item) {
	return item->tags[0].food.food;
}

static inline uint8_t mat_get_consume_speed(const mat_item_t* item) {
	return item->tags[0].food.speed;
}

static inline bool_t mat_is_entity(const mat_item_t* item) {
	return utl_test_bit(item->tags_set, mat_item_tag_entity);
}

static inline uint32_t mat_get_entity(const mat_item_t* item) {
	return item->tags[0].entity;
}

static inline bool_t mat_is_placed_entity(const mat_item_t* item) {
	return utl_test_bit(item->tags_set, mat_item_tag_entity_place);
}

static inline float32_t mat_get_throw_speed(const mat_item_t* item) {
	return item->tags[0].throw_speed;
}