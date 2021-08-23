#include <tomcrypt.h>
#include "play.h"
#include "../../io/logger/logger.h"
#include "../../io/nbt/mnbt.h"
#include "../../io/commands/graph.h"
#include "../../motor.h"
#include "../../world/world.h"
#include "../../world/entity/entity.h"
#include "../../world/item/recipe/recipe.h"
#include "../../jobs/board.h"
#include "../../jobs/jobs.h"
#include "../../jobs/scheduler/scheduler.h"
#include "../../util/util.h"
#include "../../util/bit_stream.h"

bool_t phd_play(ltg_client_t* client, pck_packet_t* packet) {

	const int32_t length = pck_read_var_int(packet); // packet length
	const int32_t id = pck_read_var_int(packet);

	switch (id) {
	case 0x00:
		return phd_handle_teleport_confirm(client, packet);
	case 0x03:
		return phd_handle_chat_message(client, packet);
	case 0x05:
		return phd_handle_client_settings(client, packet);
	case 0x09:
		return phd_handle_close_window(client, packet);
	case 0x0a:
		return phd_handle_plugin_message(client, packet, length);
	case 0x0f:
		return phd_handle_keep_alive(client, packet);
	case 0x11:
		return phd_handle_player_position(client, packet);
	case 0x12:
		return phd_handle_player_position_and_look(client, packet);
	case 0x1b:
		return phd_handle_entity_action(client, packet);
	case 0x25:
		return phd_handle_held_item_change(client, packet);
	case 0x2c:
		return phd_handle_animation(client, packet);
	default:
		log_warn("Unknown packet %02x received in play state!", id);
		return false;
	}

}

bool_t phd_handle_teleport_confirm(ltg_client_t* client, pck_packet_t* packet) {

	uint32_t confirm = pck_read_var_int(packet);

	// the player must've not heard us right
	if (confirm != client->entity->living_entity.entity.id) {
		phd_send_player_position_and_look(client);
	}

	return true;

}

bool_t phd_handle_chat_message(ltg_client_t* client, pck_packet_t* packet) {

	string_t message;
	message.length = (unsigned) pck_read_var_int(packet);
	message.value = malloc(message.length + 1);
	message.value[message.length] = '\0';
	pck_read_bytes(packet, (byte_t*) message.value, message.length);

	if (message.length > 0 && UTL_STRTOCSTR(message)[0] == '/') {
		log_info("%s issued server command: %s", UTL_STRTOCSTR(client->username), UTL_STRTOCSTR(message));
		const cmd_sender_t sender = {
			.type = cmd_player,
			.player = client
		};
		cmd_handle(UTL_STRTOCSTR(message) + 1, sender);
		free(UTL_STRTOCSTR(message));
	} else {
		JOB_CREATE_WORK(job, job_global_chat_message);

		job->sender = client;
		job->message = message;

		job_add(&job->header);
	}

	return true;

}

bool_t phd_handle_client_settings(ltg_client_t* client, pck_packet_t* packet) {

	PCK_READ_STRING(locale, packet);
	client->locale = utl_hash(locale);

	const uint8_t new_render_distance = pck_read_int8(packet);
	phd_update_sent_chunks_view_distance(client, new_render_distance);
	client->render_distance = UTL_MIN(new_render_distance, sky_main.render_distance);
	client->chat_mode = pck_read_var_int(packet);
	__attribute__((unused)) bool_t colors = pck_read_int8(packet);

	ent_player_t* player = client->entity;

	with_lock (&player->living_entity.entity.lock) {

		player->displayed_skin_parts = pck_read_int8(packet);
		player->main_hand = (byte_t) pck_read_var_int(packet);

	}

	__attribute__((unused)) bool_t disable_text_filtering = pck_read_int8(packet);

	return true;

}

