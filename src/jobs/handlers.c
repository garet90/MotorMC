#include <time.h>
#include "handlers.h"
#include "../listening/phd/play.h"
#include "../io/chat/translation.h"
#include "../io/logger/logger.h"
#include "../motor.h"
#include "../world/entity/living/player/player.h"

bool job_handle_keep_alive(job_payload_t* payload) {
	
	// what if the client disconnects by the time this is handled? TODO

	struct timespec time;
	clock_gettime(CLOCK_REALTIME, &time);
	const int64_t out_ms = time.tv_sec * 1000 + time.tv_nsec / 0xF4240;

	if (out_ms - ltg_client_get_last_receive(payload->client) >= 30000) {
		ltg_disconnect(payload->client);
		return false;
	} else {
		phd_send_keep_alive(payload->client, out_ms);
		if (ltg_client_get_entity(payload->client) != NULL) {
			ent_le_damage(ent_player_get_le(ltg_client_get_entity(payload->client)), NULL, 5);
		}
		return true;
	}

}

bool job_handle_global_chat_message(job_payload_t* payload) {

	// what if the client disconnects by the time this is handled? TODO

	log_info("<%s> %s", UTL_STRTOCSTR(ltg_client_get_username(payload->global_chat_message.client)), UTL_STRTOCSTR(payload->global_chat_message.message));

	cht_translation_t translation = cht_translation_new;
	translation.translate = cht_translation_chat_type_text;
	cht_component_t name = cht_new;
	name.text = ltg_client_get_username(payload->global_chat_message.client);
	cht_component_t message = cht_new;
	message.text = payload->global_chat_message.message;
	cht_add_with(&translation, &name);
	cht_add_with(&translation, &message);

	char out[1536];
	const size_t out_len = cht_write_translation(&translation, out);

	const uint32_t online_length = ltg_get_online_length(sky_get_listener());
	for (uint32_t i = 0; i < online_length; ++i) {
		ltg_client_t* client = ltg_get_online_client(sky_get_listener(), i);
		if (client != NULL) {
			phd_send_chat_message(client, out, out_len, ltg_client_get_uuid(payload->global_chat_message.client));
		}
	}
	cht_term_translation(&translation);

	free(payload->global_chat_message.message.value);
	return true;

}

static inline void job_send_entity(uint32_t client_id, void* entity) {

	ltg_client_t* client = ltg_get_client_by_id(sky_get_listener(), client_id);

	if (client == NULL) return;

	phd_update_send_entity(client, (ent_entity_t*) entity);

}

bool job_handle_player_join(job_payload_t* payload) {
	
	// what if the client disconnects by the time this is handled? TODO

	log_info("%s joined the game", UTL_STRTOCSTR(ltg_client_get_username(payload->client)));

	cht_translation_t translation = cht_translation_new;
	translation.translate = cht_translation_multiplayer_player_joined;
	translation.color = cht_yellow;
	cht_component_t name = cht_new;
	name.text = ltg_client_get_username(payload->client);
	cht_add_with(&translation, &name);

	char out[128];
	const size_t out_len = cht_write_translation(&translation, out);
	// lock client vector
	const uint32_t online_length = ltg_get_online_length(sky_get_listener());
	for (uint32_t i = 0; i < online_length; ++i) {
		ltg_client_t* client = ltg_get_online_client(sky_get_listener(), i);
		if (client != NULL) {
			phd_send_player_info_add_player(client, payload->client);
			phd_send_system_chat_message(client, out, out_len);
		}
	}

	cht_term_translation(&translation);

	ent_entity_t* entity = ent_player_get_entity(ltg_client_get_entity(payload->client));

	wld_chunk_subscribers_foreach(ent_get_chunk(entity), job_send_entity, entity);

	return true;

}

