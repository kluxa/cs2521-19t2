
#include <stdlib.h>

#include "tree.h"

/**
 * Returns a pointer to the node containing the inorder successor of the
 * given  number  in the tree. Returns NULL if the given number does not
 * exist in the tree or does not have an inorder successor. Assumes that
 * the given tree is a BST.
 *
 * Examples:
 *          input tree        |  num  |     expected return value
 * ---------------------------+-------+--------------------------------
 *              6             |       |
 *             / \            |       |
 *            4   8           |   8   |  pointer to node containing 9
 *                 \          |       |
 *                  9         |       |
 * ---------------------------+-------+--------------------------------
 *              5             |       |
 *             / \            |       |
 *            1   8           |   2   |  pointer to node containing 5
 *             \              |       |
 *              2             |       |
 * ---------------------------+-------+--------------------------------
 *              5             |       |
 *               \            |       |
 *                8           |   9   |             NULL
 *               / \          |       |
 *              6   9         |       |
 * ---------------------------+-------+--------------------------------
 *              3             |       |
 *             / \            |   6   |             NULL
 *            1   7           |       |
 * ---------------------------+-------+--------------------------------
 *              8             |       |
 *             /              |       |
 *            7               |   5   |  pointer to node containing 7
 *           /                |       |
 *          5                 |       |
 */
Tree bstInorderSuccessor(Tree bst, int num) {
	return NULL;
}

