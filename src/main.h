#pragma once

#include <stdint.h>
#include <stddef.h>

#if defined(__MINGW32__) || defined(__MINGW64__) || defined(__CYGWIN__) || defined(_WIN32) || defined(_WIN64)
#define __WINDOWS__
#endif

#define __MC_VER__ "1.17.1"
#define __MC_PRO__ 756
//755

#define __MOTOR_VER__ "MotorMC InDev 0.0.1"
#define __MOTOR_UNSAFE__ 1

typedef enum bool {

	false = 0x00,
	true = 0x01

} bool_t;

#define UNSET 0x02

typedef float float32_t;
typedef double float64_t;

typedef uint8_t byte_t;
