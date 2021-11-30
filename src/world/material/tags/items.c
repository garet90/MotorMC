#include "tags.h"
#include "../items.h"
#include "../../../util/str_util.h"

#define MAT_ITEM_TAG_ACACIA_LOGS \
	mat_item_acacia_log,\
	mat_item_acacia_wood,\
	mat_item_stripped_acacia_log,\
	mat_item_stripped_acacia_wood

const mat_tag_t mat_item_tag_acacia_logs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:acacia_logs"),
	MAT_ITEM_TAG_ACACIA_LOGS
);

#define MAT_ITEM_TAG_ANVIL \
	mat_item_anvil,\
	mat_item_chipped_anvil,\
	mat_item_damaged_anvil

const mat_tag_t mat_item_tag_anvil_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:anvil"),
	MAT_ITEM_TAG_ANVIL
);

#define MAT_ITEM_TAG_ARROWS \
	mat_item_arrow,\
	mat_item_tipped_arrow,\
	mat_item_spectral_arrow

const mat_tag_t mat_item_tag_arrows_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:arrows"),
	MAT_ITEM_TAG_ARROWS
);

#define MAT_ITEM_TAG_AXOLOTL_TEMPT_ITEMS \
	mat_item_tropical_fish_bucket

const mat_tag_t mat_item_tag_axolotl_tempt_items_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:axolotl_tempt_items"),
	MAT_ITEM_TAG_AXOLOTL_TEMPT_ITEMS
);

#define MAT_ITEM_TAG_BANNERS \
	mat_item_white_banner,\
	mat_item_orange_banner,\
	mat_item_magenta_banner,\
	mat_item_light_blue_banner,\
	mat_item_yellow_banner,\
	mat_item_lime_banner,\
	mat_item_pink_banner,\
	mat_item_gray_banner,\
	mat_item_light_gray_banner,\
	mat_item_cyan_banner,\
	mat_item_purple_banner,\
	mat_item_blue_banner,\
	mat_item_brown_banner,\
	mat_item_green_banner,\
	mat_item_red_banner,\
	mat_item_black_banner

const mat_tag_t mat_item_tag_banners_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:banners"),
	MAT_ITEM_TAG_BANNERS
);

#define MAT_ITEM_TAG_BEACON_PAYMENT_ITEMS \
	mat_item_netherite_ingot,\
	mat_item_emerald,\
	mat_item_diamond,\
	mat_item_gold_ingot,\
	mat_item_iron_ingot

const mat_tag_t mat_item_tag_beacon_payment_items_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:beacon_payment_items"),
	MAT_ITEM_TAG_BEACON_PAYMENT_ITEMS
);

#define MAT_ITEM_TAG_BEDS \
	mat_item_red_bed,\
	mat_item_black_bed,\
	mat_item_blue_bed,\
	mat_item_brown_bed,\
	mat_item_cyan_bed,\
	mat_item_gray_bed,\
	mat_item_green_bed,\
	mat_item_light_blue_bed,\
	mat_item_light_gray_bed,\
	mat_item_lime_bed,\
	mat_item_magenta_bed,\
	mat_item_orange_bed,\
	mat_item_pink_bed,\
	mat_item_purple_bed,\
	mat_item_white_bed,\
	mat_item_yellow_bed

const mat_tag_t mat_item_tag_beds_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:beds"),
	MAT_ITEM_TAG_BEDS
);

#define MAT_ITEM_TAG_BIRCH_LOGS \
	mat_item_birch_log,\
	mat_item_birch_wood,\
	mat_item_stripped_birch_log,\
	mat_item_stripped_birch_wood

const mat_tag_t mat_item_tag_birch_logs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:birch_logs"),
	MAT_ITEM_TAG_BIRCH_LOGS
);

#define MAT_ITEM_TAG_BOATS \
	mat_item_oak_boat,\
	mat_item_spruce_boat,\
	mat_item_birch_boat,\
	mat_item_jungle_boat,\
	mat_item_acacia_boat,\
	mat_item_dark_oak_boat

const mat_tag_t mat_item_tag_boats_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:boats"),
	MAT_ITEM_TAG_BOATS
);

#define MAT_ITEM_TAG_CANDLES \
	mat_item_candle,\
	mat_item_white_candle,\
	mat_item_orange_candle,\
	mat_item_magenta_candle,\
	mat_item_light_blue_candle,\
	mat_item_yellow_candle,\
	mat_item_lime_candle,\
	mat_item_pink_candle,\
	mat_item_gray_candle,\
	mat_item_light_gray_candle,\
	mat_item_cyan_candle,\
	mat_item_purple_candle,\
	mat_item_blue_candle,\
	mat_item_brown_candle,\
	mat_item_green_candle,\
	mat_item_red_candle,\
	mat_item_black_candle

const mat_tag_t mat_item_tag_candles_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:candles"),
	MAT_ITEM_TAG_CANDLES
);

