#pragma once
#include <assert.h>
#include <string.h>
#include <math.h>
#include "../main.h"

typedef enum io_endianness {
	io_little_endian = 0,
	io_big_endian = 1
} io_endianness_t;

static inline uint16_t io_switch_int16(uint16_t num) {
	return ((num & 0xff00) >> 8) | (num << 8);
}

static inline uint32_t io_switch_int32(uint32_t num) {
	return ((num & 0xff000000) >> 24) | ((num & 0x00ff0000) >> 8) | ((num & 0x0000ff00) << 8) | (num << 24);
}

static inline uint64_t io_switch_int64(uint64_t num) {
	return
		((num & 0xff00000000000000L) >> 56) |
		((num & 0x00ff000000000000L) >> 40) |
		((num & 0x0000ff0000000000L) >> 24) |
		((num & 0x000000ff00000000L) >> 8) |
		((num & 0x00000000ff000000L) << 8) |
		((num & 0x0000000000ff0000L) << 24) |
		((num & 0x000000000000ff00L) << 40) |
		(num << 56);
}

static inline int8_t io_read_int8(const byte_t* buffer) {
	return *buffer;
}

static inline int16_t io_read_int16(const byte_t* buffer, io_endianness_t endianness) {

	if (__ENDIANNESS__ == endianness) {

		return *((int16_t*) buffer);

	} else {

		return io_switch_int16(*((int16_t*) buffer));

	}

}

static inline int32_t io_read_int32(const byte_t* buffer, io_endianness_t endianness) {

	if (__ENDIANNESS__ == endianness) {

		return *((int32_t*) buffer);

	} else {

		return io_switch_int32(*((int32_t*) buffer));

	}

}

static inline int64_t io_read_int64(const byte_t* buffer, io_endianness_t endianness) {

	if (__ENDIANNESS__ == endianness) {
		
		return *((int64_t*) buffer);

	} else {

		return io_switch_int64(*((int64_t*) buffer));

	}

}

static inline float32_t io_read_float32(const byte_t* buffer, io_endianness_t endianness) {

	if (__ENDIANNESS__ == endianness) {

		float32_t out;
		memcpy(&out, buffer, sizeof(float32_t));
		return out;

	} else {

		float32_t out;
		byte_t* out_b = (byte_t*) &out;
		out_b[3] = buffer[0];
		out_b[2] = buffer[1];
		out_b[1] = buffer[2];
		out_b[0] = buffer[3];

		return out;

	}

}

static inline float64_t io_read_float64(const byte_t* buffer, io_endianness_t endianness) {

	if (__ENDIANNESS__ == endianness) {
		
		float64_t out;
		memcpy(&out, buffer, sizeof(float64_t));
		return out;

	} else {

		float64_t out;
		byte_t* out_b = (byte_t*) &out;
		out_b[7] = buffer[0];
		out_b[6] = buffer[1];
		out_b[5] = buffer[2];
		out_b[4] = buffer[3];
		out_b[3] = buffer[4];
		out_b[2] = buffer[5];
		out_b[1] = buffer[6];
		out_b[0] = buffer[7];

		return out;

	}

}

static inline int32_t io_read_var_int(const byte_t* buffer, size_t max_length, size_t* length) {
	
	int32_t result = 0;
	int8_t read = 0x80;

	if (max_length > 5) max_length = 5;

	if (__ENDIANNESS__ == io_little_endian) {

		for (*length = 0; *length < max_length && (read & 0x80); ++*length) {
			read = io_read_int8(buffer + *length);
			result |= ((read & 0x7F) << (7 * *length));
		}

	} else {

		for (*length = 0; *length < max_length && (read & 0x80); ++*length) {
			read = io_read_int8(buffer + *length);
			result |= ((read & 0x7F) << (32 - (7 * *length)));
		}

	}

	return result;

}

