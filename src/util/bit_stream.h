#pragma once
#include "../main.h"
#include "../io/io.h"

typedef struct {

	size_t cursor;

	uint64_t quads[];

} utl_bit_stream_t;

static inline uint64_t utl_read_bit_stream(utl_bit_stream_t* stream, size_t bits) {

	uint64_t result = 0;

	while (bits > 0) {
		
		// get bits and bytes of cursor
		const size_t quad = stream->cursor >> 6;
		const byte_t bit = stream->cursor & 0x3F;

		if (bits > (unsigned) (64 - bit)) { // get the rest of the current byte

			uint64_t add = (stream->quads[quad] << bit) >> bit;
			result = (result << (64 - bit)) | add;

			bits -= 64 - bit;
			stream->cursor += 64 - bit;

		} else { // get only a little bit of this byte

			// get remaining bits in current cursor
			uint64_t add = (stream->quads[quad] << bit) >> bit;
			add >>= (64 - bit - bits);
			result = (result << bits) | add;

			stream->cursor += bits;
			bits = 0;

		}

	}

	if (io_get_endianness() == io_big_endian) {

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

static inline void utl_write_bit_stream(utl_bit_stream_t* stream, uint64_t val, size_t bits) {

	if (io_get_endianness() == io_big_endian) {

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

		// get bits and quad of cursor
		const size_t quad = stream->cursor >> 6;
		const byte_t bit = stream->cursor & 0x3F;

		if (bits > (unsigned) (64 - bit)) {

			stream->quads[quad] |= (val << (64 - bits)) >> bit;

			stream->cursor += (64 - bit);
			bits -= (64 - bit);

		} else {

			stream->quads[quad] |= (val << (64 - bits)) >> bit;

			stream->cursor += bits;
			bits = 0;

		}

	}

}