
#include <stdlib.h>

#include "tree.h"

#define PREORDER 1

/**
 * Deletes and frees all nodes that are at or below a given depth in the
 * tree.  Will free the entire tree if the given depth is 0 or negative.
 * Returns the root of the updated tree.
 *
 * Examples:
 *          input tree        |  depth  |  expected returned tree
 * ---------------------------+---------+--------------------------
 *              7             |         |            X
 *             / \            |         |
 *            5   8           |    0    |
 *           /                |         |
 *          3                 |         |
 * ---------------------------+---------+--------------------------
 *              5             |         |            5
 *             / \            |    1    |
 *            3   9           |         |
 * ---------------------------+---------+--------------------------
 *              6             |         |            6
 *             / \            |         |           / \
 *            4   8           |    2    |          4   8
 *           / \   \          |         |
 *          2   5   9         |         |
 * ---------------------------+---------+--------------------------
 *              5             |         |            5
 *             / \            |         |           / \
 *            1   7           |         |          1   7
 *             \   \          |    3    |           \   \
 *              3   9         |         |            3   9
 *             / \            |         |
 *            2   4           |         |
 * ---------------------------+---------+--------------------------
 *              1             |         |            1
 *               \            |         |             \
 *                2           |         |              2
 *                 \          |         |               \
 *                  5         |    4    |                5
 *                 / \        |         |               / \
 *                3   6       |         |              3   6
 *                 \   \      |         |
 *                  4   8     |         |
 */

#if PREORDER ///////////////////////////////////////////////////////////

static void freeTree(Tree t);

// This  is  what would be considered a preorder approach, since we deal
// with the current tree (root) before the left and right subtrees.
Tree treePrune(Tree t, int depth) {
	if (t == NULL) {
		return NULL;
	}
	
	// If the given depth is 0 or less, free the entire tree, and return
	// the empty tree.
	if (depth <= 0) {
		freeTree(t);
		return NULL;
	}
	
	// Prune  the  left and right subtrees, but at a depth of depth - 1,
	// since we are moving down one level.
	t->left = treePrune(t->left, depth - 1);
	t->right = treePrune(t->right, depth - 1);
	return t;
}

static void freeTree(Tree t) {
	if (t != NULL) {
		freeTree(t->left);
		freeTree(t->right);
		free(t);
	}
}

#else // POSTORDER /////////////////////////////////////////////////////

// A postorder traversal avoids the need for a freeTree helper function.

Tree treePrune(Tree t, int depth) {
	if (t == NULL) {
		return NULL;
	}
	
	// Prune the left and right subtrees
	t->left = treePrune(t->left, depth - 1);
	t->right = treePrune(t->right, depth - 1);
	
	// If the given depth is 0 or less, then the left and right subtrees
	// have  ALREADY  been  pruned, so just free the root and return the
	// empty  tree. Otherwise, the root is not pruned, so we just return
	// it.
	if (depth <= 0) {
		free(t);
		return NULL;
	} else {
		return t;
	}
}

#endif

