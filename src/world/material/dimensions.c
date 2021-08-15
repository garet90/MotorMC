#include "material.h"

const mat_dimension_t mat_dimension_overworld_d = {
	.name = "minecraft:overworld",
	.name_length = 19,
	.effects = "minecraft:overworld",
	.effects_length = 19,
	.ambient_light = 0,
	.coordinate_scale = 1,
	.has_fixed_time = false,
	.min_y = 0,
	.height = 256,
	.logical_height = 256,
	.natural = true,
	.bed_works = true,
	.has_raids = true,
	.has_skylight = true
};
const mat_dimension_t mat_dimension_nether_d = {
	.name = "minecraft:the_nether",
	.name_length = 20,
	.effects = "minecraft:the_nether",
	.effects_length = 20,
	.ambient_light = 0.1,
	.coordinate_scale = 8.0,
	.has_fixed_time = true,
	.fixed_time = 18000,
	.min_y = 0,
	.height = 256,
	.logical_height = 128,
	.ultrawarm = true,
	.piglin_safe = true,
	.respawn_anchor_works = true,
	.has_ceiling = true
};
const mat_dimension_t mat_dimension_end_d = {
	.name = "minecraft:the_end",
	.name_length = 17,
	.effects = "minecraft:the_end",
	.effects_length = 17,
	.ambient_light = 0,
	.coordinate_scale = 1,
	.has_fixed_time = true,
	.fixed_time = 6000,
	.min_y = 0,
	.height = 256,
	.logical_height = 256,
	.has_raids = true
};

const mat_dimension_t* mat_dimensions[] = {
	&mat_dimension_overworld_d,
	&mat_dimension_nether_d,
	&mat_dimension_end_d
};