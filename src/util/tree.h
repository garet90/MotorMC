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

extern utl_tree_t* utl_createBranch(int64_t, void*);

static inline void utl_initBranch(utl_tree_t* branch, int64_t key, void* object) {
	branch->object = object;
	branch->key = key;
	branch->parent = NULL;
	branch->left = NULL;
	branch->right = NULL;
}

extern void utl_treePut(utl_tree_t*, int64_t, void*);
extern void* utl_treeGet(const utl_tree_t*, int64_t);
extern void utl_treeRemove(utl_tree_t*, int64_t);

extern void utl_treeTerm(utl_tree_t*);
extern void utl_treeDestroy(utl_tree_t*);

extern void* utl_treeShift(utl_tree_t*);
