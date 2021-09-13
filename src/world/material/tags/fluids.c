#include "tags.h"
#include "../blocks.h"
#include "../../../util/str_util.h"

const mat_tag_t mat_fluid_tag_water_d = {
	.identifier = UTL_CSTRTOSTR("minecraft:water"),
	.count = 2,
	.entries = {
		mat_fluid_water,
		mat_fluid_flowing_water
	}
};
const mat_tag_t mat_fluid_tag_lava_d = {
	.identifier = UTL_CSTRTOSTR("minecraft:lava"),
	.count = 2,
	.entries = {
		mat_fluid_lava,
		mat_fluid_flowing_lava
	}
};

const mat_tag_t* mat_fluid_tags[] = {
	&mat_fluid_tag_water_d,
	&mat_fluid_tag_lava_d,
};