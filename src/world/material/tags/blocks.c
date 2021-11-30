#include "tags.h"
#include "../blocks.h"
#include "../../../util/str_util.h"

const mat_tag_t mat_block_tag_catches_fire_from_lava_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("motor:catches_fire_from_lava"),
	mat_block_acacia_door,
	mat_block_acacia_fence,
	mat_block_acacia_fence_gate,
	mat_block_acacia_leaves,
	mat_block_acacia_log,
	mat_block_acacia_planks,
	mat_block_acacia_pressure_plate,
	mat_block_acacia_sign,
	mat_block_acacia_slab,
	mat_block_acacia_stairs,
	mat_block_acacia_trapdoor,
	mat_block_acacia_wood,
	mat_block_azalea_leaves,
	mat_block_bamboo,
	mat_block_bamboo_sapling,
	mat_block_barrel,
	mat_block_beehive,
	mat_block_bee_nest,
	mat_block_birch_door,
	mat_block_birch_fence,
	mat_block_birch_fence_gate,
	mat_block_birch_leaves,
	mat_block_birch_log,
	mat_block_birch_planks,
	mat_block_birch_pressure_plate,
	mat_block_birch_sign,
	mat_block_birch_slab,
	mat_block_birch_stairs,
	mat_block_birch_trapdoor,
	mat_block_birch_wood,
	mat_block_black_banner,
	mat_block_black_bed,
	mat_block_black_carpet,
	mat_block_black_wool,
	mat_block_blue_banner,
	mat_block_blue_bed,
	mat_block_blue_carpet,
	mat_block_blue_wool,
	mat_block_bookshelf,
	mat_block_brown_banner,
	mat_block_brown_bed,
	mat_block_brown_carpet,
	mat_block_brown_mushroom_block,
	mat_block_brown_wool,
	mat_block_campfire,
	mat_block_cartography_table,
	mat_block_chest,
	mat_block_composter,
	mat_block_crafting_table,
	mat_block_crimson_roots,
	mat_block_cyan_banner,
	mat_block_cyan_bed,
	mat_block_cyan_carpet,
	mat_block_cyan_wool,
	mat_block_dark_oak_door,
	mat_block_dark_oak_fence,
	mat_block_dark_oak_fence_gate,
	mat_block_dark_oak_leaves,
	mat_block_dark_oak_log,
	mat_block_dark_oak_planks,
	mat_block_dark_oak_pressure_plate,
	mat_block_dark_oak_sign,
	mat_block_dark_oak_slab,
	mat_block_dark_oak_stairs,
	mat_block_dark_oak_trapdoor,
	mat_block_dark_oak_wood,
	mat_block_daylight_detector,
	mat_block_dead_bush,
	mat_block_fletching_table,
	mat_block_flowering_azalea_leaves,
	mat_block_grass,
	mat_block_gray_banner,
	mat_block_gray_bed,
	mat_block_gray_carpet,
	mat_block_gray_wool,
	mat_block_green_banner,
	mat_block_green_bed,
	mat_block_green_carpet,
	mat_block_green_wool,
	mat_block_jukebox,
	mat_block_jungle_door,
	mat_block_jungle_fence,
	mat_block_jungle_fence_gate,
	mat_block_jungle_leaves,
	mat_block_jungle_log,
	mat_block_jungle_planks,
	mat_block_jungle_pressure_plate,
	mat_block_jungle_sign,
	mat_block_jungle_slab,
	mat_block_jungle_stairs,
	mat_block_jungle_trapdoor,
	mat_block_jungle_wood,
	mat_block_lectern,
	mat_block_light_blue_banner,
	mat_block_light_blue_bed,
	mat_block_light_blue_carpet,
	mat_block_light_blue_wool,
	mat_block_light_gray_banner,
	mat_block_light_gray_bed,
	mat_block_light_gray_carpet,
	mat_block_light_gray_wool,
	mat_block_lilac,
	mat_block_lime_banner,
	mat_block_lime_bed,
	mat_block_lime_carpet,
	mat_block_lime_wool,
	mat_block_loom,
	mat_block_magenta_banner,
	mat_block_magenta_bed,
	mat_block_magenta_carpet,
	mat_block_magenta_wool,
	mat_block_mushroom_stem,
	mat_block_nether_sprouts,
	mat_block_note_block,
	mat_block_oak_door,
	mat_block_oak_fence,
	mat_block_oak_fence_gate,
	mat_block_oak_leaves,
	mat_block_oak_log,
	mat_block_oak_planks,
	mat_block_oak_pressure_plate,
	mat_block_oak_sign,
	mat_block_oak_slab,
	mat_block_oak_stairs,
	mat_block_oak_trapdoor,
	mat_block_oak_wood,
	mat_block_orange_banner,
	mat_block_orange_bed,
	mat_block_orange_carpet,
	mat_block_orange_wool,
	mat_block_peony,
	mat_block_pink_banner,
	mat_block_pink_bed,
	mat_block_pink_carpet,
	mat_block_pink_wool,
	mat_block_purple_banner,
	mat_block_purple_bed,
	mat_block_purple_carpet,
	mat_block_purple_wool,
	mat_block_red_banner,
	mat_block_red_bed,
	mat_block_red_carpet,
	mat_block_red_mushroom_block,
	mat_block_red_wool,
	mat_block_rose_bush,
	mat_block_scaffolding,
	mat_block_smithing_table,
	mat_block_soul_campfire,
	mat_block_spruce_door,
	mat_block_spruce_fence,
	mat_block_spruce_fence_gate,
	mat_block_spruce_leaves,
	mat_block_spruce_log,
	mat_block_spruce_planks,
	mat_block_spruce_pressure_plate,
	mat_block_spruce_sign,
	mat_block_spruce_slab,
	mat_block_spruce_stairs,
	mat_block_spruce_trapdoor,
	mat_block_spruce_wood,
	mat_block_stripped_acacia_log,
	mat_block_stripped_acacia_wood,
	mat_block_stripped_birch_log,
	mat_block_stripped_birch_wood,
	mat_block_stripped_dark_oak_log,
	mat_block_stripped_dark_oak_wood,
	mat_block_stripped_jungle_log,
	mat_block_stripped_jungle_wood,
	mat_block_stripped_oak_log,
	mat_block_stripped_oak_wood,
	mat_block_stripped_spruce_log,
	mat_block_stripped_spruce_wood,
	mat_block_sunflower,
	mat_block_tall_grass,
	mat_block_tnt,
	mat_block_trapped_chest,
	mat_block_vine,
	mat_block_warped_roots,
	mat_block_white_banner,
	mat_block_white_bed,
	mat_block_white_carpet,
	mat_block_white_wool,
	mat_block_yellow_banner,
	mat_block_yellow_bed,
	mat_block_yellow_carpet,
	mat_block_yellow_wool,
);
const mat_tag_t mat_block_tag_light_filtering_d = MAT_TAG_INITIALIZER(
UTL_CSTRTOSTR("motor:light_filtering"),
	mat_block_acacia_leaves,
	mat_block_azalea_leaves,
	mat_block_beacon,
	mat_block_birch_leaves,
	mat_block_black_shulker_box,
	mat_block_blue_shulker_box,
	mat_block_brown_shulker_box,
	mat_block_chorus_flower,
	mat_block_chorus_plant,
	mat_block_cobweb,
	mat_block_cyan_shulker_box,
	mat_block_dark_oak_leaves,
	mat_block_flowering_azalea_leaves,
	mat_block_gray_shulker_box,
	mat_block_green_shulker_box,
	mat_block_honey_block,
	mat_block_ice,
	mat_block_jungle_leaves,
	mat_block_lava,
	mat_block_light_blue_shulker_box,
	mat_block_light_gray_shulker_box,
	mat_block_lime_shulker_box,
	mat_block_magenta_shulker_box,
	mat_block_oak_leaves,
	mat_block_orange_shulker_box,
	mat_block_pink_shulker_box,
	mat_block_purple_shulker_box,
	mat_block_red_shulker_box,
	mat_block_shulker_box,
	mat_block_slime_block,
	mat_block_spruce_leaves,
	mat_block_water,
	mat_block_white_shulker_box,
	mat_block_yellow_shulker_box,
	mat_block_frosted_ice,
	mat_block_end_gateway,
	mat_block_bubble_column,
);
const mat_tag_t mat_block_tag_transparent_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("motor:transparent"),
	mat_block_air,
	mat_block_acacia_button,
	mat_block_acacia_door,
	mat_block_acacia_fence,
	mat_block_acacia_fence_gate,
	mat_block_acacia_leaves,
	mat_block_acacia_pressure_plate,
	mat_block_acacia_sapling,
	mat_block_acacia_sign,
	mat_block_acacia_slab,
	mat_block_acacia_stairs,
	mat_block_acacia_trapdoor,
	mat_block_activator_rail,
	mat_block_allium,
	mat_block_amethyst_cluster,
	mat_block_andesite_slab,
	mat_block_andesite_stairs,
	mat_block_andesite_wall,
	mat_block_anvil,
	mat_block_azalea_leaves,
	mat_block_azure_bluet,
	mat_block_bamboo,
	mat_block_bamboo_sapling,
	mat_block_beetroots,
	mat_block_barrier,
	mat_block_beacon,
	mat_block_bell,
	mat_block_big_dripleaf,
	mat_block_birch_button,
	mat_block_birch_door,
	mat_block_birch_fence,
	mat_block_birch_fence_gate,
	mat_block_birch_leaves,
	mat_block_birch_pressure_plate,
	mat_block_birch_sapling,
	mat_block_birch_sign,
	mat_block_birch_slab,
	mat_block_birch_stairs,
	mat_block_birch_trapdoor,
	mat_block_black_banner,
	mat_block_black_bed,
	mat_block_black_candle,
	mat_block_black_carpet,
	mat_block_black_shulker_box,
	mat_block_black_stained_glass,
	mat_block_black_stained_glass_pane,
	mat_block_blackstone_slab,
	mat_block_blackstone_stairs,
	mat_block_blackstone_wall,
	mat_block_blue_banner,
	mat_block_blue_bed,
	mat_block_blue_candle,
	mat_block_blue_carpet,
	mat_block_blue_orchid,
	mat_block_blue_shulker_box,
	mat_block_blue_stained_glass,
	mat_block_blue_stained_glass_pane,
	mat_block_brain_coral,
	mat_block_brain_coral_fan,
	mat_block_brewing_stand,
	mat_block_brick_slab,
	mat_block_brick_stairs,
	mat_block_brick_wall,
	mat_block_brown_banner,
	mat_block_brown_bed,
	mat_block_brown_candle,
	mat_block_brown_carpet,
	mat_block_brown_mushroom,
	mat_block_brown_shulker_box,
	mat_block_brown_stained_glass,
	mat_block_brown_stained_glass_pane,
	mat_block_bubble_coral,
	mat_block_bubble_coral_fan,
	mat_block_cactus,
	mat_block_cake,
	mat_block_campfire,
	mat_block_candle,
	mat_block_carrots,
	mat_block_cauldron,
	mat_block_cave_vines,
	mat_block_chain,
	mat_block_chest,
	mat_block_chipped_anvil,
	mat_block_chorus_flower,
	mat_block_chorus_plant,
	mat_block_cobbled_deepslate_slab,
	mat_block_cobbled_deepslate_stairs,
	mat_block_cobbled_deepslate_wall,
	mat_block_cobblestone_slab,
	mat_block_cobblestone_stairs,
	mat_block_cobblestone_wall,
	mat_block_cobweb,
	mat_block_cocoa,
	mat_block_composter,
	mat_block_conduit,
	mat_block_cornflower,
	mat_block_creeper_head,
	mat_block_crimson_button,
	mat_block_crimson_door,
	mat_block_crimson_fence,
	mat_block_crimson_fence_gate,
	mat_block_crimson_fungus,
	mat_block_crimson_pressure_plate,
	mat_block_crimson_roots,
	mat_block_crimson_sign,
	mat_block_crimson_slab,
	mat_block_crimson_stairs,
	mat_block_crimson_trapdoor,
	mat_block_cut_copper_slab,
	mat_block_cut_copper_stairs,
	mat_block_cut_red_sandstone_slab,
	mat_block_cut_sandstone_slab,
	mat_block_cyan_banner,
	mat_block_cyan_bed,
	mat_block_cyan_candle,
	mat_block_cyan_carpet,
	mat_block_cyan_shulker_box,
	mat_block_cyan_stained_glass,
	mat_block_cyan_stained_glass_pane,
	mat_block_damaged_anvil,
	mat_block_dandelion,
	mat_block_dark_oak_button,
	mat_block_dark_oak_door,
	mat_block_dark_oak_fence,
	mat_block_dark_oak_fence_gate,
	mat_block_dark_oak_leaves,
	mat_block_dark_oak_pressure_plate,
	mat_block_dark_oak_sapling,
	mat_block_dark_oak_sign,
	mat_block_dark_oak_slab,
	mat_block_dark_oak_stairs,
	mat_block_dark_oak_trapdoor,
	mat_block_dark_prismarine_slab,
	mat_block_dark_prismarine_stairs,
	mat_block_daylight_detector,
	mat_block_dead_brain_coral,
	mat_block_dead_brain_coral_fan,
	mat_block_dead_bubble_coral,
	mat_block_dead_bubble_coral_fan,
	mat_block_dead_bush,
	mat_block_dead_fire_coral,
	mat_block_dead_fire_coral_fan,
	mat_block_dead_horn_coral,
	mat_block_dead_horn_coral_fan,
	mat_block_dead_tube_coral,
	mat_block_dead_tube_coral_fan,
	mat_block_deepslate_brick_slab,
	mat_block_deepslate_brick_stairs,
	mat_block_deepslate_brick_wall,
	mat_block_deepslate_tile_slab,
	mat_block_deepslate_tile_stairs,
	mat_block_deepslate_tile_wall,
	mat_block_detector_rail,
	mat_block_diorite_slab,
	mat_block_diorite_stairs,
	mat_block_diorite_wall,
	mat_block_dragon_egg,
	mat_block_dragon_head,
	mat_block_enchanting_table,
	mat_block_end_portal_frame,
	mat_block_end_rod,
	mat_block_end_stone_brick_slab,
	mat_block_end_stone_brick_stairs,
	mat_block_end_stone_brick_wall,
	mat_block_ender_chest,
	mat_block_exposed_cut_copper_slab,
	mat_block_exposed_cut_copper_stairs,
	mat_block_farmland,
	mat_block_fern,
	mat_block_fire,
	mat_block_fire_coral,
	mat_block_fire_coral_fan,
	mat_block_flower_pot,
	mat_block_flowering_azalea_leaves,
	mat_block_glass,
	mat_block_glass_pane,
	mat_block_glow_lichen,
	mat_block_glowstone,
	mat_block_granite_slab,
	mat_block_granite_stairs,
	mat_block_granite_wall,
	mat_block_grass,
	mat_block_grass_block,
	mat_block_gray_banner,
	mat_block_gray_bed,
	mat_block_gray_candle,
	mat_block_gray_carpet,
	mat_block_gray_shulker_box,
	mat_block_gray_stained_glass,
	mat_block_gray_stained_glass_pane,
	mat_block_green_banner,
	mat_block_green_bed,
	mat_block_green_candle,
	mat_block_green_carpet,
	mat_block_green_shulker_box,
	mat_block_green_stained_glass,
	mat_block_green_stained_glass_pane,
	mat_block_grindstone,
	mat_block_hanging_roots,
	mat_block_heavy_weighted_pressure_plate,
	mat_block_honey_block,
	mat_block_hopper,
	mat_block_horn_coral,
	mat_block_horn_coral_fan,
	mat_block_ice,
	mat_block_iron_bars,
	mat_block_iron_door,
	mat_block_iron_trapdoor,
	mat_block_jack_o_lantern,
	mat_block_jungle_button,
	mat_block_jungle_door,
	mat_block_jungle_fence,
	mat_block_jungle_fence_gate,
	mat_block_jungle_leaves,
	mat_block_jungle_pressure_plate,
	mat_block_jungle_sapling,
	mat_block_jungle_sign,
	mat_block_jungle_slab,
	mat_block_jungle_stairs,
	mat_block_jungle_trapdoor,
	mat_block_kelp_plant,
	mat_block_ladder,
	mat_block_lantern,
	mat_block_large_fern,
	mat_block_lectern,
	mat_block_lever,
	mat_block_light,
	mat_block_light_blue_banner,
	mat_block_light_blue_bed,
	mat_block_light_blue_candle,
	mat_block_light_blue_carpet,
	mat_block_light_blue_shulker_box,
	mat_block_light_blue_stained_glass,
	mat_block_light_blue_stained_glass_pane,
	mat_block_light_gray_banner,
	mat_block_light_gray_bed,
	mat_block_light_gray_candle,
	mat_block_light_gray_carpet,
	mat_block_light_gray_shulker_box,
	mat_block_light_gray_stained_glass,
	mat_block_light_gray_stained_glass_pane,
	mat_block_light_weighted_pressure_plate,
	mat_block_lightning_rod,
	mat_block_lilac,
	mat_block_lily_of_the_valley,
	mat_block_lily_pad,
	mat_block_lime_banner,
	mat_block_lime_bed,
	mat_block_lime_candle,
	mat_block_lime_carpet,
	mat_block_lime_shulker_box,
	mat_block_lime_stained_glass,
	mat_block_lime_stained_glass_pane,
	mat_block_magenta_banner,
	mat_block_magenta_bed,
	mat_block_magenta_candle,
	mat_block_magenta_carpet,
	mat_block_magenta_shulker_box,
	mat_block_magenta_stained_glass,
	mat_block_magenta_stained_glass_pane,
	mat_block_melon_stem,
	mat_block_moss_carpet,
	mat_block_mossy_cobblestone_slab,
	mat_block_mossy_cobblestone_stairs,
	mat_block_mossy_cobblestone_wall,
	mat_block_mossy_stone_brick_slab,
	mat_block_mossy_stone_brick_stairs,
	mat_block_mossy_stone_brick_wall,
	mat_block_nether_brick_fence,
	mat_block_nether_brick_slab,
	mat_block_nether_brick_stairs,
	mat_block_nether_brick_wall,
	mat_block_nether_sprouts,
	mat_block_nether_wart,
	mat_block_oak_button,
	mat_block_oak_door,
	mat_block_oak_fence,
	mat_block_oak_fence_gate,
	mat_block_oak_leaves,
	mat_block_oak_pressure_plate,
	mat_block_oak_sapling,
	mat_block_oak_sign,
	mat_block_oak_slab,
	mat_block_oak_stairs,
	mat_block_oak_trapdoor,
	mat_block_orange_banner,
	mat_block_orange_bed,
	mat_block_orange_candle,
	mat_block_orange_carpet,
	mat_block_orange_shulker_box,
	mat_block_orange_stained_glass,
	mat_block_orange_stained_glass_pane,
	mat_block_orange_tulip,
	mat_block_oxeye_daisy,
	mat_block_oxidized_cut_copper_slab,
	mat_block_oxidized_cut_copper_stairs,
	mat_block_peony,
	mat_block_petrified_oak_slab,
	mat_block_pink_banner,
	mat_block_pink_bed,
	mat_block_pink_candle,
	mat_block_pink_carpet,
	mat_block_pink_shulker_box,
	mat_block_pink_stained_glass,
	mat_block_pink_stained_glass_pane,
	mat_block_pink_tulip,
	mat_block_player_head,
	mat_block_pointed_dripstone,
	mat_block_polished_andesite_slab,
	mat_block_polished_andesite_stairs,
	mat_block_polished_blackstone_brick_slab,
	mat_block_polished_blackstone_brick_stairs,
	mat_block_polished_blackstone_brick_wall,
	mat_block_polished_blackstone_button,
	mat_block_polished_blackstone_pressure_plate,
	mat_block_polished_blackstone_slab,
	mat_block_polished_blackstone_stairs,
	mat_block_polished_blackstone_wall,
	mat_block_polished_diorite_slab,
	mat_block_polished_diorite_stairs,
	mat_block_polished_granite_slab,
	mat_block_polished_granite_stairs,
	mat_block_polished_deepslate_slab,
	mat_block_polished_deepslate_stairs,
	mat_block_polished_deepslate_wall,
	mat_block_poppy,
	mat_block_potatoes,
	mat_block_powder_snow,
	mat_block_powered_rail,
	mat_block_prismarine_brick_slab,
	mat_block_prismarine_brick_stairs,
	mat_block_prismarine_slab,
	mat_block_prismarine_stairs,
	mat_block_prismarine_wall,
	mat_block_pumpkin_stem,
	mat_block_purple_banner,
	mat_block_purple_bed,
	mat_block_purple_candle,
	mat_block_purple_carpet,
	mat_block_purple_shulker_box,
	mat_block_purple_stained_glass,
	mat_block_purple_stained_glass_pane,
	mat_block_purpur_slab,
	mat_block_purpur_stairs,
	mat_block_quartz_slab,
	mat_block_quartz_stairs,
	mat_block_rail,
	mat_block_red_banner,
	mat_block_red_bed,
	mat_block_red_candle,
	mat_block_red_carpet,
	mat_block_red_mushroom,
	mat_block_red_nether_brick_slab,
	mat_block_red_nether_brick_stairs,
	mat_block_red_nether_brick_wall,
	mat_block_red_sandstone_slab,
	mat_block_red_sandstone_stairs,
	mat_block_red_sandstone_wall,
	mat_block_red_shulker_box,
	mat_block_red_stained_glass,
	mat_block_red_stained_glass_pane,
	mat_block_red_tulip,
	mat_block_comparator,
	mat_block_repeater,
	mat_block_redstone_torch,
	mat_block_redstone_wire,
	mat_block_rose_bush,
	mat_block_sandstone_slab,
	mat_block_sandstone_stairs,
	mat_block_sandstone_wall,
	mat_block_scaffolding,
	mat_block_sculk_sensor,
	mat_block_sea_lantern,
	mat_block_sea_pickle,
	mat_block_shulker_box,
	mat_block_skeleton_skull,
	mat_block_small_dripleaf,
	mat_block_smooth_quartz_slab,
	mat_block_smooth_quartz_stairs,
	mat_block_smooth_red_sandstone_slab,
	mat_block_smooth_red_sandstone_stairs,
	mat_block_smooth_sandstone_slab,
	mat_block_smooth_sandstone_stairs,
	mat_block_smooth_stone_slab,
	mat_block_snow,
	mat_block_soul_campfire,
	mat_block_soul_fire,
	mat_block_soul_lantern,
	mat_block_soul_torch,
	mat_block_spawner,
	mat_block_spore_blossom,
	mat_block_spruce_button,
	mat_block_spruce_door,
	mat_block_spruce_fence,
	mat_block_spruce_fence_gate,
	mat_block_spruce_leaves,
	mat_block_spruce_pressure_plate,
	mat_block_spruce_sapling,
	mat_block_spruce_sign,
	mat_block_spruce_slab,
	mat_block_spruce_stairs,
	mat_block_spruce_trapdoor,
	mat_block_stone_brick_slab,
	mat_block_stone_brick_stairs,
	mat_block_stone_brick_wall,
	mat_block_stone_button,
	mat_block_stone_pressure_plate,
	mat_block_stone_slab,
	mat_block_stone_stairs,
	mat_block_stonecutter,
	mat_block_structure_void,
	mat_block_sugar_cane,
	mat_block_sunflower,
	mat_block_sweet_berry_bush,
	mat_block_tall_seagrass,
	mat_block_torch,
	mat_block_trapped_chest,
	mat_block_tripwire,
	mat_block_tripwire_hook,
	mat_block_tube_coral,
	mat_block_tube_coral_fan,
	mat_block_turtle_egg,
	mat_block_twisting_vines,
	mat_block_vine,
	mat_block_warped_button,
	mat_block_warped_door,
	mat_block_warped_fence,
	mat_block_warped_fence_gate,
	mat_block_warped_fungus,
	mat_block_warped_pressure_plate,
	mat_block_warped_roots,
	mat_block_warped_sign,
	mat_block_warped_slab,
	mat_block_warped_stairs,
	mat_block_warped_trapdoor,
	mat_block_water,
	mat_block_waxed_cut_copper_slab,
	mat_block_waxed_cut_copper_stairs,
	mat_block_waxed_exposed_cut_copper_slab,
	mat_block_waxed_exposed_cut_copper_stairs,
	mat_block_waxed_oxidized_cut_copper_slab,
	mat_block_waxed_oxidized_cut_copper_stairs,
	mat_block_waxed_weathered_cut_copper_slab,
	mat_block_waxed_weathered_cut_copper_stairs,
	mat_block_weathered_cut_copper_slab,
	mat_block_weathered_cut_copper_stairs,
	mat_block_weeping_vines,
	mat_block_wheat,
	mat_block_white_banner,
	mat_block_white_bed,
	mat_block_white_candle,
	mat_block_white_carpet,
	mat_block_white_shulker_box,
	mat_block_white_stained_glass,
	mat_block_white_stained_glass_pane,
	mat_block_white_tulip,
	mat_block_wither_rose,
	mat_block_wither_skeleton_skull,
	mat_block_yellow_banner,
	mat_block_yellow_bed,
	mat_block_yellow_candle,
	mat_block_yellow_carpet,
	mat_block_yellow_shulker_box,
	mat_block_yellow_stained_glass,
	mat_block_yellow_stained_glass_pane,
	mat_block_zombie_head,
	mat_block_end_portal,
	mat_block_frosted_ice,
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
);

