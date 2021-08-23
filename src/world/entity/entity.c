#include <pthread.h>
#include <stdlib.h>
#include "entity.h"
#include "../../util/id_vector.h"
#include "../../util/lock_util.h"
#include "../../motor.h"

struct {

	utl_id_vector_t entities;
	pthread_mutex_t lock;

} ent_entities = {
	.entities = {
		.bytes_per_element = sizeof(ent_entity_t*)
	},
	.lock = PTHREAD_MUTEX_INITIALIZER
};

uint32_t ent_register_entity(ent_entity_t* entity) {

	pthread_mutex_init(&entity->lock, NULL);
	
	with_lock (&entity->lock) {

		with_lock (&ent_entities.lock) {
			entity->id = utl_id_vector_add(&ent_entities.entities, &entity);
		}

		ent_set_chunk_l(entity);

	}

	return entity->id;

}

ent_entity_t* ent_get_entity_by_id(uint32_t id) {

	ent_entity_t* entity = NULL;
	with_lock (&ent_entities.lock) {
		entity = UTL_ID_VECTOR_GET_AS(ent_entity_t*, &ent_entities.entities, id);
	}

	return entity;

}

void ent_set_chunk_l(ent_entity_t* entity) {

	wld_chunk_t* chunk = NULL;

	if (entity->chunk != NULL) {

		// try relative
		int32_t o_x = wld_get_chunk_x(entity->chunk);
		int32_t o_z = wld_get_chunk_z(entity->chunk);
		int32_t n_x = ((int64_t) entity->position.x) >> 4;
		int32_t n_z = ((int64_t) entity->position.z) >> 4;

		if (UTL_ABS(n_x - o_x) < sky_main.render_distance && UTL_ABS(n_z - o_z) < sky_main.render_distance) {
			
			chunk = wld_relative_chunk(entity->chunk, n_x - o_x, n_z - o_z);
			
		} else { // set absolute (o(logn))

			chunk = wld_get_chunk_at(entity->position.world, (int64_t) entity->position.x, (int64_t) entity->position.z);
		}
		ent_remove_chunk_l(entity);
	} else {
		// set absolute (o(logn))
		chunk = wld_get_chunk_at(entity->position.world, (int64_t) entity->position.x, (int64_t) entity->position.z);
	}

	assert(chunk != NULL);

	with_lock (&chunk->lock) {

		entity->chunk_node = utl_dllist_push(&chunk->entities, entity);
	
	}

	entity->chunk = chunk;

}

void ent_free_entity(ent_entity_t* entity) {

	ent_remove_chunk(entity);

	with_lock (&ent_entities.lock) {
		utl_id_vector_remove(&ent_entities.entities, entity->id);
	}
	
	pthread_mutex_destroy(&entity->lock);
	free(entity);

}