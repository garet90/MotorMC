#pragma once
#include <stdint.h>
#include <stddef.h>
#if defined(__MINGW32__) || defined(__MINGW64__) || defined(__CYGWIN__) || defined(_WIN32) || defined(_WIN64)
#define __WINDOWS__
#endif
#define __MC_VER__ "1.17.1"
#define __MC_PRO__ 756
#define __MOTOR_VER__ "MotorMC InDev 0.0.1"
#define __MOTOR_UNSAFE__ 1
typedef enum bool {
    false = 0x00,
    true = 0x01
} bool_t;
typedef float float32_t;
typedef double float64_t;
typedef uint8_t byte_t;
#define utl_bitset(length, name) byte_t name [((length) >> 3) + 1]
#define utl_arraybit(x) (1 << (x & 7))
typedef struct {
	byte_t* array;
	size_t size;
	size_t capacity;
	size_t bytes_per_element; // bytes per element
} utl_vector_t;
#define utl_vectorGetAs(t, v, i) *((t*) utl_vectorGet(v, i))
#define utl_vectorShiftAs(t, v) *((t*) utl_vectorShift(v))
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
typedef enum {
	cmd_not_op = 0,
	cmd_op_1 = 1,
	cmd_op_2 = 2,
	cmd_op_3 = 3,
	cmd_op_4 = 4
} cmd_op_level_t;
typedef struct cmd_sender cmd_sender_t;
struct cmd_sender {
	utl_vector_t permissions;
	char* name;
	cmd_op_level_t op;
};
typedef struct {
	const char* label;
	const char* description;
	const char* usage;
	const char* permission;
	const char* permissionMessage;
	bool_t (*const handler) (char*, cmd_sender_t*);
	const size_t alias_count;
	const char* aliases[];
} cmd_command_t;
#ifdef __WINDOWS__
#define EXPORT __declspec(dllexport)
#define IMPORT __declspec(dllimport)
#elif __GNUC__
#define EXPORT __attribute__((visibility("default")))
#define IMPORT
#else
#define EXPORT
#define IMPORT
#endif
#define PLG_CURRENT_INTERFACE 0
typedef struct {
	uint32_t interface_version;
	struct {
		void (*info) (const char*, ...);
		void (*warn) (const char*, ...);
		void (*error) (const char*, ...);
	} logger;
	struct {
		void (*add) (const cmd_command_t*);
		void (*message) (cmd_sender_t*, const cht_component_t*);
	} commands;
	struct {
		cht_component_t* (*alloc) ();
		void (*addExtra) (cht_component_t*, const cht_component_t*);
		void (*free) (cht_component_t*);
	} chat;
} plg_interface_t;
typedef enum {
	plg_postworld = 0,
	plg_startup
} plg_startup_t;
typedef struct {
	const char* name;
	const char* description;
	const char* authors;
	const char* version;
	const char* website;
	const plg_startup_t load;
} plg_plugin_t;
#define registerPlugin(plugin) EXPORT const plg_plugin_t* getPlugin(const plg_interface_t* interface) {\
			if (interface->interface_version != PLG_CURRENT_INTERFACE) {\
				return NULL;\
			}\
			motor = interface;\
			return plugin;\
		}
static const plg_interface_t* motor;
