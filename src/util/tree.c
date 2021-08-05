#include <stdlib.h>
#include "tree.h"

utl_tree_t* utl_create_branch(int64_t key, void* object) {

	utl_tree_t* branch = malloc(sizeof(utl_tree_t));

	utl_init_branch(branch, key, object);

	return branch;

}

void utl_tree_put(utl_tree_t* tree, int64_t key, void* object) {

	if (tree->object == NULL) {
		tree->object = object;
		tree->key = key;
		return;
	}

	if (tree->key < key) {

		if (tree->left == NULL) {

			tree->left = utl_create_branch(key, object);

		} else {

			utl_tree_put(tree->left, key, object);

		}

	} else if (tree->key > key) {

		if (tree->right == NULL) {

			tree->right = utl_create_branch(key, object);

		} else {

			utl_tree_put(tree->right, key, object);

		}

	}

}

void* utl_tree_get(const utl_tree_t* tree, int64_t key) {

	if (tree == NULL) return NULL;

	if (tree->key == key) {

		return tree->object;

	} else if (tree->key < key) {

		if (tree->left != NULL) {

			return utl_tree_get(tree->left, key);

		} else {

			return NULL;

		}

	} else if (tree->key > key) {

		if (tree->right != NULL) {

			return utl_tree_get(tree->right, key);

		} else {

			return NULL;

		}

	}

	return NULL;

}

void utl_tree_remove(utl_tree_t* tree, int64_t key) {

	if (tree->key == key) {

		if (tree->left == NULL && tree->right == NULL) {

			utl_tree_t* parent = tree->parent;

			if (parent->left == tree) {

				parent->left = NULL;

			} else {

				parent->right = NULL;

			}

			free(tree);

		} else if (tree->left != NULL && tree->right != NULL) {

			utl_tree_t* successor = tree->right;

			while (successor->left != NULL) {
				successor = successor->left;
			}

			int64_t nkey = successor->key;
			void* nobject = successor->object;

			utl_tree_remove(tree, nkey);

			tree->key = nkey;
			tree->object = nobject;

		} else if (tree->left != NULL) {

			utl_tree_t* branch = tree->left;

			tree->left = branch->left;
			tree->right = branch->right;
			tree->key = branch->key;
			tree->object = branch->object;

			free(branch);

		} else if (tree->right != NULL) {

			utl_tree_t* branch = tree->right;

			tree->left = branch->left;
			tree->right = branch->right;
			tree->key = branch->key;
			tree->object = branch->object;

			free(branch);

		}

	} else if (tree->key < key) {

		utl_tree_remove(tree->left, key);

	} else if (tree->key > key) {

		utl_tree_remove(tree->right, key);

	}

}

void utl_tree_term(utl_tree_t* tree) {

	if (tree->left != NULL) {

		utl_tree_destroy(tree->left);

	}

	if (tree->right != NULL) {

		utl_tree_destroy(tree->right);

	}

}

void utl_tree_destroy(utl_tree_t* tree) {

	if (tree->left != NULL) {

		utl_tree_destroy(tree->left);

	}

	if (tree->right != NULL) {

		utl_tree_destroy(tree->right);

	}

	free(tree);

}

void* utl_treeShiftL1(utl_tree_t* tree, utl_tree_t* branch) {

	if (branch->left != NULL) {

		return utl_treeShiftL1(tree, branch->left);

	} else if (branch->right != NULL) {

		return utl_treeShiftL1(tree, branch->right);

	} else {

		void* object = branch->object;
		utl_tree_remove(tree, branch->key);
		return object;

	}

}

void* utl_tree_shift(utl_tree_t* tree) {

	if (tree->left != NULL) {

		return utl_treeShiftL1(tree, tree->left);

	} else if (tree->right != NULL) {

		return utl_treeShiftL1(tree, tree->right);

	}

	return NULL;

}
