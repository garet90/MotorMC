#include "play.h"
#include "../../io/logger/logger.h"
#include "../../motor.h"
#include "../../world/world.h"
#include "../../world/entity/entity.h"
#include "../../jobs/board.h"
#include "../../jobs/jobs.h"
#include "../../jobs/scheduler/scheduler.h"
#include "../../util/util.h"

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

bool_t phd_handle_teleport_confirm(__attribute__((unused)) ltg_client_t* client, pck_packet_t* packet) {

	log_info("Teleport confirm: %d", pck_read_var_int(packet));

	return true;

}

bool_t phd_handle_chat_message(ltg_client_t* client, pck_packet_t* packet) {

	PCK_READ_STRING(message, packet);

	if (message_length > 0 && message[0] == '/') {
		log_info("%s issued server command: %s", client->username.value, message);
		const cmd_sender_t sender = {
			.type = cmd_player,
			.player = client
		};
		cmd_handle(message + 1, sender);
	} else {
		JOB_CREATE_WORK(job, job_global_chat_message);

		job->sender = client;
		job->message.length = message_length;
		memcpy(job->message.value, message, message_length + 1);

		job_add(&job->header);
	}

	return true;

}

bool_t phd_handle_client_settings(ltg_client_t* client, pck_packet_t* packet) {

	client->locale.length = pck_read_var_int(packet);
	pck_read_bytes(packet, (byte_t*) client->locale.value, client->locale.length);

	client->render_distance = pck_read_int8(packet);
	client->chat_mode = pck_read_var_int(packet);
	__attribute__((unused)) bool_t colors = pck_read_int8(packet);

	ent_player_t* player = (ent_player_t*) ent_get_entity_by_id(client->entity_id);

	pthread_mutex_lock(&player->living_entity.entity.lock);

	player->displayed_skin_parts = pck_read_int8(packet);
	player->main_hand = (byte_t) pck_read_var_int(packet);
	
	pthread_mutex_unlock(&player->living_entity.entity.lock);

	__attribute__((unused)) bool_t disable_text_filtering = pck_read_int8(packet);

	return true;

}

bool_t phd_handle_plugin_message(__attribute__((unused)) ltg_client_t* client, pck_packet_t* packet, int32_t length) {

	PCK_READ_STRING(channel, packet);

	int32_t payload_length = length - (1 + io_var_int_length(channel_length) + channel_length);
	byte_t payload[payload_length];
	pck_read_bytes(packet, payload, payload_length);

	switch(utl_hash(channel)) {
		default:
			break;
	}

	return true;

}

bool_t phd_handle_keep_alive(ltg_client_t* client, pck_packet_t* packet) {

	int64_t out_ms = pck_read_int64(packet);

	struct timespec time;
	clock_gettime(CLOCK_REALTIME, &time);
    client->last_recv = time.tv_sec * 1000 + time.tv_nsec / 0xF4240;

	client->ping = client->last_recv - out_ms;

	return true;

}

bool_t phd_handle_player_position(ltg_client_t* client, pck_packet_t* packet) {

	ent_player_t* player = (ent_player_t*) ent_get_entity_by_id(client->entity_id);
	
	pthread_mutex_lock(&player->living_entity.entity.lock);
	
	player->living_entity.entity.position.x = pck_read_float64(packet);
	player->living_entity.entity.position.y = pck_read_float64(packet);
	player->living_entity.entity.position.z = pck_read_float64(packet);
	
	if (pck_read_int8(packet)) {
		utl_set_bit(player->living_entity.entity.status, ent_on_ground);
	} else {
		utl_reset_bit(player->living_entity.entity.status, ent_on_ground);
	}

	pthread_mutex_unlock(&player->living_entity.entity.lock);

	return true;

}

bool_t phd_handle_player_position_and_look(__attribute__((unused)) ltg_client_t* client, pck_packet_t* packet) {

	ent_player_t* player = (ent_player_t*) ent_get_entity_by_id(client->entity_id);
	
	pthread_mutex_lock(&player->living_entity.entity.lock);

	player->living_entity.entity.position.x = pck_read_float64(packet);
	player->living_entity.entity.position.y = pck_read_float64(packet);
	player->living_entity.entity.position.z = pck_read_float64(packet);

	player->living_entity.rotation.yaw = pck_read_float32(packet);
	player->living_entity.rotation.pitch = pck_read_float32(packet);
	
	if (pck_read_int8(packet)) {
		utl_set_bit(player->living_entity.entity.status, ent_on_ground);
	} else {
		utl_reset_bit(player->living_entity.entity.status, ent_on_ground);
	}
	
	pthread_mutex_unlock(&player->living_entity.entity.lock);

	return true;

}

