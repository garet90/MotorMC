#pragma once
#include "../main.h"

typedef struct {

	byte_t* array;
	size_t size;
	size_t capacity;
	size_t bytes_per_element; // bytes per element

} utl_vector_t;

#define utl_vectorGetAs(t, v, i) *((t*) utl_vectorGet(v, i))
#define utl_vectorShiftAs(t, v) *((t*) utl_vectorShift(v))

extern utl_vector_t* utl_createVector(size_t, size_t);
extern void utl_initVector(utl_vector_t*, size_t, size_t);

extern void utl_vectorPush(utl_vector_t*, const void*);
static inline void* utl_vectorGet(const utl_vector_t* vector, size_t idx) {
	
	if (vector == NULL) return NULL;

	return (vector->array + (vector->bytes_per_element * idx));

}
extern void utl_vectorShift(utl_vector_t*);
extern void utl_vectorSet(utl_vector_t*, size_t, const void*);

extern void utl_vectorResize(utl_vector_t*, size_t);

extern void utl_vectorTerm(utl_vector_t*);
extern void utl_vectorDestroy(utl_vector_t*);
