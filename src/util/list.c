#include "list.h"

void utl_list_push(utl_list_t* list, void* element) {

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