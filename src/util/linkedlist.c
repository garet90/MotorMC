#include <stdlib.h>
#include "linkedlist.h"

utl_linked_list_t* utl_createList() {
	utl_linked_list_t* list = malloc(sizeof(utl_linked_list_t));
	utl_initList(list);
	return list;
}

utl_linked_node_t* utl_createNode() {

	utl_linked_node_t* node = malloc(sizeof(utl_linked_node_t));
	node->element = NULL;
	node->next = NULL;
	return node;

}

void utl_listPush(utl_linked_list_t* list, void* element) {

	utl_linked_node_t* node = utl_createNode();
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

void* utl_listShift(utl_linked_list_t* list) {

	if (list->first == NULL) return NULL;

	utl_linked_node_t* node = list->first;
	list->first = NULL;

	if (node->next == NULL) list->last = NULL;

	void* element = node->element;

	free(node);

	list->length -= 1;

	return element;

}
