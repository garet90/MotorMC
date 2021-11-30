#pragma once
#include "../../../main.h"

typedef struct {

	string_t identifier;
	int32_t count;
	int32_t entries[];

} mat_tag_t;

#define MAT_TAG_INITIALIZER(name, ...) { .identifier = name, .count = sizeof((int32_t[]) { __VA_ARGS__ }) / sizeof(int32_t), .entries = { __VA_ARGS__ } }

typedef enum {

	mat_fluid_tag_water,
	mat_fluid_tag_lava,

	mat_fluid_tag_count

} mat_fluid_tag_t;

extern const mat_tag_t* mat_fluid_tags[];

typedef enum {

	mat_item_tag_banners,
	mat_item_tag_soul_fire_base_blocks,
	mat_item_tag_stone_crafting_materials,
	mat_item_tag_wooden_fences,
	mat_item_tag_piglin_repellents,
	mat_item_tag_beacon_payment_items,
	mat_item_tag_wooden_slabs,
	mat_item_tag_coal_ores,
	mat_item_tag_occludes_vibration_signals,
	mat_item_tag_small_flowers,
	mat_item_tag_wooden_trapdoors,
	mat_item_tag_jungle_logs,
	mat_item_tag_lectern_books,
	mat_item_tag_wooden_stairs,
	mat_item_tag_spruce_logs,
	mat_item_tag_signs,
	mat_item_tag_axolotl_tempt_items,
	mat_item_tag_carpets,
	mat_item_tag_wool,
	mat_item_tag_wooden_buttons,
	mat_item_tag_stairs,
	mat_item_tag_fishes,
	mat_item_tag_logs,
	mat_item_tag_stone_bricks,
	mat_item_tag_creeper_drop_music_discs,
	mat_item_tag_arrows,
	mat_item_tag_slabs,
	mat_item_tag_wooden_doors,
	mat_item_tag_warped_stems,
	mat_item_tag_emerald_ores,
	mat_item_tag_trapdoors,
	mat_item_tag_redstone_ores,
	mat_item_tag_crimson_stems,
	mat_item_tag_ignored_by_piglin_babies,
	mat_item_tag_buttons,
	mat_item_tag_flowers,
	mat_item_tag_stone_tool_materials,
	mat_item_tag_planks,
	mat_item_tag_fox_food,
	mat_item_tag_boats,
	mat_item_tag_dark_oak_logs,
	mat_item_tag_rails,
	mat_item_tag_diamond_ores,
	mat_item_tag_non_flammable_wood,
	mat_item_tag_leaves,
	mat_item_tag_walls,
	mat_item_tag_coals,
	mat_item_tag_piglin_food,
	mat_item_tag_wooden_pressure_plates,
	mat_item_tag_acacia_logs,
	mat_item_tag_anvil,
	mat_item_tag_piglin_loved,
	mat_item_tag_candles,
	mat_item_tag_music_discs,
	mat_item_tag_birch_logs,
	mat_item_tag_tall_flowers,
	mat_item_tag_lapis_ores,
	mat_item_tag_sand,
	mat_item_tag_copper_ores,
	mat_item_tag_gold_ores,
	mat_item_tag_freeze_immune_wearables,
	mat_item_tag_logs_that_burn,
	mat_item_tag_fences,
	mat_item_tag_saplings,
	mat_item_tag_beds,
	mat_item_tag_iron_ores,
	mat_item_tag_oak_logs,
	mat_item_tag_doors,
	mat_item_tag_cluster_max_harvestables,
	mat_item_tag_dirt,
	mat_item_tag_terracotta,
	
	mat_item_tag_count

} mat_item_tag_t;

extern const mat_tag_t* mat_item_tags[];

