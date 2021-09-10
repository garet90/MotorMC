#pragma once
#include "../../main.h"
#include "dimensions.h"

/*
	CODEC
*/

typedef struct {

	size_t size;
	byte_t bytes[];

} mat_codec_t;

extern const mat_codec_t* mat_get_codec();

extern const mat_codec_t* mat_get_dimension_codec(mat_dimension_type_t dimension);