#define MAT_ITEM_TAG_CARPETS \
	mat_item_white_carpet,\
	mat_item_orange_carpet,\
	mat_item_magenta_carpet,\
	mat_item_light_blue_carpet,\
	mat_item_yellow_carpet,\
	mat_item_lime_carpet,\
	mat_item_pink_carpet,\
	mat_item_gray_carpet,\
	mat_item_light_gray_carpet,\
	mat_item_cyan_carpet,\
	mat_item_purple_carpet,\
	mat_item_blue_carpet,\
	mat_item_brown_carpet,\
	mat_item_green_carpet,\
	mat_item_red_carpet,\
	mat_item_black_carpet

const mat_tag_t mat_item_tag_carpets_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:carpets"),
	MAT_ITEM_TAG_CARPETS
);

#define MAT_ITEM_TAG_CLUSTER_MAX_HARVESTABLES \
	mat_item_diamond_pickaxe,\
	mat_item_golden_pickaxe,\
	mat_item_iron_pickaxe,\
	mat_item_netherite_pickaxe,\
	mat_item_stone_pickaxe,\
	mat_item_wooden_pickaxe

const mat_tag_t mat_item_tag_cluster_max_harvestables_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:cluster_max_harvestables"),
	MAT_ITEM_TAG_CLUSTER_MAX_HARVESTABLES
);

#define MAT_ITEM_TAG_COALS \
	mat_item_coal,\
	mat_item_charcoal

const mat_tag_t mat_item_tag_coals_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:coals"),
	MAT_ITEM_TAG_COALS
);

#define MAT_ITEM_TAG_COAL_ORES \
	mat_item_coal_ore,\
	mat_item_deepslate_coal_ore

const mat_tag_t mat_item_tag_coal_ores_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:coal_ores"),
	MAT_ITEM_TAG_COAL_ORES
);

#define MAT_ITEM_TAG_COPPER_ORES \
	mat_item_copper_ore,\
	mat_item_deepslate_copper_ore

const mat_tag_t mat_item_tag_copper_ores_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:copper_ores"),
	MAT_ITEM_TAG_COPPER_ORES
);

#define MAT_ITEM_TAG_CREEPER_DROP_MUSIC_DISCS \
	mat_item_music_disc_13,\
	mat_item_music_disc_cat,\
	mat_item_music_disc_blocks,\
	mat_item_music_disc_chirp,\
	mat_item_music_disc_far,\
	mat_item_music_disc_mall,\
	mat_item_music_disc_mellohi,\
	mat_item_music_disc_stal,\
	mat_item_music_disc_strad,\
	mat_item_music_disc_ward,\
	mat_item_music_disc_11,\
	mat_item_music_disc_wait

const mat_tag_t mat_item_tag_creeper_drop_music_discs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:creeper_drop_music_discs"),
	MAT_ITEM_TAG_CREEPER_DROP_MUSIC_DISCS
);

#define MAT_ITEM_TAG_CRIMSON_STEMS \
	mat_item_crimson_stem,\
	mat_item_stripped_crimson_stem,\
	mat_item_crimson_hyphae,\
	mat_item_stripped_crimson_hyphae

const mat_tag_t mat_item_tag_crimson_stems_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:crimson_stems"),
	MAT_ITEM_TAG_CRIMSON_STEMS
);

#define MAT_ITEM_TAG_DARK_OAK_LOGS \
	mat_item_dark_oak_log,\
	mat_item_dark_oak_wood,\
	mat_item_stripped_dark_oak_log,\
	mat_item_stripped_dark_oak_wood

const mat_tag_t mat_item_tag_dark_oak_logs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:dark_oak_logs"),
	MAT_ITEM_TAG_DARK_OAK_LOGS
);

#define MAT_ITEM_TAG_DIAMOND_ORES \
	mat_item_diamond_ore,\
	mat_item_deepslate_diamond_ore

const mat_tag_t mat_item_tag_diamond_ores_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:diamond_ores"),
	MAT_ITEM_TAG_DIAMOND_ORES
);

#define MAT_ITEM_TAG_EMERALD_ORES \
	mat_item_emerald_ore,\
	mat_item_deepslate_emerald_ore

const mat_tag_t mat_item_tag_emerald_ores_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:emerald_ores"),
	MAT_ITEM_TAG_EMERALD_ORES
);

#define MAT_ITEM_TAG_FISHES \
	mat_item_cod,\
	mat_item_cooked_cod,\
	mat_item_salmon,\
	mat_item_cooked_salmon,\
	mat_item_pufferfish,\
	mat_item_tropical_fish

const mat_tag_t mat_item_tag_fishes_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:fishes"),
	MAT_ITEM_TAG_FISHES
);

#define MAT_ITEM_TAG_FOX_FOOD \
	mat_item_sweet_berries,\
	mat_item_glow_berries

const mat_tag_t mat_item_tag_fox_food_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:fox_food"),
	MAT_ITEM_TAG_FOX_FOOD
);

#define MAT_ITEM_TAG_FREEZE_IMMUNE_WEARABLES \
	mat_item_leather_boots,\
	mat_item_leather_leggings,\
	mat_item_leather_chestplate,\
	mat_item_leather_helmet,\
	mat_item_leather_horse_armor

