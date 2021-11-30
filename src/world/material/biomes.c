#include "material.h"
#include "../../util/str_util.h"

const mat_biome_t mat_biome_badlands_d = {
	.name = UTL_CSTRTOSTR("minecraft:badlands"),
	.precipitation = mat_precipitation_none,
	.temperature = 2.0,
	.downfall = 0.0,
	.category = mat_biome_category_mesa,
	.effects = {
		.sky_color = 7254527,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.has_foliage_color = true,
		.foliage_color = 10387789,
		.has_grass_color = true,
		.grass_color = 9470285,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_bamboo_jungle_d = {
	.name = UTL_CSTRTOSTR("minecraft:bamboo_jungle"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.95,
	.downfall = 0.9,
	.category = mat_biome_category_jungle,
	.effects = {
		.sky_color = 7842047,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_basalt_deltas_d = {
	.name = UTL_CSTRTOSTR("minecraft:basalt_deltas"),
	.precipitation = mat_precipitation_none,
	.temperature = 2.0,
	.downfall = 0.0,
	.category = mat_biome_category_nether,
	.effects = {
		.sky_color = 7254527,
		.water_fog_color = 329011,
		.fog_color = 6840176,
		.music = {
			.sound = UTL_CSTRTOSTR("minecraft:music.nether.basalt_deltas"),
			.max_delay = 24000,
			.min_delay = 12000,
		},
		.ambient_sound = UTL_CSTRTOSTR("minecraft:ambient.basalt_deltas.loop"),
		.additions_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.basalt_deltas.additions"),
			.tick_chance = 0.0111,
		},
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.basalt_deltas.mood"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
	.particle = {
		.probability = 0.118093334,
		.options = {
			.type = UTL_CSTRTOSTR("minecraft:white_ash"),
		},
	},
};
const mat_biome_t mat_biome_beach_d = {
	.name = UTL_CSTRTOSTR("minecraft:beach"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.8,
	.downfall = 0.4,
	.category = mat_biome_category_beach,
	.effects = {
		.sky_color = 7907327,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_birch_forest_d = {
	.name = UTL_CSTRTOSTR("minecraft:birch_forest"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.6,
	.downfall = 0.6,
	.category = mat_biome_category_forest,
	.effects = {
		.sky_color = 8037887,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_cold_ocean_d = {
	.name = UTL_CSTRTOSTR("minecraft:cold_ocean"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.5,
	.downfall = 0.5,
	.category = mat_biome_category_ocean,
	.effects = {
		.sky_color = 8103167,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_crimson_forest_d = {
	.name = UTL_CSTRTOSTR("minecraft:crimson_forest"),
	.precipitation = mat_precipitation_none,
	.temperature = 2.0,
	.downfall = 0.0,
	.category = mat_biome_category_nether,
	.effects = {
		.sky_color = 7254527,
		.water_fog_color = 329011,
		.fog_color = 3343107,
		.music = {
			.sound = UTL_CSTRTOSTR("minecraft:music.nether.crimson_forest"),
			.max_delay = 24000,
			.min_delay = 12000,
		},
		.ambient_sound = UTL_CSTRTOSTR("minecraft:ambient.crimson_forest.loop"),
		.additions_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.crimson_forest.additions"),
			.tick_chance = 0.0111,
		},
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.crimson_forest.mood"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
	.particle = {
		.probability = 0.025,
		.options = {
			.type = UTL_CSTRTOSTR("minecraft:crimson_spore"),
		},
	},
};
const mat_biome_t mat_biome_dark_forest_d = {
	.name = UTL_CSTRTOSTR("minecraft:dark_forest"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.7,
	.downfall = 0.8,
	.category = mat_biome_category_forest,
	.effects = {
		.sky_color = 7972607,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.grass_color_modifier = mat_grass_color_modifier_dark_forest,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_deep_cold_ocean_d = {
	.name = UTL_CSTRTOSTR("minecraft:deep_cold_ocean"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.5,
	.downfall = 0.5,
	.category = mat_biome_category_ocean,
	.effects = {
		.sky_color = 8103167,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_deep_frozen_ocean_d = {
	.name = UTL_CSTRTOSTR("minecraft:deep_frozen_ocean"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.5,
	.temperature_modifier = mat_temperature_modifier_frozen,
	.downfall = 0.5,
	.category = mat_biome_category_ocean,
	.effects = {
		.sky_color = 8103167,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_deep_lukewarm_ocean_d = {
	.name = UTL_CSTRTOSTR("minecraft:deep_lukewarm_ocean"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.5,
	.downfall = 0.5,
	.category = mat_biome_category_ocean,
	.effects = {
		.sky_color = 8103167,
		.water_fog_color = 267827,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_deep_ocean_d = {
	.name = UTL_CSTRTOSTR("minecraft:deep_ocean"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.5,
	.downfall = 0.5,
	.category = mat_biome_category_ocean,
	.effects = {
		.sky_color = 8103167,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_desert_d = {
	.name = UTL_CSTRTOSTR("minecraft:desert"),
	.precipitation = mat_precipitation_none,
	.temperature = 2.0,
	.downfall = 0.0,
	.category = mat_biome_category_desert,
	.effects = {
		.sky_color = 7254527,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_dripstone_caves_d = {
	.name = UTL_CSTRTOSTR("minecraft:dripstone_caves"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.8,
	.downfall = 0.4,
	.category = mat_biome_category_underground,
	.effects = {
		.sky_color = 7907327,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.music = {
			.sound = UTL_CSTRTOSTR("minecraft:music.overworld.dripstone_caves"),
			.max_delay = 24000,
			.min_delay = 12000,
		},
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_end_barrens_d = {
	.name = UTL_CSTRTOSTR("minecraft:end_barrens"),
	.precipitation = mat_precipitation_none,
	.temperature = 0.5,
	.downfall = 0.5,
	.category = mat_biome_category_the_end,
	.effects = {
		.sky_color = 0,
		.water_fog_color = 329011,
		.fog_color = 10518688,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_end_highlands_d = {
	.name = UTL_CSTRTOSTR("minecraft:end_highlands"),
	.precipitation = mat_precipitation_none,
	.temperature = 0.5,
	.downfall = 0.5,
	.category = mat_biome_category_the_end,
	.effects = {
		.sky_color = 0,
		.water_fog_color = 329011,
		.fog_color = 10518688,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_end_midlands_d = {
	.name = UTL_CSTRTOSTR("minecraft:end_midlands"),
	.precipitation = mat_precipitation_none,
	.temperature = 0.5,
	.downfall = 0.5,
	.category = mat_biome_category_the_end,
	.effects = {
		.sky_color = 0,
		.water_fog_color = 329011,
		.fog_color = 10518688,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_eroded_badlands_d = {
	.name = UTL_CSTRTOSTR("minecraft:eroded_badlands"),
	.precipitation = mat_precipitation_none,
	.temperature = 2.0,
	.downfall = 0.0,
	.category = mat_biome_category_mesa,
	.effects = {
		.sky_color = 7254527,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.has_foliage_color = true,
		.foliage_color = 10387789,
		.has_grass_color = true,
		.grass_color = 9470285,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_flower_forest_d = {
	.name = UTL_CSTRTOSTR("minecraft:flower_forest"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.7,
	.downfall = 0.8,
	.category = mat_biome_category_forest,
	.effects = {
		.sky_color = 7972607,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_forest_d = {
	.name = UTL_CSTRTOSTR("minecraft:forest"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.7,
	.downfall = 0.8,
	.category = mat_biome_category_forest,
	.effects = {
		.sky_color = 7972607,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_frozen_ocean_d = {
	.name = UTL_CSTRTOSTR("minecraft:frozen_ocean"),
	.precipitation = mat_precipitation_snow,
	.temperature = 0.0,
	.temperature_modifier = mat_temperature_modifier_frozen,
	.downfall = 0.5,
	.category = mat_biome_category_ocean,
	.effects = {
		.sky_color = 8364543,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_frozen_peaks_d = {
	.name = UTL_CSTRTOSTR("minecraft:frozen_peaks"),
	.precipitation = mat_precipitation_snow,
	.temperature = -0.7,
	.downfall = 0.9,
	.category = mat_biome_category_mountain,
	.effects = {
		.sky_color = 8756735,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.music = {
			.sound = UTL_CSTRTOSTR("minecraft:music.overworld.frozen_peaks"),
			.max_delay = 24000,
			.min_delay = 12000,
		},
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_frozen_river_d = {
	.name = UTL_CSTRTOSTR("minecraft:frozen_river"),
	.precipitation = mat_precipitation_snow,
	.temperature = 0.0,
	.downfall = 0.5,
	.category = mat_biome_category_river,
	.effects = {
		.sky_color = 8364543,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_grove_d = {
	.name = UTL_CSTRTOSTR("minecraft:grove"),
	.precipitation = mat_precipitation_snow,
	.temperature = -0.2,
	.downfall = 0.8,
	.category = mat_biome_category_forest,
	.effects = {
		.sky_color = 8495359,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.music = {
			.sound = UTL_CSTRTOSTR("minecraft:music.overworld.grove"),
			.max_delay = 24000,
			.min_delay = 12000,
		},
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_ice_spikes_d = {
	.name = UTL_CSTRTOSTR("minecraft:ice_spikes"),
	.precipitation = mat_precipitation_snow,
	.temperature = 0.0,
	.downfall = 0.5,
	.category = mat_biome_category_icy,
	.effects = {
		.sky_color = 8364543,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_jagged_peaks_d = {
	.name = UTL_CSTRTOSTR("minecraft:jagged_peaks"),
	.precipitation = mat_precipitation_snow,
	.temperature = -0.7,
	.downfall = 0.9,
	.category = mat_biome_category_mountain,
	.effects = {
		.sky_color = 8756735,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.music = {
			.sound = UTL_CSTRTOSTR("minecraft:music.overworld.jagged_peaks"),
			.max_delay = 24000,
			.min_delay = 12000,
		},
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_jungle_d = {
	.name = UTL_CSTRTOSTR("minecraft:jungle"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.95,
	.downfall = 0.9,
	.category = mat_biome_category_jungle,
	.effects = {
		.sky_color = 7842047,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_lukewarm_ocean_d = {
	.name = UTL_CSTRTOSTR("minecraft:lukewarm_ocean"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.5,
	.downfall = 0.5,
	.category = mat_biome_category_ocean,
	.effects = {
		.sky_color = 8103167,
		.water_fog_color = 267827,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_lush_caves_d = {
	.name = UTL_CSTRTOSTR("minecraft:lush_caves"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.5,
	.downfall = 0.5,
	.category = mat_biome_category_underground,
	.effects = {
		.sky_color = 8103167,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.music = {
			.sound = UTL_CSTRTOSTR("minecraft:music.overworld.lush_caves"),
			.max_delay = 24000,
			.min_delay = 12000,
		},
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_meadow_d = {
	.name = UTL_CSTRTOSTR("minecraft:meadow"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.5,
	.downfall = 0.8,
	.category = mat_biome_category_mountain,
	.effects = {
		.sky_color = 8103167,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.music = {
			.sound = UTL_CSTRTOSTR("minecraft:music.overworld.meadow"),
			.max_delay = 24000,
			.min_delay = 12000,
		},
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_mushroom_fields_d = {
	.name = UTL_CSTRTOSTR("minecraft:mushroom_fields"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.9,
	.downfall = 1.0,
	.category = mat_biome_category_mushroom,
	.effects = {
		.sky_color = 7842047,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_nether_wastes_d = {
	.name = UTL_CSTRTOSTR("minecraft:nether_wastes"),
	.precipitation = mat_precipitation_none,
	.temperature = 2.0,
	.downfall = 0.0,
	.category = mat_biome_category_nether,
	.effects = {
		.sky_color = 7254527,
		.water_fog_color = 329011,
		.fog_color = 3344392,
		.music = {
			.sound = UTL_CSTRTOSTR("minecraft:music.nether.nether_wastes"),
			.max_delay = 24000,
			.min_delay = 12000,
		},
		.ambient_sound = UTL_CSTRTOSTR("minecraft:ambient.nether_wastes.loop"),
		.additions_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.nether_wastes.additions"),
			.tick_chance = 0.0111,
		},
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.nether_wastes.mood"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_ocean_d = {
	.name = UTL_CSTRTOSTR("minecraft:ocean"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.5,
	.downfall = 0.5,
	.category = mat_biome_category_ocean,
	.effects = {
		.sky_color = 8103167,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_old_growth_birch_forest_d = {
	.name = UTL_CSTRTOSTR("minecraft:old_growth_birch_forest"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.6,
	.downfall = 0.6,
	.category = mat_biome_category_forest,
	.effects = {
		.sky_color = 8037887,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_old_growth_pine_taiga_d = {
	.name = UTL_CSTRTOSTR("minecraft:old_growth_pine_taiga"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.3,
	.downfall = 0.8,
	.category = mat_biome_category_taiga,
	.effects = {
		.sky_color = 8168447,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_old_growth_spruce_taiga_d = {
	.name = UTL_CSTRTOSTR("minecraft:old_growth_spruce_taiga"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.25,
	.downfall = 0.8,
	.category = mat_biome_category_taiga,
	.effects = {
		.sky_color = 8233983,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_plains_d = {
	.name = UTL_CSTRTOSTR("minecraft:plains"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.8,
	.downfall = 0.4,
	.category = mat_biome_category_plains,
	.effects = {
		.sky_color = 7907327,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_river_d = {
	.name = UTL_CSTRTOSTR("minecraft:river"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.5,
	.downfall = 0.5,
	.category = mat_biome_category_river,
	.effects = {
		.sky_color = 8103167,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_savanna_d = {
	.name = UTL_CSTRTOSTR("minecraft:savanna"),
	.precipitation = mat_precipitation_none,
	.temperature = 2.0,
	.downfall = 0.0,
	.category = mat_biome_category_savanna,
	.effects = {
		.sky_color = 7254527,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_savanna_plateau_d = {
	.name = UTL_CSTRTOSTR("minecraft:savanna_plateau"),
	.precipitation = mat_precipitation_none,
	.temperature = 2.0,
	.downfall = 0.0,
	.category = mat_biome_category_savanna,
	.effects = {
		.sky_color = 7254527,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_small_end_islands_d = {
	.name = UTL_CSTRTOSTR("minecraft:small_end_islands"),
	.precipitation = mat_precipitation_none,
	.temperature = 0.5,
	.downfall = 0.5,
	.category = mat_biome_category_the_end,
	.effects = {
		.sky_color = 0,
		.water_fog_color = 329011,
		.fog_color = 10518688,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_snowy_beach_d = {
	.name = UTL_CSTRTOSTR("minecraft:snowy_beach"),
	.precipitation = mat_precipitation_snow,
	.temperature = 0.05,
	.downfall = 0.3,
	.category = mat_biome_category_beach,
	.effects = {
		.sky_color = 8364543,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_snowy_plains_d = {
	.name = UTL_CSTRTOSTR("minecraft:snowy_plains"),
	.precipitation = mat_precipitation_snow,
	.temperature = 0.0,
	.downfall = 0.5,
	.category = mat_biome_category_icy,
	.effects = {
		.sky_color = 8364543,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_snowy_slopes_d = {
	.name = UTL_CSTRTOSTR("minecraft:snowy_slopes"),
	.precipitation = mat_precipitation_snow,
	.temperature = -0.3,
	.downfall = 0.9,
	.category = mat_biome_category_mountain,
	.effects = {
		.sky_color = 8560639,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.music = {
			.sound = UTL_CSTRTOSTR("minecraft:music.overworld.snowy_slopes"),
			.max_delay = 24000,
			.min_delay = 12000,
		},
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_snowy_taiga_d = {
	.name = UTL_CSTRTOSTR("minecraft:snowy_taiga"),
	.precipitation = mat_precipitation_snow,
	.temperature = -0.5,
	.downfall = 0.4,
	.category = mat_biome_category_taiga,
	.effects = {
		.sky_color = 8625919,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_soul_sand_valley_d = {
	.name = UTL_CSTRTOSTR("minecraft:soul_sand_valley"),
	.precipitation = mat_precipitation_none,
	.temperature = 2.0,
	.downfall = 0.0,
	.category = mat_biome_category_nether,
	.effects = {
		.sky_color = 7254527,
		.water_fog_color = 329011,
		.fog_color = 1787717,
		.music = {
			.sound = UTL_CSTRTOSTR("minecraft:music.nether.soul_sand_valley"),
			.max_delay = 24000,
			.min_delay = 12000,
		},
		.ambient_sound = UTL_CSTRTOSTR("minecraft:ambient.soul_sand_valley.loop"),
		.additions_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.soul_sand_valley.additions"),
			.tick_chance = 0.0111,
		},
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.soul_sand_valley.mood"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
	.particle = {
		.probability = 0.00625,
		.options = {
			.type = UTL_CSTRTOSTR("minecraft:ash"),
		},
	},
};
const mat_biome_t mat_biome_sparse_jungle_d = {
	.name = UTL_CSTRTOSTR("minecraft:sparse_jungle"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.95,
	.downfall = 0.8,
	.category = mat_biome_category_jungle,
	.effects = {
		.sky_color = 7842047,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_stony_peaks_d = {
	.name = UTL_CSTRTOSTR("minecraft:stony_peaks"),
	.precipitation = mat_precipitation_rain,
	.temperature = 1.0,
	.downfall = 0.3,
	.category = mat_biome_category_mountain,
	.effects = {
		.sky_color = 7776511,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.music = {
			.sound = UTL_CSTRTOSTR("minecraft:music.overworld.stony_peaks"),
			.max_delay = 24000,
			.min_delay = 12000,
		},
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_stony_shore_d = {
	.name = UTL_CSTRTOSTR("minecraft:stony_shore"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.2,
	.downfall = 0.3,
	.category = mat_biome_category_beach,
	.effects = {
		.sky_color = 8233727,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_sunflower_plains_d = {
	.name = UTL_CSTRTOSTR("minecraft:sunflower_plains"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.8,
	.downfall = 0.4,
	.category = mat_biome_category_plains,
	.effects = {
		.sky_color = 7907327,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_swamp_d = {
	.name = UTL_CSTRTOSTR("minecraft:swamp"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.8,
	.downfall = 0.9,
	.category = mat_biome_category_swamp,
	.effects = {
		.sky_color = 7907327,
		.water_fog_color = 2302743,
		.fog_color = 12638463,
		.has_foliage_color = true,
		.foliage_color = 6975545,
		.grass_color_modifier = mat_grass_color_modifier_swamp,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_taiga_d = {
	.name = UTL_CSTRTOSTR("minecraft:taiga"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.25,
	.downfall = 0.8,
	.category = mat_biome_category_taiga,
	.effects = {
		.sky_color = 8233983,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_the_end_d = {
	.name = UTL_CSTRTOSTR("minecraft:the_end"),
	.precipitation = mat_precipitation_none,
	.temperature = 0.5,
	.downfall = 0.5,
	.category = mat_biome_category_the_end,
	.effects = {
		.sky_color = 0,
		.water_fog_color = 329011,
		.fog_color = 10518688,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_the_void_d = {
	.name = UTL_CSTRTOSTR("minecraft:the_void"),
	.precipitation = mat_precipitation_none,
	.temperature = 0.5,
	.downfall = 0.5,
	.category = mat_biome_category_none,
	.effects = {
		.sky_color = 8103167,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_warm_ocean_d = {
	.name = UTL_CSTRTOSTR("minecraft:warm_ocean"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.5,
	.downfall = 0.5,
	.category = mat_biome_category_ocean,
	.effects = {
		.sky_color = 8103167,
		.water_fog_color = 270131,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_warped_forest_d = {
	.name = UTL_CSTRTOSTR("minecraft:warped_forest"),
	.precipitation = mat_precipitation_none,
	.temperature = 2.0,
	.downfall = 0.0,
	.category = mat_biome_category_nether,
	.effects = {
		.sky_color = 7254527,
		.water_fog_color = 329011,
		.fog_color = 1705242,
		.music = {
			.sound = UTL_CSTRTOSTR("minecraft:music.nether.warped_forest"),
			.max_delay = 24000,
			.min_delay = 12000,
		},
		.ambient_sound = UTL_CSTRTOSTR("minecraft:ambient.warped_forest.loop"),
		.additions_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.warped_forest.additions"),
			.tick_chance = 0.0111,
		},
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.warped_forest.mood"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
	.particle = {
		.probability = 0.01428,
		.options = {
			.type = UTL_CSTRTOSTR("minecraft:warped_spore"),
		},
	},
};
const mat_biome_t mat_biome_windswept_forest_d = {
	.name = UTL_CSTRTOSTR("minecraft:windswept_forest"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.2,
	.downfall = 0.3,
	.category = mat_biome_category_extreme_hills,
	.effects = {
		.sky_color = 8233727,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_windswept_gravelly_hills_d = {
	.name = UTL_CSTRTOSTR("minecraft:windswept_gravelly_hills"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.2,
	.downfall = 0.3,
	.category = mat_biome_category_extreme_hills,
	.effects = {
		.sky_color = 8233727,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_windswept_hills_d = {
	.name = UTL_CSTRTOSTR("minecraft:windswept_hills"),
	.precipitation = mat_precipitation_rain,
	.temperature = 0.2,
	.downfall = 0.3,
	.category = mat_biome_category_extreme_hills,
	.effects = {
		.sky_color = 8233727,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_windswept_savanna_d = {
	.name = UTL_CSTRTOSTR("minecraft:windswept_savanna"),
	.precipitation = mat_precipitation_none,
	.temperature = 2.0,
	.downfall = 0.0,
	.category = mat_biome_category_savanna,
	.effects = {
		.sky_color = 7254527,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t mat_biome_wooded_badlands_d = {
	.name = UTL_CSTRTOSTR("minecraft:wooded_badlands"),
	.precipitation = mat_precipitation_none,
	.temperature = 2.0,
	.downfall = 0.0,
	.category = mat_biome_category_mesa,
	.effects = {
		.sky_color = 7254527,
		.water_fog_color = 329011,
		.fog_color = 12638463,
		.has_foliage_color = true,
		.foliage_color = 10387789,
		.has_grass_color = true,
		.grass_color = 9470285,
		.mood_sound = {
			.sound = UTL_CSTRTOSTR("minecraft:ambient.cave"),
			.offset = 2.0,
			.tick_delay = 6000,
			.block_search_extent = 8,
		},
	},
};
const mat_biome_t* mat_biomes[] = {
	&mat_biome_badlands_d,
	&mat_biome_bamboo_jungle_d,
	&mat_biome_basalt_deltas_d,
	&mat_biome_beach_d,
	&mat_biome_birch_forest_d,
	&mat_biome_cold_ocean_d,
	&mat_biome_crimson_forest_d,
	&mat_biome_dark_forest_d,
	&mat_biome_deep_cold_ocean_d,
	&mat_biome_deep_frozen_ocean_d,
	&mat_biome_deep_lukewarm_ocean_d,
	&mat_biome_deep_ocean_d,
	&mat_biome_desert_d,
	&mat_biome_dripstone_caves_d,
	&mat_biome_end_barrens_d,
	&mat_biome_end_highlands_d,
	&mat_biome_end_midlands_d,
	&mat_biome_eroded_badlands_d,
	&mat_biome_flower_forest_d,
	&mat_biome_forest_d,
	&mat_biome_frozen_ocean_d,
	&mat_biome_frozen_peaks_d,
	&mat_biome_frozen_river_d,
	&mat_biome_grove_d,
	&mat_biome_ice_spikes_d,
	&mat_biome_jagged_peaks_d,
	&mat_biome_jungle_d,
	&mat_biome_lukewarm_ocean_d,
	&mat_biome_lush_caves_d,
	&mat_biome_meadow_d,
	&mat_biome_mushroom_fields_d,
	&mat_biome_nether_wastes_d,
	&mat_biome_ocean_d,
	&mat_biome_old_growth_birch_forest_d,
	&mat_biome_old_growth_pine_taiga_d,
	&mat_biome_old_growth_spruce_taiga_d,
	&mat_biome_plains_d,
	&mat_biome_river_d,
	&mat_biome_savanna_d,
	&mat_biome_savanna_plateau_d,
	&mat_biome_small_end_islands_d,
	&mat_biome_snowy_beach_d,
	&mat_biome_snowy_plains_d,
	&mat_biome_snowy_slopes_d,
	&mat_biome_snowy_taiga_d,
	&mat_biome_soul_sand_valley_d,
	&mat_biome_sparse_jungle_d,
	&mat_biome_stony_peaks_d,
	&mat_biome_stony_shore_d,
	&mat_biome_sunflower_plains_d,
	&mat_biome_swamp_d,
	&mat_biome_taiga_d,
	&mat_biome_the_end_d,
	&mat_biome_the_void_d,
	&mat_biome_warm_ocean_d,
	&mat_biome_warped_forest_d,
	&mat_biome_windswept_forest_d,
	&mat_biome_windswept_gravelly_hills_d,
	&mat_biome_windswept_hills_d,
	&mat_biome_windswept_savanna_d,
	&mat_biome_wooded_badlands_d,
};
