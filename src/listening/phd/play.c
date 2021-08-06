#include "play.h"
#include "../../io/logger/logger.h"
#include "../../motor.h"
#include "../../world/world.h"

bool_t phd_play(ltg_client_t* client, pck_packet_t* packet) {

	pck_read_var_int(packet); // packet length
	int32_t id = pck_read_var_int(packet);

	switch (id) {
	default:
		log_warn("Unknown packet %x received in play state! %d", id, client->id);
		return false;
	}

}

void phd_send_join_game(ltg_client_t* client) {

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

}