const mat_tag_t mat_item_tag_freeze_immune_wearables_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:freeze_immune_wearables"),
	MAT_ITEM_TAG_FREEZE_IMMUNE_WEARABLES
);

#define MAT_ITEM_TAG_GOLD_ORES \
	mat_item_gold_ore,\
	mat_item_nether_gold_ore,\
	mat_item_deepslate_gold_ore

const mat_tag_t mat_item_tag_gold_ores_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:gold_ores"),
	MAT_ITEM_TAG_GOLD_ORES
);

#define MAT_ITEM_TAG_IGNORED_BY_PIGLIN_BABIES \
	mat_item_leather

const mat_tag_t mat_item_tag_ignored_by_piglin_babies_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:ignored_by_piglin_babies"),
	MAT_ITEM_TAG_IGNORED_BY_PIGLIN_BABIES
);

#define MAT_ITEM_TAG_IRON_ORES \
	mat_item_iron_ore,\
	mat_item_deepslate_iron_ore

const mat_tag_t mat_item_tag_iron_ores_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:iron_ores"),
	MAT_ITEM_TAG_IRON_ORES
);

#define MAT_ITEM_TAG_JUNGLE_LOGS \
	mat_item_jungle_log,\
	mat_item_jungle_wood,\
	mat_item_stripped_jungle_log,\
	mat_item_stripped_jungle_wood

const mat_tag_t mat_item_tag_jungle_logs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:jungle_logs"),
	MAT_ITEM_TAG_JUNGLE_LOGS
);

#define MAT_ITEM_TAG_LAPIS_ORES \
	mat_item_lapis_ore,\
	mat_item_deepslate_lapis_ore

const mat_tag_t mat_item_tag_lapis_ores_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:lapis_ores"),
	MAT_ITEM_TAG_LAPIS_ORES
);

#define MAT_ITEM_TAG_LEAVES \
	mat_item_jungle_leaves,\
	mat_item_oak_leaves,\
	mat_item_spruce_leaves,\
	mat_item_dark_oak_leaves,\
	mat_item_acacia_leaves,\
	mat_item_birch_leaves,\
	mat_item_azalea_leaves,\
	mat_item_flowering_azalea_leaves

const mat_tag_t mat_item_tag_leaves_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:leaves"),
	MAT_ITEM_TAG_LEAVES
);

#define MAT_ITEM_TAG_LECTERN_BOOKS \
	mat_item_written_book,\
	mat_item_writable_book

const mat_tag_t mat_item_tag_lectern_books_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:lectern_books"),
	MAT_ITEM_TAG_LECTERN_BOOKS
);

#define MAT_ITEM_TAG_MUSIC_DISCS \
	MAT_ITEM_TAG_CREEPER_DROP_MUSIC_DISCS,\
	mat_item_music_disc_pigstep,\
	mat_item_music_disc_otherside

const mat_tag_t mat_item_tag_music_discs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:music_discs"),
	MAT_ITEM_TAG_MUSIC_DISCS
);

#define MAT_ITEM_TAG_NON_FLAMMABLE_WOOD \
	mat_item_warped_stem,\
	mat_item_stripped_warped_stem,\
	mat_item_warped_hyphae,\
	mat_item_stripped_warped_hyphae,\
	mat_item_crimson_stem,\
	mat_item_stripped_crimson_stem,\
	mat_item_crimson_hyphae,\
	mat_item_stripped_crimson_hyphae,\
	mat_item_crimson_planks,\
	mat_item_warped_planks,\
	mat_item_crimson_slab,\
	mat_item_warped_slab,\
	mat_item_crimson_pressure_plate,\
	mat_item_warped_pressure_plate,\
	mat_item_crimson_fence,\
	mat_item_warped_fence,\
	mat_item_crimson_trapdoor,\
	mat_item_warped_trapdoor,\
	mat_item_crimson_fence_gate,\
	mat_item_warped_fence_gate,\
	mat_item_crimson_stairs,\
	mat_item_warped_stairs,\
	mat_item_crimson_button,\
	mat_item_warped_button,\
	mat_item_crimson_door,\
	mat_item_warped_door,\
	mat_item_crimson_sign,\
	mat_item_warped_sign,

const mat_tag_t mat_item_tag_non_flammable_wood_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:non_flammable_wood"),
	MAT_ITEM_TAG_NON_FLAMMABLE_WOOD
);

#define MAT_ITEM_TAG_OAK_LOGS \
	mat_item_oak_log,\
	mat_item_oak_wood,\
	mat_item_stripped_oak_log,\
	mat_item_stripped_oak_wood

const mat_tag_t mat_item_tag_oak_logs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:oak_logs"),
	MAT_ITEM_TAG_OAK_LOGS
);

#define MAT_ITEM_TAG_PIGLIN_FOOD \
	mat_item_porkchop,\
	mat_item_cooked_porkchop