typedef enum {

	mat_block_tag_catches_fire_from_lava,
	mat_block_tag_light_filtering,
	mat_block_tag_transparent,
	mat_block_tag_mineable,
	mat_block_tag_needs,
	mat_block_tag_needs_wooden_tool,
	mat_block_tag_air,
	mat_block_tag_mineable_axe,
	mat_block_tag_mineable_hoe,
	mat_block_tag_mineable_pickaxe,
	mat_block_tag_mineable_shovel,
	mat_block_tag_acacia_logs,
	mat_block_tag_anvil,
	mat_block_tag_bamboo_plantable_on,
	mat_block_tag_banners,
	mat_block_tag_base_stone_nether,
	mat_block_tag_base_stone_overworld,
	mat_block_tag_beacon_base_blocks,
	mat_block_tag_beds,
	mat_block_tag_beehives,
	mat_block_tag_bee_growables,
	mat_block_tag_birch_logs,
	mat_block_tag_buttons,
	mat_block_tag_campfires,
	mat_block_tag_candle_cakes,
	mat_block_tag_candles,
	mat_block_tag_carpets,
	mat_block_tag_cauldrons,
	mat_block_tag_cave_vines,
	mat_block_tag_climbable,
	mat_block_tag_coal_ores,
	mat_block_tag_copper_ores,
	mat_block_tag_corals,
	mat_block_tag_coral_blocks,
	mat_block_tag_coral_plants,
	mat_block_tag_crimson_stems,
	mat_block_tag_crops,
	mat_block_tag_crystal_sound_blocks,
	mat_block_tag_dark_oak_logs,
	mat_block_tag_deepslate_ore_replaceables,
	mat_block_tag_diamond_ores,
	mat_block_tag_dirt,
	mat_block_tag_doors,
	mat_block_tag_dragon_immune,
	mat_block_tag_dripstone_replaceable_blocks,
	mat_block_tag_emerald_ores,
	mat_block_tag_enderman_holdable,
	mat_block_tag_features_cannot_replace,
	mat_block_tag_fence_gates,
	mat_block_tag_fences,
	mat_block_tag_fire,
	mat_block_tag_flower_pots,
	mat_block_tag_flowers,
	mat_block_tag_geode_invalid_blocks,
	mat_block_tag_gold_ores,
	mat_block_tag_guarded_by_piglins,
	mat_block_tag_hoglin_repellents,
	mat_block_tag_ice,
	mat_block_tag_impermeable,
	mat_block_tag_infiniburn_end,
	mat_block_tag_infiniburn_nether,
	mat_block_tag_infiniburn_overworld,
	mat_block_tag_inside_step_sound_blocks,
	mat_block_tag_iron_ores,
	mat_block_tag_jungle_logs,
	mat_block_tag_lapis_ores,
	mat_block_tag_lava_pool_stone_cannot_replace,
	mat_block_tag_leaves,
	mat_block_tag_logs,
	mat_block_tag_logs_that_burn,
	mat_block_tag_lush_ground_replaceable,
	mat_block_tag_moss_replaceable,
	mat_block_tag_mushroom_grow_block,
	mat_block_tag_needs_diamond_tool,
	mat_block_tag_needs_iron_tool,
	mat_block_tag_needs_stone_tool,
	mat_block_tag_non_flammable_wood,
	mat_block_tag_nylium,
	mat_block_tag_oak_logs,
	mat_block_tag_occludes_vibration_signals,
	mat_block_tag_piglin_repellents,
	mat_block_tag_planks,
	mat_block_tag_portals,
	mat_block_tag_pressure_plates,
	mat_block_tag_prevent_mob_spawning_inside,
	mat_block_tag_rails,
	mat_block_tag_redstone_ores,
	mat_block_tag_sand,
	mat_block_tag_saplings,
	mat_block_tag_shulker_boxes,
	mat_block_tag_signs,
	mat_block_tag_slabs,
	mat_block_tag_small_dripleaf_placeable,
	mat_block_tag_small_flowers,
	mat_block_tag_snow,
	mat_block_tag_soul_fire_base_blocks,
	mat_block_tag_soul_speed_blocks,
	mat_block_tag_spruce_logs,
	mat_block_tag_stairs,
	mat_block_tag_standing_signs,
	mat_block_tag_stone_bricks,
	mat_block_tag_stone_ore_replaceables,
	mat_block_tag_stone_pressure_plates,
	mat_block_tag_strider_warm_blocks,
	mat_block_tag_tall_flowers,
	mat_block_tag_trapdoors,
	mat_block_tag_underwater_bonemeals,
	mat_block_tag_unstable_bottom_center,
	mat_block_tag_valid_spawn,
	mat_block_tag_walls,
	mat_block_tag_wall_corals,
	mat_block_tag_wall_post_override,
	mat_block_tag_wall_signs,
	mat_block_tag_warped_stems,
	mat_block_tag_wart_blocks,
	mat_block_tag_wither_immune,
	mat_block_tag_wither_summon_base_blocks,
	mat_block_tag_wooden_buttons,
	mat_block_tag_wooden_doors,
	mat_block_tag_wooden_fences,
	mat_block_tag_wooden_pressure_plates,
	mat_block_tag_wooden_slabs,
	mat_block_tag_wooden_stairs,
	mat_block_tag_wooden_trapdoors,
	mat_block_tag_wool,
	mat_block_tag_animals_spawnable_on,
	mat_block_tag_axolotls_spawnable_on,
	mat_block_tag_azalea_grows_on,
	mat_block_tag_azalea_root_replaceable,
	mat_block_tag_big_dripleaf_placeable,
	mat_block_tag_foxes_spawnable_on,
	mat_block_tag_goats_spawnable_on,
	mat_block_tag_mooshrooms_spawnable_on,
	mat_block_tag_parrots_spawnable_on,
	mat_block_tag_polar_bears_spawnable_on_in_frozen_ocean,
	mat_block_tag_rabbits_spawnable_on,
	mat_block_tag_replaceable_plants,
	mat_block_tag_terracotta,
	mat_block_tag_wolves_spawnable_on,
	
	mat_block_tag_count

} mat_block_tag_t;

extern const mat_tag_t* mat_block_tags[];

typedef enum {

	mat_game_event_tag_vibrations,
	mat_game_event_tag_ignore_vibrations_sneaking,

	mat_game_event_tag_count

} mat_game_event_tag_t;

extern const mat_tag_t* mat_game_event_tags[];

typedef enum {

	mat_entity_type_tag_axolotl_always_hostiles,
	mat_entity_type_tag_freeze_hurts_extra_types,
	mat_entity_type_tag_freeze_immune_entity_types,
	mat_entity_type_tag_beehive_inhabitors,
	mat_entity_type_tag_impact_projectiles,
	mat_entity_type_tag_skeletons,
	mat_entity_type_tag_raiders,
	mat_entity_type_tag_powder_snow_walkable_mobs,
	mat_entity_type_tag_axolotl_hunt_targets,
	mat_entity_type_tag_arrows,
	
	mat_entity_type_tag_count

} mat_entity_type_tag_t;

extern const mat_tag_t* mat_entity_type_tags[];