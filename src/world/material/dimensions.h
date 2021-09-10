#pragma once
#include "../../main.h"

/*
	DIMENSIONS
*/

typedef enum {

	mat_dimension_overworld,
	mat_dimension_nether,
	mat_dimension_end,

	mat_dimension_count

} mat_dimension_type_t;

typedef struct {

	const string_t name;
	const string_t effects;
	float32_t ambient_light;
	float32_t coordinate_scale;
	bool has_fixed_time : 1;
	uint16_t fixed_time : 15;
	int16_t min_y;
	int16_t height;
	int16_t logical_height;
	bool piglin_safe : 1;
	bool natural : 1;
	bool respawn_anchor_works : 1;
	bool has_skylight : 1;
	bool bed_works : 1;
	bool has_raids : 1;
	bool ultrawarm : 1;
	bool has_ceiling : 1;

} mat_dimension_t;

extern const mat_dimension_t* mat_dimensions[];

static inline const mat_dimension_t* mat_get_dimension_by_type(mat_dimension_type_t type) {
	return mat_dimensions[type];
}

static inline uint16_t mat_get_chunk_height(mat_dimension_type_t type) {
	const mat_dimension_t* dimension = mat_get_dimension_by_type(type);
	return (dimension->height - dimension->min_y) >> 4;
}