bool job_handle_player_leave(job_payload_t* payload) {

	log_info("%s left the game", payload->player_leave.username);

	cht_translation_t translation = cht_translation_new;
	translation.translate = cht_translation_multiplayer_player_left;
	translation.color = cht_yellow;
	cht_component_t name = cht_new;
	name.text = (string_t) {
		.value = payload->player_leave.username,
		.length = payload->player_leave.username_length
	};
	cht_add_with(&translation, &name);

	char out[128];
	const size_t out_len = cht_write_translation(&translation, out);
	
	const uint32_t online_length = ltg_get_online_length(sky_get_listener());
	for (uint32_t i = 0; i < online_length; ++i) {
		ltg_client_t* client = ltg_get_online_client(sky_get_listener(), i);
		if (client != NULL) {
			phd_send_player_info_remove_player(client, payload->player_leave.uuid);
			phd_send_system_chat_message(client, out, out_len);
		}
	}

	cht_term_translation(&translation);

	return true;

}

bool job_handle_send_update_pings(__attribute__((unused)) job_payload_t* payload) {

	const uint32_t online_length = ltg_get_online_length(sky_get_listener());
	for (uint32_t i = 0; i < online_length; ++i) {
		ltg_client_t* client = ltg_get_online_client(sky_get_listener(), i);
		if (client != NULL) {
			phd_send_player_info_update_latency(client);
		}
	}

	return true;

}

bool job_handle_tick_region(job_payload_t* payload) {

	// TODO what if this region is unloaded by the time this is handled?
	
	for (uint32_t i = 0; i < 32 * 32; ++i) {

		const wld_chunk_t* chunk = wld_region_get_chunk_by_idx(payload->region, i);

		if (chunk != NULL) {
			if (wld_chunk_get_ticket(chunk) <= WLD_TICKET_TICK_ENTITIES) {
				// entities and chunk ticks
			}

			if (wld_chunk_get_ticket(chunk) <= WLD_TICKET_TICK) {
				// tick
			}

			if (wld_chunk_get_ticket(chunk) <= WLD_TICKET_BORDER) {
				// border
			}
		}
	}

	return true;

}

bool job_handle_unload_region(job_payload_t* payload) {

	// what if this region is unloaded by the time this is handled?

	if (wld_region_get_loaded_chunks(payload->region) == 0) {
		wld_unload_region(payload->region);
		return true;
	}

	return false;

}

bool job_handle_dig_block(job_payload_t* payload) {

	// what if the client disconnects by the time this is handled TODO

	ent_player_t* player = ltg_client_get_entity(payload->dig_block.client);

	if (ent_player_is_digging_block(player)) {
		ent_player_stop_digging_block(player);
	} else {
		return false;
	}

	// break block
	wld_set_block_type_at(payload->dig_block.chunk, payload->dig_block.x, payload->dig_block.y, payload->dig_block.z, mat_block_air);

	return true;

}

static inline void job_update_entity_move(uint32_t client_id, void* args) {
	
	job_payload_t* payload = args;
	ent_entity_t* entity = payload->entity_move.entity;
	
	ltg_client_t* client = ltg_get_client_by_id(sky_get_listener(), client_id);

	if (client == NULL) return;
	
	if (ent_get_type(entity) == ent_player && ent_player_get_entity(ltg_client_get_entity(client)) == entity) {
		if (ent_get_chunk(entity) != payload->entity_move.initial_chunk) {
			phd_update_sent_chunks_move(payload->entity_move.initial_chunk, client);
		}
	} else {
		phd_send_entity_position(client, entity, payload->entity_move.d_x, payload->entity_move.d_y, payload->entity_move.d_z);
	}

}

bool job_handle_entity_move(job_payload_t* payload) {
	
	// what if the entity has been destroyed by the time this is handled? TODO

	ent_entity_t* entity = payload->entity_move.entity;

	// why not +=?
	// well, Atomic implementations vary from PC to PC and operating system to operating system,
	// and additions on floats are not very commonly implemented, but set usually is
	entity->position.x = entity->position.x + payload->entity_move.d_x;
	entity->position.y = entity->position.y + payload->entity_move.d_y;
	entity->position.z = entity->position.z + payload->entity_move.d_z;

	entity->on_ground = payload->entity_move.on_ground;

	// TODO physics

	if (!wld_in_chunk(ent_get_chunk(entity), ent_get_block_x(entity), ent_get_block_z(entity))) {
		// change chunk
		ent_set_chunk(entity);
	}

	wld_chunk_t* chunk = ent_get_chunk(entity);
	wld_chunk_subscribers_foreach(chunk, job_update_entity_move, payload);

	return true;

}

