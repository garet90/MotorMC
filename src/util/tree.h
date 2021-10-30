#pragma once
#include "../main.h"
#include "id_vector.h"

#define UTL_TREE_NULL 0xFFFFFFFF

typedef struct {

	void* value;
	uint32_t key;

	uint32_t parent;
	uint32_t left;
	uint32_t right;

} utl_tree_branch_t;

typedef struct {

	utl_id_vector_t nodes;
	uint32_t root;
	uint32_t length;

} utl_tree_t;

#define UTL_TREE_INITIALIZER { .nodes = UTL_ID_VECTOR_INITIALIZER(utl_tree_branch_t), .root = UTL_TREE_NULL, .length = 0 }

static inline utl_tree_t* utl_create_tree() {

	utl_tree_t* tree = calloc(1, sizeof(utl_tree_t));
	tree->root = UTL_TREE_NULL;
	utl_init_id_vector(&tree->nodes, sizeof(utl_tree_branch_t));

	return tree;

}

static inline void utl_init_tree(utl_tree_t* tree) {

	memset(tree, 0, sizeof(utl_tree_t));
	tree->root = UTL_TREE_NULL;
	utl_init_id_vector(&tree->nodes, sizeof(utl_tree_branch_t));

}

extern void utl_tree_put(utl_tree_t* tree, uint32_t key, void* value);

extern void* utl_tree_get(const utl_tree_t* tree, uint32_t key);

extern void utl_tree_remove(utl_tree_t* tree, uint32_t key);

extern void* utl_tree_shift(utl_tree_t* tree);

static inline void utl_term_tree(utl_tree_t* tree) {
	
	utl_term_id_vector(&tree->nodes);

}

static inline void utl_destroy_tree(utl_tree_t* tree) {

	utl_term_tree(tree);
	free(tree);

}
