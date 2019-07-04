
#include <assert.h>
#include <stdlib.h>

#include "tree.h"

#define RECURSIVE 1

/**
 * Deletes  the  largest  value in the given BST and returns the updated
 * root  of  the tree. Also sets *max to the value that was deleted. The
 * function also assumes that the given BST is not empty.
 *
 * Examples:
 *       input tree     | expected returned tree | expected value of *max
 * ---------------------+------------------------+------------------------
 *           2          |           X            |           2
 * ---------------------+------------------------+------------------------
 *           6          |           2            |
 *          /           |          / \           |
 *         2            |         1   4          |           6
 *        / \           |                        |
 *       1   4          |                        |
 * ---------------------+------------------------+------------------------
 *           2          |           2            |
 *            \         |            \           |
 *             3        |             3          |
 *              \       |              \         |           7
 *               7      |               5        |
 *              /       |                        |
 *             5        |                        |
 */

#if RECURSIVE //////////////////////////////////////////////////////////

Tree bstDeleteLargest(Tree bst, int *max) {
	assert(bst != NULL);
	
	// If the root of the tree does not have a right child,
	// then it definitely contains the largest value in the
	// tree. The new root becomes its left child (if it has
	// a left child). 
	if (bst->right == NULL) {
		*max = bst->value;
		Tree newRoot = bst->left;
		free(bst);
		return newRoot;
	
	// Otherwise,  delete  the largest value from the right
	// subtree and return its updated root.
	} else {
		bst->right = bstDeleteLargest(bst->right, max);
		return bst;
	}
}

#else // ITERATIVE /////////////////////////////////////////////////////

Tree bstDeleteLargest(Tree bst, int *max) {
	assert(bst != NULL);
	
	Tree curr = bst;
	Tree prev = NULL;
	while (curr->right != NULL) {
		prev = curr;
		curr = curr->right;
	}
	
	*max = curr->value;
	
	// If prev == NULL, this means we didn't enter the loop, which means
	// the  root  has  no right child, which means the root contains the
	// largest value.
	if (prev == NULL) {
		Tree newRoot = curr->left;
		free(curr);
		return newRoot;
	} else {
		prev->right = curr->left;
		free(curr);
		return bst;
	}
}

#endif

