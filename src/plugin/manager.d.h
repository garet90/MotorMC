#pragma once

typedef enum {

	plg_postworld = 0,
	plg_startup

} plg_startup_t;

typedef struct plg_plugin plg_plugin_t;

#define PLG_CURRENT_INTERFACE 0

typedef struct plg_interface plg_interface_t;