
#include <stdlib.h>

#include "tree.h"

/**
 * Deletes  and frees all leaf nodes in the given tree. Returns the root
 * of the updated tree.
 *
 * Examples:
 *          input tree        |  expected returned tree
 * ---------------------------+--------------------------
 *              6             |            6
 *             / \            |           / \
 *            4   8           |          4   8
 *           / \   \          |
 *          2   5   9         |
 * ---------------------------+--------------------------
 *              5             |            5
 *             / \            |           / \
 *            1   7           |          1   7
 *             \   \          |           \
 *              3   9         |            3
 *             / \            |
 *            2   4           |
 * ---------------------------+--------------------------
 *              1             |            1
 *               \            |             \
 *                2           |              2
 *                 \          |               \
 *                  5         |                5
 *                 / \        |               /
 *                3   6       |              3
 *                 \          |
 *                  4         |
 * ---------------------------+--------------------------
 *              4             |            4
 *             / \            |
 *            2   5           |
 * ---------------------------+--------------------------
 *              9             |            X
 */
Tree treeDeleteLeaves(Tree t) {
	// If  the  tree is empty, there's nothing to delete, so just return
	// the empty tree.
	if (t == NULL) {
		return NULL;
	
	// If  the  root is a leaf, free the leaf and return the empty tree.
	} else if (t->left == NULL && t->right == NULL) {
		free(t);
		return NULL;
	
	// Otherwise, the root is not a leaf, so delete leaves from the left
	// and right subtrees, then return the original root.
	} else {
		t->left = treeDeleteLeaves(t->left);
		t->right = treeDeleteLeaves(t->right);
		return t;
	}
}

