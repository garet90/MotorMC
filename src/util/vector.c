#include <string.h>
#include <stdlib.h>
#include "vector.h"

utl_vector_t* utl_createVector(size_t bpe, size_t capacity) {

	utl_vector_t* vector = malloc(sizeof(utl_vector_t));

	utl_initVector(vector, bpe, capacity);

	return vector;

}

void utl_initVector(utl_vector_t* vector, size_t bpe, size_t capacity) {

	vector->bytes_per_element = bpe;
	vector->capacity = capacity;
	vector->size = 0;
	vector->array = malloc(bpe * capacity);

}

void utl_vectorPush(utl_vector_t* vector, const void* element) {

	if (vector->size >= vector->capacity) {
		utl_vectorResize(vector, (vector->size > 0 ? vector->size * 2 : 2));
	}

	memcpy(vector->array + (vector->bytes_per_element * vector->size++), element, vector->bytes_per_element);

}

void utl_vectorShift(utl_vector_t* vector) {

	if (vector == NULL) return;

	if (vector->size > 0) {

		vector->size -= 1;
		if (vector->size > 0) {

			memmove(vector->array, vector->array + vector->bytes_per_element, vector->bytes_per_element * vector->size);

		}

	}

}

void utl_vectorSet(utl_vector_t* vector, size_t i, const void* value) {

	memcpy(vector->array + (vector->bytes_per_element * i), value, vector->bytes_per_element);

}

void utl_vectorResize(utl_vector_t* vector, size_t capacity) {

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

void utl_vectorTerm(utl_vector_t* vector) {

	free(vector->array);
	vector->capacity = 0;

}

void utl_vectorDestroy(utl_vector_t* vector) {

	utl_vectorTerm(vector);
	free(vector);

}