const mat_tag_t mat_item_tag_piglin_food_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:piglin_food"),
	MAT_ITEM_TAG_PIGLIN_FOOD
);

#define MAT_ITEM_TAG_PIGLIN_LOVED \
	MAT_ITEM_TAG_GOLD_ORES,\
	mat_item_gold_block,\
	mat_item_gilded_blackstone,\
	mat_item_light_weighted_pressure_plate,\
	mat_item_gold_ingot,\
	mat_item_bell,\
	mat_item_clock,\
	mat_item_golden_carrot,\
	mat_item_glistering_melon_slice,\
	mat_item_golden_apple,\
	mat_item_enchanted_golden_apple,\
	mat_item_golden_helmet,\
	mat_item_golden_chestplate,\
	mat_item_golden_leggings,\
	mat_item_golden_boots,\
	mat_item_golden_horse_armor,\
	mat_item_golden_sword,\
	mat_item_golden_pickaxe,\
	mat_item_golden_shovel,\
	mat_item_golden_axe,\
	mat_item_golden_hoe,\
	mat_item_raw_gold,\
	mat_item_raw_gold_block,

const mat_tag_t mat_item_tag_piglin_loved_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:piglin_loved"),
	MAT_ITEM_TAG_PIGLIN_LOVED
);

#define MAT_ITEM_TAG_PIGLIN_REPELLENTS \
	mat_item_soul_torch,\
	mat_item_soul_lantern,\
	mat_item_soul_campfire

const mat_tag_t mat_item_tag_piglin_repellents_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:piglin_repellents"),
	MAT_ITEM_TAG_PIGLIN_REPELLENTS
);

#define MAT_ITEM_TAG_PLANKS \
	mat_item_oak_planks,\
	mat_item_spruce_planks,\
	mat_item_birch_planks,\
	mat_item_jungle_planks,\
	mat_item_acacia_planks,\
	mat_item_dark_oak_planks,\
	mat_item_crimson_planks,\
	mat_item_warped_planks

const mat_tag_t mat_item_tag_planks_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:planks"),
	MAT_ITEM_TAG_PLANKS
);

#define MAT_ITEM_TAG_RAILS \
	mat_item_rail,\
	mat_item_powered_rail,\
	mat_item_detector_rail,\
	mat_item_activator_rail

const mat_tag_t mat_item_tag_rails_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:rails"),
	MAT_ITEM_TAG_RAILS
);

#define MAT_ITEM_TAG_REDSTONE_ORES \
	mat_item_redstone_ore,\
	mat_item_deepslate_redstone_ore

const mat_tag_t mat_item_tag_redstone_ores_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:redstone_ores"),
	MAT_ITEM_TAG_REDSTONE_ORES
);

#define MAT_ITEM_TAG_SAND \
	mat_item_sand,\
	mat_item_red_sand

const mat_tag_t mat_item_tag_sand_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:sand"),
	MAT_ITEM_TAG_SAND
);

#define MAT_ITEM_TAG_SAPLINGS \
	mat_item_oak_sapling,\
	mat_item_spruce_sapling,\
	mat_item_birch_sapling,\
	mat_item_jungle_sapling,\
	mat_item_acacia_sapling,\
	mat_item_dark_oak_sapling,\
	mat_item_azalea,\
	mat_item_flowering_azalea,

const mat_tag_t mat_item_tag_saplings_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:saplings"),
	MAT_ITEM_TAG_SAPLINGS
);

#define MAT_ITEM_TAG_SIGNS \
	mat_item_oak_sign,\
	mat_item_spruce_sign,\
	mat_item_birch_sign,\
	mat_item_acacia_sign,\
	mat_item_jungle_sign,\
	mat_item_dark_oak_sign,\
	mat_item_crimson_sign,\
	mat_item_warped_sign

const mat_tag_t mat_item_tag_signs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:signs"),
	MAT_ITEM_TAG_SIGNS
);

#define MAT_ITEM_TAG_SMALL_FLOWERS \
	mat_item_dandelion,\
	mat_item_poppy,\
	mat_item_blue_orchid,\
	mat_item_allium,\
	mat_item_azure_bluet,\
	mat_item_red_tulip,\
	mat_item_orange_tulip,\
	mat_item_white_tulip,\
	mat_item_pink_tulip,\
	mat_item_oxeye_daisy,\
	mat_item_cornflower,\
	mat_item_lily_of_the_valley,\
	mat_item_wither_rose

const mat_tag_t mat_item_tag_small_flowers_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:small_flowers"),
	MAT_ITEM_TAG_SMALL_FLOWERS
);

#define MAT_ITEM_TAG_SOUL_FIRE_BASE_BLOCKS \
	mat_item_soul_sand,\
	mat_item_soul_soil

const mat_tag_t mat_item_tag_soul_fire_base_blocks_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:soul_fire_base_blocks"),
	MAT_ITEM_TAG_SOUL_FIRE_BASE_BLOCKS
);

#define MAT_ITEM_TAG_SPRUCE_LOGS \
	mat_item_spruce_log,\
	mat_item_spruce_wood,\
	mat_item_stripped_spruce_log,\
	mat_item_stripped_spruce_wood

