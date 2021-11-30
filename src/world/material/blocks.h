#pragma once
#include "../../main.h"
#include "block_entities.h"
#include "state_modifiers.h"

/*
	BLOCKS
	Blocks are the basic building blocks of the world
*/

typedef enum {

	mat_block_air,
	mat_block_stone,
	mat_block_granite,
	mat_block_polished_granite,
	mat_block_diorite,
	mat_block_polished_diorite,
	mat_block_andesite,
	mat_block_polished_andesite,
	mat_block_grass_block,
	mat_block_dirt,
	mat_block_coarse_dirt,
	mat_block_podzol,
	mat_block_cobblestone,
	mat_block_oak_planks,
	mat_block_spruce_planks,
	mat_block_birch_planks,
	mat_block_jungle_planks,
	mat_block_acacia_planks,
	mat_block_dark_oak_planks,
	mat_block_oak_sapling,
	mat_block_spruce_sapling,
	mat_block_birch_sapling,
	mat_block_jungle_sapling,
	mat_block_acacia_sapling,
	mat_block_dark_oak_sapling,
	mat_block_bedrock,
	mat_block_water,
	mat_block_lava,
	mat_block_sand,
	mat_block_red_sand,
	mat_block_gravel,
	mat_block_gold_ore,
	mat_block_deepslate_gold_ore,
	mat_block_iron_ore,
	mat_block_deepslate_iron_ore,
	mat_block_coal_ore,
	mat_block_deepslate_coal_ore,
	mat_block_nether_gold_ore,
	mat_block_oak_log,
	mat_block_spruce_log,
	mat_block_birch_log,
	mat_block_jungle_log,
	mat_block_acacia_log,
	mat_block_dark_oak_log,
	mat_block_stripped_spruce_log,
	mat_block_stripped_birch_log,
	mat_block_stripped_jungle_log,
	mat_block_stripped_acacia_log,
	mat_block_stripped_dark_oak_log,
	mat_block_stripped_oak_log,
	mat_block_oak_wood,
	mat_block_spruce_wood,
	mat_block_birch_wood,
	mat_block_jungle_wood,
	mat_block_acacia_wood,
	mat_block_dark_oak_wood,
	mat_block_stripped_oak_wood,
	mat_block_stripped_spruce_wood,
	mat_block_stripped_birch_wood,
	mat_block_stripped_jungle_wood,
	mat_block_stripped_acacia_wood,
	mat_block_stripped_dark_oak_wood,
	mat_block_oak_leaves,
	mat_block_spruce_leaves,
	mat_block_birch_leaves,
	mat_block_jungle_leaves,
	mat_block_acacia_leaves,
	mat_block_dark_oak_leaves,
	mat_block_azalea_leaves,
	mat_block_flowering_azalea_leaves,
	mat_block_sponge,
	mat_block_wet_sponge,
	mat_block_glass,
	mat_block_lapis_ore,
	mat_block_deepslate_lapis_ore,
	mat_block_lapis_block,
	mat_block_dispenser,
	mat_block_sandstone,
	mat_block_chiseled_sandstone,
	mat_block_cut_sandstone,
	mat_block_note_block,
	mat_block_white_bed,
	mat_block_orange_bed,
	mat_block_magenta_bed,
	mat_block_light_blue_bed,
	mat_block_yellow_bed,
	mat_block_lime_bed,
	mat_block_pink_bed,
	mat_block_gray_bed,
	mat_block_light_gray_bed,
	mat_block_cyan_bed,
	mat_block_purple_bed,
	mat_block_blue_bed,
	mat_block_brown_bed,
	mat_block_green_bed,
	mat_block_red_bed,
	mat_block_black_bed,
	mat_block_powered_rail,
	mat_block_detector_rail,
	mat_block_sticky_piston,
	mat_block_cobweb,
	mat_block_grass,
	mat_block_fern,
	mat_block_dead_bush,
	mat_block_seagrass,
	mat_block_tall_seagrass,
	mat_block_piston,
	mat_block_piston_head,
	mat_block_white_wool,
	mat_block_orange_wool,
	mat_block_magenta_wool,
	mat_block_light_blue_wool,
	mat_block_yellow_wool,
	mat_block_lime_wool,
	mat_block_pink_wool,
	mat_block_gray_wool,
	mat_block_light_gray_wool,
	mat_block_cyan_wool,
	mat_block_purple_wool,
	mat_block_blue_wool,
	mat_block_brown_wool,
	mat_block_green_wool,
	mat_block_red_wool,
	mat_block_black_wool,
	mat_block_moving_piston,
	mat_block_dandelion,
	mat_block_poppy,
	mat_block_blue_orchid,
	mat_block_allium,
	mat_block_azure_bluet,
	mat_block_red_tulip,
	mat_block_orange_tulip,
	mat_block_white_tulip,
	mat_block_pink_tulip,
	mat_block_oxeye_daisy,
	mat_block_cornflower,
	mat_block_wither_rose,
	mat_block_lily_of_the_valley,
	mat_block_brown_mushroom,
	mat_block_red_mushroom,
	mat_block_gold_block,
	mat_block_iron_block,
	mat_block_bricks,
	mat_block_tnt,
	mat_block_bookshelf,
	mat_block_mossy_cobblestone,
	mat_block_obsidian,
	mat_block_torch,
	mat_block_wall_torch,
	mat_block_fire,
	mat_block_soul_fire,
	mat_block_spawner,
	mat_block_oak_stairs,
	mat_block_chest,
	mat_block_redstone_wire,
	mat_block_diamond_ore,
	mat_block_deepslate_diamond_ore,
	mat_block_diamond_block,
	mat_block_crafting_table,
	mat_block_wheat,
	mat_block_farmland,
	mat_block_furnace,
	mat_block_oak_sign,
	mat_block_spruce_sign,
	mat_block_birch_sign,
	mat_block_acacia_sign,
	mat_block_jungle_sign,
	mat_block_dark_oak_sign,
	mat_block_oak_door,
	mat_block_ladder,
	mat_block_rail,
	mat_block_cobblestone_stairs,
	mat_block_oak_wall_sign,
	mat_block_spruce_wall_sign,
	mat_block_birch_wall_sign,
	mat_block_acacia_wall_sign,
	mat_block_jungle_wall_sign,
	mat_block_dark_oak_wall_sign,
	mat_block_lever,
	mat_block_stone_pressure_plate,
	mat_block_iron_door,
	mat_block_oak_pressure_plate,
	mat_block_spruce_pressure_plate,
	mat_block_birch_pressure_plate,
	mat_block_jungle_pressure_plate,
	mat_block_acacia_pressure_plate,
	mat_block_dark_oak_pressure_plate,
	mat_block_redstone_ore,
	mat_block_deepslate_redstone_ore,
	mat_block_redstone_torch,
	mat_block_redstone_wall_torch,
	mat_block_stone_button,
	mat_block_snow,
	mat_block_ice,
	mat_block_snow_block,
	mat_block_cactus,
	mat_block_clay,
	mat_block_sugar_cane,
	mat_block_jukebox,
	mat_block_oak_fence,
	mat_block_pumpkin,
	mat_block_netherrack,
	mat_block_soul_sand,
	mat_block_soul_soil,
	mat_block_basalt,
	mat_block_polished_basalt,
	mat_block_soul_torch,
	mat_block_soul_wall_torch,
	mat_block_glowstone,
	mat_block_nether_portal,
	mat_block_carved_pumpkin,
	mat_block_jack_o_lantern,
	mat_block_cake,
	mat_block_repeater,
	mat_block_white_stained_glass,
	mat_block_orange_stained_glass,
	mat_block_magenta_stained_glass,
	mat_block_light_blue_stained_glass,
	mat_block_yellow_stained_glass,
	mat_block_lime_stained_glass,
	mat_block_pink_stained_glass,
	mat_block_gray_stained_glass,
	mat_block_light_gray_stained_glass,
	mat_block_cyan_stained_glass,
	mat_block_purple_stained_glass,
	mat_block_blue_stained_glass,
	mat_block_brown_stained_glass,
	mat_block_green_stained_glass,
	mat_block_red_stained_glass,
	mat_block_black_stained_glass,
	mat_block_oak_trapdoor,
	mat_block_spruce_trapdoor,
	mat_block_birch_trapdoor,
	mat_block_jungle_trapdoor,
	mat_block_acacia_trapdoor,
	mat_block_dark_oak_trapdoor,
	mat_block_stone_bricks,
	mat_block_mossy_stone_bricks,
	mat_block_cracked_stone_bricks,
	mat_block_chiseled_stone_bricks,
	mat_block_infested_stone,
	mat_block_infested_cobblestone,
	mat_block_infested_stone_bricks,
	mat_block_infested_mossy_stone_bricks,
	mat_block_infested_cracked_stone_bricks,
	mat_block_infested_chiseled_stone_bricks,
	mat_block_brown_mushroom_block,
	mat_block_red_mushroom_block,
	mat_block_mushroom_stem,
	mat_block_iron_bars,
	mat_block_chain,
	mat_block_glass_pane,
	mat_block_melon,
	mat_block_attached_pumpkin_stem,
	mat_block_attached_melon_stem,
	mat_block_pumpkin_stem,
	mat_block_melon_stem,
	mat_block_vine,
	mat_block_glow_lichen,
	mat_block_oak_fence_gate,
	mat_block_brick_stairs,
	mat_block_stone_brick_stairs,
	mat_block_mycelium,
	mat_block_lily_pad,
	mat_block_nether_bricks,
	mat_block_nether_brick_fence,
	mat_block_nether_brick_stairs,
	mat_block_nether_wart,
	mat_block_enchanting_table,
	mat_block_brewing_stand,
	mat_block_cauldron,
	mat_block_water_cauldron,
	mat_block_lava_cauldron,
	mat_block_powder_snow_cauldron,
	mat_block_end_portal,
	mat_block_end_portal_frame,
	mat_block_end_stone,
	mat_block_dragon_egg,
	mat_block_redstone_lamp,
	mat_block_cocoa,
	mat_block_sandstone_stairs,
	mat_block_emerald_ore,
	mat_block_deepslate_emerald_ore,
	mat_block_ender_chest,
	mat_block_tripwire_hook,
	mat_block_tripwire,
	mat_block_emerald_block,
	mat_block_spruce_stairs,
	mat_block_birch_stairs,
	mat_block_jungle_stairs,
	mat_block_command_block,
	mat_block_beacon,
	mat_block_cobblestone_wall,
	mat_block_mossy_cobblestone_wall,
	mat_block_flower_pot,
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
	mat_block_carrots,
	mat_block_potatoes,
	mat_block_oak_button,
	mat_block_spruce_button,
	mat_block_birch_button,
	mat_block_jungle_button,
	mat_block_acacia_button,
	mat_block_dark_oak_button,
	mat_block_skeleton_skull,
	mat_block_skeleton_wall_skull,
	mat_block_wither_skeleton_skull,
	mat_block_wither_skeleton_wall_skull,
	mat_block_zombie_head,
	mat_block_zombie_wall_head,
	mat_block_player_head,
	mat_block_player_wall_head,
	mat_block_creeper_head,
	mat_block_creeper_wall_head,
	mat_block_dragon_head,
	mat_block_dragon_wall_head,
	mat_block_anvil,
	mat_block_chipped_anvil,
	mat_block_damaged_anvil,
	mat_block_trapped_chest,
	mat_block_light_weighted_pressure_plate,
	mat_block_heavy_weighted_pressure_plate,
	mat_block_comparator,
	mat_block_daylight_detector,
	mat_block_redstone_block,
	mat_block_nether_quartz_ore,
	mat_block_hopper,
	mat_block_quartz_block,
	mat_block_chiseled_quartz_block,
	mat_block_quartz_pillar,
	mat_block_quartz_stairs,
	mat_block_activator_rail,
	mat_block_dropper,
	mat_block_white_terracotta,
	mat_block_orange_terracotta,
	mat_block_magenta_terracotta,
	mat_block_light_blue_terracotta,
	mat_block_yellow_terracotta,
	mat_block_lime_terracotta,
	mat_block_pink_terracotta,
	mat_block_gray_terracotta,
	mat_block_light_gray_terracotta,
	mat_block_cyan_terracotta,
	mat_block_purple_terracotta,
	mat_block_blue_terracotta,
	mat_block_brown_terracotta,
	mat_block_green_terracotta,
	mat_block_red_terracotta,
	mat_block_black_terracotta,
	mat_block_white_stained_glass_pane,
	mat_block_orange_stained_glass_pane,
	mat_block_magenta_stained_glass_pane,
	mat_block_light_blue_stained_glass_pane,
	mat_block_yellow_stained_glass_pane,
	mat_block_lime_stained_glass_pane,
	mat_block_pink_stained_glass_pane,
	mat_block_gray_stained_glass_pane,
	mat_block_light_gray_stained_glass_pane,
	mat_block_cyan_stained_glass_pane,
	mat_block_purple_stained_glass_pane,
	mat_block_blue_stained_glass_pane,
	mat_block_brown_stained_glass_pane,
	mat_block_green_stained_glass_pane,
	mat_block_red_stained_glass_pane,
	mat_block_black_stained_glass_pane,
	mat_block_acacia_stairs,
	mat_block_dark_oak_stairs,
	mat_block_slime_block,
	mat_block_barrier,
	mat_block_light,
	mat_block_iron_trapdoor,
	mat_block_prismarine,
	mat_block_prismarine_bricks,
	mat_block_dark_prismarine,
	mat_block_prismarine_stairs,
	mat_block_prismarine_brick_stairs,
	mat_block_dark_prismarine_stairs,
	mat_block_prismarine_slab,
	mat_block_prismarine_brick_slab,
	mat_block_dark_prismarine_slab,
	mat_block_sea_lantern,
	mat_block_hay_block,
	mat_block_white_carpet,
	mat_block_orange_carpet,
	mat_block_magenta_carpet,
	mat_block_light_blue_carpet,
	mat_block_yellow_carpet,
	mat_block_lime_carpet,
	mat_block_pink_carpet,
	mat_block_gray_carpet,
	mat_block_light_gray_carpet,
	mat_block_cyan_carpet,
	mat_block_purple_carpet,
	mat_block_blue_carpet,
	mat_block_brown_carpet,
	mat_block_green_carpet,
	mat_block_red_carpet,
	mat_block_black_carpet,
	mat_block_terracotta,
	mat_block_coal_block,
	mat_block_packed_ice,
	mat_block_sunflower,
	mat_block_lilac,
	mat_block_rose_bush,
	mat_block_peony,
	mat_block_tall_grass,
	mat_block_large_fern,
	mat_block_white_banner,
	mat_block_orange_banner,
	mat_block_magenta_banner,
	mat_block_light_blue_banner,
	mat_block_yellow_banner,
	mat_block_lime_banner,
	mat_block_pink_banner,
	mat_block_gray_banner,
	mat_block_light_gray_banner,
	mat_block_cyan_banner,
	mat_block_purple_banner,
	mat_block_blue_banner,
	mat_block_brown_banner,
	mat_block_green_banner,
	mat_block_red_banner,
	mat_block_black_banner,
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
	mat_block_red_sandstone,
	mat_block_chiseled_red_sandstone,
	mat_block_cut_red_sandstone,
	mat_block_red_sandstone_stairs,
	mat_block_oak_slab,
	mat_block_spruce_slab,
	mat_block_birch_slab,
	mat_block_jungle_slab,
	mat_block_acacia_slab,
	mat_block_dark_oak_slab,
	mat_block_stone_slab,
	mat_block_smooth_stone_slab,
	mat_block_sandstone_slab,
	mat_block_cut_sandstone_slab,
	mat_block_petrified_oak_slab,
	mat_block_cobblestone_slab,
	mat_block_brick_slab,
	mat_block_stone_brick_slab,
	mat_block_nether_brick_slab,
	mat_block_quartz_slab,
	mat_block_red_sandstone_slab,
	mat_block_cut_red_sandstone_slab,
	mat_block_purpur_slab,
	mat_block_smooth_stone,
	mat_block_smooth_sandstone,
	mat_block_smooth_quartz,
	mat_block_smooth_red_sandstone,
	mat_block_spruce_fence_gate,
	mat_block_birch_fence_gate,
	mat_block_jungle_fence_gate,
	mat_block_acacia_fence_gate,
	mat_block_dark_oak_fence_gate,
	mat_block_spruce_fence,
	mat_block_birch_fence,
	mat_block_jungle_fence,
	mat_block_acacia_fence,
	mat_block_dark_oak_fence,
	mat_block_spruce_door,
	mat_block_birch_door,
	mat_block_jungle_door,
	mat_block_acacia_door,
	mat_block_dark_oak_door,
	mat_block_end_rod,
	mat_block_chorus_plant,
	mat_block_chorus_flower,
	mat_block_purpur_block,
	mat_block_purpur_pillar,
	mat_block_purpur_stairs,
	mat_block_end_stone_bricks,
	mat_block_beetroots,
	mat_block_dirt_path,
	mat_block_end_gateway,
	mat_block_repeating_command_block,
	mat_block_chain_command_block,
	mat_block_frosted_ice,
	mat_block_magma_block,
	mat_block_nether_wart_block,
	mat_block_red_nether_bricks,
	mat_block_bone_block,
	mat_block_structure_void,
	mat_block_observer,
	mat_block_shulker_box,
	mat_block_white_shulker_box,
	mat_block_orange_shulker_box,
	mat_block_magenta_shulker_box,
	mat_block_light_blue_shulker_box,
	mat_block_yellow_shulker_box,
	mat_block_lime_shulker_box,
	mat_block_pink_shulker_box,
	mat_block_gray_shulker_box,
	mat_block_light_gray_shulker_box,
	mat_block_cyan_shulker_box,
	mat_block_purple_shulker_box,
	mat_block_blue_shulker_box,
	mat_block_brown_shulker_box,
	mat_block_green_shulker_box,
	mat_block_red_shulker_box,
	mat_block_black_shulker_box,
	mat_block_white_glazed_terracotta,
	mat_block_orange_glazed_terracotta,
	mat_block_magenta_glazed_terracotta,
	mat_block_light_blue_glazed_terracotta,
	mat_block_yellow_glazed_terracotta,
	mat_block_lime_glazed_terracotta,
	mat_block_pink_glazed_terracotta,
	mat_block_gray_glazed_terracotta,
	mat_block_light_gray_glazed_terracotta,
	mat_block_cyan_glazed_terracotta,
	mat_block_purple_glazed_terracotta,
	mat_block_blue_glazed_terracotta,
	mat_block_brown_glazed_terracotta,
	mat_block_green_glazed_terracotta,
	mat_block_red_glazed_terracotta,
	mat_block_black_glazed_terracotta,
	mat_block_white_concrete,
	mat_block_orange_concrete,
	mat_block_magenta_concrete,
	mat_block_light_blue_concrete,
	mat_block_yellow_concrete,
	mat_block_lime_concrete,
	mat_block_pink_concrete,
	mat_block_gray_concrete,
	mat_block_light_gray_concrete,
	mat_block_cyan_concrete,
	mat_block_purple_concrete,
	mat_block_blue_concrete,
	mat_block_brown_concrete,
	mat_block_green_concrete,
	mat_block_red_concrete,
	mat_block_black_concrete,
	mat_block_white_concrete_powder,
	mat_block_orange_concrete_powder,
	mat_block_magenta_concrete_powder,
	mat_block_light_blue_concrete_powder,
	mat_block_yellow_concrete_powder,
	mat_block_lime_concrete_powder,
	mat_block_pink_concrete_powder,
	mat_block_gray_concrete_powder,
	mat_block_light_gray_concrete_powder,
	mat_block_cyan_concrete_powder,
	mat_block_purple_concrete_powder,
	mat_block_blue_concrete_powder,
	mat_block_brown_concrete_powder,
	mat_block_green_concrete_powder,
	mat_block_red_concrete_powder,
	mat_block_black_concrete_powder,
	mat_block_kelp,
	mat_block_kelp_plant,
	mat_block_dried_kelp_block,
	mat_block_turtle_egg,
	mat_block_dead_tube_coral_block,
	mat_block_dead_brain_coral_block,
	mat_block_dead_bubble_coral_block,
	mat_block_dead_fire_coral_block,
	mat_block_dead_horn_coral_block,
	mat_block_tube_coral_block,
	mat_block_brain_coral_block,
	mat_block_bubble_coral_block,
	mat_block_fire_coral_block,
	mat_block_horn_coral_block,
	mat_block_dead_tube_coral,
	mat_block_dead_brain_coral,
	mat_block_dead_bubble_coral,
	mat_block_dead_fire_coral,
	mat_block_dead_horn_coral,
	mat_block_tube_coral,
	mat_block_brain_coral,
	mat_block_bubble_coral,
	mat_block_fire_coral,
	mat_block_horn_coral,
	mat_block_dead_tube_coral_fan,
	mat_block_dead_brain_coral_fan,
	mat_block_dead_bubble_coral_fan,
	mat_block_dead_fire_coral_fan,
	mat_block_dead_horn_coral_fan,
	mat_block_tube_coral_fan,
	mat_block_brain_coral_fan,
	mat_block_bubble_coral_fan,
	mat_block_fire_coral_fan,
	mat_block_horn_coral_fan,
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
	mat_block_sea_pickle,
	mat_block_blue_ice,
	mat_block_conduit,
	mat_block_bamboo_sapling,
	mat_block_bamboo,
	mat_block_potted_bamboo,
	mat_block_void_air,
	mat_block_cave_air,
	mat_block_bubble_column,
	mat_block_polished_granite_stairs,
	mat_block_smooth_red_sandstone_stairs,
	mat_block_mossy_stone_brick_stairs,
	mat_block_polished_diorite_stairs,
	mat_block_mossy_cobblestone_stairs,
	mat_block_end_stone_brick_stairs,
	mat_block_stone_stairs,
	mat_block_smooth_sandstone_stairs,
	mat_block_smooth_quartz_stairs,
	mat_block_granite_stairs,
	mat_block_andesite_stairs,
	mat_block_red_nether_brick_stairs,
	mat_block_polished_andesite_stairs,
	mat_block_diorite_stairs,
	mat_block_polished_granite_slab,
	mat_block_smooth_red_sandstone_slab,
	mat_block_mossy_stone_brick_slab,
	mat_block_polished_diorite_slab,
	mat_block_mossy_cobblestone_slab,
	mat_block_end_stone_brick_slab,
	mat_block_smooth_sandstone_slab,
	mat_block_smooth_quartz_slab,
	mat_block_granite_slab,
	mat_block_andesite_slab,
	mat_block_red_nether_brick_slab,
	mat_block_polished_andesite_slab,
	mat_block_diorite_slab,
	mat_block_brick_wall,
	mat_block_prismarine_wall,
	mat_block_red_sandstone_wall,
	mat_block_mossy_stone_brick_wall,
	mat_block_granite_wall,
	mat_block_stone_brick_wall,
	mat_block_nether_brick_wall,
	mat_block_andesite_wall,
	mat_block_red_nether_brick_wall,
	mat_block_sandstone_wall,
	mat_block_end_stone_brick_wall,
	mat_block_diorite_wall,
	mat_block_scaffolding,
	mat_block_loom,
	mat_block_barrel,
	mat_block_smoker,
	mat_block_blast_furnace,
	mat_block_cartography_table,
	mat_block_fletching_table,
	mat_block_grindstone,
	mat_block_lectern,
	mat_block_smithing_table,
	mat_block_stonecutter,
	mat_block_bell,
	mat_block_lantern,
	mat_block_soul_lantern,
	mat_block_campfire,
	mat_block_soul_campfire,
	mat_block_sweet_berry_bush,
	mat_block_warped_stem,
	mat_block_stripped_warped_stem,
	mat_block_warped_hyphae,
	mat_block_stripped_warped_hyphae,
	mat_block_warped_nylium,
	mat_block_warped_fungus,
	mat_block_warped_wart_block,
	mat_block_warped_roots,
	mat_block_nether_sprouts,
	mat_block_crimson_stem,
	mat_block_stripped_crimson_stem,
	mat_block_crimson_hyphae,
	mat_block_stripped_crimson_hyphae,
	mat_block_crimson_nylium,
	mat_block_crimson_fungus,
	mat_block_shroomlight,
	mat_block_weeping_vines,
	mat_block_weeping_vines_plant,
	mat_block_twisting_vines,
	mat_block_twisting_vines_plant,
	mat_block_crimson_roots,
	mat_block_crimson_planks,
	mat_block_warped_planks,
	mat_block_crimson_slab,
	mat_block_warped_slab,
	mat_block_crimson_pressure_plate,
	mat_block_warped_pressure_plate,
	mat_block_crimson_fence,
	mat_block_warped_fence,
	mat_block_crimson_trapdoor,
	mat_block_warped_trapdoor,
	mat_block_crimson_fence_gate,
	mat_block_warped_fence_gate,
	mat_block_crimson_stairs,
	mat_block_warped_stairs,
	mat_block_crimson_button,
	mat_block_warped_button,
	mat_block_crimson_door,
	mat_block_warped_door,
	mat_block_crimson_sign,
	mat_block_warped_sign,
	mat_block_crimson_wall_sign,
	mat_block_warped_wall_sign,
	mat_block_structure_block,
	mat_block_jigsaw,
	mat_block_composter,
	mat_block_target,
	mat_block_bee_nest,
	mat_block_beehive,
	mat_block_honey_block,
	mat_block_honeycomb_block,
	mat_block_netherite_block,
	mat_block_ancient_debris,
	mat_block_crying_obsidian,
	mat_block_respawn_anchor,
	mat_block_potted_crimson_fungus,
	mat_block_potted_warped_fungus,
	mat_block_potted_crimson_roots,
	mat_block_potted_warped_roots,
	mat_block_lodestone,
	mat_block_blackstone,
	mat_block_blackstone_stairs,
	mat_block_blackstone_wall,
	mat_block_blackstone_slab,
	mat_block_polished_blackstone,
	mat_block_polished_blackstone_bricks,
	mat_block_cracked_polished_blackstone_bricks,
	mat_block_chiseled_polished_blackstone,
	mat_block_polished_blackstone_brick_slab,
	mat_block_polished_blackstone_brick_stairs,
	mat_block_polished_blackstone_brick_wall,
	mat_block_gilded_blackstone,
	mat_block_polished_blackstone_stairs,
	mat_block_polished_blackstone_slab,
	mat_block_polished_blackstone_pressure_plate,
	mat_block_polished_blackstone_button,
	mat_block_polished_blackstone_wall,
	mat_block_chiseled_nether_bricks,
	mat_block_cracked_nether_bricks,
	mat_block_quartz_bricks,
	mat_block_candle,
	mat_block_white_candle,
	mat_block_orange_candle,
	mat_block_magenta_candle,
	mat_block_light_blue_candle,
	mat_block_yellow_candle,
	mat_block_lime_candle,
	mat_block_pink_candle,
	mat_block_gray_candle,
	mat_block_light_gray_candle,
	mat_block_cyan_candle,
	mat_block_purple_candle,
	mat_block_blue_candle,
	mat_block_brown_candle,
	mat_block_green_candle,
	mat_block_red_candle,
	mat_block_black_candle,
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
	mat_block_amethyst_block,
	mat_block_budding_amethyst,
	mat_block_amethyst_cluster,
	mat_block_large_amethyst_bud,
	mat_block_medium_amethyst_bud,
	mat_block_small_amethyst_bud,
	mat_block_tuff,
	mat_block_calcite,
	mat_block_tinted_glass,
	mat_block_powder_snow,
	mat_block_sculk_sensor,
	mat_block_oxidized_copper,
	mat_block_weathered_copper,
	mat_block_exposed_copper,
	mat_block_copper_block,
	mat_block_copper_ore,
	mat_block_deepslate_copper_ore,
	mat_block_oxidized_cut_copper,
	mat_block_weathered_cut_copper,
	mat_block_exposed_cut_copper,
	mat_block_cut_copper,
	mat_block_oxidized_cut_copper_stairs,
	mat_block_weathered_cut_copper_stairs,
	mat_block_exposed_cut_copper_stairs,
	mat_block_cut_copper_stairs,
	mat_block_oxidized_cut_copper_slab,
	mat_block_weathered_cut_copper_slab,
	mat_block_exposed_cut_copper_slab,
	mat_block_cut_copper_slab,
	mat_block_waxed_copper_block,
	mat_block_waxed_weathered_copper,
	mat_block_waxed_exposed_copper,
	mat_block_waxed_oxidized_copper,
	mat_block_waxed_oxidized_cut_copper,
	mat_block_waxed_weathered_cut_copper,
	mat_block_waxed_exposed_cut_copper,
	mat_block_waxed_cut_copper,
	mat_block_waxed_oxidized_cut_copper_stairs,
	mat_block_waxed_weathered_cut_copper_stairs,
	mat_block_waxed_exposed_cut_copper_stairs,
	mat_block_waxed_cut_copper_stairs,
	mat_block_waxed_oxidized_cut_copper_slab,
	mat_block_waxed_weathered_cut_copper_slab,
	mat_block_waxed_exposed_cut_copper_slab,
	mat_block_waxed_cut_copper_slab,
	mat_block_lightning_rod,
	mat_block_pointed_dripstone,
	mat_block_dripstone_block,
	mat_block_cave_vines,
	mat_block_cave_vines_plant,
	mat_block_spore_blossom,
	mat_block_azalea,
	mat_block_flowering_azalea,
	mat_block_moss_carpet,
	mat_block_moss_block,
	mat_block_big_dripleaf,
	mat_block_big_dripleaf_stem,
	mat_block_small_dripleaf,
	mat_block_hanging_roots,
	mat_block_rooted_dirt,
	mat_block_deepslate,
	mat_block_cobbled_deepslate,
	mat_block_cobbled_deepslate_stairs,
	mat_block_cobbled_deepslate_slab,
	mat_block_cobbled_deepslate_wall,
	mat_block_polished_deepslate,
	mat_block_polished_deepslate_stairs,
	mat_block_polished_deepslate_slab,
	mat_block_polished_deepslate_wall,
	mat_block_deepslate_tiles,
	mat_block_deepslate_tile_stairs,
	mat_block_deepslate_tile_slab,
	mat_block_deepslate_tile_wall,
	mat_block_deepslate_bricks,
	mat_block_deepslate_brick_stairs,
	mat_block_deepslate_brick_slab,
	mat_block_deepslate_brick_wall,
	mat_block_chiseled_deepslate,
	mat_block_cracked_deepslate_bricks,
	mat_block_cracked_deepslate_tiles,
	mat_block_infested_deepslate,
	mat_block_smooth_basalt,
	mat_block_raw_iron_block,
	mat_block_raw_copper_block,
	mat_block_raw_gold_block,
	mat_block_potted_azalea_bush,
	mat_block_potted_flowering_azalea_bush,

	mat_block_count

} mat_block_type_t;