void phd_send_chat_message(ltg_client_t* client, const char* message, size_t message_len, ltg_uuid_t uuid) {

	PCK_INLINE(packet, 23 + message_len, io_big_endian);

	pck_write_var_int(packet, 0x0F);
	pck_write_string(packet, message, message_len);
	pck_write_int8(packet, 0); // position
	pck_write_bytes(packet, uuid, 16);

	ltg_send(client, packet);

}

void phd_send_system_chat_message(ltg_client_t* client, const char* message, size_t message_len) {

	PCK_INLINE(packet, 7 + message_len, io_big_endian);

	pck_write_var_int(packet, 0x0F);
	pck_write_string(packet, message, message_len);
	pck_write_int8(packet, 1);
	pck_write_int64(packet, 0);
	pck_write_int64(packet, 0);
	
	ltg_send(client, packet);

}

void phd_send_declare_commands(ltg_client_t* client) {

	ltg_send(client, cmd_get_graph());

}

void phd_send_plugin_message(ltg_client_t* client, const char* identifier, size_t identifier_length, const byte_t* data, size_t data_length) {

	PCK_INLINE(packet, 6 + identifier_length + data_length, io_big_endian);
	
	pck_write_var_int(packet, 0x18);
	pck_write_string(packet, identifier, identifier_length);
	pck_write_bytes(packet, data, data_length);

	ltg_send(client, packet);

}

void phd_send_disconnect(ltg_client_t* client, const char* message, size_t message_len) {

	PCK_INLINE(packet, 1 + message_len, io_big_endian);

	pck_write_var_int(packet, 0x1a);
	pck_write_string(packet, message, message_len);

	ltg_send(client, packet);

}

void phd_send_keep_alive(ltg_client_t* client, uint64_t id) {

	PCK_INLINE(packet, 9, io_big_endian);

	pck_write_var_int(packet, 0x21);
	pck_write_int64(packet, id);

	ltg_send(client, packet);

}

void phd_send_join_game(ltg_client_t* client) {

	// create an entity for the player
	ent_player_t* player = calloc(1, sizeof(ent_player_t));
	client->entity_id = ent_register_entity((ent_entity_t*) player);

	// set last recieve packet to now
	struct timespec time;
	clock_gettime(CLOCK_REALTIME, &time);
    client->last_recv = time.tv_sec * 1000 + time.tv_nsec / 0xF4240;

	JOB_CREATE_WORK(keep_alive, job_keep_alive);
	keep_alive->client = client;
	client->keep_alive = sch_schedule_repeating(&keep_alive->header, 200, 200);

	const mat_codec_t* codec = mat_get_codec();
	const mat_codec_t* dimension_codec = mat_get_dimension_codec(mat_dimension_overworld);

	PCK_INLINE(packet, codec->size + dimension_codec->size + 1024, io_big_endian);

	pck_write_var_int(packet, 0x26);
	pck_write_int32(packet, client->entity_id); // entity ID
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
	phd_send_declare_commands(client);
	phd_send_player_info_add_players(client);
	phd_send_player_position_and_look(client);

	// add to online players
	pthread_mutex_lock(&sky_main.listener.online.lock);
	
	client->online_node = utl_list_doubly_push(&sky_main.listener.online.list, client);

	pthread_mutex_unlock(&sky_main.listener.online.lock);

	JOB_CREATE_WORK(work, job_player_join);
	work->player = client;

	job_add(&work->header);

}