const mat_tag_t mat_item_tag_spruce_logs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:spruce_logs"),
	MAT_ITEM_TAG_SPRUCE_LOGS
);

#define MAT_ITEM_TAG_LOGS_THAT_BURN \
	MAT_ITEM_TAG_DARK_OAK_LOGS,\
	MAT_ITEM_TAG_OAK_LOGS,\
	MAT_ITEM_TAG_ACACIA_LOGS,\
	MAT_ITEM_TAG_BIRCH_LOGS,\
	MAT_ITEM_TAG_JUNGLE_LOGS,\
	MAT_ITEM_TAG_SPRUCE_LOGS

const mat_tag_t mat_item_tag_logs_that_burn_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:logs_that_burn"),
	MAT_ITEM_TAG_LOGS_THAT_BURN
);

#define MAT_ITEM_TAG_STONE_BRICKS \
	mat_item_stone_bricks,\
	mat_item_mossy_stone_bricks,\
	mat_item_cracked_stone_bricks,\
	mat_item_chiseled_stone_bricks

const mat_tag_t mat_item_tag_stone_bricks_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:stone_bricks"),
	MAT_ITEM_TAG_STONE_BRICKS
);

#define MAT_ITEM_TAG_STONE_CRAFTING_MATERIALS \
	mat_item_cobblestone,\
	mat_item_blackstone,\
	mat_item_cobbled_deepslate

const mat_tag_t mat_item_tag_stone_crafting_materials_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:stone_crafting_materials"),
	MAT_ITEM_TAG_STONE_CRAFTING_MATERIALS
);

#define MAT_ITEM_TAG_STONE_TOOL_MATERIALS \
	mat_item_cobblestone,\
	mat_item_blackstone,\
	mat_item_cobbled_deepslate

const mat_tag_t mat_item_tag_stone_tool_materials_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:stone_tool_materials"),
	MAT_ITEM_TAG_STONE_TOOL_MATERIALS
);

#define MAT_ITEM_TAG_TALL_FLOWERS \
	mat_item_sunflower,\
	mat_item_lilac,\
	mat_item_peony,\
	mat_item_rose_bush


const mat_tag_t mat_item_tag_tall_flowers_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:tall_flowers"),
	MAT_ITEM_TAG_TALL_FLOWERS
);

#define MAT_ITEM_TAG_FLOWERS \
	MAT_ITEM_TAG_SMALL_FLOWERS,\
	MAT_ITEM_TAG_TALL_FLOWERS,\
	mat_item_flowering_azalea_leaves,\
	mat_item_flowering_azalea

const mat_tag_t mat_item_tag_flowers_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:flowers"),
	MAT_ITEM_TAG_FLOWERS
);

#define MAT_ITEM_TAG_WALLS \
	mat_item_cobblestone_wall,\
	mat_item_mossy_cobblestone_wall,\
	mat_item_brick_wall,\
	mat_item_prismarine_wall,\
	mat_item_red_sandstone_wall,\
	mat_item_mossy_stone_brick_wall,\
	mat_item_granite_wall,\
	mat_item_stone_brick_wall,\
	mat_item_nether_brick_wall,\
	mat_item_andesite_wall,\
	mat_item_red_nether_brick_wall,\
	mat_item_sandstone_wall,\
	mat_item_end_stone_brick_wall,\
	mat_item_diorite_wall,\
	mat_item_blackstone_wall,\
	mat_item_polished_blackstone_brick_wall,\
	mat_item_polished_blackstone_wall,\
	mat_item_cobbled_deepslate_wall,\
	mat_item_polished_deepslate_wall,\
	mat_item_deepslate_tile_wall,\
	mat_item_deepslate_brick_wall

const mat_tag_t mat_item_tag_walls_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:walls"),
	MAT_ITEM_TAG_WALLS
);

#define MAT_ITEM_TAG_WARPED_STEMS \
	mat_item_warped_stem,\
	mat_item_stripped_warped_stem,\
	mat_item_warped_hyphae,\
	mat_item_stripped_warped_hyphae

const mat_tag_t mat_item_tag_warped_stems_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:warped_stems"),
	MAT_ITEM_TAG_WARPED_STEMS
);

#define MAT_ITEM_TAG_LOGS \
	MAT_ITEM_TAG_LOGS_THAT_BURN,\
	MAT_ITEM_TAG_CRIMSON_STEMS,\
	MAT_ITEM_TAG_WARPED_STEMS

const mat_tag_t mat_item_tag_logs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:logs"),
	MAT_ITEM_TAG_LOGS
);

#define MAT_ITEM_TAG_WOODEN_BUTTONS \
	mat_item_oak_button,\
	mat_item_spruce_button,\
	mat_item_birch_button,\
	mat_item_jungle_button,\
	mat_item_acacia_button,\
	mat_item_dark_oak_button,\
	mat_item_crimson_button,\
	mat_item_warped_button