static inline void job_update_entity_teleport(uint32_t client_id, void* args) {
	
	job_payload_t* payload = args;
	ent_entity_t* entity = payload->entity_teleport.entity;
	
	ltg_client_t* client = ltg_get_client_by_id(sky_get_listener(), client_id);
	
	if (client == NULL) return;
	
	if (ent_get_type(entity) == ent_player && ent_player_get_entity(ltg_client_get_entity(client)) == entity) {
		if (ent_get_chunk(entity) != payload->entity_teleport.initial_chunk) {
			// TODO phd_update_sent_chunks_teleport(client);
		}
	} else {
		// TODO entering chunks, leaving chunks, etc
	}

}

bool job_handle_entity_teleport(job_payload_t* payload) {

	ent_entity_t* entity = payload->entity_teleport.entity;

	entity->position.world = payload->entity_teleport.world;
	entity->position.x = payload->entity_teleport.x;
	entity->position.y = payload->entity_teleport.y;
	entity->position.z = payload->entity_teleport.z;
	
	ent_remove_chunk(entity);

	entity->on_ground = false;

	// TODO physics
	
	if (!wld_in_chunk(ent_get_chunk(entity), ent_get_block_x(entity), ent_get_block_z(entity))) {
		// change chunk
		ent_set_chunk(entity);
	}

	wld_chunk_t* chunk = ent_get_chunk(entity);
	wld_chunk_subscribers_foreach(chunk, job_update_entity_teleport, payload);

	return true;

}

static inline void job_update_living_entity_look(uint32_t client_id, void* args) {
	
	job_payload_t* payload = args;
	ent_living_entity_t* entity = payload->living_entity_look.entity;
	
	ltg_client_t* client = ltg_get_client_by_id(sky_get_listener(), client_id);
	
	if (client == NULL) return;

	if (ent_get_type(ent_le_get_entity(entity)) == ent_player && ent_player_get_le(ltg_client_get_entity(client)) == entity) {
		// Do nothing
	} else {
		phd_send_entity_rotation(client, entity);
		phd_send_entity_head_look(client, entity);
	}

}

bool job_handle_living_entity_look(job_payload_t* payload) {

	ent_living_entity_t* entity = payload->living_entity_look.entity;

	entity->rotation.yaw = payload->living_entity_look.yaw;
	entity->rotation.pitch = payload->living_entity_look.pitch;

	entity->entity.on_ground = payload->living_entity_look.on_ground;

	wld_chunk_t* chunk = ent_get_chunk(ent_le_get_entity(entity));
	wld_chunk_subscribers_foreach(chunk, job_update_living_entity_look, payload);

	return true;

}

static inline void job_update_living_entity_move_look(uint32_t client_id, void* args) {

	job_payload_t* payload = args;
	ent_living_entity_t* entity = payload->living_entity_move_look.entity;

	ltg_client_t* client = ltg_get_client_by_id(sky_get_listener(), client_id);
	
	if (client == NULL) return;

	if (ent_get_type(ent_le_get_entity(entity)) == ent_player && ent_player_get_le(ltg_client_get_entity(client)) == entity) {
		if (ent_get_chunk(ent_le_get_entity(entity)) != payload->living_entity_move_look.initial_chunk) {
			phd_update_sent_chunks_move(payload->living_entity_move_look.initial_chunk, client);
		}
	} else {
		phd_send_entity_position_and_rotation(client, entity, payload->living_entity_move_look.d_x, payload->living_entity_move_look.d_y, payload->living_entity_move_look.d_z);
		phd_send_entity_head_look(client, entity);
	}
	
}