void phd_send_player_info_add_players(ltg_client_t* client) {

	pthread_mutex_lock(&sky_main.listener.online.lock);

	if (sky_main.listener.online.list.length == 0) {
		pthread_mutex_unlock(&sky_main.listener.online.lock);
		return;
	}

	PCK_INLINE(packet, 3 + (sky_main.listener.online.list.length * 2048), io_big_endian);
	
	pck_write_var_int(packet, 0x36);
	pck_write_var_int(packet, 0);
	pck_write_var_int(packet, sky_main.listener.online.list.length);

	utl_doubly_linked_node_t* node = sky_main.listener.online.list.first;
	while (node != NULL) {
		ltg_client_t* player = node->element;
		pck_write_bytes(packet, player->uuid, 16);
		pck_write_string(packet, player->username.value, player->username.length);
		if (player->textures.value.value != NULL) {
			pck_write_var_int(packet, 1);
			pck_write_string(packet, "textures", 8);
			pck_write_string(packet, player->textures.value.value, player->textures.value.length);
			if (player->textures.signature.value != NULL) {
				pck_write_int8(packet, 1);
				pck_write_string(packet, player->textures.signature.value, player->textures.signature.length);
			} else {
				pck_write_int8(packet, 0);
			}
		} else {
			pck_write_var_int(packet, 0);
		}
		pck_write_var_int(packet, 0); // game mode
		pck_write_var_int(packet, player->ping); // ping
		pck_write_int8(packet, 0); // has display name
		node = node->next;
	}

	pthread_mutex_unlock(&sky_main.listener.online.lock);

	ltg_send(client, packet);

}

void phd_send_player_info_add_player(ltg_client_t* client, ltg_client_t* player) {

	PCK_INLINE(packet, 2048, io_big_endian);
	pck_write_var_int(packet, 0x36);
	pck_write_var_int(packet, 0);
	pck_write_var_int(packet, 1);
	pck_write_bytes(packet, player->uuid, 16);
	pck_write_string(packet, player->username.value, player->username.length);
	if (player->textures.value.value != NULL) {
		pck_write_var_int(packet, 1);
		pck_write_string(packet, "textures", 8);
		pck_write_string(packet, player->textures.value.value, player->textures.value.length);
		if (player->textures.signature.value != NULL) {
			pck_write_int8(packet, 1);
			pck_write_string(packet, player->textures.signature.value, player->textures.signature.length);
		} else {
			pck_write_int8(packet, 0);
		}
	} else {
		pck_write_var_int(packet, 0);
	}
	pck_write_var_int(packet, 0); // game mode
	pck_write_var_int(packet, player->ping); // ping
	pck_write_int8(packet, 0); // has display name
	
	ltg_send(client, packet);

}

void phd_send_player_info_update_gamemode(__attribute__((unused)) ltg_client_t* client, __attribute__((unused)) ltg_client_t* player) {

}

void phd_send_player_info_update_latency(ltg_client_t* client) {

	// TODO test to make sure this actually works
	PCK_INLINE(packet, 21 * sky_main.listener.online.list.length + 6, io_big_endian);

	pck_write_var_int(packet, 0x36);
	pck_write_var_int(packet, 2); // update latency
	pck_write_var_int(packet, sky_main.listener.online.list.length);
	utl_doubly_linked_node_t* node = sky_main.listener.online.list.first;
	while (node != NULL) {
		ltg_client_t* player = node->element;
		pck_write_bytes(packet, player->uuid, 16);
		pck_write_var_int(packet, player->ping);
		node = node->next;
	}

	ltg_send(client, packet);

}

void phd_send_player_info_update_display_name(__attribute__((unused)) ltg_client_t* client, __attribute__((unused)) ltg_client_t* player) {

}

void phd_send_player_info_remove_player(ltg_client_t* client, ltg_uuid_t uuid) {

	PCK_INLINE(packet, 19, io_big_endian);
	pck_write_var_int(packet, 0x36);
	pck_write_var_int(packet, 4);
	pck_write_var_int(packet, 1);
	pck_write_bytes(packet, uuid, 16);

	ltg_send(client, packet);

}

void phd_send_player_position_and_look(ltg_client_t* client) {

	PCK_INLINE(packet, 40, io_big_endian);

	ent_player_t* player = (ent_player_t*) ent_get_entity_by_id(client->entity_id);

	pthread_mutex_lock(&player->living_entity.entity.lock);

	pck_write_var_int(packet, 0x38);
	pck_write_float64(packet, player->living_entity.entity.position.x); // x
	pck_write_float64(packet, player->living_entity.entity.position.y); // y
	pck_write_float64(packet, player->living_entity.entity.position.z); // z
	pck_write_float32(packet, player->living_entity.rotation.pitch); // pitch
	pck_write_float32(packet, player->living_entity.rotation.yaw); // yaw
	pck_write_int8(packet, 0); // flags
	pck_write_var_int(packet, 0); // teleport id
	pck_write_int8(packet, 0); // dismount vehicle

	pthread_mutex_unlock(&player->living_entity.entity.lock);

	ltg_send(client, packet);

}