const mat_tag_t mat_item_tag_wooden_buttons_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:wooden_buttons"),
	MAT_ITEM_TAG_WOODEN_BUTTONS
);

#define MAT_ITEM_TAG_BUTTONS \
	MAT_ITEM_TAG_WOODEN_BUTTONS,\
	mat_item_stone_button,\
	mat_item_polished_blackstone_button

const mat_tag_t mat_item_tag_buttons_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:buttons"),
	MAT_ITEM_TAG_BUTTONS
);

#define MAT_ITEM_TAG_WOODEN_DOORS \
	mat_item_oak_door,\
	mat_item_spruce_door,\
	mat_item_birch_door,\
	mat_item_jungle_door,\
	mat_item_acacia_door,\
	mat_item_dark_oak_door,\
	mat_item_crimson_door,\
	mat_item_warped_door

const mat_tag_t mat_item_tag_wooden_doors_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:wooden_doors"),
	MAT_ITEM_TAG_WOODEN_DOORS
);

#define MAT_ITEM_TAG_DOORS \
	MAT_ITEM_TAG_WOODEN_DOORS,\
	mat_item_iron_door

const mat_tag_t mat_item_tag_doors_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:doors"),
	MAT_ITEM_TAG_DOORS
);

#define MAT_ITEM_TAG_WOODEN_FENCES \
	mat_item_oak_fence,\
	mat_item_acacia_fence,\
	mat_item_dark_oak_fence,\
	mat_item_spruce_fence,\
	mat_item_birch_fence,\
	mat_item_jungle_fence,\
	mat_item_crimson_fence,\
	mat_item_warped_fence

const mat_tag_t mat_item_tag_wooden_fences_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:wooden_fences"),
	MAT_ITEM_TAG_WOODEN_FENCES
);

#define MAT_ITEM_TAG_FENCES \
	MAT_ITEM_TAG_WOODEN_FENCES,\
	mat_item_nether_brick_fence

const mat_tag_t mat_item_tag_fences_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:fences"),
	MAT_ITEM_TAG_FENCES
);

#define MAT_ITEM_TAG_WOODEN_PRESSURE_PLATES \
	mat_item_oak_pressure_plate,\
	mat_item_spruce_pressure_plate,\
	mat_item_birch_pressure_plate,\
	mat_item_jungle_pressure_plate,\
	mat_item_acacia_pressure_plate,\
	mat_item_dark_oak_pressure_plate,\
	mat_item_crimson_pressure_plate,\
	mat_item_warped_pressure_plate

const mat_tag_t mat_item_tag_wooden_pressure_plates_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:wooden_pressure_plates"),
	MAT_ITEM_TAG_WOODEN_PRESSURE_PLATES
);

#define MAT_ITEM_TAG_WOODEN_SLABS \
	mat_item_oak_slab,\
	mat_item_spruce_slab,\
	mat_item_birch_slab,\
	mat_item_jungle_slab,\
	mat_item_acacia_slab,\
	mat_item_dark_oak_slab,\
	mat_item_crimson_slab,\
	mat_item_warped_slab

const mat_tag_t mat_item_tag_wooden_slabs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:wooden_slabs"),
	MAT_ITEM_TAG_WOODEN_SLABS
);

#define MAT_ITEM_TAG_SLABS \
	MAT_ITEM_TAG_WOODEN_SLABS,\
	mat_item_stone_slab,\
	mat_item_smooth_stone_slab,\
	mat_item_stone_brick_slab,\
	mat_item_sandstone_slab,\
	mat_item_purpur_slab,\
	mat_item_quartz_slab,\
	mat_item_red_sandstone_slab,\
	mat_item_brick_slab,\
	mat_item_cobblestone_slab,\
	mat_item_nether_brick_slab,\
	mat_item_petrified_oak_slab,\
	mat_item_prismarine_slab,\
	mat_item_prismarine_brick_slab,\
	mat_item_dark_prismarine_slab,\
	mat_item_polished_granite_slab,\
	mat_item_smooth_red_sandstone_slab,\
	mat_item_mossy_stone_brick_slab,\
	mat_item_polished_diorite_slab,\
	mat_item_mossy_cobblestone_slab,\
	mat_item_end_stone_brick_slab,\
	mat_item_smooth_sandstone_slab,\
	mat_item_smooth_quartz_slab,\
	mat_item_granite_slab,\
	mat_item_andesite_slab,\
	mat_item_red_nether_brick_slab,\
	mat_item_polished_andesite_slab,\
	mat_item_diorite_slab,\
	mat_item_cut_sandstone_slab,\
	mat_item_cut_red_sandstone_slab,\
	mat_item_blackstone_slab,\
	mat_item_polished_blackstone_brick_slab,\
	mat_item_polished_blackstone_slab,\
	mat_item_cobbled_deepslate_slab,\
	mat_item_polished_deepslate_slab,\
	mat_item_deepslate_tile_slab,\
	mat_item_deepslate_brick_slab,\
	mat_item_waxed_weathered_cut_copper_slab,\
	mat_item_waxed_exposed_cut_copper_slab,\
	mat_item_waxed_cut_copper_slab,\
	mat_item_oxidized_cut_copper_slab,\
	mat_item_weathered_cut_copper_slab,\
	mat_item_exposed_cut_copper_slab,\
	mat_item_cut_copper_slab,\
	mat_item_waxed_oxidized_cut_copper_slab

