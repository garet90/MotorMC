#include "material.h"

const mat_dimension_t mat_dimension_overworld_d = {
	.name = "minecraft:overworld",
	.name_length = 19,
	.effects = "minecraft:overworld",
	.effects_length = 19,
	.ambient_light = 0,
	.coordinate_scale = 1,
	.fixed_time = 0xFFFF,
	.min_y = 0,
	.height = 256,
	.logical_height = 256,
	.properties = {
		utl_arraybit(mat_dimension_natural) | utl_arraybit(mat_dimension_bed) | utl_arraybit(mat_dimension_raids) | utl_arraybit(mat_dimension_skylight)
	}
};
const mat_dimension_t mat_dimension_nether_d = {
	.name = "minecraft:the_nether",
	.name_length = 20,
	.effects = "minecraft:the_nether",
	.effects_length = 20,
	.ambient_light = 0.1,
	.coordinate_scale = 8.0,
	.fixed_time = 18000,
	.min_y = 0,
	.height = 256,
	.logical_height = 128,
	.properties = {
		utl_arraybit(mat_dimension_ultrawarm) | utl_arraybit(mat_dimension_piglin_safe) | utl_arraybit(mat_dimension_respawn_anchor) | utl_arraybit(mat_dimension_ceiling)
	}
};
const mat_dimension_t mat_dimension_end_d = {
	.name = "minecraft:the_end",
	.name_length = 17,
	.effects = "minecraft:the_end",
	.effects_length = 17,
	.ambient_light = 0,
	.coordinate_scale = 1,
	.fixed_time = 6000,
	.min_y = 0,
	.height = 256,
	.logical_height = 256,
	.properties = {
		utl_arraybit(mat_dimension_raids)
	}
};

const mat_dimension_t* mat_dimensions[] = {
	&mat_dimension_overworld_d,
	&mat_dimension_nether_d,
	&mat_dimension_end_d
};