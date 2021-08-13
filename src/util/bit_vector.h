#pragma once
#include "../main.h"

typedef struct {

	byte_t* array;
	size_t capacity;

} utl_bit_vector_t;

static inline bool_t utl_bit_vector_test_bit(utl_bit_vector_t* vector, uint32_t bit) {

    const uint32_t byte = bit >> 3;
    bit &= 0x7;

    if (byte >= vector->capacity) {
        return false;
    } else {
        return (vector->array[byte] & (1 << bit)) ? true : false;
    }

}

extern void utl_bit_vector_set_bit(utl_bit_vector_t* vector, uint32_t bit);
extern void utl_bit_vector_reset_bit(utl_bit_vector_t* vector, uint32_t bit);
extern void utl_bit_vector_foreach(utl_bit_vector_t* vector, void (*function) (uint32_t, void*), void* input);
extern void utl_bit_vector_term(utl_bit_vector_t* vector);