#include "world.h"
#include <stdlib.h>
#include <string.h>

wld_world_t* wld_new(const char* name, int64_t seed, mat_dimension_type_t environment) {

	wld_world_t* world = calloc(1, sizeof(wld_world_t));
	world->seed = seed;
	world->environment = environment;
	world->name = name;

	return world;

}

wld_world_t* wld_load(const char* name) {

	wld_world_t* world = calloc(1, sizeof(wld_world_t));
	world->name = name;

	// TODO

	return world;

}

void wld_unload(wld_world_t* world) {

	free(world);

}