bool_t phd_handle_close_window(__attribute__((unused)) ltg_client_t* client, pck_packet_t* packet) {

	// TODO actually do stuff
	__attribute__((unused)) uint8_t window_id = pck_read_int8(packet);

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

	ent_player_t* player = client->entity;

	const float64_t x = pck_read_float64(packet);
	const float64_t y = pck_read_float64(packet);
	const float64_t z = pck_read_float64(packet);
	const bool_t on_ground = pck_read_int8(packet);

	with_lock (&player->living_entity.entity.lock) {
		
		const uint64_t c_x = (((uint64_t) x) >> 4);
		const uint64_t c_z = (((uint64_t) z) >> 4);

		if ((((uint64_t) player->living_entity.entity.position.x) >> 4) != c_x || (((uint64_t) player->living_entity.entity.position.z) >> 4) != c_z) {

			phd_send_update_view_position_to(client, c_x, c_z);
			phd_update_sent_chunks_move(client, c_x, c_z);

		}

		ent_move_l(&player->living_entity.entity, x, y, z, on_ground);

	}

	return true;

}

bool_t phd_handle_player_position_and_look(ltg_client_t* client, pck_packet_t* packet) {

	ent_player_t* player = client->entity;

	const float64_t x = pck_read_float64(packet);
	const float64_t y = pck_read_float64(packet);
	const float64_t z = pck_read_float64(packet);
	
	const float32_t yaw = pck_read_float32(packet);
	const float32_t pitch = pck_read_float32(packet);

	const bool_t on_ground = pck_read_int8(packet);

	with_lock (&player->living_entity.entity.lock) {

		const uint64_t c_x = (((uint64_t) x) >> 4);
		const uint64_t c_z = (((uint64_t) z) >> 4);

		if ((((uint64_t) player->living_entity.entity.position.x) >> 4) != c_x || (((uint64_t) player->living_entity.entity.position.z) >> 4) != c_z) {

			phd_send_update_view_position_to(client, c_x, c_z);
			phd_update_sent_chunks_move(client, c_x, c_z);

		}

		ent_move_look_l(&player->living_entity, x, y, z, yaw, pitch, on_ground);
	
	}
	
	return true;

}

bool_t phd_handle_entity_action(ltg_client_t* client, pck_packet_t* packet) {

	ent_player_t* player = client->entity;

	// at this point, i have no idea what the client is doing
	// it should send its own entity id
	if (player->living_entity.entity.id != (uint32_t) pck_read_var_int(packet)) {
		return false;
	}

	with_lock (&player->living_entity.entity.lock) {

		int32_t action = pck_read_var_int(packet);
		__attribute__((unused)) int32_t jump_boost = pck_read_var_int(packet); // for jumping with horses

		switch (action) {
		case 0: // start sneaking
			player->living_entity.entity.crouching = true;
			break;
		case 1: // stop sneaking
			player->living_entity.entity.crouching = false;
			break;
		case 2: // leave bed
			break;
		case 3: // start sprinting
			player->living_entity.entity.sprinting = true;
			break;
		case 4: // stop sprinting
			player->living_entity.entity.sprinting = false;
			break;
		case 5: // start jump with horse
			break;
		case 6: // stop jump with horse
			break;
		case 7: // open horse inventory
			break;
		case 8: // start flying with elytra
			player->living_entity.entity.flying_with_elytra = true;
			break;
		}

	}

	return true;

}

bool_t phd_handle_held_item_change(ltg_client_t* client, pck_packet_t* packet) {

	uint16_t slot = pck_read_int16(packet);
	
	ent_player_t* player = client->entity;

	with_lock (&player->living_entity.entity.lock) {
		player->held_item = slot;
	}

	return true;

}

bool_t phd_handle_animation(__attribute__((unused)) ltg_client_t* client, pck_packet_t* packet) {

	__attribute__((unused)) uint8_t hand = pck_read_var_int(packet);

	// TODO

	return true;

}

