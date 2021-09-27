#pragma once
#include "../main.h"
#include "id_vector.h"

typedef struct {

	uint32_t next;
	byte_t element[];

} utl_list_node_t;

typedef struct {

	utl_id_vector_t nodes;
	uint32_t first;
	uint32_t last;
	uint32_t length;

} utl_list_t;

#define UTL_LIST_INITIALIZER(type) { .nodes = { .array = { .array = NULL, .size = 0, .capacity = 0, .bytes_per_element = (sizeof(utl_list_node_t) + sizeof(type)) }, .next_id = UTL_VECTOR_INITIALIZER(uint32_t) }, .first = 0, .last = 0, .length = 0 }

static inline void utl_init_list(utl_list_t* list, uint32_t bytes_per_element) {

	utl_list_t init = {
		.nodes = {
			.array = {
				.array = NULL,
				.size = 0,
				.capacity = 0,
				.bytes_per_element = (sizeof(utl_list_node_t) + bytes_per_element)
			},
			.next_id = UTL_VECTOR_INITIALIZER(uint32_t)
		},
		.first = 0,
		.last = 0,
		.length = 0
	};

	memcpy(list, &init, sizeof(utl_list_t));

}

static inline utl_list_t* utl_create_list(uint32_t bytes_per_element) {

	utl_list_t* list = malloc(sizeof(utl_list_t));
	utl_init_list(list, bytes_per_element);

	return list;

}

static inline void utl_list_push(utl_list_t* list, void* element) {

	// create node
	byte_t bytes[list->nodes.array.bytes_per_element];
	utl_list_node_t* node = (utl_list_node_t*) bytes;
	memcpy(node->element, element, list->nodes.array.bytes_per_element - sizeof(utl_list_node_t));

	// add node to nodes and get last
	uint32_t node_id = utl_id_vector_push(&list->nodes, node);

	if (list->length != 0) {

		utl_list_node_t* last = utl_id_vector_get(&list->nodes, list->last);

		// set last node to new node
		last->next = node_id;
	
	} else {
		
		list->first = node_id;

	}

	list->last = node_id;
	list->length++;

}

static inline void* utl_list_first(utl_list_t* list) {

	utl_list_node_t* node = utl_id_vector_get(&list->nodes, list->first);

	return node->element;

}

static inline void utl_list_shift(utl_list_t* list) {

	uint32_t node_id = list->first;
	utl_list_node_t* node = utl_id_vector_get(&list->nodes, node_id);
	list->first = node->next;
	list->length--;

	utl_id_vector_remove(&list->nodes, node_id);

}

static inline void utl_term_list(utl_list_t* list) {

	utl_term_id_vector(&list->nodes);

}

static inline void utl_destroy_list(utl_list_t* list) {

	utl_term_list(list);
	free(list);

}