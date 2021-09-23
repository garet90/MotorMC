#include "handshake.h"
#include "../../motor.h"
#include "../../io/logger/logger.h"

bool phd_handshake(ltg_client_t* client, pck_packet_t* packet) {

	// legacy server list ping
	if (packet->sub_length == 0x3F01) {
		return phd_handle_legacy_slp(client, packet);
	}

	const int32_t id = pck_read_var_int(packet);

	switch (id) {
	case 0x00:
		return phd_handle_handshake(client, packet);
	default:
		log_warn("Received unknown packet %x in handhsake state!", id);
		return false;
	}

}

bool phd_handle_handshake(ltg_client_t* client, pck_packet_t* packet) {

	client->protocol = pck_read_var_int(packet); // protocol
	PCK_READ_STRING(address, packet); // connecting address
	pck_read_int16(packet); // port

	// set state to next state
	int32_t next_state = pck_read_var_int(packet);
	if (next_state == ltg_login || next_state == ltg_status) {
		client->state = next_state;
		return true;
	} else {
		return false;
	}

}

bool phd_handle_legacy_slp(ltg_client_t* client, __attribute__((unused)) pck_packet_t* packet) {

	phd_send_legacy_slp(client);
	return false;

}

void phd_send_legacy_slp(ltg_client_t* client) {

	PCK_INLINE(packet, 128, io_big_endian);
	pck_write_int8(packet, 0xFF);
	char legacy_slp[384];
	char motd[256];
	cht_write_old(sky_main.motd, motd);

	size_t length = 0;
	with_lock (&sky_main.listener.online.lock) {
		length = sprintf(legacy_slp, "\xa7\x31%c127%cMotor MC " __MC_VER__ "%c%s%c%u%c%u", '\0', '\0', '\0', motd, '\0', sky_main.listener.online.list.length, '\0', sky_main.listener.online.max);
	}
	pck_write_int16(packet, length);
	for (size_t i = 0; i < length; ++i) {
		pck_write_int8(packet, 0);
		pck_write_int8(packet, legacy_slp[i]);
	}

	sck_send(client->socket, (char*) packet->bytes, packet->cursor);

}