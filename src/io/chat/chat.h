#pragma once
#include "../../main.h"
#include "../../util/bitset.h"
#include "../../util/vector.h"
#include <yyjson.h>

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

	cht_nocolor = -0x01

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

typedef enum {
	cht_bold_set = 0,
	cht_bold,
	cht_italic_set,
	cht_italic,
	cht_underlined_set,
	cht_underlined,
	cht_strikethrough_set,
	cht_strikethrough,
	cht_obfuscated_set,
	cht_obfuscated,

	cht_heap,

	cht_format_max
} cht_fields_t;

typedef struct {

	char* text;

	// format bitset
	utl_bitset(cht_format_max, format);

	cht_color_t color;

	char* insertion;

	struct {
		cht_click_action_t action;
		char* value;
	} click_event;

	struct {
		cht_hover_action_t action;
		char* value;
	} hover_event;

	utl_vector_t extra;

} cht_component_t;

static /*in-plugin*/ const cht_component_t cht_new = {
	.color = cht_nocolor,
	.extra = {
		.bytes_per_element = sizeof(cht_component_t*)
	}
};

extern cht_component_t* cht_alloc();
extern cht_component_t* cht_from_json(yyjson_val*);
extern cht_component_t* cht_from_string(const char*, size_t);

static inline void cht_add_extra(cht_component_t* base, const cht_component_t* extra) {
	utl_vector_push(&base->extra, &extra);
}

extern void cht_jsonify(yyjson_mut_doc*, yyjson_mut_val*, const cht_component_t*);
extern size_t cht_write(const cht_component_t*, char*);

extern void cht_free(cht_component_t*);

extern size_t cht_server_list_ping(char*);