void phd_send_server_difficulty(ltg_client_t* client) {

	PCK_INLINE(packet, 3, io_big_endian);

	pck_write_var_int(packet, 0x0e);
	pck_write_int8(packet, sky_main.difficulty);
	pck_write_int8(packet, 0); // difficulty locked

	ltg_send(client, packet);

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

	PCK_INLINE(packet, 23 + message_len, io_big_endian);

	pck_write_var_int(packet, 0x0F);
	pck_write_string(packet, message, message_len);
	pck_write_int8(packet, 1); // position
	pck_write_int64(packet, 0); // sender
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

void phd_send_entity_status(ltg_client_t* client, int32_t entity_id, uint8_t status) {

	PCK_INLINE(packet, 6, io_big_endian);

	pck_write_var_int(packet, 0x1b);
	pck_write_int32(packet, entity_id);
	pck_write_int8(packet, status);

	ltg_send(client, packet);

}

void phd_send_keep_alive(ltg_client_t* client, uint64_t id) {

	PCK_INLINE(packet, 9, io_big_endian);

	pck_write_var_int(packet, 0x21);
	pck_write_int64(packet, id);

	ltg_send(client, packet);

}

void phd_send_chunk_data(ltg_client_t* client, wld_chunk_t* chunk) {

	// damn that's a lot of data, maybe consider this not being on the stack
	PCK_INLINE(packet, 262144, io_big_endian);
	
	pck_write_var_int(packet, 0x22);
	pck_write_int32(packet, wld_get_chunk_x(chunk));
	pck_write_int32(packet, wld_get_chunk_z(chunk));
	pck_write_int8(packet, true); // full chunk

	const uint16_t chunk_height = mat_get_chunk_height(chunk->region->world->environment);

	// CHUNK MASK

	const uint16_t chunk_mask_length = (chunk_height >> 6) + 1;
	pck_write_var_int(packet, chunk_mask_length);
	int64_t primary_chunk_mask[chunk_mask_length];
	memset(primary_chunk_mask, 0, sizeof(primary_chunk_mask));
	for (uint16_t i = 0; i < chunk_height; ++i) {
		if (chunk->sections[i].block_count != 0) {
			primary_chunk_mask[i >> 6] |= (1 << (i & 0x3f));
		}
	}
	pck_write_bytes(packet, (byte_t*) primary_chunk_mask, sizeof(primary_chunk_mask));

	// HEIGHTMAP

	int64_t motion_blocking[37];
	memset(motion_blocking, 0, sizeof(motion_blocking));

	// just so we can use i and j again
	{
		uint8_t i = 0; // long
		uint8_t j = 0; // in long

		for (uint16_t k = 0; k < 16 * 16; ++k) {
			motion_blocking[i] |= (uint64_t) io_htons(chunk->highest[k].motion_blocking) << (1 + (6 - j++) * 9);
			if (j > 6) {
				j = 0;
				i += 1;
			}
		}
	}

	// create heightmap
	mnbt_doc* doc = mnbt_new();
	mnbt_tag* tag = mnbt_new_tag(doc, UTL_CSTRTOARG(""), MNBT_COMPOUND, mnbt_val_compound());
	mnbt_push_tag(tag, mnbt_new_tag(doc, UTL_CSTRTOARG("MOTION_BLOCKING"), MNBT_LONG_ARRAY, mnbt_val_long_array(motion_blocking, 37)));
	mnbt_set_root(doc, tag);

	packet->cursor += mnbt_write(doc, (byte_t*) pck_cursor(packet), MNBT_NONE);

	mnbt_free(doc);

	// BIOMES

	pck_write_var_int(packet, chunk_height << 6);

	for (uint16_t i = 0; i < chunk_height; ++i) {
		for (uint8_t x = 0; x < 4; ++x) {
			for (uint8_t z = 0; z < 4; ++z) {
				for (uint8_t y = 0; y < 4; ++y) {
					pck_write_var_int(packet, chunk->sections[i].biome[(x << 4) + (z << 2) + y]);
				}
			}
		}
	}

	// CHUNK DATA

	// am i really gonna waste time copying data from one stream to another or am i gonna just waste 4 bytes?
	// you're damn right i'm gonna waste 4 bytes, speed is key
	// TODO chunk data
	const size_t data_len = packet->cursor;
	pck_write_long_var_int(packet, 0);

	const uint8_t bits_per_block = 15;

	for (uint16_t i = 0; i < chunk_height; ++i) {
		if (chunk->sections[i].block_count != 0) {
			pck_write_int16(packet, 0);
			pck_write_int8(packet, bits_per_block);
			pck_write_var_int(packet, 960);
			utl_bit_stream_t data_array = {
				.cursor = 0,
				.quads = (uint64_t*) pck_cursor(packet)
			};
			for (uint8_t x = 0; x < 16; ++x) {
				for (uint8_t z = 0; z < 16; ++z) {
					for (uint8_t y = 0; y < 16; ++y) {
						utl_write_bit_stream(&data_array, chunk->sections[i].blocks[(x << 8) + (z << 4) + y].state, bits_per_block);
					}
				}
			}
			packet->cursor += 960 * 8;
		}
	}

	const size_t current = packet->cursor;
	packet->cursor = data_len;
	pck_write_long_var_int(packet, current - data_len - 5);
	packet->cursor = current;
	
	// BLOCK ENTITIES
	// TODO block entities
	pck_write_var_int(packet, 0);

	ltg_send(client, packet);

}

void phd_send_update_light(ltg_client_t* client, wld_chunk_t* chunk) {

	PCK_INLINE(packet, 8192, io_big_endian);

	pck_write_var_int(packet, 0x25);
	pck_write_var_int(packet, wld_get_chunk_x(chunk));
	pck_write_var_int(packet, wld_get_chunk_z(chunk));

	pck_write_int8(packet, true); // trust edges
	
	pck_write_var_int(packet, 0); // sky light mask length

	pck_write_var_int(packet, 0); // block light mask length

	pck_write_var_int(packet, 0); // empty sky light mask length
	
	pck_write_var_int(packet, 0); // empty block light mask length
	
	pck_write_var_int(packet, 0); // sky light array count
	
	pck_write_var_int(packet, 0); // block light array count

	ltg_send(client, packet);

}

/**
 * @EntryPoint
 * This is the first function called in state play
 */
void phd_send_join_game(ltg_client_t* client) {

	wld_world_t* player_world = wld_get_default();

	// create an entity for the player
	ent_player_t* player = client->entity = calloc(1, sizeof(ent_player_t));
	player->living_entity.entity.type = ent_player;
	player->living_entity.entity.position.world = player_world;
	player->living_entity.entity.position.y = 256;
	player->living_entity.entity.position.x = player_world->spawn.x;
	player->living_entity.entity.position.z = player_world->spawn.z;
	ent_register_entity(&player->living_entity.entity);

	// set last recieve packet to now
	struct timespec time;
	clock_gettime(CLOCK_REALTIME, &time);
	client->last_recv = time.tv_sec * 1000 + time.tv_nsec / 0xF4240;

	JOB_CREATE_WORK(keep_alive, job_keep_alive);
	keep_alive->client = client;
	client->keep_alive = sch_schedule_repeating(&keep_alive->header, 200, 200);

	const mat_codec_t* codec = mat_get_codec();
	const mat_codec_t* dimension_codec = mat_get_dimension_codec(player_world->environment);

	PCK_INLINE(packet, codec->size + dimension_codec->size + 1024, io_big_endian);

	pck_write_var_int(packet, 0x26);
	pck_write_int32(packet, player->living_entity.entity.id); // entity ID
	pck_write_int8(packet, sky_main.hardcore);
	pck_write_int8(packet, sky_main.gamemode);
	pck_write_int8(packet, -1); // previous game mode

	// worlds
	uint16_t world_count = wld_get_count();
	pck_write_var_int(packet, world_count);
	for (size_t i = 0; i < world_count; ++i) {
		wld_world_t* world = wld_get_world(i);
		if (world != NULL) {
			pck_write_string(packet, world->name.value, world->name.length);
		} else {
			pck_write_string(packet, "", 0);
		}
	}

	pck_write_bytes(packet, codec->bytes, codec->size);
	pck_write_bytes(packet, dimension_codec->bytes, dimension_codec->size);

	pck_write_string(packet, player_world->name.value, player_world->name.length);
	
	// hash seed
	byte_t seed_hash[sha256_desc.hashsize];
	hash_state hash;
	sha256_init(&hash);
	sha256_process(&hash, (byte_t*) &player_world->seed, 8);
	sha1_done(&hash, seed_hash);

	pck_write_int64(packet, *((uint64_t*) seed_hash)); // hashed seed
	
	pck_write_var_int(packet, sky_main.listener.online.max);
	pck_write_var_int(packet, sky_main.render_distance); // view distance
	pck_write_int8(packet, sky_main.reduced_debug_info); // reduced debug info
	pck_write_int8(packet, sky_main.enable_respawn_screen); // enable respawn screen
	pck_write_int8(packet, player_world->debug); // is debug
	pck_write_int8(packet, player_world->flat); // is flat

	ltg_send(client, packet);

	// NORMAL LOGIN SEQUENCE
	phd_send_server_difficulty(client);
	phd_send_plugin_message(client, UTL_CSTRTOARG("minecraft:brand"), (const byte_t*) UTL_CSTRTOARG("\x07MotorMC"));
	phd_send_held_item_change(client);
	phd_send_declare_recipes(client);
	// TODO send tags
	phd_send_entity_status(client, player->living_entity.entity.id, 24); // TODO actual op level
	phd_send_declare_commands(client);
	phd_send_unlock_recipes(client);
	phd_send_player_position_and_look(client);
	phd_send_player_info_add_players(client);

	phd_send_update_view_position(client);
	phd_update_sent_chunks(client);

	// add to online players
	with_lock (&sky_main.listener.online.lock) {
		client->online_node = utl_dllist_push(&sky_main.listener.online.list, client);
	}

	JOB_CREATE_WORK(work, job_player_join);
	work->player = client;

	job_add(&work->header);

}

void phd_send_player_info_add_players(ltg_client_t* client) {

	with_lock (&sky_main.listener.online.lock) {

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
				pck_write_string(packet, UTL_CSTRTOARG("textures"));
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
			
			ent_player_t* player_ent = client->entity;

			with_lock (&player_ent->living_entity.entity.lock) {

				pck_write_var_int(packet, player_ent->gamemode); // game mode

			}
			
			pck_write_var_int(packet, player->ping); // ping
			pck_write_int8(packet, 0); // has display name
			node = node->next;
		}

		ltg_send(client, packet);

	}

}

