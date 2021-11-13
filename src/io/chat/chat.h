#pragma once

#include "chat.d.h"

#include "../../main.h"
#include "../../util/vector.h"
#include "../json/mjson.h"

struct cht_component {

	string_t text;

	uint8_t bold : 2;
	uint8_t italic : 2;
	uint8_t underlined : 2;
	uint8_t strikethrough : 2;
	uint8_t obfuscated : 2;

	bool heap : 1;
	bool text_heap : 1;
	bool insertion_heap : 1;
	bool click_event_heap : 1;
	bool hover_event_heap : 1;

	cht_color_t color;

	string_t insertion;

	struct {
		cht_click_action_t action : 3;
		string_t value;
	} click_event;

	struct {
		cht_hover_action_t action : 3;
		string_t value;
	} hover_event;

	utl_vector_t extra;

};

static /*in-plugin*/ const cht_component_t cht_new = {
	.bold = UNSET,
	.italic = UNSET,
	.underlined = UNSET,
	.strikethrough = UNSET,
	.obfuscated = UNSET,
	.heap = false,
	.color = cht_no_color,
	.extra = UTL_VECTOR_INITIALIZER(cht_component_t*)
};

extern cht_component_t* cht_alloc();
extern cht_component_t* cht_from_json(mjson_val*);
extern cht_component_t* cht_from_string(const char*, size_t);

static inline void cht_add_extra(cht_component_t* base, const cht_component_t* extra) {
	utl_vector_push(&base->extra, &extra);
}

extern void cht_jsonify(mjson_doc*, mjson_val*, const cht_component_t*);
extern size_t cht_write(const cht_component_t*, char*);

extern size_t cht_write_old(const cht_component_t*, char*);

extern void cht_free(cht_component_t*);

extern size_t cht_server_list_ping(char*);

// API functions

static inline void cht_set_text(cht_component_t* component, string_t text) {
	component->text = text;
}

static inline string_t cht_get_text(cht_component_t* component) {
	return component->text;
}

static inline void cht_set_bold(cht_component_t* component, bool bold) {
	component->bold = bold;
}

static inline void cht_unset_bold(cht_component_t* component) {
	component->bold = UNSET;
}

static inline bool cht_get_bold(cht_component_t* component) {
	return component->bold;
}

static inline void cht_set_italic(cht_component_t* component, bool italic) {
	component->italic = italic;
}

static inline void cht_unset_italic(cht_component_t* component) {
	component->italic = UNSET;
}

static inline bool cht_get_italic(cht_component_t* component) {
	return component->italic;
}

static inline void cht_set_underlined(cht_component_t* component, bool underlined) {
	component->underlined = underlined;
}

static inline void cht_unset_underlined(cht_component_t* component) {
	component->underlined = UNSET;
}

static inline bool cht_get_underlined(cht_component_t* component) {
	return component->underlined;
}

static inline void cht_set_strikethrough(cht_component_t* component, bool strikethrough) {
	component->strikethrough = strikethrough;
}

static inline void cht_unset_strikethrough(cht_component_t* component) {
	component->strikethrough = UNSET;
}

static inline bool cht_get_strikethrough(cht_component_t* component) {
	return component->strikethrough;
}

static inline void cht_set_obfuscated(cht_component_t* component, bool obfuscated) {
	component->obfuscated = obfuscated;
}

static inline void cht_unset_obfuscated(cht_component_t* component) {
	component->obfuscated = UNSET;
}

static inline bool cht_get_obfuscated(cht_component_t* component) {
	return component->obfuscated;
}

static inline void cht_set_color(cht_component_t* component, cht_color_t color) {
	component->color = color;
}

static inline void cht_unset_color(cht_component_t* component) {
	component->color = cht_no_color;
}

static inline cht_color_t cht_get_color(cht_component_t* component) {
	return component->color;
}