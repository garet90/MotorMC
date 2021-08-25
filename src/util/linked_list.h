#pragma once
#include "../main.h"

typedef struct utl_linked_node utl_linked_node_t;

struct utl_linked_node {

	void* _Atomic element;
	utl_linked_node_t* _Atomic next;

};

typedef struct {

	utl_linked_node_t* _Atomic first;
	utl_linked_node_t* _Atomic last;
	_Atomic size_t length;

} utl_linked_list_t;

extern utl_linked_list_t* utl_create_list();

static inline void utl_init_list(utl_linked_list_t* list) {
	list->first = NULL;
	list->last = NULL;
	list->length = 0;
}

extern utl_linked_node_t* utl_create_node();
extern utl_linked_node_t* utl_list_push(utl_linked_list_t*, void*);
extern void* utl_list_shift(utl_linked_list_t*);
