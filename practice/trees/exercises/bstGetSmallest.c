
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
Tree bstGetSmallest(Tree bst) {
	return NULL;
}

