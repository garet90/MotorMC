#include <stdlib.h>
#include "doubly_linked_list.h"

utl_doubly_linked_list_t* utl_create_dllist() {
	utl_doubly_linked_list_t* list = calloc(1, sizeof(utl_doubly_linked_list_t));
	return list;
}

utl_doubly_linked_node_t* utl_create_dlnode() {

	utl_doubly_linked_node_t* node = calloc(1, sizeof(utl_doubly_linked_node_t));
	return node;

}

utl_doubly_linked_node_t* utl_dllist_push(utl_doubly_linked_list_t* list, void* element) {

	utl_doubly_linked_node_t* node = utl_create_dlnode();
	node->element = element;

	if (list->first == NULL) {
		list->first = node;
		list->last = node;
	} else {
		list->last->next = node;
        node->previous = list->last;
		list->last = node;
	}

	list->length += 1;

    return node;

}

void* utl_dllist_shift(utl_doubly_linked_list_t* list) {

	if (list->first == NULL) return NULL;

	utl_doubly_linked_node_t* node = list->first;
	list->first = node->next;
    node->next->previous = NULL;

	if (node->next == NULL) list->last = NULL;

	void* element = node->element;

	free(node);

	list->length -= 1;

	return element;

}

void utl_list_doubly_remove_by_reference(utl_doubly_linked_list_t* list, utl_doubly_linked_node_t* node) {

	if (node->previous != NULL) {
		node->previous->next = node->next;
	} else {
		list->first = node->next;
	}
	if (node->next != NULL) {
		node->next->previous = node->previous;
	} else {
		list->last = node->previous;
	}

	list->length -= 1;

	free(node);

}