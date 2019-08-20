
#include <stdlib.h>

#include "tree.h"

/**
 * Returns  true  if  the given tree is a max heap, and false otherwise.
 * Assumes that the given tree is complete.
 */
bool treeIsMaxHeap(Tree t) {
	if (t == NULL) {
		return true;
	}
	if (t->left != NULL && t->value < t->left->value) {
		return false;
	}
	if (t->right != NULL && t->value < t->right->value) {
		return false;
	}
	
	return treeIsMaxHeap(t->left) && treeIsMaxHeap(t->right);
}

