#include "items.h"

const mat_item_t mat_item_air_d = {
	.block = mat_block_air,
};
const mat_item_t mat_item_stone_d = {
	.block = mat_block_stone,
};
const mat_item_t mat_item_granite_d = {
	.block = mat_block_granite,
};
const mat_item_t mat_item_polished_granite_d = {
	.block = mat_block_polished_granite,
};
const mat_item_t mat_item_diorite_d = {
	.block = mat_block_diorite,
};
const mat_item_t mat_item_polished_diorite_d = {
	.block = mat_block_polished_diorite,
};
const mat_item_t mat_item_andesite_d = {
	.block = mat_block_andesite,
};
const mat_item_t mat_item_polished_andesite_d = {
	.block = mat_block_polished_andesite,
};
const mat_item_t mat_item_deepslate_d = {
	.block = mat_block_deepslate,
};
const mat_item_t mat_item_cobbled_deepslate_d = {
	.block = mat_block_cobbled_deepslate,
	.stone_crafting_materials = true,
	.stone_tool_materials = true,
};
const mat_item_t mat_item_polished_deepslate_d = {
	.block = mat_block_polished_deepslate,
};
const mat_item_t mat_item_calcite_d = {
	.block = mat_block_calcite,
};
const mat_item_t mat_item_tuff_d = {
	.block = mat_block_tuff,
};
const mat_item_t mat_item_dripstone_block_d = {
	.block = mat_block_dripstone_block,
};
const mat_item_t mat_item_grass_block_d = {
	.block = mat_block_grass_block,
	.dirt = true,
};
const mat_item_t mat_item_dirt_d = {
	.block = mat_block_dirt,
	.dirt = true,
};
const mat_item_t mat_item_coarse_dirt_d = {
	.block = mat_block_coarse_dirt,
	.dirt = true,
};
const mat_item_t mat_item_podzol_d = {
	.block = mat_block_podzol,
	.dirt = true,
};
const mat_item_t mat_item_rooted_dirt_d = {
	.block = mat_block_rooted_dirt,
	.dirt = true,
};
const mat_item_t mat_item_crimson_nylium_d = {
	.block = mat_block_crimson_nylium,
};
const mat_item_t mat_item_warped_nylium_d = {
	.block = mat_block_warped_nylium,
};
const mat_item_t mat_item_cobblestone_d = {
	.block = mat_block_cobblestone,
	.stone_crafting_materials = true,
	.stone_tool_materials = true,
};
const mat_item_t mat_item_oak_planks_d = {
	.block = mat_block_oak_planks,
	.planks = true,
};
const mat_item_t mat_item_spruce_planks_d = {
	.block = mat_block_spruce_planks,
	.planks = true,
};
const mat_item_t mat_item_birch_planks_d = {
	.block = mat_block_birch_planks,
	.planks = true,
};
const mat_item_t mat_item_jungle_planks_d = {
	.block = mat_block_jungle_planks,
	.planks = true,
};
const mat_item_t mat_item_acacia_planks_d = {
	.block = mat_block_acacia_planks,
	.planks = true,
};
const mat_item_t mat_item_dark_oak_planks_d = {
	.block = mat_block_dark_oak_planks,
	.planks = true,
};
const mat_item_t mat_item_crimson_planks_d = {
	.block = mat_block_crimson_planks,
	.non_flammable_wood = true,
	.planks = true,
};
const mat_item_t mat_item_warped_planks_d = {
	.block = mat_block_warped_planks,
	.non_flammable_wood = true,
	.planks = true,
};
const mat_item_t mat_item_oak_sapling_d = {
	.block = mat_block_oak_sapling,
	.saplings = true,
};
const mat_item_t mat_item_spruce_sapling_d = {
	.block = mat_block_spruce_sapling,
	.saplings = true,
};
const mat_item_t mat_item_birch_sapling_d = {
	.block = mat_block_birch_sapling,
	.saplings = true,
};
const mat_item_t mat_item_jungle_sapling_d = {
	.block = mat_block_jungle_sapling,
	.saplings = true,
};
const mat_item_t mat_item_acacia_sapling_d = {
	.block = mat_block_acacia_sapling,
	.saplings = true,
};
const mat_item_t mat_item_dark_oak_sapling_d = {
	.block = mat_block_dark_oak_sapling,
	.saplings = true,
};
const mat_item_t mat_item_bedrock_d = {
	.block = mat_block_bedrock,
};
const mat_item_t mat_item_sand_d = {
	.block = mat_block_sand,
	.sand = true,
};
const mat_item_t mat_item_red_sand_d = {
	.block = mat_block_red_sand,
	.sand = true,
};
const mat_item_t mat_item_gravel_d = {
	.block = mat_block_gravel,
};
const mat_item_t mat_item_coal_ore_d = {
	.block = mat_block_coal_ore,
	.coal_ores = true,
};
const mat_item_t mat_item_deepslate_coal_ore_d = {
	.block = mat_block_deepslate_coal_ore,
	.coal_ores = true,
};
const mat_item_t mat_item_iron_ore_d = {
	.block = mat_block_iron_ore,
	.iron_ores = true,
};
const mat_item_t mat_item_deepslate_iron_ore_d = {
	.block = mat_block_deepslate_iron_ore,
	.iron_ores = true,
};
const mat_item_t mat_item_copper_ore_d = {
	.block = mat_block_copper_ore,
	.copper_ores = true,
};
const mat_item_t mat_item_deepslate_copper_ore_d = {
	.block = mat_block_deepslate_copper_ore,
	.copper_ores = true,
};
const mat_item_t mat_item_gold_ore_d = {
	.block = mat_block_gold_ore,
	.gold_ores = true,
	.piglin_loved = true,
};
const mat_item_t mat_item_deepslate_gold_ore_d = {
	.block = mat_block_deepslate_gold_ore,
	.gold_ores = true,
	.piglin_loved = true,
};
const mat_item_t mat_item_redstone_ore_d = {
	.block = mat_block_redstone_ore,
	.redstone_ores = true,
};
const mat_item_t mat_item_deepslate_redstone_ore_d = {
	.block = mat_block_deepslate_redstone_ore,
	.redstone_ores = true,
};
const mat_item_t mat_item_emerald_ore_d = {
	.block = mat_block_emerald_ore,
	.emerald_ores = true,
};
const mat_item_t mat_item_deepslate_emerald_ore_d = {
	.block = mat_block_deepslate_emerald_ore,
	.emerald_ores = true,
};
const mat_item_t mat_item_lapis_ore_d = {
	.block = mat_block_lapis_ore,
	.lapis_ores = true,
};
const mat_item_t mat_item_deepslate_lapis_ore_d = {
	.block = mat_block_deepslate_lapis_ore,
	.lapis_ores = true,
};
const mat_item_t mat_item_diamond_ore_d = {
	.block = mat_block_diamond_ore,
	.diamond_ores = true,
};
const mat_item_t mat_item_deepslate_diamond_ore_d = {
	.block = mat_block_deepslate_diamond_ore,
	.diamond_ores = true,
};
const mat_item_t mat_item_nether_gold_ore_d = {
	.block = mat_block_nether_gold_ore,
	.gold_ores = true,
	.piglin_loved = true,
};
const mat_item_t mat_item_nether_quartz_ore_d = {
	.block = mat_block_nether_quartz_ore,
};
const mat_item_t mat_item_ancient_debris_d = {
	.block = mat_block_ancient_debris,
};
const mat_item_t mat_item_coal_block_d = {
	.block = mat_block_coal_block,
};
const mat_item_t mat_item_raw_iron_block_d = {
	.block = mat_block_raw_iron_block,
};
const mat_item_t mat_item_raw_copper_block_d = {
	.block = mat_block_raw_copper_block,
};
const mat_item_t mat_item_raw_gold_block_d = {
	.block = mat_block_raw_gold_block,
	.piglin_loved = true,
};
const mat_item_t mat_item_amethyst_block_d = {
	.block = mat_block_amethyst_block,
};
const mat_item_t mat_item_budding_amethyst_d = {
	.block = mat_block_budding_amethyst,
};
const mat_item_t mat_item_iron_block_d = {
	.block = mat_block_iron_block,
};
const mat_item_t mat_item_copper_block_d = {
	.block = mat_block_copper_block,
};
const mat_item_t mat_item_gold_block_d = {
	.block = mat_block_gold_block,
	.piglin_loved = true,
};
const mat_item_t mat_item_diamond_block_d = {
	.block = mat_block_diamond_block,
};
const mat_item_t mat_item_netherite_block_d = {
	.block = mat_block_netherite_block,
};
const mat_item_t mat_item_exposed_copper_d = {
	.block = mat_block_exposed_copper,
};
const mat_item_t mat_item_weathered_copper_d = {
	.block = mat_block_weathered_copper,
};
const mat_item_t mat_item_oxidized_copper_d = {
	.block = mat_block_oxidized_copper,
};
const mat_item_t mat_item_cut_copper_d = {
	.block = mat_block_cut_copper,
};
const mat_item_t mat_item_exposed_cut_copper_d = {
	.block = mat_block_exposed_cut_copper,
};
const mat_item_t mat_item_weathered_cut_copper_d = {
	.block = mat_block_weathered_cut_copper,
};
const mat_item_t mat_item_oxidized_cut_copper_d = {
	.block = mat_block_oxidized_cut_copper,
};
const mat_item_t mat_item_cut_copper_stairs_d = {
	.block = mat_block_cut_copper_stairs,
	.stairs = true,
};
const mat_item_t mat_item_exposed_cut_copper_stairs_d = {
	.block = mat_block_exposed_cut_copper_stairs,
	.stairs = true,
};
const mat_item_t mat_item_weathered_cut_copper_stairs_d = {
	.block = mat_block_weathered_cut_copper_stairs,
	.stairs = true,
};
const mat_item_t mat_item_oxidized_cut_copper_stairs_d = {
	.block = mat_block_oxidized_cut_copper_stairs,
	.stairs = true,
};
const mat_item_t mat_item_cut_copper_slab_d = {
	.block = mat_block_cut_copper_slab,
	.slabs = true,
};
const mat_item_t mat_item_exposed_cut_copper_slab_d = {
	.block = mat_block_exposed_cut_copper_slab,
	.slabs = true,
};
const mat_item_t mat_item_weathered_cut_copper_slab_d = {
	.block = mat_block_weathered_cut_copper_slab,
	.slabs = true,
};
const mat_item_t mat_item_oxidized_cut_copper_slab_d = {
	.block = mat_block_oxidized_cut_copper_slab,
	.slabs = true,
};
const mat_item_t mat_item_waxed_copper_block_d = {
	.block = mat_block_waxed_copper_block,
};
const mat_item_t mat_item_waxed_exposed_copper_d = {
	.block = mat_block_waxed_exposed_copper,
};
const mat_item_t mat_item_waxed_weathered_copper_d = {
	.block = mat_block_waxed_weathered_copper,
};
const mat_item_t mat_item_waxed_oxidized_copper_d = {
	.block = mat_block_waxed_oxidized_copper,
};
const mat_item_t mat_item_waxed_cut_copper_d = {
	.block = mat_block_waxed_cut_copper,
};
const mat_item_t mat_item_waxed_exposed_cut_copper_d = {
	.block = mat_block_waxed_exposed_cut_copper,
};
const mat_item_t mat_item_waxed_weathered_cut_copper_d = {
	.block = mat_block_waxed_weathered_cut_copper,
};
const mat_item_t mat_item_waxed_oxidized_cut_copper_d = {
	.block = mat_block_waxed_oxidized_cut_copper,
};
const mat_item_t mat_item_waxed_cut_copper_stairs_d = {
	.block = mat_block_waxed_cut_copper_stairs,
	.stairs = true,
};
const mat_item_t mat_item_waxed_exposed_cut_copper_stairs_d = {
	.block = mat_block_waxed_exposed_cut_copper_stairs,
	.stairs = true,
};
const mat_item_t mat_item_waxed_weathered_cut_copper_stairs_d = {
	.block = mat_block_waxed_weathered_cut_copper_stairs,
	.stairs = true,
};
const mat_item_t mat_item_waxed_oxidized_cut_copper_stairs_d = {
	.block = mat_block_waxed_oxidized_cut_copper_stairs,
	.stairs = true,
};
const mat_item_t mat_item_waxed_cut_copper_slab_d = {
	.block = mat_block_waxed_cut_copper_slab,
	.slabs = true,
};
const mat_item_t mat_item_waxed_exposed_cut_copper_slab_d = {
	.block = mat_block_waxed_exposed_cut_copper_slab,
	.slabs = true,
};
const mat_item_t mat_item_waxed_weathered_cut_copper_slab_d = {
	.block = mat_block_waxed_weathered_cut_copper_slab,
	.slabs = true,
};
const mat_item_t mat_item_waxed_oxidized_cut_copper_slab_d = {
	.block = mat_block_waxed_oxidized_cut_copper_slab,
	.slabs = true,
};
const mat_item_t mat_item_oak_log_d = {
	.block = mat_block_oak_log,
	.logs = true,
	.logs_that_burn = true,
	.oak_logs = true,
};
const mat_item_t mat_item_spruce_log_d = {
	.block = mat_block_spruce_log,
	.logs = true,
	.logs_that_burn = true,
	.spruce_logs = true,
};
const mat_item_t mat_item_birch_log_d = {
	.block = mat_block_birch_log,
	.birch_logs = true,
	.logs = true,
	.logs_that_burn = true,
};
const mat_item_t mat_item_jungle_log_d = {
	.block = mat_block_jungle_log,
	.jungle_logs = true,
	.logs = true,
	.logs_that_burn = true,
};
const mat_item_t mat_item_acacia_log_d = {
	.block = mat_block_acacia_log,
	.acacia_logs = true,
	.logs = true,
	.logs_that_burn = true,
};
const mat_item_t mat_item_dark_oak_log_d = {
	.block = mat_block_dark_oak_log,
	.dark_oak_logs = true,
	.logs = true,
	.logs_that_burn = true,
};
const mat_item_t mat_item_crimson_stem_d = {
	.block = mat_block_crimson_stem,
	.crimson_stems = true,
	.logs = true,
	.non_flammable_wood = true,
};
const mat_item_t mat_item_warped_stem_d = {
	.block = mat_block_warped_stem,
	.logs = true,
	.non_flammable_wood = true,
	.warped_stems = true,
};
const mat_item_t mat_item_stripped_oak_log_d = {
	.block = mat_block_stripped_oak_log,
	.logs = true,
	.logs_that_burn = true,
	.oak_logs = true,
};
const mat_item_t mat_item_stripped_spruce_log_d = {
	.block = mat_block_stripped_spruce_log,
	.logs = true,
	.logs_that_burn = true,
	.spruce_logs = true,
};
const mat_item_t mat_item_stripped_birch_log_d = {
	.block = mat_block_stripped_birch_log,
	.birch_logs = true,
	.logs = true,
	.logs_that_burn = true,
};
const mat_item_t mat_item_stripped_jungle_log_d = {
	.block = mat_block_stripped_jungle_log,
	.jungle_logs = true,
	.logs = true,
	.logs_that_burn = true,
};
const mat_item_t mat_item_stripped_acacia_log_d = {
	.block = mat_block_stripped_acacia_log,
	.acacia_logs = true,
	.logs = true,
	.logs_that_burn = true,
};
const mat_item_t mat_item_stripped_dark_oak_log_d = {
	.block = mat_block_stripped_dark_oak_log,
	.dark_oak_logs = true,
	.logs = true,
	.logs_that_burn = true,
};
const mat_item_t mat_item_stripped_crimson_stem_d = {
	.block = mat_block_stripped_crimson_stem,
	.crimson_stems = true,
	.logs = true,
	.non_flammable_wood = true,
};
const mat_item_t mat_item_stripped_warped_stem_d = {
	.block = mat_block_stripped_warped_stem,
	.logs = true,
	.non_flammable_wood = true,
	.warped_stems = true,
};
const mat_item_t mat_item_stripped_oak_wood_d = {
	.block = mat_block_stripped_oak_wood,
	.logs = true,
	.logs_that_burn = true,
	.oak_logs = true,
};
const mat_item_t mat_item_stripped_spruce_wood_d = {
	.block = mat_block_stripped_spruce_wood,
	.logs = true,
	.logs_that_burn = true,
	.spruce_logs = true,
};
const mat_item_t mat_item_stripped_birch_wood_d = {
	.block = mat_block_stripped_birch_wood,
	.birch_logs = true,
	.logs = true,
	.logs_that_burn = true,
};
const mat_item_t mat_item_stripped_jungle_wood_d = {
	.block = mat_block_stripped_jungle_wood,
	.jungle_logs = true,
	.logs = true,
	.logs_that_burn = true,
};
const mat_item_t mat_item_stripped_acacia_wood_d = {
	.block = mat_block_stripped_acacia_wood,
	.acacia_logs = true,
	.logs = true,
	.logs_that_burn = true,
};
const mat_item_t mat_item_stripped_dark_oak_wood_d = {
	.block = mat_block_stripped_dark_oak_wood,
	.dark_oak_logs = true,
	.logs = true,
	.logs_that_burn = true,
};
const mat_item_t mat_item_stripped_crimson_hyphae_d = {
	.block = mat_block_stripped_crimson_hyphae,
	.crimson_stems = true,
	.logs = true,
	.non_flammable_wood = true,
};
const mat_item_t mat_item_stripped_warped_hyphae_d = {
	.block = mat_block_stripped_warped_hyphae,
	.logs = true,
	.non_flammable_wood = true,
	.warped_stems = true,
};
const mat_item_t mat_item_oak_wood_d = {
	.block = mat_block_oak_wood,
	.logs = true,
	.logs_that_burn = true,
	.oak_logs = true,
};
const mat_item_t mat_item_spruce_wood_d = {
	.block = mat_block_spruce_wood,
	.logs = true,
	.logs_that_burn = true,
	.spruce_logs = true,
};
const mat_item_t mat_item_birch_wood_d = {
	.block = mat_block_birch_wood,
	.birch_logs = true,
	.logs = true,
	.logs_that_burn = true,
};
const mat_item_t mat_item_jungle_wood_d = {
	.block = mat_block_jungle_wood,
	.jungle_logs = true,
	.logs = true,
	.logs_that_burn = true,
};
const mat_item_t mat_item_acacia_wood_d = {
	.block = mat_block_acacia_wood,
	.acacia_logs = true,
	.logs = true,
	.logs_that_burn = true,
};
const mat_item_t mat_item_dark_oak_wood_d = {
	.block = mat_block_dark_oak_wood,
	.dark_oak_logs = true,
	.logs = true,
	.logs_that_burn = true,
};
const mat_item_t mat_item_crimson_hyphae_d = {
	.block = mat_block_crimson_hyphae,
	.crimson_stems = true,
	.logs = true,
	.non_flammable_wood = true,
};
const mat_item_t mat_item_warped_hyphae_d = {
	.block = mat_block_warped_hyphae,
	.logs = true,
	.non_flammable_wood = true,
	.warped_stems = true,
};
const mat_item_t mat_item_oak_leaves_d = {
	.block = mat_block_oak_leaves,
	.leaves = true,
};
const mat_item_t mat_item_spruce_leaves_d = {
	.block = mat_block_spruce_leaves,
	.leaves = true,
};
const mat_item_t mat_item_birch_leaves_d = {
	.block = mat_block_birch_leaves,
	.leaves = true,
};
const mat_item_t mat_item_jungle_leaves_d = {
	.block = mat_block_jungle_leaves,
	.leaves = true,
};
const mat_item_t mat_item_acacia_leaves_d = {
	.block = mat_block_acacia_leaves,
	.leaves = true,
};
const mat_item_t mat_item_dark_oak_leaves_d = {
	.block = mat_block_dark_oak_leaves,
	.leaves = true,
};
const mat_item_t mat_item_azalea_leaves_d = {
	.block = mat_block_azalea_leaves,
	.leaves = true,
};
const mat_item_t mat_item_flowering_azalea_leaves_d = {
	.block = mat_block_flowering_azalea_leaves,
	.flowers = true,
	.leaves = true,
};
const mat_item_t mat_item_sponge_d = {
	.block = mat_block_sponge,
};
const mat_item_t mat_item_wet_sponge_d = {
	.block = mat_block_wet_sponge,
};
const mat_item_t mat_item_glass_d = {
	.block = mat_block_glass,
};
const mat_item_t mat_item_tinted_glass_d = {
	.block = mat_block_tinted_glass,
};
const mat_item_t mat_item_lapis_block_d = {
	.block = mat_block_lapis_block,
};
const mat_item_t mat_item_sandstone_d = {
	.block = mat_block_sandstone,
};
const mat_item_t mat_item_chiseled_sandstone_d = {
	.block = mat_block_chiseled_sandstone,
};
const mat_item_t mat_item_cut_sandstone_d = {
	.block = mat_block_cut_sandstone,
};
const mat_item_t mat_item_cobweb_d = {
	.block = mat_block_cobweb,
};
const mat_item_t mat_item_grass_d = {
	.block = mat_block_grass,
};
const mat_item_t mat_item_fern_d = {
	.block = mat_block_fern,
};
const mat_item_t mat_item_azalea_d = {
	.block = mat_block_azalea,
	.saplings = true,
};
const mat_item_t mat_item_flowering_azalea_d = {
	.block = mat_block_flowering_azalea,
	.flowers = true,
	.saplings = true,
};
const mat_item_t mat_item_dead_bush_d = {
	.block = mat_block_dead_bush,
};
const mat_item_t mat_item_seagrass_d = {
	.block = mat_block_seagrass,
};
const mat_item_t mat_item_sea_pickle_d = {
	.block = mat_block_sea_pickle,
};
const mat_item_t mat_item_white_wool_d = {
	.block = mat_block_white_wool,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_item_t mat_item_orange_wool_d = {
	.block = mat_block_orange_wool,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_item_t mat_item_magenta_wool_d = {
	.block = mat_block_magenta_wool,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_item_t mat_item_light_blue_wool_d = {
	.block = mat_block_light_blue_wool,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_item_t mat_item_yellow_wool_d = {
	.block = mat_block_yellow_wool,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_item_t mat_item_lime_wool_d = {
	.block = mat_block_lime_wool,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_item_t mat_item_pink_wool_d = {
	.block = mat_block_pink_wool,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_item_t mat_item_gray_wool_d = {
	.block = mat_block_gray_wool,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_item_t mat_item_light_gray_wool_d = {
	.block = mat_block_light_gray_wool,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_item_t mat_item_cyan_wool_d = {
	.block = mat_block_cyan_wool,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_item_t mat_item_purple_wool_d = {
	.block = mat_block_purple_wool,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_item_t mat_item_blue_wool_d = {
	.block = mat_block_blue_wool,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_item_t mat_item_brown_wool_d = {
	.block = mat_block_brown_wool,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_item_t mat_item_green_wool_d = {
	.block = mat_block_green_wool,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_item_t mat_item_red_wool_d = {
	.block = mat_block_red_wool,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_item_t mat_item_black_wool_d = {
	.block = mat_block_black_wool,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_item_t mat_item_dandelion_d = {
	.block = mat_block_dandelion,
	.flowers = true,
	.small_flowers = true,
};
const mat_item_t mat_item_poppy_d = {
	.block = mat_block_poppy,
	.flowers = true,
	.small_flowers = true,
};
const mat_item_t mat_item_blue_orchid_d = {
	.block = mat_block_blue_orchid,
	.flowers = true,
	.small_flowers = true,
};
const mat_item_t mat_item_allium_d = {
	.block = mat_block_allium,
	.flowers = true,
	.small_flowers = true,
};
const mat_item_t mat_item_azure_bluet_d = {
	.block = mat_block_azure_bluet,
	.flowers = true,
	.small_flowers = true,
};
const mat_item_t mat_item_red_tulip_d = {
	.block = mat_block_red_tulip,
	.flowers = true,
	.small_flowers = true,
};
const mat_item_t mat_item_orange_tulip_d = {
	.block = mat_block_orange_tulip,
	.flowers = true,
	.small_flowers = true,
};
const mat_item_t mat_item_white_tulip_d = {
	.block = mat_block_white_tulip,
	.flowers = true,
	.small_flowers = true,
};
const mat_item_t mat_item_pink_tulip_d = {
	.block = mat_block_pink_tulip,
	.flowers = true,
	.small_flowers = true,
};
const mat_item_t mat_item_oxeye_daisy_d = {
	.block = mat_block_oxeye_daisy,
	.flowers = true,
	.small_flowers = true,
};
const mat_item_t mat_item_cornflower_d = {
	.block = mat_block_cornflower,
	.flowers = true,
	.small_flowers = true,
};
const mat_item_t mat_item_lily_of_the_valley_d = {
	.block = mat_block_lily_of_the_valley,
	.flowers = true,
	.small_flowers = true,
};
const mat_item_t mat_item_wither_rose_d = {
	.block = mat_block_wither_rose,
	.flowers = true,
	.small_flowers = true,
};
const mat_item_t mat_item_spore_blossom_d = {
	.block = mat_block_spore_blossom,
};
const mat_item_t mat_item_brown_mushroom_d = {
	.block = mat_block_brown_mushroom,
};
const mat_item_t mat_item_red_mushroom_d = {
	.block = mat_block_red_mushroom,
};
const mat_item_t mat_item_crimson_fungus_d = {
	.block = mat_block_crimson_fungus,
};
const mat_item_t mat_item_warped_fungus_d = {
	.block = mat_block_warped_fungus,
};
const mat_item_t mat_item_crimson_roots_d = {
	.block = mat_block_crimson_roots,
};
const mat_item_t mat_item_warped_roots_d = {
	.block = mat_block_warped_roots,
};
const mat_item_t mat_item_nether_sprouts_d = {
	.block = mat_block_nether_sprouts,
};
const mat_item_t mat_item_weeping_vines_d = {
	.block = mat_block_weeping_vines,
};
const mat_item_t mat_item_twisting_vines_d = {
	.block = mat_block_twisting_vines,
};
const mat_item_t mat_item_sugar_cane_d = {
	.block = mat_block_sugar_cane,
};
const mat_item_t mat_item_kelp_d = {
	.block = mat_block_kelp,
};
const mat_item_t mat_item_moss_carpet_d = {
	.block = mat_block_moss_carpet,
};
const mat_item_t mat_item_moss_block_d = {
	.block = mat_block_moss_block,
	.dirt = true,
};
const mat_item_t mat_item_hanging_roots_d = {
	.block = mat_block_hanging_roots,
};
const mat_item_t mat_item_big_dripleaf_d = {
	.block = mat_block_big_dripleaf,
};
const mat_item_t mat_item_small_dripleaf_d = {
	.block = mat_block_small_dripleaf,
};
const mat_item_t mat_item_bamboo_d = {
	.block = mat_block_bamboo,
};
const mat_item_t mat_item_oak_slab_d = {
	.block = mat_block_oak_slab,
	.slabs = true,
	.wooden_slabs = true,
};
const mat_item_t mat_item_spruce_slab_d = {
	.block = mat_block_spruce_slab,
	.slabs = true,
	.wooden_slabs = true,
};
const mat_item_t mat_item_birch_slab_d = {
	.block = mat_block_birch_slab,
	.slabs = true,
	.wooden_slabs = true,
};
const mat_item_t mat_item_jungle_slab_d = {
	.block = mat_block_jungle_slab,
	.slabs = true,
	.wooden_slabs = true,
};
const mat_item_t mat_item_acacia_slab_d = {
	.block = mat_block_acacia_slab,
	.slabs = true,
	.wooden_slabs = true,
};
const mat_item_t mat_item_dark_oak_slab_d = {
	.block = mat_block_dark_oak_slab,
	.slabs = true,
	.wooden_slabs = true,
};
const mat_item_t mat_item_crimson_slab_d = {
	.block = mat_block_crimson_slab,
	.non_flammable_wood = true,
	.slabs = true,
	.wooden_slabs = true,
};
const mat_item_t mat_item_warped_slab_d = {
	.block = mat_block_warped_slab,
	.non_flammable_wood = true,
	.slabs = true,
	.wooden_slabs = true,
};
const mat_item_t mat_item_stone_slab_d = {
	.block = mat_block_stone_slab,
	.slabs = true,
};
const mat_item_t mat_item_smooth_stone_slab_d = {
	.block = mat_block_smooth_stone_slab,
	.slabs = true,
};
const mat_item_t mat_item_sandstone_slab_d = {
	.block = mat_block_sandstone_slab,
	.slabs = true,
};
const mat_item_t mat_item_cut_sandstone_slab_d = {
	.block = mat_block_cut_sandstone_slab,
	.slabs = true,
};
const mat_item_t mat_item_petrified_oak_slab_d = {
	.block = mat_block_petrified_oak_slab,
	.slabs = true,
};
const mat_item_t mat_item_cobblestone_slab_d = {
	.block = mat_block_cobblestone_slab,
	.slabs = true,
};
const mat_item_t mat_item_brick_slab_d = {
	.block = mat_block_brick_slab,
	.slabs = true,
};
const mat_item_t mat_item_stone_brick_slab_d = {
	.block = mat_block_stone_brick_slab,
	.slabs = true,
};
const mat_item_t mat_item_nether_brick_slab_d = {
	.block = mat_block_nether_brick_slab,
	.slabs = true,
};
const mat_item_t mat_item_quartz_slab_d = {
	.block = mat_block_quartz_slab,
	.slabs = true,
};
const mat_item_t mat_item_red_sandstone_slab_d = {
	.block = mat_block_red_sandstone_slab,
	.slabs = true,
};
const mat_item_t mat_item_cut_red_sandstone_slab_d = {
	.block = mat_block_cut_red_sandstone_slab,
	.slabs = true,
};
const mat_item_t mat_item_purpur_slab_d = {
	.block = mat_block_purpur_slab,
	.slabs = true,
};
const mat_item_t mat_item_prismarine_slab_d = {
	.block = mat_block_prismarine_slab,
	.slabs = true,
};
const mat_item_t mat_item_prismarine_brick_slab_d = {
	.block = mat_block_prismarine_brick_slab,
	.slabs = true,
};
const mat_item_t mat_item_dark_prismarine_slab_d = {
	.block = mat_block_dark_prismarine_slab,
	.slabs = true,
};
const mat_item_t mat_item_smooth_quartz_d = {
	.block = mat_block_smooth_quartz,
};
const mat_item_t mat_item_smooth_red_sandstone_d = {
	.block = mat_block_smooth_red_sandstone,
};
const mat_item_t mat_item_smooth_sandstone_d = {
	.block = mat_block_smooth_sandstone,
};
const mat_item_t mat_item_smooth_stone_d = {
	.block = mat_block_smooth_stone,
};
const mat_item_t mat_item_bricks_d = {
	.block = mat_block_bricks,
};
const mat_item_t mat_item_bookshelf_d = {
	.block = mat_block_bookshelf,
};
const mat_item_t mat_item_mossy_cobblestone_d = {
	.block = mat_block_mossy_cobblestone,
};
const mat_item_t mat_item_obsidian_d = {
	.block = mat_block_obsidian,
};
const mat_item_t mat_item_torch_d = {
	.block = mat_block_torch,
};
const mat_item_t mat_item_end_rod_d = {
	.block = mat_block_end_rod,
};
const mat_item_t mat_item_chorus_plant_d = {
	.block = mat_block_chorus_plant,
};
const mat_item_t mat_item_chorus_flower_d = {
	.block = mat_block_chorus_flower,
};
const mat_item_t mat_item_purpur_block_d = {
	.block = mat_block_purpur_block,
};
const mat_item_t mat_item_purpur_pillar_d = {
	.block = mat_block_purpur_pillar,
};
const mat_item_t mat_item_purpur_stairs_d = {
	.block = mat_block_purpur_stairs,
	.stairs = true,
};
const mat_item_t mat_item_spawner_d = {
	.block = mat_block_spawner,
};
const mat_item_t mat_item_oak_stairs_d = {
	.block = mat_block_oak_stairs,
	.stairs = true,
	.wooden_stairs = true,
};
const mat_item_t mat_item_chest_d = {
	.block = mat_block_chest,
};
const mat_item_t mat_item_crafting_table_d = {
	.block = mat_block_crafting_table,
};
const mat_item_t mat_item_farmland_d = {
	.block = mat_block_farmland,
};
const mat_item_t mat_item_furnace_d = {
	.block = mat_block_furnace,
};
const mat_item_t mat_item_ladder_d = {
	.block = mat_block_ladder,
};
const mat_item_t mat_item_cobblestone_stairs_d = {
	.block = mat_block_cobblestone_stairs,
	.stairs = true,
};
const mat_item_t mat_item_snow_d = {
	.block = mat_block_snow,
};
const mat_item_t mat_item_ice_d = {
	.block = mat_block_ice,
};
const mat_item_t mat_item_snow_block_d = {
	.block = mat_block_snow_block,
};
const mat_item_t mat_item_cactus_d = {
	.block = mat_block_cactus,
};
const mat_item_t mat_item_clay_d = {
	.block = mat_block_clay,
};
const mat_item_t mat_item_jukebox_d = {
	.block = mat_block_jukebox,
};
const mat_item_t mat_item_oak_fence_d = {
	.block = mat_block_oak_fence,
	.fences = true,
	.wooden_fences = true,
};
const mat_item_t mat_item_spruce_fence_d = {
	.block = mat_block_spruce_fence,
	.fences = true,
	.wooden_fences = true,
};
const mat_item_t mat_item_birch_fence_d = {
	.block = mat_block_birch_fence,
	.fences = true,
	.wooden_fences = true,
};
const mat_item_t mat_item_jungle_fence_d = {
	.block = mat_block_jungle_fence,
	.fences = true,
	.wooden_fences = true,
};
const mat_item_t mat_item_acacia_fence_d = {
	.block = mat_block_acacia_fence,
	.fences = true,
	.wooden_fences = true,
};
const mat_item_t mat_item_dark_oak_fence_d = {
	.block = mat_block_dark_oak_fence,
	.fences = true,
	.wooden_fences = true,
};
const mat_item_t mat_item_crimson_fence_d = {
	.block = mat_block_crimson_fence,
	.fences = true,
	.non_flammable_wood = true,
	.wooden_fences = true,
};
const mat_item_t mat_item_warped_fence_d = {
	.block = mat_block_warped_fence,
	.fences = true,
	.non_flammable_wood = true,
	.wooden_fences = true,
};
const mat_item_t mat_item_pumpkin_d = {
	.block = mat_block_pumpkin,
};
const mat_item_t mat_item_carved_pumpkin_d = {
	.block = mat_block_carved_pumpkin,
};
const mat_item_t mat_item_jack_o_lantern_d = {
	.block = mat_block_jack_o_lantern,
};
const mat_item_t mat_item_netherrack_d = {
	.block = mat_block_netherrack,
};
const mat_item_t mat_item_soul_sand_d = {
	.block = mat_block_soul_sand,
	.soul_fire_base_blocks = true,
};
const mat_item_t mat_item_soul_soil_d = {
	.block = mat_block_soul_soil,
	.soul_fire_base_blocks = true,
};
const mat_item_t mat_item_basalt_d = {
	.block = mat_block_basalt,
};
const mat_item_t mat_item_polished_basalt_d = {
	.block = mat_block_polished_basalt,
};
const mat_item_t mat_item_smooth_basalt_d = {
	.block = mat_block_smooth_basalt,
};
const mat_item_t mat_item_soul_torch_d = {
	.block = mat_block_soul_torch,
	.piglin_repellents = true,
};
const mat_item_t mat_item_glowstone_d = {
	.block = mat_block_glowstone,
};
const mat_item_t mat_item_infested_stone_d = {
	.block = mat_block_infested_stone,
};
const mat_item_t mat_item_infested_cobblestone_d = {
	.block = mat_block_infested_cobblestone,
};
const mat_item_t mat_item_infested_stone_bricks_d = {
	.block = mat_block_infested_stone_bricks,
};
const mat_item_t mat_item_infested_mossy_stone_bricks_d = {
	.block = mat_block_infested_mossy_stone_bricks,
};
const mat_item_t mat_item_infested_cracked_stone_bricks_d = {
	.block = mat_block_infested_cracked_stone_bricks,
};
const mat_item_t mat_item_infested_chiseled_stone_bricks_d = {
	.block = mat_block_infested_chiseled_stone_bricks,
};
const mat_item_t mat_item_infested_deepslate_d = {
	.block = mat_block_infested_deepslate,
};
const mat_item_t mat_item_stone_bricks_d = {
	.block = mat_block_stone_bricks,
	.stone_bricks = true,
};
const mat_item_t mat_item_mossy_stone_bricks_d = {
	.block = mat_block_mossy_stone_bricks,
	.stone_bricks = true,
};
const mat_item_t mat_item_cracked_stone_bricks_d = {
	.block = mat_block_cracked_stone_bricks,
	.stone_bricks = true,
};
const mat_item_t mat_item_chiseled_stone_bricks_d = {
	.block = mat_block_chiseled_stone_bricks,
	.stone_bricks = true,
};
const mat_item_t mat_item_deepslate_bricks_d = {
	.block = mat_block_deepslate_bricks,
};
const mat_item_t mat_item_cracked_deepslate_bricks_d = {
	.block = mat_block_cracked_deepslate_bricks,
};
const mat_item_t mat_item_deepslate_tiles_d = {
	.block = mat_block_deepslate_tiles,
};
const mat_item_t mat_item_cracked_deepslate_tiles_d = {
	.block = mat_block_cracked_deepslate_tiles,
};
const mat_item_t mat_item_chiseled_deepslate_d = {
	.block = mat_block_chiseled_deepslate,
};
const mat_item_t mat_item_brown_mushroom_block_d = {
	.block = mat_block_brown_mushroom_block,
};
const mat_item_t mat_item_red_mushroom_block_d = {
	.block = mat_block_red_mushroom_block,
};
const mat_item_t mat_item_mushroom_stem_d = {
	.block = mat_block_mushroom_stem,
};
const mat_item_t mat_item_iron_bars_d = {
	.block = mat_block_iron_bars,
};
const mat_item_t mat_item_chain_d = {
	.block = mat_block_chain,
};
const mat_item_t mat_item_glass_pane_d = {
	.block = mat_block_glass_pane,
};
const mat_item_t mat_item_melon_d = {
	.block = mat_block_melon,
};
const mat_item_t mat_item_vine_d = {
	.block = mat_block_vine,
};
const mat_item_t mat_item_glow_lichen_d = {
	.block = mat_block_glow_lichen,
};
const mat_item_t mat_item_brick_stairs_d = {
	.block = mat_block_brick_stairs,
	.stairs = true,
};
const mat_item_t mat_item_stone_brick_stairs_d = {
	.block = mat_block_stone_brick_stairs,
	.stairs = true,
};
const mat_item_t mat_item_mycelium_d = {
	.block = mat_block_mycelium,
	.dirt = true,
};
const mat_item_t mat_item_lily_pad_d = {
	.block = mat_block_lily_pad,
};
const mat_item_t mat_item_nether_bricks_d = {
	.block = mat_block_nether_bricks,
};
const mat_item_t mat_item_cracked_nether_bricks_d = {
	.block = mat_block_cracked_nether_bricks,
};
const mat_item_t mat_item_chiseled_nether_bricks_d = {
	.block = mat_block_chiseled_nether_bricks,
};
const mat_item_t mat_item_nether_brick_fence_d = {
	.block = mat_block_nether_brick_fence,
	.fences = true,
};
const mat_item_t mat_item_nether_brick_stairs_d = {
	.block = mat_block_nether_brick_stairs,
	.stairs = true,
};
const mat_item_t mat_item_enchanting_table_d = {
	.block = mat_block_enchanting_table,
};
const mat_item_t mat_item_end_portal_frame_d = {
	.block = mat_block_end_portal_frame,
};
const mat_item_t mat_item_end_stone_d = {
	.block = mat_block_end_stone,
};
const mat_item_t mat_item_end_stone_bricks_d = {
	.block = mat_block_end_stone_bricks,
};
const mat_item_t mat_item_dragon_egg_d = {
	.block = mat_block_dragon_egg,
};
const mat_item_t mat_item_sandstone_stairs_d = {
	.block = mat_block_sandstone_stairs,
	.stairs = true,
};
const mat_item_t mat_item_ender_chest_d = {
	.block = mat_block_ender_chest,
};
const mat_item_t mat_item_emerald_block_d = {
	.block = mat_block_emerald_block,
};
const mat_item_t mat_item_spruce_stairs_d = {
	.block = mat_block_spruce_stairs,
	.stairs = true,
	.wooden_stairs = true,
};
const mat_item_t mat_item_birch_stairs_d = {
	.block = mat_block_birch_stairs,
	.stairs = true,
	.wooden_stairs = true,
};
const mat_item_t mat_item_jungle_stairs_d = {
	.block = mat_block_jungle_stairs,
	.stairs = true,
	.wooden_stairs = true,
};
const mat_item_t mat_item_crimson_stairs_d = {
	.block = mat_block_crimson_stairs,
	.non_flammable_wood = true,
	.stairs = true,
	.wooden_stairs = true,
};
const mat_item_t mat_item_warped_stairs_d = {
	.block = mat_block_warped_stairs,
	.non_flammable_wood = true,
	.stairs = true,
	.wooden_stairs = true,
};
const mat_item_t mat_item_command_block_d = {
	.block = mat_block_command_block,
};
const mat_item_t mat_item_beacon_d = {
	.block = mat_block_beacon,
};
const mat_item_t mat_item_cobblestone_wall_d = {
	.block = mat_block_cobblestone_wall,
	.walls = true,
};
const mat_item_t mat_item_mossy_cobblestone_wall_d = {
	.block = mat_block_mossy_cobblestone_wall,
	.walls = true,
};
const mat_item_t mat_item_brick_wall_d = {
	.block = mat_block_brick_wall,
	.walls = true,
};
const mat_item_t mat_item_prismarine_wall_d = {
	.block = mat_block_prismarine_wall,
	.walls = true,
};
const mat_item_t mat_item_red_sandstone_wall_d = {
	.block = mat_block_red_sandstone_wall,
	.walls = true,
};
const mat_item_t mat_item_mossy_stone_brick_wall_d = {
	.block = mat_block_mossy_stone_brick_wall,
	.walls = true,
};
const mat_item_t mat_item_granite_wall_d = {
	.block = mat_block_granite_wall,
	.walls = true,
};
const mat_item_t mat_item_stone_brick_wall_d = {
	.block = mat_block_stone_brick_wall,
	.walls = true,
};
const mat_item_t mat_item_nether_brick_wall_d = {
	.block = mat_block_nether_brick_wall,
	.walls = true,
};
const mat_item_t mat_item_andesite_wall_d = {
	.block = mat_block_andesite_wall,
	.walls = true,
};
const mat_item_t mat_item_red_nether_brick_wall_d = {
	.block = mat_block_red_nether_brick_wall,
	.walls = true,
};
const mat_item_t mat_item_sandstone_wall_d = {
	.block = mat_block_sandstone_wall,
	.walls = true,
};
const mat_item_t mat_item_end_stone_brick_wall_d = {
	.block = mat_block_end_stone_brick_wall,
	.walls = true,
};
const mat_item_t mat_item_diorite_wall_d = {
	.block = mat_block_diorite_wall,
	.walls = true,
};
const mat_item_t mat_item_blackstone_wall_d = {
	.block = mat_block_blackstone_wall,
	.walls = true,
};
const mat_item_t mat_item_polished_blackstone_wall_d = {
	.block = mat_block_polished_blackstone_wall,
	.walls = true,
};
const mat_item_t mat_item_polished_blackstone_brick_wall_d = {
	.block = mat_block_polished_blackstone_brick_wall,
	.walls = true,
};
const mat_item_t mat_item_cobbled_deepslate_wall_d = {
	.block = mat_block_cobbled_deepslate_wall,
	.walls = true,
};
const mat_item_t mat_item_polished_deepslate_wall_d = {
	.block = mat_block_polished_deepslate_wall,
	.walls = true,
};
const mat_item_t mat_item_deepslate_brick_wall_d = {
	.block = mat_block_deepslate_brick_wall,
	.walls = true,
};
const mat_item_t mat_item_deepslate_tile_wall_d = {
	.block = mat_block_deepslate_tile_wall,
	.walls = true,
};
const mat_item_t mat_item_anvil_d = {
	.block = mat_block_anvil,
	.anvil = true,
};
const mat_item_t mat_item_chipped_anvil_d = {
	.block = mat_block_chipped_anvil,
	.anvil = true,
};
const mat_item_t mat_item_damaged_anvil_d = {
	.block = mat_block_damaged_anvil,
	.anvil = true,
};
const mat_item_t mat_item_chiseled_quartz_block_d = {
	.block = mat_block_chiseled_quartz_block,
};
const mat_item_t mat_item_quartz_block_d = {
	.block = mat_block_quartz_block,
};
const mat_item_t mat_item_quartz_bricks_d = {
	.block = mat_block_quartz_bricks,
};
const mat_item_t mat_item_quartz_pillar_d = {
	.block = mat_block_quartz_pillar,
};
const mat_item_t mat_item_quartz_stairs_d = {
	.block = mat_block_quartz_stairs,
	.stairs = true,
};
const mat_item_t mat_item_white_terracotta_d = {
	.block = mat_block_white_terracotta,
	.terracotta = true,
};
const mat_item_t mat_item_orange_terracotta_d = {
	.block = mat_block_orange_terracotta,
	.terracotta = true,
};
const mat_item_t mat_item_magenta_terracotta_d = {
	.block = mat_block_magenta_terracotta,
	.terracotta = true,
};
const mat_item_t mat_item_light_blue_terracotta_d = {
	.block = mat_block_light_blue_terracotta,
	.terracotta = true,
};
const mat_item_t mat_item_yellow_terracotta_d = {
	.block = mat_block_yellow_terracotta,
	.terracotta = true,
};
const mat_item_t mat_item_lime_terracotta_d = {
	.block = mat_block_lime_terracotta,
	.terracotta = true,
};
const mat_item_t mat_item_pink_terracotta_d = {
	.block = mat_block_pink_terracotta,
	.terracotta = true,
};
const mat_item_t mat_item_gray_terracotta_d = {
	.block = mat_block_gray_terracotta,
	.terracotta = true,
};
const mat_item_t mat_item_light_gray_terracotta_d = {
	.block = mat_block_light_gray_terracotta,
	.terracotta = true,
};
const mat_item_t mat_item_cyan_terracotta_d = {
	.block = mat_block_cyan_terracotta,
	.terracotta = true,
};
const mat_item_t mat_item_purple_terracotta_d = {
	.block = mat_block_purple_terracotta,
	.terracotta = true,
};
const mat_item_t mat_item_blue_terracotta_d = {
	.block = mat_block_blue_terracotta,
	.terracotta = true,
};
const mat_item_t mat_item_brown_terracotta_d = {
	.block = mat_block_brown_terracotta,
	.terracotta = true,
};
const mat_item_t mat_item_green_terracotta_d = {
	.block = mat_block_green_terracotta,
	.terracotta = true,
};
const mat_item_t mat_item_red_terracotta_d = {
	.block = mat_block_red_terracotta,
	.terracotta = true,
};
const mat_item_t mat_item_black_terracotta_d = {
	.block = mat_block_black_terracotta,
	.terracotta = true,
};
const mat_item_t mat_item_barrier_d = {
	.block = mat_block_barrier,
};
const mat_item_t mat_item_light_d = {
	.block = mat_block_light,
};
const mat_item_t mat_item_hay_block_d = {
	.block = mat_block_hay_block,
};
const mat_item_t mat_item_white_carpet_d = {
	.block = mat_block_white_carpet,
	.carpets = true,
};
const mat_item_t mat_item_orange_carpet_d = {
	.block = mat_block_orange_carpet,
	.carpets = true,
};
const mat_item_t mat_item_magenta_carpet_d = {
	.block = mat_block_magenta_carpet,
	.carpets = true,
};
const mat_item_t mat_item_light_blue_carpet_d = {
	.block = mat_block_light_blue_carpet,
	.carpets = true,
};
const mat_item_t mat_item_yellow_carpet_d = {
	.block = mat_block_yellow_carpet,
	.carpets = true,
};
const mat_item_t mat_item_lime_carpet_d = {
	.block = mat_block_lime_carpet,
	.carpets = true,
};
const mat_item_t mat_item_pink_carpet_d = {
	.block = mat_block_pink_carpet,
	.carpets = true,
};
const mat_item_t mat_item_gray_carpet_d = {
	.block = mat_block_gray_carpet,
	.carpets = true,
};
const mat_item_t mat_item_light_gray_carpet_d = {
	.block = mat_block_light_gray_carpet,
	.carpets = true,
};
const mat_item_t mat_item_cyan_carpet_d = {
	.block = mat_block_cyan_carpet,
	.carpets = true,
};
const mat_item_t mat_item_purple_carpet_d = {
	.block = mat_block_purple_carpet,
	.carpets = true,
};
const mat_item_t mat_item_blue_carpet_d = {
	.block = mat_block_blue_carpet,
	.carpets = true,
};
const mat_item_t mat_item_brown_carpet_d = {
	.block = mat_block_brown_carpet,
	.carpets = true,
};
const mat_item_t mat_item_green_carpet_d = {
	.block = mat_block_green_carpet,
	.carpets = true,
};
const mat_item_t mat_item_red_carpet_d = {
	.block = mat_block_red_carpet,
	.carpets = true,
};
const mat_item_t mat_item_black_carpet_d = {
	.block = mat_block_black_carpet,
	.carpets = true,
};
const mat_item_t mat_item_terracotta_d = {
	.block = mat_block_terracotta,
	.terracotta = true,
};
const mat_item_t mat_item_packed_ice_d = {
	.block = mat_block_packed_ice,
};
const mat_item_t mat_item_acacia_stairs_d = {
	.block = mat_block_acacia_stairs,
	.stairs = true,
	.wooden_stairs = true,
};
const mat_item_t mat_item_dark_oak_stairs_d = {
	.block = mat_block_dark_oak_stairs,
	.stairs = true,
	.wooden_stairs = true,
};
const mat_item_t mat_item_dirt_path_d = {
	.block = mat_block_dirt_path,
};
const mat_item_t mat_item_sunflower_d = {
	.block = mat_block_sunflower,
	.flowers = true,
	.tall_flowers = true,
};
const mat_item_t mat_item_lilac_d = {
	.block = mat_block_lilac,
	.flowers = true,
	.tall_flowers = true,
};
const mat_item_t mat_item_rose_bush_d = {
	.block = mat_block_rose_bush,
	.flowers = true,
	.tall_flowers = true,
};
const mat_item_t mat_item_peony_d = {
	.block = mat_block_peony,
	.flowers = true,
	.tall_flowers = true,
};
const mat_item_t mat_item_tall_grass_d = {
	.block = mat_block_tall_grass,
};
const mat_item_t mat_item_large_fern_d = {
	.block = mat_block_large_fern,
};
const mat_item_t mat_item_white_stained_glass_d = {
	.block = mat_block_white_stained_glass,
};
const mat_item_t mat_item_orange_stained_glass_d = {
	.block = mat_block_orange_stained_glass,
};
const mat_item_t mat_item_magenta_stained_glass_d = {
	.block = mat_block_magenta_stained_glass,
};
const mat_item_t mat_item_light_blue_stained_glass_d = {
	.block = mat_block_light_blue_stained_glass,
};
const mat_item_t mat_item_yellow_stained_glass_d = {
	.block = mat_block_yellow_stained_glass,
};
const mat_item_t mat_item_lime_stained_glass_d = {
	.block = mat_block_lime_stained_glass,
};
const mat_item_t mat_item_pink_stained_glass_d = {
	.block = mat_block_pink_stained_glass,
};
const mat_item_t mat_item_gray_stained_glass_d = {
	.block = mat_block_gray_stained_glass,
};
const mat_item_t mat_item_light_gray_stained_glass_d = {
	.block = mat_block_light_gray_stained_glass,
};
const mat_item_t mat_item_cyan_stained_glass_d = {
	.block = mat_block_cyan_stained_glass,
};
const mat_item_t mat_item_purple_stained_glass_d = {
	.block = mat_block_purple_stained_glass,
};
const mat_item_t mat_item_blue_stained_glass_d = {
	.block = mat_block_blue_stained_glass,
};
const mat_item_t mat_item_brown_stained_glass_d = {
	.block = mat_block_brown_stained_glass,
};
const mat_item_t mat_item_green_stained_glass_d = {
	.block = mat_block_green_stained_glass,
};
const mat_item_t mat_item_red_stained_glass_d = {
	.block = mat_block_red_stained_glass,
};
const mat_item_t mat_item_black_stained_glass_d = {
	.block = mat_block_black_stained_glass,
};
const mat_item_t mat_item_white_stained_glass_pane_d = {
	.block = mat_block_white_stained_glass_pane,
};
const mat_item_t mat_item_orange_stained_glass_pane_d = {
	.block = mat_block_orange_stained_glass_pane,
};
const mat_item_t mat_item_magenta_stained_glass_pane_d = {
	.block = mat_block_magenta_stained_glass_pane,
};
const mat_item_t mat_item_light_blue_stained_glass_pane_d = {
	.block = mat_block_light_blue_stained_glass_pane,
};
const mat_item_t mat_item_yellow_stained_glass_pane_d = {
	.block = mat_block_yellow_stained_glass_pane,
};
const mat_item_t mat_item_lime_stained_glass_pane_d = {
	.block = mat_block_lime_stained_glass_pane,
};
const mat_item_t mat_item_pink_stained_glass_pane_d = {
	.block = mat_block_pink_stained_glass_pane,
};
const mat_item_t mat_item_gray_stained_glass_pane_d = {
	.block = mat_block_gray_stained_glass_pane,
};
const mat_item_t mat_item_light_gray_stained_glass_pane_d = {
	.block = mat_block_light_gray_stained_glass_pane,
};
const mat_item_t mat_item_cyan_stained_glass_pane_d = {
	.block = mat_block_cyan_stained_glass_pane,
};
const mat_item_t mat_item_purple_stained_glass_pane_d = {
	.block = mat_block_purple_stained_glass_pane,
};
const mat_item_t mat_item_blue_stained_glass_pane_d = {
	.block = mat_block_blue_stained_glass_pane,
};
const mat_item_t mat_item_brown_stained_glass_pane_d = {
	.block = mat_block_brown_stained_glass_pane,
};
const mat_item_t mat_item_green_stained_glass_pane_d = {
	.block = mat_block_green_stained_glass_pane,
};
const mat_item_t mat_item_red_stained_glass_pane_d = {
	.block = mat_block_red_stained_glass_pane,
};
const mat_item_t mat_item_black_stained_glass_pane_d = {
	.block = mat_block_black_stained_glass_pane,
};
const mat_item_t mat_item_prismarine_d = {
	.block = mat_block_prismarine,
};
const mat_item_t mat_item_prismarine_bricks_d = {
	.block = mat_block_prismarine_bricks,
};
const mat_item_t mat_item_dark_prismarine_d = {
	.block = mat_block_dark_prismarine,
};
const mat_item_t mat_item_prismarine_stairs_d = {
	.block = mat_block_prismarine_stairs,
	.stairs = true,
};
const mat_item_t mat_item_prismarine_brick_stairs_d = {
	.block = mat_block_prismarine_brick_stairs,
	.stairs = true,
};
const mat_item_t mat_item_dark_prismarine_stairs_d = {
	.block = mat_block_dark_prismarine_stairs,
	.stairs = true,
};
const mat_item_t mat_item_sea_lantern_d = {
	.block = mat_block_sea_lantern,
};
const mat_item_t mat_item_red_sandstone_d = {
	.block = mat_block_red_sandstone,
};
const mat_item_t mat_item_chiseled_red_sandstone_d = {
	.block = mat_block_chiseled_red_sandstone,
};
const mat_item_t mat_item_cut_red_sandstone_d = {
	.block = mat_block_cut_red_sandstone,
};
const mat_item_t mat_item_red_sandstone_stairs_d = {
	.block = mat_block_red_sandstone_stairs,
	.stairs = true,
};
const mat_item_t mat_item_repeating_command_block_d = {
	.block = mat_block_repeating_command_block,
};
const mat_item_t mat_item_chain_command_block_d = {
	.block = mat_block_chain_command_block,
};
const mat_item_t mat_item_magma_block_d = {
	.block = mat_block_magma_block,
};
const mat_item_t mat_item_nether_wart_block_d = {
	.block = mat_block_nether_wart_block,
};
const mat_item_t mat_item_warped_wart_block_d = {
	.block = mat_block_warped_wart_block,
};
const mat_item_t mat_item_red_nether_bricks_d = {
	.block = mat_block_red_nether_bricks,
};
const mat_item_t mat_item_bone_block_d = {
	.block = mat_block_bone_block,
};
const mat_item_t mat_item_structure_void_d = {
	.block = mat_block_structure_void,
};
const mat_item_t mat_item_shulker_box_d = {
	.block = mat_block_shulker_box,
};
const mat_item_t mat_item_white_shulker_box_d = {
	.block = mat_block_white_shulker_box,
};
const mat_item_t mat_item_orange_shulker_box_d = {
	.block = mat_block_orange_shulker_box,
};
const mat_item_t mat_item_magenta_shulker_box_d = {
	.block = mat_block_magenta_shulker_box,
};
const mat_item_t mat_item_light_blue_shulker_box_d = {
	.block = mat_block_light_blue_shulker_box,
};
const mat_item_t mat_item_yellow_shulker_box_d = {
	.block = mat_block_yellow_shulker_box,
};
const mat_item_t mat_item_lime_shulker_box_d = {
	.block = mat_block_lime_shulker_box,
};
const mat_item_t mat_item_pink_shulker_box_d = {
	.block = mat_block_pink_shulker_box,
};
const mat_item_t mat_item_gray_shulker_box_d = {
	.block = mat_block_gray_shulker_box,
};
const mat_item_t mat_item_light_gray_shulker_box_d = {
	.block = mat_block_light_gray_shulker_box,
};
const mat_item_t mat_item_cyan_shulker_box_d = {
	.block = mat_block_cyan_shulker_box,
};
const mat_item_t mat_item_purple_shulker_box_d = {
	.block = mat_block_purple_shulker_box,
};
const mat_item_t mat_item_blue_shulker_box_d = {
	.block = mat_block_blue_shulker_box,
};
const mat_item_t mat_item_brown_shulker_box_d = {
	.block = mat_block_brown_shulker_box,
};
const mat_item_t mat_item_green_shulker_box_d = {
	.block = mat_block_green_shulker_box,
};
const mat_item_t mat_item_red_shulker_box_d = {
	.block = mat_block_red_shulker_box,
};
const mat_item_t mat_item_black_shulker_box_d = {
	.block = mat_block_black_shulker_box,
};
const mat_item_t mat_item_white_glazed_terracotta_d = {
	.block = mat_block_white_glazed_terracotta,
};
const mat_item_t mat_item_orange_glazed_terracotta_d = {
	.block = mat_block_orange_glazed_terracotta,
};
const mat_item_t mat_item_magenta_glazed_terracotta_d = {
	.block = mat_block_magenta_glazed_terracotta,
};
const mat_item_t mat_item_light_blue_glazed_terracotta_d = {
	.block = mat_block_light_blue_glazed_terracotta,
};
const mat_item_t mat_item_yellow_glazed_terracotta_d = {
	.block = mat_block_yellow_glazed_terracotta,
};
const mat_item_t mat_item_lime_glazed_terracotta_d = {
	.block = mat_block_lime_glazed_terracotta,
};
const mat_item_t mat_item_pink_glazed_terracotta_d = {
	.block = mat_block_pink_glazed_terracotta,
};
const mat_item_t mat_item_gray_glazed_terracotta_d = {
	.block = mat_block_gray_glazed_terracotta,
};
const mat_item_t mat_item_light_gray_glazed_terracotta_d = {
	.block = mat_block_light_gray_glazed_terracotta,
};
const mat_item_t mat_item_cyan_glazed_terracotta_d = {
	.block = mat_block_cyan_glazed_terracotta,
};
const mat_item_t mat_item_purple_glazed_terracotta_d = {
	.block = mat_block_purple_glazed_terracotta,
};
const mat_item_t mat_item_blue_glazed_terracotta_d = {
	.block = mat_block_blue_glazed_terracotta,
};
const mat_item_t mat_item_brown_glazed_terracotta_d = {
	.block = mat_block_brown_glazed_terracotta,
};
const mat_item_t mat_item_green_glazed_terracotta_d = {
	.block = mat_block_green_glazed_terracotta,
};
const mat_item_t mat_item_red_glazed_terracotta_d = {
	.block = mat_block_red_glazed_terracotta,
};
const mat_item_t mat_item_black_glazed_terracotta_d = {
	.block = mat_block_black_glazed_terracotta,
};
const mat_item_t mat_item_white_concrete_d = {
	.block = mat_block_white_concrete,
};
const mat_item_t mat_item_orange_concrete_d = {
	.block = mat_block_orange_concrete,
};
const mat_item_t mat_item_magenta_concrete_d = {
	.block = mat_block_magenta_concrete,
};
const mat_item_t mat_item_light_blue_concrete_d = {
	.block = mat_block_light_blue_concrete,
};
const mat_item_t mat_item_yellow_concrete_d = {
	.block = mat_block_yellow_concrete,
};
const mat_item_t mat_item_lime_concrete_d = {
	.block = mat_block_lime_concrete,
};
const mat_item_t mat_item_pink_concrete_d = {
	.block = mat_block_pink_concrete,
};
const mat_item_t mat_item_gray_concrete_d = {
	.block = mat_block_gray_concrete,
};
const mat_item_t mat_item_light_gray_concrete_d = {
	.block = mat_block_light_gray_concrete,
};
const mat_item_t mat_item_cyan_concrete_d = {
	.block = mat_block_cyan_concrete,
};
const mat_item_t mat_item_purple_concrete_d = {
	.block = mat_block_purple_concrete,
};
const mat_item_t mat_item_blue_concrete_d = {
	.block = mat_block_blue_concrete,
};
const mat_item_t mat_item_brown_concrete_d = {
	.block = mat_block_brown_concrete,
};
const mat_item_t mat_item_green_concrete_d = {
	.block = mat_block_green_concrete,
};
const mat_item_t mat_item_red_concrete_d = {
	.block = mat_block_red_concrete,
};
const mat_item_t mat_item_black_concrete_d = {
	.block = mat_block_black_concrete,
};
const mat_item_t mat_item_white_concrete_powder_d = {
	.block = mat_block_white_concrete_powder,
};
const mat_item_t mat_item_orange_concrete_powder_d = {
	.block = mat_block_orange_concrete_powder,
};
const mat_item_t mat_item_magenta_concrete_powder_d = {
	.block = mat_block_magenta_concrete_powder,
};
const mat_item_t mat_item_light_blue_concrete_powder_d = {
	.block = mat_block_light_blue_concrete_powder,
};
const mat_item_t mat_item_yellow_concrete_powder_d = {
	.block = mat_block_yellow_concrete_powder,
};
const mat_item_t mat_item_lime_concrete_powder_d = {
	.block = mat_block_lime_concrete_powder,
};
const mat_item_t mat_item_pink_concrete_powder_d = {
	.block = mat_block_pink_concrete_powder,
};
const mat_item_t mat_item_gray_concrete_powder_d = {
	.block = mat_block_gray_concrete_powder,
};
const mat_item_t mat_item_light_gray_concrete_powder_d = {
	.block = mat_block_light_gray_concrete_powder,
};
const mat_item_t mat_item_cyan_concrete_powder_d = {
	.block = mat_block_cyan_concrete_powder,
};
const mat_item_t mat_item_purple_concrete_powder_d = {
	.block = mat_block_purple_concrete_powder,
};
const mat_item_t mat_item_blue_concrete_powder_d = {
	.block = mat_block_blue_concrete_powder,
};
const mat_item_t mat_item_brown_concrete_powder_d = {
	.block = mat_block_brown_concrete_powder,
};
const mat_item_t mat_item_green_concrete_powder_d = {
	.block = mat_block_green_concrete_powder,
};
const mat_item_t mat_item_red_concrete_powder_d = {
	.block = mat_block_red_concrete_powder,
};
const mat_item_t mat_item_black_concrete_powder_d = {
	.block = mat_block_black_concrete_powder,
};
const mat_item_t mat_item_turtle_egg_d = {
	.block = mat_block_turtle_egg,
};
const mat_item_t mat_item_dead_tube_coral_block_d = {
	.block = mat_block_dead_tube_coral_block,
};
const mat_item_t mat_item_dead_brain_coral_block_d = {
	.block = mat_block_dead_brain_coral_block,
};
const mat_item_t mat_item_dead_bubble_coral_block_d = {
	.block = mat_block_dead_bubble_coral_block,
};
const mat_item_t mat_item_dead_fire_coral_block_d = {
	.block = mat_block_dead_fire_coral_block,
};
const mat_item_t mat_item_dead_horn_coral_block_d = {
	.block = mat_block_dead_horn_coral_block,
};
const mat_item_t mat_item_tube_coral_block_d = {
	.block = mat_block_tube_coral_block,
};
const mat_item_t mat_item_brain_coral_block_d = {
	.block = mat_block_brain_coral_block,
};
const mat_item_t mat_item_bubble_coral_block_d = {
	.block = mat_block_bubble_coral_block,
};
const mat_item_t mat_item_fire_coral_block_d = {
	.block = mat_block_fire_coral_block,
};
const mat_item_t mat_item_horn_coral_block_d = {
	.block = mat_block_horn_coral_block,
};
const mat_item_t mat_item_tube_coral_d = {
	.block = mat_block_tube_coral,
};
const mat_item_t mat_item_brain_coral_d = {
	.block = mat_block_brain_coral,
};
const mat_item_t mat_item_bubble_coral_d = {
	.block = mat_block_bubble_coral,
};
const mat_item_t mat_item_fire_coral_d = {
	.block = mat_block_fire_coral,
};
const mat_item_t mat_item_horn_coral_d = {
	.block = mat_block_horn_coral,
};
const mat_item_t mat_item_dead_brain_coral_d = {
	.block = mat_block_dead_brain_coral,
};
const mat_item_t mat_item_dead_bubble_coral_d = {
	.block = mat_block_dead_bubble_coral,
};
const mat_item_t mat_item_dead_fire_coral_d = {
	.block = mat_block_dead_fire_coral,
};
const mat_item_t mat_item_dead_horn_coral_d = {
	.block = mat_block_dead_horn_coral,
};
const mat_item_t mat_item_dead_tube_coral_d = {
	.block = mat_block_dead_tube_coral,
};
const mat_item_t mat_item_tube_coral_fan_d = {
	.block = mat_block_tube_coral_fan,
};
const mat_item_t mat_item_brain_coral_fan_d = {
	.block = mat_block_brain_coral_fan,
};
const mat_item_t mat_item_bubble_coral_fan_d = {
	.block = mat_block_bubble_coral_fan,
};
const mat_item_t mat_item_fire_coral_fan_d = {
	.block = mat_block_fire_coral_fan,
};
const mat_item_t mat_item_horn_coral_fan_d = {
	.block = mat_block_horn_coral_fan,
};
const mat_item_t mat_item_dead_tube_coral_fan_d = {
	.block = mat_block_dead_tube_coral_fan,
};
const mat_item_t mat_item_dead_brain_coral_fan_d = {
	.block = mat_block_dead_brain_coral_fan,
};
const mat_item_t mat_item_dead_bubble_coral_fan_d = {
	.block = mat_block_dead_bubble_coral_fan,
};
const mat_item_t mat_item_dead_fire_coral_fan_d = {
	.block = mat_block_dead_fire_coral_fan,
};
const mat_item_t mat_item_dead_horn_coral_fan_d = {
	.block = mat_block_dead_horn_coral_fan,
};
const mat_item_t mat_item_blue_ice_d = {
	.block = mat_block_blue_ice,
};
const mat_item_t mat_item_conduit_d = {
	.block = mat_block_conduit,
};
const mat_item_t mat_item_polished_granite_stairs_d = {
	.block = mat_block_polished_granite_stairs,
	.stairs = true,
};
const mat_item_t mat_item_smooth_red_sandstone_stairs_d = {
	.block = mat_block_smooth_red_sandstone_stairs,
	.stairs = true,
};
const mat_item_t mat_item_mossy_stone_brick_stairs_d = {
	.block = mat_block_mossy_stone_brick_stairs,
	.stairs = true,
};
const mat_item_t mat_item_polished_diorite_stairs_d = {
	.block = mat_block_polished_diorite_stairs,
	.stairs = true,
};
const mat_item_t mat_item_mossy_cobblestone_stairs_d = {
	.block = mat_block_mossy_cobblestone_stairs,
	.stairs = true,
};
const mat_item_t mat_item_end_stone_brick_stairs_d = {
	.block = mat_block_end_stone_brick_stairs,
	.stairs = true,
};
const mat_item_t mat_item_stone_stairs_d = {
	.block = mat_block_stone_stairs,
	.stairs = true,
};
const mat_item_t mat_item_smooth_sandstone_stairs_d = {
	.block = mat_block_smooth_sandstone_stairs,
	.stairs = true,
};
const mat_item_t mat_item_smooth_quartz_stairs_d = {
	.block = mat_block_smooth_quartz_stairs,
	.stairs = true,
};
const mat_item_t mat_item_granite_stairs_d = {
	.block = mat_block_granite_stairs,
	.stairs = true,
};
const mat_item_t mat_item_andesite_stairs_d = {
	.block = mat_block_andesite_stairs,
	.stairs = true,
};
const mat_item_t mat_item_red_nether_brick_stairs_d = {
	.block = mat_block_red_nether_brick_stairs,
	.stairs = true,
};
const mat_item_t mat_item_polished_andesite_stairs_d = {
	.block = mat_block_polished_andesite_stairs,
	.stairs = true,
};
const mat_item_t mat_item_diorite_stairs_d = {
	.block = mat_block_diorite_stairs,
	.stairs = true,
};
const mat_item_t mat_item_cobbled_deepslate_stairs_d = {
	.block = mat_block_cobbled_deepslate_stairs,
	.stairs = true,
};
const mat_item_t mat_item_polished_deepslate_stairs_d = {
	.block = mat_block_polished_deepslate_stairs,
	.stairs = true,
};
const mat_item_t mat_item_deepslate_brick_stairs_d = {
	.block = mat_block_deepslate_brick_stairs,
	.stairs = true,
};
const mat_item_t mat_item_deepslate_tile_stairs_d = {
	.block = mat_block_deepslate_tile_stairs,
	.stairs = true,
};
const mat_item_t mat_item_polished_granite_slab_d = {
	.block = mat_block_polished_granite_slab,
	.slabs = true,
};
const mat_item_t mat_item_smooth_red_sandstone_slab_d = {
	.block = mat_block_smooth_red_sandstone_slab,
	.slabs = true,
};
const mat_item_t mat_item_mossy_stone_brick_slab_d = {
	.block = mat_block_mossy_stone_brick_slab,
	.slabs = true,
};
const mat_item_t mat_item_polished_diorite_slab_d = {
	.block = mat_block_polished_diorite_slab,
	.slabs = true,
};
const mat_item_t mat_item_mossy_cobblestone_slab_d = {
	.block = mat_block_mossy_cobblestone_slab,
	.slabs = true,
};
const mat_item_t mat_item_end_stone_brick_slab_d = {
	.block = mat_block_end_stone_brick_slab,
	.slabs = true,
};
const mat_item_t mat_item_smooth_sandstone_slab_d = {
	.block = mat_block_smooth_sandstone_slab,
	.slabs = true,
};
const mat_item_t mat_item_smooth_quartz_slab_d = {
	.block = mat_block_smooth_quartz_slab,
	.slabs = true,
};
const mat_item_t mat_item_granite_slab_d = {
	.block = mat_block_granite_slab,
	.slabs = true,
};
const mat_item_t mat_item_andesite_slab_d = {
	.block = mat_block_andesite_slab,
	.slabs = true,
};
const mat_item_t mat_item_red_nether_brick_slab_d = {
	.block = mat_block_red_nether_brick_slab,
	.slabs = true,
};
const mat_item_t mat_item_polished_andesite_slab_d = {
	.block = mat_block_polished_andesite_slab,
	.slabs = true,
};
const mat_item_t mat_item_diorite_slab_d = {
	.block = mat_block_diorite_slab,
	.slabs = true,
};
const mat_item_t mat_item_cobbled_deepslate_slab_d = {
	.block = mat_block_cobbled_deepslate_slab,
	.slabs = true,
};
const mat_item_t mat_item_polished_deepslate_slab_d = {
	.block = mat_block_polished_deepslate_slab,
	.slabs = true,
};
const mat_item_t mat_item_deepslate_brick_slab_d = {
	.block = mat_block_deepslate_brick_slab,
	.slabs = true,
};
const mat_item_t mat_item_deepslate_tile_slab_d = {
	.block = mat_block_deepslate_tile_slab,
	.slabs = true,
};
const mat_item_t mat_item_scaffolding_d = {
	.block = mat_block_scaffolding,
};
const mat_item_t mat_item_redstone_d = {
	.block = mat_block_redstone_wire,
};
const mat_item_t mat_item_redstone_torch_d = {
	.block = mat_block_redstone_torch,
};
const mat_item_t mat_item_redstone_block_d = {
	.block = mat_block_redstone_block,
};
const mat_item_t mat_item_repeater_d = {
	.block = mat_block_repeater,
};
const mat_item_t mat_item_comparator_d = {
	.block = mat_block_comparator,
};
const mat_item_t mat_item_piston_d = {
	.block = mat_block_piston,
};
const mat_item_t mat_item_sticky_piston_d = {
	.block = mat_block_sticky_piston,
};
const mat_item_t mat_item_slime_block_d = {
	.block = mat_block_slime_block,
};
const mat_item_t mat_item_honey_block_d = {
	.block = mat_block_honey_block,
};
const mat_item_t mat_item_observer_d = {
	.block = mat_block_observer,
};
const mat_item_t mat_item_hopper_d = {
	.block = mat_block_hopper,
};
const mat_item_t mat_item_dispenser_d = {
	.block = mat_block_dispenser,
};
const mat_item_t mat_item_dropper_d = {
	.block = mat_block_dropper,
};
const mat_item_t mat_item_lectern_d = {
	.block = mat_block_lectern,
};
const mat_item_t mat_item_target_d = {
	.block = mat_block_target,
};
const mat_item_t mat_item_lever_d = {
	.block = mat_block_lever,
};
const mat_item_t mat_item_lightning_rod_d = {
	.block = mat_block_lightning_rod,
};
const mat_item_t mat_item_daylight_detector_d = {
	.block = mat_block_daylight_detector,
};
const mat_item_t mat_item_sculk_sensor_d = {
	.block = mat_block_sculk_sensor,
};
const mat_item_t mat_item_tripwire_hook_d = {
	.block = mat_block_tripwire_hook,
};
const mat_item_t mat_item_trapped_chest_d = {
	.block = mat_block_trapped_chest,
};
const mat_item_t mat_item_tnt_d = {
	.block = mat_block_tnt,
};
const mat_item_t mat_item_redstone_lamp_d = {
	.block = mat_block_redstone_lamp,
};
const mat_item_t mat_item_note_block_d = {
	.block = mat_block_note_block,
};
const mat_item_t mat_item_stone_button_d = {
	.block = mat_block_stone_button,
	.buttons = true,
};
const mat_item_t mat_item_polished_blackstone_button_d = {
	.block = mat_block_polished_blackstone_button,
	.buttons = true,
};
const mat_item_t mat_item_oak_button_d = {
	.block = mat_block_oak_button,
	.buttons = true,
	.wooden_buttons = true,
};
const mat_item_t mat_item_spruce_button_d = {
	.block = mat_block_spruce_button,
	.buttons = true,
	.wooden_buttons = true,
};
const mat_item_t mat_item_birch_button_d = {
	.block = mat_block_birch_button,
	.buttons = true,
	.wooden_buttons = true,
};
const mat_item_t mat_item_jungle_button_d = {
	.block = mat_block_jungle_button,
	.buttons = true,
	.wooden_buttons = true,
};
const mat_item_t mat_item_acacia_button_d = {
	.block = mat_block_acacia_button,
	.buttons = true,
	.wooden_buttons = true,
};
const mat_item_t mat_item_dark_oak_button_d = {
	.block = mat_block_dark_oak_button,
	.buttons = true,
	.wooden_buttons = true,
};
const mat_item_t mat_item_crimson_button_d = {
	.block = mat_block_crimson_button,
	.buttons = true,
	.non_flammable_wood = true,
	.wooden_buttons = true,
};
const mat_item_t mat_item_warped_button_d = {
	.block = mat_block_warped_button,
	.buttons = true,
	.non_flammable_wood = true,
	.wooden_buttons = true,
};
const mat_item_t mat_item_stone_pressure_plate_d = {
	.block = mat_block_stone_pressure_plate,
};
const mat_item_t mat_item_polished_blackstone_pressure_plate_d = {
	.block = mat_block_polished_blackstone_pressure_plate,
};
const mat_item_t mat_item_light_weighted_pressure_plate_d = {
	.block = mat_block_light_weighted_pressure_plate,
	.piglin_loved = true,
};
const mat_item_t mat_item_heavy_weighted_pressure_plate_d = {
	.block = mat_block_heavy_weighted_pressure_plate,
};
const mat_item_t mat_item_oak_pressure_plate_d = {
	.block = mat_block_oak_pressure_plate,
	.wooden_pressure_plates = true,
};
const mat_item_t mat_item_spruce_pressure_plate_d = {
	.block = mat_block_spruce_pressure_plate,
	.wooden_pressure_plates = true,
};
const mat_item_t mat_item_birch_pressure_plate_d = {
	.block = mat_block_birch_pressure_plate,
	.wooden_pressure_plates = true,
};
const mat_item_t mat_item_jungle_pressure_plate_d = {
	.block = mat_block_jungle_pressure_plate,
	.wooden_pressure_plates = true,
};
const mat_item_t mat_item_acacia_pressure_plate_d = {
	.block = mat_block_acacia_pressure_plate,
	.wooden_pressure_plates = true,
};
const mat_item_t mat_item_dark_oak_pressure_plate_d = {
	.block = mat_block_dark_oak_pressure_plate,
	.wooden_pressure_plates = true,
};
const mat_item_t mat_item_crimson_pressure_plate_d = {
	.block = mat_block_crimson_pressure_plate,
	.non_flammable_wood = true,
	.wooden_pressure_plates = true,
};
const mat_item_t mat_item_warped_pressure_plate_d = {
	.block = mat_block_warped_pressure_plate,
	.non_flammable_wood = true,
	.wooden_pressure_plates = true,
};
const mat_item_t mat_item_iron_door_d = {
	.block = mat_block_iron_door,
	.doors = true,
};
const mat_item_t mat_item_oak_door_d = {
	.block = mat_block_oak_door,
	.doors = true,
	.wooden_doors = true,
};
const mat_item_t mat_item_spruce_door_d = {
	.block = mat_block_spruce_door,
	.doors = true,
	.wooden_doors = true,
};
const mat_item_t mat_item_birch_door_d = {
	.block = mat_block_birch_door,
	.doors = true,
	.wooden_doors = true,
};
const mat_item_t mat_item_jungle_door_d = {
	.block = mat_block_jungle_door,
	.doors = true,
	.wooden_doors = true,
};
const mat_item_t mat_item_acacia_door_d = {
	.block = mat_block_acacia_door,
	.doors = true,
	.wooden_doors = true,
};
const mat_item_t mat_item_dark_oak_door_d = {
	.block = mat_block_dark_oak_door,
	.doors = true,
	.wooden_doors = true,
};
const mat_item_t mat_item_crimson_door_d = {
	.block = mat_block_crimson_door,
	.doors = true,
	.non_flammable_wood = true,
	.wooden_doors = true,
};
const mat_item_t mat_item_warped_door_d = {
	.block = mat_block_warped_door,
	.doors = true,
	.non_flammable_wood = true,
	.wooden_doors = true,
};
const mat_item_t mat_item_iron_trapdoor_d = {
	.block = mat_block_iron_trapdoor,
	.trapdoors = true,
};
const mat_item_t mat_item_oak_trapdoor_d = {
	.block = mat_block_oak_trapdoor,
	.trapdoors = true,
	.wooden_trapdoors = true,
};
const mat_item_t mat_item_spruce_trapdoor_d = {
	.block = mat_block_spruce_trapdoor,
	.trapdoors = true,
	.wooden_trapdoors = true,
};
const mat_item_t mat_item_birch_trapdoor_d = {
	.block = mat_block_birch_trapdoor,
	.trapdoors = true,
	.wooden_trapdoors = true,
};
const mat_item_t mat_item_jungle_trapdoor_d = {
	.block = mat_block_jungle_trapdoor,
	.trapdoors = true,
	.wooden_trapdoors = true,
};
const mat_item_t mat_item_acacia_trapdoor_d = {
	.block = mat_block_acacia_trapdoor,
	.trapdoors = true,
	.wooden_trapdoors = true,
};
const mat_item_t mat_item_dark_oak_trapdoor_d = {
	.block = mat_block_dark_oak_trapdoor,
	.trapdoors = true,
	.wooden_trapdoors = true,
};
const mat_item_t mat_item_crimson_trapdoor_d = {
	.block = mat_block_crimson_trapdoor,
	.non_flammable_wood = true,
	.trapdoors = true,
	.wooden_trapdoors = true,
};
const mat_item_t mat_item_warped_trapdoor_d = {
	.block = mat_block_warped_trapdoor,
	.non_flammable_wood = true,
	.trapdoors = true,
	.wooden_trapdoors = true,
};
const mat_item_t mat_item_oak_fence_gate_d = {
	.block = mat_block_oak_fence_gate,
};
const mat_item_t mat_item_spruce_fence_gate_d = {
	.block = mat_block_spruce_fence_gate,
};
const mat_item_t mat_item_birch_fence_gate_d = {
	.block = mat_block_birch_fence_gate,
};
const mat_item_t mat_item_jungle_fence_gate_d = {
	.block = mat_block_jungle_fence_gate,
};
const mat_item_t mat_item_acacia_fence_gate_d = {
	.block = mat_block_acacia_fence_gate,
};
const mat_item_t mat_item_dark_oak_fence_gate_d = {
	.block = mat_block_dark_oak_fence_gate,
};
const mat_item_t mat_item_crimson_fence_gate_d = {
	.block = mat_block_crimson_fence_gate,
	.non_flammable_wood = true,
};
const mat_item_t mat_item_warped_fence_gate_d = {
	.block = mat_block_warped_fence_gate,
	.non_flammable_wood = true,
};
const mat_item_t mat_item_powered_rail_d = {
	.block = mat_block_powered_rail,
	.rails = true,
};
const mat_item_t mat_item_detector_rail_d = {
	.block = mat_block_detector_rail,
	.rails = true,
};
const mat_item_t mat_item_rail_d = {
	.block = mat_block_rail,
	.rails = true,
};
const mat_item_t mat_item_activator_rail_d = {
	.block = mat_block_activator_rail,
	.rails = true,
};
const mat_item_t mat_item_saddle_d = {
};
const mat_item_t mat_item_minecart_d = {
};
const mat_item_t mat_item_chest_minecart_d = {
};
const mat_item_t mat_item_furnace_minecart_d = {
};
const mat_item_t mat_item_tnt_minecart_d = {
};
const mat_item_t mat_item_hopper_minecart_d = {
};
const mat_item_t mat_item_carrot_on_a_stick_d = {
};
const mat_item_t mat_item_warped_fungus_on_a_stick_d = {
};
const mat_item_t mat_item_elytra_d = {
};
const mat_item_t mat_item_oak_boat_d = {
	.boats = true,
};
const mat_item_t mat_item_spruce_boat_d = {
	.boats = true,
};
const mat_item_t mat_item_birch_boat_d = {
	.boats = true,
};
const mat_item_t mat_item_jungle_boat_d = {
	.boats = true,
};
const mat_item_t mat_item_acacia_boat_d = {
	.boats = true,
};
const mat_item_t mat_item_dark_oak_boat_d = {
	.boats = true,
};
const mat_item_t mat_item_structure_block_d = {
	.block = mat_block_structure_block,
};
const mat_item_t mat_item_jigsaw_d = {
	.block = mat_block_jigsaw,
};
const mat_item_t mat_item_turtle_helmet_d = {
};
const mat_item_t mat_item_scute_d = {
};
const mat_item_t mat_item_flint_and_steel_d = {
};
const mat_item_t mat_item_apple_d = {
};
const mat_item_t mat_item_bow_d = {
};
const mat_item_t mat_item_arrow_d = {
	.arrows = true,
};
const mat_item_t mat_item_coal_d = {
	.coals = true,
};
const mat_item_t mat_item_charcoal_d = {
	.coals = true,
};
const mat_item_t mat_item_diamond_d = {
	.beacon_payment_items = true,
};
const mat_item_t mat_item_emerald_d = {
	.beacon_payment_items = true,
};
const mat_item_t mat_item_lapis_lazuli_d = {
};
const mat_item_t mat_item_quartz_d = {
};
const mat_item_t mat_item_amethyst_shard_d = {
};
const mat_item_t mat_item_raw_iron_d = {
};
const mat_item_t mat_item_iron_ingot_d = {
	.beacon_payment_items = true,
};
const mat_item_t mat_item_raw_copper_d = {
};
const mat_item_t mat_item_copper_ingot_d = {
};
const mat_item_t mat_item_raw_gold_d = {
	.piglin_loved = true,
};
const mat_item_t mat_item_gold_ingot_d = {
	.beacon_payment_items = true,
	.piglin_loved = true,
};
const mat_item_t mat_item_netherite_ingot_d = {
	.beacon_payment_items = true,
};
const mat_item_t mat_item_netherite_scrap_d = {
};
const mat_item_t mat_item_wooden_sword_d = {
};
const mat_item_t mat_item_wooden_shovel_d = {
};
const mat_item_t mat_item_wooden_pickaxe_d = {
	.cluster_max_harvestables = true,
};
const mat_item_t mat_item_wooden_axe_d = {
};
const mat_item_t mat_item_wooden_hoe_d = {
};
const mat_item_t mat_item_stone_sword_d = {
};
const mat_item_t mat_item_stone_shovel_d = {
};
const mat_item_t mat_item_stone_pickaxe_d = {
	.cluster_max_harvestables = true,
};
const mat_item_t mat_item_stone_axe_d = {
};
const mat_item_t mat_item_stone_hoe_d = {
};
const mat_item_t mat_item_golden_sword_d = {
	.piglin_loved = true,
};
const mat_item_t mat_item_golden_shovel_d = {
	.piglin_loved = true,
};
const mat_item_t mat_item_golden_pickaxe_d = {
	.cluster_max_harvestables = true,
	.piglin_loved = true,
};
const mat_item_t mat_item_golden_axe_d = {
	.piglin_loved = true,
};
const mat_item_t mat_item_golden_hoe_d = {
	.piglin_loved = true,
};
const mat_item_t mat_item_iron_sword_d = {
};
const mat_item_t mat_item_iron_shovel_d = {
};
const mat_item_t mat_item_iron_pickaxe_d = {
	.cluster_max_harvestables = true,
};
const mat_item_t mat_item_iron_axe_d = {
};
const mat_item_t mat_item_iron_hoe_d = {
};
const mat_item_t mat_item_diamond_sword_d = {
};
const mat_item_t mat_item_diamond_shovel_d = {
};
const mat_item_t mat_item_diamond_pickaxe_d = {
	.cluster_max_harvestables = true,
};
const mat_item_t mat_item_diamond_axe_d = {
};
const mat_item_t mat_item_diamond_hoe_d = {
};
const mat_item_t mat_item_netherite_sword_d = {
};
const mat_item_t mat_item_netherite_shovel_d = {
};
const mat_item_t mat_item_netherite_pickaxe_d = {
	.cluster_max_harvestables = true,
};
const mat_item_t mat_item_netherite_axe_d = {
};
const mat_item_t mat_item_netherite_hoe_d = {
};
const mat_item_t mat_item_stick_d = {
};
const mat_item_t mat_item_bowl_d = {
};
const mat_item_t mat_item_mushroom_stew_d = {
};
const mat_item_t mat_item_string_d = {
};
const mat_item_t mat_item_feather_d = {
};
const mat_item_t mat_item_gunpowder_d = {
};
const mat_item_t mat_item_wheat_seeds_d = {
	.block = mat_block_wheat,
};
const mat_item_t mat_item_wheat_d = {
};
const mat_item_t mat_item_bread_d = {
};
const mat_item_t mat_item_leather_helmet_d = {
	.freeze_immune_wearables = true,
};
const mat_item_t mat_item_leather_chestplate_d = {
	.freeze_immune_wearables = true,
};
const mat_item_t mat_item_leather_leggings_d = {
	.freeze_immune_wearables = true,
};
const mat_item_t mat_item_leather_boots_d = {
	.freeze_immune_wearables = true,
};
const mat_item_t mat_item_chainmail_helmet_d = {
};
const mat_item_t mat_item_chainmail_chestplate_d = {
};
const mat_item_t mat_item_chainmail_leggings_d = {
};
const mat_item_t mat_item_chainmail_boots_d = {
};
const mat_item_t mat_item_iron_helmet_d = {
};
const mat_item_t mat_item_iron_chestplate_d = {
};
const mat_item_t mat_item_iron_leggings_d = {
};
const mat_item_t mat_item_iron_boots_d = {
};
const mat_item_t mat_item_diamond_helmet_d = {
};
const mat_item_t mat_item_diamond_chestplate_d = {
};
const mat_item_t mat_item_diamond_leggings_d = {
};
const mat_item_t mat_item_diamond_boots_d = {
};
const mat_item_t mat_item_golden_helmet_d = {
	.piglin_loved = true,
};
const mat_item_t mat_item_golden_chestplate_d = {
	.piglin_loved = true,
};
const mat_item_t mat_item_golden_leggings_d = {
	.piglin_loved = true,
};
const mat_item_t mat_item_golden_boots_d = {
	.piglin_loved = true,
};
const mat_item_t mat_item_netherite_helmet_d = {
};
const mat_item_t mat_item_netherite_chestplate_d = {
};
const mat_item_t mat_item_netherite_leggings_d = {
};
const mat_item_t mat_item_netherite_boots_d = {
};
const mat_item_t mat_item_flint_d = {
};
const mat_item_t mat_item_porkchop_d = {
	.piglin_food = true,
};
const mat_item_t mat_item_cooked_porkchop_d = {
	.piglin_food = true,
};
const mat_item_t mat_item_painting_d = {
};
const mat_item_t mat_item_golden_apple_d = {
	.piglin_loved = true,
};
const mat_item_t mat_item_enchanted_golden_apple_d = {
	.piglin_loved = true,
};
const mat_item_t mat_item_oak_sign_d = {
	.block = mat_block_oak_sign,
	.signs = true,
};
const mat_item_t mat_item_spruce_sign_d = {
	.block = mat_block_spruce_sign,
	.signs = true,
};
const mat_item_t mat_item_birch_sign_d = {
	.block = mat_block_birch_sign,
	.signs = true,
};
const mat_item_t mat_item_jungle_sign_d = {
	.block = mat_block_jungle_sign,
	.signs = true,
};
const mat_item_t mat_item_acacia_sign_d = {
	.block = mat_block_acacia_sign,
	.signs = true,
};
const mat_item_t mat_item_dark_oak_sign_d = {
	.block = mat_block_dark_oak_sign,
	.signs = true,
};
const mat_item_t mat_item_crimson_sign_d = {
	.block = mat_block_crimson_sign,
	.non_flammable_wood = true,
	.signs = true,
};
const mat_item_t mat_item_warped_sign_d = {
	.block = mat_block_warped_sign,
	.non_flammable_wood = true,
	.signs = true,
};
const mat_item_t mat_item_bucket_d = {
};
const mat_item_t mat_item_water_bucket_d = {
};
const mat_item_t mat_item_lava_bucket_d = {
};
const mat_item_t mat_item_powder_snow_bucket_d = {
};
const mat_item_t mat_item_snowball_d = {
};
const mat_item_t mat_item_leather_d = {
	.ignored_by_piglin_babies = true,
};
const mat_item_t mat_item_milk_bucket_d = {
};
const mat_item_t mat_item_pufferfish_bucket_d = {
};
const mat_item_t mat_item_salmon_bucket_d = {
};
const mat_item_t mat_item_cod_bucket_d = {
};
const mat_item_t mat_item_tropical_fish_bucket_d = {
	.axolotl_tempt_items = true,
};
const mat_item_t mat_item_axolotl_bucket_d = {
};
const mat_item_t mat_item_brick_d = {
};
const mat_item_t mat_item_clay_ball_d = {
};
const mat_item_t mat_item_dried_kelp_block_d = {
	.block = mat_block_dried_kelp_block,
};
const mat_item_t mat_item_paper_d = {
};
const mat_item_t mat_item_book_d = {
};
const mat_item_t mat_item_slime_ball_d = {
};
const mat_item_t mat_item_egg_d = {
};
const mat_item_t mat_item_compass_d = {
};
const mat_item_t mat_item_bundle_d = {
};
const mat_item_t mat_item_fishing_rod_d = {
};
const mat_item_t mat_item_clock_d = {
	.piglin_loved = true,
};
const mat_item_t mat_item_spyglass_d = {
};
const mat_item_t mat_item_glowstone_dust_d = {
};
const mat_item_t mat_item_cod_d = {
	.fishes = true,
};
const mat_item_t mat_item_salmon_d = {
	.fishes = true,
};
const mat_item_t mat_item_tropical_fish_d = {
	.fishes = true,
};
const mat_item_t mat_item_pufferfish_d = {
	.fishes = true,
};
const mat_item_t mat_item_cooked_cod_d = {
	.fishes = true,
};
const mat_item_t mat_item_cooked_salmon_d = {
	.fishes = true,
};
const mat_item_t mat_item_ink_sac_d = {
};
const mat_item_t mat_item_glow_ink_sac_d = {
};
const mat_item_t mat_item_cocoa_beans_d = {
};
const mat_item_t mat_item_white_dye_d = {
};
const mat_item_t mat_item_orange_dye_d = {
};
const mat_item_t mat_item_magenta_dye_d = {
};
const mat_item_t mat_item_light_blue_dye_d = {
};
const mat_item_t mat_item_yellow_dye_d = {
};
const mat_item_t mat_item_lime_dye_d = {
};
const mat_item_t mat_item_pink_dye_d = {
};
const mat_item_t mat_item_gray_dye_d = {
};
const mat_item_t mat_item_light_gray_dye_d = {
};
const mat_item_t mat_item_cyan_dye_d = {
};
const mat_item_t mat_item_purple_dye_d = {
};
const mat_item_t mat_item_blue_dye_d = {
};
const mat_item_t mat_item_brown_dye_d = {
};
const mat_item_t mat_item_green_dye_d = {
};
const mat_item_t mat_item_red_dye_d = {
};
const mat_item_t mat_item_black_dye_d = {
};
const mat_item_t mat_item_bone_meal_d = {
};
const mat_item_t mat_item_bone_d = {
};
const mat_item_t mat_item_sugar_d = {
};
const mat_item_t mat_item_cake_d = {
	.block = mat_block_cake,
};
const mat_item_t mat_item_white_bed_d = {
	.block = mat_block_white_bed,
	.beds = true,
};
const mat_item_t mat_item_orange_bed_d = {
	.block = mat_block_orange_bed,
	.beds = true,
};
const mat_item_t mat_item_magenta_bed_d = {
	.block = mat_block_magenta_bed,
	.beds = true,
};
const mat_item_t mat_item_light_blue_bed_d = {
	.block = mat_block_light_blue_bed,
	.beds = true,
};
const mat_item_t mat_item_yellow_bed_d = {
	.block = mat_block_yellow_bed,
	.beds = true,
};
const mat_item_t mat_item_lime_bed_d = {
	.block = mat_block_lime_bed,
	.beds = true,
};
const mat_item_t mat_item_pink_bed_d = {
	.block = mat_block_pink_bed,
	.beds = true,
};
const mat_item_t mat_item_gray_bed_d = {
	.block = mat_block_gray_bed,
	.beds = true,
};
const mat_item_t mat_item_light_gray_bed_d = {
	.block = mat_block_light_gray_bed,
	.beds = true,
};
const mat_item_t mat_item_cyan_bed_d = {
	.block = mat_block_cyan_bed,
	.beds = true,
};
const mat_item_t mat_item_purple_bed_d = {
	.block = mat_block_purple_bed,
	.beds = true,
};
const mat_item_t mat_item_blue_bed_d = {
	.block = mat_block_blue_bed,
	.beds = true,
};
const mat_item_t mat_item_brown_bed_d = {
	.block = mat_block_brown_bed,
	.beds = true,
};
const mat_item_t mat_item_green_bed_d = {
	.block = mat_block_green_bed,
	.beds = true,
};
const mat_item_t mat_item_red_bed_d = {
	.block = mat_block_red_bed,
	.beds = true,
};
const mat_item_t mat_item_black_bed_d = {
	.block = mat_block_black_bed,
	.beds = true,
};
const mat_item_t mat_item_cookie_d = {
};
const mat_item_t mat_item_filled_map_d = {
};
const mat_item_t mat_item_shears_d = {
};
const mat_item_t mat_item_melon_slice_d = {
};
const mat_item_t mat_item_dried_kelp_d = {
};
const mat_item_t mat_item_pumpkin_seeds_d = {
};
const mat_item_t mat_item_melon_seeds_d = {
};
const mat_item_t mat_item_beef_d = {
};
const mat_item_t mat_item_cooked_beef_d = {
};
const mat_item_t mat_item_chicken_d = {
};
const mat_item_t mat_item_cooked_chicken_d = {
};
const mat_item_t mat_item_rotten_flesh_d = {
};
const mat_item_t mat_item_ender_pearl_d = {
};
const mat_item_t mat_item_blaze_rod_d = {
};
const mat_item_t mat_item_ghast_tear_d = {
};
const mat_item_t mat_item_gold_nugget_d = {
};
const mat_item_t mat_item_nether_wart_d = {
	.block = mat_block_nether_wart,
};
const mat_item_t mat_item_potion_d = {
};
const mat_item_t mat_item_glass_bottle_d = {
};
const mat_item_t mat_item_spider_eye_d = {
};
const mat_item_t mat_item_fermented_spider_eye_d = {
};
const mat_item_t mat_item_blaze_powder_d = {
};
const mat_item_t mat_item_magma_cream_d = {
};
const mat_item_t mat_item_brewing_stand_d = {
	.block = mat_block_brewing_stand,
};
const mat_item_t mat_item_cauldron_d = {
	.block = mat_block_cauldron,
};
const mat_item_t mat_item_ender_eye_d = {
};
const mat_item_t mat_item_glistering_melon_slice_d = {
	.piglin_loved = true,
};
const mat_item_t mat_item_axolotl_spawn_egg_d = {
};
const mat_item_t mat_item_bat_spawn_egg_d = {
};
const mat_item_t mat_item_bee_spawn_egg_d = {
};
const mat_item_t mat_item_blaze_spawn_egg_d = {
};
const mat_item_t mat_item_cat_spawn_egg_d = {
};
const mat_item_t mat_item_cave_spider_spawn_egg_d = {
};
const mat_item_t mat_item_chicken_spawn_egg_d = {
};
const mat_item_t mat_item_cod_spawn_egg_d = {
};
const mat_item_t mat_item_cow_spawn_egg_d = {
};
const mat_item_t mat_item_creeper_spawn_egg_d = {
};
const mat_item_t mat_item_dolphin_spawn_egg_d = {
};
const mat_item_t mat_item_donkey_spawn_egg_d = {
};
const mat_item_t mat_item_drowned_spawn_egg_d = {
};
const mat_item_t mat_item_elder_guardian_spawn_egg_d = {
};
const mat_item_t mat_item_enderman_spawn_egg_d = {
};
const mat_item_t mat_item_endermite_spawn_egg_d = {
};
const mat_item_t mat_item_evoker_spawn_egg_d = {
};
const mat_item_t mat_item_fox_spawn_egg_d = {
};
const mat_item_t mat_item_ghast_spawn_egg_d = {
};
const mat_item_t mat_item_glow_squid_spawn_egg_d = {
};
const mat_item_t mat_item_goat_spawn_egg_d = {
};
const mat_item_t mat_item_guardian_spawn_egg_d = {
};
const mat_item_t mat_item_hoglin_spawn_egg_d = {
};
const mat_item_t mat_item_horse_spawn_egg_d = {
};
const mat_item_t mat_item_husk_spawn_egg_d = {
};
const mat_item_t mat_item_llama_spawn_egg_d = {
};
const mat_item_t mat_item_magma_cube_spawn_egg_d = {
};
const mat_item_t mat_item_mooshroom_spawn_egg_d = {
};
const mat_item_t mat_item_mule_spawn_egg_d = {
};
const mat_item_t mat_item_ocelot_spawn_egg_d = {
};
const mat_item_t mat_item_panda_spawn_egg_d = {
};
const mat_item_t mat_item_parrot_spawn_egg_d = {
};
const mat_item_t mat_item_phantom_spawn_egg_d = {
};
const mat_item_t mat_item_pig_spawn_egg_d = {
};
const mat_item_t mat_item_piglin_spawn_egg_d = {
};
const mat_item_t mat_item_piglin_brute_spawn_egg_d = {
};
const mat_item_t mat_item_pillager_spawn_egg_d = {
};
const mat_item_t mat_item_polar_bear_spawn_egg_d = {
};
const mat_item_t mat_item_pufferfish_spawn_egg_d = {
};
const mat_item_t mat_item_rabbit_spawn_egg_d = {
};
const mat_item_t mat_item_ravager_spawn_egg_d = {
};
const mat_item_t mat_item_salmon_spawn_egg_d = {
};
const mat_item_t mat_item_sheep_spawn_egg_d = {
};
const mat_item_t mat_item_shulker_spawn_egg_d = {
};
const mat_item_t mat_item_silverfish_spawn_egg_d = {
};
const mat_item_t mat_item_skeleton_spawn_egg_d = {
};
const mat_item_t mat_item_skeleton_horse_spawn_egg_d = {
};
const mat_item_t mat_item_slime_spawn_egg_d = {
};
const mat_item_t mat_item_spider_spawn_egg_d = {
};
const mat_item_t mat_item_squid_spawn_egg_d = {
};
const mat_item_t mat_item_stray_spawn_egg_d = {
};
const mat_item_t mat_item_strider_spawn_egg_d = {
};
const mat_item_t mat_item_trader_llama_spawn_egg_d = {
};
const mat_item_t mat_item_tropical_fish_spawn_egg_d = {
};
const mat_item_t mat_item_turtle_spawn_egg_d = {
};
const mat_item_t mat_item_vex_spawn_egg_d = {
};
const mat_item_t mat_item_villager_spawn_egg_d = {
};
const mat_item_t mat_item_vindicator_spawn_egg_d = {
};
const mat_item_t mat_item_wandering_trader_spawn_egg_d = {
};
const mat_item_t mat_item_witch_spawn_egg_d = {
};
const mat_item_t mat_item_wither_skeleton_spawn_egg_d = {
};
const mat_item_t mat_item_wolf_spawn_egg_d = {
};
const mat_item_t mat_item_zoglin_spawn_egg_d = {
};
const mat_item_t mat_item_zombie_spawn_egg_d = {
};
const mat_item_t mat_item_zombie_horse_spawn_egg_d = {
};
const mat_item_t mat_item_zombie_villager_spawn_egg_d = {
};
const mat_item_t mat_item_zombified_piglin_spawn_egg_d = {
};
const mat_item_t mat_item_experience_bottle_d = {
};
const mat_item_t mat_item_fire_charge_d = {
};
const mat_item_t mat_item_writable_book_d = {
	.lectern_books = true,
};
const mat_item_t mat_item_written_book_d = {
	.lectern_books = true,
};
const mat_item_t mat_item_item_frame_d = {
};
const mat_item_t mat_item_glow_item_frame_d = {
};
const mat_item_t mat_item_flower_pot_d = {
	.block = mat_block_flower_pot,
};
const mat_item_t mat_item_carrot_d = {
	.block = mat_block_carrots,
};
const mat_item_t mat_item_potato_d = {
	.block = mat_block_potatoes,
};
const mat_item_t mat_item_baked_potato_d = {
};
const mat_item_t mat_item_poisonous_potato_d = {
};
const mat_item_t mat_item_map_d = {
};
const mat_item_t mat_item_golden_carrot_d = {
	.piglin_loved = true,
};
const mat_item_t mat_item_skeleton_skull_d = {
	.block = mat_block_skeleton_skull,
};
const mat_item_t mat_item_wither_skeleton_skull_d = {
	.block = mat_block_wither_skeleton_skull,
};
const mat_item_t mat_item_player_head_d = {
	.block = mat_block_player_head,
};
const mat_item_t mat_item_zombie_head_d = {
	.block = mat_block_zombie_head,
};
const mat_item_t mat_item_creeper_head_d = {
	.block = mat_block_creeper_head,
};
const mat_item_t mat_item_dragon_head_d = {
	.block = mat_block_dragon_head,
};
const mat_item_t mat_item_nether_star_d = {
};
const mat_item_t mat_item_pumpkin_pie_d = {
};
const mat_item_t mat_item_firework_rocket_d = {
};
const mat_item_t mat_item_firework_star_d = {
};
const mat_item_t mat_item_enchanted_book_d = {
};
const mat_item_t mat_item_nether_brick_d = {
};
const mat_item_t mat_item_prismarine_shard_d = {
};
const mat_item_t mat_item_prismarine_crystals_d = {
};
const mat_item_t mat_item_rabbit_d = {
};
const mat_item_t mat_item_cooked_rabbit_d = {
};
const mat_item_t mat_item_rabbit_stew_d = {
};
const mat_item_t mat_item_rabbit_foot_d = {
};
const mat_item_t mat_item_rabbit_hide_d = {
};
const mat_item_t mat_item_armor_stand_d = {
};
const mat_item_t mat_item_iron_horse_armor_d = {
};
const mat_item_t mat_item_golden_horse_armor_d = {
	.piglin_loved = true,
};
const mat_item_t mat_item_diamond_horse_armor_d = {
};
const mat_item_t mat_item_leather_horse_armor_d = {
	.freeze_immune_wearables = true,
};
const mat_item_t mat_item_lead_d = {
};
const mat_item_t mat_item_name_tag_d = {
};
const mat_item_t mat_item_command_block_minecart_d = {
};
const mat_item_t mat_item_mutton_d = {
};
const mat_item_t mat_item_cooked_mutton_d = {
};
const mat_item_t mat_item_white_banner_d = {
	.block = mat_block_white_banner,
	.banners = true,
};
const mat_item_t mat_item_orange_banner_d = {
	.block = mat_block_orange_banner,
	.banners = true,
};
const mat_item_t mat_item_magenta_banner_d = {
	.block = mat_block_magenta_banner,
	.banners = true,
};
const mat_item_t mat_item_light_blue_banner_d = {
	.block = mat_block_light_blue_banner,
	.banners = true,
};
const mat_item_t mat_item_yellow_banner_d = {
	.block = mat_block_yellow_banner,
	.banners = true,
};
const mat_item_t mat_item_lime_banner_d = {
	.block = mat_block_lime_banner,
	.banners = true,
};
const mat_item_t mat_item_pink_banner_d = {
	.block = mat_block_pink_banner,
	.banners = true,
};
const mat_item_t mat_item_gray_banner_d = {
	.block = mat_block_gray_banner,
	.banners = true,
};
const mat_item_t mat_item_light_gray_banner_d = {
	.block = mat_block_light_gray_banner,
	.banners = true,
};
const mat_item_t mat_item_cyan_banner_d = {
	.block = mat_block_cyan_banner,
	.banners = true,
};
const mat_item_t mat_item_purple_banner_d = {
	.block = mat_block_purple_banner,
	.banners = true,
};
const mat_item_t mat_item_blue_banner_d = {
	.block = mat_block_blue_banner,
	.banners = true,
};
const mat_item_t mat_item_brown_banner_d = {
	.block = mat_block_brown_banner,
	.banners = true,
};
const mat_item_t mat_item_green_banner_d = {
	.block = mat_block_green_banner,
	.banners = true,
};
const mat_item_t mat_item_red_banner_d = {
	.block = mat_block_red_banner,
	.banners = true,
};
const mat_item_t mat_item_black_banner_d = {
	.block = mat_block_black_banner,
	.banners = true,
};
const mat_item_t mat_item_end_crystal_d = {
};
const mat_item_t mat_item_chorus_fruit_d = {
	.block = mat_block_chorus_plant,
};
const mat_item_t mat_item_popped_chorus_fruit_d = {
};
const mat_item_t mat_item_beetroot_d = {
};
const mat_item_t mat_item_beetroot_seeds_d = {
	.block = mat_block_beetroots,
};
const mat_item_t mat_item_beetroot_soup_d = {
};
const mat_item_t mat_item_dragon_breath_d = {
};
const mat_item_t mat_item_splash_potion_d = {
};
const mat_item_t mat_item_spectral_arrow_d = {
	.arrows = true,
};
const mat_item_t mat_item_tipped_arrow_d = {
	.arrows = true,
};
const mat_item_t mat_item_lingering_potion_d = {
};
const mat_item_t mat_item_shield_d = {
};
const mat_item_t mat_item_totem_of_undying_d = {
};
const mat_item_t mat_item_shulker_shell_d = {
};
const mat_item_t mat_item_iron_nugget_d = {
};
const mat_item_t mat_item_knowledge_book_d = {
};
const mat_item_t mat_item_debug_stick_d = {
};
const mat_item_t mat_item_music_disc_13_d = {
	.creeper_drop_music_discs = true,
	.music_discs = true,
};
const mat_item_t mat_item_music_disc_cat_d = {
	.creeper_drop_music_discs = true,
	.music_discs = true,
};
const mat_item_t mat_item_music_disc_blocks_d = {
	.creeper_drop_music_discs = true,
	.music_discs = true,
};
const mat_item_t mat_item_music_disc_chirp_d = {
	.creeper_drop_music_discs = true,
	.music_discs = true,
};
const mat_item_t mat_item_music_disc_far_d = {
	.creeper_drop_music_discs = true,
	.music_discs = true,
};
const mat_item_t mat_item_music_disc_mall_d = {
	.creeper_drop_music_discs = true,
	.music_discs = true,
};
const mat_item_t mat_item_music_disc_mellohi_d = {
	.creeper_drop_music_discs = true,
	.music_discs = true,
};
const mat_item_t mat_item_music_disc_stal_d = {
	.creeper_drop_music_discs = true,
	.music_discs = true,
};
const mat_item_t mat_item_music_disc_strad_d = {
	.creeper_drop_music_discs = true,
	.music_discs = true,
};
const mat_item_t mat_item_music_disc_ward_d = {
	.creeper_drop_music_discs = true,
	.music_discs = true,
};
const mat_item_t mat_item_music_disc_11_d = {
	.creeper_drop_music_discs = true,
	.music_discs = true,
};
const mat_item_t mat_item_music_disc_wait_d = {
	.creeper_drop_music_discs = true,
	.music_discs = true,
};
const mat_item_t mat_item_music_disc_pigstep_d = {
	.music_discs = true,
};
const mat_item_t mat_item_music_disc_otherside_d = {
	.music_discs = true,
};
const mat_item_t mat_item_trident_d = {
};
const mat_item_t mat_item_phantom_membrane_d = {
};
const mat_item_t mat_item_nautilus_shell_d = {
};
const mat_item_t mat_item_heart_of_the_sea_d = {
};
const mat_item_t mat_item_crossbow_d = {
};
const mat_item_t mat_item_suspicious_stew_d = {
};
const mat_item_t mat_item_loom_d = {
	.block = mat_block_loom,
};
const mat_item_t mat_item_flower_banner_pattern_d = {
};
const mat_item_t mat_item_creeper_banner_pattern_d = {
};
const mat_item_t mat_item_skull_banner_pattern_d = {
};
const mat_item_t mat_item_mojang_banner_pattern_d = {
};
const mat_item_t mat_item_globe_banner_pattern_d = {
};
const mat_item_t mat_item_piglin_banner_pattern_d = {
};
const mat_item_t mat_item_composter_d = {
	.block = mat_block_composter,
};
const mat_item_t mat_item_barrel_d = {
	.block = mat_block_barrel,
};
const mat_item_t mat_item_smoker_d = {
	.block = mat_block_smoker,
};
const mat_item_t mat_item_blast_furnace_d = {
	.block = mat_block_blast_furnace,
};
const mat_item_t mat_item_cartography_table_d = {
	.block = mat_block_cartography_table,
};
const mat_item_t mat_item_fletching_table_d = {
	.block = mat_block_fletching_table,
};
const mat_item_t mat_item_grindstone_d = {
	.block = mat_block_grindstone,
};
const mat_item_t mat_item_smithing_table_d = {
	.block = mat_block_smithing_table,
};
const mat_item_t mat_item_stonecutter_d = {
	.block = mat_block_stonecutter,
};
const mat_item_t mat_item_bell_d = {
	.block = mat_block_bell,
	.piglin_loved = true,
};
const mat_item_t mat_item_lantern_d = {
	.block = mat_block_lantern,
};
const mat_item_t mat_item_soul_lantern_d = {
	.block = mat_block_soul_lantern,
	.piglin_repellents = true,
};
const mat_item_t mat_item_sweet_berries_d = {
	.block = mat_block_sweet_berry_bush,
	.fox_food = true,
};
const mat_item_t mat_item_glow_berries_d = {
	.block = mat_block_glow_lichen,
	.fox_food = true,
};
const mat_item_t mat_item_campfire_d = {
	.block = mat_block_campfire,
};
const mat_item_t mat_item_soul_campfire_d = {
	.block = mat_block_soul_campfire,
	.piglin_repellents = true,
};
const mat_item_t mat_item_shroomlight_d = {
	.block = mat_block_shroomlight,
};
const mat_item_t mat_item_honeycomb_d = {
};
const mat_item_t mat_item_bee_nest_d = {
	.block = mat_block_bee_nest,
};
const mat_item_t mat_item_beehive_d = {
	.block = mat_block_beehive,
};
const mat_item_t mat_item_honey_bottle_d = {
};
const mat_item_t mat_item_honeycomb_block_d = {
	.block = mat_block_honeycomb_block,
};
const mat_item_t mat_item_lodestone_d = {
	.block = mat_block_lodestone,
};
const mat_item_t mat_item_crying_obsidian_d = {
	.block = mat_block_crying_obsidian,
};
const mat_item_t mat_item_blackstone_d = {
	.block = mat_block_blackstone,
	.stone_crafting_materials = true,
	.stone_tool_materials = true,
};
const mat_item_t mat_item_blackstone_slab_d = {
	.block = mat_block_blackstone_slab,
	.slabs = true,
};
const mat_item_t mat_item_blackstone_stairs_d = {
	.block = mat_block_blackstone_stairs,
	.stairs = true,
};
const mat_item_t mat_item_gilded_blackstone_d = {
	.block = mat_block_gilded_blackstone,
	.piglin_loved = true,
};
const mat_item_t mat_item_polished_blackstone_d = {
	.block = mat_block_polished_blackstone,
};
const mat_item_t mat_item_polished_blackstone_slab_d = {
	.block = mat_block_polished_blackstone_slab,
	.slabs = true,
};
const mat_item_t mat_item_polished_blackstone_stairs_d = {
	.block = mat_block_polished_blackstone_stairs,
	.stairs = true,
};
const mat_item_t mat_item_chiseled_polished_blackstone_d = {
	.block = mat_block_chiseled_polished_blackstone,
};
const mat_item_t mat_item_polished_blackstone_bricks_d = {
	.block = mat_block_polished_blackstone_bricks,
};
const mat_item_t mat_item_polished_blackstone_brick_slab_d = {
	.block = mat_block_polished_blackstone_brick_slab,
	.slabs = true,
};
const mat_item_t mat_item_polished_blackstone_brick_stairs_d = {
	.block = mat_block_polished_blackstone_brick_stairs,
	.stairs = true,
};
const mat_item_t mat_item_cracked_polished_blackstone_bricks_d = {
	.block = mat_block_cracked_polished_blackstone_bricks,
};
const mat_item_t mat_item_respawn_anchor_d = {
	.block = mat_block_respawn_anchor,
};
const mat_item_t mat_item_candle_d = {
	.block = mat_block_candle,
	.candles = true,
};
const mat_item_t mat_item_white_candle_d = {
	.block = mat_block_white_candle,
	.candles = true,
};
const mat_item_t mat_item_orange_candle_d = {
	.block = mat_block_orange_candle,
	.candles = true,
};
const mat_item_t mat_item_magenta_candle_d = {
	.block = mat_block_magenta_candle,
	.candles = true,
};
const mat_item_t mat_item_light_blue_candle_d = {
	.block = mat_block_light_blue_candle,
	.candles = true,
};
const mat_item_t mat_item_yellow_candle_d = {
	.block = mat_block_yellow_candle,
	.candles = true,
};
const mat_item_t mat_item_lime_candle_d = {
	.block = mat_block_lime_candle,
	.candles = true,
};
const mat_item_t mat_item_pink_candle_d = {
	.block = mat_block_pink_candle,
	.candles = true,
};
const mat_item_t mat_item_gray_candle_d = {
	.block = mat_block_gray_candle,
	.candles = true,
};
const mat_item_t mat_item_light_gray_candle_d = {
	.block = mat_block_light_gray_candle,
	.candles = true,
};
const mat_item_t mat_item_cyan_candle_d = {
	.block = mat_block_cyan_candle,
	.candles = true,
};
const mat_item_t mat_item_purple_candle_d = {
	.block = mat_block_purple_candle,
	.candles = true,
};
const mat_item_t mat_item_blue_candle_d = {
	.block = mat_block_blue_candle,
	.candles = true,
};
const mat_item_t mat_item_brown_candle_d = {
	.block = mat_block_brown_candle,
	.candles = true,
};
const mat_item_t mat_item_green_candle_d = {
	.block = mat_block_green_candle,
	.candles = true,
};
const mat_item_t mat_item_red_candle_d = {
	.block = mat_block_red_candle,
	.candles = true,
};
const mat_item_t mat_item_black_candle_d = {
	.block = mat_block_black_candle,
	.candles = true,
};
const mat_item_t mat_item_small_amethyst_bud_d = {
	.block = mat_block_small_amethyst_bud,
};
const mat_item_t mat_item_medium_amethyst_bud_d = {
	.block = mat_block_medium_amethyst_bud,
};
const mat_item_t mat_item_large_amethyst_bud_d = {
	.block = mat_block_large_amethyst_bud,
};
const mat_item_t mat_item_amethyst_cluster_d = {
	.block = mat_block_amethyst_cluster,
};
const mat_item_t mat_item_pointed_dripstone_d = {
	.block = mat_block_pointed_dripstone,
};

const mat_item_t* mat_items[] = {
	&mat_item_air_d,
	&mat_item_stone_d,
	&mat_item_granite_d,
	&mat_item_polished_granite_d,
	&mat_item_diorite_d,
	&mat_item_polished_diorite_d,
	&mat_item_andesite_d,
	&mat_item_polished_andesite_d,
	&mat_item_deepslate_d,
	&mat_item_cobbled_deepslate_d,
	&mat_item_polished_deepslate_d,
	&mat_item_calcite_d,
	&mat_item_tuff_d,
	&mat_item_dripstone_block_d,
	&mat_item_grass_block_d,
	&mat_item_dirt_d,
	&mat_item_coarse_dirt_d,
	&mat_item_podzol_d,
	&mat_item_rooted_dirt_d,
	&mat_item_crimson_nylium_d,
	&mat_item_warped_nylium_d,
	&mat_item_cobblestone_d,
	&mat_item_oak_planks_d,
	&mat_item_spruce_planks_d,
	&mat_item_birch_planks_d,
	&mat_item_jungle_planks_d,
	&mat_item_acacia_planks_d,
	&mat_item_dark_oak_planks_d,
	&mat_item_crimson_planks_d,
	&mat_item_warped_planks_d,
	&mat_item_oak_sapling_d,
	&mat_item_spruce_sapling_d,
	&mat_item_birch_sapling_d,
	&mat_item_jungle_sapling_d,
	&mat_item_acacia_sapling_d,
	&mat_item_dark_oak_sapling_d,
	&mat_item_bedrock_d,
	&mat_item_sand_d,
	&mat_item_red_sand_d,
	&mat_item_gravel_d,
	&mat_item_coal_ore_d,
	&mat_item_deepslate_coal_ore_d,
	&mat_item_iron_ore_d,
	&mat_item_deepslate_iron_ore_d,
	&mat_item_copper_ore_d,
	&mat_item_deepslate_copper_ore_d,
	&mat_item_gold_ore_d,
	&mat_item_deepslate_gold_ore_d,
	&mat_item_redstone_ore_d,
	&mat_item_deepslate_redstone_ore_d,
	&mat_item_emerald_ore_d,
	&mat_item_deepslate_emerald_ore_d,
	&mat_item_lapis_ore_d,
	&mat_item_deepslate_lapis_ore_d,
	&mat_item_diamond_ore_d,
	&mat_item_deepslate_diamond_ore_d,
	&mat_item_nether_gold_ore_d,
	&mat_item_nether_quartz_ore_d,
	&mat_item_ancient_debris_d,
	&mat_item_coal_block_d,
	&mat_item_raw_iron_block_d,
	&mat_item_raw_copper_block_d,
	&mat_item_raw_gold_block_d,
	&mat_item_amethyst_block_d,
	&mat_item_budding_amethyst_d,
	&mat_item_iron_block_d,
	&mat_item_copper_block_d,
	&mat_item_gold_block_d,
	&mat_item_diamond_block_d,
	&mat_item_netherite_block_d,
	&mat_item_exposed_copper_d,
	&mat_item_weathered_copper_d,
	&mat_item_oxidized_copper_d,
	&mat_item_cut_copper_d,
	&mat_item_exposed_cut_copper_d,
	&mat_item_weathered_cut_copper_d,
	&mat_item_oxidized_cut_copper_d,
	&mat_item_cut_copper_stairs_d,
	&mat_item_exposed_cut_copper_stairs_d,
	&mat_item_weathered_cut_copper_stairs_d,
	&mat_item_oxidized_cut_copper_stairs_d,
	&mat_item_cut_copper_slab_d,
	&mat_item_exposed_cut_copper_slab_d,
	&mat_item_weathered_cut_copper_slab_d,
	&mat_item_oxidized_cut_copper_slab_d,
	&mat_item_waxed_copper_block_d,
	&mat_item_waxed_exposed_copper_d,
	&mat_item_waxed_weathered_copper_d,
	&mat_item_waxed_oxidized_copper_d,
	&mat_item_waxed_cut_copper_d,
	&mat_item_waxed_exposed_cut_copper_d,
	&mat_item_waxed_weathered_cut_copper_d,
	&mat_item_waxed_oxidized_cut_copper_d,
	&mat_item_waxed_cut_copper_stairs_d,
	&mat_item_waxed_exposed_cut_copper_stairs_d,
	&mat_item_waxed_weathered_cut_copper_stairs_d,
	&mat_item_waxed_oxidized_cut_copper_stairs_d,
	&mat_item_waxed_cut_copper_slab_d,
	&mat_item_waxed_exposed_cut_copper_slab_d,
	&mat_item_waxed_weathered_cut_copper_slab_d,
	&mat_item_waxed_oxidized_cut_copper_slab_d,
	&mat_item_oak_log_d,
	&mat_item_spruce_log_d,
	&mat_item_birch_log_d,
	&mat_item_jungle_log_d,
	&mat_item_acacia_log_d,
	&mat_item_dark_oak_log_d,
	&mat_item_crimson_stem_d,
	&mat_item_warped_stem_d,
	&mat_item_stripped_oak_log_d,
	&mat_item_stripped_spruce_log_d,
	&mat_item_stripped_birch_log_d,
	&mat_item_stripped_jungle_log_d,
	&mat_item_stripped_acacia_log_d,
	&mat_item_stripped_dark_oak_log_d,
	&mat_item_stripped_crimson_stem_d,
	&mat_item_stripped_warped_stem_d,
	&mat_item_stripped_oak_wood_d,
	&mat_item_stripped_spruce_wood_d,
	&mat_item_stripped_birch_wood_d,
	&mat_item_stripped_jungle_wood_d,
	&mat_item_stripped_acacia_wood_d,
	&mat_item_stripped_dark_oak_wood_d,
	&mat_item_stripped_crimson_hyphae_d,
	&mat_item_stripped_warped_hyphae_d,
	&mat_item_oak_wood_d,
	&mat_item_spruce_wood_d,
	&mat_item_birch_wood_d,
	&mat_item_jungle_wood_d,
	&mat_item_acacia_wood_d,
	&mat_item_dark_oak_wood_d,
	&mat_item_crimson_hyphae_d,
	&mat_item_warped_hyphae_d,
	&mat_item_oak_leaves_d,
	&mat_item_spruce_leaves_d,
	&mat_item_birch_leaves_d,
	&mat_item_jungle_leaves_d,
	&mat_item_acacia_leaves_d,
	&mat_item_dark_oak_leaves_d,
	&mat_item_azalea_leaves_d,
	&mat_item_flowering_azalea_leaves_d,
	&mat_item_sponge_d,
	&mat_item_wet_sponge_d,
	&mat_item_glass_d,
	&mat_item_tinted_glass_d,
	&mat_item_lapis_block_d,
	&mat_item_sandstone_d,
	&mat_item_chiseled_sandstone_d,
	&mat_item_cut_sandstone_d,
	&mat_item_cobweb_d,
	&mat_item_grass_d,
	&mat_item_fern_d,
	&mat_item_azalea_d,
	&mat_item_flowering_azalea_d,
	&mat_item_dead_bush_d,
	&mat_item_seagrass_d,
	&mat_item_sea_pickle_d,
	&mat_item_white_wool_d,
	&mat_item_orange_wool_d,
	&mat_item_magenta_wool_d,
	&mat_item_light_blue_wool_d,
	&mat_item_yellow_wool_d,
	&mat_item_lime_wool_d,
	&mat_item_pink_wool_d,
	&mat_item_gray_wool_d,
	&mat_item_light_gray_wool_d,
	&mat_item_cyan_wool_d,
	&mat_item_purple_wool_d,
	&mat_item_blue_wool_d,
	&mat_item_brown_wool_d,
	&mat_item_green_wool_d,
	&mat_item_red_wool_d,
	&mat_item_black_wool_d,
	&mat_item_dandelion_d,
	&mat_item_poppy_d,
	&mat_item_blue_orchid_d,
	&mat_item_allium_d,
	&mat_item_azure_bluet_d,
	&mat_item_red_tulip_d,
	&mat_item_orange_tulip_d,
	&mat_item_white_tulip_d,
	&mat_item_pink_tulip_d,
	&mat_item_oxeye_daisy_d,
	&mat_item_cornflower_d,
	&mat_item_lily_of_the_valley_d,
	&mat_item_wither_rose_d,
	&mat_item_spore_blossom_d,
	&mat_item_brown_mushroom_d,
	&mat_item_red_mushroom_d,
	&mat_item_crimson_fungus_d,
	&mat_item_warped_fungus_d,
	&mat_item_crimson_roots_d,
	&mat_item_warped_roots_d,
	&mat_item_nether_sprouts_d,
	&mat_item_weeping_vines_d,
	&mat_item_twisting_vines_d,
	&mat_item_sugar_cane_d,
	&mat_item_kelp_d,
	&mat_item_moss_carpet_d,
	&mat_item_moss_block_d,
	&mat_item_hanging_roots_d,
	&mat_item_big_dripleaf_d,
	&mat_item_small_dripleaf_d,
	&mat_item_bamboo_d,
	&mat_item_oak_slab_d,
	&mat_item_spruce_slab_d,
	&mat_item_birch_slab_d,
	&mat_item_jungle_slab_d,
	&mat_item_acacia_slab_d,
	&mat_item_dark_oak_slab_d,
	&mat_item_crimson_slab_d,
	&mat_item_warped_slab_d,
	&mat_item_stone_slab_d,
	&mat_item_smooth_stone_slab_d,
	&mat_item_sandstone_slab_d,
	&mat_item_cut_sandstone_slab_d,
	&mat_item_petrified_oak_slab_d,
	&mat_item_cobblestone_slab_d,
	&mat_item_brick_slab_d,
	&mat_item_stone_brick_slab_d,
	&mat_item_nether_brick_slab_d,
	&mat_item_quartz_slab_d,
	&mat_item_red_sandstone_slab_d,
	&mat_item_cut_red_sandstone_slab_d,
	&mat_item_purpur_slab_d,
	&mat_item_prismarine_slab_d,
	&mat_item_prismarine_brick_slab_d,
	&mat_item_dark_prismarine_slab_d,
	&mat_item_smooth_quartz_d,
	&mat_item_smooth_red_sandstone_d,
	&mat_item_smooth_sandstone_d,
	&mat_item_smooth_stone_d,
	&mat_item_bricks_d,
	&mat_item_bookshelf_d,
	&mat_item_mossy_cobblestone_d,
	&mat_item_obsidian_d,
	&mat_item_torch_d,
	&mat_item_end_rod_d,
	&mat_item_chorus_plant_d,
	&mat_item_chorus_flower_d,
	&mat_item_purpur_block_d,
	&mat_item_purpur_pillar_d,
	&mat_item_purpur_stairs_d,
	&mat_item_spawner_d,
	&mat_item_oak_stairs_d,
	&mat_item_chest_d,
	&mat_item_crafting_table_d,
	&mat_item_farmland_d,
	&mat_item_furnace_d,
	&mat_item_ladder_d,
	&mat_item_cobblestone_stairs_d,
	&mat_item_snow_d,
	&mat_item_ice_d,
	&mat_item_snow_block_d,
	&mat_item_cactus_d,
	&mat_item_clay_d,
	&mat_item_jukebox_d,
	&mat_item_oak_fence_d,
	&mat_item_spruce_fence_d,
	&mat_item_birch_fence_d,
	&mat_item_jungle_fence_d,
	&mat_item_acacia_fence_d,
	&mat_item_dark_oak_fence_d,
	&mat_item_crimson_fence_d,
	&mat_item_warped_fence_d,
	&mat_item_pumpkin_d,
	&mat_item_carved_pumpkin_d,
	&mat_item_jack_o_lantern_d,
	&mat_item_netherrack_d,
	&mat_item_soul_sand_d,
	&mat_item_soul_soil_d,
	&mat_item_basalt_d,
	&mat_item_polished_basalt_d,
	&mat_item_smooth_basalt_d,
	&mat_item_soul_torch_d,
	&mat_item_glowstone_d,
	&mat_item_infested_stone_d,
	&mat_item_infested_cobblestone_d,
	&mat_item_infested_stone_bricks_d,
	&mat_item_infested_mossy_stone_bricks_d,
	&mat_item_infested_cracked_stone_bricks_d,
	&mat_item_infested_chiseled_stone_bricks_d,
	&mat_item_infested_deepslate_d,
	&mat_item_stone_bricks_d,
	&mat_item_mossy_stone_bricks_d,
	&mat_item_cracked_stone_bricks_d,
	&mat_item_chiseled_stone_bricks_d,
	&mat_item_deepslate_bricks_d,
	&mat_item_cracked_deepslate_bricks_d,
	&mat_item_deepslate_tiles_d,
	&mat_item_cracked_deepslate_tiles_d,
	&mat_item_chiseled_deepslate_d,
	&mat_item_brown_mushroom_block_d,
	&mat_item_red_mushroom_block_d,
	&mat_item_mushroom_stem_d,
	&mat_item_iron_bars_d,
	&mat_item_chain_d,
	&mat_item_glass_pane_d,
	&mat_item_melon_d,
	&mat_item_vine_d,
	&mat_item_glow_lichen_d,
	&mat_item_brick_stairs_d,
	&mat_item_stone_brick_stairs_d,
	&mat_item_mycelium_d,
	&mat_item_lily_pad_d,
	&mat_item_nether_bricks_d,
	&mat_item_cracked_nether_bricks_d,
	&mat_item_chiseled_nether_bricks_d,
	&mat_item_nether_brick_fence_d,
	&mat_item_nether_brick_stairs_d,
	&mat_item_enchanting_table_d,
	&mat_item_end_portal_frame_d,
	&mat_item_end_stone_d,
	&mat_item_end_stone_bricks_d,
	&mat_item_dragon_egg_d,
	&mat_item_sandstone_stairs_d,
	&mat_item_ender_chest_d,
	&mat_item_emerald_block_d,
	&mat_item_spruce_stairs_d,
	&mat_item_birch_stairs_d,
	&mat_item_jungle_stairs_d,
	&mat_item_crimson_stairs_d,
	&mat_item_warped_stairs_d,
	&mat_item_command_block_d,
	&mat_item_beacon_d,
	&mat_item_cobblestone_wall_d,
	&mat_item_mossy_cobblestone_wall_d,
	&mat_item_brick_wall_d,
	&mat_item_prismarine_wall_d,
	&mat_item_red_sandstone_wall_d,
	&mat_item_mossy_stone_brick_wall_d,
	&mat_item_granite_wall_d,
	&mat_item_stone_brick_wall_d,
	&mat_item_nether_brick_wall_d,
	&mat_item_andesite_wall_d,
	&mat_item_red_nether_brick_wall_d,
	&mat_item_sandstone_wall_d,
	&mat_item_end_stone_brick_wall_d,
	&mat_item_diorite_wall_d,
	&mat_item_blackstone_wall_d,
	&mat_item_polished_blackstone_wall_d,
	&mat_item_polished_blackstone_brick_wall_d,
	&mat_item_cobbled_deepslate_wall_d,
	&mat_item_polished_deepslate_wall_d,
	&mat_item_deepslate_brick_wall_d,
	&mat_item_deepslate_tile_wall_d,
	&mat_item_anvil_d,
	&mat_item_chipped_anvil_d,
	&mat_item_damaged_anvil_d,
	&mat_item_chiseled_quartz_block_d,
	&mat_item_quartz_block_d,
	&mat_item_quartz_bricks_d,
	&mat_item_quartz_pillar_d,
	&mat_item_quartz_stairs_d,
	&mat_item_white_terracotta_d,
	&mat_item_orange_terracotta_d,
	&mat_item_magenta_terracotta_d,
	&mat_item_light_blue_terracotta_d,
	&mat_item_yellow_terracotta_d,
	&mat_item_lime_terracotta_d,
	&mat_item_pink_terracotta_d,
	&mat_item_gray_terracotta_d,
	&mat_item_light_gray_terracotta_d,
	&mat_item_cyan_terracotta_d,
	&mat_item_purple_terracotta_d,
	&mat_item_blue_terracotta_d,
	&mat_item_brown_terracotta_d,
	&mat_item_green_terracotta_d,
	&mat_item_red_terracotta_d,
	&mat_item_black_terracotta_d,
	&mat_item_barrier_d,
	&mat_item_light_d,
	&mat_item_hay_block_d,
	&mat_item_white_carpet_d,
	&mat_item_orange_carpet_d,
	&mat_item_magenta_carpet_d,
	&mat_item_light_blue_carpet_d,
	&mat_item_yellow_carpet_d,
	&mat_item_lime_carpet_d,
	&mat_item_pink_carpet_d,
	&mat_item_gray_carpet_d,
	&mat_item_light_gray_carpet_d,
	&mat_item_cyan_carpet_d,
	&mat_item_purple_carpet_d,
	&mat_item_blue_carpet_d,
	&mat_item_brown_carpet_d,
	&mat_item_green_carpet_d,
	&mat_item_red_carpet_d,
	&mat_item_black_carpet_d,
	&mat_item_terracotta_d,
	&mat_item_packed_ice_d,
	&mat_item_acacia_stairs_d,
	&mat_item_dark_oak_stairs_d,
	&mat_item_dirt_path_d,
	&mat_item_sunflower_d,
	&mat_item_lilac_d,
	&mat_item_rose_bush_d,
	&mat_item_peony_d,
	&mat_item_tall_grass_d,
	&mat_item_large_fern_d,
	&mat_item_white_stained_glass_d,
	&mat_item_orange_stained_glass_d,
	&mat_item_magenta_stained_glass_d,
	&mat_item_light_blue_stained_glass_d,
	&mat_item_yellow_stained_glass_d,
	&mat_item_lime_stained_glass_d,
	&mat_item_pink_stained_glass_d,
	&mat_item_gray_stained_glass_d,
	&mat_item_light_gray_stained_glass_d,
	&mat_item_cyan_stained_glass_d,
	&mat_item_purple_stained_glass_d,
	&mat_item_blue_stained_glass_d,
	&mat_item_brown_stained_glass_d,
	&mat_item_green_stained_glass_d,
	&mat_item_red_stained_glass_d,
	&mat_item_black_stained_glass_d,
	&mat_item_white_stained_glass_pane_d,
	&mat_item_orange_stained_glass_pane_d,
	&mat_item_magenta_stained_glass_pane_d,
	&mat_item_light_blue_stained_glass_pane_d,
	&mat_item_yellow_stained_glass_pane_d,
	&mat_item_lime_stained_glass_pane_d,
	&mat_item_pink_stained_glass_pane_d,
	&mat_item_gray_stained_glass_pane_d,
	&mat_item_light_gray_stained_glass_pane_d,
	&mat_item_cyan_stained_glass_pane_d,
	&mat_item_purple_stained_glass_pane_d,
	&mat_item_blue_stained_glass_pane_d,
	&mat_item_brown_stained_glass_pane_d,
	&mat_item_green_stained_glass_pane_d,
	&mat_item_red_stained_glass_pane_d,
	&mat_item_black_stained_glass_pane_d,
	&mat_item_prismarine_d,
	&mat_item_prismarine_bricks_d,
	&mat_item_dark_prismarine_d,
	&mat_item_prismarine_stairs_d,
	&mat_item_prismarine_brick_stairs_d,
	&mat_item_dark_prismarine_stairs_d,
	&mat_item_sea_lantern_d,
	&mat_item_red_sandstone_d,
	&mat_item_chiseled_red_sandstone_d,
	&mat_item_cut_red_sandstone_d,
	&mat_item_red_sandstone_stairs_d,
	&mat_item_repeating_command_block_d,
	&mat_item_chain_command_block_d,
	&mat_item_magma_block_d,
	&mat_item_nether_wart_block_d,
	&mat_item_warped_wart_block_d,
	&mat_item_red_nether_bricks_d,
	&mat_item_bone_block_d,
	&mat_item_structure_void_d,
	&mat_item_shulker_box_d,
	&mat_item_white_shulker_box_d,
	&mat_item_orange_shulker_box_d,
	&mat_item_magenta_shulker_box_d,
	&mat_item_light_blue_shulker_box_d,
	&mat_item_yellow_shulker_box_d,
	&mat_item_lime_shulker_box_d,
	&mat_item_pink_shulker_box_d,
	&mat_item_gray_shulker_box_d,
	&mat_item_light_gray_shulker_box_d,
	&mat_item_cyan_shulker_box_d,
	&mat_item_purple_shulker_box_d,
	&mat_item_blue_shulker_box_d,
	&mat_item_brown_shulker_box_d,
	&mat_item_green_shulker_box_d,
	&mat_item_red_shulker_box_d,
	&mat_item_black_shulker_box_d,
	&mat_item_white_glazed_terracotta_d,
	&mat_item_orange_glazed_terracotta_d,
	&mat_item_magenta_glazed_terracotta_d,
	&mat_item_light_blue_glazed_terracotta_d,
	&mat_item_yellow_glazed_terracotta_d,
	&mat_item_lime_glazed_terracotta_d,
	&mat_item_pink_glazed_terracotta_d,
	&mat_item_gray_glazed_terracotta_d,
	&mat_item_light_gray_glazed_terracotta_d,
	&mat_item_cyan_glazed_terracotta_d,
	&mat_item_purple_glazed_terracotta_d,
	&mat_item_blue_glazed_terracotta_d,
	&mat_item_brown_glazed_terracotta_d,
	&mat_item_green_glazed_terracotta_d,
	&mat_item_red_glazed_terracotta_d,
	&mat_item_black_glazed_terracotta_d,
	&mat_item_white_concrete_d,
	&mat_item_orange_concrete_d,
	&mat_item_magenta_concrete_d,
	&mat_item_light_blue_concrete_d,
	&mat_item_yellow_concrete_d,
	&mat_item_lime_concrete_d,
	&mat_item_pink_concrete_d,
	&mat_item_gray_concrete_d,
	&mat_item_light_gray_concrete_d,
	&mat_item_cyan_concrete_d,
	&mat_item_purple_concrete_d,
	&mat_item_blue_concrete_d,
	&mat_item_brown_concrete_d,
	&mat_item_green_concrete_d,
	&mat_item_red_concrete_d,
	&mat_item_black_concrete_d,
	&mat_item_white_concrete_powder_d,
	&mat_item_orange_concrete_powder_d,
	&mat_item_magenta_concrete_powder_d,
	&mat_item_light_blue_concrete_powder_d,
	&mat_item_yellow_concrete_powder_d,
	&mat_item_lime_concrete_powder_d,
	&mat_item_pink_concrete_powder_d,
	&mat_item_gray_concrete_powder_d,
	&mat_item_light_gray_concrete_powder_d,
	&mat_item_cyan_concrete_powder_d,
	&mat_item_purple_concrete_powder_d,
	&mat_item_blue_concrete_powder_d,
	&mat_item_brown_concrete_powder_d,
	&mat_item_green_concrete_powder_d,
	&mat_item_red_concrete_powder_d,
	&mat_item_black_concrete_powder_d,
	&mat_item_turtle_egg_d,
	&mat_item_dead_tube_coral_block_d,
	&mat_item_dead_brain_coral_block_d,
	&mat_item_dead_bubble_coral_block_d,
	&mat_item_dead_fire_coral_block_d,
	&mat_item_dead_horn_coral_block_d,
	&mat_item_tube_coral_block_d,
	&mat_item_brain_coral_block_d,
	&mat_item_bubble_coral_block_d,
	&mat_item_fire_coral_block_d,
	&mat_item_horn_coral_block_d,
	&mat_item_tube_coral_d,
	&mat_item_brain_coral_d,
	&mat_item_bubble_coral_d,
	&mat_item_fire_coral_d,
	&mat_item_horn_coral_d,
	&mat_item_dead_brain_coral_d,
	&mat_item_dead_bubble_coral_d,
	&mat_item_dead_fire_coral_d,
	&mat_item_dead_horn_coral_d,
	&mat_item_dead_tube_coral_d,
	&mat_item_tube_coral_fan_d,
	&mat_item_brain_coral_fan_d,
	&mat_item_bubble_coral_fan_d,
	&mat_item_fire_coral_fan_d,
	&mat_item_horn_coral_fan_d,
	&mat_item_dead_tube_coral_fan_d,
	&mat_item_dead_brain_coral_fan_d,
	&mat_item_dead_bubble_coral_fan_d,
	&mat_item_dead_fire_coral_fan_d,
	&mat_item_dead_horn_coral_fan_d,
	&mat_item_blue_ice_d,
	&mat_item_conduit_d,
	&mat_item_polished_granite_stairs_d,
	&mat_item_smooth_red_sandstone_stairs_d,
	&mat_item_mossy_stone_brick_stairs_d,
	&mat_item_polished_diorite_stairs_d,
	&mat_item_mossy_cobblestone_stairs_d,
	&mat_item_end_stone_brick_stairs_d,
	&mat_item_stone_stairs_d,
	&mat_item_smooth_sandstone_stairs_d,
	&mat_item_smooth_quartz_stairs_d,
	&mat_item_granite_stairs_d,
	&mat_item_andesite_stairs_d,
	&mat_item_red_nether_brick_stairs_d,
	&mat_item_polished_andesite_stairs_d,
	&mat_item_diorite_stairs_d,
	&mat_item_cobbled_deepslate_stairs_d,
	&mat_item_polished_deepslate_stairs_d,
	&mat_item_deepslate_brick_stairs_d,
	&mat_item_deepslate_tile_stairs_d,
	&mat_item_polished_granite_slab_d,
	&mat_item_smooth_red_sandstone_slab_d,
	&mat_item_mossy_stone_brick_slab_d,
	&mat_item_polished_diorite_slab_d,
	&mat_item_mossy_cobblestone_slab_d,
	&mat_item_end_stone_brick_slab_d,
	&mat_item_smooth_sandstone_slab_d,
	&mat_item_smooth_quartz_slab_d,
	&mat_item_granite_slab_d,
	&mat_item_andesite_slab_d,
	&mat_item_red_nether_brick_slab_d,
	&mat_item_polished_andesite_slab_d,
	&mat_item_diorite_slab_d,
	&mat_item_cobbled_deepslate_slab_d,
	&mat_item_polished_deepslate_slab_d,
	&mat_item_deepslate_brick_slab_d,
	&mat_item_deepslate_tile_slab_d,
	&mat_item_scaffolding_d,
	&mat_item_redstone_d,
	&mat_item_redstone_torch_d,
	&mat_item_redstone_block_d,
	&mat_item_repeater_d,
	&mat_item_comparator_d,
	&mat_item_piston_d,
	&mat_item_sticky_piston_d,
	&mat_item_slime_block_d,
	&mat_item_honey_block_d,
	&mat_item_observer_d,
	&mat_item_hopper_d,
	&mat_item_dispenser_d,
	&mat_item_dropper_d,
	&mat_item_lectern_d,
	&mat_item_target_d,
	&mat_item_lever_d,
	&mat_item_lightning_rod_d,
	&mat_item_daylight_detector_d,
	&mat_item_sculk_sensor_d,
	&mat_item_tripwire_hook_d,
	&mat_item_trapped_chest_d,
	&mat_item_tnt_d,
	&mat_item_redstone_lamp_d,
	&mat_item_note_block_d,
	&mat_item_stone_button_d,
	&mat_item_polished_blackstone_button_d,
	&mat_item_oak_button_d,
	&mat_item_spruce_button_d,
	&mat_item_birch_button_d,
	&mat_item_jungle_button_d,
	&mat_item_acacia_button_d,
	&mat_item_dark_oak_button_d,
	&mat_item_crimson_button_d,
	&mat_item_warped_button_d,
	&mat_item_stone_pressure_plate_d,
	&mat_item_polished_blackstone_pressure_plate_d,
	&mat_item_light_weighted_pressure_plate_d,
	&mat_item_heavy_weighted_pressure_plate_d,
	&mat_item_oak_pressure_plate_d,
	&mat_item_spruce_pressure_plate_d,
	&mat_item_birch_pressure_plate_d,
	&mat_item_jungle_pressure_plate_d,
	&mat_item_acacia_pressure_plate_d,
	&mat_item_dark_oak_pressure_plate_d,
	&mat_item_crimson_pressure_plate_d,
	&mat_item_warped_pressure_plate_d,
	&mat_item_iron_door_d,
	&mat_item_oak_door_d,
	&mat_item_spruce_door_d,
	&mat_item_birch_door_d,
	&mat_item_jungle_door_d,
	&mat_item_acacia_door_d,
	&mat_item_dark_oak_door_d,
	&mat_item_crimson_door_d,
	&mat_item_warped_door_d,
	&mat_item_iron_trapdoor_d,
	&mat_item_oak_trapdoor_d,
	&mat_item_spruce_trapdoor_d,
	&mat_item_birch_trapdoor_d,
	&mat_item_jungle_trapdoor_d,
	&mat_item_acacia_trapdoor_d,
	&mat_item_dark_oak_trapdoor_d,
	&mat_item_crimson_trapdoor_d,
	&mat_item_warped_trapdoor_d,
	&mat_item_oak_fence_gate_d,
	&mat_item_spruce_fence_gate_d,
	&mat_item_birch_fence_gate_d,
	&mat_item_jungle_fence_gate_d,
	&mat_item_acacia_fence_gate_d,
	&mat_item_dark_oak_fence_gate_d,
	&mat_item_crimson_fence_gate_d,
	&mat_item_warped_fence_gate_d,
	&mat_item_powered_rail_d,
	&mat_item_detector_rail_d,
	&mat_item_rail_d,
	&mat_item_activator_rail_d,
	&mat_item_saddle_d,
	&mat_item_minecart_d,
	&mat_item_chest_minecart_d,
	&mat_item_furnace_minecart_d,
	&mat_item_tnt_minecart_d,
	&mat_item_hopper_minecart_d,
	&mat_item_carrot_on_a_stick_d,
	&mat_item_warped_fungus_on_a_stick_d,
	&mat_item_elytra_d,
	&mat_item_oak_boat_d,
	&mat_item_spruce_boat_d,
	&mat_item_birch_boat_d,
	&mat_item_jungle_boat_d,
	&mat_item_acacia_boat_d,
	&mat_item_dark_oak_boat_d,
	&mat_item_structure_block_d,
	&mat_item_jigsaw_d,
	&mat_item_turtle_helmet_d,
	&mat_item_scute_d,
	&mat_item_flint_and_steel_d,
	&mat_item_apple_d,
	&mat_item_bow_d,
	&mat_item_arrow_d,
	&mat_item_coal_d,
	&mat_item_charcoal_d,
	&mat_item_diamond_d,
	&mat_item_emerald_d,
	&mat_item_lapis_lazuli_d,
	&mat_item_quartz_d,
	&mat_item_amethyst_shard_d,
	&mat_item_raw_iron_d,
	&mat_item_iron_ingot_d,
	&mat_item_raw_copper_d,
	&mat_item_copper_ingot_d,
	&mat_item_raw_gold_d,
	&mat_item_gold_ingot_d,
	&mat_item_netherite_ingot_d,
	&mat_item_netherite_scrap_d,
	&mat_item_wooden_sword_d,
	&mat_item_wooden_shovel_d,
	&mat_item_wooden_pickaxe_d,
	&mat_item_wooden_axe_d,
	&mat_item_wooden_hoe_d,
	&mat_item_stone_sword_d,
	&mat_item_stone_shovel_d,
	&mat_item_stone_pickaxe_d,
	&mat_item_stone_axe_d,
	&mat_item_stone_hoe_d,
	&mat_item_golden_sword_d,
	&mat_item_golden_shovel_d,
	&mat_item_golden_pickaxe_d,
	&mat_item_golden_axe_d,
	&mat_item_golden_hoe_d,
	&mat_item_iron_sword_d,
	&mat_item_iron_shovel_d,
	&mat_item_iron_pickaxe_d,
	&mat_item_iron_axe_d,
	&mat_item_iron_hoe_d,
	&mat_item_diamond_sword_d,
	&mat_item_diamond_shovel_d,
	&mat_item_diamond_pickaxe_d,
	&mat_item_diamond_axe_d,
	&mat_item_diamond_hoe_d,
	&mat_item_netherite_sword_d,
	&mat_item_netherite_shovel_d,
	&mat_item_netherite_pickaxe_d,
	&mat_item_netherite_axe_d,
	&mat_item_netherite_hoe_d,
	&mat_item_stick_d,
	&mat_item_bowl_d,
	&mat_item_mushroom_stew_d,
	&mat_item_string_d,
	&mat_item_feather_d,
	&mat_item_gunpowder_d,
	&mat_item_wheat_seeds_d,
	&mat_item_wheat_d,
	&mat_item_bread_d,
	&mat_item_leather_helmet_d,
	&mat_item_leather_chestplate_d,
	&mat_item_leather_leggings_d,
	&mat_item_leather_boots_d,
	&mat_item_chainmail_helmet_d,
	&mat_item_chainmail_chestplate_d,
	&mat_item_chainmail_leggings_d,
	&mat_item_chainmail_boots_d,
	&mat_item_iron_helmet_d,
	&mat_item_iron_chestplate_d,
	&mat_item_iron_leggings_d,
	&mat_item_iron_boots_d,
	&mat_item_diamond_helmet_d,
	&mat_item_diamond_chestplate_d,
	&mat_item_diamond_leggings_d,
	&mat_item_diamond_boots_d,
	&mat_item_golden_helmet_d,
	&mat_item_golden_chestplate_d,
	&mat_item_golden_leggings_d,
	&mat_item_golden_boots_d,
	&mat_item_netherite_helmet_d,
	&mat_item_netherite_chestplate_d,
	&mat_item_netherite_leggings_d,
	&mat_item_netherite_boots_d,
	&mat_item_flint_d,
	&mat_item_porkchop_d,
	&mat_item_cooked_porkchop_d,
	&mat_item_painting_d,
	&mat_item_golden_apple_d,
	&mat_item_enchanted_golden_apple_d,
	&mat_item_oak_sign_d,
	&mat_item_spruce_sign_d,
	&mat_item_birch_sign_d,
	&mat_item_jungle_sign_d,
	&mat_item_acacia_sign_d,
	&mat_item_dark_oak_sign_d,
	&mat_item_crimson_sign_d,
	&mat_item_warped_sign_d,
	&mat_item_bucket_d,
	&mat_item_water_bucket_d,
	&mat_item_lava_bucket_d,
	&mat_item_powder_snow_bucket_d,
	&mat_item_snowball_d,
	&mat_item_leather_d,
	&mat_item_milk_bucket_d,
	&mat_item_pufferfish_bucket_d,
	&mat_item_salmon_bucket_d,
	&mat_item_cod_bucket_d,
	&mat_item_tropical_fish_bucket_d,
	&mat_item_axolotl_bucket_d,
	&mat_item_brick_d,
	&mat_item_clay_ball_d,
	&mat_item_dried_kelp_block_d,
	&mat_item_paper_d,
	&mat_item_book_d,
	&mat_item_slime_ball_d,
	&mat_item_egg_d,
	&mat_item_compass_d,
	&mat_item_bundle_d,
	&mat_item_fishing_rod_d,
	&mat_item_clock_d,
	&mat_item_spyglass_d,
	&mat_item_glowstone_dust_d,
	&mat_item_cod_d,
	&mat_item_salmon_d,
	&mat_item_tropical_fish_d,
	&mat_item_pufferfish_d,
	&mat_item_cooked_cod_d,
	&mat_item_cooked_salmon_d,
	&mat_item_ink_sac_d,
	&mat_item_glow_ink_sac_d,
	&mat_item_cocoa_beans_d,
	&mat_item_white_dye_d,
	&mat_item_orange_dye_d,
	&mat_item_magenta_dye_d,
	&mat_item_light_blue_dye_d,
	&mat_item_yellow_dye_d,
	&mat_item_lime_dye_d,
	&mat_item_pink_dye_d,
	&mat_item_gray_dye_d,
	&mat_item_light_gray_dye_d,
	&mat_item_cyan_dye_d,
	&mat_item_purple_dye_d,
	&mat_item_blue_dye_d,
	&mat_item_brown_dye_d,
	&mat_item_green_dye_d,
	&mat_item_red_dye_d,
	&mat_item_black_dye_d,
	&mat_item_bone_meal_d,
	&mat_item_bone_d,
	&mat_item_sugar_d,
	&mat_item_cake_d,
	&mat_item_white_bed_d,
	&mat_item_orange_bed_d,
	&mat_item_magenta_bed_d,
	&mat_item_light_blue_bed_d,
	&mat_item_yellow_bed_d,
	&mat_item_lime_bed_d,
	&mat_item_pink_bed_d,
	&mat_item_gray_bed_d,
	&mat_item_light_gray_bed_d,
	&mat_item_cyan_bed_d,
	&mat_item_purple_bed_d,
	&mat_item_blue_bed_d,
	&mat_item_brown_bed_d,
	&mat_item_green_bed_d,
	&mat_item_red_bed_d,
	&mat_item_black_bed_d,
	&mat_item_cookie_d,
	&mat_item_filled_map_d,
	&mat_item_shears_d,
	&mat_item_melon_slice_d,
	&mat_item_dried_kelp_d,
	&mat_item_pumpkin_seeds_d,
	&mat_item_melon_seeds_d,
	&mat_item_beef_d,
	&mat_item_cooked_beef_d,
	&mat_item_chicken_d,
	&mat_item_cooked_chicken_d,
	&mat_item_rotten_flesh_d,
	&mat_item_ender_pearl_d,
	&mat_item_blaze_rod_d,
	&mat_item_ghast_tear_d,
	&mat_item_gold_nugget_d,
	&mat_item_nether_wart_d,
	&mat_item_potion_d,
	&mat_item_glass_bottle_d,
	&mat_item_spider_eye_d,
	&mat_item_fermented_spider_eye_d,
	&mat_item_blaze_powder_d,
	&mat_item_magma_cream_d,
	&mat_item_brewing_stand_d,
	&mat_item_cauldron_d,
	&mat_item_ender_eye_d,
	&mat_item_glistering_melon_slice_d,
	&mat_item_axolotl_spawn_egg_d,
	&mat_item_bat_spawn_egg_d,
	&mat_item_bee_spawn_egg_d,
	&mat_item_blaze_spawn_egg_d,
	&mat_item_cat_spawn_egg_d,
	&mat_item_cave_spider_spawn_egg_d,
	&mat_item_chicken_spawn_egg_d,
	&mat_item_cod_spawn_egg_d,
	&mat_item_cow_spawn_egg_d,
	&mat_item_creeper_spawn_egg_d,
	&mat_item_dolphin_spawn_egg_d,
	&mat_item_donkey_spawn_egg_d,
	&mat_item_drowned_spawn_egg_d,
	&mat_item_elder_guardian_spawn_egg_d,
	&mat_item_enderman_spawn_egg_d,
	&mat_item_endermite_spawn_egg_d,
	&mat_item_evoker_spawn_egg_d,
	&mat_item_fox_spawn_egg_d,
	&mat_item_ghast_spawn_egg_d,
	&mat_item_glow_squid_spawn_egg_d,
	&mat_item_goat_spawn_egg_d,
	&mat_item_guardian_spawn_egg_d,
	&mat_item_hoglin_spawn_egg_d,
	&mat_item_horse_spawn_egg_d,
	&mat_item_husk_spawn_egg_d,
	&mat_item_llama_spawn_egg_d,
	&mat_item_magma_cube_spawn_egg_d,
	&mat_item_mooshroom_spawn_egg_d,
	&mat_item_mule_spawn_egg_d,
	&mat_item_ocelot_spawn_egg_d,
	&mat_item_panda_spawn_egg_d,
	&mat_item_parrot_spawn_egg_d,
	&mat_item_phantom_spawn_egg_d,
	&mat_item_pig_spawn_egg_d,
	&mat_item_piglin_spawn_egg_d,
	&mat_item_piglin_brute_spawn_egg_d,
	&mat_item_pillager_spawn_egg_d,
	&mat_item_polar_bear_spawn_egg_d,
	&mat_item_pufferfish_spawn_egg_d,
	&mat_item_rabbit_spawn_egg_d,
	&mat_item_ravager_spawn_egg_d,
	&mat_item_salmon_spawn_egg_d,
	&mat_item_sheep_spawn_egg_d,
	&mat_item_shulker_spawn_egg_d,
	&mat_item_silverfish_spawn_egg_d,
	&mat_item_skeleton_spawn_egg_d,
	&mat_item_skeleton_horse_spawn_egg_d,
	&mat_item_slime_spawn_egg_d,
	&mat_item_spider_spawn_egg_d,
	&mat_item_squid_spawn_egg_d,
	&mat_item_stray_spawn_egg_d,
	&mat_item_strider_spawn_egg_d,
	&mat_item_trader_llama_spawn_egg_d,
	&mat_item_tropical_fish_spawn_egg_d,
	&mat_item_turtle_spawn_egg_d,
	&mat_item_vex_spawn_egg_d,
	&mat_item_villager_spawn_egg_d,
	&mat_item_vindicator_spawn_egg_d,
	&mat_item_wandering_trader_spawn_egg_d,
	&mat_item_witch_spawn_egg_d,
	&mat_item_wither_skeleton_spawn_egg_d,
	&mat_item_wolf_spawn_egg_d,
	&mat_item_zoglin_spawn_egg_d,
	&mat_item_zombie_spawn_egg_d,
	&mat_item_zombie_horse_spawn_egg_d,
	&mat_item_zombie_villager_spawn_egg_d,
	&mat_item_zombified_piglin_spawn_egg_d,
	&mat_item_experience_bottle_d,
	&mat_item_fire_charge_d,
	&mat_item_writable_book_d,
	&mat_item_written_book_d,
	&mat_item_item_frame_d,
	&mat_item_glow_item_frame_d,
	&mat_item_flower_pot_d,
	&mat_item_carrot_d,
	&mat_item_potato_d,
	&mat_item_baked_potato_d,
	&mat_item_poisonous_potato_d,
	&mat_item_map_d,
	&mat_item_golden_carrot_d,
	&mat_item_skeleton_skull_d,
	&mat_item_wither_skeleton_skull_d,
	&mat_item_player_head_d,
	&mat_item_zombie_head_d,
	&mat_item_creeper_head_d,
	&mat_item_dragon_head_d,
	&mat_item_nether_star_d,
	&mat_item_pumpkin_pie_d,
	&mat_item_firework_rocket_d,
	&mat_item_firework_star_d,
	&mat_item_enchanted_book_d,
	&mat_item_nether_brick_d,
	&mat_item_prismarine_shard_d,
	&mat_item_prismarine_crystals_d,
	&mat_item_rabbit_d,
	&mat_item_cooked_rabbit_d,
	&mat_item_rabbit_stew_d,
	&mat_item_rabbit_foot_d,
	&mat_item_rabbit_hide_d,
	&mat_item_armor_stand_d,
	&mat_item_iron_horse_armor_d,
	&mat_item_golden_horse_armor_d,
	&mat_item_diamond_horse_armor_d,
	&mat_item_leather_horse_armor_d,
	&mat_item_lead_d,
	&mat_item_name_tag_d,
	&mat_item_command_block_minecart_d,
	&mat_item_mutton_d,
	&mat_item_cooked_mutton_d,
	&mat_item_white_banner_d,
	&mat_item_orange_banner_d,
	&mat_item_magenta_banner_d,
	&mat_item_light_blue_banner_d,
	&mat_item_yellow_banner_d,
	&mat_item_lime_banner_d,
	&mat_item_pink_banner_d,
	&mat_item_gray_banner_d,
	&mat_item_light_gray_banner_d,
	&mat_item_cyan_banner_d,
	&mat_item_purple_banner_d,
	&mat_item_blue_banner_d,
	&mat_item_brown_banner_d,
	&mat_item_green_banner_d,
	&mat_item_red_banner_d,
	&mat_item_black_banner_d,
	&mat_item_end_crystal_d,
	&mat_item_chorus_fruit_d,
	&mat_item_popped_chorus_fruit_d,
	&mat_item_beetroot_d,
	&mat_item_beetroot_seeds_d,
	&mat_item_beetroot_soup_d,
	&mat_item_dragon_breath_d,
	&mat_item_splash_potion_d,
	&mat_item_spectral_arrow_d,
	&mat_item_tipped_arrow_d,
	&mat_item_lingering_potion_d,
	&mat_item_shield_d,
	&mat_item_totem_of_undying_d,
	&mat_item_shulker_shell_d,
	&mat_item_iron_nugget_d,
	&mat_item_knowledge_book_d,
	&mat_item_debug_stick_d,
	&mat_item_music_disc_13_d,
	&mat_item_music_disc_cat_d,
	&mat_item_music_disc_blocks_d,
	&mat_item_music_disc_chirp_d,
	&mat_item_music_disc_far_d,
	&mat_item_music_disc_mall_d,
	&mat_item_music_disc_mellohi_d,
	&mat_item_music_disc_stal_d,
	&mat_item_music_disc_strad_d,
	&mat_item_music_disc_ward_d,
	&mat_item_music_disc_11_d,
	&mat_item_music_disc_wait_d,
	&mat_item_music_disc_otherside_d,
	&mat_item_music_disc_pigstep_d,
	&mat_item_trident_d,
	&mat_item_phantom_membrane_d,
	&mat_item_nautilus_shell_d,
	&mat_item_heart_of_the_sea_d,
	&mat_item_crossbow_d,
	&mat_item_suspicious_stew_d,
	&mat_item_loom_d,
	&mat_item_flower_banner_pattern_d,
	&mat_item_creeper_banner_pattern_d,
	&mat_item_skull_banner_pattern_d,
	&mat_item_mojang_banner_pattern_d,
	&mat_item_globe_banner_pattern_d,
	&mat_item_piglin_banner_pattern_d,
	&mat_item_composter_d,
	&mat_item_barrel_d,
	&mat_item_smoker_d,
	&mat_item_blast_furnace_d,
	&mat_item_cartography_table_d,
	&mat_item_fletching_table_d,
	&mat_item_grindstone_d,
	&mat_item_smithing_table_d,
	&mat_item_stonecutter_d,
	&mat_item_bell_d,
	&mat_item_lantern_d,
	&mat_item_soul_lantern_d,
	&mat_item_sweet_berries_d,
	&mat_item_glow_berries_d,
	&mat_item_campfire_d,
	&mat_item_soul_campfire_d,
	&mat_item_shroomlight_d,
	&mat_item_honeycomb_d,
	&mat_item_bee_nest_d,
	&mat_item_beehive_d,
	&mat_item_honey_bottle_d,
	&mat_item_honeycomb_block_d,
	&mat_item_lodestone_d,
	&mat_item_crying_obsidian_d,
	&mat_item_blackstone_d,
	&mat_item_blackstone_slab_d,
	&mat_item_blackstone_stairs_d,
	&mat_item_gilded_blackstone_d,
	&mat_item_polished_blackstone_d,
	&mat_item_polished_blackstone_slab_d,
	&mat_item_polished_blackstone_stairs_d,
	&mat_item_chiseled_polished_blackstone_d,
	&mat_item_polished_blackstone_bricks_d,
	&mat_item_polished_blackstone_brick_slab_d,
	&mat_item_polished_blackstone_brick_stairs_d,
	&mat_item_cracked_polished_blackstone_bricks_d,
	&mat_item_respawn_anchor_d,
	&mat_item_candle_d,
	&mat_item_white_candle_d,
	&mat_item_orange_candle_d,
	&mat_item_magenta_candle_d,
	&mat_item_light_blue_candle_d,
	&mat_item_yellow_candle_d,
	&mat_item_lime_candle_d,
	&mat_item_pink_candle_d,
	&mat_item_gray_candle_d,
	&mat_item_light_gray_candle_d,
	&mat_item_cyan_candle_d,
	&mat_item_purple_candle_d,
	&mat_item_blue_candle_d,
	&mat_item_brown_candle_d,
	&mat_item_green_candle_d,
	&mat_item_red_candle_d,
	&mat_item_black_candle_d,
	&mat_item_small_amethyst_bud_d,
	&mat_item_medium_amethyst_bud_d,
	&mat_item_large_amethyst_bud_d,
	&mat_item_amethyst_cluster_d,
	&mat_item_pointed_dripstone_d,
};