#define MAT_BLOCK_TAG_ACACIA_LOGS \
	mat_block_acacia_log,\
	mat_block_acacia_wood,\
	mat_block_stripped_acacia_log,\
	mat_block_stripped_acacia_wood

const mat_tag_t mat_block_tag_acacia_logs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:acacia_logs"),
	MAT_BLOCK_TAG_ACACIA_LOGS
);

#define MAT_BLOCK_TAG_ANVIL \
	mat_block_anvil,\
	mat_block_chipped_anvil,\
	mat_block_damaged_anvil

const mat_tag_t mat_block_tag_anvil_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:anvil"),
	MAT_BLOCK_TAG_ANVIL
);

#define MAT_BLOCK_TAG_BANNERS \
	mat_block_white_banner,\
	mat_block_orange_banner,\
	mat_block_magenta_banner,\
	mat_block_light_blue_banner,\
	mat_block_yellow_banner,\
	mat_block_lime_banner,\
	mat_block_pink_banner,\
	mat_block_gray_banner,\
	mat_block_light_gray_banner,\
	mat_block_cyan_banner,\
	mat_block_purple_banner,\
	mat_block_blue_banner,\
	mat_block_brown_banner,\
	mat_block_green_banner,\
	mat_block_red_banner,\
	mat_block_black_banner,\
	mat_block_white_wall_banner,\
	mat_block_orange_wall_banner,\
	mat_block_magenta_wall_banner,\
	mat_block_light_blue_wall_banner,\
	mat_block_yellow_wall_banner,\
	mat_block_lime_wall_banner,\
	mat_block_pink_wall_banner,\
	mat_block_gray_wall_banner,\
	mat_block_light_gray_wall_banner,\
	mat_block_cyan_wall_banner,\
	mat_block_purple_wall_banner,\
	mat_block_blue_wall_banner,\
	mat_block_brown_wall_banner,\
	mat_block_green_wall_banner,\
	mat_block_red_wall_banner,\
	mat_block_black_wall_banner

const mat_tag_t mat_block_tag_banners_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:banners"),
	MAT_BLOCK_TAG_BANNERS
);

#define MAT_BLOCK_TAG_BASE_STONE_NETHER \
	mat_block_netherrack,\
	mat_block_basalt,\
	mat_block_blackstone

const mat_tag_t mat_block_tag_base_stone_nether_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:base_stone_nether"),
	MAT_BLOCK_TAG_BASE_STONE_NETHER
);

#define MAT_BLOCK_TAG_BASE_STONE_OVERWORLD \
	mat_block_stone,\
	mat_block_granite,\
	mat_block_diorite,\
	mat_block_andesite,\
	mat_block_tuff,\
	mat_block_deepslate

const mat_tag_t mat_block_tag_base_stone_overworld_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:base_stone_overworld"),
	MAT_BLOCK_TAG_BASE_STONE_OVERWORLD
);

#define MAT_BLOCK_TAG_BEACON_BASE_BLOCKS \
	mat_block_netherite_block,\
	mat_block_emerald_block,\
	mat_block_diamond_block,\
	mat_block_gold_block,\
	mat_block_iron_block

const mat_tag_t mat_block_tag_beacon_base_blocks_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:beacon_base_blocks"),
	MAT_BLOCK_TAG_BEACON_BASE_BLOCKS
);

#define MAT_BLOCK_TAG_BEDS \
	mat_block_red_bed,\
	mat_block_black_bed,\
	mat_block_blue_bed,\
	mat_block_brown_bed,\
	mat_block_cyan_bed,\
	mat_block_gray_bed,\
	mat_block_green_bed,\
	mat_block_light_blue_bed,\
	mat_block_light_gray_bed,\
	mat_block_lime_bed,\
	mat_block_magenta_bed,\
	mat_block_orange_bed,\
	mat_block_pink_bed,\
	mat_block_purple_bed,\
	mat_block_white_bed,\
	mat_block_yellow_bed

const mat_tag_t mat_block_tag_beds_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:beds"),
	MAT_BLOCK_TAG_BEDS
);

#define MAT_BLOCK_TAG_BEEHIVES \
	mat_block_bee_nest,\
	mat_block_beehive

const mat_tag_t mat_block_tag_beehives_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:beehives"),
	MAT_BLOCK_TAG_BEEHIVES
);

#define MAT_BLOCK_TAG_BIRCH_LOGS \
	mat_block_birch_log,\
	mat_block_birch_wood,\
	mat_block_stripped_birch_log,\
	mat_block_stripped_birch_wood

const mat_tag_t mat_block_tag_birch_logs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:birch_logs"),
	MAT_BLOCK_TAG_BIRCH_LOGS
);

#define MAT_BLOCK_TAG_CAMPFIRES \
	mat_block_campfire,\
	mat_block_soul_campfire

const mat_tag_t mat_block_tag_campfires_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:campfires"),
	MAT_BLOCK_TAG_CAMPFIRES
);

#define MAT_BLOCK_TAG_CANDLES \
	mat_block_candle,\
	mat_block_white_candle,\
	mat_block_orange_candle,\
	mat_block_magenta_candle,\
	mat_block_light_blue_candle,\
	mat_block_yellow_candle,\
	mat_block_lime_candle,\
	mat_block_pink_candle,\
	mat_block_gray_candle,\
	mat_block_light_gray_candle,\
	mat_block_cyan_candle,\
	mat_block_purple_candle,\
	mat_block_blue_candle,\
	mat_block_brown_candle,\
	mat_block_green_candle,\
	mat_block_red_candle,\
	mat_block_black_candle

const mat_tag_t mat_block_tag_candles_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:candles"),
	MAT_BLOCK_TAG_CANDLES
);

#define MAT_BLOCK_TAG_CANDLE_CAKES \
	mat_block_candle_cake,\
	mat_block_white_candle_cake,\
	mat_block_orange_candle_cake,\
	mat_block_magenta_candle_cake,\
	mat_block_light_blue_candle_cake,\
	mat_block_yellow_candle_cake,\
	mat_block_lime_candle_cake,\
	mat_block_pink_candle_cake,\
	mat_block_gray_candle_cake,\
	mat_block_light_gray_candle_cake,\
	mat_block_cyan_candle_cake,\
	mat_block_purple_candle_cake,\
	mat_block_blue_candle_cake,\
	mat_block_brown_candle_cake,\
	mat_block_green_candle_cake,\
	mat_block_red_candle_cake,\
	mat_block_black_candle_cake

const mat_tag_t mat_block_tag_candle_cakes_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:candle_cakes"),
	MAT_BLOCK_TAG_CANDLE_CAKES
);

