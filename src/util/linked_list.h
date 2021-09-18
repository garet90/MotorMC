#pragma once
#include "../main.h"
#include "id_vector.h"

typedef struct {

	void* element;
	uint32_t next;

} utl_list_node_t;

typedef struct {

	utl_id_vector_t nodes;
	uint32_t first;
	uint32_t last;
	uint32_t length;

} utl_list_t;

#define UTL_LIST_INITIALIZER { .nodes = UTL_ID_VECTOR_INITIALIZER(utl_list_node_t), .first = 0, .last = 0, .length = 0 }

static inline utl_list_t* utl_create_list() {

	utl_list_t* list = calloc(1, sizeof(utl_list_t));
	utl_init_id_vector(&list->nodes, sizeof(utl_list_node_t));

	return list;

}

static inline void utl_init_list(utl_list_t* list) {

	memset(list, 0, sizeof(utl_list_t));
	utl_init_id_vector(&list->nodes, sizeof(utl_list_node_t));

}

static inline void utl_list_push(utl_list_t* list, void* element) {

	// create node
	const utl_list_node_t node_init = {
		.element = element
	};

	uint32_t node_id = utl_id_vector_push(&list->nodes, &node_init);
	utl_list_node_t* last = utl_id_vector_get(&list->nodes, list->last);

	last->next = list->last = node_id;
	list->length++;

}

static inline void* utl_list_shift(utl_list_t* list) {

	utl_list_node_t* node = utl_id_vector_get(&list->nodes, list->first);
	uint32_t node_id = list->first;
	list->first = node->next;
	list->length--;

	void* element = node->element;
	utl_id_vector_remove(&list->nodes, node_id);

	return element;

}

static inline void utl_term_list(utl_list_t* list) {

	utl_term_id_vector(&list->nodes);

}

static inline void utl_destroy_list(utl_list_t* list) {

	utl_term_list(list);
	free(list);

}