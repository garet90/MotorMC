#pragma once
#include "world.h"

wld_region_t* wld_gen_region(wld_world_t* world, int16_t x, int16_t y);
wld_chunk_t* wld_gen_chunk(wld_region_t* region, uint16_t idx);