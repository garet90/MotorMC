#include "handshake.h"
#include "../../motor.h"
#include "../../io/logger/logger.h"

bool_t phd_handshake(ltg_client_t* client, pck_packet_t* packet) {

	// legacy server list ping
	if (packet->bytes[0] == 0xFE) {
		packet->cursor++;
		return phd_handle_legacy_slp(client, packet);
	}

	pck_read_var_int(packet); // packet length
	int32_t id = pck_read_var_int(packet);

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

bool_t phd_handle_legacy_slp(ltg_client_t* client, pck_packet_t* packet) {

	pck_read_int8(packet); // always 0x01
	phd_send_legacy_slp(client);
	return true;

}

void phd_send_legacy_slp(ltg_client_t* client) {

	// this no worky TODO fix it
	
	const uint8_t MC_PING_HOST[] = {
		0x00, 0x0b,
		0x00, 0x4d, 0x00, 0x43, 0x00, 0x7c, 0x00, 0x50, 0x00, 0x69, 0x00, 0x6e, 0x00, 0x67, 0x00, 0x48, 0x00, 0x6f, 0x00, 0x73, 0x00, 0x74
	};
	
	PCK_INLINE(packet, 512, io_big_endian);

	// Packet identifier
	pck_write_int8(packet, -0x02);
	
	// server list ping payload
	pck_write_int8(packet, 0x01);

	pck_write_bytes(packet, MC_PING_HOST, sizeof(MC_PING_HOST));

	pck_write_int16(packet, 7); // length of rest of the data

	pck_write_int8(packet, 75); // protocol version (1 after last using this protocol)

	pck_write_int16(packet, 0); // length of hostname string

	pck_write_int32(packet, sky_main.listener.address.port);

	ltg_send(client, packet);

}