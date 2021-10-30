#pragma once
#include "../main.h"
#include "../io/logger/logger.h"
#include "../io/commands/commands.h"
#include "../util/vector.h"

#ifdef __WINDOWS__
#include <windows.h>
#else
#include <dlfcn.h>
#endif

// PLUGINS

typedef enum {

	plg_postworld = 0,
	plg_startup

} plg_startup_t;

typedef struct {

	const string_t name;
	const string_t description;
	const string_t authors;
	const string_t version;
	const string_t website;
	const plg_startup_t load;

} plg_plugin_t;

// API (Server side)

#define PLG_CURRENT_INTERFACE 0

typedef struct {
	
	uint32_t interface_version;

	struct {

		void (*const info) (const char*, ...);
		void (*const warn) (const char*, ...);
		void (*const error) (const char*, ...);

	} logger;

	struct {

		void (*const add) (const cmd_command_t*);
		void (*const message) (const cmd_sender_t*, const cht_component_t*);
		uint8_t (*const get_op_level) (const cmd_sender_t*);
		cmd_sender_type_t (*const get_sender_type) (const cmd_sender_t*);
		ltg_client_t* (*const get_player) (const cmd_sender_t*);

	} commands;

	struct {

		string_t (*const get_username) (const ltg_client_t*);
		const byte_t* (*const get_uuid) (const ltg_client_t*);
		uint16_t (*const get_protocol) (const ltg_client_t*);
		uint8_t (*const get_render_distance) (const ltg_client_t*);
		int64_t (*const get_ping) (const ltg_client_t*);
		string_t (*const get_textures) (const ltg_client_t*);
		ltg_locale_t (*const get_locale) (const ltg_client_t*);
		ent_player_t* (*const get_entity) (const ltg_client_t*);
		void (*const kick) (const ltg_client_t*, const cht_component_t*);
		void (*const ban) (const ltg_client_t*, const cht_component_t*);
		void (*const pardon) (const ltg_client_t*);

	} player;

	struct {

		cht_component_t* (*alloc) ();

		void (*const set_text) (cht_component_t*, const string_t);
		string_t (*const get_text) (cht_component_t* component);

		void (*const set_bold) (cht_component_t* component, bool bold);
		void (*const unset_bold) (cht_component_t* component);
		bool (*const get_bold) (cht_component_t* component);

		void (*const set_italic) (cht_component_t* component, bool italic);
		void (*const unset_italic) (cht_component_t* component);
		bool (*const get_italic) (cht_component_t* component);

		void (*const set_underlined) (cht_component_t* component, bool underlined);
		void (*const unset_underlined) (cht_component_t* component);
		bool (*const get_underlined) (cht_component_t* component);

		void (*const set_strikethrough) (cht_component_t* component, bool strikethrough);
		void (*const unset_strikethrough) (cht_component_t* component);
		bool (*const get_strikethrough) (cht_component_t* component);

		void (*const set_obfuscated) (cht_component_t* component, bool obfuscated);
		void (*const unset_obfuscated) (cht_component_t* component);
		bool (*const get_obfuscated) (cht_component_t* component);

		void (*const set_color) (cht_component_t* component, cht_color_t color);
		void (*const unset_color) (cht_component_t* component);
		cht_color_t (*const get_color) (cht_component_t* component);

		void (*const add_extra) (cht_component_t*, const cht_component_t*);
		void (*const free) (cht_component_t*);

	} chat;

} plg_interface_t;

static const plg_interface_t plg_interface = {

	.interface_version = PLG_CURRENT_INTERFACE,

	.logger = {
		.info = log_info,
		.warn = log_warn,
		.error = log_error
	},

	.commands = {
		.add = cmd_add_command,
		.message = cmd_message,
		.get_op_level = cmd_get_op_level,
		.get_sender_type = cmd_get_sender_type,
		.get_player = cmd_get_player
	},

	.player = {
		.get_username = ltg_get_username,
		.get_uuid = ltg_get_uuid,
		.get_protocol = ltg_get_protocol,
		.get_render_distance = ltg_get_render_distance,
		.get_ping = ltg_get_ping,
		.get_textures = ltg_get_textures,
		.get_locale = ltg_get_locale,
		.get_entity = ltg_get_entity
	},

	.chat = {
		.alloc = cht_alloc,
		.set_text = cht_set_text,
		.get_text = cht_get_text,
		.set_bold = cht_set_bold,
		.unset_bold = cht_unset_bold,
		.get_bold = cht_get_bold,
		.set_italic = cht_set_italic,
		.unset_italic = cht_unset_italic,
		.get_italic = cht_get_italic,
		.set_underlined = cht_set_underlined,
		.unset_underlined = cht_unset_underlined,
		.get_underlined = cht_get_underlined,
		.set_strikethrough = cht_set_strikethrough,
		.unset_strikethrough = cht_unset_strikethrough,
		.get_strikethrough = cht_get_strikethrough,
		.set_obfuscated = cht_set_obfuscated,
		.unset_obfuscated = cht_unset_obfuscated,
		.get_obfuscated = cht_get_obfuscated,
		.set_color = cht_set_color,
		.unset_color = cht_unset_color,
		.get_color = cht_get_color,
		.add_extra = cht_add_extra,
		.free = cht_free
	}

};

typedef struct plg_link plg_link_t;

typedef const plg_plugin_t* (*plg_get_plugin_t) (const plg_interface_t*);
typedef void (*plg_on_enable_t) (void);
typedef void (*plg_on_disable_t) (void);

#ifdef __WINDOWS__

struct plg_link {

	HINSTANCE lib;
	const plg_plugin_t* meta;

};

#else

struct plg_link {

	void* lib;
	const plg_plugin_t* meta;

};

#endif

extern utl_vector_t plg_links;

extern void plg_register_plugin(const char*);
extern void plg_register_plugins();

extern void plg_on_startup();
extern void plg_on_postworld();
extern void plg_on_disable();
