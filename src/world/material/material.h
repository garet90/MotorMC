#pragma once
#include "../../main.h"

/*
	DIMENSIONS
*/

typedef enum {

	mat_dimension_overworld,
	mat_dimension_nether,
	mat_dimension_end,

	mat_dimension_count

} mat_dimension_type_t;

typedef struct {

	const string_t name;
	const string_t effects;
	float32_t ambient_light;
	float32_t coordinate_scale;
	bool_t has_fixed_time : 1;
	uint16_t fixed_time : 15;
	int16_t min_y;
	int16_t height;
	int16_t logical_height;
	bool_t piglin_safe : 1;
	bool_t natural : 1;
	bool_t respawn_anchor_works : 1;
	bool_t has_skylight : 1;
	bool_t bed_works : 1;
	bool_t has_raids : 1;
	bool_t ultrawarm : 1;
	bool_t has_ceiling : 1;

} mat_dimension_t;

extern const mat_dimension_t* mat_dimensions[];

static inline const mat_dimension_t* mat_get_dimension_by_type(mat_dimension_type_t type) {
	return mat_dimensions[type];
}

static inline uint16_t mat_get_chunk_height(mat_dimension_type_t type) {
	const mat_dimension_t* dimension = mat_get_dimension_by_type(type);
	return (dimension->height - dimension->min_y) >> 4;
}

/*
	BIOMES
*/

typedef enum {

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

} mat_biome_type_t;

typedef enum {

	mat_precipitation_rain,
	mat_precipitation_snow,
	mat_precipitation_none

} mat_precipitation_type_t;

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

typedef enum {

	mat_grass_color_modifier_none,
	mat_grass_color_modifier_swamp,
	mat_grass_color_modifier_dark_forest

} mat_grass_color_modifier_t;

typedef enum {

	mat_temperature_modifier_none,
	mat_temperature_modifier_frozen
	
} mat_temperature_modifier_t;

typedef struct {

	const string_t name;
	float32_t depth;
	float32_t temperature;
	float32_t scale;
	float32_t downfall;
	mat_biome_category_t category : 5;
	mat_temperature_modifier_t temperature_modifier : 1;
	mat_precipitation_type_t precipitation : 2;

	struct {

		uint32_t sky_color : 24;
		uint32_t water_fog_color : 24;
		uint32_t fog_color : 24;
		uint32_t water_color : 24;
		uint32_t foliage_color : 24;
		bool_t has_foliage_color : 1;
		uint32_t grass_color : 24;
		bool_t has_grass_color: 1;
		mat_grass_color_modifier_t grass_color_modifier : 2;

		struct {

			const string_t sound;
			uint32_t max_delay;
			uint32_t min_delay;
			bool_t replace_current_music : 1;
		
		} music;

		const string_t ambient_sound;

		struct {
		
			const string_t sound;
			float64_t tick_chance;
		
		} additions_sound;

		struct {
		
			const string_t sound;
			float64_t offset;
			uint32_t tick_delay;
			uint32_t block_search_extent;
		
		} mood_sound;

	} effects;

	struct {
		
		float32_t probability;
		struct {
			const string_t type;
		} options;

	} particle;

} mat_biome_t;

extern const mat_biome_t* mat_biomes[];

static inline const mat_biome_t* mat_get_biome_by_type(mat_biome_type_t type) {
	return mat_biomes[type];
}

/*
	CODEC
*/

typedef struct {

	size_t size;
	byte_t bytes[];

} mat_codec_t;

extern const mat_codec_t* mat_get_codec();

extern const mat_codec_t* mat_get_dimension_codec(mat_dimension_type_t dimension);

/*
	STATE MODIFIERS
	State modifiers are used to determine the state
*/

typedef enum {

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

} mat_state_modifier_type_t;

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

typedef enum {

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

} mat_block_type_t;

typedef uint16_t mat_block_protocol_id_t;

typedef struct {

	float32_t resistance;
		// blast resistance

	float32_t hardness;
		// hardness value for calculating break times

	uint8_t luminance : 4;
	uint8_t encouragement : 6;
	uint8_t flammability : 7;

	struct {
		
		mat_equipment_type_t type : 5;
		mat_equipment_tier_t tier : 3;

	} best_tool;

	mat_block_entity_type_t entity : 5;

	bool_t catches_fire_from_lava : 1;
	bool_t light_filtering : 1;
	bool_t transparent : 1;

	uint8_t modifiers_count : 3;
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

	for (int32_t i = block_data->modifiers_count - 1; i >= 0; --i) {

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

	for (int32_t i = block_data->modifiers_count - 1; i >= 0; --i) {

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

/*
	ITEMS
*/

typedef enum {

	mat_item_air = 0,
	mat_item_stone_block = 1

} mat_item_type_t;