#include "manager.h"
#include <stdio.h>
#include "../util/vector.h"
#include "../io/logger/logger.h"
#include "../io/filesystem/filesystem.h"

utl_vector_t plg_links = {
		.bytes_per_element = sizeof(plg_link_t)
};

void plg_registerPlugin(const char* file) {

	plg_link_t link;
	plg_getPlugin_t getPlugin = NULL;

#ifdef __WINDOWS__
	char libraryPath[1024];
	sprintf(libraryPath, "plugins\\%s", file);
	link.lib = LoadLibrary(libraryPath);

	if (link.lib == NULL) {
		log_error("Failed to load plugin %s", file);
		return;
	}

	getPlugin = (void*) GetProcAddress(link.lib, "getPlugin");

	if (getPlugin == NULL) {
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

	getPlugin = dlsym(link.lib, "getPlugin");
	if (dlerror() != NULL) {
		log_error("Failed to load plugin %s", file);
		dlclose(link.lib);
		return;
	}
#endif

	link.meta = getPlugin(&plg_interface);

	if (link.meta == NULL) {
		log_error("Plugin is out of date and was not loaded: %s", file);
#ifdef __WINDOWS__
		FreeLibrary(link.lib);
#else
		dlclose(link.lib);
#endif
		return;
	}

	utl_vectorPush(&plg_links, &link);

}

void plg_registerPlugins() {

	if (fs_dirExists("plugins")) {
#ifdef __WINDOWS__
		fs_getDirContents("plugins", "dll", plg_registerPlugin);
#elif __APPLE__
		fs_getDirContents("plugins", "bundle", plg_registerPlugin);
#else
		fs_getDirContents("plugins", "so", plg_registerPlugin);
#endif
	} else {
		if (!fs_makeDir("plugins")) {
			log_error("Error creating plugin directory!");
		}
	}

}

void plg_onStartup() {

	plg_registerPlugins();

	for (uint32_t i = 0; i < plg_links.size; ++i) {

		plg_link_t plugin = utl_vectorGetAs(plg_link_t, &plg_links, i);

		if (plugin.meta->load == plg_startup) {

			log_info("Enabling %s version %s...", plugin.meta->name, plugin.meta->version);

			plg_onEnable_t onEnable = NULL;

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

void plg_onPostworld() {

	for (uint32_t i = 0; i < plg_links.size; ++i) {

		plg_link_t plugin = utl_vectorGetAs(plg_link_t, &plg_links, i);

		if (plugin.meta->load == plg_postworld) {

			log_info("Enabling %s version %s...", plugin.meta->name, plugin.meta->version);

			plg_onEnable_t onEnable = NULL;

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

void plg_onDisable() {

	for (uint32_t i = 0; i < plg_links.size; ++i) {

		plg_link_t plugin = utl_vectorGetAs(plg_link_t, &plg_links, i);

		log_info("Disabling %s...", plugin.meta->name);

		plg_onDisable_t onDisable = NULL;

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
