#include "status.h"
#include "../../io/logger/logger.h"
#include "../../io/chat/chat.h"

bool_t phd_status(ltg_client_t* client, pck_packet_t* packet) {

	pck_readVarInt(packet); // packet length
	int32_t id = pck_readVarInt(packet);

	switch (id) {
	case 0x00:
		return phd_handleRequest(client, packet);
	case 0x01:
		return phd_handlePing(client, packet);
	default:
		log_warn("Received unknown packet %x in status state!", id);
		return false;
	}

}

bool_t phd_handleRequest(ltg_client_t* client, pck_packet_t* packet) {

	if (packet->cursor != packet->length) {
		log_error("Client sent bad request packet!");
		return false;
	}

	phd_sendResponse(client);

	return true;

}

bool_t phd_handlePing(ltg_client_t* client, pck_packet_t* packet) {

	int64_t random = pck_readInt64(packet);

	phd_sendPong(client, random);

	return true;

}

void phd_sendResponse(ltg_client_t* client) {

	char slp[2048];
	int32_t slp_length = cht_serverListPing(slp);

	pck_inline(response, 2048, IO_BIG_ENDIAN);

	pck_writeVarInt(response, 0x00);
	pck_writeString(response, slp, slp_length);

	ltg_send(client, response);

}

void phd_sendPong(ltg_client_t* client, int64_t random) {

	pck_inline(response, 9, IO_BIG_ENDIAN);

	pck_writeVarInt(response, 0x01);
	pck_writeInt64(response, random);

	ltg_send(client, response);

}
