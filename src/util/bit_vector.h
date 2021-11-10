#pragma once
#include <pthread.h>
#include "../main.h"
#include "util.h"
#include "vector.h"
#include "lock_util.h"

typedef struct {

	utl_vector_t vector;

} utl_bit_vector_t;

#define UTL_BIT_VECTOR_INITIALIZER { .vector = UTL_VECTOR_INITIALIZER(byte_t) }

static inline utl_bit_vector_t* utl_create_bit_vector() {

	utl_bit_vector_t* vector = malloc(sizeof(utl_bit_vector_t));
	utl_init_vector(&vector->vector, sizeof(byte_t));

	return vector;

}

static inline void utl_init_bit_vector(utl_bit_vector_t* vector) {

	utl_init_vector(&vector->vector, sizeof(byte_t));

}

static inline bool utl_bit_vector_test_bit(utl_bit_vector_t* vector, uint32_t bit) {

	if (vector->vector.size > (bit >> 3)) {

		const byte_t byte = UTL_VECTOR_GET_AS(byte_t, &vector->vector, bit >> 3);
		
		return ((byte & 0x7) | (1 << bit)) ? true : false;

	}

	return false;

}

static inline void utl_bit_vector_expand(utl_bit_vector_t* vector, uint32_t to) {

	if (vector->vector.capacity <= to) {

		utl_vector_resize(&vector->vector, (to + 1) * 2);

	}

	if (vector->vector.size <= to) {
		
		memset(vector->vector.array + vector->vector.size, 0, to + 1);
		vector->vector.size = to + 1;

	}

}

static inline void utl_bit_vector_set_bit(utl_bit_vector_t* vector, uint32_t bit) {
	
	utl_bit_vector_expand(vector, bit >> 3);

	byte_t* byte = utl_vector_get(&vector->vector, bit >> 3);

	*byte |= (1 << (bit & 0x7));

}

static inline void utl_bit_vector_reset_bit(utl_bit_vector_t* vector, uint32_t bit) {
	
	utl_bit_vector_expand(vector, bit >> 3);

	byte_t* byte = utl_vector_get(&vector->vector, bit >> 3);

	*byte &= ~(1 << (bit & 0x7));

}

static const byte_t utl_ffs[] = {
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

static inline void utl_bit_vector_foreach(utl_bit_vector_t* vector, void (*const function) (uint32_t, void*), void* input) {

	const uint32_t size = vector->vector.size;

	for (uint32_t i = 0; i < size; ++i) {
		
		byte_t byte = UTL_VECTOR_GET_AS(byte_t, &vector->vector, i);

		while (byte) {
			function((i << 3) + utl_ffs[byte], input);
			byte &= byte - 1;
		}

	}

}

static inline void utl_bit_vector_lock_foreach(utl_bit_vector_t* vector, pthread_mutex_t* mutex, void (*const function) (uint32_t, void*), void* input) {

	pthread_mutex_lock(mutex);
	
	const uint32_t size = vector->vector.size;

	for (uint32_t i = 0; i < size; ++i) {
			
		byte_t byte = UTL_VECTOR_GET_AS(byte_t, &vector->vector, i);

		pthread_mutex_unlock(mutex);

		while (byte) {
			function((i << 3) + utl_ffs[byte], input);
			byte &= byte - 1;
		}

		pthread_mutex_lock(mutex);

	}

	pthread_mutex_unlock(mutex);

}

static inline void utl_bit_vector_or_foreach(utl_bit_vector_t* v1, utl_bit_vector_t* v2, void (*const function) (uint32_t, void*), void* input) {
	
	const uint32_t size = UTL_MAX(v1->vector.size, v2->vector.size);

	for (uint32_t i = 0; i < size; ++i) {
		
		byte_t byte = 0;

		if (i < v1->vector.size) {
			byte |= UTL_VECTOR_GET_AS(byte_t, &v1->vector, i);
		}
		if (i < v2->vector.size) {
			byte |= UTL_VECTOR_GET_AS(byte_t, &v2->vector, i);
		}

		while (byte) {
			function((i << 3) + utl_ffs[byte], input);
			byte &= byte - 1;
		}

	}

}

static inline void utl_bit_vector_xor_foreach(utl_bit_vector_t* v1, utl_bit_vector_t* v2, pthread_mutex_t* m1, pthread_mutex_t* m2, void (*const function) (uint32_t, void*), void* input) {
	
	const uint32_t size = UTL_MAX(v1->vector.size, v2->vector.size);

	for (uint32_t i = 0; i < size; ++i) {
		
		byte_t byte = 0;

		if (i < v1->vector.size) {
			with_lock (m1) {
				byte ^= UTL_VECTOR_GET_AS(byte_t, &v1->vector, i);
			}
		}
		if (i < v2->vector.size) {
			with_lock (m2) {
				byte ^= UTL_VECTOR_GET_AS(byte_t, &v2->vector, i);
			}
		}

		while (byte) {
			function((i << 3) + utl_ffs[byte], input);
			byte &= byte - 1;
		}

	}

}

static inline void utl_term_bit_vector(utl_bit_vector_t* vector) {

	utl_term_vector(&vector->vector);

}

static inline void utl_destroy_bit_vector(utl_bit_vector_t* vector) {

	utl_term_bit_vector(vector);
	free(vector);

}