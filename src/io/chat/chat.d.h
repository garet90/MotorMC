#pragma once

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

typedef struct cht_component cht_component_t;