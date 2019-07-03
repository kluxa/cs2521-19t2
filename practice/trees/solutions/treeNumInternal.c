
#include <stdlib.h>

#include "tree.h"

/**
 * Returns  the  number of internal nodes in the given tree. An internal
 * node is a node that has one or more children, i.e., is not a leaf.
 */

// This was a tutorial exercise
int treeNumInternal(Tree t) {
	if (t == NULL) {
		return 0;
	} else if (t->left == NULL && t->right == NULL) {
		return 0;
	} else {
		return 1 + treeNumInternal(t->left) + treeNumInternal(t->right);
	}
}

