#include <pthread.h>
#include "entity.h"
#include "../../util/id_vector.h"

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

	pthread_mutex_lock(&ent_entities.lock);

	uint32_t id = utl_id_vector_add(&ent_entities.entities, &entity);

	pthread_mutex_unlock(&ent_entities.lock);

	entity->chunk = wld_get_chunk_at(entity->position.world, entity->position.x, entity->position.z);
	pthread_mutex_init(&entity->lock, NULL);
	entity->id = id;
	return id;

}

ent_entity_t* ent_get_entity_by_id(uint32_t id) {

	pthread_mutex_lock(&ent_entities.lock);

	ent_entity_t* entity = UTL_ID_VECTOR_GET_AS(ent_entity_t*, &ent_entities.entities, id);

	pthread_mutex_unlock(&ent_entities.lock);

	return entity;

}

void ent_free_entity(ent_entity_t* entity) {

	pthread_mutex_lock(&ent_entities.lock);

	utl_id_vector_remove(&ent_entities.entities, entity->id);
	
	pthread_mutex_unlock(&ent_entities.lock);
	
	pthread_mutex_destroy(&entity->lock);
	free(entity);

}