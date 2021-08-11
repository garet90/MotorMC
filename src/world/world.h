#pragma once
#include "../main.h"
#include "../util/vector.h"
#include "../util/tree.h"
#include "../util/bitset.h"
#include "material/material.h"

typedef struct wld_world wld_world_t;
typedef struct wld_region wld_region_t;
typedef struct wld_chunk wld_chunk_t;

struct wld_chunk {

	wld_region_t* region;

	// loaders, to determine which chunks to keep loaded and which to unload
	utl_vector_t loaders;

	// highest blocks
	struct {

		int16_t motion_blocking;
		int16_t world_surface;

	} highest[16 * 16];

	uint16_t idx; // index of chunk in region (used for finding chunk x and y)
	
	struct {
		
		utl_vector_t block_entities;
		utl_vector_t entities;

		// block map
		struct {

			mat_block_protocol_id_t state;
			uint16_t entity;

		} blocks[16 * 16 * 16];

		// biome map
		mat_biome_type_t biome[4 * 4 * 4];

	} sections[]; // y = section index * 16, count of sections = World.height / 16

};

struct wld_region {
	
	wld_world_t* world; // typeof wld_world_t*

	int16_t x;
	int16_t y;

	// bit array determining which chunks are active
	utl_bitset(32 * 32, chunk_active);
	// chunks
	wld_chunk_t* chunks[32 * 32];

	// relative regions
	struct {
		wld_region_t* north;
		wld_region_t* east;
		wld_region_t* south;
		wld_region_t* west;
	} relative;

};

struct wld_world {

	int64_t seed;
	uint64_t time;
	const char* name;
	size_t name_length;

	// regions
	utl_tree_t regions;

	mat_dimension_type_t environment;
	
	bool_t debug;
	bool_t flat;

};

extern wld_world_t* wld_new(const char* name, int64_t seed, mat_dimension_type_t environment);

extern wld_world_t* wld_load(const char* name);

extern void wld_unload(wld_world_t* world);
