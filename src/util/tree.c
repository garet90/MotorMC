#include "tree.h"

void utl_tree_put(utl_tree_t* tree, uint32_t key, void* value) {

	if (tree->length == 0) {
		// set root node to current node
		const utl_tree_branch_t branch = {
			.key = key,
			.value = value,
			.left = UTL_TREE_NULL,
			.right = UTL_TREE_NULL,
			.parent = UTL_TREE_NULL
		};

		tree->length++;
		tree->root = utl_id_vector_push(&tree->nodes, &branch);

	} else {
		// find where to put this branch
		uint32_t look_idx = tree->root;

		for (;;) {

			utl_tree_branch_t* look = utl_id_vector_get(&tree->nodes, look_idx);

			if (key > look->key) {

				if (look->right == UTL_TREE_NULL) {

					// create a right branch
					const utl_tree_branch_t branch = {
						.key = key,
						.value = value,
						.left = UTL_TREE_NULL,
						.right = UTL_TREE_NULL,
						.parent = look_idx
					};
					
					tree->length++;
					const uint32_t idx = utl_id_vector_push(&tree->nodes, &branch);
					// get look again because realloc can change the pointer
					look = utl_id_vector_get(&tree->nodes, look_idx);
					look->right = idx;
					
					return;

				} else {
					look_idx = look->right;
					continue;
				}

			} else if (key < look->key) {

				if (look->left == UTL_TREE_NULL) {

					// create a left branch
					const utl_tree_branch_t branch = {
						.key = key,
						.value = value,
						.left = UTL_TREE_NULL,
						.right = UTL_TREE_NULL,
						.parent = look_idx
					};
					
					tree->length++;
					const uint32_t idx = utl_id_vector_push(&tree->nodes, &branch);
					// get look again because realloc can change the pointer
					look = utl_id_vector_get(&tree->nodes, look_idx);
					look->left = idx;

					return;

				} else {
					look_idx = look->left;
					continue;
				}

			} else {
				look->value = value;
				return;
			}

		}
	}

}

void* utl_tree_get(const utl_tree_t* tree, uint32_t key) {

	if (tree->length == 0) {

		return NULL;

	} else {

		utl_tree_branch_t* look = utl_id_vector_get(&tree->nodes, tree->root);

		for (;;) {

			if (key > look->key) {

				if (look->right == UTL_TREE_NULL) {

					return NULL;

				} else {

					look = utl_id_vector_get(&tree->nodes, look->right);
					continue;

				}

			} else if (key < look->key) {

				if (look->left == UTL_TREE_NULL) {

					return NULL;

				} else {

					look = utl_id_vector_get(&tree->nodes, look->left);
					continue;

				}

			} else {

				return look->value;

			}

		}

	}

}

void utl_tree_remove(utl_tree_t* tree, uint32_t key) {

	if (tree->length == 0) {

		return;

	} else {

		uint32_t look_idx = tree->root;

		for (;;) {

			utl_tree_branch_t* look = utl_id_vector_get(&tree->nodes, look_idx);

			if (key > look->key) {

				if (look->right == UTL_TREE_NULL) {

					return;

				} else {

					look_idx = look->right;
					continue;

				}

			} else if (key < look->key) {

				if (look->left == UTL_TREE_NULL) {

					return;

				} else {

					look_idx = look->left;
					continue;

				}

			} else {

				if (look->left == UTL_TREE_NULL && look->right == UTL_TREE_NULL) {
					
					if (look->parent != UTL_TREE_NULL) {
						utl_tree_branch_t* parent = utl_id_vector_get(&tree->nodes, look->parent);

						if (parent->left == look_idx) {
							parent->left = UTL_TREE_NULL;
						} else if (parent->right == look_idx) {
							parent->right = UTL_TREE_NULL;
						}
					} else {
						tree->root = UTL_TREE_NULL;
					}

					tree->length--;
					utl_id_vector_remove(&tree->nodes, look_idx);

				} else if (look->left != UTL_TREE_NULL && look->right != UTL_TREE_NULL) {

					utl_tree_branch_t* successor = utl_id_vector_get(&tree->nodes, look->right);

					while (successor->left != UTL_TREE_NULL) {
						successor = utl_id_vector_get(&tree->nodes, successor->left);
					}
					
					int64_t new_key = successor->key;
					void* new_value = successor->value;

					// has to be an empty or right only
					utl_tree_remove(tree, new_key);

					look->key = new_key;
					look->value = new_value;

				} else if (look->left != UTL_TREE_NULL) {

					if (look->parent != UTL_TREE_NULL) {
						utl_tree_branch_t* parent = utl_id_vector_get(&tree->nodes, look->parent);

						if (parent->left == look_idx) {
							parent->left = look->left;
						} else if (parent->right == look_idx) {
							parent->right = look->left;
						}
					} else {
						tree->root = look->left;
					}
					
					tree->length--;
					utl_id_vector_remove(&tree->nodes, look_idx);

				} else if (look->right != UTL_TREE_NULL) {

					if (look->parent != UTL_TREE_NULL) {
						utl_tree_branch_t* parent = utl_id_vector_get(&tree->nodes, look->parent);

						if (parent->left == look_idx) {
							parent->left = look->right;
						} else if (parent->right == look_idx) {
							parent->right = look->right;
						}
					} else {
						tree->root = look->right;
					}
					
					tree->length--;
					utl_id_vector_remove(&tree->nodes, look_idx);

				}

				break;

			}

		}

	}

}

void* utl_tree_shift(utl_tree_t* tree) {

	if (tree->length == 0) {
		
		return NULL;

	} else {

		utl_tree_branch_t* look = utl_id_vector_get(&tree->nodes, tree->root);

		for (;;) {

			if (look->left != UTL_TREE_NULL) {

				look = utl_id_vector_get(&tree->nodes, look->left);

			} else if (look->right != UTL_TREE_NULL) {

				look = utl_id_vector_get(&tree->nodes, look->right);

			} else {

				// TODO optimize remove (because it is a free branch)
				void* value = look->value;
				utl_tree_remove(tree, look->key);
				return value;

			}

		}

	}

}