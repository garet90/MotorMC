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

extern utl_doubly_linked_list_t* utl_create_dllist();

static inline void utl_init_dllist(utl_doubly_linked_list_t* list) {
	list->first = NULL;
	list->last = NULL;
	list->length = 0;
}

extern utl_doubly_linked_node_t* utl_create_dlnode();
extern utl_doubly_linked_node_t* utl_dllist_push(utl_doubly_linked_list_t*, void*);
extern void* utl_dllist_shift(utl_doubly_linked_list_t*);
extern void utl_dllist_remove_by_reference(utl_doubly_linked_list_t* list, utl_doubly_linked_node_t* node);
