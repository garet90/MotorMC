#include <string.h>
#include <stdlib.h>
#include "vector.h"

utl_vector_t* utl_create_vector(size_t bpe, size_t capacity) {

	utl_vector_t* vector = malloc(sizeof(utl_vector_t));

	utl_init_vector(vector, bpe, capacity);

	return vector;

}

void utl_init_vector(utl_vector_t* vector, size_t bpe, size_t capacity) {

	vector->bytes_per_element = bpe;
	vector->capacity = capacity;
	vector->size = 0;
	vector->array = malloc(bpe * capacity);

}

void* utl_vector_push(utl_vector_t* vector, const void* element) {

	if (vector->size >= vector->capacity) {
		utl_vector_resize(vector, (vector->size > 0 ? vector->size * 2 : 2));
	}

	void* ptr = vector->array + (vector->bytes_per_element * vector->size++);
	memcpy(ptr, element, vector->bytes_per_element);

	return ptr;

}

void utl_vector_shift(utl_vector_t* vector) {

	if (vector == NULL) return;

	if (vector->size > 0) {

		vector->size -= 1;
		if (vector->size > 0) {

			memmove(vector->array, vector->array + vector->bytes_per_element, vector->bytes_per_element * vector->size);

		}

	}

}

void utl_vector_set(utl_vector_t* vector, size_t i, const void* value) {

	memcpy(vector->array + (vector->bytes_per_element * i), value, vector->bytes_per_element);

}

void utl_vector_resize(utl_vector_t* vector, size_t capacity) {

	if (vector->capacity != 0) {
		vector->array = realloc(vector->array, vector->bytes_per_element * capacity);
	} else {
		if (vector->size > 0) {
			void* newarr = malloc(vector->bytes_per_element * capacity);
			memcpy(newarr, vector->array, vector->bytes_per_element * vector->size);
			vector->array = newarr;
		} else {
			vector->array = malloc(vector->bytes_per_element * capacity);
		}
	}
	vector->capacity = capacity;

}

void utl_vector_term(utl_vector_t* vector) {

	if (vector->capacity > 0) {
		free(vector->array);
		vector->capacity = 0;
		vector->size = 0;
	}

}

void utl_vector_destroy(utl_vector_t* vector) {

	utl_vector_term(vector);
	free(vector);

}
