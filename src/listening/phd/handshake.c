#include "handshake.h"
#include "../../motor.h"
#include "../../io/logger/logger.h"

bool_t phd_handshake(ltg_client_t* client, pck_packet_t* packet) {

	// legacy server list ping
	if (packet->bytes[0] == 0xFE) {
		packet->cursor++;
		return phd_handleLegacySLP(client, packet);
	}

	pck_readVarInt(packet); // packet length
	int32_t id = pck_readVarInt(packet);

	switch (id) {
	case 0x00:
		return phd_handleHandshake(client, packet);
	default:
		log_warn("Received unknown packet %x in handhsake state!", id);
		return false;
	}

}

bool_t phd_handleHandshake(ltg_client_t* client, pck_packet_t* packet) {

	client->protocol = pck_readVarInt(packet); // protocol
	pck_readString(address, packet); // connecting address
	pck_readInt16(packet); // port

	// set state to next state
	client->state = pck_readVarInt(packet);
	return true;

}

bool_t phd_handleLegacySLP(ltg_client_t* client, pck_packet_t* packet) {

	pck_readInt8(packet); // always 0x01
	phd_sendLegacySLP(client);
	return true;

}

void phd_sendLegacySLP(ltg_client_t* client) {

	// this no worky TODO fix it
	
	const uint8_t MC_PING_HOST[] = {
		0x00, 0x0b,
		0x00, 0x4d, 0x00, 0x43, 0x00, 0x7c, 0x00, 0x50, 0x00, 0x69, 0x00, 0x6e, 0x00, 0x67, 0x00, 0x48, 0x00, 0x6f, 0x00, 0x73, 0x00, 0x74
	};
	
	pck_inline(packet, 512, IO_BIG_ENDIAN);

	// Packet identifier
	pck_writeInt8(packet, -0x02);
	
	// server list ping payload
	pck_writeInt8(packet, 0x01);

	pck_writeBytes(packet, MC_PING_HOST, sizeof(MC_PING_HOST));

	pck_writeInt16(packet, 7); // length of rest of the data

	pck_writeInt8(packet, 75); // protocol version (1 after last using this protocol)

	pck_writeInt16(packet, 0); // length of hostname string

	pck_writeInt32(packet, sky_main.listener.address.port);

	ltg_send(client, packet);

}