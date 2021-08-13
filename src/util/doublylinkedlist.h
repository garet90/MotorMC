#pragma once
#include "../main.h"

typedef struct utl_doubly_linked_node utl_doubly_linked_node_t;

struct utl_doubly_linked_node {

	utl_doubly_linked_node_t* previous;
	void* element;
	utl_doubly_linked_node_t* next;

};

typedef struct {

	utl_doubly_linked_node_t* first;
	utl_doubly_linked_node_t* last;
	size_t length;

} utl_doubly_linked_list_t;

extern utl_doubly_linked_list_t* utl_create_doubly_list();

static inline void utl_init_doubly_list(utl_doubly_linked_list_t* list) {
	list->first = NULL;
	list->last = NULL;
	list->length = 0;
}

extern utl_doubly_linked_node_t* utl_create_doubly_node();
extern utl_doubly_linked_node_t* utl_list_doubly_push(utl_doubly_linked_list_t*, void*);
extern void* utl_list_doubly_shift(utl_doubly_linked_list_t*);
extern void utl_list_doubly_remove_by_reference(utl_doubly_linked_list_t* list, utl_doubly_linked_node_t* node);