bool job_handle_living_entity_move_look(job_payload_t* payload) {

	ent_living_entity_t* entity = payload->living_entity_move_look.entity;

	entity->entity.position.x = entity->entity.position.x + payload->living_entity_move_look.d_x;
	entity->entity.position.y = entity->entity.position.y + payload->living_entity_move_look.d_y;
	entity->entity.position.z = entity->entity.position.z + payload->living_entity_move_look.d_z;

	entity->rotation.yaw = payload->living_entity_move_look.yaw;
	entity->rotation.pitch = payload->living_entity_move_look.pitch;

	entity->entity.on_ground = payload->living_entity_move_look.on_ground;

	// TODO physics

	if (!wld_in_chunk(ent_get_chunk(ent_le_get_entity(entity)), ent_get_block_x(ent_le_get_entity(entity)), ent_get_block_z(ent_le_get_entity(entity)))) {
		// change chunk
		ent_set_chunk(ent_le_get_entity(entity));
	}

	wld_chunk_t* chunk = ent_get_chunk(ent_le_get_entity(entity));
	wld_chunk_subscribers_foreach(chunk, job_update_living_entity_move_look, payload);

	return true;

}

static inline void job_update_living_entity_teleport_look(uint32_t client_id, void* args) {
	
	job_payload_t* payload = args;
	ent_living_entity_t* entity = payload->living_entity_teleport_look.entity;
	
	ltg_client_t* client = ltg_get_client_by_id(sky_get_listener(), client_id);
	
	if (client == NULL) return;
	
	if (ent_get_type(ent_le_get_entity(entity)) == ent_player && ent_player_get_le(ltg_client_get_entity(client)) == entity) {
		if (ent_get_chunk(ent_le_get_entity(entity)) != payload->living_entity_teleport_look.initial_chunk) {
			// TODO phd_update_sent_chunks_teleport(client);
		}
	} else {
		// TODO phd_send_entity_teleport_look(...)
	}

}

bool job_handle_living_entity_teleport_look(job_payload_t* payload) {

	ent_living_entity_t* entity = payload->living_entity_teleport_look.entity;

	entity->entity.position.world = payload->living_entity_teleport_look.world;

	entity->entity.position.x = payload->living_entity_teleport_look.x;
	entity->entity.position.y = payload->living_entity_teleport_look.y;
	entity->entity.position.z = payload->living_entity_teleport_look.z;

	entity->rotation.yaw = payload->living_entity_teleport_look.yaw;
	entity->rotation.pitch = payload->living_entity_teleport_look.pitch;

	entity->entity.on_ground = false;
	
	ent_remove_chunk(ent_le_get_entity(entity));

	// TODO physics

	if (!wld_in_chunk(ent_get_chunk(ent_le_get_entity(entity)), ent_get_block_x(ent_le_get_entity(entity)), ent_get_block_z(ent_le_get_entity(entity)))) {
		// change chunk
		ent_set_chunk(ent_le_get_entity(entity));
	}

	wld_chunk_t* chunk = ent_get_chunk(ent_le_get_entity(entity));
	wld_chunk_subscribers_foreach(chunk, job_update_living_entity_teleport_look, payload);

	return true;

}

static inline void job_update_living_entity_damage(uint32_t client_id, void* args) {

	job_payload_t* payload = args;
	ent_living_entity_t* entity = payload->living_entity_damage.entity;

	ltg_client_t* client = ltg_get_client_by_id(sky_get_listener(), client_id);
	
	if (client == NULL) return;

	phd_send_entity_status(client, ent_le_get_entity(entity), 2);
	
	if (payload->living_entity_damage.damage > 0 && ent_get_type(ent_le_get_entity(entity)) == ent_player && ent_player_get_le(ltg_client_get_entity(client)) == entity) {
		phd_send_update_health(client);
	}

}

bool job_handle_living_entity_damage(job_payload_t* payload) {

	ent_living_entity_t* entity = payload->living_entity_damage.entity;

	entity->health = entity->health - payload->living_entity_damage.damage;

	// play hurt animation
	wld_chunk_subscribers_foreach(ent_get_chunk(ent_le_get_entity(entity)), job_update_living_entity_damage, payload);

	return true;

}

bool job_handle_tick_world(job_payload_t* payload) {

	wld_world_t* world = payload->world;

	world->age++;
	
	if (wld_is_time_progressing(world)) {
		world->time++;
		if (world->time >= 24000) {
			world->time = 0;
		}
	}
	
	return true;

}