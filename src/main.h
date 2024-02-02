#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdatomic.h>
#include <stdbool.h>

#if defined(__MINGW32__) || defined(__MINGW64__) || defined(__CYGWIN__) || defined(_WIN32) || defined(_WIN64)
#define __WINDOWS__
#endif

#define __MC_VER__ "1.20.4"
#define __MC_PRO__ 765
//755

#define __MOTOR_VER__ "MotorMC InDev 0.0.5"
#define __MOTOR_UNSAFE__ 1

#define UNSET 2

typedef float float32_t;
typedef double float64_t;

typedef uint8_t byte_t;

typedef struct {
	char* value;
	size_t length;
} string_t;

#ifndef __ENDIANNESS__
#define __ENDIANNESS__ 0
#endif