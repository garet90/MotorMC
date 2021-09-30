#include "tags.h"
#include "../../../util/str_util.h"

const mat_tag_t mat_game_event_tag_vibrations_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:vibrations"),

);
const mat_tag_t mat_game_event_tag_ignore_vibrations_sneaking_d = MAT_TAG_INITIALIZER(
	UTL_CSTRTOSTR("minecraft:ignore_vibrations_sneaking"),

);

const mat_tag_t* mat_game_event_tags[] = {

	&mat_game_event_tag_vibrations_d,
	&mat_game_event_tag_ignore_vibrations_sneaking_d,

};