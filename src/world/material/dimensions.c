#include "material.h"
#include "../../util/str_util.h"

const mat_dimension_t mat_dimension_overworld_d = {
	.name = UTL_CSTRTOSTR("minecraft:overworld"),
	.effects = UTL_CSTRTOSTR("minecraft:overworld"),
	.ambient_light = 0,
	.coordinate_scale = 1,
	.has_fixed_time = false,
	.min_y = -64,
	.height = 384,
	.logical_height = 384,
	.natural = true,
	.bed_works = true,
	.has_raids = true,
	.has_skylight = true
};
const mat_dimension_t mat_dimension_nether_d = {
	.name = UTL_CSTRTOSTR("minecraft:the_nether"),
	.effects = UTL_CSTRTOSTR("minecraft:the_nether"),
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
	.name = UTL_CSTRTOSTR("minecraft:the_end"),
	.effects = UTL_CSTRTOSTR("minecraft:the_end"),
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