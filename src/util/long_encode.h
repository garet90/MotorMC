#pragma once
#include "../main.h"

const uint8_t utl_values_per_long[] = {
	0, 64, 32, 21, 16, 12, 10, 9,
	8, 7, 6, 5, 5, 4, 4, 4,
	4, 3, 3, 3, 3, 3, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2,
	2, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1
};

static inline size_t utl_encode_bytes_to_longs_r(int8_t* values, size_t values_length, uint8_t bits_per_entry, int64_t* data) {

	assert(bits_per_entry > 0);

	const uint8_t values_per_long = utl_values_per_long[bits_per_entry];

	size_t i = 0, j = 0;
	for (;;) {
		data[i] = 0;
		
		for (int8_t k = 0; k < values_per_long; ++k) {
			if (j < values_length) {
				data[i] |= ((int64_t) values[j++]) << (k * bits_per_entry);
			} else {
				goto done;
			}
		}

		if (__ENDIANNESS__ == io_little_endian) {
			data[i] = io_switch_int64(data[i]);
		}

		i++;
	}

	done:
	if (__ENDIANNESS__ == io_little_endian) {
		data[i] = io_switch_int64(data[i]);
	}

	return i + 1;

}

static inline size_t utl_encode_shorts_to_longs_r(int16_t* values, size_t values_length, uint8_t bits_per_entry, int64_t* data) {

	assert(bits_per_entry > 0);

	const uint8_t values_per_long = utl_values_per_long[bits_per_entry];

	size_t i = 0, j = 0;
	for (;;) {
		data[i] = 0;
		
		for (int8_t k = 0; k < values_per_long; ++k) {
			if (j < values_length) {
				data[i] |= ((int64_t) values[j++]) << (k * bits_per_entry);
			} else {
				goto done;
			}
		}
		
		if (__ENDIANNESS__ == io_little_endian) {
			data[i] = io_switch_int64(data[i]);
		}

		i++;
	}

	done:

	if (__ENDIANNESS__ == io_little_endian) {
		data[i] = io_switch_int64(data[i]);
	}

	return i + 1;

}

static inline size_t utl_encode_shorts_to_longs(int16_t* values, size_t values_length, uint8_t bits_per_entry, int64_t* data) {

	assert(bits_per_entry > 0);

	const uint8_t values_per_long = utl_values_per_long[bits_per_entry];

	size_t i = 0, j = 0;
	for (;;) {
		data[i] = 0;
		
		for (int8_t k = 0; k < values_per_long; ++k) {
			if (j < values_length) {
				data[i] |= ((int64_t) values[j++]) << (k * bits_per_entry + (64 - values_per_long * bits_per_entry));
			} else {
				goto done;
			}
		}
		
		if (__ENDIANNESS__ == io_little_endian) {
			data[i] = io_switch_int64(data[i]);
		}

		i++;
	}

	done:
	
	if (__ENDIANNESS__ == io_little_endian) {
		data[i] = io_switch_int64(data[i]);
	}

	return i + 1;

}
