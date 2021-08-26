#pragma once
#include "../../main.h"
#include "../io.h"
#include "../nbt/mnbt.h"

typedef struct {

	size_t cursor;
	size_t length;
	
	io_endianness_t endianness : 1;
	
	byte_t length_prefix[5]; // the length of the packet
	byte_t bytes[];

} pck_packet_t;

#define PCK_INLINE(name, len, end) byte_t name ##_r[sizeof(pck_packet_t) + len]; pck_packet_t* name = (pck_packet_t*) name ##_r; name->cursor = 0; name->length = len; name->endianness = end;

#define PCK_READ_STRING(name, packet) int32_t name ##_length = pck_read_var_int(packet); char name [name ##_length + 1]; pck_read_bytes(packet, (uint8_t*) name, name ##_length); if (name ##_length + 1 != 0) { name [name ##_length] = '\0'; }
#define PCK_ALLOC_STRING(name, packet) int32_t name ##_length = pck_read_var_int(packet); char* name = malloc(name ##_length + 1); pck_read_bytes(packet, (uint8_t*) name, name ##_length); name[name ##_length] = '\0';

extern pck_packet_t* pck_create(size_t, io_endianness_t);
extern pck_packet_t* pck_from_bytes(byte_t*, size_t, io_endianness_t);

extern void pck_init_from_bytes(pck_packet_t*, byte_t*, size_t, io_endianness_t);

static inline int8_t pck_read_int8(pck_packet_t* packet) {

	if (packet->length - packet->cursor < 1) return 0;

	packet->cursor += 1;

	return io_read_int8(packet->bytes + packet->cursor - 1);

}

static inline int16_t pck_read_int16(pck_packet_t* packet) {
	
	if (packet->length - packet->cursor < 2) return 0;

	packet->cursor += 2;

	return io_read_int16(packet->bytes + packet->cursor - 2, packet->endianness);

}

static inline int32_t pck_read_int32(pck_packet_t* packet) {
	
	if (packet->length - packet->cursor < 4) return 0;

	packet->cursor += 4;

	return io_read_int32(packet->bytes + packet->cursor - 4, packet->endianness);

}

static inline int64_t pck_read_int64(pck_packet_t* packet) {
	
	if (packet->length - packet->cursor < 8) return 0;

	packet->cursor += 8;

	return io_read_int64(packet->bytes + packet->cursor - 8, packet->endianness);

}

static inline float32_t pck_read_float32(pck_packet_t* packet) {
	
	if (packet->length - packet->cursor < 4) return 0;

	packet->cursor += 4;

	return io_read_float32(packet->bytes + packet->cursor - 4, packet->endianness);

}

static inline float64_t pck_read_float64(pck_packet_t* packet) {
	
	if (packet->length - packet->cursor < 8) return 0;

	packet->cursor += 8;

	return io_read_float64(packet->bytes + packet->cursor - 8, packet->endianness);

}

static inline int32_t pck_read_var_int(pck_packet_t* packet) {

	size_t size = 0;
	int32_t value = io_read_var_int(packet->bytes + packet->cursor, packet->length - packet->cursor, &size);

	packet->cursor += size;

	return value;

}

static inline int64_t pck_read_var_long(pck_packet_t* packet) {

	size_t size = 0;
	int64_t value = io_read_var_long(packet->bytes + packet->cursor, packet->length - packet->cursor, &size);

	packet->cursor += size;

	return value;

}

extern void pck_read_bytes(pck_packet_t*, byte_t*, int32_t);

static inline void pck_write_int8(pck_packet_t* packet, int8_t value) {

	io_write_int8(packet->bytes + packet->cursor, value);

	packet->cursor += 1;

}

static inline void pck_write_int16(pck_packet_t* packet, int16_t value) {

	io_write_int16(packet->bytes + packet->cursor, value, packet->endianness);

	packet->cursor += 2;

}

static inline void pck_write_int32(pck_packet_t* packet, int32_t value) {

	io_write_int32(packet->bytes + packet->cursor, value, packet->endianness);

	packet->cursor += 4;

}

static inline void pck_write_int64(pck_packet_t* packet, int64_t value) {

	io_write_int64(packet->bytes + packet->cursor, value, packet->endianness);

	packet->cursor += 8;

}

static inline void pck_write_float32(pck_packet_t* packet, float32_t value) {

	io_write_float32(packet->bytes + packet->cursor, value, packet->endianness);

	packet->cursor += 4;

}

static inline void pck_write_float64(pck_packet_t* packet, float64_t value) {

	io_write_float64(packet->bytes + packet->cursor, value, packet->endianness);

	packet->cursor += 8;

}

static inline void pck_write_var_int(pck_packet_t* packet, int32_t value) {

	packet->cursor += io_write_var_int(packet->bytes + packet->cursor, value);

}

// waste between 0-4 bytes but you can always come back to it later and change it
static inline void pck_write_long_var_int(pck_packet_t* packet, int32_t value) {

	io_write_long_var_int(packet->bytes + packet->cursor, value);
	packet->cursor += 5;

}

static inline void pck_write_var_long(pck_packet_t* packet, int64_t value) {

	packet->cursor += io_write_var_long(packet->bytes + packet->cursor, value);

}

extern void pck_write_bytes(pck_packet_t*, const byte_t*, int32_t);

static inline void pck_write_string(pck_packet_t* packet, const char* string, size_t length) {

	pck_write_var_int(packet, length);
	pck_write_bytes(packet, (byte_t*) string, length);

}

static inline void pck_write_nbt(pck_packet_t* packet, mnbt_doc* doc) {

	packet->cursor += mnbt_write(doc, packet->bytes + packet->cursor, MNBT_NONE);

}

static inline byte_t* pck_cursor(pck_packet_t* packet) {
	return packet->bytes + packet->cursor;
}

#if NDEBUG
#define pck_log(packet) {}
#else
extern void pck_log(pck_packet_t* packet);
#endif

/*
static inline void pck_padLength(pck_packet_t* packet) {
	packet->cursor = 0;
	pck_write_int32(packet, 0);
	pck_write_int8(packet, 0);
}

static inline void pck_writeLength(pck_packet_t* packet) {
	
	size_t packet_length = packet->cursor;
	packet->cursor = 5 - io_varIntLength(packet_length - 5);
	pck_write_var_int(packet, packet_length - 5);
	packet->cursor = packet_length;

}
*/