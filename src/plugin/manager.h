#pragma once
#include "../main.h"
#include "../io/logger/logger.h"
#include "plugin.h"

#ifdef __WINDOWS__
#include <windows.h>
#else
#include <dlfcn.h>
#endif

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
		.addExtra = cht_add_extra,
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

extern void plg_register_plugin(const char*);
extern void plg_register_plugins();

extern void plg_on_startup();
extern void plg_on_postworld();
extern void plg_on_disable();
