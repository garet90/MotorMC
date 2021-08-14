#pragma once
#include "../main.h"
#include "../io/io.h"

typedef struct {

	size_t cursor;

	byte_t bytes[];

} utl_bit_stream_t;

static inline int64_t utl_read_bit_stream(utl_bit_stream_t* stream, size_t bits) {

	int64_t result = 0;

	while (bits > 0) {
		
		// get bits and bytes of cursor
		const size_t byte = stream->cursor >> 3;
		const byte_t bit = stream->cursor & 0x7;

		if (bits > (unsigned) (8 - bit)) { // get the rest of the current byte

			byte_t add = (stream->bytes[byte] << bit) >> bit;
			result = (result << (8 - bit)) | add;

			bits -= 8 - bit;
			stream->cursor += 8 - bit;

		} else { // get only a little bit of this byte

			// get remaining bits in current cursor
			byte_t add = (stream->bytes[byte] << bit) >> bit;
			add = (add >> (8 - bit - (8 - bit - bits)));
			result = (result << bits) | add;

			stream->cursor += bits;
			bits = 0;

		}

	}

	if (io_get_endianness() == io_little_endian) {

		union {
			int64_t num;
			byte_t bytes[8];
		} flip;

		flip.bytes[0] = ((byte_t*) &result)[7];
		flip.bytes[1] = ((byte_t*) &result)[6];
		flip.bytes[2] = ((byte_t*) &result)[5];
		flip.bytes[3] = ((byte_t*) &result)[4];
		flip.bytes[4] = ((byte_t*) &result)[3];
		flip.bytes[5] = ((byte_t*) &result)[2];
		flip.bytes[6] = ((byte_t*) &result)[1];
		flip.bytes[7] = ((byte_t*) &result)[0];

		return flip.num;

	} else {
		return result;
	}

}

static inline void utl_write_bit_stream(utl_bit_stream_t* stream, int64_t val, size_t bits) {

	if (io_get_endianness() == io_little_endian) {

		// convert the number to big endian

		union {
			int64_t num;
			byte_t bytes[8];
		} flip;

		flip.bytes[0] = ((byte_t*) &val)[7];
		flip.bytes[1] = ((byte_t*) &val)[6];
		flip.bytes[2] = ((byte_t*) &val)[5];
		flip.bytes[3] = ((byte_t*) &val)[4];
		flip.bytes[4] = ((byte_t*) &val)[3];
		flip.bytes[5] = ((byte_t*) &val)[2];
		flip.bytes[6] = ((byte_t*) &val)[1];
		flip.bytes[7] = ((byte_t*) &val)[0];

		val = flip.num;

	}

	while (bits > 0) {
		
		// get bits and bytes of cursor
		const size_t byte = stream->cursor >> 3;
		const byte_t bit = stream->cursor & 0x7;

		if (bits > (unsigned) (8 - bit)) { // rest of current byte should be this number

			byte_t add = (val << bit) >> bit;
			stream->bytes[byte] |= add;

			stream->cursor += (8 - bit);
			val <<= (8 - bit);
			bits -= (8 - bit);

		} else { // only part of this byte should be this number

			byte_t add = (val << bit) >> bit;
			add = (add >> (8 - bit - (8 - bit - bits))) << (8 - bit - (8 - bit - bits));
			stream->bytes[byte] |= add;

			stream->cursor += bits;
			val <<= bits;
			bits = 0;

		}

	}

}