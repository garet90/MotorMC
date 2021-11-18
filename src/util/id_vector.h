#pragma once
#include <stdlib.h>
#include "../main.h"
#include "vector.h"

typedef struct {

	utl_vector_t array;
	utl_vector_t next_id;
	uint32_t count;

} utl_id_vector_t;

#define UTL_ID_VECTOR_GET_AS(t, v, i) *((t*) utl_id_vector_get(v, i))
#define UTL_ID_VECTOR_INITIALIZER(type) { .array = UTL_VECTOR_INITIALIZER(type), .next_id = UTL_VECTOR_INITIALIZER(uint32_t), .count = 0 }

static inline utl_id_vector_t* utl_create_id_vector(uint32_t bytes_per_element) {

	utl_id_vector_t* id_vector = malloc(sizeof(utl_id_vector_t));
	utl_init_vector(&id_vector->array, bytes_per_element);
	utl_init_vector(&id_vector->next_id, sizeof(uint32_t));
	id_vector->count = 0;

	return id_vector;

}

static inline void utl_init_id_vector(utl_id_vector_t* id_vector, uint32_t bytes_per_element) {
	
	utl_init_vector(&id_vector->array, bytes_per_element);
	utl_init_vector(&id_vector->next_id, sizeof(uint32_t));
	id_vector->count = 0;

}

static inline void utl_id_vector_set(utl_id_vector_t* id_vector, uint32_t id, const void* element) {

	utl_vector_set(&id_vector->array, id, element);

}

static inline uint32_t utl_id_vector_push(utl_id_vector_t* id_vector, const void* element) {

	id_vector->count++;

	if (id_vector->next_id.size != 0) {
		uint32_t idx = UTL_VECTOR_GET_AS(uint32_t, &id_vector->next_id, 0);
		uint32_t last_idx = UTL_VECTOR_GET_AS(uint32_t, &id_vector->next_id, id_vector->next_id.size - 1);
		id_vector->next_id.size -= 1;
		utl_vector_set(&id_vector->next_id, 0, &last_idx);
		utl_id_vector_set(id_vector, idx, element);
		return idx;
	} else {
		utl_vector_push(&id_vector->array, element);
		return id_vector->array.size - 1;
	}

}

static inline void* utl_id_vector_get(const utl_id_vector_t* id_vector, uint32_t id) {
	
	if (id_vector == NULL) return NULL;

	return utl_vector_get(&id_vector->array, id);

}

static inline void utl_id_vector_remove(utl_id_vector_t* id_vector, uint32_t id) {

	byte_t* ptr = utl_vector_get(&id_vector->array, id);

	if (ptr == NULL) return;

	utl_vector_push(&id_vector->next_id, &id);
	memset(ptr, 0, id_vector->array.bytes_per_element);
	id_vector->count--;

}

static inline uint32_t utl_id_vector_count(const utl_id_vector_t* id_vector) {
	return id_vector->count;
}

static inline uint32_t utl_id_vector_length(const utl_id_vector_t* id_vector) {
	return utl_vector_size(&id_vector->array);
}

static inline void utl_term_id_vector(utl_id_vector_t* id_vector) {

	utl_term_vector(&id_vector->array);
	utl_term_vector(&id_vector->next_id);

}

static inline void utl_destroy_id_vector(utl_id_vector_t* id_vector) {

	utl_term_id_vector(id_vector);
	free(id_vector);

}