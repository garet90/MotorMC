#include <pthread.h>
#include <stdlib.h>
#include "entity.h"
#include "../../util/id_vector.h"
#include "../../util/lock_util.h"
#include "../../motor.h"
#include "../../jobs/scheduler/scheduler.h"
#include "../../listening/phd/play.h"

utl_id_vector_t ent_entities = UTL_ID_VECTOR_INITIALIZER(ent_entity_t*);

uint32_t ent_register_entity(ent_entity_t* entity) {
	
	uint32_t id = utl_id_vector_push(&ent_entities, &entity);
	memcpy((uint32_t*) &entity->id, &id, sizeof(id));

	pthread_mutex_init(&entity->lock, NULL);
	
	ent_set_chunk(entity);

	return entity->id;

}

ent_entity_t* ent_get_entity_by_id(uint32_t id) {

	ent_entity_t* entity = UTL_ID_VECTOR_GET_AS(ent_entity_t*, &ent_entities, id);

	return entity;

}

static inline void ent_send_entity(uint32_t client_id, void* entity) {

	ltg_client_t* client = ltg_get_client_by_id(sky_get_listener(), client_id);

	if (client == NULL) return;

	phd_update_send_entity(client, (ent_entity_t*) entity);

}

static inline void ent_destroy_entity(uint32_t client_id, void* entity) {

	ltg_client_t* client = ltg_get_client_by_id(sky_get_listener(), client_id);

	if (client == NULL) return;

	phd_send_destroy_entity(client, (ent_entity_t*) entity);

}

static inline void ent_send_destroy_entity(uint32_t client_id, void* entity) {

	wld_chunk_t* entity_chunk = ((ent_entity_t*) entity)->chunk;

	if (wld_chunk_has_subscriber(entity_chunk, client_id)) {
		ent_send_entity(client_id, entity);
	} else {
		ent_destroy_entity(client_id, entity);
	}

}

void ent_set_chunk(ent_entity_t* entity) {

	wld_chunk_t* chunk = NULL;

	const int64_t f_x = ent_get_block_x(entity);
	const int64_t f_z = ent_get_block_z(entity);

	if (ent_get_chunk(entity) != NULL) {

		wld_chunk_t* entity_chunk = ent_get_chunk(entity);

		// try relative
		int32_t o_x = wld_get_chunk_x(entity_chunk);
		int32_t o_z = wld_get_chunk_z(entity_chunk);
		int32_t n_x = f_x >> 4;
		int32_t n_z = f_z >> 4;

		const uint8_t server_render_distance = sky_get_render_distance();

		if (UTL_ABS(n_x - o_x) < server_render_distance && UTL_ABS(n_z - o_z) < server_render_distance) {
			
			chunk = wld_relative_chunk(entity_chunk, n_x - o_x, n_z - o_z);
			
		} else { // set absolute (o(logn))

			chunk = wld_get_chunk_at(ent_get_world(entity), f_x, f_z);

		}

		// update players around
		wld_chunk_subscribers_xor_foreach(entity_chunk, chunk, ent_send_destroy_entity, entity);
		ent_remove_chunk(entity);

	} else {
		// set absolute (o(logn))
		chunk = wld_get_chunk_at(ent_get_world(entity), f_x, f_z);
		
		// if its a player, we must wait until it has been added to the server list
		if (ent_get_type(entity) != ent_player) {
			// spawn in chunk to listeners
			wld_chunk_subscribers_foreach(chunk, ent_send_entity, entity);
		}
	}

	assert(chunk != NULL);

	with_lock (&entity->lock) {
		entity->chunk_node = wld_chunk_add_entity(chunk, entity);
		entity->chunk = chunk;
	}

}

void ent_free_entity(ent_entity_t* entity) {

	// remove entity from clients
	wld_chunk_subscribers_foreach(ent_get_chunk(entity), ent_destroy_entity, entity);

	ent_remove_chunk(entity);

	utl_id_vector_remove(&ent_entities, entity->id);

	pthread_mutex_destroy(&entity->lock);

	free(entity);

}

void ent_free(ent_entity_t* entity) {

	switch (entity->type) {
		case ent_player: {
			ent_free_player((ent_player_t*) entity);
		} break;
		default: {
			ent_free_entity(entity);
		}
	}

}