typedef enum {

	mat_fluid_empty,
	mat_fluid_water,
	mat_fluid_flowing_water,
	mat_fluid_lava,
	mat_fluid_flowing_lava,

	mat_fluid_count

} mat_fluid_type_t;

typedef uint16_t mat_block_protocol_id_t;

typedef struct {

	float32_t resistance;
		// blast resistance

	float32_t hardness;
		// hardness value for calculating break times

	uint8_t luminance : 4;

	mat_block_entity_type_t entity : 5;

	uint8_t encouragement : 6;
	uint8_t flammability : 7;

	// motor: tags that help with certain calculations
	bool catches_fire_from_lava : 1;
	bool light_filtering : 1;
	bool transparent : 1;
	bool mineable : 1;
	bool needs : 1;
	bool needs_wooden_tool : 1;
	bool air : 1;

	// vanilla tags
	bool mineable_axe : 1;
	bool mineable_hoe : 1;
	bool mineable_pickaxe : 1;
	bool mineable_shovel : 1;
	bool acacia_logs : 1;
	bool anvil : 1;
	bool bamboo_plantable_on : 1;
	bool banners : 1;
	bool base_stone_nether : 1;
	bool base_stone_overworld : 1;
	bool beacon_base_blocks : 1;
	bool beds : 1;
	bool beehives : 1;
	bool bee_growables : 1;
	bool birch_logs : 1;
	bool buttons : 1;
	bool campfires : 1;
	bool candle_cakes : 1;
	bool candles : 1;
	bool carpets : 1;
	bool cauldrons : 1;
	bool cave_vines : 1;
	bool climbable : 1;
	bool coal_ores : 1;
	bool copper_ores : 1;
	bool corals : 1;
	bool coral_blocks : 1;
	bool coral_plants : 1;
	bool crimson_stems : 1;
	bool crops : 1;
	bool crystal_sound_blocks : 1;
	bool dark_oak_logs : 1;
	bool deepslate_ore_replaceables : 1;
	bool diamond_ores : 1;
	bool dirt : 1;
	bool doors : 1;
	bool dragon_immune : 1;
	bool dripstone_replaceable_blocks : 1;
	bool emerald_ores : 1;
	bool enderman_holdable : 1;
	bool features_cannot_replace : 1;
	bool fence_gates : 1;
	bool fences : 1;
	bool fire : 1;
	bool flower_pots : 1;
	bool flowers : 1;
	bool geode_invalid_blocks : 1;
	bool gold_ores : 1;
	bool guarded_by_piglins : 1;
	bool hoglin_repellents : 1;
	bool ice : 1;
	bool impermeable : 1;
	bool infiniburn_end : 1;
	bool infiniburn_nether : 1;
	bool infiniburn_overworld : 1;
	bool inside_step_sound_blocks : 1;
	bool iron_ores : 1;
	bool jungle_logs : 1;
	bool lapis_ores : 1;
	bool lava_pool_stone_replaceables : 1;
	bool leaves : 1;
	bool logs : 1;
	bool logs_that_burn : 1;
	bool lush_ground_replaceable : 1;
	bool moss_replaceable : 1;
	bool mushroom_grow_block : 1;
	bool needs_diamond_tool : 1;
	bool needs_iron_tool : 1;
	bool needs_stone_tool : 1;
	bool non_flammable_wood : 1;
	bool nylium : 1;
	bool oak_logs : 1;
	bool occludes_vibration_signals : 1;
	bool piglin_repellents : 1;
	bool planks : 1;
	bool portals : 1;
	bool pressure_plates : 1;
	bool prevent_mob_spawning_inside : 1;
	bool rails : 1;
	bool redstone_ores : 1;
	bool sand : 1;
	bool saplings : 1;
	bool shulker_boxes : 1;
	bool signs : 1;
	bool slabs : 1;
	bool small_dripleaf_placeable : 1;
	bool small_flowers : 1;
	bool snow : 1;
	bool soul_fire_base_blocks : 1;
	bool soul_speed_blocks : 1;
	bool spruce_logs : 1;
	bool stairs : 1;
	bool standing_signs : 1;
	bool stone_bricks : 1;
	bool stone_ore_replaceables : 1;
	bool stone_pressure_plates : 1;
	bool strider_warm_blocks : 1;
	bool tall_flowers : 1;
	bool trapdoors : 1;
	bool underwater_bonemeals : 1;
	bool unstable_bottom_center : 1;
	bool valid_spawn : 1;
	bool walls : 1;
	bool wall_corals : 1;
	bool wall_post_override : 1;
	bool wall_signs : 1;
	bool warped_stems : 1;
	bool wart_blocks : 1;
	bool wither_immune : 1;
	bool wither_summon_base_blocks : 1;
	bool wooden_buttons : 1;
	bool wooden_doors : 1;
	bool wooden_fences : 1;
	bool wooden_pressure_plates : 1;
	bool wooden_slabs : 1;
	bool wooden_stairs : 1;
	bool wooden_trapdoors : 1;
	bool wool : 1;
	bool animals_spawnable_on : 1;
	bool axolotls_spawnable_on : 1;
	bool azalea_grows_on : 1;
	bool azalea_root_replaceable : 1;
	bool big_dripleaf_placeable : 1;
	bool foxes_spawnable_on : 1;
	bool goats_spawnable_on : 1;
	bool mooshrooms_spawnable_on : 1;
	bool parrots_spawnable_on : 1;
	bool polar_bears_spawnable_on_in_frozen_ocean : 1;
	bool rabbits_spawnable_on : 1;
	bool replaceable_plants : 1;
	bool terracotta : 1;
	bool wolves_spawnable_on : 1;

	bool water : 1;
	bool lava : 1;

	uint8_t modifiers_count : 3;
	mat_state_modifier_type_t modifiers[];

} mat_block_t;