#define MAT_BLOCK_TAG_CARPETS \
	mat_block_white_carpet,\
	mat_block_orange_carpet,\
	mat_block_magenta_carpet,\
	mat_block_light_blue_carpet,\
	mat_block_yellow_carpet,\
	mat_block_lime_carpet,\
	mat_block_pink_carpet,\
	mat_block_gray_carpet,\
	mat_block_light_gray_carpet,\
	mat_block_cyan_carpet,\
	mat_block_purple_carpet,\
	mat_block_blue_carpet,\
	mat_block_brown_carpet,\
	mat_block_green_carpet,\
	mat_block_red_carpet,\
	mat_block_black_carpet

const mat_tag_t mat_block_tag_carpets_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:carpets"),
	MAT_BLOCK_TAG_CARPETS
);

#define MAT_BLOCK_TAG_CAULDRONS \
	mat_block_cauldron,\
	mat_block_water_cauldron,\
	mat_block_lava_cauldron,\
	mat_block_powder_snow_cauldron

const mat_tag_t mat_block_tag_cauldrons_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:cauldrons"),
	MAT_BLOCK_TAG_CAULDRONS
);

#define MAT_BLOCK_TAG_CAVE_VINES \
	mat_block_cave_vines_plant,\
	mat_block_cave_vines

const mat_tag_t mat_block_tag_cave_vines_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:cave_vines"),
	MAT_BLOCK_TAG_CAVE_VINES
);

#define MAT_BLOCK_TAG_CLIMBABLE \
	mat_block_ladder,\
	mat_block_vine,\
	mat_block_scaffolding,\
	mat_block_weeping_vines,\
	mat_block_weeping_vines_plant,\
	mat_block_twisting_vines,\
	mat_block_twisting_vines_plant,\
	mat_block_cave_vines,\
	mat_block_cave_vines_plant

const mat_tag_t mat_block_tag_climbable_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:climbable"),
	MAT_BLOCK_TAG_CLIMBABLE
);

#define MAT_BLOCK_TAG_COAL_ORES \
	mat_block_coal_ore,\
	mat_block_deepslate_coal_ore

const mat_tag_t mat_block_tag_coal_ores_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:coal_ores"),
	MAT_BLOCK_TAG_COAL_ORES
);

#define MAT_BLOCK_TAG_NEEDS_WOODEN_TOOL \
	mat_block_ender_chest,\
	MAT_BLOCK_TAG_ANVIL,\
	mat_block_coal_block,\
	mat_block_redstone_block,\
	mat_block_enchanting_table,\
	mat_block_iron_bars,\
	mat_block_iron_door,\
	mat_block_iron_trapdoor,\
	mat_block_spawner,\
	mat_block_bell,\
	mat_block_dispenser,\
	mat_block_dropper,\
	mat_block_observer,\
	mat_block_furnace,\
	mat_block_blast_furnace,\
	mat_block_smoker,\
	mat_block_stonecutter,\
	mat_block_lodestone,\
	mat_block_lantern,\
	mat_block_soul_lantern,\
	MAT_BLOCK_TAG_COAL_ORES,\
	mat_block_end_stone,\
	mat_block_end_stone_bricks,\
	mat_block_end_stone_brick_stairs,\
	mat_block_end_stone_brick_wall,\
	mat_block_hopper,\
	mat_block_nether_quartz_ore,\
	mat_block_nether_gold_ore,\
	mat_block_grindstone,\
	mat_block_bone_block,\
	mat_block_brick_stairs,\
	mat_block_brick_wall,\
	mat_block_bricks,\
	mat_block_cauldron,\
	mat_block_water_cauldron,\
	mat_block_lava_cauldron,\
	mat_block_powder_snow_cauldron,\
	mat_block_cobblestone,\
	mat_block_cobblestone_stairs,\
	mat_block_cobblestone_wall,\
	mat_block_mossy_cobblestone,\
	mat_block_mossy_cobblestone_stairs,\
	mat_block_mossy_cobblestone_wall,\
	mat_block_nether_bricks,\
	mat_block_red_nether_bricks,\
	mat_block_red_nether_brick_stairs,\
	mat_block_red_nether_brick_wall,\
	mat_block_nether_brick_wall,\
	mat_block_nether_brick_fence,\
	mat_block_nether_brick_stairs,\
	mat_block_stone_slab,\
	mat_block_smooth_stone_slab,\
	mat_block_cobblestone_slab,\
	mat_block_mossy_cobblestone_slab,\
	mat_block_stone_brick_slab,\
	mat_block_mossy_stone_brick_slab,\
	mat_block_andesite_slab,\
	mat_block_polished_andesite_slab,\
	mat_block_diorite_slab,\
	mat_block_polished_diorite_slab,\
	mat_block_granite_slab,\
	mat_block_polished_granite_slab,\
	mat_block_sandstone_slab,\
	mat_block_cut_sandstone_slab,\
	mat_block_smooth_sandstone_slab,\
	mat_block_red_sandstone_slab,\
	mat_block_cut_red_sandstone_slab,\
	mat_block_smooth_red_sandstone_slab,\
	mat_block_brick_slab,\
	mat_block_prismarine_slab,\
	mat_block_prismarine_brick_slab,\
	mat_block_dark_prismarine_slab,\
	mat_block_nether_brick_slab,\
	mat_block_red_nether_brick_slab,\
	mat_block_quartz_slab,\
	mat_block_smooth_quartz_slab,\
	mat_block_purpur_slab,\
	mat_block_end_stone_brick_slab,\
	mat_block_blackstone_slab,\
	mat_block_polished_blackstone_slab,\
	mat_block_polished_blackstone_brick_slab,\
	mat_block_deepslate_tile_slab,\
	mat_block_deepslate_brick_slab,\
	mat_block_cobbled_deepslate_slab,\
	mat_block_polished_deepslate_slab,\
	mat_block_polished_blackstone,\
	mat_block_polished_blackstone_button,\
	mat_block_polished_blackstone_pressure_plate,\
	mat_block_polished_blackstone_stairs,\
	mat_block_polished_blackstone_wall,\
	mat_block_red_concrete,\
	mat_block_blue_concrete,\
	mat_block_gray_concrete,\
	mat_block_lime_concrete,\
	mat_block_pink_concrete,\
	mat_block_cyan_concrete,\
	mat_block_black_concrete,\
	mat_block_brown_concrete,\
	mat_block_green_concrete,\
	mat_block_white_concrete,\
	mat_block_orange_concrete,\
	mat_block_purple_concrete,\
	mat_block_yellow_concrete,\
	mat_block_magenta_concrete,\
	mat_block_light_blue_concrete,\
	mat_block_light_gray_concrete,\
	mat_block_andesite,\
	mat_block_andesite_stairs,\
	mat_block_andesite_wall,\
	mat_block_polished_andesite,\
	mat_block_polished_andesite_stairs,\
	mat_block_dark_prismarine,\
	mat_block_dark_prismarine_stairs,\
	mat_block_diorite,\
	mat_block_diorite_wall,\
	mat_block_diorite_stairs,\
	mat_block_polished_diorite,\
	mat_block_polished_diorite_stairs,\
	mat_block_granite,\
	mat_block_granite_stairs,\
	mat_block_granite_wall,\
	mat_block_polished_granite,\
	mat_block_polished_granite_stairs,\
	mat_block_prismarine,\
	mat_block_prismarine_stairs,\
	mat_block_prismarine_wall,\
	mat_block_prismarine_bricks,\
	mat_block_prismarine_brick_stairs,\
	mat_block_stone,\
	mat_block_stone_stairs,\
	mat_block_stone_button,\
	mat_block_stone_pressure_plate,\
	mat_block_smooth_stone,\
	mat_block_purpur_block,\
	mat_block_purpur_stairs,\
	mat_block_purpur_pillar,\
	mat_block_stone_bricks,\
	mat_block_stone_brick_wall,\
	mat_block_stone_brick_stairs,\
	mat_block_mossy_stone_bricks,\
	mat_block_mossy_stone_brick_stairs,\
	mat_block_mossy_stone_brick_wall,\
	mat_block_cracked_stone_bricks,\
	mat_block_blackstone,\
	mat_block_blackstone_stairs,\
	mat_block_blackstone_wall,\
	mat_block_chiseled_polished_blackstone,\
	mat_block_polished_blackstone_bricks,\
	mat_block_polished_blackstone_brick_stairs,\
	mat_block_polished_blackstone_brick_wall,\
	mat_block_gilded_blackstone,\
	mat_block_red_glazed_terracotta,\
	mat_block_blue_glazed_terracotta,\
	mat_block_cyan_glazed_terracotta,\
	mat_block_lime_glazed_terracotta,\
	mat_block_pink_glazed_terracotta,\
	mat_block_gray_glazed_terracotta,\
	mat_block_black_glazed_terracotta,\
	mat_block_brown_glazed_terracotta,\
	mat_block_white_glazed_terracotta,\
	mat_block_green_glazed_terracotta,\
	mat_block_orange_glazed_terracotta,\
	mat_block_purple_glazed_terracotta,\
	mat_block_yellow_glazed_terracotta,\
	mat_block_magenta_glazed_terracotta,\
	mat_block_light_blue_glazed_terracotta,\
	mat_block_light_gray_glazed_terracotta,\
	mat_block_red_terracotta,\
	mat_block_blue_terracotta,\
	mat_block_cyan_terracotta,\
	mat_block_lime_terracotta,\
	mat_block_pink_terracotta,\
	mat_block_gray_terracotta,\
	mat_block_black_terracotta,\
	mat_block_brown_terracotta,\
	mat_block_white_terracotta,\
	mat_block_green_terracotta,\
	mat_block_orange_terracotta,\
	mat_block_purple_terracotta,\
	mat_block_yellow_terracotta,\
	mat_block_magenta_terracotta,\
	mat_block_light_blue_terracotta,\
	mat_block_light_gray_terracotta,\
	mat_block_terracotta,\
	mat_block_basalt,\
	mat_block_smooth_basalt,\
	mat_block_polished_basalt,\
	mat_block_quartz_block,\
	mat_block_quartz_bricks,\
	mat_block_quartz_pillar,\
	mat_block_quartz_stairs,\
	mat_block_chiseled_quartz_block,\
	mat_block_smooth_quartz,\
	mat_block_smooth_quartz_stairs,\
	mat_block_red_sandstone,\
	mat_block_red_sandstone_wall,\
	mat_block_red_sandstone_stairs,\
	mat_block_cut_red_sandstone,\
	mat_block_smooth_red_sandstone,\
	mat_block_smooth_red_sandstone_stairs,\
	mat_block_chiseled_red_sandstone,\
	mat_block_sandstone,\
	mat_block_sandstone_wall,\
	mat_block_sandstone_stairs,\
	mat_block_cut_sandstone,\
	mat_block_smooth_sandstone,\
	mat_block_smooth_sandstone_stairs,\
	mat_block_chiseled_sandstone,\
	mat_block_warped_nylium,\
	mat_block_crimson_nylium,\
	mat_block_brewing_stand,\
	mat_block_magma_block,\
	mat_block_netherrack,\
	mat_block_deepslate,\
	mat_block_deepslate_bricks,\
	mat_block_deepslate_brick_stairs,\
	mat_block_deepslate_brick_wall,\
	mat_block_cobbled_deepslate,\
	mat_block_cobbled_deepslate_stairs,\
	mat_block_cobbled_deepslate_wall,\
	mat_block_deepslate_tiles,\
	mat_block_deepslate_tile_stairs,\
	mat_block_deepslate_tile_wall,\
	mat_block_cracked_deepslate_bricks,\
	mat_block_cracked_deepslate_tiles,\
	mat_block_polished_deepslate,\
	mat_block_polished_deepslate_stairs,\
	mat_block_polished_deepslate_wall,\
	mat_block_chiseled_deepslate,\
	mat_block_snow,\
	mat_block_snow_block

const mat_tag_t mat_block_tag_needs_wooden_tool_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("motor:needs_wooden_tool"),
	MAT_BLOCK_TAG_NEEDS_WOODEN_TOOL
);

#define MAT_BLOCK_TAG_COPPER_ORES \
	mat_block_copper_ore,\
	mat_block_deepslate_copper_ore

const mat_tag_t mat_block_tag_copper_ores_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:copper_ores"),
	MAT_BLOCK_TAG_COPPER_ORES
);

#define MAT_BLOCK_TAG_CORALS \
	mat_block_tube_coral,\
	mat_block_brain_coral,\
	mat_block_bubble_coral,\
	mat_block_fire_coral,\
	mat_block_horn_coral,\
	mat_block_tube_coral_fan,\
	mat_block_brain_coral_fan,\
	mat_block_bubble_coral_fan,\
	mat_block_fire_coral_fan,\
	mat_block_horn_coral_fan

const mat_tag_t mat_block_tag_corals_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:corals"),
	MAT_BLOCK_TAG_CORALS
);

#define MAT_BLOCK_TAG_CORAL_BLOCKS \
	mat_block_tube_coral_block,\
	mat_block_brain_coral_block,\
	mat_block_bubble_coral_block,\
	mat_block_fire_coral_block,\
	mat_block_horn_coral_block

const mat_tag_t mat_block_tag_coral_blocks_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:coral_blocks"),
	MAT_BLOCK_TAG_CORAL_BLOCKS
);

#define MAT_BLOCK_TAG_CORAL_PLANTS \
	mat_block_tube_coral,\
	mat_block_brain_coral,\
	mat_block_bubble_coral,\
	mat_block_fire_coral,\
	mat_block_horn_coral

const mat_tag_t mat_block_tag_coral_plants_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:coral_plants"),
	MAT_BLOCK_TAG_CORAL_PLANTS
);

#define MAT_BLOCK_TAG_CRIMSON_STEMS \
	mat_block_crimson_stem,\
	mat_block_stripped_crimson_stem,\
	mat_block_crimson_hyphae,\
	mat_block_stripped_crimson_hyphae

const mat_tag_t mat_block_tag_crimson_stems_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:crimson_stems"),
	MAT_BLOCK_TAG_CRIMSON_STEMS
);

#define MAT_BLOCK_TAG_CROPS \
	mat_block_beetroots,\
	mat_block_carrots,\
	mat_block_potatoes,\
	mat_block_wheat,\
	mat_block_melon_stem,\
	mat_block_pumpkin_stem

const mat_tag_t mat_block_tag_crops_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:crops"),
	MAT_BLOCK_TAG_CROPS
);

#define MAT_BLOCK_TAG_BEE_GROWABLES \
	MAT_BLOCK_TAG_CROPS,\
	mat_block_sweet_berry_bush,\
	mat_block_cave_vines,\
	mat_block_cave_vines_plant

const mat_tag_t mat_block_tag_bee_growables_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:bee_growables"),
	MAT_BLOCK_TAG_BEE_GROWABLES
);

#define MAT_BLOCK_TAG_CRYSTAL_SOUND_BLOCKS \
	mat_block_amethyst_block,\
	mat_block_budding_amethyst

const mat_tag_t mat_block_tag_crystal_sound_blocks_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:crystal_sound_blocks"),
	MAT_BLOCK_TAG_CRYSTAL_SOUND_BLOCKS
);

#define MAT_BLOCK_TAG_DARK_OAK_LOGS \
	mat_block_dark_oak_log,\
	mat_block_dark_oak_wood,\
	mat_block_stripped_dark_oak_log,\
	mat_block_stripped_dark_oak_wood

const mat_tag_t mat_block_tag_dark_oak_logs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:dark_oak_logs"),
	MAT_BLOCK_TAG_DARK_OAK_LOGS
);

#define MAT_BLOCK_TAG_DEEPSLATE_ORE_REPLACEABLES \
	mat_block_deepslate,\
	mat_block_tuff

const mat_tag_t mat_block_tag_deepslate_ore_replaceables_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:deepslate_ore_replaceables"),
	MAT_BLOCK_TAG_DEEPSLATE_ORE_REPLACEABLES
);

#define MAT_BLOCK_TAG_DIAMOND_ORES \
	mat_block_diamond_ore,\
	mat_block_deepslate_diamond_ore