static inline int64_t io_read_var_long(const byte_t* buffer, size_t max_length, size_t* length) {
	
	int64_t result = 0;
	int8_t read = 0x80;

	if (max_length > 10) max_length = 10;

	if (__ENDIANNESS__ == io_little_endian) {

		for (*length = 0; *length < max_length && (read & 0x80); ++*length) {
			read = io_read_int8(buffer + *length);
			result |= ((read & 0x7F) << (7 * *length));
		}

	} else {

		for (*length = 0; *length < max_length && (read & 0x80); ++*length) {
			read = io_read_int8(buffer + *length);
			result |= ((read & 0x7F) << (64 - (7 * *length)));
		}

	}

	return result;

}

static inline void io_write_int8(byte_t* buffer, int8_t value) {

	buffer[0] = value;

}

static inline void io_write_int16(byte_t* buffer, int16_t value, io_endianness_t endianness) {

	if (__ENDIANNESS__ == endianness) {

		*((int16_t*) buffer) = value;
		
	} else {

		*((int16_t*) buffer) = io_switch_int16(value);

	}

}

static inline void io_write_int32(byte_t* buffer, int32_t value, io_endianness_t endianness) {

	if (__ENDIANNESS__ == endianness) {

		*((int32_t*) buffer) = value;

	} else {

		*((int32_t*) buffer) = io_switch_int32(value);

	}

}

static inline void io_write_int64(byte_t* buffer, int64_t value, io_endianness_t endianness) {

	if (__ENDIANNESS__ == endianness) {

		*((int64_t*) buffer) = value;

	} else {

		*((int64_t*) buffer) = io_switch_int64(value);

	}

}

static inline void io_write_float32(byte_t* buffer, float32_t value, io_endianness_t endianness) {

	if (__ENDIANNESS__ == endianness) {

		memcpy(buffer, &value, sizeof(value));

	} else {

		byte_t* in = (byte_t*) &value;

		buffer[0] = in[3];
		buffer[1] = in[2];
		buffer[2] = in[1];
		buffer[3] = in[0];

	}

}

static inline void io_write_float64(byte_t* buffer, float64_t value, io_endianness_t endianness) {

	if (__ENDIANNESS__ == endianness) {

		memcpy(buffer, &value, sizeof(value));

	} else {

		byte_t* in = (byte_t*) &value;

		buffer[0] = in[7];
		buffer[1] = in[6];
		buffer[2] = in[5];
		buffer[3] = in[4];
		buffer[4] = in[3];
		buffer[5] = in[2];
		buffer[6] = in[1];
		buffer[7] = in[0];

	}

}

static inline size_t io_var_int_length(uint32_t value) {

	size_t len = 0;

	do {

		len++;
		value >>= 7;

	} while (value != 0);

	return len;

}

static inline size_t io_write_var_int(byte_t* buffer, uint32_t value, __attribute__((unused)) size_t max_length) {

	size_t i = 0;
	do {
		int8_t temp = (int8_t) (value & 0x7F);

		value >>= 7;
		if (value != 0) {
			temp |= 0x80;
		}
		assert(i < max_length);
		io_write_int8(buffer + i++, temp);
	} while (value != 0);

	return i;

}

static inline void io_write_long_var_int(byte_t* buffer, uint32_t value) {

	size_t i = 0;
	do {
		int8_t temp = (int8_t) (value & 0x7F);

		value >>= 7;
		if (i < 4) {
			temp |= 0x80;
		}
		io_write_int8(buffer + i++, temp);
	} while (i < 5);

}

static inline size_t io_write_var_long(byte_t* buffer, uint64_t value) {

	size_t i = 0;
	do {
		int8_t temp = (int8_t) (value & 0x7F);

		value >>= 7;
		if (value != 0) {
			temp |= 0x80;
		}
		io_write_int8(buffer + i++, temp);
	} while (value != 0);

	return i;

}

static inline uint16_t io_htons(uint16_t n) {

	if (__ENDIANNESS__ == io_little_endian) {

		return io_switch_int16(n);

	}

	return n;

}

static inline uint8_t io_angle_to_byte(float32_t angle) {

	angle = fmodf(angle, 360.f);

	if (angle < 0.f) {
		angle += 360.f;
	}

	return (uint8_t) ((angle / 360.f) * 256.f);

}