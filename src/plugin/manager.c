#include "manager.h"
#include <stdio.h>
#include "../util/vector.h"
#include "../io/logger/logger.h"
#include "../io/filesystem/filesystem.h"

utl_vector_t plg_links = {
	.bytes_per_element = sizeof(plg_link_t)
};

void plg_register_plugin(const char* file) {

	plg_link_t link;
	plg_get_plugin_t get_plugin = NULL;

#ifdef __WINDOWS__
	char libraryPath[1024];
	sprintf(libraryPath, "plugins\\%s", file);
	link.lib = LoadLibrary(libraryPath);

	if (link.lib == NULL) {
		log_error("Failed to load plugin %s", file);
		return;
	}

	get_plugin = (void*) GetProcAddress(link.lib, "get_plugin");

	if (get_plugin == NULL) {
		log_error("Failed to load plugin %s", file);
		FreeLibrary(link.lib);
		return;
	}
#else
	char libraryPath[1024];
	sprintf(libraryPath, "plugins/%s", file);
	link.lib = dlopen(libraryPath, RTLD_LAZY);

	if (!link.lib) {
		log_error("Failed to load plugin %s", file);
		return;
	}

	get_plugin = dlsym(link.lib, "get_plugin");
	if (dlerror() != NULL) {
		log_error("Failed to load plugin %s", file);
		dlclose(link.lib);
		return;
	}
#endif

	link.meta = get_plugin(&plg_interface);

	if (link.meta == NULL) {
		log_error("Plugin is out of date and was not loaded: %s", file);
#ifdef __WINDOWS__
		FreeLibrary(link.lib);
#else
		dlclose(link.lib);
#endif
		return;
	}

	utl_vector_push(&plg_links, &link);

}

void plg_register_plugins() {

	if (fs_dir_exists("plugins")) {
#ifdef __WINDOWS__
		fs_get_dir_contents("plugins", "dll", plg_register_plugin);
#elif __APPLE__
		fs_get_dir_contents("plugins", "bundle", plg_register_plugin);
#else
		fs_get_dir_contents("plugins", "so", plg_register_plugin);
#endif
	} else {
		if (!fs_mkdir("plugins")) {
			log_error("Error creating plugin directory!");
		}
	}

}

void plg_on_startup() {

	plg_register_plugins();

	for (uint32_t i = 0; i < plg_links.size; ++i) {

		plg_link_t plugin = UTL_VECTOR_GET_AS(plg_link_t, &plg_links, i);

		if (plugin.meta->load == plg_startup) {

			log_info("Enabling %s version %s...", plugin.meta->name, plugin.meta->version);

			plg_on_enable_t onEnable = NULL;

#ifdef __WINDOWS__

			onEnable = (void*) GetProcAddress(plugin.lib, "onEnable");

#else

			onEnable = dlsym(plugin.lib, "onEnable");

#endif
			if (onEnable == NULL) {
				log_error("Failed to enable %s", plugin.meta->name);
			} else {
				onEnable();
			}

		}

	}

}

void plg_on_postworld() {

	for (uint32_t i = 0; i < plg_links.size; ++i) {

		plg_link_t plugin = UTL_VECTOR_GET_AS(plg_link_t, &plg_links, i);

		if (plugin.meta->load == plg_postworld) {

			log_info("Enabling %s version %s...", plugin.meta->name, plugin.meta->version);

			plg_on_enable_t onEnable = NULL;

#ifdef __WINDOWS__

			onEnable = (void*) GetProcAddress(plugin.lib, "onEnable");

#else

			onEnable = dlsym(plugin.lib, "onEnable");

#endif
			if (onEnable == NULL) {
				log_error("Failed to enable %s", plugin.meta->name);
			} else {
				onEnable();
			}

		}

	}

}

void plg_on_disable() {

	for (uint32_t i = 0; i < plg_links.size; ++i) {

		plg_link_t plugin = UTL_VECTOR_GET_AS(plg_link_t, &plg_links, i);

		log_info("Disabling %s...", plugin.meta->name);

		plg_on_disable_t onDisable = NULL;

#ifdef __WINDOWS__

		onDisable = (void*) GetProcAddress(plugin.lib, "onDisable");

#else

		onDisable = dlsym(plugin.lib, "onDisable");

#endif

		if (onDisable == NULL) {
			log_error("Failed to disable %s", plugin.meta->name);
		} else {
			onDisable();
		}

#ifdef __WINDOWS__

		FreeLibrary(plugin.lib);

#else

		dlclose(plugin.lib);

#endif

	}

}
