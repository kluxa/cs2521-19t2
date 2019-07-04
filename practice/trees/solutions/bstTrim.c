
#include <stdlib.h>

#include "tree.h"

/**
 * Deletes  and  frees  all  nodes in the given BST that contain a value
 * that  is  less  than min or greater than max. Returns the root of the
 * updated tree.
 *
 * Examples:
 *          input tree        |  min  |  max  |  expected returned tree
 * ---------------------------+-------+-------+--------------------------
 *              6             |       |       |            6
 *             / \            |       |       |           / \
 *            4   8           |   3   |   8   |          4   8
 *           / \   \          |       |       |           \
 *          2   5   9         |       |       |            5
 * ---------------------------+-------+-------+--------------------------
 *              5             |       |       |            5
 *             / \            |       |       |           / \
 *            1   7           |       |       |          3   7
 *             \   \          |   3   |   8   |           \
 *              3   9         |       |       |            4
 *             / \            |       |       |
 *            2   4           |       |       |
 * ---------------------------+-------+-------+--------------------------
 *              1             |       |       |            5
 *               \            |       |       |           / \
 *                2           |       |       |          4   6
 *                 \          |       |       |
 *                  5         |   4   |   7   |
 *                 / \        |       |       |
 *                3   6       |       |       |
 *                 \          |       |       |
 *                  4         |       |       |
 * ---------------------------+-------+-------+--------------------------
 *              4             |       |       |            X
 *             / \            |   6   |   8   |
 *            2   5           |       |       |
 * ---------------------------+-------+-------+--------------------------
 *              9             |       |       |            6
 *             /              |       |       |           /
 *            7               |       |       |          5
 *           /                |       |       |
 *          6                 |   4   |   6   |
 *         /                  |       |       |
 *        5                   |       |       |
 *       /                    |       |       |
 *      3                     |       |       |
 */
Tree bstTrim(Tree bst, int min, int max) {
	if (bst == NULL) {
		return NULL;
	}
	
	// Trim the left and right subtrees
	bst->left = bstTrim(bst->left, min, max);
	bst->right = bstTrim(bst->right, min, max);
	
	// If  the value in the root is less than min, then we know that all
	// of the values in the left subtree will also be less than min, and
	// will have therefore been trimmed away. But this isn't necessarily
	// true  for the right subtree, so we just return what is left after
	// trimming the right subtree.
	if (bst->value < min) {
		Tree newRoot = bst->right;
		free(bst);
		return newRoot;
	
	// Similar  to above - if the value in the root is greater than max,
	// we return what is left after trimming the left subtree.
	} else if (bst->value > max) {
		Tree newRoot = bst->left;
		free(bst);
		return newRoot;
	
	// Otherwise, the root will not be trimmed, so we simply return it.
	} else {
		return bst;
	}
}

