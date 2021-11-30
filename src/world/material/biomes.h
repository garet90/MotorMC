#pragma once
#include "../../main.h"

/*
	BIOMES
*/

typedef enum {

	mat_biome_badlands,
	mat_biome_bamboo_jungle,
	mat_biome_basalt_deltas,
	mat_biome_beach,
	mat_biome_birch_forest,
	mat_biome_cold_ocean,
	mat_biome_crimson_forest,
	mat_biome_dark_forest,
	mat_biome_deep_cold_ocean,
	mat_biome_deep_frozen_ocean,
	mat_biome_deep_lukewarm_ocean,
	mat_biome_deep_ocean,
	mat_biome_desert,
	mat_biome_dripstone_caves,
	mat_biome_end_barrens,
	mat_biome_end_highlands,
	mat_biome_end_midlands,
	mat_biome_eroded_badlands,
	mat_biome_flower_forest,
	mat_biome_forest,
	mat_biome_frozen_ocean,
	mat_biome_frozen_peaks,
	mat_biome_frozen_river,
	mat_biome_grove,
	mat_biome_ice_spikes,
	mat_biome_jagged_peaks,
	mat_biome_jungle,
	mat_biome_lukewarm_ocean,
	mat_biome_lush_caves,
	mat_biome_meadow,
	mat_biome_mushroom_fields,
	mat_biome_nether_wastes,
	mat_biome_ocean,
	mat_biome_old_growth_birch_forest,
	mat_biome_old_growth_pine_taiga,
	mat_biome_old_growth_spruce_taiga,
	mat_biome_plains,
	mat_biome_river,
	mat_biome_savanna,
	mat_biome_savanna_plateau,
	mat_biome_small_end_islands,
	mat_biome_snowy_beach,
	mat_biome_snowy_plains,
	mat_biome_snowy_slopes,
	mat_biome_snowy_taiga,
	mat_biome_soul_sand_valley,
	mat_biome_sparse_jungle,
	mat_biome_stony_peaks,
	mat_biome_stony_shore,
	mat_biome_sunflower_plains,
	mat_biome_swamp,
	mat_biome_taiga,
	mat_biome_the_end,
	mat_biome_the_void,
	mat_biome_warm_ocean,
	mat_biome_warped_forest,
	mat_biome_windswept_forest,
	mat_biome_windswept_gravelly_hills,
	mat_biome_windswept_hills,
	mat_biome_windswept_savanna,
	mat_biome_wooded_badlands,

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
	mat_biome_category_mountain,

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
	float32_t temperature;
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
		bool has_foliage_color : 1;
		uint32_t grass_color : 24;
		bool has_grass_color: 1;
		mat_grass_color_modifier_t grass_color_modifier : 2;

		struct {

			const string_t sound;
			uint32_t max_delay;
			uint32_t min_delay;
			bool replace_current_music : 1;
		
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