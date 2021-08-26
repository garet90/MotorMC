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

		void (*info) (const char*, ...);
		void (*warn) (const char*, ...);
		void (*error) (const char*, ...);

	} logger;

	struct {

		void (*add) (const cmd_command_t*);
		void (*message) (const cmd_sender_t*, const cht_component_t*);

	} commands;

	struct {

		cht_component_t* (*alloc) ();
		void (*add_extra) (cht_component_t*, const cht_component_t*);
		void (*free) (cht_component_t*);

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
		.message = cmd_message
	},

	.chat = {
		.alloc = cht_alloc,
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
