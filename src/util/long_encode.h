#pragma once
#include "../main.h"

#define UTL_ENCODE_TO_LONGS(blocks, blocks_length, bits_per_entry, right, data) _Generic((blocks), int32_t*: utl_encode_ints_to_longs, int16_t*: utl_encode_shorts_to_longs, int8_t*: utl_encode_bytes_to_longs) (blocks, blocks_length, bits_per_entry, right, (int64_t*) data)

static inline size_t utl_encode_ints_to_longs(int32_t* values, size_t values_length, int8_t bits_per_entry, bool right, int64_t* data) {
	
	const int8_t values_per_long = 64 / bits_per_entry;
	const size_t size = 1 + ((values_length - 1) / values_per_long);

	for (size_t i = 0; i < values_length; ++i) {
		const int64_t value = values[i];
		const ldiv_t cell_bit = ldiv(i, values_per_long);
		const size_t cell = cell_bit.quot;
		const size_t bit = cell_bit.rem;
		if (bit == 0)
			data[cell] = 0;
		if (right) {
			data[cell] |= value << (bit * bits_per_entry);
		} else {
			data[cell] |= value << (bit * bits_per_entry + (64 - values_per_long * bits_per_entry));
		}
	}

	return size;

}

static inline size_t utl_encode_shorts_to_longs(int16_t* values, size_t values_length, int8_t bits_per_entry, bool right, int64_t* data) {
	
	const int8_t values_per_long = 64 / bits_per_entry;
	const size_t size = 1 + ((values_length - 1) / values_per_long);

	for (size_t i = 0; i < values_length; ++i) {
		const int64_t value = values[i];
		const ldiv_t cell_bit = ldiv(i, values_per_long);
		const size_t cell = cell_bit.quot;
		const size_t bit = cell_bit.rem;
		if (bit == 0)
			data[cell] = 0;
		if (right) {
			data[cell] |= value << (bit * bits_per_entry);
		} else {
			data[cell] |= value << (bit * bits_per_entry + (64 - values_per_long * bits_per_entry));
		}
	}

	return size;

}

static inline size_t utl_encode_bytes_to_longs(int8_t* values, size_t values_length, int8_t bits_per_entry, bool right, int64_t* data) {
	
	const int8_t values_per_long = 64 / bits_per_entry;
	const size_t size = 1 + ((values_length - 1) / values_per_long);

	for (size_t i = 0; i < values_length; ++i) {
		const int64_t value = values[i];
		const ldiv_t cell_bit = ldiv(i, values_per_long);
		const size_t cell = cell_bit.quot;
		const size_t bit = cell_bit.rem;
		if (bit == 0)
			data[cell] = 0;
		if (right) {
			data[cell] |= value << (bit * bits_per_entry);
		} else {
			data[cell] |= value << (bit * bits_per_entry + (64 - values_per_long * bits_per_entry));
		}
	}

	return size;

}
