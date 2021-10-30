#include "dll.h"

uint32_t utl_dll_push(utl_dll_t* dll, void* element) {

	if (dll->length == 0) {
		
		const utl_dll_node_t node = {
			.element = element
		};

		uint32_t node_id = utl_id_vector_push(&dll->nodes, &node);
		dll->first = node_id;
		dll->last = node_id;
		dll->length++;

		return node_id;

	} else {
		
		const utl_dll_node_t node = {
			.element = element,
			.previous = dll->last
		};
		
		uint32_t node_id = utl_id_vector_push(&dll->nodes, &node);
		utl_dll_node_t* last = utl_id_vector_get(&dll->nodes, dll->last);

		last->next = node_id;
		dll->last = node_id;
		dll->length++;

		return node_id;

	}

}

void* utl_dll_remove(utl_dll_t* dll, uint32_t id) {

	utl_dll_node_t* node = utl_id_vector_get(&dll->nodes, id);
	if (id != dll->first) {
		utl_dll_node_t* previous = utl_id_vector_get(&dll->nodes, node->previous);
		previous->next = node->next;
	} else {
		dll->first = node->next;
	}
	if (id != dll->last) {
		utl_dll_node_t* next = utl_id_vector_get(&dll->nodes, node->next);
		next->previous = node->previous;
	} else {
		dll->last = node->previous;
	}
	dll->length--;

	void* element = node->element;
	utl_id_vector_remove(&dll->nodes, id);

	return element;

}