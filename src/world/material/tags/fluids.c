#include "tags.h"
#include "../blocks.h"
#include "../../../util/str_util.h"

const mat_tag_t mat_fluid_tag_water_d = {
	.identifier = UTL_CSTRTOSTR("minecraft:water"),
	.count = 1,
	.entries = {
		mat_block_water
	}
};
const mat_tag_t mat_fluid_tag_lava_d = {
	.identifier = UTL_CSTRTOSTR("minecraft:lava"),
	.count = 1,
	.entries = {
		mat_block_lava
	}
};

const mat_tag_t* mat_fluid_tags[] = {
	&mat_fluid_tag_water_d,
	&mat_fluid_tag_lava_d,
};