extern const mat_block_t* mat_blocks[];
extern const uint16_t mat_blocks_protocol[];
extern const mat_block_protocol_id_t mat_blocks_base_protocol[];
extern const mat_block_protocol_id_t mat_blocks_default_protocol[];

static inline const mat_block_t* mat_get_block_by_type(mat_block_type_t id) {
	return mat_blocks[id];
}

static inline mat_block_type_t mat_get_block_type_by_protocol_id(mat_block_protocol_id_t protocol) {
	return mat_blocks_protocol[protocol];
}

static inline mat_block_protocol_id_t mat_get_block_base_protocol_id_by_type(mat_block_type_t type) {
	return mat_blocks_base_protocol[type];
}

static inline mat_block_protocol_id_t mat_get_block_default_protocol_id_by_type(mat_block_type_t type) {
	return mat_blocks_default_protocol[type];
}

/*
Read the value of a state field of a block with certain protocol
*/
static inline uint8_t mat_get_block_state_value(mat_block_protocol_id_t block_protocol, mat_state_modifier_type_t field) {

	mat_block_type_t block_id = mat_get_block_type_by_protocol_id(block_protocol);
	mat_block_protocol_id_t block_state = block_protocol - mat_get_block_base_protocol_id_by_type(block_id);
	const mat_block_t* block_data = mat_get_block_by_type(block_id);

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

	mat_block_type_t block_id = mat_get_block_type_by_protocol_id(block_protocol);
	mat_block_protocol_id_t block_state = block_protocol - mat_get_block_base_protocol_id_by_type(block_id);
	int32_t state_add = 1;
	const mat_block_t* block_data = mat_get_block_by_type(block_id);

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