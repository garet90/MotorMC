#pragma once
#include "../main.h"
#include "world.h"

typedef enum {

	wld_face_bottom,
	wld_face_top,
	wld_face_north,
	wld_face_south,
	wld_face_west,
	wld_face_east

} wld_face_t;

typedef struct {

	wld_world_t* _Atomic world;
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