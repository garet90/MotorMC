#pragma once
#include "../../main.h"
#include "../../util/bitset.h"
#include "../../util/vector.h"
#include <yyjson.h>

typedef enum {

	CHT_BLACK = 0x0,
	CHT_DARK_BLUE = 0x1,
	CHT_DARK_GREEN = 0x2,
	CHT_DARK_CYAN = 0x3,
	CHT_DARK_RED = 0x4,
	CHT_PURPLE = 0x5,
	CHT_GOLD = 0x6,
	CHT_GRAY = 0x7,
	CHT_DARK_GRAY = 0x8,
	CHT_BLUE = 0x9,
	CHT_BRIGHT_GREEN = 0xA,
	CHT_CYAN = 0xB,
	CHT_RED = 0xC,
	CHT_PINK = 0xD,
	CHT_YELLOW = 0xE,
	CHT_WHITE = 0xF,

	CHT_NOCOLOR = -0x01

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

	utl_vector_t* extra;

} cht_component_t;

static /*in-plugin*/ const cht_component_t cht_new = {
		.color = CHT_NOCOLOR
};

extern cht_component_t* cht_alloc();
extern cht_component_t* cht_fromJson(yyjson_val*);
extern cht_component_t* cht_fromString(const char*, size_t);

extern void cht_addExtra(cht_component_t*, const cht_component_t*);

extern void cht_jsonify(yyjson_mut_doc*, yyjson_mut_val*, const cht_component_t*);
extern size_t cht_write(const cht_component_t*, char*);

extern void cht_free(cht_component_t*);

extern size_t cht_serverListPing(char*);