const mat_tag_t mat_item_tag_slabs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:slabs"),
	MAT_ITEM_TAG_SLABS
);

#define MAT_ITEM_TAG_WOODEN_STAIRS \
	mat_item_oak_stairs,\
	mat_item_spruce_stairs,\
	mat_item_birch_stairs,\
	mat_item_jungle_stairs,\
	mat_item_acacia_stairs,\
	mat_item_dark_oak_stairs,\
	mat_item_crimson_stairs,\
	mat_item_warped_stairs

const mat_tag_t mat_item_tag_wooden_stairs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:wooden_stairs"),
	MAT_ITEM_TAG_WOODEN_STAIRS
);

#define MAT_ITEM_TAG_STAIRS \
	MAT_ITEM_TAG_WOODEN_STAIRS,\
	mat_item_cobblestone_stairs,\
	mat_item_sandstone_stairs,\
	mat_item_nether_brick_stairs,\
	mat_item_stone_brick_stairs,\
	mat_item_brick_stairs,\
	mat_item_purpur_stairs,\
	mat_item_quartz_stairs,\
	mat_item_red_sandstone_stairs,\
	mat_item_prismarine_brick_stairs,\
	mat_item_prismarine_stairs,\
	mat_item_dark_prismarine_stairs,\
	mat_item_polished_granite_stairs,\
	mat_item_smooth_red_sandstone_stairs,\
	mat_item_mossy_stone_brick_stairs,\
	mat_item_polished_diorite_stairs,\
	mat_item_mossy_cobblestone_stairs,\
	mat_item_end_stone_brick_stairs,\
	mat_item_stone_stairs,\
	mat_item_smooth_sandstone_stairs,\
	mat_item_smooth_quartz_stairs,\
	mat_item_granite_stairs,\
	mat_item_andesite_stairs,\
	mat_item_red_nether_brick_stairs,\
	mat_item_polished_andesite_stairs,\
	mat_item_diorite_stairs,\
	mat_item_blackstone_stairs,\
	mat_item_polished_blackstone_brick_stairs,\
	mat_item_polished_blackstone_stairs,\
	mat_item_cobbled_deepslate_stairs,\
	mat_item_polished_deepslate_stairs,\
	mat_item_deepslate_tile_stairs,\
	mat_item_deepslate_brick_stairs,\
	mat_item_oxidized_cut_copper_stairs,\
	mat_item_weathered_cut_copper_stairs,\
	mat_item_exposed_cut_copper_stairs,\
	mat_item_cut_copper_stairs,\
	mat_item_waxed_weathered_cut_copper_stairs,\
	mat_item_waxed_exposed_cut_copper_stairs,\
	mat_item_waxed_cut_copper_stairs,\
	mat_item_waxed_oxidized_cut_copper_stairs

const mat_tag_t mat_item_tag_stairs_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:stairs"),
	MAT_ITEM_TAG_STAIRS
);

#define MAT_ITEM_TAG_WOODEN_TRAPDOORS \
	mat_item_acacia_trapdoor,\
	mat_item_birch_trapdoor,\
	mat_item_dark_oak_trapdoor,\
	mat_item_jungle_trapdoor,\
	mat_item_oak_trapdoor,\
	mat_item_spruce_trapdoor,\
	mat_item_crimson_trapdoor,\
	mat_item_warped_trapdoor

const mat_tag_t mat_item_tag_wooden_trapdoors_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:wooden_trapdoors"),
	MAT_ITEM_TAG_WOODEN_TRAPDOORS
);

#define MAT_ITEM_TAG_TRAPDOORS \
	MAT_ITEM_TAG_WOODEN_TRAPDOORS,\
	mat_item_iron_trapdoor

const mat_tag_t mat_item_tag_trapdoors_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:trapdoors"),
	MAT_ITEM_TAG_TRAPDOORS
);

#define MAT_ITEM_TAG_WOOL \
	mat_item_white_wool,\
	mat_item_orange_wool,\
	mat_item_magenta_wool,\
	mat_item_light_blue_wool,\
	mat_item_yellow_wool,\
	mat_item_lime_wool,\
	mat_item_pink_wool,\
	mat_item_gray_wool,\
	mat_item_light_gray_wool,\
	mat_item_cyan_wool,\
	mat_item_purple_wool,\
	mat_item_blue_wool,\
	mat_item_brown_wool,\
	mat_item_green_wool,\
	mat_item_red_wool,\
	mat_item_black_wool

const mat_tag_t mat_item_tag_wool_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:wool"),
	MAT_ITEM_TAG_WOOL
);

#define MAT_ITEM_TAG_OCCLUDES_VIBRATION_SIGNALS \
	MAT_ITEM_TAG_WOOL

