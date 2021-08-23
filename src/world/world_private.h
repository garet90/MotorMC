#pragma once
#include "world.h"

void wld_prepare_spawn(wld_world_t* world);

wld_region_t* wld_gen_region(wld_world_t* world, int16_t x, int16_t z);
wld_chunk_t* wld_gen_chunk(wld_region_t* region, int8_t x, int8_t z, uint8_t max_ticket);
wld_chunk_t* wld_gen_relative_chunk(const wld_chunk_t* chunk, int16_t x, int16_t z, uint8_t max_ticket);