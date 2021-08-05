#pragma once
#include "../main.h"

typedef struct utl_tree utl_tree_t;

struct utl_tree {

	int64_t key;
	void* object;

	utl_tree_t* parent;
	utl_tree_t* left; // utl_tree_t*
	utl_tree_t* right; // utl_tree_t*

};

extern utl_tree_t* utl_create_branch(int64_t, void*);

static inline void utl_init_branch(utl_tree_t* branch, int64_t key, void* object) {
	branch->object = object;
	branch->key = key;
	branch->parent = NULL;
	branch->left = NULL;
	branch->right = NULL;
}

extern void utl_tree_put(utl_tree_t*, int64_t, void*);
extern void* utl_tree_get(const utl_tree_t*, int64_t);
extern void utl_tree_remove(utl_tree_t*, int64_t);

extern void utl_tree_term(utl_tree_t*);
extern void utl_tree_destroy(utl_tree_t*);

extern void* utl_tree_shift(utl_tree_t*);
