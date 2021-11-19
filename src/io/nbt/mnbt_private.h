#pragma once
#include <string.h>
#include "mnbt.h"

size_t _mnbt_read_tag(mnbt_doc* document, mnbt_tag** tag, const uint8_t* bytes);
size_t _mnbt_read_val(mnbt_doc* document, mnbt_type type, mnbt_val* value, const uint8_t* bytes);

void _mnbt_add(mnbt_doc* document, mnbt_tag* tag);

size_t _mnbt_write_tag(mnbt_tag* tag, uint8_t* bytes);
size_t _mnbt_write_val(mnbt_type type, mnbt_val val, uint8_t* bytes);

void _mnbt_free_val(mnbt_type type, mnbt_val val);

static inline uint16_t _mnbt_reverse_short(uint16_t num) {
#if __ENDIANNESS__
	return num;
#else
	return ((num & 0xff00) >> 8) | (num << 8);
#endif
}

static inline uint32_t _mnbt_reverse_int(uint32_t num) {
#if __ENDIANNESS__
	return num;
#else
	return ((num & 0xff000000) >> 24) | ((num & 0x00ff0000) >> 8) | ((num & 0x0000ff00) << 8) | (num << 24);
#endif
}

static inline uint64_t _mnbt_reverse_long(uint64_t num) {
#if __ENDIANNESS__
	return num;
#else
	return
		((num & 0xff00000000000000L) >> 56) |
		((num & 0x00ff000000000000L) >> 48) |
		((num & 0x0000ff0000000000L) >> 24) |
		((num & 0x000000ff00000000L) >> 8) |
		((num & 0x00000000ff000000L) << 8) |
		((num & 0x0000000000ff0000L) << 24) |
		((num & 0x000000000000ff00L) << 48) |
		(num << 56);
#endif
}

static inline float _mnbt_reverse_float(float val) {
#if __ENDIANNESS__
	return val;
#else
	uint32_t in;
	float out;
	memcpy(&in, &val, sizeof(val));
	in = _mnbt_reverse_int(in);
	memcpy(&out, &in, sizeof(out));

	return out;
#endif
}

static inline double _mnbt_reverse_double(double val) {
#if __ENDIANNESS__
	return val;
#else
	uint64_t in;
	double out;
	memcpy(&in, &val, sizeof(val));
	in = _mnbt_reverse_long(in);
	memcpy(&out, &in, sizeof(out));

	return out;
#endif
}