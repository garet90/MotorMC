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
				.add = cmd_addCommand,
				.message = cmd_message
		},

		.chat = {
				.alloc = cht_alloc,
				.addExtra = cht_addExtra,
				.free = cht_free
		}

};

typedef struct plg_link plg_link_t;

typedef const plg_plugin_t* (*plg_getPlugin_t) (const plg_interface_t*);
typedef void (*plg_onEnable_t) (void);
typedef void (*plg_onDisable_t) (void);

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

extern void plg_registerPlugin(const char*);
extern void plg_registerPlugins();

extern void plg_onStartup();
extern void plg_onPostworld();
extern void plg_onDisable();
