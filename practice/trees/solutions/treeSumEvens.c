
#include <stdlib.h>

#include "tree.h"

/**
 * Returns the sum of all of the even values in the tree.
 */
int treeSumEvens(Tree t) {
	// There  are  no values in an empty tree, let alone even values, so
	// return 0
	if (t == NULL) {
		return 0;
	}
	
	// Find  the  sum of the even values in the left and right subtrees,
	// then add the root value if it is even.
	int sum = treeSumEvens(t->left) + treeSumEvens(t->right);
	if (t->value % 2 == 0) {
		return t->value + sum;
	} else {
		return sum;
	}
}

