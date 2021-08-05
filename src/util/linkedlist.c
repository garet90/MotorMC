#include <stdlib.h>
#include "linkedlist.h"

utl_linked_list_t* utl_create_list() {
	utl_linked_list_t* list = malloc(sizeof(utl_linked_list_t));
	utl_init_list(list);
	return list;
}

utl_linked_node_t* utl_create_node() {

	utl_linked_node_t* node = malloc(sizeof(utl_linked_node_t));
	node->element = NULL;
	node->next = NULL;
	return node;

}

void utl_list_push(utl_linked_list_t* list, void* element) {

	utl_linked_node_t* node = utl_create_node();
	node->element = element;

	if (list->first == NULL) {
		list->first = node;
		list->last = node;
	} else {
		list->last->next = node;
		list->last = node;
	}

	list->length += 1;

}

void* utl_list_shift(utl_linked_list_t* list) {

	if (list->first == NULL) return NULL;

	utl_linked_node_t* node = list->first;
	list->first = NULL;

	if (node->next == NULL) list->last = NULL;

	void* element = node->element;

	free(node);

	list->length -= 1;

	return element;

}
