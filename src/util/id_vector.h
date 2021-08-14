#pragma once
#include "../main.h"

typedef struct {

	byte_t* array;

	uint32_t* next_id;
	uint32_t next_id_size;
	uint32_t next_id_capacity;

	uint32_t size;
	uint32_t capacity;
	uint32_t bytes_per_element; // bytes per element

} utl_id_vector_t;

#define UTL_ID_VECTOR_GET_AS(t, v, i) *((t*) utl_id_vector_get(v, i))

extern uint32_t utl_id_vector_add(utl_id_vector_t* vector, const void* element);
static inline void* utl_id_vector_get(const utl_id_vector_t* vector, size_t idx) {
	
	if (vector == NULL) return NULL;

	return (vector->array + (vector->bytes_per_element * idx));

}
extern void utl_id_vector_set(utl_id_vector_t* vector, uint32_t id, const void* element);

extern void utl_id_vector_remove(utl_id_vector_t* vector, uint32_t id);

extern void utl_id_vector_resize(utl_id_vector_t* vector, uint32_t new_size);
extern void utl_id_vector_resize_ids(utl_id_vector_t* vector, uint32_t new_size);

extern void utl_id_vector_term(utl_id_vector_t* vector);
