#include <string.h>
#include <stdlib.h>
#include "packet.h"
#include "../logger/logger.h"
#include "../../util/util.h"

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

// i know, terribly written function, it's debug, not production don't worry
#if NDEBUG
#else
void pck_log(pck_packet_t* packet) {
	size_t len = packet->cursor;
	if (len > 2048) {
		log_warn("Packet is too big to log! (%d)", len);
		return;
	}
	byte_t* cursor = packet->bytes;
	log_info("Packet of length %d", len);
	while (len >= 16) {
		log_info("%02x%02x %02x%02x %02x%02x %02x%02x %02x%02x %02x%02x %02x%02x %02x%02x",
			cursor[0], cursor[1], cursor[2], cursor[3], cursor[4], cursor[5], cursor[6], cursor[7],
			cursor[8], cursor[9], cursor[10], cursor[11], cursor[12], cursor[13], cursor[14], cursor[15]);
		cursor += 16;
		len -= 16;
	}
	switch (len) {
	case 15:
		log_info("%02x%02x %02x%02x %02x%02x %02x%02x %02x%02x %02x%02x %02x%02x %02x",
			cursor[0], cursor[1], cursor[2], cursor[3], cursor[4], cursor[5], cursor[6], cursor[7],
			cursor[8], cursor[9], cursor[10], cursor[11], cursor[12], cursor[13], cursor[14]);
		break;
	case 14:
		log_info("%02x%02x %02x%02x %02x%02x %02x%02x %02x%02x %02x%02x %02x%02x",
			cursor[0], cursor[1], cursor[2], cursor[3], cursor[4], cursor[5], cursor[6], cursor[7],
			cursor[8], cursor[9], cursor[10], cursor[11], cursor[12], cursor[13]);
		break;
	case 13:
		log_info("%02x%02x %02x%02x %02x%02x %02x%02x %02x%02x %02x%02x %02x",
			cursor[0], cursor[1], cursor[2], cursor[3], cursor[4], cursor[5], cursor[6], cursor[7],
			cursor[8], cursor[9], cursor[10], cursor[11], cursor[12]);
		break;
	case 12:
		log_info("%02x%02x %02x%02x %02x%02x %02x%02x %02x%02x %02x%02x",
			cursor[0], cursor[1], cursor[2], cursor[3], cursor[4], cursor[5], cursor[6], cursor[7],
			cursor[8], cursor[9], cursor[10], cursor[11]);
		break;
	case 11:
		log_info("%02x%02x %02x%02x %02x%02x %02x%02x %02x%02x %02x",
			cursor[0], cursor[1], cursor[2], cursor[3], cursor[4], cursor[5], cursor[6], cursor[7],
			cursor[8], cursor[9], cursor[10]);
		break;
	case 10:
		log_info("%02x%02x %02x%02x %02x%02x %02x%02x %02x%02x",
			cursor[0], cursor[1], cursor[2], cursor[3], cursor[4], cursor[5], cursor[6], cursor[7],
			cursor[8], cursor[9]);
		break;
	case 9:
		log_info("%02x%02x %02x%02x %02x%02x %02x%02x %02x",
			cursor[0], cursor[1], cursor[2], cursor[3], cursor[4], cursor[5], cursor[6], cursor[7],
			cursor[8]);
		break;
	case 8:
		log_info("%02x%02x %02x%02x %02x%02x %02x%02x",
			cursor[0], cursor[1], cursor[2], cursor[3], cursor[4], cursor[5], cursor[6], cursor[7]);
		break;
	case 7:
		log_info("%02x%02x %02x%02x %02x%02x %02x", cursor[0], cursor[1], cursor[2], cursor[3], cursor[4], cursor[5], cursor[6]);
		break;
	case 6:
		log_info("%02x%02x %02x%02x %02x%02x", cursor[0], cursor[1], cursor[2], cursor[3], cursor[4], cursor[5]);
		break;
	case 5:
		log_info("%02x%02x %02x%02x %02x", cursor[0], cursor[1], cursor[2], cursor[3], cursor[4]);
		break;
	case 4:
		log_info("%02x%02x %02x%02x", cursor[0], cursor[1], cursor[2], cursor[3]);
		break;
	case 3:
		log_info("%02x%02x %02x", cursor[0], cursor[1], cursor[2]);
		break;
	case 2:
		log_info("%02x%02x", cursor[0], cursor[1]);
		break;
	case 1:
		log_info("%02x", cursor[0]);
		break;
	default:
		break;
	}
	log_info("End packet payload");
}
#endif