#pragma once
#include "../../main.h"
#include "../io.h"

typedef struct {

	size_t cursor;
	size_t length;
	
	io_endianness_t endianness;
	byte_t bytes[];

} pck_packet_t;

#define pck_inline(name, len, end) byte_t name ##_r[sizeof(pck_packet_t) + len]; pck_packet_t* name = (pck_packet_t*) name ##_r; name->cursor = 0; name->length = len; name->endianness = end;

#define pck_readString(name, packet) int32_t name ##_length = pck_readVarInt(packet); char name [name ##_length + 1]; pck_readBytes(packet, (uint8_t*) name, name ##_length); name [name ##_length] = '\0';
#define pck_allocString(name, packet) int32_t name ##_length = pck_readVarInt(packet); char* name = malloc(name ##_length + 1); pck_readBytes(packet, (uint8_t*) name, name ##_length); name[name ##_length] = '\0';

extern pck_packet_t* pck_create(size_t, io_endianness_t);
extern pck_packet_t* pck_fromBytes(byte_t*, size_t, io_endianness_t);

extern void pck_initFromBytes(pck_packet_t*, byte_t*, size_t, io_endianness_t);

static inline int8_t pck_readInt8(pck_packet_t* packet) {

	packet->cursor += 1;

	return io_readInt8(packet->bytes + packet->cursor - 1);

}

static inline int16_t pck_readInt16(pck_packet_t* packet) {

	packet->cursor += 2;

	return io_readInt16(packet->bytes + packet->cursor - 2, packet->endianness);

}

static inline int32_t pck_readInt32(pck_packet_t* packet) {

	packet->cursor += 4;

	return io_readInt32(packet->bytes + packet->cursor - 4, packet->endianness);

}

static inline int64_t pck_readInt64(pck_packet_t* packet) {

	packet->cursor += 8;

	return io_readInt64(packet->bytes + packet->cursor - 8, packet->endianness);

}

static inline int32_t pck_readVarInt(pck_packet_t* packet) {

	size_t size = 0;
	int32_t value = io_readVarInt(packet->bytes + packet->cursor, &size);

	packet->cursor += size;

	return value;

}

static inline int64_t pck_readVarLong(pck_packet_t* packet) {

	size_t size = 0;
	int64_t value = io_readVarLong(packet->bytes + packet->cursor, &size);

	packet->cursor += size;

	return value;

}

extern void pck_readBytes(pck_packet_t*, byte_t*, int32_t);

static inline void pck_writeInt8(pck_packet_t* packet, int8_t value) {

	io_writeInt8(packet->bytes + packet->cursor, value);

	packet->cursor += 1;

}

static inline void pck_writeInt16(pck_packet_t* packet, int16_t value) {

	io_writeInt16(packet->bytes + packet->cursor, value, packet->endianness);

	packet->cursor += 2;

}

static inline void pck_writeInt32(pck_packet_t* packet, int32_t value) {

	io_writeInt32(packet->bytes + packet->cursor, value, packet->endianness);

	packet->cursor += 4;

}

static inline void pck_writeInt64(pck_packet_t* packet, int64_t value) {

	io_writeInt64(packet->bytes + packet->cursor, value, packet->endianness);

	packet->cursor += 8;

}

static inline void pck_writeVarInt(pck_packet_t* packet, int32_t value) {

	packet->cursor += io_writeVarInt(packet->bytes + packet->cursor, value);

}

static inline void pck_writeVarLong(pck_packet_t* packet, int64_t value) {

	packet->cursor += io_writeVarLong(packet->bytes + packet->cursor, value);

}

extern void pck_writeBytes(pck_packet_t*, const byte_t*, int32_t);

static inline void pck_writeString(pck_packet_t* packet, char* string, size_t length) {

	pck_writeVarInt(packet, length);
	pck_writeBytes(packet, (byte_t*) string, length);

}

static inline byte_t* pck_cursor(pck_packet_t* packet) {
	return packet->bytes + packet->cursor;
}

static inline void pck_padLength(pck_packet_t* packet) {
	packet->cursor = 0;
	pck_writeInt32(packet, 0);
	pck_writeInt8(packet, 0);
}

static inline void pck_writeLength(pck_packet_t* packet) {
	
	size_t packet_length = packet->cursor;
	packet->cursor = 5 - io_varIntLength(packet_length - 5);
	pck_writeVarInt(packet, packet_length - 5);
	packet->cursor = packet_length;

}