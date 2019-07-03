
#include <stdlib.h>

#include "tree.h"

/**
 * Returns the number of fully internal nodes in the given tree. A fully
 * internal node is a node that has two children.
 */
int treeNumFullyInternal(Tree t) {
	if (t == NULL) {
		return 0;
	}
	
	// Count  the  number  of fully internal nodes in the left and right
	// subtrees
	int l = treeNumFullyInternal(t->left);
	int r = treeNumFullyInternal(t->right);
	
	// If the root is a fully internal node, add one to the count.
	if (t->left != NULL && t->right != NULL) {
		return l + r + 1;
	} else {
		return l + r;
	}
}

