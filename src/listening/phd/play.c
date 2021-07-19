#include "play.h"
#include "../../io/logger/logger.h"

bool_t phd_play(ltg_client_t* client, pck_packet_t* packet) {

	pck_readVarInt(packet); // packet length
	int32_t id = pck_readVarInt(packet);

	switch (id) {
	case 0x00: // teleport confirm
		return phd_handleTeleportConfirm(client, packet);
	case 0x04:
		return phd_handleClientStatus(client, packet);
	case 0x05: // client settings
		return phd_handleClientSettings(client, packet);
	case 0x12:
		return phd_handlePlayerPositionAndLook(client, packet);
	default:
		log_warn("Unknown packet %x received in play state!", id);
		return false;
	}

}

bool_t phd_handleTeleportConfirm(ltg_client_t* client, pck_packet_t* packet) {

	assert(client != NULL);
	assert(packet != NULL);

	return false;

}

bool_t phd_handleClientStatus(ltg_client_t* client, pck_packet_t* packet) {

	assert(client != NULL);
	assert(packet != NULL);

	return false;

}

bool_t phd_handleClientSettings(ltg_client_t* client, pck_packet_t* packet) {

	assert(client != NULL);
	assert(packet != NULL);

	return false;

}

bool_t phd_handlePlayerPositionAndLook(ltg_client_t* client, pck_packet_t* packet) {

	assert(client != NULL);
	assert(packet != NULL);

	return false;

}

void phd_sendJoinGame(ltg_client_t* client) {

	assert(client != NULL);

}
