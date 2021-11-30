#include "blocks.h"

const mat_block_t mat_block_air_d = {
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.air = true,
	.parrots_spawnable_on = true,
};
const mat_block_t mat_block_acacia_button_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_buttons = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_face,
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_powered
	}
};
const mat_block_t mat_block_acacia_door_d = { 
	.resistance = 3,
	.hardness = 3,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_doors = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_door_half,
		mat_state_modifier_door_hinge,
		mat_state_modifier_door_open,
		mat_state_modifier_powered
	}
};
const mat_block_t mat_block_acacia_fence_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_fences = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_acacia_fence_gate_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.fence_gates = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_fencegate_in_wall,
		mat_state_modifier_open,
		mat_state_modifier_powered
	},
	.unstable_bottom_center = true,
};
const mat_block_t mat_block_acacia_leaves_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.encouragement = 30,
	.flammability = 60,
	.transparent = true,
	.catches_fire_from_lava = true,
	.light_filtering = true,
	.mineable_hoe = true,
	.mineable = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_distance,
		mat_state_modifier_leaves_persistant
	},
	.lava_pool_stone_replaceables = true,
	.leaves = true,
	.parrots_spawnable_on = true,
};
const mat_block_t mat_block_acacia_log_d = { 
	.resistance = 2,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.logs_that_burn = true,
	.acacia_logs = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_acacia_planks_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.planks = true
};
const mat_block_t mat_block_acacia_pressure_plate_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_pressure_plates = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_powered
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_acacia_sapling_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_sapling_stage
	},
	.mineable_axe = true,
	.mineable = true,
	.saplings = true
};
const mat_block_t mat_block_acacia_sign_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_sign,
	.mineable_axe = true,
	.mineable = true,
	.signs = true,
	.standing_signs = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_rotation,
		mat_state_modifier_waterlogged
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_acacia_slab_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_slabs = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_acacia_stairs_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_stairs = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_acacia_trapdoor_d = { 
	.resistance = 3,
	.hardness = 3,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_trapdoors = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_trapdoor_half,
		mat_state_modifier_trapdoor_open,
		mat_state_modifier_powered,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_acacia_wood_d = { 
	.resistance = 2,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.logs_that_burn = true,
	.acacia_logs = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_activator_rail_d = { 
	.resistance = 0.7,
	.hardness = 0.7,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_powered,
		mat_state_modifier_special_rail_shape,
		mat_state_modifier_waterlogged
	},
	.prevent_mob_spawning_inside = true,
	.rails = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_allium_d = { 
	.resistance = 0,
	.hardness = 0,
	.encouragement = 60,
	.flammability = 100,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.flowers = true,
	.small_flowers = true,
	.enderman_holdable = true,
};
const mat_block_t mat_block_amethyst_cluster_d = { 
	.resistance = 1.5,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_ancient_debris_d = {
	.resistance = 1200,
	.hardness = 30,
	.needs_diamond_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_andesite_d = {
	.resistance = 6,
	.hardness = 1.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.base_stone_overworld = true,
	.dripstone_replaceable_blocks = true,
	.lush_ground_replaceable = true,
	.azalea_root_replaceable = true,
	.moss_replaceable = true,
	.stone_ore_replaceables = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_andesite_slab_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_andesite_stairs_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_andesite_wall_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_wall_east,
		mat_state_modifier_wall_north,
		mat_state_modifier_wall_south,
		mat_state_modifier_up,
		mat_state_modifier_waterlogged,
		mat_state_modifier_wall_west
	},
	.walls = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_anvil_d = { 
	.resistance = 1200,
	.hardness = 5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.anvil = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_azalea_d = { 
	.resistance = 0,
	.hardness = 0,
	.mineable_axe = true,
	.mineable = true,
	.saplings = true
};
const mat_block_t mat_block_azalea_leaves_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.encouragement = 30,
	.flammability = 60,
	.transparent = true,
	.catches_fire_from_lava = true,
	.light_filtering = true,
	.mineable_hoe = true,
	.mineable = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_distance,
		mat_state_modifier_leaves_persistant
	},
	.lava_pool_stone_replaceables = true,
	.leaves = true,
	.parrots_spawnable_on = true,
};
const mat_block_t mat_block_azure_bluet_d = { 
	.resistance = 0,
	.hardness = 0,
	.encouragement = 60,
	.flammability = 100,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.flowers = true,
	.small_flowers = true,
	.enderman_holdable = true,
};
const mat_block_t mat_block_bamboo_d = { 
	.resistance = 1,
	.hardness = 1,
	.encouragement = 60,
	.flammability = 60,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_bamboo_age,
		mat_state_modifier_bamboo_leaves,
		mat_state_modifier_bamboo_stage
	},
	.bamboo_plantable_on = true,
};
const mat_block_t mat_block_bamboo_sapling_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.catches_fire_from_lava = true,
	.bamboo_plantable_on = true,
};
const mat_block_t mat_block_beetroots_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_beetroot_age
	},
	.bee_growables = true,
	.crops = true,
};
const mat_block_t mat_block_barrel_d = { 
	.resistance = 2.5,
	.hardness = 2.5,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_container,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing,
		mat_state_modifier_open
	},
	.guarded_by_piglins = true,
};
const mat_block_t mat_block_barrier_d = {
	.resistance = 3600000.8,
	.hardness = -1,
	.transparent = true,
	.dragon_immune = true,
	.wither_immune = true,
};
const mat_block_t mat_block_basalt_d = {
	.resistance = 4.2,
	.hardness = 1.25,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.base_stone_nether = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_beacon_d = { 
	.resistance = 3,
	.hardness = 3,
	.light_filtering = true,
	.transparent = true,
	.luminance = 15,
	.entity = mat_block_entity_beacon
};
const mat_block_t mat_block_bedrock_d = {
	.resistance = 3600000,
	.hardness = -1,
	.dragon_immune = true,
	.features_cannot_replace = true,
	.geode_invalid_blocks = true,
	.infiniburn_end = true,
	.lava_pool_stone_replaceables = true,
	.wither_immune = true,
};
const mat_block_t mat_block_beehive_d = { 
	.resistance = 0.6,
	.hardness = 0.6,
	.encouragement = 5,
	.flammability = 20,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_bees,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_hive_honey_level
	},
	.beehives = true,
};
const mat_block_t mat_block_bee_nest_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.encouragement = 30,
	.flammability = 20,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_bees,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_hive_honey_level
	},
	.beehives = true,
};
const mat_block_t mat_block_bell_d = {
	.resistance = 5,
	.hardness = 5,
	.transparent = true,
	.entity = mat_block_entity_bell,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_bell_attachment,
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_powered
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_big_dripleaf_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_dripleaf_tilt,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_birch_button_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_buttons = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_face,
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_powered
	}
};
const mat_block_t mat_block_birch_door_d = { 
	.resistance = 3,
	.hardness = 3,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_doors = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_door_half,
		mat_state_modifier_door_hinge,
		mat_state_modifier_door_open,
		mat_state_modifier_powered
	}
};
const mat_block_t mat_block_birch_fence_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_fences = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_birch_fence_gate_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.fence_gates = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_fencegate_in_wall,
		mat_state_modifier_open,
		mat_state_modifier_powered
	},
	.unstable_bottom_center = true,
};
const mat_block_t mat_block_birch_leaves_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.encouragement = 30,
	.flammability = 60,
	.transparent = true,
	.catches_fire_from_lava = true,
	.light_filtering = true,
	.mineable_hoe = true,
	.mineable = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_distance,
		mat_state_modifier_leaves_persistant
	},
	.lava_pool_stone_replaceables = true,
	.leaves = true,
	.parrots_spawnable_on = true,
};
const mat_block_t mat_block_birch_log_d = { 
	.resistance = 2,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.logs_that_burn = true,
	.birch_logs = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_birch_planks_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.planks = true
};
const mat_block_t mat_block_birch_pressure_plate_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_pressure_plates = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_powered
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_birch_sapling_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_sapling_stage
	},
	.mineable_axe = true,
	.mineable = true,
	.saplings = true
};
const mat_block_t mat_block_birch_sign_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_sign,
	.mineable_axe = true,
	.mineable = true,
	.signs = true,
	.standing_signs = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_rotation,
		mat_state_modifier_waterlogged
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_birch_slab_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_slabs = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_birch_stairs_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_stairs = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_birch_trapdoor_d = { 
	.resistance = 3,
	.hardness = 3,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_trapdoors = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_trapdoor_half,
		mat_state_modifier_trapdoor_open,
		mat_state_modifier_powered,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_birch_wood_d = { 
	.resistance = 2,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.logs_that_burn = true,
	.birch_logs = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_black_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_rotation
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_black_bed_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_bed,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_bed_occupied,
		mat_state_modifier_bed_part
	},
	.beds = true,
};
const mat_block_t mat_block_black_candle_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_candle_candles,
		mat_state_modifier_lit,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_black_carpet_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.encouragement = 60,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.carpets = true,
};
const mat_block_t mat_block_black_concrete_d = { 
	.resistance = 1.8,
	.hardness = 1.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_black_concrete_powder_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.mineable_shovel = true,
	.mineable = true,
};
const mat_block_t mat_block_black_glazed_terracotta_d = { 
	.resistance = 1.4,
	.hardness = 1.4,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_black_shulker_box_d = { 
	.resistance = 2,
	.hardness = 2,
	.light_filtering = true,
	.transparent = true,
	.entity = mat_block_entity_locational_container,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing
	},
	.guarded_by_piglins = true,
	.shulker_boxes = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_black_stained_glass_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.impermeable = true,
};
const mat_block_t mat_block_black_stained_glass_pane_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_black_terracotta_d = { 
	.resistance = 4.2,
	.hardness = 1.25,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
	.terracotta = true,
	.azalea_root_replaceable = true,
	.azalea_grows_on = true,
};
const mat_block_t mat_block_black_wool_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.encouragement = 30,
	.flammability = 60,
	.catches_fire_from_lava = true,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_block_t mat_block_blackstone_d = {
	.resistance = 6,
	.hardness = 1.5,
	.base_stone_nether = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_blackstone_slab_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_blackstone_stairs_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_blackstone_wall_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_wall_east,
		mat_state_modifier_wall_north,
		mat_state_modifier_wall_south,
		mat_state_modifier_up,
		mat_state_modifier_waterlogged,
		mat_state_modifier_wall_west
	},
	.walls = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_blast_furnace_d = {
	.resistance = 3.5,
	.hardness = 3.5,
	.entity = mat_block_entity_furnace,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_lit
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_amethyst_block_d = { 
	.resistance = 1.5,
	.hardness = 1.5,
	.crystal_sound_blocks = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_coal_block_d = {
	.resistance = 6,
	.hardness = 5,
	.encouragement = 5,
	.flammability = 5,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_copper_block_d = {
	.resistance = 6,
	.hardness = 3,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_diamond_block_d = {
	.resistance = 6,
	.hardness = 5,
	.beacon_base_blocks = true,
	.needs_iron_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_emerald_block_d = {
	.resistance = 6,
	.hardness = 5,
	.beacon_base_blocks = true,
	.needs_iron_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_gold_block_d = {
	.resistance = 6,
	.hardness = 3,
	.beacon_base_blocks = true,
	.guarded_by_piglins = true,
	.needs_iron_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_iron_block_d = {
	.resistance = 6,
	.hardness = 5,
	.beacon_base_blocks = true,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_lapis_block_d = { 
	.resistance = 3,
	.hardness = 3,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_netherite_block_d = {
	.resistance = 1200,
	.hardness = 50,
	.beacon_base_blocks = true,
	.needs_diamond_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_quartz_block_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_raw_copper_block_d = { 
	.resistance = 6,
	.hardness = 5,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_raw_gold_block_d = { 
	.resistance = 6,
	.hardness = 5,
	.guarded_by_piglins = true,
	.needs_iron_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_raw_iron_block_d = { 
	.resistance = 6,
	.hardness = 5,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_redstone_block_d = {
	.resistance = 6,
	.hardness = 5,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_blue_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_rotation
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_blue_bed_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_bed,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_bed_occupied,
		mat_state_modifier_bed_part
	},
	.beds = true,
};
const mat_block_t mat_block_blue_candle_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_candle_candles,
		mat_state_modifier_lit,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_blue_carpet_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.encouragement = 60,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.carpets = true,
};
const mat_block_t mat_block_blue_concrete_d = { 
	.resistance = 1.8,
	.hardness = 1.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_blue_concrete_powder_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.mineable_shovel = true,
	.mineable = true,
};
const mat_block_t mat_block_blue_glazed_terracotta_d = { 
	.resistance = 1.4,
	.hardness = 1.4,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_blue_ice_d = { 
	.resistance = 2.8,
	.hardness = 2.8,
	.geode_invalid_blocks = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.ice = true,
};
const mat_block_t mat_block_blue_orchid_d = { 
	.resistance = 0,
	.hardness = 0,
	.encouragement = 60,
	.flammability = 100,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.flowers = true,
	.small_flowers = true,
	.enderman_holdable = true,
};
const mat_block_t mat_block_blue_shulker_box_d = { 
	.resistance = 2,
	.hardness = 2,
	.light_filtering = true,
	.transparent = true,
	.entity = mat_block_entity_locational_container,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing
	},
	.guarded_by_piglins = true,
	.shulker_boxes = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_blue_stained_glass_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.impermeable = true,
};
const mat_block_t mat_block_blue_stained_glass_pane_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_blue_terracotta_d = { 
	.resistance = 4.2,
	.hardness = 1.25,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
	.terracotta = true,
	.azalea_root_replaceable = true,
	.azalea_grows_on = true,
};
const mat_block_t mat_block_blue_wool_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.encouragement = 30,
	.flammability = 60,
	.catches_fire_from_lava = true,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_block_t mat_block_bone_block_d = { 
	.resistance = 2,
	.hardness = 2,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_bookshelf_d = { 
	.resistance = 1.5,
	.hardness = 1.5,
	.encouragement = 30,
	.flammability = 20,
	.catches_fire_from_lava = true,
	.mineable_axe = true
};
const mat_block_t mat_block_brain_coral_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_waterlogged
	},
	.corals = true,
	.coral_plants = true,
	.underwater_bonemeals = true,
};
const mat_block_t mat_block_brain_coral_block_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.coral_blocks = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_brain_coral_fan_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_waterlogged
	},
	.corals = true,
	.underwater_bonemeals = true,
};
const mat_block_t mat_block_brewing_stand_d = {
	.resistance = 0.5,
	.hardness = 0.5,
	.luminance = 1,
	.transparent = true,
	.entity = mat_block_entity_brewing,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_brewing_stand_has_bottle_0,
		mat_state_modifier_brewing_stand_has_bottle_1,
		mat_state_modifier_brewing_stand_has_bottle_2
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_brick_slab_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_brick_stairs_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_brick_wall_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_wall_east,
		mat_state_modifier_wall_north,
		mat_state_modifier_wall_south,
		mat_state_modifier_up,
		mat_state_modifier_waterlogged,
		mat_state_modifier_wall_west
	},
	.walls = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_bricks_d = { 
	.resistance = 6,
	.hardness = 2,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_brown_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_rotation
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_brown_bed_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_bed,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_bed_occupied,
		mat_state_modifier_bed_part
	},
	.beds = true,
};
const mat_block_t mat_block_brown_candle_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_candle_candles,
		mat_state_modifier_lit,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_brown_carpet_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.encouragement = 60,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.carpets = true,
};
const mat_block_t mat_block_brown_concrete_d = { 
	.resistance = 1.8,
	.hardness = 1.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_brown_concrete_powder_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.mineable_shovel = true,
	.mineable = true,
};
const mat_block_t mat_block_brown_glazed_terracotta_d = { 
	.resistance = 1.4,
	.hardness = 1.4,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_brown_mushroom_d = { 
	.resistance = 0,
	.hardness = 0,
	.luminance = 1,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.enderman_holdable = true,
};
const mat_block_t mat_block_brown_mushroom_block_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_down,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_up,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_brown_shulker_box_d = { 
	.resistance = 2,
	.hardness = 2,
	.light_filtering = true,
	.transparent = true,
	.entity = mat_block_entity_locational_container,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing
	},
	.guarded_by_piglins = true,
	.shulker_boxes = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_brown_stained_glass_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.impermeable = true,
};
const mat_block_t mat_block_brown_stained_glass_pane_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_brown_terracotta_d = { 
	.resistance = 4.2,
	.hardness = 1.25,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
	.terracotta = true,
	.azalea_root_replaceable = true,
	.azalea_grows_on = true,
};
const mat_block_t mat_block_brown_wool_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.encouragement = 30,
	.flammability = 60,
	.catches_fire_from_lava = true,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_block_t mat_block_bubble_coral_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_waterlogged
	},
	.corals = true,
	.coral_plants = true,
	.underwater_bonemeals = true,
};
const mat_block_t mat_block_bubble_coral_block_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.coral_blocks = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_bubble_coral_fan_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_waterlogged
	},
	.corals = true,
	.underwater_bonemeals = true,
};
const mat_block_t mat_block_budding_amethyst_d = { 
	.resistance = 1.5,
	.hardness = 1.5,
	.crystal_sound_blocks = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_cactus_d = { 
	.resistance = 0.4,
	.hardness = 0.4,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_stock_age
	},
	.enderman_holdable = true,
};
const mat_block_t mat_block_cake_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_cake_bites
	}
};
const mat_block_t mat_block_calcite_d = { 
	.resistance = 0.75,
	.hardness = 0.75,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_campfire_d = { 
	.resistance = 2,
	.hardness = 2,
	.transparent = true,
	.catches_fire_from_lava = true,
	.luminance = 15,
	.entity = mat_block_entity_container,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_lit,
		mat_state_modifier_campfire_signal,
		mat_state_modifier_waterlogged
	},
	.campfires = true,
};
const mat_block_t mat_block_candle_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_candle_candles,
		mat_state_modifier_lit,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_carrots_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_crop_age
	},
	.bee_growables = true,
	.crops = true,
};
const mat_block_t mat_block_cartography_table_d = { 
	.resistance = 2.5,
	.hardness = 2.5,
	.catches_fire_from_lava = true,
	.mineable_axe = true
};
const mat_block_t mat_block_carved_pumpkin_d = { 
	.resistance = 1,
	.hardness = 1,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.enderman_holdable = true,
};
const mat_block_t mat_block_cauldron_d = { 
	.resistance = 2,
	.hardness = 2,
	.transparent = true,
	.cauldrons = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_cave_vines_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_vine_age,
		mat_state_modifier_cave_vines_berries
	},
	.bee_growables = true,
	.climbable = true,
	.lush_ground_replaceable = true,
	.azalea_root_replaceable = true,
	.moss_replaceable = true,
};
const mat_block_t mat_block_chain_d = { 
	.resistance = 6,
	.hardness = 5,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_axis,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_chain_command_block_d = { 
	.resistance = 3600000,
	.hardness = -1,
	.entity = mat_block_entity_command,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_command_block_conditional,
		mat_state_modifier_facing
	},
	.dragon_immune = true,
	.wither_immune = true,
};
const mat_block_t mat_block_chest_d = { 
	.resistance = 2.5,
	.hardness = 2.5,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_locational_container,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_chest_type,
		mat_state_modifier_waterlogged
	},
	.features_cannot_replace = true,
	.guarded_by_piglins = true,
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_chipped_anvil_d = { 
	.resistance = 1200,
	.hardness = 5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.anvil = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_chiseled_deepslate_d = { 
	.resistance = 6,
	.hardness = 3.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_chiseled_nether_bricks_d = { 
	.resistance = 6,
	.hardness = 2,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_chiseled_polished_blackstone_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_chiseled_quartz_block_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_chiseled_red_sandstone_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_chiseled_sandstone_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_chiseled_stone_bricks_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.stone_bricks = true,
};
const mat_block_t mat_block_chorus_flower_d = { 
	.resistance = 0.4,
	.hardness = 0.4,
	.light_filtering = true,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_chorus_flower_age
	}
};
const mat_block_t mat_block_chorus_plant_d = { 
	.resistance = 0.4,
	.hardness = 0.4,
	.light_filtering = true,
	.transparent = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_down,
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_up,
		mat_state_modifier_west
	},
	.mineable_axe = true,
	.mineable = true,
};
const mat_block_t mat_block_clay_d = { 
	.resistance = 0.6,
	.hardness = 0.6,
	.enderman_holdable = true,
	.lush_ground_replaceable = true,
	.azalea_root_replaceable = true,
	.small_dripleaf_placeable = true,
	.big_dripleaf_placeable = true,
	.mineable_shovel = true,
	.mineable = true,
	.axolotls_spawnable_on = true,
};
const mat_block_t mat_block_coal_ore_d = { 
	.resistance = 3,
	.hardness = 3,
	.coal_ores = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_coarse_dirt_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.bamboo_plantable_on = true,
	.enderman_holdable = true,
	.lush_ground_replaceable = true,
	.azalea_root_replaceable = true,
	.moss_replaceable = true,
	.mineable_shovel = true,
	.mineable = true,
	.dirt = true,
	.big_dripleaf_placeable = true,
	.azalea_grows_on = true,
	.foxes_spawnable_on = true,
};
const mat_block_t mat_block_cobbled_deepslate_d = { 
	.resistance = 6,
	.hardness = 3.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_cobbled_deepslate_slab_d = { 
	.resistance = 6,
	.hardness = 3.5,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_cobbled_deepslate_stairs_d = { 
	.resistance = 6,
	.hardness = 3.5,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_cobbled_deepslate_wall_d = { 
	.resistance = 6,
	.hardness = 3.5,
	.transparent = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_wall_east,
		mat_state_modifier_wall_north,
		mat_state_modifier_wall_south,
		mat_state_modifier_up,
		mat_state_modifier_waterlogged,
		mat_state_modifier_wall_west
	},
	.walls = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_cobblestone_d = {
	.resistance = 6,
	.hardness = 2,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_cobblestone_slab_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_cobblestone_stairs_d = {
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_cobblestone_wall_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_wall_east,
		mat_state_modifier_wall_north,
		mat_state_modifier_wall_south,
		mat_state_modifier_up,
		mat_state_modifier_waterlogged,
		mat_state_modifier_wall_west
	},
	.walls = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_cobweb_d = {
	.resistance = 4,
	.hardness = 4,
	.light_filtering = true,
	.transparent = true,
};
const mat_block_t mat_block_cocoa_d = { 
	.resistance = 3,
	.hardness = 0.2,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_cocoa_age,
		mat_state_modifier_facing_cardinal
	}
};
const mat_block_t mat_block_command_block_d = {
	.resistance = 3600000,
	.hardness = -1,
	.entity = mat_block_entity_command,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_command_block_conditional,
		mat_state_modifier_facing
	},
	.dragon_immune = true,
	.wither_immune = true,
};
const mat_block_t mat_block_composter_d = { 
	.resistance = 0.6,
	.hardness = 0.6,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_composter_level
	}
};
const mat_block_t mat_block_conduit_d = { 
	.resistance = 3,
	.hardness = 3,
	.luminance = 15,
	.transparent = true,
	.entity = mat_block_entity_conduit,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_waterlogged
	},
	.mineable = true,
	.mineable_pickaxe = true,
};
const mat_block_t mat_block_copper_ore_d = { 
	.resistance = 3,
	.hardness = 3,
	.copper_ores = true,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_cornflower_d = { 
	.resistance = 0,
	.hardness = 0,
	.encouragement = 60,
	.flammability = 100,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.flowers = true,
	.small_flowers = true,
	.enderman_holdable = true,
};
const mat_block_t mat_block_cracked_deepslate_bricks_d = { 
	.resistance = 6,
	.hardness = 3.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_cracked_deepslate_tiles_d = { 
	.resistance = 6,
	.hardness = 3.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_cracked_nether_bricks_d = { 
	.resistance = 6,
	.hardness = 2,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_cracked_polished_blackstone_bricks_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_cracked_stone_bricks_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.stone_bricks = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_crafting_table_d = { 
	.resistance = 2.5,
	.hardness = 2.5,
	.catches_fire_from_lava = true,
	.mineable_axe = true
};
const mat_block_t mat_block_creeper_head_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_rotation
	}
};
const mat_block_t mat_block_crimson_button_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_buttons = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_face,
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_powered
	},
	.non_flammable_wood = true,
};
const mat_block_t mat_block_crimson_door_d = { 
	.resistance = 3,
	.hardness = 3,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_doors = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_door_half,
		mat_state_modifier_door_hinge,
		mat_state_modifier_door_open,
		mat_state_modifier_powered
	},
	.non_flammable_wood = true,
};
const mat_block_t mat_block_crimson_fence_d = { 
	.resistance = 3,
	.hardness = 2,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_fences = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	},
	.non_flammable_wood = true,
};
const mat_block_t mat_block_crimson_fence_gate_d = { 
	.resistance = 3,
	.hardness = 2,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.fence_gates = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_fencegate_in_wall,
		mat_state_modifier_open,
		mat_state_modifier_powered
	},
	.non_flammable_wood = true,
	.unstable_bottom_center = true,
};
const mat_block_t mat_block_crimson_fungus_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.enderman_holdable = true,
};
const mat_block_t mat_block_crimson_hyphae_d = { 
	.resistance = 2,
	.hardness = 2,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.crimson_stems = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
	.non_flammable_wood = true,
};
const mat_block_t mat_block_crimson_nylium_d = { 
	.resistance = 0.4,
	.hardness = 0.4,
	.enderman_holdable = true,
	.mushroom_grow_block = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.nylium = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_crimson_planks_d = { 
	.resistance = 3,
	.hardness = 2,
	.mineable_axe = true,
	.mineable = true,
	.planks = true,
	.non_flammable_wood = true,
};
const mat_block_t mat_block_crimson_pressure_plate_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_pressure_plates = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_powered
	},
	.non_flammable_wood = true,
	.wall_post_override = true,
};
const mat_block_t mat_block_crimson_roots_d = { 
	.resistance = 0,
	.hardness = 0,
	.catches_fire_from_lava = true,
	.transparent = true,
	.enderman_holdable = true,
};
const mat_block_t mat_block_crimson_sign_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_sign,
	.mineable_axe = true,
	.mineable = true,
	.signs = true,
	.standing_signs = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_rotation,
		mat_state_modifier_waterlogged
	},
	.non_flammable_wood = true,
	.wall_post_override = true,
};
const mat_block_t mat_block_crimson_slab_d = { 
	.resistance = 3,
	.hardness = 2,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_slabs = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.non_flammable_wood = true,
};
const mat_block_t mat_block_crimson_stairs_d = { 
	.resistance = 3,
	.hardness = 2,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_stairs = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.non_flammable_wood = true,
};
const mat_block_t mat_block_crimson_stem_d = { 
	.resistance = 2,
	.hardness = 2,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.crimson_stems = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
	.non_flammable_wood = true,
};
const mat_block_t mat_block_crimson_trapdoor_d = { 
	.resistance = 3,
	.hardness = 3,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_trapdoors = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_trapdoor_half,
		mat_state_modifier_trapdoor_open,
		mat_state_modifier_powered,
		mat_state_modifier_waterlogged
	},
	.non_flammable_wood = true,
};
const mat_block_t mat_block_crying_obsidian_d = { 
	.resistance = 1200,
	.hardness = 50,
	.dragon_immune = true,
	.needs_diamond_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_cut_copper_d = { 
	.resistance = 6,
	.hardness = 3,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_cut_copper_slab_d = { 
	.resistance = 6,
	.hardness = 3,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.needs_stone_tool = true,
	.needs = true,
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_cut_copper_stairs_d = { 
	.resistance = 6,
	.hardness = 3,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_cut_red_sandstone_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_cut_red_sandstone_slab_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_cut_sandstone_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_cut_sandstone_slab_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_cyan_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_rotation
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_cyan_bed_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_bed,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_bed_occupied,
		mat_state_modifier_bed_part
	},
	.beds = true,
};
const mat_block_t mat_block_cyan_candle_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_candle_candles,
		mat_state_modifier_lit,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_cyan_carpet_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.encouragement = 60,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.carpets = true,
};
const mat_block_t mat_block_cyan_concrete_d = { 
	.resistance = 1.8,
	.hardness = 1.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_cyan_concrete_powder_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.mineable_shovel = true,
	.mineable = true,
};
const mat_block_t mat_block_cyan_glazed_terracotta_d = { 
	.resistance = 1.4,
	.hardness = 1.4,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_cyan_shulker_box_d = { 
	.resistance = 2,
	.hardness = 2,
	.light_filtering = true,
	.transparent = true,
	.entity = mat_block_entity_locational_container,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing
	},
	.guarded_by_piglins = true,
	.shulker_boxes = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_cyan_stained_glass_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.impermeable = true,
};
const mat_block_t mat_block_cyan_stained_glass_pane_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_cyan_terracotta_d = { 
	.resistance = 4.2,
	.hardness = 1.25,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
	.terracotta = true,
	.azalea_root_replaceable = true,
	.azalea_grows_on = true,
};
const mat_block_t mat_block_cyan_wool_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.encouragement = 30,
	.flammability = 60,
	.catches_fire_from_lava = true,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_block_t mat_block_damaged_anvil_d = { 
	.resistance = 1200,
	.hardness = 5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.anvil = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_dandelion_d = { 
	.resistance = 0,
	.hardness = 0,
	.encouragement = 60,
	.flammability = 100,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.flowers = true,
	.small_flowers = true,
	.enderman_holdable = true,
};
const mat_block_t mat_block_dark_oak_button_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_buttons = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_face,
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_powered
	}
};
const mat_block_t mat_block_dark_oak_door_d = { 
	.resistance = 3,
	.hardness = 3,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_doors = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_door_half,
		mat_state_modifier_door_hinge,
		mat_state_modifier_door_open,
		mat_state_modifier_powered
	}
};
const mat_block_t mat_block_dark_oak_fence_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_fences = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_dark_oak_fence_gate_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.fence_gates = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_fencegate_in_wall,
		mat_state_modifier_open,
		mat_state_modifier_powered
	},
	.unstable_bottom_center = true,
};
const mat_block_t mat_block_dark_oak_leaves_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.encouragement = 30,
	.flammability = 60,
	.transparent = true,
	.catches_fire_from_lava = true,
	.light_filtering = true,
	.mineable_hoe = true,
	.mineable = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_distance,
		mat_state_modifier_leaves_persistant
	},
	.lava_pool_stone_replaceables = true,
	.leaves = true,
	.parrots_spawnable_on = true,
};
const mat_block_t mat_block_dark_oak_log_d = { 
	.resistance = 2,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.logs_that_burn = true,
	.dark_oak_logs = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_dark_oak_planks_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.planks = true
};
const mat_block_t mat_block_dark_oak_pressure_plate_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_pressure_plates = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_powered
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_dark_oak_sapling_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_sapling_stage
	},
	.mineable_axe = true,
	.mineable = true,
	.saplings = true
};
const mat_block_t mat_block_dark_oak_sign_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_sign,
	.mineable_axe = true,
	.mineable = true,
	.signs = true,
	.standing_signs = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_rotation,
		mat_state_modifier_waterlogged
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_dark_oak_slab_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_slabs = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_dark_oak_stairs_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_stairs = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_dark_oak_trapdoor_d = { 
	.resistance = 3,
	.hardness = 3,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_trapdoors = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_trapdoor_half,
		mat_state_modifier_trapdoor_open,
		mat_state_modifier_powered,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_dark_oak_wood_d = { 
	.resistance = 2,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.logs_that_burn = true,
	.dark_oak_logs = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_dark_prismarine_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_dark_prismarine_slab_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_dark_prismarine_stairs_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_daylight_detector_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_daylight,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_daylight_detector_inverted,
		mat_state_modifier_power
	}
};
const mat_block_t mat_block_dead_brain_coral_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_dead_brain_coral_block_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_dead_brain_coral_fan_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_dead_bubble_coral_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_dead_bubble_coral_block_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_dead_bubble_coral_fan_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_dead_bush_d = { 
	.resistance = 0,
	.hardness = 0,
	.encouragement = 60,
	.flammability = 100,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
};
const mat_block_t mat_block_dead_fire_coral_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_dead_fire_coral_block_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_dead_fire_coral_fan_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_dead_horn_coral_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_dead_horn_coral_block_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_dead_horn_coral_fan_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_dead_tube_coral_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_dead_tube_coral_block_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_dead_tube_coral_fan_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_deepslate_d = { 
	.resistance = 6,
	.hardness = 3,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.base_stone_overworld = true,
	.deepslate_ore_replaceables = true,
	.dripstone_replaceable_blocks = true,
	.lush_ground_replaceable = true,
	.azalea_root_replaceable = true,
	.moss_replaceable = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_deepslate_bricks_d = { 
	.resistance = 6,
	.hardness = 3.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_deepslate_brick_slab_d = { 
	.resistance = 6,
	.hardness = 3.5,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_deepslate_brick_stairs_d = { 
	.resistance = 6,
	.hardness = 3.5,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_deepslate_brick_wall_d = { 
	.resistance = 6,
	.hardness = 3.5,
	.transparent = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_wall_east,
		mat_state_modifier_wall_north,
		mat_state_modifier_wall_south,
		mat_state_modifier_up,
		mat_state_modifier_waterlogged,
		mat_state_modifier_wall_west
	},
	.walls = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_deepslate_coal_ore_d = { 
	.resistance = 3,
	.hardness = 4.5,
	.coal_ores = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_deepslate_copper_ore_d = { 
	.resistance = 3,
	.hardness = 4.5,
	.copper_ores = true,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_deepslate_diamond_ore_d = { 
	.resistance = 3,
	.hardness = 4.5,
	.diamond_ores = true,
	.needs_iron_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_deepslate_emerald_ore_d = { 
	.resistance = 3,
	.hardness = 4.5,
	.emerald_ores = true,
	.needs_iron_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_deepslate_gold_ore_d = { 
	.resistance = 3,
	.hardness = 4.5,
	.gold_ores = true,
	.guarded_by_piglins = true,
	.needs_iron_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_deepslate_iron_ore_d = { 
	.resistance = 3,
	.hardness = 4.5,
	.iron_ores = true,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_deepslate_lapis_ore_d = { 
	.resistance = 3,
	.hardness = 4.5,
	.lapis_ores = true,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_deepslate_redstone_ore_d = { 
	.resistance = 3,
	.hardness = 4.5,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_lit
	},
	.needs_iron_tool = true,
	.needs = true,
	.redstone_ores = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_deepslate_tiles_d = { 
	.resistance = 6,
	.hardness = 3.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_deepslate_tile_slab_d = { 
	.resistance = 6,
	.hardness = 3.5,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_deepslate_tile_stairs_d = { 
	.resistance = 6,
	.hardness = 3.5,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_deepslate_tile_wall_d = { 
	.resistance = 6,
	.hardness = 3.5,
	.transparent = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_wall_east,
		mat_state_modifier_wall_north,
		mat_state_modifier_wall_south,
		mat_state_modifier_up,
		mat_state_modifier_waterlogged,
		mat_state_modifier_wall_west
	},
	.walls = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_detector_rail_d = { 
	.resistance = 0.7,
	.hardness = 0.7,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_powered,
		mat_state_modifier_special_rail_shape,
		mat_state_modifier_waterlogged
	},
	.prevent_mob_spawning_inside = true,
	.rails = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_diamond_ore_d = {
	.resistance = 3,
	.hardness = 3,
	.diamond_ores = true,
	.needs_iron_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_diorite_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.base_stone_overworld = true,
	.dripstone_replaceable_blocks = true,
	.lush_ground_replaceable = true,
	.azalea_root_replaceable = true,
	.moss_replaceable = true,
	.stone_ore_replaceables = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_diorite_slab_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_diorite_stairs_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_diorite_wall_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_wall_east,
		mat_state_modifier_wall_north,
		mat_state_modifier_wall_south,
		mat_state_modifier_up,
		mat_state_modifier_waterlogged,
		mat_state_modifier_wall_west
	},
	.walls = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_dirt_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.bamboo_plantable_on = true,
	.dripstone_replaceable_blocks = true,
	.enderman_holdable = true,
	.lush_ground_replaceable = true,
	.azalea_root_replaceable = true,
	.moss_replaceable = true,
	.mineable_shovel = true,
	.mineable = true,
	.dirt = true,
	.big_dripleaf_placeable = true,
	.azalea_grows_on = true,
};
const mat_block_t mat_block_dirt_path_d = { 
	.resistance = 0.65,
	.hardness = 0.65,
	.mineable_shovel = true,
	.mineable = true,
};
const mat_block_t mat_block_dispenser_d = { 
	.resistance = 3.5,
	.hardness = 3.5,
	.entity = mat_block_entity_container,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing,
		mat_state_modifier_triggered
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_dragon_egg_d = { 
	.resistance = 9,
	.hardness = 3,
	.luminance = 1,
	.transparent = true,
};
const mat_block_t mat_block_dragon_head_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_rotation
	}
};
const mat_block_t mat_block_kelp_d = { 
	.resistance = 0,
	.hardness = 0,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_vine_age
	}
};
const mat_block_t mat_block_dripstone_block_d = { 
	.resistance = 1,
	.hardness = 1.5,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_dropper_d = { 
	.resistance = 3.5,
	.hardness = 3.5,
	.entity = mat_block_entity_container,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing,
		mat_state_modifier_triggered
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_emerald_ore_d = { 
	.resistance = 3,
	.hardness = 3,
	.emerald_ores = true,
	.needs_iron_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_enchanting_table_d = { 
	.resistance = 1200,
	.hardness = 5,
	.transparent = true,
	.entity = mat_block_entity_enchanting_table,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_end_portal_frame_d = { 
	.resistance = 3600000,
	.hardness = -1,
	.luminance = 1,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_end_portal_frame_eye
	},
	.dragon_immune = true,
	.features_cannot_replace = true,
	.lava_pool_stone_replaceables = true,
	.wither_immune = true,
};
const mat_block_t mat_block_end_rod_d = { 
	.resistance = 0,
	.hardness = 0,
	.luminance = 14,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing
	}
};
const mat_block_t mat_block_end_stone_d = { 
	.resistance = 9,
	.hardness = 3,
	.dragon_immune = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_end_stone_brick_slab_d = { 
	.resistance = 9,
	.hardness = 3,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_end_stone_brick_stairs_d = { 
	.resistance = 9,
	.hardness = 3,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_end_stone_brick_wall_d = { 
	.resistance = 9,
	.hardness = 3,
	.transparent = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_wall_east,
		mat_state_modifier_wall_north,
		mat_state_modifier_wall_south,
		mat_state_modifier_up,
		mat_state_modifier_waterlogged,
		mat_state_modifier_wall_west
	},
	.walls = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_end_stone_bricks_d = { 
	.resistance = 9,
	.hardness = 3,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_ender_chest_d = { 
	.resistance = 600,
	.hardness = 22.5,
	.luminance = 7,
	.transparent = true,
	.entity = mat_block_entity_end_particles,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_waterlogged
	},
	.guarded_by_piglins = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_exposed_copper_d = { 
	.resistance = 6,
	.hardness = 3,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_exposed_cut_copper_d = { 
	.resistance = 6,
	.hardness = 3,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_exposed_cut_copper_slab_d = { 
	.resistance = 6,
	.hardness = 3,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.needs_stone_tool = true,
	.needs = true,
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_exposed_cut_copper_stairs_d = { 
	.resistance = 6,
	.hardness = 3,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_farmland_d = { 
	.resistance = 0.6,
	.hardness = 0.6,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_farmland_moisture
	},
	.mineable_shovel = true,
	.mineable = true,
	.big_dripleaf_placeable = true,
};
const mat_block_t mat_block_fern_d = { 
	.resistance = 0,
	.hardness = 0,
	.encouragement = 60,
	.flammability = 100,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
};
const mat_block_t mat_block_fire_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_fire_age,
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_up,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_fire_coral_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_waterlogged
	},
	.corals = true,
	.coral_plants = true,
	.underwater_bonemeals = true,
};
const mat_block_t mat_block_fire_coral_block_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.coral_blocks = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_fire_coral_fan_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_waterlogged
	},
	.corals = true,
	.underwater_bonemeals = true,
};
const mat_block_t mat_block_fletching_table_d = { 
	.resistance = 2.5,
	.hardness = 2.5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
};
const mat_block_t mat_block_flower_pot_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_flowering_azalea_d = { 
	.resistance = 0,
	.hardness = 0,
	.mineable_axe = true,
	.mineable = true,
	.flowers = true,
	.saplings = true
};
const mat_block_t mat_block_flowering_azalea_leaves_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.encouragement = 30,
	.flammability = 60,
	.transparent = true,
	.catches_fire_from_lava = true,
	.light_filtering = true,
	.flowers = true,
	.mineable_hoe = true,
	.mineable = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_distance,
		mat_state_modifier_leaves_persistant
	},
	.lava_pool_stone_replaceables = true,
	.leaves = true,
	.parrots_spawnable_on = true,
};
const mat_block_t mat_block_furnace_d = { 
	.resistance = 3.5,
	.hardness = 3.5,
	.entity = mat_block_entity_furnace,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_lit
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_gilded_blackstone_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.guarded_by_piglins = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_glass_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.impermeable = true,
};
const mat_block_t mat_block_glass_pane_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_glow_lichen_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.luminance = 0,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 7,
	.modifiers = {
		mat_state_modifier_down,
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_up,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_glowstone_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.luminance = 15
};
const mat_block_t mat_block_gold_ore_d = { 
	.resistance = 3,
	.hardness = 3,
	.gold_ores = true,
	.guarded_by_piglins = true,
	.needs_iron_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_granite_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.base_stone_overworld = true,
	.dripstone_replaceable_blocks = true,
	.lush_ground_replaceable = true,
	.azalea_root_replaceable = true,
	.moss_replaceable = true,
	.stone_ore_replaceables = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_granite_slab_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_granite_stairs_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_granite_wall_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_wall_east,
		mat_state_modifier_wall_north,
		mat_state_modifier_wall_south,
		mat_state_modifier_up,
		mat_state_modifier_waterlogged,
		mat_state_modifier_wall_west
	},
	.walls = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_grass_d = { 
	.resistance = 0,
	.hardness = 0,
	.encouragement = 60,
	.flammability = 100,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
};
const mat_block_t mat_block_grass_block_d = { 
	.resistance = 0.6,
	.hardness = 0.6,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_grass_snowy
	},
	.bamboo_plantable_on = true,
	.dirt = true,
	.big_dripleaf_placeable = true,
	.azalea_grows_on = true,
	.enderman_holdable = true,
	.lush_ground_replaceable = true,
	.azalea_root_replaceable = true,
	.moss_replaceable = true,
	.valid_spawn = true,
	.mineable_shovel = true,
	.mineable = true,
	.animals_spawnable_on = true,
	.foxes_spawnable_on = true,
	.parrots_spawnable_on = true,
	.rabbits_spawnable_on = true,
};
const mat_block_t mat_block_gravel_d = { 
	.resistance = 0.6,
	.hardness = 0.6,
	.bamboo_plantable_on = true,
	.enderman_holdable = true,
	.lush_ground_replaceable = true,
	.azalea_root_replaceable = true,
	.mineable_shovel = true,
	.mineable = true,
	.goats_spawnable_on = true,
};
const mat_block_t mat_block_gray_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_rotation
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_gray_bed_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_bed,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_bed_occupied,
		mat_state_modifier_bed_part
	},
	.beds = true,
};
const mat_block_t mat_block_gray_candle_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_candle_candles,
		mat_state_modifier_lit,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_gray_carpet_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.encouragement = 60,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.carpets = true,
};
const mat_block_t mat_block_gray_concrete_d = { 
	.resistance = 1.8,
	.hardness = 1.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_gray_concrete_powder_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.mineable_shovel = true,
	.mineable = true,
};
const mat_block_t mat_block_gray_glazed_terracotta_d = { 
	.resistance = 1.4,
	.hardness = 1.4,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_gray_shulker_box_d = { 
	.resistance = 2,
	.hardness = 2,
	.light_filtering = true,
	.transparent = true,
	.entity = mat_block_entity_locational_container,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing
	},
	.guarded_by_piglins = true,
	.shulker_boxes = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_gray_stained_glass_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.impermeable = true,
};
const mat_block_t mat_block_gray_stained_glass_pane_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_gray_terracotta_d = { 
	.resistance = 4.2,
	.hardness = 1.25,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
	.terracotta = true,
	.azalea_root_replaceable = true,
	.azalea_grows_on = true,
};
const mat_block_t mat_block_gray_wool_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.encouragement = 30,
	.flammability = 60,
	.catches_fire_from_lava = true,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_block_t mat_block_green_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_rotation
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_green_bed_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_bed,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_bed_occupied,
		mat_state_modifier_bed_part
	},
	.beds = true,
};
const mat_block_t mat_block_green_candle_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_candle_candles,
		mat_state_modifier_lit,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_green_carpet_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.encouragement = 60,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.carpets = true,
};
const mat_block_t mat_block_green_concrete_d = { 
	.resistance = 1.8,
	.hardness = 1.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_green_concrete_powder_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.mineable_shovel = true,
	.mineable = true,
};
const mat_block_t mat_block_green_glazed_terracotta_d = { 
	.resistance = 1.4,
	.hardness = 1.4,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_green_shulker_box_d = { 
	.resistance = 2,
	.hardness = 2,
	.light_filtering = true,
	.transparent = true,
	.entity = mat_block_entity_locational_container,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing
	},
	.guarded_by_piglins = true,
	.shulker_boxes = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_green_stained_glass_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.impermeable = true,
};
const mat_block_t mat_block_green_stained_glass_pane_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_green_terracotta_d = { 
	.resistance = 4.2,
	.hardness = 1.25,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
	.terracotta = true,
	.azalea_root_replaceable = true,
	.azalea_grows_on = true,
};
const mat_block_t mat_block_green_wool_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.encouragement = 30,
	.flammability = 60,
	.catches_fire_from_lava = true,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_block_t mat_block_grindstone_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_face,
		mat_state_modifier_facing_cardinal
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_hanging_roots_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_hay_block_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.encouragement = 60,
	.flammability = 20,
	.mineable_hoe = true,
	.mineable = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	}
};
const mat_block_t mat_block_heavy_weighted_pressure_plate_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_power
	},
	.pressure_plates = true,
	.wall_post_override = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_honey_block_d = { 
	.resistance = 0,
	.hardness = 0,
	.light_filtering = true,
	.transparent = true,
};
const mat_block_t mat_block_honeycomb_block_d = { 
	.resistance = 0.6,
	.hardness = 0.6
};
const mat_block_t mat_block_hopper_d = { 
	.resistance = 4.8,
	.hardness = 3,
	.transparent = true,
	.entity = mat_block_entity_hopper,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_hopper_enabled,
		mat_state_modifier_hopper_facing
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_horn_coral_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_waterlogged
	},
	.corals = true,
	.coral_plants = true,
	.underwater_bonemeals = true,
};
const mat_block_t mat_block_horn_coral_block_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.coral_blocks = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_horn_coral_fan_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_waterlogged
	},
	.corals = true,
	.underwater_bonemeals = true,
};
const mat_block_t mat_block_ice_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.light_filtering = true,
	.transparent = true,
	.geode_invalid_blocks = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.ice = true,
	.polar_bears_spawnable_on_in_frozen_ocean = true,
};
const mat_block_t mat_block_infested_chiseled_stone_bricks_d = { 
	.resistance = 0.75,
	.hardness = 0.75,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_infested_cobblestone_d = { 
	.resistance = 0.75,
	.hardness = 1,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_infested_cracked_stone_bricks_d = { 
	.resistance = 0.75,
	.hardness = 0.75,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_infested_deepslate_d = { 
	.resistance = 0.75,
	.hardness = 1.5,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_infested_mossy_stone_bricks_d = { 
	.resistance = 0.75,
	.hardness = 0.75,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_infested_stone_d = { 
	.resistance = 0.75,
	.hardness = 0.75,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_infested_stone_bricks_d = { 
	.resistance = 0.75,
	.hardness = 0.75,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_iron_bars_d = { 
	.resistance = 6,
	.hardness = 5,
	.transparent = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	},
	.dragon_immune = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_iron_door_d = { 
	.resistance = 5,
	.hardness = 5,
	.transparent = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_door_half,
		mat_state_modifier_door_hinge,
		mat_state_modifier_door_open,
		mat_state_modifier_powered
	},
	.doors = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_iron_ore_d = { 
	.resistance = 3,
	.hardness = 3,
	.iron_ores = true,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_iron_trapdoor_d = { 
	.resistance = 5,
	.hardness = 5,
	.transparent = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_trapdoor_half,
		mat_state_modifier_trapdoor_open,
		mat_state_modifier_powered,
		mat_state_modifier_waterlogged
	},
	.trapdoors = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_jack_o_lantern_d = { 
	.resistance = 1,
	.hardness = 1,
	.luminance = 15,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	}
};
const mat_block_t mat_block_jigsaw_d = { 
	.resistance = 3600000,
	.hardness = -1,
	.entity = mat_block_entity_jigsaw,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_jigsaw_facing
	},
	.dragon_immune = true,
	.wither_immune = true,
};
const mat_block_t mat_block_jukebox_d = { 
	.resistance = 6,
	.hardness = 2,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_jukebox,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_jukebox_has_record
	}
};
const mat_block_t mat_block_jungle_button_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_buttons = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_face,
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_powered
	}
};
const mat_block_t mat_block_jungle_door_d = { 
	.resistance = 3,
	.hardness = 3,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_doors = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_door_half,
		mat_state_modifier_door_hinge,
		mat_state_modifier_door_open,
		mat_state_modifier_powered
	}
};
const mat_block_t mat_block_jungle_fence_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_fences = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_jungle_fence_gate_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.fence_gates = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_fencegate_in_wall,
		mat_state_modifier_open,
		mat_state_modifier_powered
	},
	.unstable_bottom_center = true,
};
const mat_block_t mat_block_jungle_leaves_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.encouragement = 30,
	.flammability = 60,
	.transparent = true,
	.catches_fire_from_lava = true,
	.light_filtering = true,
	.mineable_hoe = true,
	.mineable = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_distance,
		mat_state_modifier_leaves_persistant
	},
	.lava_pool_stone_replaceables = true,
	.leaves = true,
	.parrots_spawnable_on = true,
};
const mat_block_t mat_block_jungle_log_d = { 
	.resistance = 2,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.logs_that_burn = true,
	.jungle_logs = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_jungle_planks_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.planks = true
};
const mat_block_t mat_block_jungle_pressure_plate_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_pressure_plates = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_powered
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_jungle_sapling_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_sapling_stage
	},
	.mineable_axe = true,
	.mineable = true,
	.saplings = true
};
const mat_block_t mat_block_jungle_sign_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_sign,
	.mineable_axe = true,
	.mineable = true,
	.signs = true,
	.standing_signs = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_rotation,
		mat_state_modifier_waterlogged
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_jungle_slab_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.wooden_slabs = true,
	.mineable_axe = true,
	.mineable = true,
};
const mat_block_t mat_block_jungle_stairs_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_stairs = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_jungle_trapdoor_d = { 
	.resistance = 3,
	.hardness = 3,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_trapdoors = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_trapdoor_half,
		mat_state_modifier_trapdoor_open,
		mat_state_modifier_powered,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_jungle_wood_d = { 
	.resistance = 2,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.logs_that_burn = true,
	.jungle_logs = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_kelp_plant_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
};
const mat_block_t mat_block_ladder_d = { 
	.resistance = 0.4,
	.hardness = 0.4,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_waterlogged
	},
	.climbable = true,
};
const mat_block_t mat_block_lantern_d = { 
	.resistance = 3.5,
	.hardness = 3.5,
	.luminance = 15,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_lantern_hanging,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_lapis_ore_d = { 
	.resistance = 3,
	.hardness = 3,
	.lapis_ores = true,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_large_amethyst_bud_d = { 
	.resistance = 1.5,
	.hardness = 1.5,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_large_fern_d = { 
	.resistance = 0,
	.hardness = 0,
	.encouragement = 60,
	.flammability = 100,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_plant_half
	}
};
const mat_block_t mat_block_lava_d = { 
	.resistance = 100,
	.hardness = 100,
	.light_filtering = true,
	.luminance = 15,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_liquid_level
	},
	.geode_invalid_blocks = true,
	.strider_warm_blocks = true,
	.lava = true,
};
const mat_block_t mat_block_lectern_d = { 
	.resistance = 2.5,
	.hardness = 2.5,
	.encouragement = 30,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_lectern,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_lectern_has_book,
		mat_state_modifier_powered
	}
};
const mat_block_t mat_block_lever_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_face,
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_powered
	}
};
const mat_block_t mat_block_light_d = { 
	.resistance = 3600000.8,
	.hardness = -1,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_light_level,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_light_blue_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_rotation
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_light_blue_bed_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_bed,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_bed_occupied,
		mat_state_modifier_bed_part
	},
	.beds = true,
};
const mat_block_t mat_block_light_blue_candle_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_candle_candles,
		mat_state_modifier_lit,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_light_blue_carpet_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.encouragement = 60,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.carpets = true,
};
const mat_block_t mat_block_light_blue_concrete_d = { 
	.resistance = 1.8,
	.hardness = 1.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_light_blue_concrete_powder_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.mineable_shovel = true,
	.mineable = true,
};
const mat_block_t mat_block_light_blue_glazed_terracotta_d = { 
	.resistance = 1.4,
	.hardness = 1.4,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_light_blue_shulker_box_d = { 
	.resistance = 2,
	.hardness = 2,
	.light_filtering = true,
	.transparent = true,
	.entity = mat_block_entity_locational_container,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing
	},
	.guarded_by_piglins = true,
	.shulker_boxes = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_light_blue_stained_glass_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.impermeable = true,
};
const mat_block_t mat_block_light_blue_stained_glass_pane_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_light_blue_terracotta_d = { 
	.resistance = 4.2,
	.hardness = 1.25,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
	.terracotta = true,
	.azalea_root_replaceable = true,
	.azalea_grows_on = true,
};
const mat_block_t mat_block_light_blue_wool_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.encouragement = 30,
	.flammability = 60,
	.catches_fire_from_lava = true,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_block_t mat_block_light_gray_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_rotation
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_light_gray_bed_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_bed,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_bed_occupied,
		mat_state_modifier_bed_part
	},
	.beds = true,
};
const mat_block_t mat_block_light_gray_candle_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_candle_candles,
		mat_state_modifier_lit,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_light_gray_carpet_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.encouragement = 60,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.carpets = true,
};
const mat_block_t mat_block_light_gray_concrete_d = { 
	.resistance = 1.8,
	.hardness = 1.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_light_gray_concrete_powder_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.mineable_shovel = true,
	.mineable = true,
};
const mat_block_t mat_block_light_gray_glazed_terracotta_d = { 
	.resistance = 1.4,
	.hardness = 1.4,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_light_gray_shulker_box_d = { 
	.resistance = 2,
	.hardness = 2,
	.light_filtering = true,
	.transparent = true,
	.entity = mat_block_entity_locational_container,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing
	},
	.guarded_by_piglins = true,
	.shulker_boxes = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_light_gray_stained_glass_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.impermeable = true,
};
const mat_block_t mat_block_light_gray_stained_glass_pane_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_light_gray_terracotta_d = { 
	.resistance = 4.2,
	.hardness = 1.25,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
	.terracotta = true,
	.azalea_root_replaceable = true,
	.azalea_grows_on = true,
};
const mat_block_t mat_block_light_gray_wool_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.encouragement = 30,
	.flammability = 60,
	.catches_fire_from_lava = true,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_block_t mat_block_light_weighted_pressure_plate_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_power
	},
	.pressure_plates = true,
	.wall_post_override = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_lightning_rod_d = { 
	.resistance = 6,
	.hardness = 3,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_facing,
		mat_state_modifier_powered,
		mat_state_modifier_waterlogged
	},
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_lilac_d = {
	.resistance = 0,
	.hardness = 0,
	.encouragement = 60,
	.flammability = 100,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.flowers = true,
	.tall_flowers = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_plant_half
	}
};
const mat_block_t mat_block_lily_of_the_valley_d = {
	.resistance = 0,
	.hardness = 0,
	.encouragement = 60,
	.flammability = 100,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.flowers = true,
	.small_flowers = true,
	.enderman_holdable = true,
};
const mat_block_t mat_block_lily_pad_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
};
const mat_block_t mat_block_lime_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_rotation
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_lime_bed_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_bed,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_bed_occupied,
		mat_state_modifier_bed_part
	},
	.beds = true,
};
const mat_block_t mat_block_lime_candle_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_candle_candles,
		mat_state_modifier_lit,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_lime_carpet_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.encouragement = 60,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.carpets = true,
};
const mat_block_t mat_block_lime_concrete_d = { 
	.resistance = 1.8,
	.hardness = 1.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_lime_concrete_powder_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.mineable_shovel = true,
	.mineable = true,
};
const mat_block_t mat_block_lime_glazed_terracotta_d = { 
	.resistance = 1.4,
	.hardness = 1.4,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_lime_shulker_box_d = { 
	.resistance = 2,
	.hardness = 2,
	.light_filtering = true,
	.transparent = true,
	.entity = mat_block_entity_locational_container,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing
	},
	.guarded_by_piglins = true,
	.shulker_boxes = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_lime_stained_glass_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.impermeable = true,
};
const mat_block_t mat_block_lime_stained_glass_pane_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_lime_terracotta_d = { 
	.resistance = 4.2,
	.hardness = 1.25,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
	.terracotta = true,
	.azalea_root_replaceable = true,
	.azalea_grows_on = true,
};
const mat_block_t mat_block_lime_wool_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.encouragement = 30,
	.flammability = 60,
	.catches_fire_from_lava = true,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_block_t mat_block_lodestone_d = { 
	.resistance = 3.5,
	.hardness = 3.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_loom_d = { 
	.resistance = 2.5,
	.hardness = 2.5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	}
};
const mat_block_t mat_block_magenta_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_rotation
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_magenta_bed_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_bed,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_bed_occupied,
		mat_state_modifier_bed_part
	},
	.beds = true,
};
const mat_block_t mat_block_magenta_candle_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_candle_candles,
		mat_state_modifier_lit,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_magenta_carpet_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.encouragement = 60,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.carpets = true,
};
const mat_block_t mat_block_magenta_concrete_d = { 
	.resistance = 1.8,
	.hardness = 1.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_magenta_concrete_powder_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.mineable_shovel = true,
	.mineable = true,
};
const mat_block_t mat_block_magenta_glazed_terracotta_d = { 
	.resistance = 1.4,
	.hardness = 1.4,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_magenta_shulker_box_d = { 
	.resistance = 2,
	.hardness = 2,
	.light_filtering = true,
	.transparent = true,
	.entity = mat_block_entity_locational_container,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing
	},
	.guarded_by_piglins = true,
	.shulker_boxes = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_magenta_stained_glass_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.impermeable = true,
};
const mat_block_t mat_block_magenta_stained_glass_pane_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_magenta_terracotta_d = { 
	.resistance = 4.2,
	.hardness = 1.25,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
	.terracotta = true,
	.azalea_root_replaceable = true,
	.azalea_grows_on = true,
};
const mat_block_t mat_block_magenta_wool_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.encouragement = 30,
	.flammability = 60,
	.catches_fire_from_lava = true,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_block_t mat_block_magma_block_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.luminance = 3,
	.infiniburn_end = true,
	.infiniburn_nether = true,
	.infiniburn_overworld = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_medium_amethyst_bud_d = { 
	.resistance = 1.5,
	.hardness = 1.5,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_melon_d = { 
	.resistance = 1,
	.hardness = 1,
	.mineable_axe = true,
	.mineable = true,
	.enderman_holdable = true,
};
const mat_block_t mat_block_melon_stem_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_crop_age
	},
	.bee_growables = true,
	.crops = true,
};
const mat_block_t mat_block_moss_block_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.mineable_hoe = true,
	.mineable = true,
	.bamboo_plantable_on = true,
	.dirt = true,
	.big_dripleaf_placeable = true,
	.azalea_grows_on = true,
	.enderman_holdable = true,
	.lush_ground_replaceable = true,
	.azalea_root_replaceable = true,
	.moss_replaceable = true,
	.small_dripleaf_placeable = true,
};
const mat_block_t mat_block_moss_carpet_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.transparent = true,
	.mineable_hoe = true,
	.mineable = true,
};
const mat_block_t mat_block_mossy_cobblestone_d = { 
	.resistance = 6,
	.hardness = 2,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_mossy_cobblestone_slab_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_mossy_cobblestone_stairs_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_mossy_cobblestone_wall_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_wall_east,
		mat_state_modifier_wall_north,
		mat_state_modifier_wall_south,
		mat_state_modifier_up,
		mat_state_modifier_waterlogged,
		mat_state_modifier_wall_west
	},
	.walls = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_mossy_stone_brick_slab_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_mossy_stone_brick_stairs_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_mossy_stone_brick_wall_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_wall_east,
		mat_state_modifier_wall_north,
		mat_state_modifier_wall_south,
		mat_state_modifier_up,
		mat_state_modifier_waterlogged,
		mat_state_modifier_wall_west
	},
	.walls = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_mossy_stone_bricks_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.stone_bricks = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_mushroom_stem_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_down,
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_up,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_mycelium_d = { 
	.resistance = 0.6,
	.hardness = 0.6,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_grass_snowy
	},
	.bamboo_plantable_on = true,
	.dirt = true,
	.big_dripleaf_placeable = true,
	.azalea_grows_on = true,
	.enderman_holdable = true,
	.lush_ground_replaceable = true,
	.azalea_root_replaceable = true,
	.moss_replaceable = true,
	.mushroom_grow_block = true,
	.mineable_shovel = true,
	.mineable = true,
	.mooshrooms_spawnable_on = true,
};
const mat_block_t mat_block_nether_brick_fence_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	},
	.fences = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_nether_brick_slab_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_nether_brick_stairs_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_nether_brick_wall_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_wall_east,
		mat_state_modifier_wall_north,
		mat_state_modifier_wall_south,
		mat_state_modifier_up,
		mat_state_modifier_waterlogged,
		mat_state_modifier_wall_west
	},
	.walls = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_nether_bricks_d = { 
	.resistance = 6,
	.hardness = 2,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_nether_gold_ore_d = { 
	.resistance = 3,
	.hardness = 3,
	.gold_ores = true,
	.guarded_by_piglins = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_nether_quartz_ore_d = { 
	.resistance = 3,
	.hardness = 3,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_nether_sprouts_d = { 
	.resistance = 0,
	.hardness = 0,
	.catches_fire_from_lava = true,
	.transparent = true,
};
const mat_block_t mat_block_nether_wart_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_nether_wart_age
	}
};
const mat_block_t mat_block_nether_wart_block_d = { 
	.resistance = 1,
	.hardness = 1,
	.mineable_hoe = true,
	.mineable = true,
	.wart_blocks = true,
};
const mat_block_t mat_block_netherrack_d = { 
	.resistance = 0.4,
	.hardness = 0.4,
	.base_stone_nether = true,
	.infiniburn_end = true,
	.infiniburn_nether = true,
	.infiniburn_overworld = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_note_block_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_note_block_instrument,
		mat_state_modifier_note_block_note,
		mat_state_modifier_powered
	}
};
const mat_block_t mat_block_oak_button_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_buttons = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_face,
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_powered
	}
};
const mat_block_t mat_block_oak_door_d = { 
	.resistance = 3,
	.hardness = 3,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_doors = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_door_half,
		mat_state_modifier_door_hinge,
		mat_state_modifier_door_open,
		mat_state_modifier_powered
	}
};
const mat_block_t mat_block_oak_fence_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_fences = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_oak_fence_gate_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.fence_gates = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_fencegate_in_wall,
		mat_state_modifier_open,
		mat_state_modifier_powered
	},
	.unstable_bottom_center = true,
};
const mat_block_t mat_block_oak_leaves_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.encouragement = 30,
	.flammability = 60,
	.transparent = true,
	.catches_fire_from_lava = true,
	.light_filtering = true,
	.mineable_hoe = true,
	.mineable = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_distance,
		mat_state_modifier_leaves_persistant
	},
	.lava_pool_stone_replaceables = true,
	.leaves = true,
	.parrots_spawnable_on = true,
};
const mat_block_t mat_block_oak_log_d = { 
	.resistance = 2,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.logs_that_burn = true,
	.oak_logs = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_oak_planks_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.planks = true
};
const mat_block_t mat_block_oak_pressure_plate_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_pressure_plates = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_powered
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_oak_sapling_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_sapling_stage
	},
	.mineable_axe = true,
	.mineable = true,
	.saplings = true
};
const mat_block_t mat_block_oak_sign_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_sign,
	.mineable_axe = true,
	.mineable = true,
	.signs = true,
	.standing_signs = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_rotation,
		mat_state_modifier_waterlogged
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_oak_slab_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_slabs = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_oak_stairs_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_stairs = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_oak_trapdoor_d = { 
	.resistance = 3,
	.hardness = 3,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_trapdoors = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_trapdoor_half,
		mat_state_modifier_trapdoor_open,
		mat_state_modifier_powered,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_oak_wood_d = { 
	.resistance = 2,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.logs_that_burn = true,
	.oak_logs = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_observer_d = { 
	.resistance = 3,
	.hardness = 3,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing,
		mat_state_modifier_powered
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_obsidian_d = { 
	.resistance = 1200,
	.hardness = 50,
	.dragon_immune = true,
	.needs_diamond_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_orange_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_rotation
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_orange_bed_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_bed,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_bed_occupied,
		mat_state_modifier_bed_part
	},
	.beds = true,
};
const mat_block_t mat_block_orange_candle_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_candle_candles,
		mat_state_modifier_lit,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_orange_carpet_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.encouragement = 60,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.carpets = true,
};
const mat_block_t mat_block_orange_concrete_d = { 
	.resistance = 1.8,
	.hardness = 1.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_orange_concrete_powder_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.mineable_shovel = true,
	.mineable = true,
};
const mat_block_t mat_block_orange_glazed_terracotta_d = { 
	.resistance = 1.4,
	.hardness = 1.4,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_orange_shulker_box_d = { 
	.resistance = 2,
	.hardness = 2,
	.light_filtering = true,
	.transparent = true,
	.entity = mat_block_entity_locational_container,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing
	},
	.guarded_by_piglins = true,
	.shulker_boxes = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_orange_stained_glass_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.impermeable = true,
};
const mat_block_t mat_block_orange_stained_glass_pane_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_orange_terracotta_d = { 
	.resistance = 4.2,
	.hardness = 1.25,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
	.terracotta = true,
	.azalea_root_replaceable = true,
	.azalea_grows_on = true,
};
const mat_block_t mat_block_orange_tulip_d = { 
	.resistance = 0,
	.hardness = 0,
	.encouragement = 60,
	.flammability = 100,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.flowers = true,
	.small_flowers = true,
	.enderman_holdable = true,
};
const mat_block_t mat_block_orange_wool_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.encouragement = 30,
	.flammability = 60,
	.catches_fire_from_lava = true,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_block_t mat_block_oxeye_daisy_d = { 
	.resistance = 0,
	.hardness = 0,
	.encouragement = 60,
	.flammability = 100,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.flowers = true,
	.small_flowers = true,
	.enderman_holdable = true,
};
const mat_block_t mat_block_oxidized_copper_d = { 
	.resistance = 6,
	.hardness = 3,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_oxidized_cut_copper_d = { 
	.resistance = 6,
	.hardness = 3,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_oxidized_cut_copper_slab_d = { 
	.resistance = 6,
	.hardness = 3,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.needs_stone_tool = true,
	.needs = true,
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_oxidized_cut_copper_stairs_d = { 
	.resistance = 6,
	.hardness = 3,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_packed_ice_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.geode_invalid_blocks = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.ice = true,
	.goats_spawnable_on = true,
};
const mat_block_t mat_block_peony_d = { 
	.resistance = 0,
	.hardness = 0,
	.encouragement = 60,
	.flammability = 100,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.flowers = true,
	.tall_flowers = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_plant_half
	}
};
const mat_block_t mat_block_petrified_oak_slab_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_pink_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_rotation
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_pink_bed_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_bed,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_bed_occupied,
		mat_state_modifier_bed_part
	},
	.beds = true,
};
const mat_block_t mat_block_pink_candle_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_candle_candles,
		mat_state_modifier_lit,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_pink_carpet_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.encouragement = 60,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.carpets = true,
};
const mat_block_t mat_block_pink_concrete_d = { 
	.resistance = 1.8,
	.hardness = 1.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_pink_concrete_powder_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.mineable_shovel = true,
	.mineable = true,
};
const mat_block_t mat_block_pink_glazed_terracotta_d = { 
	.resistance = 1.4,
	.hardness = 1.4,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_pink_shulker_box_d = { 
	.resistance = 2,
	.hardness = 2,
	.light_filtering = true,
	.transparent = true,
	.entity = mat_block_entity_locational_container,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing
	},
	.guarded_by_piglins = true,
	.shulker_boxes = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_pink_stained_glass_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.impermeable = true,
};
const mat_block_t mat_block_pink_stained_glass_pane_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_pink_terracotta_d = { 
	.resistance = 4.2,
	.hardness = 1.25,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
	.terracotta = true,
	.azalea_root_replaceable = true,
	.azalea_grows_on = true,
};
const mat_block_t mat_block_pink_tulip_d = { 
	.resistance = 0,
	.hardness = 0,
	.encouragement = 60,
	.flammability = 100,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.flowers = true,
	.small_flowers = true,
	.enderman_holdable = true,
};
const mat_block_t mat_block_pink_wool_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.encouragement = 30,
	.flammability = 60,
	.catches_fire_from_lava = true,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_block_t mat_block_piston_d = { 
	.resistance = 1.5,
	.hardness = 1.5,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_piston_extended,
		mat_state_modifier_facing
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_player_head_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_head,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_rotation
	}
};
const mat_block_t mat_block_podzol_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_grass_snowy
	},
	.bamboo_plantable_on = true,
	.dirt = true,
	.big_dripleaf_placeable = true,
	.azalea_grows_on = true,
	.enderman_holdable = true,
	.lush_ground_replaceable = true,
	.azalea_root_replaceable = true,
	.moss_replaceable = true,
	.mushroom_grow_block = true,
	.valid_spawn = true,
	.mineable_shovel = true,
	.mineable = true,
	.foxes_spawnable_on = true,
};
const mat_block_t mat_block_pointed_dripstone_d = { 
	.resistance = 3,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_dripstone_thickness,
		mat_state_modifier_dripstone_direction,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_polished_andesite_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_polished_andesite_slab_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_polished_andesite_stairs_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_polished_basalt_d = { 
	.resistance = 4.2,
	.hardness = 1.25,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_polished_blackstone_d = { 
	.resistance = 6,
	.hardness = 2,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_polished_blackstone_brick_slab_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_polished_blackstone_brick_stairs_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_polished_blackstone_brick_wall_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_wall_east,
		mat_state_modifier_wall_north,
		mat_state_modifier_wall_south,
		mat_state_modifier_up,
		mat_state_modifier_waterlogged,
		mat_state_modifier_wall_west
	},
	.walls = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_polished_blackstone_bricks_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_polished_blackstone_button_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_face,
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_powered
	},
	.buttons = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_polished_blackstone_pressure_plate_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_powered
	},
	.pressure_plates = true,
	.stone_pressure_plates = true,
	.wall_post_override = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_polished_blackstone_slab_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_polished_blackstone_stairs_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_polished_blackstone_wall_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_wall_east,
		mat_state_modifier_wall_north,
		mat_state_modifier_wall_south,
		mat_state_modifier_up,
		mat_state_modifier_waterlogged,
		mat_state_modifier_wall_west
	},
	.walls = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_polished_diorite_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_polished_diorite_slab_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_polished_diorite_stairs_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_polished_granite_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_polished_granite_slab_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_polished_granite_stairs_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_polished_deepslate_d = { 
	.resistance = 6,
	.hardness = 3.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_polished_deepslate_slab_d = { 
	.resistance = 6,
	.hardness = 3.5,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_polished_deepslate_stairs_d = { 
	.resistance = 6,
	.hardness = 3.5,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_polished_deepslate_wall_d = { 
	.resistance = 6,
	.hardness = 3.5,
	.transparent = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_wall_east,
		mat_state_modifier_wall_north,
		mat_state_modifier_wall_south,
		mat_state_modifier_up,
		mat_state_modifier_waterlogged,
		mat_state_modifier_wall_west
	},
	.walls = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_poppy_d = { 
	.resistance = 0,
	.hardness = 0,
	.encouragement = 60,
	.flammability = 100,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.flowers = true,
	.small_flowers = true,
	.enderman_holdable = true,
};
const mat_block_t mat_block_potatoes_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_crop_age
	},
	.bee_growables = true,
	.crops = true,
};
const mat_block_t mat_block_powder_snow_d = { 
	.resistance = 0.25,
	.hardness = 0.25,
	.transparent = true,
	.inside_step_sound_blocks = true,
	.snow = true,
	.azalea_grows_on = true,
	.goats_spawnable_on = true,
};
const mat_block_t mat_block_powered_rail_d = { 
	.resistance = 0.7,
	.hardness = 0.7,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_powered,
		mat_state_modifier_special_rail_shape,
		mat_state_modifier_waterlogged
	},
	.prevent_mob_spawning_inside = true,
	.rails = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_prismarine_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_prismarine_brick_slab_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_prismarine_brick_stairs_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_prismarine_bricks_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_prismarine_slab_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_prismarine_stairs_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_prismarine_wall_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_wall_east,
		mat_state_modifier_wall_north,
		mat_state_modifier_wall_south,
		mat_state_modifier_up,
		mat_state_modifier_waterlogged,
		mat_state_modifier_wall_west
	},
	.walls = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_pumpkin_d = { 
	.resistance = 1,
	.hardness = 1,
	.mineable_axe = true,
	.mineable = true,
	.enderman_holdable = true,
};
const mat_block_t mat_block_pumpkin_stem_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_crop_age
	},
	.bee_growables = true,
	.crops = true,
};
const mat_block_t mat_block_purple_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_rotation
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_purple_bed_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_bed,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_bed_occupied,
		mat_state_modifier_bed_part
	},
	.beds = true,
};
const mat_block_t mat_block_purple_candle_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_candle_candles,
		mat_state_modifier_lit,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_purple_carpet_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.encouragement = 60,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.carpets = true,
};
const mat_block_t mat_block_purple_concrete_d = { 
	.resistance = 1.8,
	.hardness = 1.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_purple_concrete_powder_d = {
	.resistance = 0.5,
	.hardness = 0.5,
 };
const mat_block_t mat_block_purple_glazed_terracotta_d = { 
	.resistance = 1.4,
	.hardness = 1.4,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_purple_shulker_box_d = { 
	.resistance = 2,
	.hardness = 2,
	.light_filtering = true,
	.transparent = true,
	.entity = mat_block_entity_locational_container,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing
	},
	.guarded_by_piglins = true,
	.shulker_boxes = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_purple_stained_glass_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.impermeable = true,
};
const mat_block_t mat_block_purple_stained_glass_pane_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_purple_terracotta_d = { 
	.resistance = 4.2,
	.hardness = 1.25,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
	.terracotta = true,
	.azalea_root_replaceable = true,
	.azalea_grows_on = true,
};
const mat_block_t mat_block_purple_wool_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.encouragement = 30,
	.flammability = 60,
	.catches_fire_from_lava = true,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_block_t mat_block_purpur_block_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_purpur_pillar_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_purpur_slab_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_purpur_stairs_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_quartz_bricks_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_quartz_pillar_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_quartz_slab_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_quartz_stairs_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_rail_d = { 
	.resistance = 0.7,
	.hardness = 0.7,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_rail_shape,
		mat_state_modifier_waterlogged
	},
	.prevent_mob_spawning_inside = true,
	.rails = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_red_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_rotation
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_red_bed_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_bed,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_bed_occupied,
		mat_state_modifier_bed_part
	},
	.beds = true,
};
const mat_block_t mat_block_red_candle_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_candle_candles,
		mat_state_modifier_lit,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_red_carpet_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.encouragement = 60,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.carpets = true,
};
const mat_block_t mat_block_red_concrete_d = { 
	.resistance = 1.8,
	.hardness = 1.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_red_concrete_powder_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.mineable_shovel = true,
	.mineable = true,
};
const mat_block_t mat_block_red_glazed_terracotta_d = { 
	.resistance = 1.4,
	.hardness = 1.4,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_red_mushroom_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.enderman_holdable = true,
};
const mat_block_t mat_block_red_mushroom_block_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.catches_fire_from_lava = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_down,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_up,
		mat_state_modifier_west
	},
	.mineable_axe = true,
	.mineable = true,
};
const mat_block_t mat_block_red_nether_brick_slab_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_red_nether_brick_stairs_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_red_nether_brick_wall_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_wall_east,
		mat_state_modifier_wall_north,
		mat_state_modifier_wall_south,
		mat_state_modifier_up,
		mat_state_modifier_waterlogged,
		mat_state_modifier_wall_west
	},
	.walls = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_red_nether_bricks_d = { 
	.resistance = 6,
	.hardness = 2,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_red_sand_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.bamboo_plantable_on = true,
	.enderman_holdable = true,
	.mineable_shovel = true,
	.mineable = true,
	.sand = true,
	.azalea_grows_on = true,
	.azalea_root_replaceable = true,
};
const mat_block_t mat_block_red_sandstone_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_red_sandstone_slab_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_red_sandstone_stairs_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_red_sandstone_wall_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.transparent = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_wall_east,
		mat_state_modifier_wall_north,
		mat_state_modifier_wall_south,
		mat_state_modifier_up,
		mat_state_modifier_waterlogged,
		mat_state_modifier_wall_west
	},
	.walls = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_red_shulker_box_d = { 
	.resistance = 2,
	.hardness = 2,
	.light_filtering = true,
	.transparent = true,
	.entity = mat_block_entity_locational_container,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing
	},
	.guarded_by_piglins = true,
	.shulker_boxes = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_red_stained_glass_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.impermeable = true,
};
const mat_block_t mat_block_red_stained_glass_pane_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_red_terracotta_d = { 
	.resistance = 4.2,
	.hardness = 1.25,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
	.terracotta = true,
	.azalea_root_replaceable = true,
	.azalea_grows_on = true,
};
const mat_block_t mat_block_red_tulip_d = { 
	.resistance = 0,
	.hardness = 0,
	.encouragement = 60,
	.flammability = 100,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.flowers = true,
	.small_flowers = true,
	.enderman_holdable = true,
};
const mat_block_t mat_block_red_wool_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.encouragement = 30,
	.flammability = 60,
	.catches_fire_from_lava = true,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_block_t mat_block_comparator_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.entity = mat_block_entity_comparator,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_comparator_mode,
		mat_state_modifier_powered
	}
};
const mat_block_t mat_block_redstone_lamp_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_lit
	}
};
const mat_block_t mat_block_redstone_ore_d = { 
	.resistance = 3,
	.hardness = 3,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_lit
	},
	.needs_iron_tool = true,
	.needs = true,
	.redstone_ores = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_repeater_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_repeater_delay,
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_repeater_locked,
		mat_state_modifier_powered
	}
};
const mat_block_t mat_block_redstone_torch_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.luminance = 7,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_lit
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_redstone_wire_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_redstone_east,
		mat_state_modifier_redstone_north,
		mat_state_modifier_power,
		mat_state_modifier_redstone_south,
		mat_state_modifier_redstone_west,
	}
};
const mat_block_t mat_block_repeating_command_block_d = { 
	.resistance = 3600000,
	.hardness = -1,
	.entity = mat_block_entity_command,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_command_block_conditional,
		mat_state_modifier_facing
	},
	.dragon_immune = true,
	.wither_immune = true,
};
const mat_block_t mat_block_respawn_anchor_d = { 
	.resistance = 1200,
	.hardness = 50,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_respawn_anchor_charges
	},
	.dragon_immune = true,
	.hoglin_repellents = true,
	.needs_diamond_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_rooted_dirt_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.bamboo_plantable_on = true,
	.enderman_holdable = true,
	.lush_ground_replaceable = true,
	.azalea_root_replaceable = true,
	.moss_replaceable = true,
	.mineable_shovel = true,
	.mineable = true,
	.dirt = true,
	.big_dripleaf_placeable = true,
	.azalea_grows_on = true,
};
const mat_block_t mat_block_rose_bush_d = { 
	.resistance = 0,
	.hardness = 0,
	.encouragement = 60,
	.flammability = 100,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.flowers = true,
	.tall_flowers = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_plant_half
	}
};
const mat_block_t mat_block_sand_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.bamboo_plantable_on = true,
	.enderman_holdable = true,
	.lush_ground_replaceable = true,
	.azalea_root_replaceable = true,
	.mineable_shovel = true,
	.mineable = true,
	.sand = true,
	.azalea_grows_on = true,
	.rabbits_spawnable_on = true,
};
const mat_block_t mat_block_sandstone_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_sandstone_slab_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_sandstone_stairs_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_sandstone_wall_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.transparent = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_wall_east,
		mat_state_modifier_wall_north,
		mat_state_modifier_wall_south,
		mat_state_modifier_up,
		mat_state_modifier_waterlogged,
		mat_state_modifier_wall_west
	},
	.walls = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_scaffolding_d = { 
	.resistance = 0,
	.hardness = 0,
	.encouragement = 60,
	.flammability = 60,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_scaffolding_bottom,
		mat_state_modifier_scaffolding_distance,
		mat_state_modifier_waterlogged
	},
	.climbable = true,
};
const mat_block_t mat_block_sculk_sensor_d = { 
	.resistance = 1.5,
	.hardness = 1.5,
	.luminance = 1,
	.transparent = true,
	.mineable_hoe = true,
	.mineable = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_power,
		mat_state_modifier_sculk_sensor_phase,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_sea_lantern_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.luminance = 15
};
const mat_block_t mat_block_sea_pickle_d = { 
	.resistance = 0,
	.hardness = 0,
	.luminance = 6,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_sea_pickle_pickles,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_seagrass_d = { 
	.resistance = 0,
	.hardness = 0,
	.underwater_bonemeals = true,
};
const mat_block_t mat_block_shroomlight_d = { 
	.resistance = 1,
	.hardness = 1,
	.luminance = 15,
	.mineable_hoe = true,
	.mineable = true,
};
const mat_block_t mat_block_shulker_box_d = { 
	.resistance = 2,
	.hardness = 2,
	.light_filtering = true,
	.transparent = true,
	.entity = mat_block_entity_locational_container,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing
	},
	.guarded_by_piglins = true,
	.shulker_boxes = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_skeleton_skull_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_rotation
	}
};
const mat_block_t mat_block_slime_block_d = { 
	.resistance = 0,
	.hardness = 0,
	.light_filtering = true,
};
const mat_block_t mat_block_small_amethyst_bud_d = { 
	.resistance = 1.5,
	.hardness = 1.5,
	.luminance = 1,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_small_dripleaf_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_plant_half,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_smithing_table_d = { 
	.resistance = 2.5,
	.hardness = 2.5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
};
const mat_block_t mat_block_smoker_d = { 
	.resistance = 3.5,
	.hardness = 3.5,
	.entity = mat_block_entity_furnace,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_lit
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_smooth_basalt_d = { 
	.resistance = 4.2,
	.hardness = 1.25,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_smooth_quartz_d = { 
	.resistance = 6,
	.hardness = 2,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_smooth_quartz_slab_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_smooth_quartz_stairs_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_smooth_red_sandstone_d = { 
	.resistance = 6,
	.hardness = 2,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_smooth_red_sandstone_slab_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_smooth_red_sandstone_stairs_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_smooth_sandstone_d = { 
	.resistance = 6,
	.hardness = 2,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_smooth_sandstone_slab_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_smooth_sandstone_stairs_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_smooth_stone_d = { 
	.resistance = 6,
	.hardness = 2,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_smooth_stone_slab_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_snow_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_snow_layers
	},
	.inside_step_sound_blocks = true,
	.mineable_shovel = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
	.foxes_spawnable_on = true,
	.goats_spawnable_on = true,
	.rabbits_spawnable_on = true,
};
const mat_block_t mat_block_snow_block_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.mineable_shovel = true,
	.mineable = true,
	.snow = true,
	.needs_wooden_tool = true,
	.needs = true,
	.azalea_grows_on = true,
	.foxes_spawnable_on = true,
	.goats_spawnable_on = true,
	.rabbits_spawnable_on = true,
};
const mat_block_t mat_block_soul_campfire_d = { 
	.resistance = 2,
	.hardness = 2,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.luminance = 10,
	.entity = mat_block_entity_container,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_lit,
		mat_state_modifier_campfire_signal,
		mat_state_modifier_waterlogged
	},
	.campfires = true,
	.piglin_repellents = true,
};
const mat_block_t mat_block_soul_fire_d = { 
	.resistance = 0,
	.hardness = 0,
	.luminance = 10,
	.transparent = true,
	.piglin_repellents = true,
	.fire = true,
};
const mat_block_t mat_block_soul_lantern_d = { 
	.resistance = 3.5,
	.hardness = 3.5,
	.luminance = 10,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_lantern_hanging,
		mat_state_modifier_waterlogged
	},
	.piglin_repellents = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_soul_sand_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.soul_fire_base_blocks = true,
	.soul_speed_blocks = true,
	.wither_summon_base_blocks = true,
	.mineable_shovel = true,
	.mineable = true,
};
const mat_block_t mat_block_soul_soil_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.soul_fire_base_blocks = true,
	.soul_speed_blocks = true,
	.wither_summon_base_blocks = true,
	.mineable_shovel = true,
	.mineable = true,
};
const mat_block_t mat_block_soul_torch_d = { 
	.resistance = 0,
	.hardness = 0,
	.luminance = 10,
	.transparent = true,
	.piglin_repellents = true,
	.wall_post_override = true,
};
const mat_block_t mat_block_spawner_d = { 
	.resistance = 5,
	.hardness = 5,
	.transparent = true,
	.features_cannot_replace = true,
	.lava_pool_stone_replaceables = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_sponge_d = { 
	.resistance = 0.6,
	.hardness = 0.6,
	.mineable_hoe = true,
	.mineable = true,
};
const mat_block_t mat_block_spore_blossom_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
};
const mat_block_t mat_block_spruce_button_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_buttons = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_face,
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_powered
	}
};
const mat_block_t mat_block_spruce_door_d = { 
	.resistance = 3,
	.hardness = 3,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_doors = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_door_half,
		mat_state_modifier_door_hinge,
		mat_state_modifier_door_open,
		mat_state_modifier_powered
	}
};
const mat_block_t mat_block_spruce_fence_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_fences = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_spruce_fence_gate_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.fence_gates = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_fencegate_in_wall,
		mat_state_modifier_open,
		mat_state_modifier_powered
	},
	.unstable_bottom_center = true,
};
const mat_block_t mat_block_spruce_leaves_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.encouragement = 30,
	.flammability = 60,
	.transparent = true,
	.catches_fire_from_lava = true,
	.light_filtering = true,
	.mineable_hoe = true,
	.mineable = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_distance,
		mat_state_modifier_leaves_persistant
	},
	.lava_pool_stone_replaceables = true,
	.leaves = true,
	.parrots_spawnable_on = true,
};
const mat_block_t mat_block_spruce_log_d = { 
	.resistance = 2,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.logs_that_burn = true,
	.spruce_logs = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_spruce_planks_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.planks = true
};
const mat_block_t mat_block_spruce_pressure_plate_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_pressure_plates = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_powered
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_spruce_sapling_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_sapling_stage
	},
	.mineable_axe = true,
	.mineable = true,
	.saplings = true
};
const mat_block_t mat_block_spruce_sign_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_sign,
	.mineable_axe = true,
	.mineable = true,
	.signs = true,
	.standing_signs = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_rotation,
		mat_state_modifier_waterlogged
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_spruce_slab_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_slabs = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_spruce_stairs_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_stairs = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_spruce_trapdoor_d = { 
	.resistance = 3,
	.hardness = 3,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_trapdoors = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_trapdoor_half,
		mat_state_modifier_trapdoor_open,
		mat_state_modifier_powered,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_spruce_wood_d = { 
	.resistance = 2,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.logs_that_burn = true,
	.spruce_logs = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_sticky_piston_d = { 
	.resistance = 1.5,
	.hardness = 1.5,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_piston_extended,
		mat_state_modifier_facing
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_stone_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.base_stone_overworld = true,
	.dripstone_replaceable_blocks = true,
	.lush_ground_replaceable = true,
	.azalea_root_replaceable = true,
	.moss_replaceable = true,
	.stone_ore_replaceables = true,
	.needs_wooden_tool = true,
	.needs = true,
	.goats_spawnable_on = true,
};
const mat_block_t mat_block_stone_brick_slab_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_stone_brick_stairs_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_stone_brick_wall_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 6,
	.modifiers = {
		mat_state_modifier_wall_east,
		mat_state_modifier_wall_north,
		mat_state_modifier_wall_south,
		mat_state_modifier_up,
		mat_state_modifier_waterlogged,
		mat_state_modifier_wall_west
	},
	.walls = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_stone_bricks_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.mineable_pickaxe = true,
	.mineable = true,
	.stone_bricks = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_stone_button_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_face,
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_powered
	},
	.buttons = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_stone_pressure_plate_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_powered
	},
	.pressure_plates = true,
	.stone_pressure_plates = true,
	.wall_post_override = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_stone_slab_d = { 
	.resistance = 6,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_stone_stairs_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_stonecutter_d = { 
	.resistance = 3.5,
	.hardness = 3.5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_stripped_acacia_log_d = { 
	.resistance = 2,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.logs_that_burn = true,
	.acacia_logs = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_stripped_acacia_wood_d = { 
	.resistance = 2,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.logs_that_burn = true,
	.acacia_logs = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_stripped_birch_log_d = { 
	.resistance = 2,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.logs_that_burn = true,
	.birch_logs = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_stripped_birch_wood_d = { 
	.resistance = 2,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.logs_that_burn = true,
	.birch_logs = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_stripped_crimson_hyphae_d = { 
	.resistance = 2,
	.hardness = 2,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.crimson_stems = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
	.non_flammable_wood = true,
};
const mat_block_t mat_block_stripped_crimson_stem_d = { 
	.resistance = 2,
	.hardness = 2,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.crimson_stems = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
	.non_flammable_wood = true,
};
const mat_block_t mat_block_stripped_dark_oak_log_d = { 
	.resistance = 2,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.logs_that_burn = true,
	.dark_oak_logs = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_stripped_dark_oak_wood_d = { 
	.resistance = 2,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.logs_that_burn = true,
	.dark_oak_logs = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_stripped_jungle_log_d = { 
	.resistance = 2,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.logs_that_burn = true,
	.jungle_logs = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_stripped_jungle_wood_d = { 
	.resistance = 2,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.logs_that_burn = true,
	.jungle_logs = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_stripped_oak_log_d = { 
	.resistance = 2,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.logs_that_burn = true,
	.oak_logs = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_stripped_oak_wood_d = { 
	.resistance = 2,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.logs_that_burn = true,
	.oak_logs = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_stripped_spruce_log_d = { 
	.resistance = 2,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.logs_that_burn = true,
	.spruce_logs = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_stripped_spruce_wood_d = { 
	.resistance = 2,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 5,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.logs_that_burn = true,
	.spruce_logs = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
};
const mat_block_t mat_block_stripped_warped_hyphae_d = { 
	.resistance = 2,
	.hardness = 2,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.warped_stems = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
	.non_flammable_wood = true,
};
const mat_block_t mat_block_stripped_warped_stem_d = { 
	.resistance = 2,
	.hardness = 2,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.warped_stems = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
	.non_flammable_wood = true,
};
const mat_block_t mat_block_structure_block_d = { 
	.resistance = 3600000,
	.hardness = -1,
	.entity = mat_block_entity_structure,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_structure_block_mode
	},
	.dragon_immune = true,
	.wither_immune = true,
};
const mat_block_t mat_block_structure_void_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
};
const mat_block_t mat_block_sugar_cane_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_stock_age
	}
};
const mat_block_t mat_block_sunflower_d = { 
	.resistance = 0,
	.hardness = 0,
	.encouragement = 60,
	.flammability = 100,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.flowers = true,
	.tall_flowers = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_plant_half
	}
};
const mat_block_t mat_block_sweet_berry_bush_d = { 
	.resistance = 0,
	.hardness = 0,
	.encouragement = 60,
	.flammability = 100,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_sweet_berry_bush_age
	},
	.bee_growables = true,
};
const mat_block_t mat_block_tall_grass_d = { 
	.resistance = 0,
	.hardness = 0,
	.encouragement = 60,
	.flammability = 100,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_plant_half
	}
};
const mat_block_t mat_block_tall_seagrass_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_plant_half
	}
};
const mat_block_t mat_block_target_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.encouragement = 15,
	.flammability = 20,
	.mineable_hoe = true,
	.mineable = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_power
	}
};
const mat_block_t mat_block_terracotta_d = { 
	.resistance = 4.2,
	.hardness = 1.25,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
	.terracotta = true,
	.azalea_root_replaceable = true,
	.azalea_grows_on = true,
};
const mat_block_t mat_block_tinted_glass_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.impermeable = true,
};
const mat_block_t mat_block_tnt_d = { 
	.resistance = 0,
	.hardness = 0,
	.encouragement = 15,
	.flammability = 100,
	.catches_fire_from_lava = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_tnt_unstable
	},
	.enderman_holdable = true,
};
const mat_block_t mat_block_torch_d = { 
	.resistance = 0,
	.hardness = 0,
	.luminance = 14,
	.transparent = true,
	.wall_post_override = true,
};
const mat_block_t mat_block_trapped_chest_d = { 
	.resistance = 2.5,
	.hardness = 2.5,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.entity = mat_block_entity_locational_container,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_chest_type,
		mat_state_modifier_waterlogged
	},
	.guarded_by_piglins = true,
};
const mat_block_t mat_block_tripwire_d = {
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 7,
	.modifiers = {
		mat_state_modifier_tripwire_attached,
		mat_state_modifier_tripwire_disarmed,
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_powered,
		mat_state_modifier_south,
		mat_state_modifier_west
	}
 };
