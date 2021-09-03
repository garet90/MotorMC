#pragma once
#include "../main.h"
#include "world.h"

typedef struct {

	atomic_int_least32_t x;
	atomic_int_least32_t y;
	atomic_int_least32_t z;

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