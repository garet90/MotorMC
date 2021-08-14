#include <stdlib.h>
#include <string.h>
#include "bit_vector.h"

void utl_bit_vector_set_bit(utl_bit_vector_t* vector, uint32_t bit) {

	const uint32_t byte = bit >> 3;
	bit &= 0x7;

	if (byte >= vector->capacity) {
		
		if (vector->capacity == 0) {
			
			vector->capacity = byte << 1;
			vector->array = calloc(vector->capacity, sizeof(byte_t));

		} else {

			const size_t old_cap = vector->capacity;
			vector->capacity = byte << 1;
			vector->array = realloc(vector->array, vector->capacity);
			memset(vector->array + old_cap, 0, vector->capacity - old_cap);

		}

	}

	vector->array[byte] |= (1 << bit);

}

void utl_bit_vector_reset_bit(utl_bit_vector_t* vector, uint32_t bit) {

	const uint32_t byte = bit >> 3;
	bit &= 0x7;

	if (byte >= vector->capacity) return;

	vector->array[byte] &= ~(1 << bit);

}

void utl_bit_vector_foreach(utl_bit_vector_t* vector, void (*function) (uint32_t, void*), void* input) {

	const byte_t ffs[] = {
		0, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2,
		0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0,
		1, 0, 2, 0, 1, 0, 5, 0, 1, 0, 2, 0, 1,
		0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0,
		2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 6,
		0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0,
		1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1,
		0, 2, 0, 1, 0, 5, 0, 1, 0, 2, 0, 1, 0,
		3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2,
		0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 7, 0,
		1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1,
		0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0,
		2, 0, 1, 0, 5, 0, 1, 0, 2, 0, 1, 0, 3,
		0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0,
		1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 6, 0, 1,
		0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
		4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2,
		0, 1, 0, 5, 0, 1, 0, 2, 0, 1, 0, 3, 0,
		1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1,
		0, 3, 0, 1, 0, 2, 0, 1, 0
	};

	for (uint32_t i = 0; i < vector->capacity; ++i) {
		
		byte_t byte = vector->array[i];

		while (byte) {
			function((i << 3) + ffs[byte], input);
			byte &= byte - 1;
		}

	}

}

void utl_bit_vector_term(utl_bit_vector_t* vector) {
	if (vector != NULL) {
		free(vector->array);
		vector->capacity = 0;
	}
}