const mat_tag_t mat_block_tag_diamond_ores_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:diamond_ores"),
	MAT_BLOCK_TAG_DIAMOND_ORES
);

#define MAT_BLOCK_TAG_DIRT \
	mat_block_dirt,\
	mat_block_grass_block,\
	mat_block_podzol,\
	mat_block_coarse_dirt,\
	mat_block_mycelium,\
	mat_block_rooted_dirt,\
	mat_block_moss_block

const mat_tag_t mat_block_tag_dirt_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:dirt"),
	MAT_BLOCK_TAG_DIRT
);

#define MAT_BLOCK_TAG_DRAGON_IMMUNE \
	mat_block_barrier,\
	mat_block_bedrock,\
	mat_block_end_portal,\
	mat_block_end_portal_frame,\
	mat_block_end_gateway,\
	mat_block_command_block,\
	mat_block_repeating_command_block,\
	mat_block_chain_command_block,\
	mat_block_structure_block,\
	mat_block_jigsaw,\
	mat_block_moving_piston,\
	mat_block_obsidian,\
	mat_block_crying_obsidian,\
	mat_block_end_stone,\
	mat_block_iron_bars,\
	mat_block_respawn_anchor

const mat_tag_t mat_block_tag_dragon_immune_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:dragon_immune"),
	MAT_BLOCK_TAG_DRAGON_IMMUNE
);

#define MAT_BLOCK_TAG_DRIPSTONE_REPLACEABLE_BLOCKS \
	MAT_BLOCK_TAG_BASE_STONE_OVERWORLD,\
	mat_block_dirt

const mat_tag_t mat_block_tag_dripstone_replaceable_blocks_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:dripstone_replaceable_blocks"),
	MAT_BLOCK_TAG_DRIPSTONE_REPLACEABLE_BLOCKS
);

#define MAT_BLOCK_TAG_EMERALD_ORES \
	mat_block_emerald_ore,\
	mat_block_deepslate_emerald_ore

const mat_tag_t mat_block_tag_emerald_ores_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:emerald_ores"),
	MAT_BLOCK_TAG_EMERALD_ORES
);

#define MAT_BLOCK_TAG_FEATURES_CANNOT_REPLACE \
	mat_block_bedrock,\
	mat_block_spawner,\
	mat_block_chest,\
	mat_block_end_portal_frame

const mat_tag_t mat_block_tag_features_cannot_replace_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:features_cannot_replace"),
	MAT_BLOCK_TAG_FEATURES_CANNOT_REPLACE
);

#define MAT_BLOCK_TAG_FENCE_GATES \
	mat_block_acacia_fence_gate,\
	mat_block_birch_fence_gate,\
	mat_block_dark_oak_fence_gate,\
	mat_block_jungle_fence_gate,\
	mat_block_oak_fence_gate,\
	mat_block_spruce_fence_gate,\
	mat_block_crimson_fence_gate,\
	mat_block_warped_fence_gate

const mat_tag_t mat_block_tag_fence_gates_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:fence_gates"),
	MAT_BLOCK_TAG_FENCE_GATES
);

#define MAT_BLOCK_TAG_FIRE \
	mat_block_fire,\
	mat_block_soul_fire

const mat_tag_t mat_block_tag_fire_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:fire"),
	MAT_BLOCK_TAG_FIRE
);

#define MAT_BLOCK_TAG_FLOWER_POTS \
	mat_block_flower_pot,\
	mat_block_potted_poppy,\
	mat_block_potted_blue_orchid,\
	mat_block_potted_allium,\
	mat_block_potted_azure_bluet,\
	mat_block_potted_red_tulip,\
	mat_block_potted_orange_tulip,\
	mat_block_potted_white_tulip,\
	mat_block_potted_pink_tulip,\
	mat_block_potted_oxeye_daisy,\
	mat_block_potted_dandelion,\
	mat_block_potted_oak_sapling,\
	mat_block_potted_spruce_sapling,\
	mat_block_potted_birch_sapling,\
	mat_block_potted_jungle_sapling,\
	mat_block_potted_acacia_sapling,\
	mat_block_potted_dark_oak_sapling,\
	mat_block_potted_red_mushroom,\
	mat_block_potted_brown_mushroom,\
	mat_block_potted_dead_bush,\
	mat_block_potted_fern,\
	mat_block_potted_cactus,\
	mat_block_potted_cornflower,\
	mat_block_potted_lily_of_the_valley,\
	mat_block_potted_wither_rose,\
	mat_block_potted_bamboo,\
	mat_block_potted_crimson_fungus,\
	mat_block_potted_warped_fungus,\
	mat_block_potted_crimson_roots,\
	mat_block_potted_warped_roots,\
	mat_block_potted_azalea_bush,\
	mat_block_potted_flowering_azalea_bush

const mat_tag_t mat_block_tag_flower_pots_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:flower_pots"),
	MAT_BLOCK_TAG_FLOWER_POTS
);

#define MAT_BLOCK_TAG_GEODE_INVALID_BLOCKS \
	mat_block_bedrock,\
	mat_block_water,\
	mat_block_lava,\
	mat_block_ice,\
	mat_block_packed_ice,\
	mat_block_blue_ice

const mat_tag_t mat_block_tag_geode_invalid_blocks_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:geode_invalid_blocks"),
	MAT_BLOCK_TAG_GEODE_INVALID_BLOCKS
);

#define MAT_BLOCK_TAG_GOLD_ORES \
	mat_block_gold_ore,\
	mat_block_nether_gold_ore,\
	mat_block_deepslate_gold_ore

const mat_tag_t mat_block_tag_gold_ores_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:gold_ores"),
	MAT_BLOCK_TAG_GOLD_ORES
);

#define MAT_BLOCK_TAG_HOGLIN_REPELLENTS \
	mat_block_warped_fungus,\
	mat_block_potted_warped_fungus,\
	mat_block_nether_portal,\
	mat_block_respawn_anchor

const mat_tag_t mat_block_tag_hoglin_repellents_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:hoglin_repellents"),
	MAT_BLOCK_TAG_HOGLIN_REPELLENTS
);

#define MAT_BLOCK_TAG_ICE \
	mat_block_ice,\
	mat_block_packed_ice,\
	mat_block_blue_ice,\
	mat_block_frosted_ice

const mat_tag_t mat_block_tag_ice_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:ice"),
	MAT_BLOCK_TAG_ICE
);

#define MAT_BLOCK_TAG_IMPERMEABLE \
	mat_block_glass,\
	mat_block_white_stained_glass,\
	mat_block_orange_stained_glass,\
	mat_block_magenta_stained_glass,\
	mat_block_light_blue_stained_glass,\
	mat_block_yellow_stained_glass,\
	mat_block_lime_stained_glass,\
	mat_block_pink_stained_glass,\
	mat_block_gray_stained_glass,\
	mat_block_light_gray_stained_glass,\
	mat_block_cyan_stained_glass,\
	mat_block_purple_stained_glass,\
	mat_block_blue_stained_glass,\
	mat_block_brown_stained_glass,\
	mat_block_green_stained_glass,\
	mat_block_red_stained_glass,\
	mat_block_black_stained_glass,\
	mat_block_tinted_glass

const mat_tag_t mat_block_tag_impermeable_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:impermeable"),
	MAT_BLOCK_TAG_IMPERMEABLE
);

#define MAT_BLOCK_TAG_INFINIBURN_END \
	mat_block_netherrack,\
	mat_block_magma_block,\
	mat_block_bedrock

const mat_tag_t mat_block_tag_infiniburn_end_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:infiniburn_end"),
	MAT_BLOCK_TAG_INFINIBURN_END
);

#define MAT_BLOCK_TAG_INFINIBURN_NETHER \
	mat_block_netherrack,\
	mat_block_magma_block

const mat_tag_t mat_block_tag_infiniburn_nether_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:infiniburn_nether"),
	MAT_BLOCK_TAG_INFINIBURN_NETHER
);

#define MAT_BLOCK_TAG_INFINIBURN_OVERWORLD \
	mat_block_netherrack,\
	mat_block_magma_block

const mat_tag_t mat_block_tag_infiniburn_overworld_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:infiniburn_overworld"),
	MAT_BLOCK_TAG_INFINIBURN_OVERWORLD
);

#define MAT_BLOCK_TAG_INSIDE_STEP_SOUND_BLOCKS \
	mat_block_snow,\
	mat_block_powder_snow

const mat_tag_t mat_block_tag_inside_step_sound_blocks_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:inside_step_sound_blocks"),
	MAT_BLOCK_TAG_INSIDE_STEP_SOUND_BLOCKS
);

#define MAT_BLOCK_TAG_IRON_ORES \
	mat_block_iron_ore,\
	mat_block_deepslate_iron_ore

const mat_tag_t mat_block_tag_iron_ores_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:iron_ores"),
	MAT_BLOCK_TAG_IRON_ORES
);

#define MAT_BLOCK_TAG_JUNGLE_LOGS \
	mat_block_jungle_log,\
	mat_block_jungle_wood,\
	mat_block_stripped_jungle_log,\
	mat_block_stripped_jungle_wood

const mat_tag_t mat_block_tag_jungle_logs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:jungle_logs"),
	MAT_BLOCK_TAG_JUNGLE_LOGS
);

#define MAT_BLOCK_TAG_LAPIS_ORES \
	mat_block_lapis_ore,\
	mat_block_deepslate_lapis_ore

const mat_tag_t mat_block_tag_lapis_ores_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:lapis_ores"),
	MAT_BLOCK_TAG_LAPIS_ORES
);

#define MAT_BLOCK_TAG_LEAVES \
	mat_block_jungle_leaves,\
	mat_block_oak_leaves,\
	mat_block_spruce_leaves,\
	mat_block_dark_oak_leaves,\
	mat_block_acacia_leaves,\
	mat_block_birch_leaves,\
	mat_block_azalea_leaves,\
	mat_block_flowering_azalea_leaves

const mat_tag_t mat_block_tag_leaves_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:leaves"),
	MAT_BLOCK_TAG_LEAVES
);

#define MAT_BLOCK_TAG_MOSS_REPLACEABLE \
	MAT_BLOCK_TAG_BASE_STONE_OVERWORLD,\
	MAT_BLOCK_TAG_CAVE_VINES,\
	MAT_BLOCK_TAG_DIRT

const mat_tag_t mat_block_tag_moss_replaceable_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:moss_replaceable"),
	MAT_BLOCK_TAG_MOSS_REPLACEABLE
);

#define MAT_BLOCK_TAG_LUSH_GROUND_REPLACEABLE \
	MAT_BLOCK_TAG_MOSS_REPLACEABLE,\
	mat_block_clay,\
	mat_block_gravel,\
	mat_block_sand

const mat_tag_t mat_block_tag_lush_ground_replaceable_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:lush_ground_replaceable"),
	MAT_BLOCK_TAG_LUSH_GROUND_REPLACEABLE
);

#define MAT_BLOCK_TAG_MUSHROOM_GROW_BLOCK \
	mat_block_mycelium,\
	mat_block_podzol,\
	mat_block_crimson_nylium,\
	mat_block_warped_nylium

const mat_tag_t mat_block_tag_mushroom_grow_block_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:mushroom_grow_block"),
	MAT_BLOCK_TAG_MUSHROOM_GROW_BLOCK
);

#define MAT_BLOCK_TAG_NEEDS_DIAMOND_TOOL \
	mat_block_obsidian,\
	mat_block_crying_obsidian,\
	mat_block_netherite_block,\
	mat_block_respawn_anchor,\
	mat_block_ancient_debris

const mat_tag_t mat_block_tag_needs_diamond_tool_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:needs_diamond_tool"),
	MAT_BLOCK_TAG_NEEDS_DIAMOND_TOOL
);

#define MAT_BLOCK_TAG_NEEDS_IRON_TOOL \
	mat_block_diamond_block,\
	mat_block_diamond_ore,\
	mat_block_deepslate_diamond_ore,\
	mat_block_emerald_ore,\
	mat_block_deepslate_emerald_ore,\
	mat_block_emerald_block,\
	mat_block_gold_block,\
	mat_block_raw_gold_block,\
	mat_block_gold_ore,\
	mat_block_deepslate_gold_ore,\
	mat_block_redstone_ore,\
	mat_block_deepslate_redstone_ore

const mat_tag_t mat_block_tag_needs_iron_tool_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:needs_iron_tool"),
	MAT_BLOCK_TAG_NEEDS_IRON_TOOL
);

#define MAT_BLOCK_TAG_NEEDS_STONE_TOOL \
	mat_block_iron_block,\
	mat_block_raw_iron_block,\
	mat_block_iron_ore,\
	mat_block_deepslate_iron_ore,\
	mat_block_lapis_block,\
	mat_block_lapis_ore,\
	mat_block_deepslate_lapis_ore,\
	mat_block_copper_block,\
	mat_block_raw_copper_block,\
	mat_block_copper_ore,\
	mat_block_deepslate_copper_ore,\
	mat_block_cut_copper_slab,\
	mat_block_cut_copper_stairs,\
	mat_block_cut_copper,\
	mat_block_weathered_copper,\
	mat_block_weathered_cut_copper_slab,\
	mat_block_weathered_cut_copper_stairs,\
	mat_block_weathered_cut_copper,\
	mat_block_oxidized_copper,\
	mat_block_oxidized_cut_copper_slab,\
	mat_block_oxidized_cut_copper_stairs,\
	mat_block_oxidized_cut_copper,\
	mat_block_exposed_copper,\
	mat_block_exposed_cut_copper_slab,\
	mat_block_exposed_cut_copper_stairs,\
	mat_block_exposed_cut_copper,\
	mat_block_waxed_copper_block,\
	mat_block_waxed_cut_copper_slab,\
	mat_block_waxed_cut_copper_stairs,\
	mat_block_waxed_cut_copper,\
	mat_block_waxed_weathered_copper,\
	mat_block_waxed_weathered_cut_copper_slab,\
	mat_block_waxed_weathered_cut_copper_stairs,\
	mat_block_waxed_weathered_cut_copper,\
	mat_block_waxed_exposed_copper,\
	mat_block_waxed_exposed_cut_copper_slab,\
	mat_block_waxed_exposed_cut_copper_stairs,\
	mat_block_waxed_exposed_cut_copper,\
	mat_block_waxed_oxidized_copper,\
	mat_block_waxed_oxidized_cut_copper_slab,\
	mat_block_waxed_oxidized_cut_copper_stairs,\
	mat_block_waxed_oxidized_cut_copper,\
	mat_block_lightning_rod

const mat_tag_t mat_block_tag_needs_stone_tool_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:needs_stone_tool"),
	MAT_BLOCK_TAG_NEEDS_STONE_TOOL
);

#define MAT_BLOCK_TAG_NEEDS \
	MAT_BLOCK_TAG_NEEDS_WOODEN_TOOL,\
	MAT_BLOCK_TAG_NEEDS_STONE_TOOL,\
	MAT_BLOCK_TAG_NEEDS_IRON_TOOL,\
	MAT_BLOCK_TAG_NEEDS_DIAMOND_TOOL

const mat_tag_t mat_block_tag_needs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("motor:needs"),
	MAT_BLOCK_TAG_NEEDS
);

#define MAT_BLOCK_TAG_NON_FLAMMABLE_WOOD \
	mat_block_warped_stem,\
	mat_block_stripped_warped_stem,\
	mat_block_warped_hyphae,\
	mat_block_stripped_warped_hyphae,\
	mat_block_crimson_stem,\
	mat_block_stripped_crimson_stem,\
	mat_block_crimson_hyphae,\
	mat_block_stripped_crimson_hyphae,\
	mat_block_crimson_planks,\
	mat_block_warped_planks,\
	mat_block_crimson_slab,\
	mat_block_warped_slab,\
	mat_block_crimson_pressure_plate,\
	mat_block_warped_pressure_plate,\
	mat_block_crimson_fence,\
	mat_block_warped_fence,\
	mat_block_crimson_trapdoor,\
	mat_block_warped_trapdoor,\
	mat_block_crimson_fence_gate,\
	mat_block_warped_fence_gate,\
	mat_block_crimson_stairs,\
	mat_block_warped_stairs,\
	mat_block_crimson_button,\
	mat_block_warped_button,\
	mat_block_crimson_door,\
	mat_block_warped_door,\
	mat_block_crimson_sign,\
	mat_block_warped_sign,\
	mat_block_crimson_wall_sign,\
	mat_block_warped_wall_sign

