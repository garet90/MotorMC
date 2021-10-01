#include "tags.h"
#include "../blocks.h"
#include "../../../util/str_util.h"

#define MAT_FLUID_TAG_WATER \
	mat_fluid_water,\
	mat_fluid_flowing_water

const mat_tag_t mat_fluid_tag_water_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:water"),
	MAT_FLUID_TAG_WATER
);

#define MAT_FLUID_TAG_LAVA \
	mat_fluid_lava,\
	mat_fluid_flowing_lava

const mat_tag_t mat_fluid_tag_lava_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:lava"),
	MAT_FLUID_TAG_LAVA
);

const mat_tag_t* mat_fluid_tags[] = {
	&mat_fluid_tag_water_d,
	&mat_fluid_tag_lava_d,
};