#include "tags.h"
#include "../../../util/str_util.h"

const mat_tag_t mat_game_event_tag_vibrations_d = {
	.identifier = UTL_CSTRTOSTR("minecraft:vibrations"),
	.count = 0,
	.entries = {

	}
};
const mat_tag_t mat_game_event_tag_ignore_vibrations_sneaking_d = {
	.identifier = UTL_CSTRTOSTR("minecraft:ignore_vibrations_sneaking"),
	.count = 0,
	.entries = {

	}
};

const mat_tag_t* mat_game_event_tags[] = {

	&mat_game_event_tag_vibrations_d,
	&mat_game_event_tag_ignore_vibrations_sneaking_d,

};