void phd_send_player_info_add_player(ltg_client_t* client, ltg_client_t* player) {

	PCK_INLINE(packet, 2048, io_big_endian);
	pck_write_var_int(packet, 0x36);
	pck_write_var_int(packet, 0); // action
	pck_write_var_int(packet, 1); // number of players
	pck_write_bytes(packet, player->uuid, 16);
	pck_write_string(packet, player->username.value, player->username.length);
	if (player->textures.value.value != NULL) {
		pck_write_var_int(packet, 1);
		pck_write_string(packet, UTL_CSTRTOARG("textures"));
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
	ent_player_t* player_ent = player->entity;

	with_lock (&player_ent->living_entity.entity.lock) {
		pck_write_var_int(packet, player_ent->gamemode); // game mode
	}

	pck_write_var_int(packet, player->ping); // ping

	pck_write_int8(packet, 0); // has display name

	ltg_send(client, packet);

}

void phd_send_player_info_update_gamemode(__attribute__((unused)) ltg_client_t* client, __attribute__((unused)) ltg_client_t* player) {

}

void phd_send_player_info_update_latency(ltg_client_t* client) {

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

	ent_player_t* player = client->entity;

	with_lock (&player->living_entity.entity.lock) {

		pck_write_var_int(packet, 0x38);
		pck_write_float64(packet, player->living_entity.entity.position.x); // x
		pck_write_float64(packet, player->living_entity.entity.position.y); // y
		pck_write_float64(packet, player->living_entity.entity.position.z); // z
		pck_write_float32(packet, player->living_entity.rotation.pitch); // pitch
		pck_write_float32(packet, player->living_entity.rotation.yaw); // yaw
		pck_write_int8(packet, 0); // flags
		pck_write_var_int(packet, player->living_entity.entity.id); // teleport id
		pck_write_int8(packet, 0); // dismount vehicle

	}

	ltg_send(client, packet);

}

void phd_send_unlock_recipes(ltg_client_t* client) {

	PCK_INLINE(packet, 128, io_big_endian);

	// TODO add seperate functions for different packets,
	// make this packet actually do something

	pck_write_var_int(packet, 0x39);

	pck_write_var_int(packet, 0); // action

	pck_write_int8(packet, false); // crafting recipe book open
	pck_write_int8(packet, false); // crafting recipe book filter active
	pck_write_int8(packet, false); // smelting recipe book open
	pck_write_int8(packet, false); // smelting recipe book filter active
	pck_write_int8(packet, false); // blast furnace recipe book open
	pck_write_int8(packet, false); // blast furnace recipe book filter active
	pck_write_int8(packet, false); // smoker recipe book open
	pck_write_int8(packet, false); // smoker recipe book filter active
	
	pck_write_var_int(packet, 0); // array 1

	pck_write_var_int(packet, 0); // array 2

	ltg_send(client, packet);

}

void phd_send_held_item_change(ltg_client_t* client) {
	
	PCK_INLINE(packet, 2, io_big_endian);

	ent_player_t* player = client->entity;

	with_lock (&player->living_entity.entity.lock) {

		pck_write_var_int(packet, 0x48);
		pck_write_int8(packet, player->held_item);

	}

	ltg_send(client, packet);

}

void phd_send_update_view_position(ltg_client_t* client) {
	
	PCK_INLINE(packet, 11, io_big_endian);

	ent_player_t* player = client->entity;

	wld_chunk_t* chunk = NULL;

	with_lock (&player->living_entity.entity.lock) {
	
		chunk = player->living_entity.entity.chunk;
	
	}

	assert(chunk != NULL);

	pck_write_var_int(packet, 0x49);
	pck_write_var_int(packet, wld_get_chunk_x(chunk));
	pck_write_var_int(packet, wld_get_chunk_z(chunk));

	ltg_send(client, packet);

}

void phd_send_update_view_position_to(ltg_client_t* client, int32_t x, int32_t z) {
	
	PCK_INLINE(packet, 11, io_big_endian);
	
	pck_write_var_int(packet, 0x49);
	pck_write_var_int(packet, x);
	pck_write_var_int(packet, z);

	ltg_send(client, packet);

}

void phd_send_declare_recipes(ltg_client_t* client) {

	PCK_INLINE(packet, 6 + rec_recipes.size * 128, io_big_endian);
	
	pck_write_var_int(packet, 0x65);
	pck_write_var_int(packet, rec_recipes.size);

	for (size_t i = 0; i < rec_recipes.size; ++i) {

		rec_serialize(packet, UTL_VECTOR_GET_AS(rec_recipe_t*, &rec_recipes, i));

	}

	ltg_send(client, packet);

}

void phd_update_sent_chunks(ltg_client_t* client) {

	const wld_chunk_t* chunk = client->entity->living_entity.entity.chunk;

	for (int16_t x = -client->render_distance; x <= client->render_distance; ++x) {
		for (int16_t z = -client->render_distance; z <= client->render_distance; ++z) {
			wld_chunk_t* v_c = wld_relative_chunk(chunk, x, z);
			wld_subscribe_chunk(v_c, client->id);
		}
	}

}

void phd_update_sent_chunks_view_distance(ltg_client_t* client, uint8_t view_distance) {
	
	const wld_chunk_t* chunk = client->entity->living_entity.entity.chunk;

	if (client->render_distance > view_distance) {
		for (int16_t x = -client->render_distance; x <= client->render_distance; ++x) {
			for (int16_t z = -client->render_distance; z <= client->render_distance; ++z) {
				if (x < -view_distance || x > view_distance || z < -view_distance || z > view_distance) {
					wld_chunk_t* v_c = wld_relative_chunk(chunk, x, z);
					wld_unsubscribe_chunk(v_c, client->id);
				}
			}
		}
	} else if (client->render_distance < view_distance) {
		for (int16_t x = -view_distance; x <= view_distance; ++x) {
			for (int16_t z = -view_distance; z <= view_distance; ++z) {
				if (x < -client->render_distance || x > client->render_distance || z < -client->render_distance || z > client->render_distance) {
					wld_chunk_t* v_c = wld_relative_chunk(chunk, x, z);
					wld_subscribe_chunk(v_c, client->id);
				}
			}
		}
	}

}

void phd_update_sent_chunks_move(ltg_client_t* client, int32_t x, int32_t z) {

	const wld_chunk_t* old_chunk = client->entity->living_entity.entity.chunk;

	const int32_t old_x = wld_get_chunk_x(client->entity->living_entity.entity.chunk);
	const int32_t old_z = wld_get_chunk_z(client->entity->living_entity.entity.chunk);


	if (x > old_x) {

		const int32_t o_x = -client->render_distance;
		const int32_t n_x = client->render_distance + 1;

		for (int32_t c_z = -client->render_distance; c_z <= client->render_distance; ++c_z) {
			wld_unsubscribe_chunk(wld_relative_chunk(old_chunk, o_x, c_z), client->id);
			wld_subscribe_chunk(wld_relative_chunk(old_chunk, n_x, c_z), client->id);
		}

	}
	if (x < old_x) {

		const int32_t o_x = client->render_distance;
		const int32_t n_x = client->render_distance - 1;

		for (int32_t c_z = -client->render_distance; c_z <= client->render_distance; ++c_z) {
			wld_unsubscribe_chunk(wld_relative_chunk(old_chunk, o_x, c_z), client->id);
			wld_subscribe_chunk(wld_relative_chunk(old_chunk, n_x, c_z), client->id);
		}

	}

	if (z > old_z) {

		const int32_t o_z = client->render_distance;
		const int32_t n_z = client->render_distance + 1;
		
		for (int32_t c_x = -client->render_distance; c_x <= client->render_distance; ++c_x) {
			wld_unsubscribe_chunk(wld_relative_chunk(old_chunk, c_x, o_z), client->id);
			wld_subscribe_chunk(wld_relative_chunk(old_chunk, c_x, n_z), client->id);
		}

	}
	if (z < old_z) {

		const int32_t o_z = client->render_distance;
		const int32_t n_z = client->render_distance - 1;
		
		for (int32_t c_x = -client->render_distance; c_x <= client->render_distance; ++c_x) {
			wld_unsubscribe_chunk(wld_relative_chunk(old_chunk, c_x, o_z), client->id);
			wld_subscribe_chunk(wld_relative_chunk(old_chunk, c_x, n_z), client->id);
		}

	}

	return;

}

void phd_update_sent_chunks_leave(ltg_client_t* client) {
	
	const wld_chunk_t* chunk = client->entity->living_entity.entity.chunk;

	for (int16_t x = -client->render_distance; x <= client->render_distance; ++x) {
		for (int16_t z = -client->render_distance; z <= client->render_distance; ++z) {
			wld_chunk_t* v_c = wld_relative_chunk(chunk, x, z);
			wld_unsubscribe_chunk(v_c, client->id);
		}
	}

}