const mat_block_t mat_block_tripwire_hook_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_tripwire_attached,
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_powered
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_tube_coral_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_waterlogged
	},
	.corals = true,
	.coral_plants = true,
	.underwater_bonemeals = true,
};
const mat_block_t mat_block_tube_coral_block_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.coral_blocks = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_tube_coral_fan_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_waterlogged
	},
	.corals = true,
	.underwater_bonemeals = true,
};
const mat_block_t mat_block_tuff_d = { 
	.resistance = 6,
	.hardness = 1.5,
	.base_stone_overworld = true,
	.deepslate_ore_replaceables = true,
	.dripstone_replaceable_blocks = true,
	.lush_ground_replaceable = true,
	.azalea_root_replaceable = true,
	.moss_replaceable = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_turtle_egg_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_turtle_egg_eggs,
		mat_state_modifier_turtle_egg_hatch
	}
};
const mat_block_t mat_block_twisting_vines_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_vine_age
	},
	.climbable = true,
};
const mat_block_t mat_block_vine_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.encouragement = 15,
	.flammability = 100,
	.transparent = true,
	.catches_fire_from_lava = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_up,
		mat_state_modifier_west
	},
	.climbable = true,
};
const mat_block_t mat_block_warped_button_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_buttons = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_face,
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_powered
	},
	.non_flammable_wood = true,
};
const mat_block_t mat_block_warped_door_d = { 
	.resistance = 3,
	.hardness = 3,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_doors = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_door_half,
		mat_state_modifier_door_hinge,
		mat_state_modifier_door_open,
		mat_state_modifier_powered
	},
	.non_flammable_wood = true,
};
const mat_block_t mat_block_warped_fence_d = { 
	.resistance = 3,
	.hardness = 2,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_fences = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	},
	.non_flammable_wood = true,
};
const mat_block_t mat_block_warped_fence_gate_d = { 
	.resistance = 3,
	.hardness = 2,
	.encouragement = 5,
	.flammability = 20,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.fence_gates = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_fencegate_in_wall,
		mat_state_modifier_open,
		mat_state_modifier_powered
	},
	.non_flammable_wood = true,
	.unstable_bottom_center = true,
};
const mat_block_t mat_block_warped_fungus_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.enderman_holdable = true,
	.hoglin_repellents = true,
};
const mat_block_t mat_block_warped_hyphae_d = { 
	.resistance = 2,
	.hardness = 2,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.warped_stems = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
	.non_flammable_wood = true,
};
const mat_block_t mat_block_warped_nylium_d = { 
	.resistance = 0.4,
	.hardness = 0.4,
	.enderman_holdable = true,
	.mushroom_grow_block = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.nylium = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_warped_planks_d = { 
	.resistance = 3,
	.hardness = 2,
	.mineable_axe = true,
	.mineable = true,
	.planks = true,
	.non_flammable_wood = true,
};
const mat_block_t mat_block_warped_pressure_plate_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_pressure_plates = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_powered
	},
	.non_flammable_wood = true,
	.wall_post_override = true,
};
const mat_block_t mat_block_warped_roots_d = { 
	.resistance = 0,
	.hardness = 0,
	.catches_fire_from_lava = true,
	.transparent = true,
	.enderman_holdable = true,
};
const mat_block_t mat_block_warped_sign_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_sign,
	.mineable_axe = true,
	.mineable = true,
	.signs = true,
	.standing_signs = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_rotation,
		mat_state_modifier_waterlogged
	},
	.non_flammable_wood = true,
	.wall_post_override = true,
};
const mat_block_t mat_block_warped_slab_d = { 
	.resistance = 3,
	.hardness = 2,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_slabs = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.non_flammable_wood = true,
};
const mat_block_t mat_block_warped_stairs_d = { 
	.resistance = 3,
	.hardness = 2,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_stairs = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.non_flammable_wood = true,
};
const mat_block_t mat_block_warped_stem_d = { 
	.resistance = 2,
	.hardness = 2,
	.mineable_axe = true,
	.mineable = true,
	.logs = true,
	.parrots_spawnable_on = true,
	.warped_stems = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_axis
	},
	.lava_pool_stone_replaceables = true,
	.non_flammable_wood = true,
};
const mat_block_t mat_block_warped_trapdoor_d = { 
	.resistance = 3,
	.hardness = 3,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.wooden_trapdoors = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_trapdoor_half,
		mat_state_modifier_trapdoor_open,
		mat_state_modifier_powered,
		mat_state_modifier_waterlogged
	},
	.non_flammable_wood = true,
};
const mat_block_t mat_block_warped_wart_block_d = {
	.resistance = 1,
	.hardness = 1,
	.mineable_hoe = true,
	.mineable = true,
	.wart_blocks = true,
};
const mat_block_t mat_block_water_d = { 
	.resistance = 100,
	.hardness = 100,
	.light_filtering = true,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_liquid_level
	},
	.geode_invalid_blocks = true,
	.water = true,
};
const mat_block_t mat_block_waxed_copper_block_d = { 
	.resistance = 6,
	.hardness = 3,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_waxed_cut_copper_d = { 
	.resistance = 6,
	.hardness = 3,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_waxed_cut_copper_slab_d = { 
	.resistance = 6,
	.hardness = 3,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.needs_stone_tool = true,
	.needs = true,
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_waxed_cut_copper_stairs_d = { 
	.resistance = 6,
	.hardness = 3,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_waxed_exposed_copper_d = { 
	.resistance = 6,
	.hardness = 3,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_waxed_exposed_cut_copper_d = { 
	.resistance = 6,
	.hardness = 3,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_waxed_exposed_cut_copper_slab_d = { 
	.resistance = 6,
	.hardness = 3,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.needs_stone_tool = true,
	.needs = true,
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_waxed_exposed_cut_copper_stairs_d = { 
	.resistance = 6,
	.hardness = 3,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_waxed_oxidized_copper_d = { 
	.resistance = 6,
	.hardness = 3,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_waxed_oxidized_cut_copper_d = { 
	.resistance = 6,
	.hardness = 3,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_waxed_oxidized_cut_copper_slab_d = { 
	.resistance = 6,
	.hardness = 3,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.needs_stone_tool = true,
	.needs = true,
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_waxed_oxidized_cut_copper_stairs_d = { 
	.resistance = 6,
	.hardness = 3,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_waxed_weathered_copper_d = { 
	.resistance = 6,
	.hardness = 3,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_waxed_weathered_cut_copper_d = { 
	.resistance = 6,
	.hardness = 3,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_waxed_weathered_cut_copper_slab_d = { 
	.resistance = 6,
	.hardness = 3,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.needs_stone_tool = true,
	.needs = true,
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_waxed_weathered_cut_copper_stairs_d = { 
	.resistance = 6,
	.hardness = 3,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_weathered_copper_d = { 
	.resistance = 6,
	.hardness = 3,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_weathered_cut_copper_d = { 
	.resistance = 6,
	.hardness = 3,
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_weathered_cut_copper_slab_d = { 
	.resistance = 6,
	.hardness = 3,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_slab_type,
		mat_state_modifier_waterlogged
	},
	.needs_stone_tool = true,
	.needs = true,
	.slabs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_weathered_cut_copper_stairs_d = { 
	.resistance = 6,
	.hardness = 3,
	.transparent = true,
	.modifiers_count = 4,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_stairs_half,
		mat_state_modifier_stairs_shape,
		mat_state_modifier_waterlogged
	},
	.needs_stone_tool = true,
	.needs = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_weeping_vines_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_vine_age
	},
	.climbable = true,
};
const mat_block_t mat_block_wet_sponge_d = { 
	.resistance = 0.6,
	.hardness = 0.6,
	.mineable_hoe = true,
	.mineable = true,
};
const mat_block_t mat_block_wheat_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_crop_age
	},
	.bee_growables = true,
	.crops = true,
};
const mat_block_t mat_block_white_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_rotation
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_white_bed_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_bed,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_bed_occupied,
		mat_state_modifier_bed_part
	},
	.beds = true,
};
const mat_block_t mat_block_white_candle_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_candle_candles,
		mat_state_modifier_lit,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_white_carpet_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.encouragement = 60,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.carpets = true,
};
const mat_block_t mat_block_white_concrete_d = { 
	.resistance = 1.8,
	.hardness = 1.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_white_concrete_powder_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.mineable_shovel = true,
	.mineable = true,
};
const mat_block_t mat_block_white_glazed_terracotta_d = { 
	.resistance = 1.4,
	.hardness = 1.4,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_white_shulker_box_d = { 
	.resistance = 2,
	.hardness = 2,
	.light_filtering = true,
	.transparent = true,
	.entity = mat_block_entity_locational_container,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing
	},
	.guarded_by_piglins = true,
	.shulker_boxes = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_white_stained_glass_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.impermeable = true,
};
const mat_block_t mat_block_white_stained_glass_pane_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_white_terracotta_d = { 
	.resistance = 4.2,
	.hardness = 1.25,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
	.terracotta = true,
	.azalea_root_replaceable = true,
	.azalea_grows_on = true,
};
const mat_block_t mat_block_white_tulip_d = { 
	.resistance = 0,
	.hardness = 0,
	.encouragement = 60,
	.flammability = 100,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.flowers = true,
	.small_flowers = true,
	.enderman_holdable = true,
};
const mat_block_t mat_block_white_wool_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.encouragement = 30,
	.flammability = 60,
	.catches_fire_from_lava = true,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_block_t mat_block_wither_rose_d = { 
	.resistance = 0,
	.hardness = 0,
	.encouragement = 60,
	.flammability = 100,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.flowers = true,
	.small_flowers = true,
	.enderman_holdable = true,
};
const mat_block_t mat_block_wither_skeleton_skull_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_rotation
	}
};
const mat_block_t mat_block_yellow_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_rotation
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_yellow_bed_d = { 
	.resistance = 0.2,
	.hardness = 0.2,
	.transparent = true,
	.catches_fire_from_lava = true,
	.entity = mat_block_entity_bed,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_bed_occupied,
		mat_state_modifier_bed_part
	},
	.beds = true,
};
const mat_block_t mat_block_yellow_candle_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.transparent = true,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_candle_candles,
		mat_state_modifier_lit,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_yellow_carpet_d = { 
	.resistance = 0.1,
	.hardness = 0.1,
	.encouragement = 60,
	.flammability = 20,
	.transparent = true,
	.catches_fire_from_lava = true,
	.carpets = true,
};
const mat_block_t mat_block_yellow_concrete_d = { 
	.resistance = 1.8,
	.hardness = 1.8,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_yellow_concrete_powder_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.mineable_shovel = true,
	.mineable = true,
};
const mat_block_t mat_block_yellow_glazed_terracotta_d = { 
	.resistance = 1.4,
	.hardness = 1.4,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_yellow_shulker_box_d = { 
	.resistance = 2,
	.hardness = 2,
	.light_filtering = true,
	.transparent = true,
	.entity = mat_block_entity_locational_container,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing
	},
	.guarded_by_piglins = true,
	.shulker_boxes = true,
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_yellow_stained_glass_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.impermeable = true,
};
const mat_block_t mat_block_yellow_stained_glass_pane_d = { 
	.resistance = 0.3,
	.hardness = 0.3,
	.transparent = true,
	.modifiers_count = 5,
	.modifiers = {
		mat_state_modifier_east,
		mat_state_modifier_north,
		mat_state_modifier_south,
		mat_state_modifier_waterlogged,
		mat_state_modifier_west
	}
};
const mat_block_t mat_block_yellow_terracotta_d = { 
	.resistance = 4.2,
	.hardness = 1.25,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
	.terracotta = true,
	.azalea_root_replaceable = true,
	.azalea_grows_on = true,
};
const mat_block_t mat_block_yellow_wool_d = { 
	.resistance = 0.8,
	.hardness = 0.8,
	.encouragement = 30,
	.flammability = 60,
	.catches_fire_from_lava = true,
	.occludes_vibration_signals = true,
	.wool = true,
};
const mat_block_t mat_block_zombie_head_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_rotation
	}
};
const mat_block_t mat_block_end_portal_d = {
	.resistance = 3600000,
	.hardness = -1,
	.luminance = 15,
	.transparent = true,
	.entity = mat_block_entity_end_particles,
	.dragon_immune = true,
	.portals = true,
	.wither_immune = true,
};
const mat_block_t mat_block_frosted_ice_d = {
	.resistance = 0.5,
	.hardness = 0.5,
	.light_filtering = true,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_frosted_ice_age
	}
};
const mat_block_t mat_block_piston_head_d = {
	.resistance = 1.5,
	.hardness = 1.5,
	.modifiers_count = 3,
	.modifiers = {
		mat_state_modifier_facing,
		mat_state_modifier_piston_short,
		mat_state_modifier_piston_type,
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_nether_portal_d = {
	.resistance = 0,
	.hardness = -1,
	.luminance = 11,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_cardinal_axis
	},
	.hoglin_repellents = true,
	.portals = true,
};
const mat_block_t mat_block_end_gateway_d = {
	.resistance = 3600000,
	.hardness = -1,
	.light_filtering = true,
	.transparent = true,
	.luminance = 15,
	.entity = mat_block_entity_gateway,
	.dragon_immune = true,
	.portals = true,
	.wither_immune = true,
};
const mat_block_t mat_block_big_dripleaf_stem_d = {
	.resistance = 0.1,
	.hardness = 0.1,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_waterlogged
	}
};
const mat_block_t mat_block_bubble_column_d = {
	.resistance = 0,
	.hardness = 0,
	.light_filtering = true,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_bubble_column_drag
	}
};
const mat_block_t mat_block_moving_piston_d = { 
	.resistance = 0,
	.hardness = -1,
	.transparent = true,
	.entity = mat_block_entity_piston_extension,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing,
		mat_state_modifier_piston_type
	},
	.dragon_immune = true,
	.wither_immune = true,
};
const mat_block_t mat_block_wall_torch_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	}
};
const mat_block_t mat_block_oak_wall_sign_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_sign,
	.mineable_axe = true,
	.mineable = true,
	.signs = true,
	.wall_signs = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_waterlogged
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_spruce_wall_sign_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_sign,
	.mineable_axe = true,
	.mineable = true,
	.signs = true,
	.wall_signs = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_waterlogged
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_birch_wall_sign_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_sign,
	.mineable_axe = true,
	.mineable = true,
	.signs = true,
	.wall_signs = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_waterlogged
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_acacia_wall_sign_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_sign,
	.mineable_axe = true,
	.mineable = true,
	.signs = true,
	.wall_signs = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_waterlogged
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_jungle_wall_sign_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_sign,
	.mineable_axe = true,
	.mineable = true,
	.signs = true,
	.wall_signs = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_waterlogged
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_dark_oak_wall_sign_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_sign,
	.mineable_axe = true,
	.mineable = true,
	.signs = true,
	.wall_signs = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_waterlogged
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_redstone_wall_torch_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_lit
	}
};
const mat_block_t mat_block_soul_wall_torch_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.piglin_repellents = true,
};
const mat_block_t mat_block_attached_pumpkin_stem_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	}
};
const mat_block_t mat_block_attached_melon_stem_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	}
};
const mat_block_t mat_block_water_cauldron_d = { 
	.resistance = 2,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_cauldron_level
	},
	.cauldrons = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_lava_cauldron_d = { 
	.resistance = 2,
	.hardness = 2,
	.transparent = true,
	.cauldrons = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_powder_snow_cauldron_d = { 
	.resistance = 2,
	.hardness = 2,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_cauldron_level
	},
	.cauldrons = true,
	.mineable_pickaxe = true,
	.mineable = true,
	.needs_wooden_tool = true,
	.needs = true,
};
const mat_block_t mat_block_potted_oak_sapling_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_spruce_sapling_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_birch_sapling_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_jungle_sapling_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_acacia_sapling_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_dark_oak_sapling_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_fern_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_dandelion_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_poppy_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_blue_orchid_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_allium_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_azure_bluet_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_red_tulip_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_orange_tulip_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_white_tulip_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_pink_tulip_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_oxeye_daisy_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_cornflower_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_lily_of_the_valley_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_wither_rose_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_red_mushroom_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_brown_mushroom_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_dead_bush_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_cactus_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_skeleton_wall_skull_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	}
};
const mat_block_t mat_block_wither_skeleton_wall_skull_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	}
};
const mat_block_t mat_block_zombie_wall_head_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	}
};
const mat_block_t mat_block_player_wall_head_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_head,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	}
};
const mat_block_t mat_block_creeper_wall_head_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	}
};
const mat_block_t mat_block_dragon_wall_head_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	}
};
const mat_block_t mat_block_white_wall_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_orange_wall_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_magenta_wall_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_light_blue_wall_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_yellow_wall_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_lime_wall_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_pink_wall_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_gray_wall_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_light_gray_wall_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_cyan_wall_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_purple_wall_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_blue_wall_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_brown_wall_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_green_wall_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_red_wall_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_black_wall_banner_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_banner,
	.mineable_axe = true,
	.mineable = true,
	.banners = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_facing_cardinal
	},
	.wall_post_override = true,
};
const mat_block_t mat_block_dead_tube_coral_wall_fan_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_dead_brain_coral_wall_fan_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_dead_bubble_coral_wall_fan_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_dead_fire_coral_wall_fan_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_dead_horn_coral_wall_fan_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_waterlogged
	},
	.mineable_pickaxe = true,
	.mineable = true,
};
const mat_block_t mat_block_tube_coral_wall_fan_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_waterlogged
	},
	.underwater_bonemeals = true,
	.wall_corals = true,
};
const mat_block_t mat_block_brain_coral_wall_fan_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_waterlogged
	},
	.underwater_bonemeals = true,
	.wall_corals = true,
};
const mat_block_t mat_block_bubble_coral_wall_fan_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_waterlogged
	},
	.underwater_bonemeals = true,
	.wall_corals = true,
};
const mat_block_t mat_block_fire_coral_wall_fan_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_waterlogged
	},
	.underwater_bonemeals = true,
	.wall_corals = true,
};
const mat_block_t mat_block_horn_coral_wall_fan_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_waterlogged
	},
	.underwater_bonemeals = true,
	.wall_corals = true,
};
const mat_block_t mat_block_potted_bamboo_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_void_air_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.air = true,
};
const mat_block_t mat_block_cave_air_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.air = true,
};
const mat_block_t mat_block_weeping_vines_plant_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.climbable = true,
};
const mat_block_t mat_block_twisting_vines_plant_d = {
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.mineable_axe = true,
	.mineable = true,
	.climbable = true,
};
const mat_block_t mat_block_crimson_wall_sign_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_sign,
	.mineable_axe = true,
	.mineable = true,
	.signs = true,
	.wall_signs = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_waterlogged
	},
	.non_flammable_wood = true,
	.wall_post_override = true,
};
const mat_block_t mat_block_warped_wall_sign_d = { 
	.resistance = 1,
	.hardness = 1,
	.transparent = true,
	.entity = mat_block_entity_sign,
	.mineable_axe = true,
	.mineable = true,
	.signs = true,
	.wall_signs = true,
	.modifiers_count = 2,
	.modifiers = {
		mat_state_modifier_facing_cardinal,
		mat_state_modifier_waterlogged
	},
	.non_flammable_wood = true,
	.wall_post_override = true,
};
const mat_block_t mat_block_potted_crimson_fungus_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_warped_fungus_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
	.hoglin_repellents = true,
};
const mat_block_t mat_block_potted_crimson_roots_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_warped_roots_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_candle_cake_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_lit
	},
	.candle_cakes = true,
};
const mat_block_t mat_block_white_candle_cake_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_lit
	},
	.candle_cakes = true,
};
const mat_block_t mat_block_orange_candle_cake_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_lit
	},
	.candle_cakes = true,
};
const mat_block_t mat_block_magenta_candle_cake_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_lit
	},
	.candle_cakes = true,
};
const mat_block_t mat_block_light_blue_candle_cake_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_lit
	},
	.candle_cakes = true,
};
const mat_block_t mat_block_yellow_candle_cake_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_lit
	},
	.candle_cakes = true,
};
const mat_block_t mat_block_lime_candle_cake_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_lit
	},
	.candle_cakes = true,
};
const mat_block_t mat_block_pink_candle_cake_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_lit
	},
	.candle_cakes = true,
};
const mat_block_t mat_block_gray_candle_cake_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_lit
	},
	.candle_cakes = true,
};
const mat_block_t mat_block_light_gray_candle_cake_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_lit
	},
	.candle_cakes = true,
};
const mat_block_t mat_block_cyan_candle_cake_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_lit
	},
	.candle_cakes = true,
};
const mat_block_t mat_block_purple_candle_cake_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_lit
	},
	.candle_cakes = true,
};
const mat_block_t mat_block_blue_candle_cake_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_lit
	},
	.candle_cakes = true,
};
const mat_block_t mat_block_brown_candle_cake_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_lit
	},
	.candle_cakes = true,
};
const mat_block_t mat_block_green_candle_cake_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_lit
	},
	.candle_cakes = true,
};
const mat_block_t mat_block_red_candle_cake_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_lit
	},
	.candle_cakes = true,
};
const mat_block_t mat_block_black_candle_cake_d = { 
	.resistance = 0.5,
	.hardness = 0.5,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_lit
	},
	.candle_cakes = true,
};
const mat_block_t mat_block_cave_vines_plant_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.modifiers_count = 1,
	.modifiers = {
		mat_state_modifier_cave_vines_berries
	},
	.mineable_axe = true,
	.mineable = true,
	.bee_growables = true,
	.climbable = true,
	.lush_ground_replaceable = true,
	.azalea_root_replaceable = true,
	.moss_replaceable = true,
};
const mat_block_t mat_block_potted_azalea_bush_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_potted_flowering_azalea_bush_d = { 
	.resistance = 0,
	.hardness = 0,
	.transparent = true,
	.flower_pots = true,
};
const mat_block_t mat_block_dried_kelp_block_d = {
	.resistance = 2.5,
	.hardness = 0.5,
	.encouragement = 30,
	.flammability = 60,
	.mineable_hoe = true,
	.mineable = true,
};
const mat_block_t* mat_blocks[] = {
	&mat_block_air_d,
	&mat_block_stone_d,
	&mat_block_granite_d,
	&mat_block_polished_granite_d,
	&mat_block_diorite_d,
	&mat_block_polished_diorite_d,
	&mat_block_andesite_d,
	&mat_block_polished_andesite_d,
	&mat_block_grass_block_d,
	&mat_block_dirt_d,
	&mat_block_coarse_dirt_d,
	&mat_block_podzol_d,
	&mat_block_cobblestone_d,
	&mat_block_oak_planks_d,
	&mat_block_spruce_planks_d,
	&mat_block_birch_planks_d,
	&mat_block_jungle_planks_d,
	&mat_block_acacia_planks_d,
	&mat_block_dark_oak_planks_d,
	&mat_block_oak_sapling_d,
	&mat_block_spruce_sapling_d,
	&mat_block_birch_sapling_d,
	&mat_block_jungle_sapling_d,
	&mat_block_acacia_sapling_d,
	&mat_block_dark_oak_sapling_d,
	&mat_block_bedrock_d,
	&mat_block_water_d,
	&mat_block_lava_d,
	&mat_block_sand_d,
	&mat_block_red_sand_d,
	&mat_block_gravel_d,
	&mat_block_gold_ore_d,
	&mat_block_deepslate_gold_ore_d,
	&mat_block_iron_ore_d,
	&mat_block_deepslate_iron_ore_d,
	&mat_block_coal_ore_d,
	&mat_block_deepslate_coal_ore_d,
	&mat_block_nether_gold_ore_d,
	&mat_block_oak_log_d,
	&mat_block_spruce_log_d,
	&mat_block_birch_log_d,
	&mat_block_jungle_log_d,
	&mat_block_acacia_log_d,
	&mat_block_dark_oak_log_d,
	&mat_block_stripped_spruce_log_d,
	&mat_block_stripped_birch_log_d,
	&mat_block_stripped_jungle_log_d,
	&mat_block_stripped_acacia_log_d,
	&mat_block_stripped_dark_oak_log_d,
	&mat_block_stripped_oak_log_d,
	&mat_block_oak_wood_d,
	&mat_block_spruce_wood_d,
	&mat_block_birch_wood_d,
	&mat_block_jungle_wood_d,
	&mat_block_acacia_wood_d,
	&mat_block_dark_oak_wood_d,
	&mat_block_stripped_oak_wood_d,
	&mat_block_stripped_spruce_wood_d,
	&mat_block_stripped_birch_wood_d,
	&mat_block_stripped_jungle_wood_d,
	&mat_block_stripped_acacia_wood_d,
	&mat_block_stripped_dark_oak_wood_d,
	&mat_block_oak_leaves_d,
	&mat_block_spruce_leaves_d,
	&mat_block_birch_leaves_d,
	&mat_block_jungle_leaves_d,
	&mat_block_acacia_leaves_d,
	&mat_block_dark_oak_leaves_d,
	&mat_block_azalea_leaves_d,
	&mat_block_flowering_azalea_leaves_d,
	&mat_block_sponge_d,
	&mat_block_wet_sponge_d,
	&mat_block_glass_d,
	&mat_block_lapis_ore_d,
	&mat_block_deepslate_lapis_ore_d,
	&mat_block_lapis_block_d,
	&mat_block_dispenser_d,
	&mat_block_sandstone_d,
	&mat_block_chiseled_sandstone_d,
	&mat_block_cut_sandstone_d,
	&mat_block_note_block_d,
	&mat_block_white_bed_d,
	&mat_block_orange_bed_d,
	&mat_block_magenta_bed_d,
	&mat_block_light_blue_bed_d,
	&mat_block_yellow_bed_d,
	&mat_block_lime_bed_d,
	&mat_block_pink_bed_d,
	&mat_block_gray_bed_d,
	&mat_block_light_gray_bed_d,
	&mat_block_cyan_bed_d,
	&mat_block_purple_bed_d,
	&mat_block_blue_bed_d,
	&mat_block_brown_bed_d,
	&mat_block_green_bed_d,
	&mat_block_red_bed_d,
	&mat_block_black_bed_d,
	&mat_block_powered_rail_d,
	&mat_block_detector_rail_d,
	&mat_block_sticky_piston_d,
	&mat_block_cobweb_d,
	&mat_block_grass_d,
	&mat_block_fern_d,
	&mat_block_dead_bush_d,
	&mat_block_seagrass_d,
	&mat_block_tall_seagrass_d,
	&mat_block_piston_d,
	&mat_block_piston_head_d,
	&mat_block_white_wool_d,
	&mat_block_orange_wool_d,
	&mat_block_magenta_wool_d,
	&mat_block_light_blue_wool_d,
	&mat_block_yellow_wool_d,
	&mat_block_lime_wool_d,
	&mat_block_pink_wool_d,
	&mat_block_gray_wool_d,
	&mat_block_light_gray_wool_d,
	&mat_block_cyan_wool_d,
	&mat_block_purple_wool_d,
	&mat_block_blue_wool_d,
	&mat_block_brown_wool_d,
	&mat_block_green_wool_d,
	&mat_block_red_wool_d,
	&mat_block_black_wool_d,
	&mat_block_moving_piston_d,
	&mat_block_dandelion_d,
	&mat_block_poppy_d,
	&mat_block_blue_orchid_d,
	&mat_block_allium_d,
	&mat_block_azure_bluet_d,
	&mat_block_red_tulip_d,
	&mat_block_orange_tulip_d,
	&mat_block_white_tulip_d,
	&mat_block_pink_tulip_d,
	&mat_block_oxeye_daisy_d,
	&mat_block_cornflower_d,
	&mat_block_wither_rose_d,
	&mat_block_lily_of_the_valley_d,
	&mat_block_brown_mushroom_d,
	&mat_block_red_mushroom_d,
	&mat_block_gold_block_d,
	&mat_block_iron_block_d,
	&mat_block_bricks_d,
	&mat_block_tnt_d,
	&mat_block_bookshelf_d,
	&mat_block_mossy_cobblestone_d,
	&mat_block_obsidian_d,
	&mat_block_torch_d,
	&mat_block_wall_torch_d,
	&mat_block_fire_d,
	&mat_block_soul_fire_d,
	&mat_block_spawner_d,
	&mat_block_oak_stairs_d,
	&mat_block_chest_d,
	&mat_block_redstone_wire_d,
	&mat_block_diamond_ore_d,
	&mat_block_deepslate_diamond_ore_d,
	&mat_block_diamond_block_d,
	&mat_block_crafting_table_d,
	&mat_block_wheat_d,
	&mat_block_farmland_d,
	&mat_block_furnace_d,
	&mat_block_oak_sign_d,
	&mat_block_spruce_sign_d,
	&mat_block_birch_sign_d,
	&mat_block_acacia_sign_d,
	&mat_block_jungle_sign_d,
	&mat_block_dark_oak_sign_d,
	&mat_block_oak_door_d,
	&mat_block_ladder_d,
	&mat_block_rail_d,
	&mat_block_cobblestone_stairs_d,
	&mat_block_oak_wall_sign_d,
	&mat_block_spruce_wall_sign_d,
	&mat_block_birch_wall_sign_d,
	&mat_block_acacia_wall_sign_d,
	&mat_block_jungle_wall_sign_d,
	&mat_block_dark_oak_wall_sign_d,
	&mat_block_lever_d,
	&mat_block_stone_pressure_plate_d,
	&mat_block_iron_door_d,
	&mat_block_oak_pressure_plate_d,
	&mat_block_spruce_pressure_plate_d,
	&mat_block_birch_pressure_plate_d,
	&mat_block_jungle_pressure_plate_d,
	&mat_block_acacia_pressure_plate_d,
	&mat_block_dark_oak_pressure_plate_d,
	&mat_block_redstone_ore_d,
	&mat_block_deepslate_redstone_ore_d,
	&mat_block_redstone_torch_d,
	&mat_block_redstone_wall_torch_d,
	&mat_block_stone_button_d,
	&mat_block_snow_d,
	&mat_block_ice_d,
	&mat_block_snow_block_d,
	&mat_block_cactus_d,
	&mat_block_clay_d,
	&mat_block_sugar_cane_d,
	&mat_block_jukebox_d,
	&mat_block_oak_fence_d,
	&mat_block_pumpkin_d,
	&mat_block_netherrack_d,
	&mat_block_soul_sand_d,
	&mat_block_soul_soil_d,
	&mat_block_basalt_d,
	&mat_block_polished_basalt_d,
	&mat_block_soul_torch_d,
	&mat_block_soul_wall_torch_d,
	&mat_block_glowstone_d,
	&mat_block_nether_portal_d,
	&mat_block_carved_pumpkin_d,
	&mat_block_jack_o_lantern_d,
	&mat_block_cake_d,
	&mat_block_repeater_d,
	&mat_block_white_stained_glass_d,
	&mat_block_orange_stained_glass_d,
	&mat_block_magenta_stained_glass_d,
	&mat_block_light_blue_stained_glass_d,
	&mat_block_yellow_stained_glass_d,
	&mat_block_lime_stained_glass_d,
	&mat_block_pink_stained_glass_d,
	&mat_block_gray_stained_glass_d,
	&mat_block_light_gray_stained_glass_d,
	&mat_block_cyan_stained_glass_d,
	&mat_block_purple_stained_glass_d,
	&mat_block_blue_stained_glass_d,
	&mat_block_brown_stained_glass_d,
	&mat_block_green_stained_glass_d,
	&mat_block_red_stained_glass_d,
	&mat_block_black_stained_glass_d,
	&mat_block_oak_trapdoor_d,
	&mat_block_spruce_trapdoor_d,
	&mat_block_birch_trapdoor_d,
	&mat_block_jungle_trapdoor_d,
	&mat_block_acacia_trapdoor_d,
	&mat_block_dark_oak_trapdoor_d,
	&mat_block_stone_bricks_d,
	&mat_block_mossy_stone_bricks_d,
	&mat_block_cracked_stone_bricks_d,
	&mat_block_chiseled_stone_bricks_d,
	&mat_block_infested_stone_d,
	&mat_block_infested_cobblestone_d,
	&mat_block_infested_stone_bricks_d,
	&mat_block_infested_mossy_stone_bricks_d,
	&mat_block_infested_cracked_stone_bricks_d,
	&mat_block_infested_chiseled_stone_bricks_d,
	&mat_block_brown_mushroom_block_d,
	&mat_block_red_mushroom_block_d,
	&mat_block_mushroom_stem_d,
	&mat_block_iron_bars_d,
	&mat_block_chain_d,
	&mat_block_glass_pane_d,
	&mat_block_melon_d,
	&mat_block_attached_pumpkin_stem_d,
	&mat_block_attached_melon_stem_d,
	&mat_block_pumpkin_stem_d,
	&mat_block_melon_stem_d,
	&mat_block_vine_d,
	&mat_block_glow_lichen_d,
	&mat_block_oak_fence_gate_d,
	&mat_block_brick_stairs_d,
	&mat_block_stone_brick_stairs_d,
	&mat_block_mycelium_d,
	&mat_block_lily_pad_d,
	&mat_block_nether_bricks_d,
	&mat_block_nether_brick_fence_d,
	&mat_block_nether_brick_stairs_d,
	&mat_block_nether_wart_d,
	&mat_block_enchanting_table_d,
	&mat_block_brewing_stand_d,
	&mat_block_cauldron_d,
	&mat_block_water_cauldron_d,
	&mat_block_lava_cauldron_d,
	&mat_block_powder_snow_cauldron_d,
	&mat_block_end_portal_d,
	&mat_block_end_portal_frame_d,
	&mat_block_end_stone_d,
	&mat_block_dragon_egg_d,
	&mat_block_redstone_lamp_d,
	&mat_block_cocoa_d,
	&mat_block_sandstone_stairs_d,
	&mat_block_emerald_ore_d,
	&mat_block_deepslate_emerald_ore_d,
	&mat_block_ender_chest_d,
	&mat_block_tripwire_hook_d,
	&mat_block_tripwire_d,
	&mat_block_emerald_block_d,
	&mat_block_spruce_stairs_d,
	&mat_block_birch_stairs_d,
	&mat_block_jungle_stairs_d,
	&mat_block_command_block_d,
	&mat_block_beacon_d,
	&mat_block_cobblestone_wall_d,
	&mat_block_mossy_cobblestone_wall_d,
	&mat_block_flower_pot_d,
	&mat_block_potted_oak_sapling_d,
	&mat_block_potted_spruce_sapling_d,
	&mat_block_potted_birch_sapling_d,
	&mat_block_potted_jungle_sapling_d,
	&mat_block_potted_acacia_sapling_d,
	&mat_block_potted_dark_oak_sapling_d,
	&mat_block_potted_fern_d,
	&mat_block_potted_dandelion_d,
	&mat_block_potted_poppy_d,
	&mat_block_potted_blue_orchid_d,
	&mat_block_potted_allium_d,
	&mat_block_potted_azure_bluet_d,
	&mat_block_potted_red_tulip_d,
	&mat_block_potted_orange_tulip_d,
	&mat_block_potted_white_tulip_d,
	&mat_block_potted_pink_tulip_d,
	&mat_block_potted_oxeye_daisy_d,
	&mat_block_potted_cornflower_d,
	&mat_block_potted_lily_of_the_valley_d,
	&mat_block_potted_wither_rose_d,
	&mat_block_potted_red_mushroom_d,
	&mat_block_potted_brown_mushroom_d,
	&mat_block_potted_dead_bush_d,
	&mat_block_potted_cactus_d,
	&mat_block_carrots_d,
	&mat_block_potatoes_d,
	&mat_block_oak_button_d,
	&mat_block_spruce_button_d,
	&mat_block_birch_button_d,
	&mat_block_jungle_button_d,
	&mat_block_acacia_button_d,
	&mat_block_dark_oak_button_d,
	&mat_block_skeleton_skull_d,
	&mat_block_skeleton_wall_skull_d,
	&mat_block_wither_skeleton_skull_d,
	&mat_block_wither_skeleton_wall_skull_d,
	&mat_block_zombie_head_d,
	&mat_block_zombie_wall_head_d,
	&mat_block_player_head_d,
	&mat_block_player_wall_head_d,
	&mat_block_creeper_head_d,
	&mat_block_creeper_wall_head_d,
	&mat_block_dragon_head_d,
	&mat_block_dragon_wall_head_d,
	&mat_block_anvil_d,
	&mat_block_chipped_anvil_d,
	&mat_block_damaged_anvil_d,
	&mat_block_trapped_chest_d,
	&mat_block_light_weighted_pressure_plate_d,
	&mat_block_heavy_weighted_pressure_plate_d,
	&mat_block_comparator_d,
	&mat_block_daylight_detector_d,
	&mat_block_redstone_block_d,
	&mat_block_nether_quartz_ore_d,
	&mat_block_hopper_d,
	&mat_block_quartz_block_d,
	&mat_block_chiseled_quartz_block_d,
	&mat_block_quartz_pillar_d,
	&mat_block_quartz_stairs_d,
	&mat_block_activator_rail_d,
	&mat_block_dropper_d,
	&mat_block_white_terracotta_d,
	&mat_block_orange_terracotta_d,
	&mat_block_magenta_terracotta_d,
	&mat_block_light_blue_terracotta_d,
	&mat_block_yellow_terracotta_d,
	&mat_block_lime_terracotta_d,
	&mat_block_pink_terracotta_d,
	&mat_block_gray_terracotta_d,
	&mat_block_light_gray_terracotta_d,
	&mat_block_cyan_terracotta_d,
	&mat_block_purple_terracotta_d,
	&mat_block_blue_terracotta_d,
	&mat_block_brown_terracotta_d,
	&mat_block_green_terracotta_d,
	&mat_block_red_terracotta_d,
	&mat_block_black_terracotta_d,
	&mat_block_white_stained_glass_pane_d,
	&mat_block_orange_stained_glass_pane_d,
	&mat_block_magenta_stained_glass_pane_d,
	&mat_block_light_blue_stained_glass_pane_d,
	&mat_block_yellow_stained_glass_pane_d,
	&mat_block_lime_stained_glass_pane_d,
	&mat_block_pink_stained_glass_pane_d,
	&mat_block_gray_stained_glass_pane_d,
	&mat_block_light_gray_stained_glass_pane_d,
	&mat_block_cyan_stained_glass_pane_d,
	&mat_block_purple_stained_glass_pane_d,
	&mat_block_blue_stained_glass_pane_d,
	&mat_block_brown_stained_glass_pane_d,
	&mat_block_green_stained_glass_pane_d,
	&mat_block_red_stained_glass_pane_d,
	&mat_block_black_stained_glass_pane_d,
	&mat_block_acacia_stairs_d,
	&mat_block_dark_oak_stairs_d,
	&mat_block_slime_block_d,
	&mat_block_barrier_d,
	&mat_block_light_d,
	&mat_block_iron_trapdoor_d,
	&mat_block_prismarine_d,
	&mat_block_prismarine_bricks_d,
	&mat_block_dark_prismarine_d,
	&mat_block_prismarine_stairs_d,
	&mat_block_prismarine_brick_stairs_d,
	&mat_block_dark_prismarine_stairs_d,
	&mat_block_prismarine_slab_d,
	&mat_block_prismarine_brick_slab_d,
	&mat_block_dark_prismarine_slab_d,
	&mat_block_sea_lantern_d,
	&mat_block_hay_block_d,
	&mat_block_white_carpet_d,
	&mat_block_orange_carpet_d,
	&mat_block_magenta_carpet_d,
	&mat_block_light_blue_carpet_d,
	&mat_block_yellow_carpet_d,
	&mat_block_lime_carpet_d,
	&mat_block_pink_carpet_d,
	&mat_block_gray_carpet_d,
	&mat_block_light_gray_carpet_d,
	&mat_block_cyan_carpet_d,
	&mat_block_purple_carpet_d,
	&mat_block_blue_carpet_d,
	&mat_block_brown_carpet_d,
	&mat_block_green_carpet_d,
	&mat_block_red_carpet_d,
	&mat_block_black_carpet_d,
	&mat_block_terracotta_d,
	&mat_block_coal_block_d,
	&mat_block_packed_ice_d,
	&mat_block_sunflower_d,
	&mat_block_lilac_d,
	&mat_block_rose_bush_d,
	&mat_block_peony_d,
	&mat_block_tall_grass_d,
	&mat_block_large_fern_d,
	&mat_block_white_banner_d,
	&mat_block_orange_banner_d,
	&mat_block_magenta_banner_d,
	&mat_block_light_blue_banner_d,
	&mat_block_yellow_banner_d,
	&mat_block_lime_banner_d,
	&mat_block_pink_banner_d,
	&mat_block_gray_banner_d,
	&mat_block_light_gray_banner_d,
	&mat_block_cyan_banner_d,
	&mat_block_purple_banner_d,
	&mat_block_blue_banner_d,
	&mat_block_brown_banner_d,
	&mat_block_green_banner_d,
	&mat_block_red_banner_d,
	&mat_block_black_banner_d,
	&mat_block_white_wall_banner_d,
	&mat_block_orange_wall_banner_d,
	&mat_block_magenta_wall_banner_d,
	&mat_block_light_blue_wall_banner_d,
	&mat_block_yellow_wall_banner_d,
	&mat_block_lime_wall_banner_d,
	&mat_block_pink_wall_banner_d,
	&mat_block_gray_wall_banner_d,
	&mat_block_light_gray_wall_banner_d,
	&mat_block_cyan_wall_banner_d,
	&mat_block_purple_wall_banner_d,
	&mat_block_blue_wall_banner_d,
	&mat_block_brown_wall_banner_d,
	&mat_block_green_wall_banner_d,
	&mat_block_red_wall_banner_d,
	&mat_block_black_wall_banner_d,
	&mat_block_red_sandstone_d,
	&mat_block_chiseled_red_sandstone_d,
	&mat_block_cut_red_sandstone_d,
	&mat_block_red_sandstone_stairs_d,
	&mat_block_oak_slab_d,
	&mat_block_spruce_slab_d,
	&mat_block_birch_slab_d,
	&mat_block_jungle_slab_d,
	&mat_block_acacia_slab_d,
	&mat_block_dark_oak_slab_d,
	&mat_block_stone_slab_d,
	&mat_block_smooth_stone_slab_d,
	&mat_block_sandstone_slab_d,
	&mat_block_cut_sandstone_slab_d,
	&mat_block_petrified_oak_slab_d,
	&mat_block_cobblestone_slab_d,
	&mat_block_brick_slab_d,
	&mat_block_stone_brick_slab_d,
	&mat_block_nether_brick_slab_d,
	&mat_block_quartz_slab_d,
	&mat_block_red_sandstone_slab_d,
	&mat_block_cut_red_sandstone_slab_d,
	&mat_block_purpur_slab_d,
	&mat_block_smooth_stone_d,
	&mat_block_smooth_sandstone_d,
	&mat_block_smooth_quartz_d,
	&mat_block_smooth_red_sandstone_d,
	&mat_block_spruce_fence_gate_d,
	&mat_block_birch_fence_gate_d,
	&mat_block_jungle_fence_gate_d,
	&mat_block_acacia_fence_gate_d,
	&mat_block_dark_oak_fence_gate_d,
	&mat_block_spruce_fence_d,
	&mat_block_birch_fence_d,
	&mat_block_jungle_fence_d,
	&mat_block_acacia_fence_d,
	&mat_block_dark_oak_fence_d,
	&mat_block_spruce_door_d,
	&mat_block_birch_door_d,
	&mat_block_jungle_door_d,
	&mat_block_acacia_door_d,
	&mat_block_dark_oak_door_d,
	&mat_block_end_rod_d,
	&mat_block_chorus_plant_d,
	&mat_block_chorus_flower_d,
	&mat_block_purpur_block_d,
	&mat_block_purpur_pillar_d,
	&mat_block_purpur_stairs_d,
	&mat_block_end_stone_bricks_d,
	&mat_block_beetroots_d,
	&mat_block_dirt_path_d,
	&mat_block_end_gateway_d,
	&mat_block_repeating_command_block_d,
	&mat_block_chain_command_block_d,
	&mat_block_frosted_ice_d,
	&mat_block_magma_block_d,
	&mat_block_nether_wart_block_d,
	&mat_block_red_nether_bricks_d,
	&mat_block_bone_block_d,
	&mat_block_structure_void_d,
	&mat_block_observer_d,
	&mat_block_shulker_box_d,
	&mat_block_white_shulker_box_d,
	&mat_block_orange_shulker_box_d,
	&mat_block_magenta_shulker_box_d,
	&mat_block_light_blue_shulker_box_d,
	&mat_block_yellow_shulker_box_d,
	&mat_block_lime_shulker_box_d,
	&mat_block_pink_shulker_box_d,
	&mat_block_gray_shulker_box_d,
	&mat_block_light_gray_shulker_box_d,
	&mat_block_cyan_shulker_box_d,
	&mat_block_purple_shulker_box_d,
	&mat_block_blue_shulker_box_d,
	&mat_block_brown_shulker_box_d,
	&mat_block_green_shulker_box_d,
	&mat_block_red_shulker_box_d,
	&mat_block_black_shulker_box_d,
	&mat_block_white_glazed_terracotta_d,
	&mat_block_orange_glazed_terracotta_d,
	&mat_block_magenta_glazed_terracotta_d,
	&mat_block_light_blue_glazed_terracotta_d,
	&mat_block_yellow_glazed_terracotta_d,
	&mat_block_lime_glazed_terracotta_d,
	&mat_block_pink_glazed_terracotta_d,
	&mat_block_gray_glazed_terracotta_d,
	&mat_block_light_gray_glazed_terracotta_d,
	&mat_block_cyan_glazed_terracotta_d,
	&mat_block_purple_glazed_terracotta_d,
	&mat_block_blue_glazed_terracotta_d,
	&mat_block_brown_glazed_terracotta_d,
	&mat_block_green_glazed_terracotta_d,
	&mat_block_red_glazed_terracotta_d,
	&mat_block_black_glazed_terracotta_d,
	&mat_block_white_concrete_d,
	&mat_block_orange_concrete_d,
	&mat_block_magenta_concrete_d,
	&mat_block_light_blue_concrete_d,
	&mat_block_yellow_concrete_d,
	&mat_block_lime_concrete_d,
	&mat_block_pink_concrete_d,
	&mat_block_gray_concrete_d,
	&mat_block_light_gray_concrete_d,
	&mat_block_cyan_concrete_d,
	&mat_block_purple_concrete_d,
	&mat_block_blue_concrete_d,
	&mat_block_brown_concrete_d,
	&mat_block_green_concrete_d,
	&mat_block_red_concrete_d,
	&mat_block_black_concrete_d,
	&mat_block_white_concrete_powder_d,
	&mat_block_orange_concrete_powder_d,
	&mat_block_magenta_concrete_powder_d,
	&mat_block_light_blue_concrete_powder_d,
	&mat_block_yellow_concrete_powder_d,
	&mat_block_lime_concrete_powder_d,
	&mat_block_pink_concrete_powder_d,
	&mat_block_gray_concrete_powder_d,
	&mat_block_light_gray_concrete_powder_d,
	&mat_block_cyan_concrete_powder_d,
	&mat_block_purple_concrete_powder_d,
	&mat_block_blue_concrete_powder_d,
	&mat_block_brown_concrete_powder_d,
	&mat_block_green_concrete_powder_d,
	&mat_block_red_concrete_powder_d,
	&mat_block_black_concrete_powder_d,
	&mat_block_kelp_d,
	&mat_block_kelp_plant_d,
	&mat_block_dried_kelp_block_d,
	&mat_block_turtle_egg_d,
	&mat_block_dead_tube_coral_block_d,
	&mat_block_dead_brain_coral_block_d,
	&mat_block_dead_bubble_coral_block_d,
	&mat_block_dead_fire_coral_block_d,
	&mat_block_dead_horn_coral_block_d,
	&mat_block_tube_coral_block_d,
	&mat_block_brain_coral_block_d,
	&mat_block_bubble_coral_block_d,
	&mat_block_fire_coral_block_d,
	&mat_block_horn_coral_block_d,
	&mat_block_dead_tube_coral_d,
	&mat_block_dead_brain_coral_d,
	&mat_block_dead_bubble_coral_d,
	&mat_block_dead_fire_coral_d,
	&mat_block_dead_horn_coral_d,
	&mat_block_tube_coral_d,
	&mat_block_brain_coral_d,
	&mat_block_bubble_coral_d,
	&mat_block_fire_coral_d,
	&mat_block_horn_coral_d,
	&mat_block_dead_tube_coral_fan_d,
	&mat_block_dead_brain_coral_fan_d,
	&mat_block_dead_bubble_coral_fan_d,
	&mat_block_dead_fire_coral_fan_d,
	&mat_block_dead_horn_coral_fan_d,
	&mat_block_tube_coral_fan_d,
	&mat_block_brain_coral_fan_d,
	&mat_block_bubble_coral_fan_d,
	&mat_block_fire_coral_fan_d,
	&mat_block_horn_coral_fan_d,
	&mat_block_dead_tube_coral_wall_fan_d,
	&mat_block_dead_brain_coral_wall_fan_d,
	&mat_block_dead_bubble_coral_wall_fan_d,
	&mat_block_dead_fire_coral_wall_fan_d,
	&mat_block_dead_horn_coral_wall_fan_d,
	&mat_block_tube_coral_wall_fan_d,
	&mat_block_brain_coral_wall_fan_d,
	&mat_block_bubble_coral_wall_fan_d,
	&mat_block_fire_coral_wall_fan_d,
	&mat_block_horn_coral_wall_fan_d,
	&mat_block_sea_pickle_d,
	&mat_block_blue_ice_d,
	&mat_block_conduit_d,
	&mat_block_bamboo_sapling_d,
	&mat_block_bamboo_d,
	&mat_block_potted_bamboo_d,
	&mat_block_void_air_d,
	&mat_block_cave_air_d,
	&mat_block_bubble_column_d,
	&mat_block_polished_granite_stairs_d,
	&mat_block_smooth_red_sandstone_stairs_d,
	&mat_block_mossy_stone_brick_stairs_d,
	&mat_block_polished_diorite_stairs_d,
	&mat_block_mossy_cobblestone_stairs_d,
	&mat_block_end_stone_brick_stairs_d,
	&mat_block_stone_stairs_d,
	&mat_block_smooth_sandstone_stairs_d,
	&mat_block_smooth_quartz_stairs_d,
	&mat_block_granite_stairs_d,
	&mat_block_andesite_stairs_d,
	&mat_block_red_nether_brick_stairs_d,
	&mat_block_polished_andesite_stairs_d,
	&mat_block_diorite_stairs_d,
	&mat_block_polished_granite_slab_d,
	&mat_block_smooth_red_sandstone_slab_d,
	&mat_block_mossy_stone_brick_slab_d,
	&mat_block_polished_diorite_slab_d,
	&mat_block_mossy_cobblestone_slab_d,
	&mat_block_end_stone_brick_slab_d,
	&mat_block_smooth_sandstone_slab_d,
	&mat_block_smooth_quartz_slab_d,
	&mat_block_granite_slab_d,
	&mat_block_andesite_slab_d,
	&mat_block_red_nether_brick_slab_d,
	&mat_block_polished_andesite_slab_d,
	&mat_block_diorite_slab_d,
	&mat_block_brick_wall_d,
	&mat_block_prismarine_wall_d,
	&mat_block_red_sandstone_wall_d,
	&mat_block_mossy_stone_brick_wall_d,
	&mat_block_granite_wall_d,
	&mat_block_stone_brick_wall_d,
	&mat_block_nether_brick_wall_d,
	&mat_block_andesite_wall_d,
	&mat_block_red_nether_brick_wall_d,
	&mat_block_sandstone_wall_d,
	&mat_block_end_stone_brick_wall_d,
	&mat_block_diorite_wall_d,
	&mat_block_scaffolding_d,
	&mat_block_loom_d,
	&mat_block_barrel_d,
	&mat_block_smoker_d,
	&mat_block_blast_furnace_d,
	&mat_block_cartography_table_d,
	&mat_block_fletching_table_d,
	&mat_block_grindstone_d,
	&mat_block_lectern_d,
	&mat_block_smithing_table_d,
	&mat_block_stonecutter_d,
	&mat_block_bell_d,
	&mat_block_lantern_d,
	&mat_block_soul_lantern_d,
	&mat_block_campfire_d,
	&mat_block_soul_campfire_d,
	&mat_block_sweet_berry_bush_d,
	&mat_block_warped_stem_d,
	&mat_block_stripped_warped_stem_d,
	&mat_block_warped_hyphae_d,
	&mat_block_stripped_warped_hyphae_d,
	&mat_block_warped_nylium_d,
	&mat_block_warped_fungus_d,
	&mat_block_warped_wart_block_d,
	&mat_block_warped_roots_d,
	&mat_block_nether_sprouts_d,
	&mat_block_crimson_stem_d,
	&mat_block_stripped_crimson_stem_d,
	&mat_block_crimson_hyphae_d,
	&mat_block_stripped_crimson_hyphae_d,
	&mat_block_crimson_nylium_d,
	&mat_block_crimson_fungus_d,
	&mat_block_shroomlight_d,
	&mat_block_weeping_vines_d,
	&mat_block_weeping_vines_plant_d,
	&mat_block_twisting_vines_d,
	&mat_block_twisting_vines_plant_d,
	&mat_block_crimson_roots_d,
	&mat_block_crimson_planks_d,
	&mat_block_warped_planks_d,
	&mat_block_crimson_slab_d,
	&mat_block_warped_slab_d,
	&mat_block_crimson_pressure_plate_d,
	&mat_block_warped_pressure_plate_d,
	&mat_block_crimson_fence_d,
	&mat_block_warped_fence_d,
	&mat_block_crimson_trapdoor_d,
	&mat_block_warped_trapdoor_d,
	&mat_block_crimson_fence_gate_d,
	&mat_block_warped_fence_gate_d,
	&mat_block_crimson_stairs_d,
	&mat_block_warped_stairs_d,
	&mat_block_crimson_button_d,
	&mat_block_warped_button_d,
	&mat_block_crimson_door_d,
	&mat_block_warped_door_d,
	&mat_block_crimson_sign_d,
	&mat_block_warped_sign_d,
	&mat_block_crimson_wall_sign_d,
	&mat_block_warped_wall_sign_d,
	&mat_block_structure_block_d,
	&mat_block_jigsaw_d,
	&mat_block_composter_d,
	&mat_block_target_d,
	&mat_block_bee_nest_d,
	&mat_block_beehive_d,
	&mat_block_honey_block_d,
	&mat_block_honeycomb_block_d,
	&mat_block_netherite_block_d,
	&mat_block_ancient_debris_d,
	&mat_block_crying_obsidian_d,
	&mat_block_respawn_anchor_d,
	&mat_block_potted_crimson_fungus_d,
	&mat_block_potted_warped_fungus_d,
	&mat_block_potted_crimson_roots_d,
	&mat_block_potted_warped_roots_d,
	&mat_block_lodestone_d,
	&mat_block_blackstone_d,
	&mat_block_blackstone_stairs_d,
	&mat_block_blackstone_wall_d,
	&mat_block_blackstone_slab_d,
	&mat_block_polished_blackstone_d,
	&mat_block_polished_blackstone_bricks_d,
	&mat_block_cracked_polished_blackstone_bricks_d,
	&mat_block_chiseled_polished_blackstone_d,
	&mat_block_polished_blackstone_brick_slab_d,
	&mat_block_polished_blackstone_brick_stairs_d,
	&mat_block_polished_blackstone_brick_wall_d,
	&mat_block_gilded_blackstone_d,
	&mat_block_polished_blackstone_stairs_d,
	&mat_block_polished_blackstone_slab_d,
	&mat_block_polished_blackstone_pressure_plate_d,
	&mat_block_polished_blackstone_button_d,
	&mat_block_polished_blackstone_wall_d,
	&mat_block_chiseled_nether_bricks_d,
	&mat_block_cracked_nether_bricks_d,
	&mat_block_quartz_bricks_d,
	&mat_block_candle_d,
	&mat_block_white_candle_d,
	&mat_block_orange_candle_d,
	&mat_block_magenta_candle_d,
	&mat_block_light_blue_candle_d,
	&mat_block_yellow_candle_d,
	&mat_block_lime_candle_d,
	&mat_block_pink_candle_d,
	&mat_block_gray_candle_d,
	&mat_block_light_gray_candle_d,
	&mat_block_cyan_candle_d,
	&mat_block_purple_candle_d,
	&mat_block_blue_candle_d,
	&mat_block_brown_candle_d,
	&mat_block_green_candle_d,
	&mat_block_red_candle_d,
	&mat_block_black_candle_d,
	&mat_block_candle_cake_d,
	&mat_block_white_candle_cake_d,
	&mat_block_orange_candle_cake_d,
	&mat_block_magenta_candle_cake_d,
	&mat_block_light_blue_candle_cake_d,
	&mat_block_yellow_candle_cake_d,
	&mat_block_lime_candle_cake_d,
	&mat_block_pink_candle_cake_d,
	&mat_block_gray_candle_cake_d,
	&mat_block_light_gray_candle_cake_d,
	&mat_block_cyan_candle_cake_d,
	&mat_block_purple_candle_cake_d,
	&mat_block_blue_candle_cake_d,
	&mat_block_brown_candle_cake_d,
	&mat_block_green_candle_cake_d,
	&mat_block_red_candle_cake_d,
	&mat_block_black_candle_cake_d,
	&mat_block_amethyst_block_d,
	&mat_block_budding_amethyst_d,
	&mat_block_amethyst_cluster_d,
	&mat_block_large_amethyst_bud_d,
	&mat_block_medium_amethyst_bud_d,
	&mat_block_small_amethyst_bud_d,
	&mat_block_tuff_d,
	&mat_block_calcite_d,
	&mat_block_tinted_glass_d,
	&mat_block_powder_snow_d,
	&mat_block_sculk_sensor_d,
	&mat_block_oxidized_copper_d,
	&mat_block_weathered_copper_d,
	&mat_block_exposed_copper_d,
	&mat_block_copper_block_d,
	&mat_block_copper_ore_d,
	&mat_block_deepslate_copper_ore_d,
	&mat_block_oxidized_cut_copper_d,
	&mat_block_weathered_cut_copper_d,
	&mat_block_exposed_cut_copper_d,
	&mat_block_cut_copper_d,
	&mat_block_oxidized_cut_copper_stairs_d,
	&mat_block_weathered_cut_copper_stairs_d,
	&mat_block_exposed_cut_copper_stairs_d,
	&mat_block_cut_copper_stairs_d,
	&mat_block_oxidized_cut_copper_slab_d,
	&mat_block_weathered_cut_copper_slab_d,
	&mat_block_exposed_cut_copper_slab_d,
	&mat_block_cut_copper_slab_d,
	&mat_block_waxed_copper_block_d,
	&mat_block_waxed_weathered_copper_d,
	&mat_block_waxed_exposed_copper_d,
	&mat_block_waxed_oxidized_copper_d,
	&mat_block_waxed_oxidized_cut_copper_d,
	&mat_block_waxed_weathered_cut_copper_d,
	&mat_block_waxed_exposed_cut_copper_d,
	&mat_block_waxed_cut_copper_d,
	&mat_block_waxed_oxidized_cut_copper_stairs_d,
	&mat_block_waxed_weathered_cut_copper_stairs_d,
	&mat_block_waxed_exposed_cut_copper_stairs_d,
	&mat_block_waxed_cut_copper_stairs_d,
	&mat_block_waxed_oxidized_cut_copper_slab_d,
	&mat_block_waxed_weathered_cut_copper_slab_d,
	&mat_block_waxed_exposed_cut_copper_slab_d,
	&mat_block_waxed_cut_copper_slab_d,
	&mat_block_lightning_rod_d,
	&mat_block_pointed_dripstone_d,
	&mat_block_dripstone_block_d,
	&mat_block_cave_vines_d,
	&mat_block_cave_vines_plant_d,
	&mat_block_spore_blossom_d,
	&mat_block_azalea_d,
	&mat_block_flowering_azalea_d,
	&mat_block_moss_carpet_d,
	&mat_block_moss_block_d,
	&mat_block_big_dripleaf_d,
	&mat_block_big_dripleaf_stem_d,
	&mat_block_small_dripleaf_d,
	&mat_block_hanging_roots_d,
	&mat_block_rooted_dirt_d,
	&mat_block_deepslate_d,
	&mat_block_cobbled_deepslate_d,
	&mat_block_cobbled_deepslate_stairs_d,
	&mat_block_cobbled_deepslate_slab_d,
	&mat_block_cobbled_deepslate_wall_d,
	&mat_block_polished_deepslate_d,
	&mat_block_polished_deepslate_stairs_d,
	&mat_block_polished_deepslate_slab_d,
	&mat_block_polished_deepslate_wall_d,
	&mat_block_deepslate_tiles_d,
	&mat_block_deepslate_tile_stairs_d,
	&mat_block_deepslate_tile_slab_d,
	&mat_block_deepslate_tile_wall_d,
	&mat_block_deepslate_bricks_d,
	&mat_block_deepslate_brick_stairs_d,
	&mat_block_deepslate_brick_slab_d,
	&mat_block_deepslate_brick_wall_d,
	&mat_block_chiseled_deepslate_d,
	&mat_block_cracked_deepslate_bricks_d,
	&mat_block_cracked_deepslate_tiles_d,
	&mat_block_infested_deepslate_d,
	&mat_block_smooth_basalt_d,
	&mat_block_raw_iron_block_d,
	&mat_block_raw_copper_block_d,
	&mat_block_raw_gold_block_d,
	&mat_block_potted_azalea_bush_d,
	&mat_block_potted_flowering_azalea_bush_d,
};
