#include "play.h"
#include "../../io/logger/logger.h"
#include "../../motor.h"
#include "../../world/world.h"
#include "../../jobs/board.h"
#include "../../jobs/jobs.h"
#include "../../jobs/scheduler/scheduler.h"

bool_t phd_play(ltg_client_t* client, pck_packet_t* packet) {

	int32_t length = pck_read_var_int(packet); // packet length
	int32_t id = pck_read_var_int(packet);

	switch (id) {
	case 0x00:
		return phd_handle_teleport_confirm(client, packet);
	case 0x03:
		return phd_handle_chat_message(client, packet);
	case 0x05:
		return phd_handle_client_settings(client, packet);
	case 0x0a:
		return phd_handle_plugin_message(client, packet, length);
	case 0x0f:
		return phd_handle_keep_alive(client, packet);
	case 0x11:
		return phd_handle_player_position(client, packet);
	case 0x12:
		return phd_handle_player_position_and_look(client, packet);
	default:
		log_warn("Unknown packet %02x received in play state!", id);
		return false;
	}

}

bool_t phd_handle_teleport_confirm(ltg_client_t* client, pck_packet_t* packet) {

	log_info("Teleport confirm: %d", pck_read_var_int(packet));

	return true;

}

bool_t phd_handle_chat_message(ltg_client_t* client, pck_packet_t* packet) {

	JOB_CREATE_WORK(job, job_global_chat_message);

	job->sender = client;
	job->message.length = pck_read_var_int(packet);
	pck_read_bytes(packet, (byte_t*) job->message.value, job->message.length);
	job->message.value[job->message.length] = '\0';

	job_add(&job->header);

	return true;

}

bool_t phd_handle_client_settings(ltg_client_t* client, pck_packet_t* packet) {

	client->locale.length = pck_read_var_int(packet);
	pck_read_bytes(packet, (byte_t*) client->locale.value, client->locale.length);

	log_info("View distance: %d", pck_read_int8(packet));
	log_info("Chat mode: %d", pck_read_var_int(packet));
	log_info("Colors: %d", pck_read_int8(packet));
	log_info("Displayed skin parts: %x", pck_read_int8(packet));
	log_info("Main hand: %d", pck_read_var_int(packet));
	log_info("Disable text filtering: %d", pck_read_int8(packet));

	phd_send_player_position_and_look(client);

	return true;

}

bool_t phd_handle_plugin_message(ltg_client_t* client, pck_packet_t* packet, int32_t length) {

	PCK_READ_STRING(channel, packet);
	log_info("Plugin message for channel: %s", channel);

	int32_t payload_length = length - (1 + io_var_int_length(channel_length) + channel_length);
	byte_t payload[payload_length];
	pck_read_bytes(packet, payload, payload_length);

	log_info("Packet cursor: %d", packet->cursor);
	log_info("Packet length: %d", packet->length);

	return true;

}

bool_t phd_handle_keep_alive(ltg_client_t* client, pck_packet_t* packet) {

	pck_read_int64(packet); // keep alive id

	return true;

}

bool_t phd_handle_player_position(ltg_client_t* client, pck_packet_t* packet) {

	log_info("X: %f", pck_read_float64(packet));
	log_info("Feet Y: %f", pck_read_float64(packet));
	log_info("Z: %f", pck_read_float64(packet));
	log_info("On Ground: %d", pck_read_int8(packet));

	return true;

}

bool_t phd_handle_player_position_and_look(ltg_client_t* client, pck_packet_t* packet) {

	log_info("X: %f", pck_read_float64(packet));
	log_info("Feet Y: %f", pck_read_float64(packet));
	log_info("Z: %f", pck_read_float64(packet));
	log_info("Yaw: %f", pck_read_float32(packet));
	log_info("Pitch: %f", pck_read_float32(packet));
	log_info("On Ground: %d", pck_read_int8(packet));

	return true;

}

void phd_send_chat_message(ltg_client_t* client, const char* message, size_t message_len, byte_t position, ltg_uuid_t uuid) {

	PCK_INLINE(packet, 23 + message_len, IO_BIG_ENDIAN);

	pck_write_var_int(packet, 0x0F);
	pck_write_string(packet, message, message_len);
	pck_write_int8(packet, position);
	pck_write_bytes(packet, uuid, 16);

	ltg_send(client, packet);

}

void phd_send_plugin_message(ltg_client_t* client, const char* identifier, size_t identifier_length, const byte_t* data, size_t data_length) {

	PCK_INLINE(packet, 6 + identifier_length + data_length, IO_BIG_ENDIAN);
	
	pck_write_var_int(packet, 0x18);
	pck_write_string(packet, identifier, identifier_length);
	pck_write_bytes(packet, data, data_length);

	ltg_send(client, packet);

}

void phd_send_keep_alive(ltg_client_t* client, uint64_t id) {

	PCK_INLINE(packet, 9, IO_BIG_ENDIAN);

	pck_write_var_int(packet, 0x21);
	pck_write_int64(packet, id);

	ltg_send(client, packet);

}

void phd_send_join_game(ltg_client_t* client) {
	
	JOB_CREATE_WORK(keep_alive, job_keep_alive);
	keep_alive->client = client;
	client->keep_alive = sch_schedule_repeating(&keep_alive->header, 200, 200);

	mat_codec_t* codec = mat_get_codec();
	mat_codec_t* dimension_codec = mat_get_dimension_codec(mat_dimension_overworld);

	PCK_INLINE(packet, codec->size + dimension_codec->size + 1024, IO_BIG_ENDIAN);

	pck_write_var_int(packet, 0x26);
	pck_write_int32(packet, 0); // entity ID
	pck_write_int8(packet, sky_main.hardcore);
	pck_write_int8(packet, sky_main.gamemode);
	pck_write_int8(packet, -1); // previous game mode

	// worlds
	pck_write_var_int(packet, sky_main.worlds.size);
	for (size_t i = 0; i < sky_main.worlds.size; ++i) {
		wld_world_t* world = UTL_VECTOR_GET_AS(wld_world_t*, &sky_main.worlds, i);
		pck_write_string(packet, world->name, world->name_length);
	}

	pck_write_bytes(packet, codec->bytes, codec->size);
	pck_write_bytes(packet, dimension_codec->bytes, dimension_codec->size);

	pck_write_string(packet, "world", 5); // world name
	pck_write_int64(packet, 0); // hashed seed
	pck_write_var_int(packet, 0); // max players
	pck_write_var_int(packet, 10); // view distance
	pck_write_int8(packet, 0); // reduced debug info
	pck_write_int8(packet, 1); // enable respawn screen
	pck_write_int8(packet, 0); // is debug
	pck_write_int8(packet, 0); // is flat

	ltg_send(client, packet);

	phd_send_plugin_message(client, "minecraft:brand", 15, (const byte_t*) "\x07MotorMC", 8);

}

void phd_send_player_position_and_look(ltg_client_t* client) {

	PCK_INLINE(packet, 40, IO_BIG_ENDIAN);

	pck_write_var_int(packet, 0x38);
	pck_write_float64(packet, 0); // x
	pck_write_float64(packet, 0); // y
	pck_write_float64(packet, 0); // z
	pck_write_float32(packet, 0); // pitch
	pck_write_float32(packet, 0); // yaw
	pck_write_int8(packet, 0); // flags
	pck_write_var_int(packet, 0); // teleport id
	pck_write_int8(packet, 0); // dismount vehicle

	ltg_send(client, packet);

}