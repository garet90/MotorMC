#pragma once
#include "../main.h"
#include "world.h"

typedef struct {

	_Atomic int32_t x;
	_Atomic int32_t y;
	_Atomic int32_t z;

} wld_block_position_t;

typedef struct {

	wld_world_t* _Atomic world;
	_Atomic float64_t x;
	_Atomic float64_t y;
	_Atomic float64_t z;

} wld_position_t;

typedef struct {

	_Atomic float32_t pitch;
	_Atomic float32_t yaw;

} wld_rotation_t;