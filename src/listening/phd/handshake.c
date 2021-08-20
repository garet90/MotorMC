#include "handshake.h"
#include "../../motor.h"
#include "../../io/logger/logger.h"

bool_t phd_handshake(ltg_client_t* client, pck_packet_t* packet) {

	// legacy server list ping
	if (packet->bytes[0] == 0xFE && packet->bytes[1] == 0x01) {
		log_info("Legacy SLP");
		packet->cursor = packet->length;
		return phd_handle_legacy_slp(client, packet);
	}

	__attribute__((unused)) const int32_t length = pck_read_var_int(packet); // packet length
	const int32_t id = pck_read_var_int(packet);

	switch (id) {
	case 0x00:
		return phd_handle_handshake(client, packet);
	default:
		log_warn("Received unknown packet %x in handhsake state!", id);
		return false;
	}

}

bool_t phd_handle_handshake(ltg_client_t* client, pck_packet_t* packet) {

	client->protocol = pck_read_var_int(packet); // protocol
	PCK_READ_STRING(address, packet); // connecting address
	pck_read_int16(packet); // port

	// set state to next state
	client->state = pck_read_var_int(packet);
	return true;

}

bool_t phd_handle_legacy_slp(ltg_client_t* client, __attribute__((unused)) pck_packet_t* packet) {

	phd_send_legacy_slp(client);
	return true;

}

void phd_send_legacy_slp(ltg_client_t* client) {

	// I have absolutely no idea why this doesn't work TODO

	PCK_INLINE(packet, 128, io_big_endian);
	pck_write_int8(packet, 0xFF);
	const char legacy_slp[] = "\xa7\x31" "\0" "127" "\0" "Motor MC " __MC_VER__ "\0" "A MotorMC Server" "\0" "0" "\0" "0";
	pck_write_int16(packet, sizeof(legacy_slp) - 1);
	for (size_t i = 0; i < sizeof(legacy_slp) - 1; ++i) {
		pck_write_int16(packet, legacy_slp[i]);
	}

	ltg_send(client, packet);

}