const mat_tag_t mat_block_tag_non_flammable_wood_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:non_flammable_wood"),
	MAT_BLOCK_TAG_NON_FLAMMABLE_WOOD
);

#define MAT_BLOCK_TAG_NYLIUM \
	mat_block_crimson_nylium,\
	mat_block_warped_nylium

const mat_tag_t mat_block_tag_nylium_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:nylium"),
	MAT_BLOCK_TAG_NYLIUM
);

#define MAT_BLOCK_TAG_OAK_LOGS \
	mat_block_oak_log,\
	mat_block_oak_wood,\
	mat_block_stripped_oak_log,\
	mat_block_stripped_oak_wood

const mat_tag_t mat_block_tag_oak_logs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:oak_logs"),
	MAT_BLOCK_TAG_OAK_LOGS
);

#define MAT_BLOCK_TAG_PIGLIN_REPELLENTS \
	mat_block_soul_fire,\
	mat_block_soul_torch,\
	mat_block_soul_lantern,\
	mat_block_soul_wall_torch,\
	mat_block_soul_campfire

const mat_tag_t mat_block_tag_piglin_repellents_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:piglin_repellents"),
	MAT_BLOCK_TAG_PIGLIN_REPELLENTS
);

#define MAT_BLOCK_TAG_PLANKS \
	mat_block_oak_planks,\
	mat_block_spruce_planks,\
	mat_block_birch_planks,\
	mat_block_jungle_planks,\
	mat_block_acacia_planks,\
	mat_block_dark_oak_planks,\
	mat_block_crimson_planks,\
	mat_block_warped_planks

const mat_tag_t mat_block_tag_planks_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:planks"),
	MAT_BLOCK_TAG_PLANKS
);

#define MAT_BLOCK_TAG_PORTALS \
	mat_block_nether_portal,\
	mat_block_end_portal,\
	mat_block_end_gateway

const mat_tag_t mat_block_tag_portals_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:portals"),
	MAT_BLOCK_TAG_PORTALS
);

#define MAT_BLOCK_TAG_RAILS \
	mat_block_rail,\
	mat_block_powered_rail,\
	mat_block_detector_rail,\
	mat_block_activator_rail

const mat_tag_t mat_block_tag_rails_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:rails"),
	MAT_BLOCK_TAG_RAILS
);

#define MAT_BLOCK_TAG_PREVENT_MOB_SPAWNING_INSIDE \
	MAT_BLOCK_TAG_RAILS

const mat_tag_t mat_block_tag_prevent_mob_spawning_inside_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:prevent_mob_spawning_inside"),
	MAT_BLOCK_TAG_PREVENT_MOB_SPAWNING_INSIDE
);

#define MAT_BLOCK_TAG_REDSTONE_ORES \
	mat_block_redstone_ore,\
	mat_block_deepslate_redstone_ore

const mat_tag_t mat_block_tag_redstone_ores_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:redstone_ores"),
	MAT_BLOCK_TAG_REDSTONE_ORES
);

#define MAT_BLOCK_TAG_SAND \
	mat_block_sand,\
	mat_block_red_sand

const mat_tag_t mat_block_tag_sand_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:sand"),
	MAT_BLOCK_TAG_SAND
);

#define MAT_BLOCK_TAG_BAMBOO_PLANTABLE_ON \
	MAT_BLOCK_TAG_SAND,\
	MAT_BLOCK_TAG_DIRT,\
	mat_block_bamboo,\
	mat_block_bamboo_sapling,\
	mat_block_gravel

const mat_tag_t mat_block_tag_bamboo_plantable_on_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:bamboo_plantable_on"),
	MAT_BLOCK_TAG_BAMBOO_PLANTABLE_ON
);

#define MAT_BLOCK_TAG_SAPLINGS \
	mat_block_oak_sapling,\
	mat_block_spruce_sapling,\
	mat_block_birch_sapling,\
	mat_block_jungle_sapling,\
	mat_block_acacia_sapling,\
	mat_block_dark_oak_sapling,\
	mat_block_azalea,\
	mat_block_flowering_azalea

const mat_tag_t mat_block_tag_saplings_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:saplings"),
	MAT_BLOCK_TAG_SAPLINGS
);

#define MAT_BLOCK_TAG_SHULKER_BOXES \
	mat_block_shulker_box,\
	mat_block_black_shulker_box,\
	mat_block_blue_shulker_box,\
	mat_block_brown_shulker_box,\
	mat_block_cyan_shulker_box,\
	mat_block_gray_shulker_box,\
	mat_block_green_shulker_box,\
	mat_block_light_blue_shulker_box,\
	mat_block_light_gray_shulker_box,\
	mat_block_lime_shulker_box,\
	mat_block_magenta_shulker_box,\
	mat_block_orange_shulker_box,\
	mat_block_pink_shulker_box,\
	mat_block_purple_shulker_box,\
	mat_block_red_shulker_box,\
	mat_block_white_shulker_box,\
	mat_block_yellow_shulker_box

const mat_tag_t mat_block_tag_shulker_boxes_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:shulker_boxes"),
	MAT_BLOCK_TAG_SHULKER_BOXES
);

#define MAT_BLOCK_TAG_GUARDED_BY_PIGLINS \
	mat_block_gold_block,\
	mat_block_barrel,\
	mat_block_chest,\
	mat_block_ender_chest,\
	mat_block_gilded_blackstone,\
	mat_block_trapped_chest,\
	mat_block_raw_gold_block,\
	MAT_BLOCK_TAG_SHULKER_BOXES,\
	MAT_BLOCK_TAG_GOLD_ORES

const mat_tag_t mat_block_tag_guarded_by_piglins_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:guarded_by_piglins"),
	MAT_BLOCK_TAG_GUARDED_BY_PIGLINS
);

#define MAT_BLOCK_TAG_SMALL_DRIPLEAF_PLACEABLE \
	mat_block_clay,\
	mat_block_moss_block

const mat_tag_t mat_block_tag_small_dripleaf_placeable_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:small_dripleaf_placeable"),
	MAT_BLOCK_TAG_SMALL_DRIPLEAF_PLACEABLE
);

#define MAT_BLOCK_TAG_SMALL_FLOWERS \
	mat_block_dandelion,\
	mat_block_poppy,\
	mat_block_blue_orchid,\
	mat_block_allium,\
	mat_block_azure_bluet,\
	mat_block_red_tulip,\
	mat_block_orange_tulip,\
	mat_block_white_tulip,\
	mat_block_pink_tulip,\
	mat_block_oxeye_daisy,\
	mat_block_cornflower,\
	mat_block_lily_of_the_valley,\
	mat_block_wither_rose

const mat_tag_t mat_block_tag_small_flowers_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:small_flowers"),
	MAT_BLOCK_TAG_SMALL_FLOWERS
);

#define MAT_BLOCK_TAG_ENDERMAN_HOLDABLE \
	MAT_BLOCK_TAG_SMALL_FLOWERS,\
	MAT_BLOCK_TAG_DIRT,\
	mat_block_sand,\
	mat_block_red_sand,\
	mat_block_gravel,\
	mat_block_brown_mushroom,\
	mat_block_red_mushroom,\
	mat_block_tnt,\
	mat_block_cactus,\
	mat_block_clay,\
	mat_block_pumpkin,\
	mat_block_carved_pumpkin,\
	mat_block_melon,\
	mat_block_crimson_fungus,\
	mat_block_crimson_nylium,\
	mat_block_crimson_roots,\
	mat_block_warped_fungus,\
	mat_block_warped_nylium,\
	mat_block_warped_roots

const mat_tag_t mat_block_tag_enderman_holdable_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:enderman_holdable"),
	MAT_BLOCK_TAG_ENDERMAN_HOLDABLE
);

#define MAT_BLOCK_TAG_SNOW \
	mat_block_snow,\
	mat_block_snow_block,\
	mat_block_powder_snow

const mat_tag_t mat_block_tag_snow_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:snow"),
	MAT_BLOCK_TAG_SNOW
);

#define MAT_BLOCK_TAG_SOUL_FIRE_BASE_BLOCKS \
	mat_block_soul_sand,\
	mat_block_soul_soil,

const mat_tag_t mat_block_tag_soul_fire_base_blocks_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:soul_fire_base_blocks"),
	MAT_BLOCK_TAG_SOUL_FIRE_BASE_BLOCKS
);

#define MAT_BLOCK_TAG_SOUL_SPEED_BLOCKS \
	mat_block_soul_sand,\
	mat_block_soul_soil

const mat_tag_t mat_block_tag_soul_speed_blocks_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:soul_speed_blocks"),
	MAT_BLOCK_TAG_SOUL_SPEED_BLOCKS
);

#define MAT_BLOCK_TAG_SPRUCE_LOGS \
	mat_block_spruce_log,\
	mat_block_spruce_wood,\
	mat_block_stripped_spruce_log,\
	mat_block_stripped_spruce_wood

const mat_tag_t mat_block_tag_spruce_logs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:spruce_logs"),
	MAT_BLOCK_TAG_SPRUCE_LOGS
);

#define MAT_BLOCK_TAG_STANDING_SIGNS \
	mat_block_oak_sign,\
	mat_block_spruce_sign,\
	mat_block_birch_sign,\
	mat_block_acacia_sign,\
	mat_block_jungle_sign,\
	mat_block_dark_oak_sign,\
	mat_block_crimson_sign,\
	mat_block_warped_sign

const mat_tag_t mat_block_tag_standing_signs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:standing_signs"),
	MAT_BLOCK_TAG_STANDING_SIGNS
);

#define MAT_BLOCK_TAG_STONE_BRICKS \
	mat_block_stone_bricks,\
	mat_block_mossy_stone_bricks,\
	mat_block_cracked_stone_bricks,\
	mat_block_chiseled_stone_bricks

const mat_tag_t mat_block_tag_stone_bricks_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:stone_bricks"),
	MAT_BLOCK_TAG_STONE_BRICKS
);

#define MAT_BLOCK_TAG_STONE_ORE_REPLACEABLES \
	mat_block_stone,\
	mat_block_granite,\
	mat_block_diorite,\
	mat_block_andesite

const mat_tag_t mat_block_tag_stone_ore_replaceables_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:stone_ore_replaceables"),
	MAT_BLOCK_TAG_STONE_ORE_REPLACEABLES
);

#define MAT_BLOCK_TAG_STONE_PRESSURE_PLATES \
	mat_block_stone_pressure_plate,\
	mat_block_polished_blackstone_pressure_plate

const mat_tag_t mat_block_tag_stone_pressure_plates_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:stone_pressure_plates"),
	MAT_BLOCK_TAG_STONE_PRESSURE_PLATES
);

#define MAT_BLOCK_TAG_STRIDER_WARM_BLOCKS \
	mat_block_lava

const mat_tag_t mat_block_tag_strider_warm_blocks_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:strider_warm_blocks"),
	MAT_BLOCK_TAG_STRIDER_WARM_BLOCKS
);

#define MAT_BLOCK_TAG_TALL_FLOWERS \
	mat_block_sunflower,\
	mat_block_lilac,\
	mat_block_peony,\
	mat_block_rose_bush

const mat_tag_t mat_block_tag_tall_flowers_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:tall_flowers"),
	MAT_BLOCK_TAG_TALL_FLOWERS
);

#define MAT_BLOCK_TAG_FLOWERS \
	MAT_BLOCK_TAG_SMALL_FLOWERS,\
	MAT_BLOCK_TAG_TALL_FLOWERS,\
	mat_block_flowering_azalea_leaves,\
	mat_block_flowering_azalea

const mat_tag_t mat_block_tag_flowers_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:flowers"),
	MAT_BLOCK_TAG_FLOWERS
);

#define MAT_BLOCK_TAG_UNSTABLE_BOTTOM_CENTER \
	MAT_BLOCK_TAG_FENCE_GATES

const mat_tag_t mat_block_tag_unstable_bottom_center_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:unstable_bottom_center"),
	MAT_BLOCK_TAG_UNSTABLE_BOTTOM_CENTER
);

#define MAT_BLOCK_TAG_VALID_SPAWN \
	mat_block_grass_block,\
	mat_block_podzol

const mat_tag_t mat_block_tag_valid_spawn_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:valid_spawn"),
	MAT_BLOCK_TAG_VALID_SPAWN
);

#define MAT_BLOCK_TAG_WALLS \
	mat_block_cobblestone_wall,\
	mat_block_mossy_cobblestone_wall,\
	mat_block_brick_wall,\
	mat_block_prismarine_wall,\
	mat_block_red_sandstone_wall,\
	mat_block_mossy_stone_brick_wall,\
	mat_block_granite_wall,\
	mat_block_stone_brick_wall,\
	mat_block_nether_brick_wall,\
	mat_block_andesite_wall,\
	mat_block_red_nether_brick_wall,\
	mat_block_sandstone_wall,\
	mat_block_end_stone_brick_wall,\
	mat_block_diorite_wall,\
	mat_block_blackstone_wall,\
	mat_block_polished_blackstone_brick_wall,\
	mat_block_polished_blackstone_wall,\
	mat_block_cobbled_deepslate_wall,\
	mat_block_polished_deepslate_wall,\
	mat_block_deepslate_tile_wall,\
	mat_block_deepslate_brick_wall

const mat_tag_t mat_block_tag_walls_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:walls"),
	MAT_BLOCK_TAG_WALLS
);

#define MAT_BLOCK_TAG_WALL_CORALS \
	mat_block_tube_coral_wall_fan,\
	mat_block_brain_coral_wall_fan,\
	mat_block_bubble_coral_wall_fan,\
	mat_block_fire_coral_wall_fan,\
	mat_block_horn_coral_wall_fan

const mat_tag_t mat_block_tag_wall_corals_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:wall_corals"),
	MAT_BLOCK_TAG_WALL_CORALS
);

#define MAT_BLOCK_TAG_UNDERWATER_BONEMEALS \
	mat_block_seagrass,\
	MAT_BLOCK_TAG_CORALS,\
	MAT_BLOCK_TAG_WALL_CORALS

const mat_tag_t mat_block_tag_underwater_bonemeals_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:underwater_bonemeals"),
	MAT_BLOCK_TAG_UNDERWATER_BONEMEALS
);

#define MAT_BLOCK_TAG_WALL_SIGNS \
	mat_block_oak_wall_sign,\
	mat_block_spruce_wall_sign,\
	mat_block_birch_wall_sign,\
	mat_block_acacia_wall_sign,\
	mat_block_jungle_wall_sign,\
	mat_block_dark_oak_wall_sign,\
	mat_block_crimson_wall_sign,\
	mat_block_warped_wall_sign

const mat_tag_t mat_block_tag_wall_signs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:wall_signs"),
	MAT_BLOCK_TAG_WALL_SIGNS
);

#define MAT_BLOCK_TAG_SIGNS \
	MAT_BLOCK_TAG_STANDING_SIGNS,\
	MAT_BLOCK_TAG_WALL_SIGNS

const mat_tag_t mat_block_tag_signs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:signs"),
	MAT_BLOCK_TAG_SIGNS
);

#define MAT_BLOCK_TAG_WARPED_STEMS \
	mat_block_warped_stem,\
	mat_block_stripped_warped_stem,\
	mat_block_warped_hyphae,\
	mat_block_stripped_warped_hyphae

const mat_tag_t mat_block_tag_warped_stems_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:warped_stems"),
	MAT_BLOCK_TAG_WARPED_STEMS
);

