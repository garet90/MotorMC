#pragma once

#include "../main.h"
#include "../io/commands/commands.h"

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
		void (*message) (cmd_sender_t, const cht_component_t*);

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

#define registerPlugin(plugin) EXPORT const plg_plugin_t* get_plugin(const plg_interface_t* interface) {\
			if (interface->interface_version != PLG_CURRENT_INTERFACE) {\
				return NULL;\
			}\
			motor = interface;\
			return plugin;\
		}
