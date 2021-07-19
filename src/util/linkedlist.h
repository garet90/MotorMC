#pragma once
#include "../main.h"

typedef struct utl_linked_node utl_linked_node_t;

struct utl_linked_node {

	utl_linked_node_t* element;
	utl_linked_node_t* next;

};

typedef struct {

	utl_linked_node_t* first;
	utl_linked_node_t* last;
	size_t length;

} utl_linked_list_t;

extern utl_linked_list_t* utl_createList();

static inline void utl_initList(utl_linked_list_t* list) {
	list->first = NULL;
	list->last = NULL;
	list->length = 0;
}

extern utl_linked_node_t* utl_createNode();
extern void utl_listPush(utl_linked_list_t*, void*);
extern void* utl_listShift(utl_linked_list_t*);