#define MAT_BLOCK_TAG_LOGS_THAT_BURN \
	MAT_BLOCK_TAG_DARK_OAK_LOGS,\
	MAT_BLOCK_TAG_OAK_LOGS,\
	MAT_BLOCK_TAG_ACACIA_LOGS,\
	MAT_BLOCK_TAG_BIRCH_LOGS,\
	MAT_BLOCK_TAG_JUNGLE_LOGS,\
	MAT_BLOCK_TAG_SPRUCE_LOGS

const mat_tag_t mat_block_tag_logs_that_burn_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:logs_that_burn"),
	MAT_BLOCK_TAG_LOGS_THAT_BURN
);

#define MAT_BLOCK_TAG_LOGS \
	MAT_BLOCK_TAG_LOGS_THAT_BURN,\
	MAT_BLOCK_TAG_CRIMSON_STEMS,\
	MAT_BLOCK_TAG_WARPED_STEMS

const mat_tag_t mat_block_tag_logs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:logs"),
	MAT_BLOCK_TAG_LOGS
);

#define MAT_BLOCK_TAG_LAVA_POOL_STONE_CANNOT_REPLACE \
	MAT_BLOCK_TAG_FEATURES_CANNOT_REPLACE,\
	MAT_BLOCK_TAG_LEAVES,\
	MAT_BLOCK_TAG_LOGS

const mat_tag_t mat_block_tag_lava_pool_stone_cannot_replace_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:lava_pool_stone_cannot_replace"),
	MAT_BLOCK_TAG_LAVA_POOL_STONE_CANNOT_REPLACE
);

#define MAT_BLOCK_TAG_WART_BLOCKS \
	mat_block_nether_wart_block,\
	mat_block_warped_wart_block

const mat_tag_t mat_block_tag_wart_blocks_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:wart_blocks"),
	MAT_BLOCK_TAG_WART_BLOCKS
);

#define MAT_BLOCK_TAG_WITHER_IMMUNE \
	mat_block_barrier,\
	mat_block_bedrock,\
	mat_block_end_portal,\
	mat_block_end_portal_frame,\
	mat_block_end_gateway,\
	mat_block_command_block,\
	mat_block_repeating_command_block,\
	mat_block_chain_command_block,\
	mat_block_structure_block,\
	mat_block_jigsaw,\
	mat_block_moving_piston

const mat_tag_t mat_block_tag_wither_immune_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:wither_immune"),
	MAT_BLOCK_TAG_WITHER_IMMUNE
);

#define MAT_BLOCK_TAG_WITHER_SUMMON_BASE_BLOCKS \
	mat_block_soul_sand,\
	mat_block_soul_soil

const mat_tag_t mat_block_tag_wither_summon_base_blocks_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:wither_summon_base_blocks"),
	MAT_BLOCK_TAG_WITHER_SUMMON_BASE_BLOCKS
);

#define MAT_BLOCK_TAG_WOODEN_BUTTONS \
	mat_block_oak_button,\
	mat_block_spruce_button,\
	mat_block_birch_button,\
	mat_block_jungle_button,\
	mat_block_acacia_button,\
	mat_block_dark_oak_button,\
	mat_block_crimson_button,\
	mat_block_warped_button

const mat_tag_t mat_block_tag_wooden_buttons_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:wooden_buttons"),
	MAT_BLOCK_TAG_WOODEN_BUTTONS
);

#define MAT_BLOCK_TAG_BUTTONS \
	MAT_BLOCK_TAG_WOODEN_BUTTONS,\
	mat_block_stone_button,\
	mat_block_polished_blackstone_button

const mat_tag_t mat_block_tag_buttons_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:buttons"),
	MAT_BLOCK_TAG_BUTTONS
);

#define MAT_BLOCK_TAG_WOODEN_DOORS \
	mat_block_oak_door,\
	mat_block_spruce_door,\
	mat_block_birch_door,\
	mat_block_jungle_door,\
	mat_block_acacia_door,\
	mat_block_dark_oak_door,\
	mat_block_crimson_door,\
	mat_block_warped_door

const mat_tag_t mat_block_tag_wooden_doors_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:wooden_doors"),
	MAT_BLOCK_TAG_WOODEN_DOORS
);

#define MAT_BLOCK_TAG_DOORS \
	MAT_BLOCK_TAG_WOODEN_DOORS,\
	mat_block_iron_door

const mat_tag_t mat_block_tag_doors_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:doors"),
	MAT_BLOCK_TAG_DOORS
);

#define MAT_BLOCK_TAG_WOODEN_FENCES \
	mat_block_oak_fence,\
	mat_block_acacia_fence,\
	mat_block_dark_oak_fence,\
	mat_block_spruce_fence,\
	mat_block_birch_fence,\
	mat_block_jungle_fence,\
	mat_block_crimson_fence,\
	mat_block_warped_fence

const mat_tag_t mat_block_tag_wooden_fences_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:wooden_fences"),
	MAT_BLOCK_TAG_WOODEN_FENCES
);

#define MAT_BLOCK_TAG_FENCES \
	MAT_BLOCK_TAG_WOODEN_FENCES,\
	mat_block_nether_brick_fence

const mat_tag_t mat_block_tag_fences_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:fences"),
	MAT_BLOCK_TAG_FENCES
);

#define MAT_BLOCK_TAG_WOODEN_PRESSURE_PLATES \
	mat_block_oak_pressure_plate,\
	mat_block_spruce_pressure_plate,\
	mat_block_birch_pressure_plate,\
	mat_block_jungle_pressure_plate,\
	mat_block_acacia_pressure_plate,\
	mat_block_dark_oak_pressure_plate,\
	mat_block_crimson_pressure_plate,\
	mat_block_warped_pressure_plate

const mat_tag_t mat_block_tag_wooden_pressure_plates_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:wooden_pressure_plates"),
	MAT_BLOCK_TAG_WOODEN_PRESSURE_PLATES
);

#define MAT_BLOCK_TAG_PRESSURE_PLATES \
	mat_block_light_weighted_pressure_plate,\
	mat_block_heavy_weighted_pressure_plate,\
	MAT_BLOCK_TAG_WOODEN_PRESSURE_PLATES,\
	MAT_BLOCK_TAG_STONE_PRESSURE_PLATES

const mat_tag_t mat_block_tag_pressure_plates_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:pressure_plates"),
	MAT_BLOCK_TAG_PRESSURE_PLATES
);

#define MAT_BLOCK_TAG_WALL_POST_OVERRIDE \
	mat_block_torch,\
	mat_block_soul_torch,\
	mat_block_redstone_torch,\
	mat_block_tripwire,\
	MAT_BLOCK_TAG_SIGNS,\
	MAT_BLOCK_TAG_BANNERS,\
	MAT_BLOCK_TAG_PRESSURE_PLATES

const mat_tag_t mat_block_tag_wall_post_override_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:wall_post_override"),
	MAT_BLOCK_TAG_WALL_POST_OVERRIDE
);

#define MAT_BLOCK_TAG_WOODEN_SLABS \
	mat_block_oak_slab,\
	mat_block_spruce_slab,\
	mat_block_birch_slab,\
	mat_block_jungle_slab,\
	mat_block_acacia_slab,\
	mat_block_dark_oak_slab,\
	mat_block_crimson_slab,\
	mat_block_warped_slab

const mat_tag_t mat_block_tag_wooden_slabs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:wooden_slabs"),
	MAT_BLOCK_TAG_WOODEN_SLABS
);

#define MAT_BLOCK_TAG_SLABS \
	MAT_BLOCK_TAG_WOODEN_SLABS,\
	mat_block_stone_slab,\
	mat_block_smooth_stone_slab,\
	mat_block_stone_brick_slab,\
	mat_block_sandstone_slab,\
	mat_block_purpur_slab,\
	mat_block_quartz_slab,\
	mat_block_red_sandstone_slab,\
	mat_block_brick_slab,\
	mat_block_cobblestone_slab,\
	mat_block_nether_brick_slab,\
	mat_block_petrified_oak_slab,\
	mat_block_prismarine_slab,\
	mat_block_prismarine_brick_slab,\
	mat_block_dark_prismarine_slab,\
	mat_block_polished_granite_slab,\
	mat_block_smooth_red_sandstone_slab,\
	mat_block_mossy_stone_brick_slab,\
	mat_block_polished_diorite_slab,\
	mat_block_mossy_cobblestone_slab,\
	mat_block_end_stone_brick_slab,\
	mat_block_smooth_sandstone_slab,\
	mat_block_smooth_quartz_slab,\
	mat_block_granite_slab,\
	mat_block_andesite_slab,\
	mat_block_red_nether_brick_slab,\
	mat_block_polished_andesite_slab,\
	mat_block_diorite_slab,\
	mat_block_cut_sandstone_slab,\
	mat_block_cut_red_sandstone_slab,\
	mat_block_blackstone_slab,\
	mat_block_polished_blackstone_brick_slab,\
	mat_block_polished_blackstone_slab,\
	mat_block_cobbled_deepslate_slab,\
	mat_block_polished_deepslate_slab,\
	mat_block_deepslate_tile_slab,\
	mat_block_deepslate_brick_slab,\
	mat_block_waxed_weathered_cut_copper_slab,\
	mat_block_waxed_exposed_cut_copper_slab,\
	mat_block_waxed_cut_copper_slab,\
	mat_block_oxidized_cut_copper_slab,\
	mat_block_weathered_cut_copper_slab,\
	mat_block_exposed_cut_copper_slab,\
	mat_block_cut_copper_slab,\
	mat_block_waxed_oxidized_cut_copper_slab

const mat_tag_t mat_block_tag_slabs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:slabs"),
	MAT_BLOCK_TAG_SLABS
);

#define MAT_BLOCK_TAG_WOODEN_STAIRS \
	mat_block_oak_stairs,\
	mat_block_spruce_stairs,\
	mat_block_birch_stairs,\
	mat_block_jungle_stairs,\
	mat_block_acacia_stairs,\
	mat_block_dark_oak_stairs,\
	mat_block_crimson_stairs,\
	mat_block_warped_stairs

const mat_tag_t mat_block_tag_wooden_stairs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:wooden_stairs"),
	MAT_BLOCK_TAG_WOODEN_STAIRS
);

#define MAT_BLOCK_TAG_STAIRS \
	MAT_BLOCK_TAG_WOODEN_STAIRS,\
	mat_block_cobblestone_stairs,\
	mat_block_sandstone_stairs,\
	mat_block_nether_brick_stairs,\
	mat_block_stone_brick_stairs,\
	mat_block_brick_stairs,\
	mat_block_purpur_stairs,\
	mat_block_quartz_stairs,\
	mat_block_red_sandstone_stairs,\
	mat_block_prismarine_brick_stairs,\
	mat_block_prismarine_stairs,\
	mat_block_dark_prismarine_stairs,\
	mat_block_polished_granite_stairs,\
	mat_block_smooth_red_sandstone_stairs,\
	mat_block_mossy_stone_brick_stairs,\
	mat_block_polished_diorite_stairs,\
	mat_block_mossy_cobblestone_stairs,\
	mat_block_end_stone_brick_stairs,\
	mat_block_stone_stairs,\
	mat_block_smooth_sandstone_stairs,\
	mat_block_smooth_quartz_stairs,\
	mat_block_granite_stairs,\
	mat_block_andesite_stairs,\
	mat_block_red_nether_brick_stairs,\
	mat_block_polished_andesite_stairs,\
	mat_block_diorite_stairs,\
	mat_block_blackstone_stairs,\
	mat_block_polished_blackstone_brick_stairs,\
	mat_block_polished_blackstone_stairs,\
	mat_block_cobbled_deepslate_stairs,\
	mat_block_polished_deepslate_stairs,\
	mat_block_deepslate_tile_stairs,\
	mat_block_deepslate_brick_stairs,\
	mat_block_oxidized_cut_copper_stairs,\
	mat_block_weathered_cut_copper_stairs,\
	mat_block_exposed_cut_copper_stairs,\
	mat_block_cut_copper_stairs,\
	mat_block_waxed_weathered_cut_copper_stairs,\
	mat_block_waxed_exposed_cut_copper_stairs,\
	mat_block_waxed_cut_copper_stairs,\
	mat_block_waxed_oxidized_cut_copper_stairs

const mat_tag_t mat_block_tag_stairs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:stairs"),
	MAT_BLOCK_TAG_STAIRS
);

#define MAT_BLOCK_TAG_WOODEN_TRAPDOORS \
	mat_block_acacia_trapdoor,\
	mat_block_birch_trapdoor,\
	mat_block_dark_oak_trapdoor,\
	mat_block_jungle_trapdoor,\
	mat_block_oak_trapdoor,\
	mat_block_spruce_trapdoor,\
	mat_block_crimson_trapdoor,\
	mat_block_warped_trapdoor

const mat_tag_t mat_block_tag_wooden_trapdoors_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:wooden_trapdoors"),
	MAT_BLOCK_TAG_WOODEN_TRAPDOORS
);

#define MAT_BLOCK_TAG_TRAPDOORS \
	MAT_BLOCK_TAG_WOODEN_TRAPDOORS,\
	mat_block_iron_trapdoor

const mat_tag_t mat_block_tag_trapdoors_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:trapdoors"),
	MAT_BLOCK_TAG_TRAPDOORS
);

#define MAT_BLOCK_TAG_WOOL \
	mat_block_white_wool,\
	mat_block_orange_wool,\
	mat_block_magenta_wool,\
	mat_block_light_blue_wool,\
	mat_block_yellow_wool,\
	mat_block_lime_wool,\
	mat_block_pink_wool,\
	mat_block_gray_wool,\
	mat_block_light_gray_wool,\
	mat_block_cyan_wool,\
	mat_block_purple_wool,\
	mat_block_blue_wool,\
	mat_block_brown_wool,\
	mat_block_green_wool,\
	mat_block_red_wool,\
	mat_block_black_wool

const mat_tag_t mat_block_tag_wool_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:wool"),
	MAT_BLOCK_TAG_WOOL
);

#define MAT_BLOCK_TAG_OCCLUDES_VIBRATION_SIGNALS \
	MAT_BLOCK_TAG_WOOL

const mat_tag_t mat_block_tag_occludes_vibration_signals_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:occludes_vibration_signals"),
	MAT_BLOCK_TAG_OCCLUDES_VIBRATION_SIGNALS
);

#define MAT_BLOCK_TAG_MINEABLE_AXE \
	mat_block_note_block,\
	mat_block_attached_melon_stem,\
	mat_block_attached_pumpkin_stem,\
	mat_block_azalea,\
	mat_block_bamboo,\
	mat_block_barrel,\
	mat_block_bee_nest,\
	mat_block_beehive,\
	mat_block_beetroots,\
	mat_block_big_dripleaf_stem,\
	mat_block_big_dripleaf,\
	mat_block_bookshelf,\
	mat_block_brown_mushroom_block,\
	mat_block_brown_mushroom,\
	mat_block_campfire,\
	mat_block_carrots,\
	mat_block_cartography_table,\
	mat_block_carved_pumpkin,\
	mat_block_cave_vines_plant,\
	mat_block_cave_vines,\
	mat_block_chest,\
	mat_block_chorus_flower,\
	mat_block_chorus_plant,\
	mat_block_cocoa,\
	mat_block_composter,\
	mat_block_crafting_table,\
	mat_block_crimson_fungus,\
	mat_block_daylight_detector,\
	mat_block_dead_bush,\
	mat_block_fern,\
	mat_block_fletching_table,\
	mat_block_glow_lichen,\
	mat_block_grass,\
	mat_block_hanging_roots,\
	mat_block_jack_o_lantern,\
	mat_block_jukebox,\
	mat_block_ladder,\
	mat_block_large_fern,\
	mat_block_lectern,\
	mat_block_lily_pad,\
	mat_block_loom,\
	mat_block_melon_stem,\
	mat_block_melon,\
	mat_block_mushroom_stem,\
	mat_block_nether_wart,\
	mat_block_potatoes,\
	mat_block_pumpkin_stem,\
	mat_block_pumpkin,\
	mat_block_red_mushroom_block,\
	mat_block_red_mushroom,\
	mat_block_scaffolding,\
	mat_block_small_dripleaf,\
	mat_block_smithing_table,\
	mat_block_soul_campfire,\
	mat_block_spore_blossom,\
	mat_block_sugar_cane,\
	mat_block_sweet_berry_bush,\
	mat_block_tall_grass,\
	mat_block_trapped_chest,\
	mat_block_twisting_vines_plant,\
	mat_block_twisting_vines,\
	mat_block_vine,\
	mat_block_warped_fungus,\
	mat_block_weeping_vines_plant,\
	mat_block_weeping_vines,\
	mat_block_wheat,\
	MAT_BLOCK_TAG_BANNERS,\
	MAT_BLOCK_TAG_FENCE_GATES,\
	MAT_BLOCK_TAG_FLOWERS,\
	MAT_BLOCK_TAG_LOGS,\
	MAT_BLOCK_TAG_PLANKS,\
	MAT_BLOCK_TAG_SAPLINGS,\
	MAT_BLOCK_TAG_SIGNS,\
	MAT_BLOCK_TAG_WOODEN_BUTTONS,\
	MAT_BLOCK_TAG_WOODEN_DOORS,\
	MAT_BLOCK_TAG_WOODEN_FENCES,\
	MAT_BLOCK_TAG_WOODEN_PRESSURE_PLATES,\
	MAT_BLOCK_TAG_WOODEN_SLABS,\
	MAT_BLOCK_TAG_WOODEN_STAIRS,\
	MAT_BLOCK_TAG_WOODEN_TRAPDOORS

