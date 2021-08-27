#pragma once
#include "../../main.h"
#include "../../util/vector.h"
#include "../json/mjson.h"

typedef enum {

	cht_black = 0x0,
	cht_dark_blue = 0x1,
	cht_dark_green = 0x2,
	cht_dark_cyan = 0x3,
	cht_dark_red = 0x4,
	cht_purple = 0x5,
	cht_gold = 0x6,
	cht_gray = 0x7,
	cht_dark_gray = 0x8,
	cht_blue = 0x9,
	cht_bright_green = 0xA,
	cht_cyan = 0xB,
	cht_red = 0xC,
	cht_pink = 0xD,
	cht_yellow = 0xE,
	cht_white = 0xF,

	cht_no_color = 0x10

} cht_color_t;

typedef enum {
	cht_open_url,
	cht_run_command,
	cht_suggest_command,
	cht_change_page,
	cht_copy_to_clipboard
} cht_click_action_t;

typedef enum {
	cht_show_text,
	cht_show_item,
	cht_show_entity
} cht_hover_action_t;

typedef struct {

	string_t text;

	bool_t bold : 2;
	bool_t italic : 2;
	bool_t underlined : 2;
	bool_t strikethrough : 2;
	bool_t obfuscated : 2;

	bool_t heap : 1;
	bool_t text_heap : 1;
	bool_t insertion_heap : 1;
	bool_t click_event_heap : 1;
	bool_t hover_event_heap : 1;

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

} cht_component_t;

static /*in-plugin*/ const cht_component_t cht_new = {
	.bold = UNSET,
	.italic = UNSET,
	.underlined = UNSET,
	.strikethrough = UNSET,
	.obfuscated = UNSET,
	.heap = false,
	.color = cht_no_color,
	.extra = {
		.bytes_per_element = sizeof(cht_component_t*)
	}
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

extern void cht_set_text(cht_component_t*, const string_t);
extern string_t cht_get_text(cht_component_t*);

extern void cht_set_bold(cht_component_t*, bool_t);
extern void cht_unset_bold(cht_component_t*);
extern bool_t cht_get_bold(cht_component_t*);

extern void cht_set_italic(cht_component_t*, bool_t);
extern void cht_unset_italic(cht_component_t*);
extern bool_t cht_get_italic(cht_component_t*);

extern void cht_set_underlined(cht_component_t*, bool_t);
extern void cht_unset_underlined(cht_component_t*);
extern bool_t cht_get_underlined(cht_component_t*);

extern void cht_set_strikethrough(cht_component_t*, bool_t);
extern void cht_unset_strikethrough(cht_component_t*);
extern bool_t cht_get_strikethrough(cht_component_t*);

extern void cht_set_obfuscated(cht_component_t*, bool_t);
extern void cht_unset_obfuscated(cht_component_t*);
extern bool_t cht_get_obfuscated(cht_component_t*);

extern void cht_set_color(cht_component_t*, cht_color_t);
extern void cht_unset_color(cht_component_t*);
extern cht_color_t cht_get_color(cht_component_t*);