const mat_tag_t mat_item_tag_occludes_vibration_signals_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:occludes_vibration_signals"),
	MAT_ITEM_TAG_OCCLUDES_VIBRATION_SIGNALS
);

#define MAT_ITEM_TAG_DIRT \
	mat_item_dirt,\
	mat_item_grass_block,\
	mat_item_podzol,\
	mat_item_coarse_dirt,\
	mat_item_mycelium,\
	mat_item_rooted_dirt,\
	mat_item_moss_block

const mat_tag_t mat_item_tag_dirt_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:dirt"),
	MAT_ITEM_TAG_DIRT
);

#define MAT_ITEM_TAG_TERRACOTTA \
	mat_item_terracotta,\
	mat_item_red_terracotta,\
	mat_item_blue_terracotta,\
	mat_item_cyan_terracotta,\
	mat_item_gray_terracotta,\
	mat_item_lime_terracotta,\
	mat_item_pink_terracotta,\
	mat_item_black_terracotta,\
	mat_item_brown_terracotta,\
	mat_item_green_terracotta,\
	mat_item_white_terracotta,\
	mat_item_orange_terracotta,\
	mat_item_purple_terracotta,\
	mat_item_yellow_terracotta,\
	mat_item_magenta_terracotta,\
	mat_item_light_blue_terracotta,\
	mat_item_light_gray_terracotta

const mat_tag_t mat_item_tag_terracotta_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:terracotta"),
	MAT_ITEM_TAG_TERRACOTTA
);

const mat_tag_t* mat_item_tags[] = {

	&mat_item_tag_banners_d,
	&mat_item_tag_soul_fire_base_blocks_d,
	&mat_item_tag_stone_crafting_materials_d,
	&mat_item_tag_wooden_fences_d,
	&mat_item_tag_piglin_repellents_d,
	&mat_item_tag_beacon_payment_items_d,
	&mat_item_tag_wooden_slabs_d,
	&mat_item_tag_coal_ores_d,
	&mat_item_tag_occludes_vibration_signals_d,
	&mat_item_tag_small_flowers_d,
	&mat_item_tag_wooden_trapdoors_d,
	&mat_item_tag_jungle_logs_d,
	&mat_item_tag_lectern_books_d,
	&mat_item_tag_wooden_stairs_d,
	&mat_item_tag_spruce_logs_d,
	&mat_item_tag_signs_d,
	&mat_item_tag_axolotl_tempt_items_d,
	&mat_item_tag_carpets_d,
	&mat_item_tag_wool_d,
	&mat_item_tag_wooden_buttons_d,
	&mat_item_tag_stairs_d,
	&mat_item_tag_fishes_d,
	&mat_item_tag_logs_d,
	&mat_item_tag_stone_bricks_d,
	&mat_item_tag_creeper_drop_music_discs_d,
	&mat_item_tag_arrows_d,
	&mat_item_tag_slabs_d,
	&mat_item_tag_wooden_doors_d,
	&mat_item_tag_warped_stems_d,
	&mat_item_tag_emerald_ores_d,
	&mat_item_tag_trapdoors_d,
	&mat_item_tag_redstone_ores_d,
	&mat_item_tag_crimson_stems_d,
	&mat_item_tag_ignored_by_piglin_babies_d,
	&mat_item_tag_buttons_d,
	&mat_item_tag_flowers_d,
	&mat_item_tag_stone_tool_materials_d,
	&mat_item_tag_planks_d,
	&mat_item_tag_fox_food_d,
	&mat_item_tag_boats_d,
	&mat_item_tag_dark_oak_logs_d,
	&mat_item_tag_rails_d,
	&mat_item_tag_diamond_ores_d,
	&mat_item_tag_non_flammable_wood_d,
	&mat_item_tag_leaves_d,
	&mat_item_tag_walls_d,
	&mat_item_tag_coals_d,
	&mat_item_tag_piglin_food_d,
	&mat_item_tag_wooden_pressure_plates_d,
	&mat_item_tag_acacia_logs_d,
	&mat_item_tag_anvil_d,
	&mat_item_tag_piglin_loved_d,
	&mat_item_tag_candles_d,
	&mat_item_tag_music_discs_d,
	&mat_item_tag_birch_logs_d,
	&mat_item_tag_tall_flowers_d,
	&mat_item_tag_lapis_ores_d,
	&mat_item_tag_sand_d,
	&mat_item_tag_copper_ores_d,
	&mat_item_tag_gold_ores_d,
	&mat_item_tag_freeze_immune_wearables_d,
	&mat_item_tag_logs_that_burn_d,
	&mat_item_tag_fences_d,
	&mat_item_tag_saplings_d,
	&mat_item_tag_beds_d,
	&mat_item_tag_iron_ores_d,
	&mat_item_tag_oak_logs_d,
	&mat_item_tag_doors_d,
	&mat_item_tag_cluster_max_harvestables_d,
	&mat_item_tag_dirt_d,
	&mat_item_tag_terracotta_d,
};