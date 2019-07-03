
#include <stdlib.h>

#include "tree.h"

/**
 * Returns  the pointer to the node containing the smallest value in the
 * given tree, or NULL if the tree is empty. Assumes that the given tree
 * is a BST.
 *
 * Examples:
 *          input tree        |     expected return value
 * ---------------------------+--------------------------------
 *              6             |
 *             / \            |
 *            4   8           |  pointer to node containing 4
 *                 \          |
 *                  9         |
 * ---------------------------+--------------------------------
 *              5             |
 *             / \            |
 *            1   8           |  pointer to node containing 1
 *             \              |
 *              2             |
 * ---------------------------+--------------------------------
 *              5             |
 *               \            |
 *                8           |  pointer to node containing 5
 *               / \          |
 *              6   9         |
 * ---------------------------+--------------------------------
 *              3             |  pointer to node containing 3
 * ---------------------------+--------------------------------
 *              X             |             NULL
 */

// If  the  tree is empty, then return NULL. If the root does not have a
// left subtree, then the root contains the smallest value, so we simply
// return the root. Otherwise we find the pointer to the node containing
// the smallest value in the left subtree and return it.
Tree bstGetSmallest(Tree bst) {
	if (bst == NULL) {
		return NULL;
	} else if (bst->left == NULL) {
		return bst;
	} else {
		return bstGetSmallest(bst->left);
	}
}

