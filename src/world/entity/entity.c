#include <pthread.h>
#include "entity.h"
#include "../../util/vector.h"
#include "../../util/linkedlist.h"

struct {

    utl_vector_t entities;
    utl_vector_t to_remove;
    utl_linked_list_t next_id;
    pthread_mutex_t lock;

} ent_entities = {
    .entities = {
        .bytes_per_element = sizeof(ent_entity_t*)
    },
    .lock = PTHREAD_MUTEX_INITIALIZER
};

uint32_t ent_register_entity(ent_entity_t* entity) {

    pthread_mutex_lock(&ent_entities.lock);

    uint32_t id;

    if (ent_entities.next_id.length > 0) {

        id = (uint32_t) ((uint64_t) utl_list_shift(&ent_entities.next_id));
        utl_vector_set(&ent_entities.entities, id, &entity);

    } else {

        id = ent_entities.entities.size;
        utl_vector_push(&ent_entities.entities, &entity);

    }

    pthread_mutex_unlock(&ent_entities.lock);

	pthread_mutex_init(&entity->lock, NULL);
    entity->entity_id = id;
    return id;

}

ent_entity_t* ent_get_entity_by_id(uint32_t id) {

    pthread_mutex_lock(&ent_entities.lock);

    ent_entity_t* entity = UTL_VECTOR_GET_AS(ent_entity_t*, &ent_entities.entities, id);

    pthread_mutex_unlock(&ent_entities.lock);

    return entity;

}

void ent_free_entity(ent_entity_t* entity) {

    pthread_mutex_lock(&ent_entities.lock);

    void* null = NULL;
    utl_vector_set(&ent_entities.entities, entity->entity_id, &null);

    utl_list_push(&ent_entities.next_id, ((byte_t*) 0) + entity->entity_id);
    
    pthread_mutex_unlock(&ent_entities.lock);

    pthread_mutex_destroy(&entity->lock);
    free(entity);

}