#include "id_vector.h"
#include <stdlib.h>
#include <string.h>

uint32_t utl_id_vector_add(utl_id_vector_t* vector, const void* element) {
    
    uint32_t id;
    if (vector->next_id_size == 0) {
        id = vector->size;
    } else {
        id = vector->next_id[0];
        vector->next_id[0] = vector->next_id[--vector->next_id_size];
    }
    
    utl_id_vector_set(vector, id, element);

    return id;

}

void utl_id_vector_set(utl_id_vector_t* vector, uint32_t id, const void* element) {

	if (id >= vector->capacity) {
		utl_id_vector_resize(vector, (id > 0 ? id * 2 : 2));
	}

    if (id >= vector->size) {
        vector->size = id + 1;
    }
    
	memcpy(vector->array + (vector->bytes_per_element * id), element, vector->bytes_per_element);

}

void utl_id_vector_remove(utl_id_vector_t* vector, uint32_t id) {

    if (vector->next_id_size >= vector->next_id_capacity) {
        utl_id_vector_resize_ids(vector, (vector->next_id_capacity > 0 ? vector->next_id_capacity * 2 : 2));
    }

    vector->next_id[vector->next_id_size++] = id;
    memset(vector->array + (vector->bytes_per_element * id), 0, vector->bytes_per_element);

}

void utl_id_vector_resize(utl_id_vector_t* vector, uint32_t capacity) {

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

void utl_id_vector_resize_ids(utl_id_vector_t* vector, uint32_t capacity) {
    
    if (vector->next_id_capacity != 0) {
        vector->next_id = realloc(vector->next_id, sizeof(uint32_t) * capacity);
    } else {
        vector->next_id = malloc(sizeof(uint32_t) * capacity);
    }
    vector->next_id_capacity = capacity;

}

void utl_id_vector_term(utl_id_vector_t* vector) {
    free(vector->array);
    free(vector->next_id);
}