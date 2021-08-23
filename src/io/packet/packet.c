#include <string.h>
#include <stdlib.h>
#include "packet.h"
#include "../logger/logger.h"

pck_packet_t* pck_create(size_t length, io_endianness_t endianness) {

	pck_packet_t* packet = malloc(sizeof(pck_packet_t) + length);

	packet->endianness = endianness;
	packet->length = length;
	packet->cursor = 0;

	return packet;

}

pck_packet_t* pck_from_bytes(byte_t* bytes, size_t length, io_endianness_t endianness) {

	pck_packet_t* packet = malloc(sizeof(pck_packet_t) + length);

	packet->endianness = endianness;
	packet->length = length;
	packet->cursor = 0;
	memcpy(packet->bytes, bytes, length);

	return packet;

}

void pck_init_from_bytes(pck_packet_t* packet, byte_t* bytes, size_t length, io_endianness_t endianness) {

	packet->endianness = endianness;
	packet->length = length;
	packet->cursor = 0;
	memcpy(packet->bytes, bytes, length);

}

void pck_read_bytes(pck_packet_t* packet, byte_t* bytes, int32_t length) {

	if (packet->length - packet->cursor < (unsigned) length) return;

	memcpy(bytes, packet->bytes + packet->cursor, length);
	packet->cursor += length;

}

void pck_write_bytes(pck_packet_t* packet, const byte_t* bytes, int32_t length) {

	memcpy(packet->bytes + packet->cursor, bytes, length);
	packet->cursor += length;

}