#pragma once
#include "../main.h"

typedef struct {

	_Atomic byte_t* array;
	_Atomic size_t size;
	_Atomic size_t capacity;
	const size_t bytes_per_element; // bytes per element

} utl_vector_t;

#define UTL_VECTOR_GET_AS(t, v, i) *((t*) utl_vector_get(v, i))
#define UTL_VECTOR_SHIFT_AS(t, v) *((t*) utl_vector_shift(v))

extern utl_vector_t* utl_create_vector(size_t, size_t);

extern void* utl_vector_push(utl_vector_t*, const void*);
static inline void* utl_vector_get(const utl_vector_t* vector, size_t idx) {
	
	if (vector == NULL) return NULL;

	return (vector->array + (vector->bytes_per_element * idx));

}
extern void utl_vector_shift(utl_vector_t*);
extern void utl_vector_set(utl_vector_t*, size_t, const void*);

extern void utl_vector_resize(utl_vector_t*, size_t);

extern void utl_vector_term(utl_vector_t*);
extern void utl_vector_destroy(utl_vector_t*);
