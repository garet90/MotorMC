#pragma once
#include "../main.h"
#include "id_vector.h"

typedef struct {

	void* element;
	uint32_t previous;
	uint32_t next;

} utl_dll_node_t;

typedef struct {

	utl_id_vector_t nodes;
	uint32_t first;
	uint32_t last;
	uint32_t length;

} utl_dll_t;

typedef struct {

	utl_dll_t* dll;
	uint32_t node;

} utl_dll_iterator_t;

#define UTL_DLL_INITIALIZER { .nodes = UTL_ID_VECTOR_INITIALIZER(utl_dll_node_t), .first = 0, .last = 0, .length = 0 }

static inline utl_dll_t* utl_create_dll() {

	utl_dll_t* dll = calloc(1, sizeof(utl_dll_t));
	utl_init_id_vector(&dll->nodes, sizeof(utl_dll_node_t));

	return dll;

}

static inline void utl_init_dll(utl_dll_t* dll) {

	memset(dll, 0, sizeof(utl_dll_t));
	utl_init_id_vector(&dll->nodes, sizeof(utl_dll_node_t));

}

// TODO make list updatable while iterating through
static inline utl_dll_iterator_t utl_dll_get_iterator(utl_dll_t* dll) {
	return (utl_dll_iterator_t) {
		.dll = dll,
		.node = 0xFFFFFFFF
	};
}

static inline void* utl_dll_iterator_next(utl_dll_iterator_t* iterator) {

	if (iterator->node == iterator->dll->last) return NULL;

	if (iterator->node == 0xFFFFFFFF) {
		if (iterator->dll->length == 0) return NULL;
		iterator->node = iterator->dll->first;
	} else {
		utl_dll_node_t* last_node = utl_id_vector_get(&iterator->dll->nodes, iterator->node);
		iterator->node = last_node->next;
	}

	utl_dll_node_t* node = utl_id_vector_get(&iterator->dll->nodes, iterator->node);
	iterator->node = node->next;

	return node->element;

}

extern uint32_t utl_dll_push(utl_dll_t* dll, void* element);

static inline void* utl_dll_shift(utl_dll_t* dll) {

	utl_dll_node_t* node = utl_id_vector_get(&dll->nodes, dll->first);
	uint32_t node_id = dll->first;
	dll->first = node->next;
	dll->length--;

	void* element = node->element;
	utl_id_vector_remove(&dll->nodes, node_id);

	return element;

}

extern void* utl_dll_remove(utl_dll_t* dll, uint32_t id);

static inline uint32_t utl_dll_length(utl_dll_t* dll) {
	return dll->length;
}

static inline void utl_term_dll(utl_dll_t* dll) {

	utl_term_id_vector(&dll->nodes);

}

static inline void utl_destroy_dll(utl_dll_t* dll) {

	utl_term_dll(dll);
	free(dll);

}