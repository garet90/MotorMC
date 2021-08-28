#pragma once
#include "../main.h"
#include "world.h"

typedef struct {

	int32_t _Atomic x;
	int32_t _Atomic y;
	int32_t _Atomic z;

} wld_block_position_t;

typedef struct {

	wld_world_t* _Atomic world;
	float64_t _Atomic x;
	float64_t _Atomic y;
	float64_t _Atomic z;

} wld_position_t;

typedef struct {

	float32_t _Atomic pitch;
	float32_t _Atomic yaw;

} wld_rotation_t;