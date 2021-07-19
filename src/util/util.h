#pragma once
#include "../main.h"

#define UTL_MIN(a, b) ((a) < (b) ? a : b)
#define UTL_MAX(a, b) ((a) > (b) ? a : b)

extern size_t utl_toMinecraftHex(char*, const uint8_t*, size_t);

extern void utl_writeByteHex(char*, uint8_t);

extern void utl_readHexBytes(byte_t*, const char*, size_t);

static inline void utl_reverseBytes(const byte_t* in, byte_t* out, size_t count) {

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
            case '\0':
                return hash;
            default:
                hash = ((hash << 5) + hash) + *string;
                ++string;
        }
    }

}