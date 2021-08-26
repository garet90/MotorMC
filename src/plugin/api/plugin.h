#pragma once

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

// TYPES

#include <stdint.h>

typedef string_t {

	char* value;
	size_t length;

}

typedef enum {
	false = 0,
	true = 1
} bool_t;

// COMMAND

typedef void* command_sender_t;

typedef struct {

	const string_t label;
	const string_t description;
	const string_t usage;
	const string_t permission;
	const string_t permission_message;
	bool_t (*const handler) (char*, const command_sender_t);
	const size_t alias_count;
	const string_t aliases[];

} command_t;

// CHAT

typedef void* chat_component_t;

// PLUGINS

typedef enum {

	plugin_postworld = 0,
	plugin_startup

} plugin_startup_t;

typedef struct {

	const string_t name;
	const string_t description;
	const string_t authors;
	const string_t version;
	const string_t website;
	const plugin_startup_t load;

} plugin_t;

#define registerPlugin(plugin) EXPORT const plugin_t* get_plugin(const plg_interface_t* interface) {\
			if (interface->interface_version != PLG_CURRENT_INTERFACE) {\
				return NULL;\
			}\
			motor = interface;\
			return plugin;\
		}

// API

#define CURRENT_PLUGIN_INTERFACE 0

static struct {

	uint32_t interface_version;

	struct {

		void (*info) (const char*, ...);
		void (*warn) (const char*, ...);
		void (*error) (const char*, ...);

	} logger;

	struct {

		void (*add) (const command_t*);
		void (*message) (const command_t, const chat_component_t);

	} commands;

	struct {

		chat_component_t (*alloc) ();
		void (*add_extra) (chat_component_t, const chat_component_t);
		void (*free) (chat_component_t);

	} chat;

} motor;