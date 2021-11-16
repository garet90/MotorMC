#pragma once
#include <string.h>
#include <stdlib.h>
#include "../main.h"

typedef struct {

	byte_t* array;
	uint32_t size;
	uint32_t capacity;
	const uint32_t bytes_per_element; // bytes per element

} utl_vector_t;

#define UTL_VECTOR_GET_AS(t, v, i) *((t*) utl_vector_get(v, i))
#define UTL_VECTOR_SHIFT_AS(t, v) *((t*) utl_vector_shift(v))

#define UTL_VECTOR_INITIALIZER(type) (utl_vector_t) { .array = NULL, .size = 0, .capacity = 0, .bytes_per_element = sizeof(type) }
#define UTL_VECTOR_DEFAULT(name, type, ...) const type name ##_default[] = {__VA_ARGS__}; utl_vector_t name = { .array = (byte_t*) name ##_default, .size = sizeof(name ##_default) / sizeof(name ##_default[0]), .capacity = 0, .bytes_per_element = sizeof(type) };

static inline utl_vector_t* utl_create_vector(uint32_t bytes_per_element, uint32_t capacity) {
	
	utl_vector_t* vector = malloc(sizeof(utl_vector_t));

	utl_vector_t init = {
		.array = malloc((size_t) capacity * bytes_per_element),
		.size = 0,
		.capacity = capacity,
		.bytes_per_element = bytes_per_element
	};

	memcpy(vector, &init, sizeof(utl_vector_t));

	return vector;

}

static inline void utl_init_vector(utl_vector_t* vector, uint32_t bytes_per_element) {

	utl_vector_t init = {
		.array = NULL,
		.size = 0,
		.capacity = 0,
		.bytes_per_element = bytes_per_element
	};

	memcpy(vector, &init, sizeof(utl_vector_t));

}

static inline void utl_vector_resize(utl_vector_t* vector, uint32_t new_capacity) {
	
	if (vector->capacity != 0) {
		vector->array = realloc(vector->array, (size_t) vector->bytes_per_element * new_capacity);
	} else {
		if (vector->size > 0) {
			void* newarr = malloc((size_t) vector->bytes_per_element * new_capacity);
			memcpy(newarr, vector->array, (size_t) vector->bytes_per_element * vector->size);
			vector->array = newarr;
		} else {
			vector->array = malloc((size_t) vector->bytes_per_element * new_capacity);
		}
	}
	vector->capacity = new_capacity;

}

static inline void* utl_vector_push(utl_vector_t* vector, const void* element) {
	
	if (vector->size >= vector->capacity) {
		utl_vector_resize(vector, (vector->size > 0 ? vector->size * 2 : 2));
	}

	void* ptr = vector->array + (vector->bytes_per_element * vector->size++);
	memcpy(ptr, element, vector->bytes_per_element);

	return ptr;

}

static inline void* utl_vector_get(const utl_vector_t* vector, uint32_t idx) {
	
	if (vector == NULL) return NULL;

	if (idx > vector->size) return NULL;

	return (vector->array + (vector->bytes_per_element * idx));

}

static inline void utl_vector_shift(utl_vector_t* vector) {
	
	if (vector == NULL) return;

	if (vector->size > 0) {

		vector->size -= 1;
		if (vector->size > 0) {

			memmove(vector->array, vector->array + vector->bytes_per_element, (size_t) vector->bytes_per_element * vector->size);

		}

	}

}

static inline void utl_vector_set(utl_vector_t* vector, uint32_t idx, const void* value) {

	memcpy(vector->array + (vector->bytes_per_element * idx), value, vector->bytes_per_element);

}

static inline uint32_t utl_vector_size(const utl_vector_t* vector) {
	return vector->size;
}

static inline void utl_term_vector(utl_vector_t* vector) {

	if (vector->capacity > 0) {
		free(vector->array);
		vector->capacity = 0;
		vector->size = 0;
	}

}

static inline void utl_destroy_vector(utl_vector_t* vector) {

	utl_term_vector(vector);
	free(vector);

}