const mat_tag_t mat_block_tag_mineable_axe_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:mineable/axe"),
	MAT_BLOCK_TAG_MINEABLE_AXE
);

#define MAT_BLOCK_TAG_MINEABLE_HOE \
	mat_block_nether_wart_block,\
	mat_block_warped_wart_block,\
	mat_block_hay_block,\
	mat_block_dried_kelp_block,\
	mat_block_target,\
	mat_block_shroomlight,\
	mat_block_sponge,\
	mat_block_wet_sponge,\
	mat_block_jungle_leaves,\
	mat_block_oak_leaves,\
	mat_block_spruce_leaves,\
	mat_block_dark_oak_leaves,\
	mat_block_acacia_leaves,\
	mat_block_birch_leaves,\
	mat_block_azalea_leaves,\
	mat_block_flowering_azalea_leaves,\
	mat_block_sculk_sensor,\
	mat_block_moss_block,\
	mat_block_moss_carpet

const mat_tag_t mat_block_tag_mineable_hoe_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:mineable/hoe"),
	MAT_BLOCK_TAG_MINEABLE_HOE
);

#define MAT_BLOCK_TAG_MINEABLE_PICKAXE \
	mat_block_stone,\
	mat_block_granite,\
	mat_block_polished_granite,\
	mat_block_diorite,\
	mat_block_polished_diorite,\
	mat_block_andesite,\
	mat_block_polished_andesite,\
	mat_block_cobblestone,\
	mat_block_gold_ore,\
	mat_block_deepslate_gold_ore,\
	mat_block_iron_ore,\
	mat_block_deepslate_iron_ore,\
	mat_block_coal_ore,\
	mat_block_deepslate_coal_ore,\
	mat_block_nether_gold_ore,\
	mat_block_lapis_ore,\
	mat_block_deepslate_lapis_ore,\
	mat_block_lapis_block,\
	mat_block_dispenser,\
	mat_block_sandstone,\
	mat_block_chiseled_sandstone,\
	mat_block_cut_sandstone,\
	mat_block_gold_block,\
	mat_block_iron_block,\
	mat_block_bricks,\
	mat_block_mossy_cobblestone,\
	mat_block_obsidian,\
	mat_block_spawner,\
	mat_block_diamond_ore,\
	mat_block_deepslate_diamond_ore,\
	mat_block_diamond_block,\
	mat_block_furnace,\
	mat_block_cobblestone_stairs,\
	mat_block_stone_pressure_plate,\
	mat_block_iron_door,\
	mat_block_redstone_ore,\
	mat_block_deepslate_redstone_ore,\
	mat_block_netherrack,\
	mat_block_basalt,\
	mat_block_polished_basalt,\
	mat_block_stone_bricks,\
	mat_block_mossy_stone_bricks,\
	mat_block_cracked_stone_bricks,\
	mat_block_chiseled_stone_bricks,\
	mat_block_iron_bars,\
	mat_block_chain,\
	mat_block_brick_stairs,\
	mat_block_stone_brick_stairs,\
	mat_block_nether_bricks,\
	mat_block_nether_brick_fence,\
	mat_block_nether_brick_stairs,\
	mat_block_enchanting_table,\
	mat_block_brewing_stand,\
	mat_block_end_stone,\
	mat_block_sandstone_stairs,\
	mat_block_emerald_ore,\
	mat_block_deepslate_emerald_ore,\
	mat_block_ender_chest,\
	mat_block_emerald_block,\
	mat_block_light_weighted_pressure_plate,\
	mat_block_heavy_weighted_pressure_plate,\
	mat_block_redstone_block,\
	mat_block_nether_quartz_ore,\
	mat_block_hopper,\
	mat_block_quartz_block,\
	mat_block_chiseled_quartz_block,\
	mat_block_quartz_pillar,\
	mat_block_quartz_stairs,\
	mat_block_dropper,\
	mat_block_white_terracotta,\
	mat_block_orange_terracotta,\
	mat_block_magenta_terracotta,\
	mat_block_light_blue_terracotta,\
	mat_block_yellow_terracotta,\
	mat_block_lime_terracotta,\
	mat_block_pink_terracotta,\
	mat_block_gray_terracotta,\
	mat_block_light_gray_terracotta,\
	mat_block_cyan_terracotta,\
	mat_block_purple_terracotta,\
	mat_block_blue_terracotta,\
	mat_block_brown_terracotta,\
	mat_block_green_terracotta,\
	mat_block_red_terracotta,\
	mat_block_black_terracotta,\
	mat_block_iron_trapdoor,\
	mat_block_prismarine,\
	mat_block_prismarine_bricks,\
	mat_block_dark_prismarine,\
	mat_block_prismarine_stairs,\
	mat_block_prismarine_brick_stairs,\
	mat_block_dark_prismarine_stairs,\
	mat_block_prismarine_slab,\
	mat_block_prismarine_brick_slab,\
	mat_block_dark_prismarine_slab,\
	mat_block_terracotta,\
	mat_block_coal_block,\
	mat_block_red_sandstone,\
	mat_block_chiseled_red_sandstone,\
	mat_block_cut_red_sandstone,\
	mat_block_red_sandstone_stairs,\
	mat_block_stone_slab,\
	mat_block_smooth_stone_slab,\
	mat_block_sandstone_slab,\
	mat_block_cut_sandstone_slab,\
	mat_block_petrified_oak_slab,\
	mat_block_cobblestone_slab,\
	mat_block_brick_slab,\
	mat_block_stone_brick_slab,\
	mat_block_nether_brick_slab,\
	mat_block_quartz_slab,\
	mat_block_red_sandstone_slab,\
	mat_block_cut_red_sandstone_slab,\
	mat_block_purpur_slab,\
	mat_block_smooth_stone,\
	mat_block_smooth_sandstone,\
	mat_block_smooth_quartz,\
	mat_block_smooth_red_sandstone,\
	mat_block_purpur_block,\
	mat_block_purpur_pillar,\
	mat_block_purpur_stairs,\
	mat_block_end_stone_bricks,\
	mat_block_magma_block,\
	mat_block_red_nether_bricks,\
	mat_block_bone_block,\
	mat_block_observer,\
	mat_block_white_glazed_terracotta,\
	mat_block_orange_glazed_terracotta,\
	mat_block_magenta_glazed_terracotta,\
	mat_block_light_blue_glazed_terracotta,\
	mat_block_yellow_glazed_terracotta,\
	mat_block_lime_glazed_terracotta,\
	mat_block_pink_glazed_terracotta,\
	mat_block_gray_glazed_terracotta,\
	mat_block_light_gray_glazed_terracotta,\
	mat_block_cyan_glazed_terracotta,\
	mat_block_purple_glazed_terracotta,\
	mat_block_blue_glazed_terracotta,\
	mat_block_brown_glazed_terracotta,\
	mat_block_green_glazed_terracotta,\
	mat_block_red_glazed_terracotta,\
	mat_block_black_glazed_terracotta,\
	mat_block_white_concrete,\
	mat_block_orange_concrete,\
	mat_block_magenta_concrete,\
	mat_block_light_blue_concrete,\
	mat_block_yellow_concrete,\
	mat_block_lime_concrete,\
	mat_block_pink_concrete,\
	mat_block_gray_concrete,\
	mat_block_light_gray_concrete,\
	mat_block_cyan_concrete,\
	mat_block_purple_concrete,\
	mat_block_blue_concrete,\
	mat_block_brown_concrete,\
	mat_block_green_concrete,\
	mat_block_red_concrete,\
	mat_block_black_concrete,\
	mat_block_dead_tube_coral_block,\
	mat_block_dead_brain_coral_block,\
	mat_block_dead_bubble_coral_block,\
	mat_block_dead_fire_coral_block,\
	mat_block_dead_horn_coral_block,\
	mat_block_tube_coral_block,\
	mat_block_brain_coral_block,\
	mat_block_bubble_coral_block,\
	mat_block_fire_coral_block,\
	mat_block_horn_coral_block,\
	mat_block_dead_tube_coral,\
	mat_block_dead_brain_coral,\
	mat_block_dead_bubble_coral,\
	mat_block_dead_fire_coral,\
	mat_block_dead_horn_coral,\
	mat_block_dead_tube_coral_fan,\
	mat_block_dead_brain_coral_fan,\
	mat_block_dead_bubble_coral_fan,\
	mat_block_dead_fire_coral_fan,\
	mat_block_dead_horn_coral_fan,\
	mat_block_dead_tube_coral_wall_fan,\
	mat_block_dead_brain_coral_wall_fan,\
	mat_block_dead_bubble_coral_wall_fan,\
	mat_block_dead_fire_coral_wall_fan,\
	mat_block_dead_horn_coral_wall_fan,\
	mat_block_polished_granite_stairs,\
	mat_block_smooth_red_sandstone_stairs,\
	mat_block_mossy_stone_brick_stairs,\
	mat_block_polished_diorite_stairs,\
	mat_block_mossy_cobblestone_stairs,\
	mat_block_end_stone_brick_stairs,\
	mat_block_stone_stairs,\
	mat_block_smooth_sandstone_stairs,\
	mat_block_smooth_quartz_stairs,\
	mat_block_granite_stairs,\
	mat_block_andesite_stairs,\
	mat_block_red_nether_brick_stairs,\
	mat_block_polished_andesite_stairs,\
	mat_block_diorite_stairs,\
	mat_block_polished_granite_slab,\
	mat_block_smooth_red_sandstone_slab,\
	mat_block_mossy_stone_brick_slab,\
	mat_block_polished_diorite_slab,\
	mat_block_mossy_cobblestone_slab,\
	mat_block_end_stone_brick_slab,\
	mat_block_smooth_sandstone_slab,\
	mat_block_smooth_quartz_slab,\
	mat_block_granite_slab,\
	mat_block_andesite_slab,\
	mat_block_red_nether_brick_slab,\
	mat_block_polished_andesite_slab,\
	mat_block_diorite_slab,\
	mat_block_smoker,\
	mat_block_blast_furnace,\
	mat_block_grindstone,\
	mat_block_stonecutter,\
	mat_block_bell,\
	mat_block_lantern,\
	mat_block_soul_lantern,\
	mat_block_warped_nylium,\
	mat_block_crimson_nylium,\
	mat_block_netherite_block,\
	mat_block_ancient_debris,\
	mat_block_crying_obsidian,\
	mat_block_respawn_anchor,\
	mat_block_lodestone,\
	mat_block_blackstone,\
	mat_block_blackstone_stairs,\
	mat_block_blackstone_slab,\
	mat_block_polished_blackstone,\
	mat_block_polished_blackstone_bricks,\
	mat_block_cracked_polished_blackstone_bricks,\
	mat_block_chiseled_polished_blackstone,\
	mat_block_polished_blackstone_brick_slab,\
	mat_block_polished_blackstone_brick_stairs,\
	mat_block_gilded_blackstone,\
	mat_block_polished_blackstone_stairs,\
	mat_block_polished_blackstone_slab,\
	mat_block_polished_blackstone_pressure_plate,\
	mat_block_chiseled_nether_bricks,\
	mat_block_cracked_nether_bricks,\
	mat_block_quartz_bricks,\
	mat_block_tuff,\
	mat_block_calcite,\
	mat_block_oxidized_copper,\
	mat_block_weathered_copper,\
	mat_block_exposed_copper,\
	mat_block_copper_block,\
	mat_block_copper_ore,\
	mat_block_deepslate_copper_ore,\
	mat_block_oxidized_cut_copper,\
	mat_block_weathered_cut_copper,\
	mat_block_exposed_cut_copper,\
	mat_block_cut_copper,\
	mat_block_oxidized_cut_copper_stairs,\
	mat_block_weathered_cut_copper_stairs,\
	mat_block_exposed_cut_copper_stairs,\
	mat_block_cut_copper_stairs,\
	mat_block_oxidized_cut_copper_slab,\
	mat_block_weathered_cut_copper_slab,\
	mat_block_exposed_cut_copper_slab,\
	mat_block_cut_copper_slab,\
	mat_block_waxed_copper_block,\
	mat_block_waxed_weathered_copper,\
	mat_block_waxed_exposed_copper,\
	mat_block_waxed_oxidized_copper,\
	mat_block_waxed_oxidized_cut_copper,\
	mat_block_waxed_weathered_cut_copper,\
	mat_block_waxed_exposed_cut_copper,\
	mat_block_waxed_cut_copper,\
	mat_block_waxed_oxidized_cut_copper_stairs,\
	mat_block_waxed_weathered_cut_copper_stairs,\
	mat_block_waxed_exposed_cut_copper_stairs,\
	mat_block_waxed_cut_copper_stairs,\
	mat_block_waxed_oxidized_cut_copper_slab,\
	mat_block_waxed_weathered_cut_copper_slab,\
	mat_block_waxed_exposed_cut_copper_slab,\
	mat_block_waxed_cut_copper_slab,\
	mat_block_lightning_rod,\
	mat_block_pointed_dripstone,\
	mat_block_dripstone_block,\
	mat_block_deepslate,\
	mat_block_cobbled_deepslate,\
	mat_block_cobbled_deepslate_stairs,\
	mat_block_cobbled_deepslate_slab,\
	mat_block_polished_deepslate,\
	mat_block_polished_deepslate_stairs,\
	mat_block_polished_deepslate_slab,\
	mat_block_deepslate_tiles,\
	mat_block_deepslate_tile_stairs,\
	mat_block_deepslate_tile_slab,\
	mat_block_deepslate_bricks,\
	mat_block_deepslate_brick_stairs,\
	mat_block_deepslate_brick_slab,\
	mat_block_chiseled_deepslate,\
	mat_block_cracked_deepslate_bricks,\
	mat_block_cracked_deepslate_tiles,\
	mat_block_smooth_basalt,\
	mat_block_raw_iron_block,\
	mat_block_raw_copper_block,\
	mat_block_raw_gold_block,\
	mat_block_ice,\
	mat_block_packed_ice,\
	mat_block_blue_ice,\
	mat_block_stone_button,\
	mat_block_piston,\
	mat_block_sticky_piston,\
	mat_block_piston_head,\
	mat_block_amethyst_cluster,\
	mat_block_small_amethyst_bud,\
	mat_block_medium_amethyst_bud,\
	mat_block_large_amethyst_bud,\
	mat_block_amethyst_block,\
	mat_block_budding_amethyst,\
	mat_block_infested_cobblestone,\
	mat_block_infested_chiseled_stone_bricks,\
	mat_block_infested_cracked_stone_bricks,\
	mat_block_infested_deepslate,\
	mat_block_infested_stone,\
	mat_block_infested_mossy_stone_bricks,\
	mat_block_infested_stone_bricks,\
	MAT_BLOCK_TAG_WALLS,\
	MAT_BLOCK_TAG_SHULKER_BOXES,\
	MAT_BLOCK_TAG_ANVIL,\
	MAT_BLOCK_TAG_CAULDRONS,\
	MAT_BLOCK_TAG_RAILS

