#include "status.h"
#include "../../io/logger/logger.h"
#include "../../io/chat/chat.h"

bool_t phd_status(ltg_client_t* client, pck_packet_t* packet) {

	pck_read_var_int(packet); // packet length
	int32_t id = pck_read_var_int(packet);

	switch (id) {
	case 0x00:
		return phd_handle_request(client, packet);
	case 0x01:
		return phd_handle_ping(client, packet);
	default:
		log_warn("Received unknown packet %x in status state!", id);
		return false;
	}

}

bool_t phd_handle_request(ltg_client_t* client, pck_packet_t* packet) {

	if (packet->cursor != packet->length) {
		log_error("Client sent bad request packet!");
		return false;
	}

	phd_send_response(client);

	return true;

}

bool_t phd_handle_ping(ltg_client_t* client, pck_packet_t* packet) {

	int64_t random = pck_read_int64(packet);

	phd_send_pong(client, random);

	return true;

}

void phd_send_response(ltg_client_t* client) {

	char slp[2048];
	int32_t slp_length = cht_server_list_ping(slp);

	PCK_INLINE(response, 2048, io_big_endian);

	pck_write_var_int(response, 0x00);
	pck_write_string(response, slp, slp_length);

	ltg_send(client, response);

}

void phd_send_pong(ltg_client_t* client, int64_t random) {

	PCK_INLINE(response, 9, io_big_endian);

	pck_write_var_int(response, 0x01);
	pck_write_int64(response, random);

	ltg_send(client, response);

}
