#include <stdlib.h>
#include "linkedlist.h"

utl_linked_list_t* utl_create_list() {
	utl_linked_list_t* list = calloc(1, sizeof(utl_linked_list_t));
	return list;
}

utl_linked_node_t* utl_create_node() {

	utl_linked_node_t* node = calloc(1, sizeof(utl_linked_node_t));
	return node;

}

utl_linked_node_t* utl_list_push(utl_linked_list_t* list, void* element) {

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

	return node;

}

void* utl_list_shift(utl_linked_list_t* list) {

	if (list->first == NULL) return NULL;

	utl_linked_node_t* node = list->first;
	list->first = node->next;

	if (node->next == NULL) list->last = NULL;

	void* element = node->element;

	free(node);

	list->length -= 1;

	return element;

}
