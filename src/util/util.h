#pragma once
#include "../main.h"

#define UTL_MIN(a, b) _Generic((a), float32_t: utl_minf, float64_t: utl_mind, default: utl_min) (a, b)

static inline float32_t utl_minf(float32_t a, float32_t b) {
	if (a < b) return a;
	return b;
}

static inline float64_t utl_mind(float64_t a, float64_t b) {
	if (a < b) return a;
	return b;
}

static inline int64_t utl_min(int64_t a, int64_t b) {
	if (a < b) return a;
	return b;
}

#define UTL_MAX(a, b) _Generic((a), float32_t: utl_maxf, float64_t: utl_maxd, default: utl_max) (a, b)

static inline float32_t utl_maxf(float32_t a, float32_t b) {
	if (a > b) return a;
	return b;
}

static inline float64_t utl_maxd(float64_t a, float64_t b) {
	if (a > b) return a;
	return b;
}

static inline int64_t utl_max(int64_t a, int64_t b) {
	if (a > b) return a;
	return b;
}

static inline float32_t utl_fabs(float32_t a) {
	if (a < 0) return -a;
	return a;
}

static inline float64_t utl_dabs(float64_t a) {
	if (a < 0) return -a;
	return a;
}

static inline int64_t utl_labs(int64_t a) {
	if (a < 0) return -a;
	return a;
}

#define UTL_ABS(a) _Generic((a), float32_t: utl_fabs, float64_t: utl_dabs, default: utl_labs) (a)

// faster variant of (int64_t) floor(x)
static inline int64_t utl_int_floor(float64_t x) {
	int64_t i = (int64_t) x;
	return i - (i > x);
}

// faster variant of (int64_t) ceil(x)
static inline int64_t utl_int_ceil(float64_t x) {
	int64_t i = (int64_t) x;
	return i + (i < x);
}

static const char utl_hexmap[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

extern size_t utl_to_minecraft_hex(char*, const uint8_t*, size_t);

static inline void utl_write_byte_hex(char* str, uint8_t val) {
	str[0] = utl_hexmap[val >> 4];
	str[1] = utl_hexmap[val & 0x0F];
}

static inline void utl_read_hex_bytes(byte_t* restrict out, const char* restrict str, size_t size) {

	const byte_t asciihex[] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //  !"#$%&'
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ()*+,-./
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, // 01234567
		0x08, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 89:;<=>?
		0x00, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x00, // @ABCDEFG
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // HIJKLMNO
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // PQRSTUVW
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // XYZ[\]^_
		0x00, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x00, // `abcdefg
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // hijklmno
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // pqrstuvw
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // xyz{|}~.
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  // ........
   };

	for (size_t i = 0; i < size; ++i, str += 2) {

		out[i] = (asciihex[(uint8_t) str[0]] << 4) | asciihex[(uint8_t) str[1]];

	}

}

static inline void utl_reverse_bytes(const byte_t* in, byte_t* out, size_t count) {

	for (size_t i = 0, j = count - 1; i < j; ++i, --j) {
		byte_t temp = in[i];
		out[i] = in[j];
		out[j] = temp;
	}

}

#ifndef __APPLE__
/**
 * stpcpy - copy a string from src to dest returning a pointer to the new end
 *          of dest, including src's %NUL-terminator. May overrun dest.
 * @dest: pointer to end of string being copied into. Must be large enough
 *        to receive copy.
 * @src: pointer to the beginning of string being copied from. Must not overlap
 *       dest.
 *
 * stpcpy differs from strcpy in a key way: the return value is the new
 * %NUL-terminated character. (for strcpy, the return value is a pointer to
 * src. This interface is considered unsafe as it doesn't perform bounds
 * checking of the inputs. As such it's not recommended for usage. Instead,
 * its definition is provided in case the compiler lowers other libcalls to
 * stpcpy.
 */
extern char *stpcpy(char *__restrict__ dest, const char *__restrict__ src);
#endif

static inline uint32_t utl_hash(const char* string) {

	uint32_t hash = 5381;
	
	for (;;) {
		switch (*string) {
			case '\0': {
				return hash;
			}
			default: {
				hash = ((hash << 5) + hash) + *string;
				++string;
			}
		}
	}

}