const mat_tag_t mat_block_tag_mineable_pickaxe_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:mineable/pickaxe"),
	MAT_BLOCK_TAG_MINEABLE_PICKAXE
);

#define MAT_BLOCK_TAG_MINEABLE_SHOVEL \
	mat_block_clay,\
	mat_block_dirt,\
	mat_block_coarse_dirt,\
	mat_block_podzol,\
	mat_block_farmland,\
	mat_block_grass_block,\
	mat_block_gravel,\
	mat_block_mycelium,\
	mat_block_sand,\
	mat_block_red_sand,\
	mat_block_snow_block,\
	mat_block_snow,\
	mat_block_soul_sand,\
	mat_block_dirt_path,\
	mat_block_white_concrete_powder,\
	mat_block_orange_concrete_powder,\
	mat_block_magenta_concrete_powder,\
	mat_block_light_blue_concrete_powder,\
	mat_block_yellow_concrete_powder,\
	mat_block_lime_concrete_powder,\
	mat_block_pink_concrete_powder,\
	mat_block_gray_concrete_powder,\
	mat_block_light_gray_concrete_powder,\
	mat_block_cyan_concrete_powder,\
	mat_block_purple_concrete_powder,\
	mat_block_blue_concrete_powder,\
	mat_block_brown_concrete_powder,\
	mat_block_green_concrete_powder,\
	mat_block_red_concrete_powder,\
	mat_block_black_concrete_powder,\
	mat_block_soul_soil,\
	mat_block_rooted_dirt

const mat_tag_t mat_block_tag_mineable_shovel_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:mineable/shovel"),
	MAT_BLOCK_TAG_MINEABLE_SHOVEL
);

#define MAT_BLOCK_TAG_MINEABLE \
	MAT_BLOCK_TAG_MINEABLE_AXE,\
	MAT_BLOCK_TAG_MINEABLE_PICKAXE,\
	MAT_BLOCK_TAG_MINEABLE_HOE,\
	MAT_BLOCK_TAG_MINEABLE_SHOVEL

const mat_tag_t mat_block_tag_mineable_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("motor:mineable"),
	MAT_BLOCK_TAG_MINEABLE
);

#define MAT_BLOCK_TAG_AIR \
	mat_block_air,\
	mat_block_cave_air,\
	mat_block_void_air

const mat_tag_t mat_block_tag_air_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("motor:air"),
	MAT_BLOCK_TAG_AIR
);

#define MAT_BLOCK_TAG_ANIMALS_SPAWNABLE_ON \
	mat_block_grass_block

const mat_tag_t mat_block_tag_animals_spawnable_on_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:animals_spawnable_on"),
	MAT_BLOCK_TAG_ANIMALS_SPAWNABLE_ON
);

#define MAT_BLOCK_TAG_AXOLOTLS_SPAWNABLE_ON \
	mat_block_clay

const mat_tag_t mat_block_tag_axolotls_spawnable_on_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:axolotls_spawnable_on"),
	MAT_BLOCK_TAG_AXOLOTLS_SPAWNABLE_ON
);

#define MAT_BLOCK_TAG_TERRACOTTA \
	mat_block_terracotta,\
	mat_block_red_terracotta,\
	mat_block_blue_terracotta,\
	mat_block_cyan_terracotta,\
	mat_block_gray_terracotta,\
	mat_block_lime_terracotta,\
	mat_block_pink_terracotta,\
	mat_block_black_terracotta,\
	mat_block_brown_terracotta,\
	mat_block_green_terracotta,\
	mat_block_white_terracotta,\
	mat_block_orange_terracotta,\
	mat_block_purple_terracotta,\
	mat_block_yellow_terracotta,\
	mat_block_magenta_terracotta,\
	mat_block_light_blue_terracotta,\
	mat_block_light_gray_terracotta

const mat_tag_t mat_block_tag_terracotta_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:terracotta"),
	MAT_BLOCK_TAG_TERRACOTTA
);

#define MAT_BLOCK_TAG_AZALEA_GROWS_ON \
	MAT_BLOCK_TAG_DIRT,\
	MAT_BLOCK_TAG_SAND,\
	MAT_BLOCK_TAG_TERRACOTTA,\
	mat_block_snow_block,\
	mat_block_powder_snow

const mat_tag_t mat_block_tag_azalea_grows_on_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:azalea_grows_on"),
	MAT_BLOCK_TAG_AZALEA_GROWS_ON
);

#define MAT_BLOCK_TAG_AZALEA_ROOT_REPLACEABLE \
	MAT_BLOCK_TAG_LUSH_GROUND_REPLACEABLE,\
	MAT_BLOCK_TAG_TERRACOTTA,\
	mat_block_red_sand

const mat_tag_t mat_block_tag_azalea_root_replaceable_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:azalea_root_replaceable"),
	MAT_BLOCK_TAG_AZALEA_ROOT_REPLACEABLE
);

#define MAT_BLOCK_TAG_BIG_DRIPLEAF_PLACEABLE \
	MAT_BLOCK_TAG_DIRT,\
	MAT_BLOCK_TAG_SMALL_DRIPLEAF_PLACEABLE,\
	mat_block_farmland

const mat_tag_t mat_block_tag_big_dripleaf_placeable_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:big_dripleaf_placeable"),
	MAT_BLOCK_TAG_BIG_DRIPLEAF_PLACEABLE
);

#define MAT_BLOCK_TAG_FOXES_SPAWNABLE_ON \
	mat_block_grass_block,\
	mat_block_snow,\
	mat_block_snow_block,\
	mat_block_podzol,\
	mat_block_coarse_dirt

const mat_tag_t mat_block_tag_foxes_spawnable_on_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:foxes_spawnable_on"),
	MAT_BLOCK_TAG_FOXES_SPAWNABLE_ON
);

#define MAT_BLOCK_TAG_GOATS_SPAWNABLE_ON \
	mat_block_stone,\
	mat_block_snow,\
	mat_block_snow_block,\
	mat_block_powder_snow,\
	mat_block_packed_ice,\
	mat_block_gravel

const mat_tag_t mat_block_tag_goats_spawnable_on_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:goats_spawnable_on"),
	MAT_BLOCK_TAG_GOATS_SPAWNABLE_ON
);

#define MAT_BLOCK_TAG_MOOSHROOMS_SPAWNABLE_ON \
	mat_block_mycelium

const mat_tag_t mat_block_tag_mooshrooms_spawnable_on_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:mooshrooms_spawnable_on"),
	MAT_BLOCK_TAG_MOOSHROOMS_SPAWNABLE_ON
);

#define MAT_BLOCK_TAG_PARROTS_SPAWNABLE_ON \
	mat_block_grass_block,\
	mat_block_air,\
	MAT_BLOCK_TAG_LEAVES,\
	MAT_BLOCK_TAG_LOGS

const mat_tag_t mat_block_tag_parrots_spawnable_on_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:parrots_spawnable_on"),
	MAT_BLOCK_TAG_PARROTS_SPAWNABLE_ON
);

#define MAT_BLOCK_TAG_POLAR_BEARS_SPAWNABLE_ON_IN_FROZEN_OCEAN \
	mat_block_ice

const mat_tag_t mat_block_tag_polar_bears_spawnable_on_in_frozen_ocean_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:polar_bears_spawnable_on_in_frozen_ocean"),
	MAT_BLOCK_TAG_POLAR_BEARS_SPAWNABLE_ON_IN_FROZEN_OCEAN
);

#define MAT_BLOCK_TAG_RABBITS_SPAWNABLE_ON \
	mat_block_grass_block,\
	mat_block_snow,\
	mat_block_snow_block,\
	mat_block_sand

const mat_tag_t mat_block_tag_rabbits_spawnable_on_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:rabbits_spawnable_on"),
	MAT_BLOCK_TAG_RABBITS_SPAWNABLE_ON
);

#define MAT_BLOCK_TAG_REPLACEABLE_PLANTS \
	mat_block_grass,\
	mat_block_fern,\
	mat_block_dead_bush,\
	mat_block_vine,\
	mat_block_glow_lichen,\
	mat_block_sunflower,\
	mat_block_lilac,\
	mat_block_rose_bush,\
	mat_block_peony,\
	mat_block_tall_grass,\
	mat_block_large_fern,\
	mat_block_hanging_roots

const mat_tag_t mat_block_tag_replaceable_plants_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:replaceable_plants"),
	MAT_BLOCK_TAG_REPLACEABLE_PLANTS
);

#define MAT_BLOCK_TAG_WOLVES_SPAWNABLE_ON \
	mat_block_grass_block,\
	mat_block_snow,\
	mat_block_snow_block

const mat_tag_t mat_block_tag_wolves_spawnable_on_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:wolves_spawnable_on"),
	MAT_BLOCK_TAG_WOLVES_SPAWNABLE_ON
);

const mat_tag_t* mat_block_tags[] = {

	&mat_block_tag_catches_fire_from_lava_d,
	&mat_block_tag_light_filtering_d,
	&mat_block_tag_transparent_d,
	&mat_block_tag_mineable_d,
	&mat_block_tag_needs_d,
	&mat_block_tag_needs_wooden_tool_d,
	&mat_block_tag_air_d,
	&mat_block_tag_mineable_axe_d,
	&mat_block_tag_mineable_hoe_d,
	&mat_block_tag_mineable_pickaxe_d,
	&mat_block_tag_mineable_shovel_d,
	&mat_block_tag_acacia_logs_d,
	&mat_block_tag_anvil_d,
	&mat_block_tag_bamboo_plantable_on_d,
	&mat_block_tag_banners_d,
	&mat_block_tag_base_stone_nether_d,
	&mat_block_tag_base_stone_overworld_d,
	&mat_block_tag_beacon_base_blocks_d,
	&mat_block_tag_beds_d,
	&mat_block_tag_beehives_d,
	&mat_block_tag_bee_growables_d,
	&mat_block_tag_birch_logs_d,
	&mat_block_tag_buttons_d,
	&mat_block_tag_campfires_d,
	&mat_block_tag_candle_cakes_d,
	&mat_block_tag_candles_d,
	&mat_block_tag_carpets_d,
	&mat_block_tag_cauldrons_d,
	&mat_block_tag_cave_vines_d,
	&mat_block_tag_climbable_d,
	&mat_block_tag_coal_ores_d,
	&mat_block_tag_copper_ores_d,
	&mat_block_tag_corals_d,
	&mat_block_tag_coral_blocks_d,
	&mat_block_tag_coral_plants_d,
	&mat_block_tag_crimson_stems_d,
	&mat_block_tag_crops_d,
	&mat_block_tag_crystal_sound_blocks_d,
	&mat_block_tag_dark_oak_logs_d,
	&mat_block_tag_deepslate_ore_replaceables_d,
	&mat_block_tag_diamond_ores_d,
	&mat_block_tag_dirt_d,
	&mat_block_tag_doors_d,
	&mat_block_tag_dragon_immune_d,
	&mat_block_tag_dripstone_replaceable_blocks_d,
	&mat_block_tag_emerald_ores_d,
	&mat_block_tag_enderman_holdable_d,
	&mat_block_tag_features_cannot_replace_d,
	&mat_block_tag_fence_gates_d,
	&mat_block_tag_fences_d,
	&mat_block_tag_fire_d,
	&mat_block_tag_flower_pots_d,
	&mat_block_tag_flowers_d,
	&mat_block_tag_geode_invalid_blocks_d,
	&mat_block_tag_gold_ores_d,
	&mat_block_tag_guarded_by_piglins_d,
	&mat_block_tag_hoglin_repellents_d,
	&mat_block_tag_ice_d,
	&mat_block_tag_impermeable_d,
	&mat_block_tag_infiniburn_end_d,
	&mat_block_tag_infiniburn_nether_d,
	&mat_block_tag_infiniburn_overworld_d,
	&mat_block_tag_inside_step_sound_blocks_d,
	&mat_block_tag_iron_ores_d,
	&mat_block_tag_jungle_logs_d,
	&mat_block_tag_lapis_ores_d,
	&mat_block_tag_lava_pool_stone_cannot_replace_d,
	&mat_block_tag_leaves_d,
	&mat_block_tag_logs_d,
	&mat_block_tag_logs_that_burn_d,
	&mat_block_tag_lush_ground_replaceable_d,
	&mat_block_tag_moss_replaceable_d,
	&mat_block_tag_mushroom_grow_block_d,
	&mat_block_tag_needs_diamond_tool_d,
	&mat_block_tag_needs_iron_tool_d,
	&mat_block_tag_needs_stone_tool_d,
	&mat_block_tag_non_flammable_wood_d,
	&mat_block_tag_nylium_d,
	&mat_block_tag_oak_logs_d,
	&mat_block_tag_occludes_vibration_signals_d,
	&mat_block_tag_piglin_repellents_d,
	&mat_block_tag_planks_d,
	&mat_block_tag_portals_d,
	&mat_block_tag_pressure_plates_d,
	&mat_block_tag_prevent_mob_spawning_inside_d,
	&mat_block_tag_rails_d,
	&mat_block_tag_redstone_ores_d,
	&mat_block_tag_sand_d,
	&mat_block_tag_saplings_d,
	&mat_block_tag_shulker_boxes_d,
	&mat_block_tag_signs_d,
	&mat_block_tag_slabs_d,
	&mat_block_tag_small_dripleaf_placeable_d,
	&mat_block_tag_small_flowers_d,
	&mat_block_tag_snow_d,
	&mat_block_tag_soul_fire_base_blocks_d,
	&mat_block_tag_soul_speed_blocks_d,
	&mat_block_tag_spruce_logs_d,
	&mat_block_tag_stairs_d,
	&mat_block_tag_standing_signs_d,
	&mat_block_tag_stone_bricks_d,
	&mat_block_tag_stone_ore_replaceables_d,
	&mat_block_tag_stone_pressure_plates_d,
	&mat_block_tag_strider_warm_blocks_d,
	&mat_block_tag_tall_flowers_d,
	&mat_block_tag_trapdoors_d,
	&mat_block_tag_underwater_bonemeals_d,
	&mat_block_tag_unstable_bottom_center_d,
	&mat_block_tag_valid_spawn_d,
	&mat_block_tag_walls_d,
	&mat_block_tag_wall_corals_d,
	&mat_block_tag_wall_post_override_d,
	&mat_block_tag_wall_signs_d,
	&mat_block_tag_warped_stems_d,
	&mat_block_tag_wart_blocks_d,
	&mat_block_tag_wither_immune_d,
	&mat_block_tag_wither_summon_base_blocks_d,
	&mat_block_tag_wooden_buttons_d,
	&mat_block_tag_wooden_doors_d,
	&mat_block_tag_wooden_fences_d,
	&mat_block_tag_wooden_pressure_plates_d,
	&mat_block_tag_wooden_slabs_d,
	&mat_block_tag_wooden_stairs_d,
	&mat_block_tag_wooden_trapdoors_d,
	&mat_block_tag_wool_d,
	&mat_block_tag_animals_spawnable_on_d,
	&mat_block_tag_axolotls_spawnable_on_d,
	&mat_block_tag_azalea_grows_on_d,
	&mat_block_tag_azalea_root_replaceable_d,
	&mat_block_tag_big_dripleaf_placeable_d,
	&mat_block_tag_foxes_spawnable_on_d,
	&mat_block_tag_goats_spawnable_on_d,
	&mat_block_tag_mooshrooms_spawnable_on_d,
	&mat_block_tag_parrots_spawnable_on_d,
	&mat_block_tag_polar_bears_spawnable_on_in_frozen_ocean_d,
	&mat_block_tag_rabbits_spawnable_on_d,
	&mat_block_tag_replaceable_plants_d,
	&mat_block_tag_terracotta_d,
	&mat_block_tag_wolves_spawnable_on_d,

};