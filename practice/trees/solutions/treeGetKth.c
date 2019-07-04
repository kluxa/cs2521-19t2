
#include <assert.h>
#include <stdlib.h>

#include "tree.h"

/**
 * Returns the value at index k in the tree. Assumes that k is between 0
 * and N - 1 where N is the size of the tree.
 *
 * Examples:
 *          input tree        |  k  |  expected return value
 * ---------------------------+-----+-------------------------
 *              6             |  0  |           4
 *             / \            |  1  |           5
 *            4   8           |  2  |           6
 *             \              |  3  |           8
 *              5             |     |
 * ---------------------------+-----+-------------------------
 *              5             |  0  |           1
 *             / \            |  1  |           2
 *            1   7           |  2  |           3
 *             \   \          |  3  |           4
 *              3   9         |  4  |           5
 *             / \            |  5  |           7
 *            2   4           |  6  |           9
 * ---------------------------+-----+-------------------------
 *              5             |  0  |           1
 *             / \            |  1  |           2
 *            3   7           |  2  |           3
 *           /     \          |  3  |           5
 *          2       8         |  4  |           7
 *         /                  |  5  |           8
 *        1                   |     |
 * ---------------------------+-----+-------------------------
 *              4             |  0  |           4
 * ---------------------------+-----+-------------------------
 *              2             |  0  |           2
 *               \            |  1  |           5
 *                5           |  2  |           7
 *                 \          |  3  |           8
 *                  8         |  4  |           9
 *                 / \        |     |
 *                7   9       |     |
 */

static int treeSize(Tree t);

int treeGetKth(Tree t, int k) {
	// As  we  are allowed to assume that k will always be between 0 and
	// N - 1, this assertion captures that assumption.
	assert(t != NULL);
	
	// If k is equal to L, the size of the left subtree, then this means
	// that  the  left  subtree contains indexes 0, 1, ..., k - 1, which
	// means  that  the root is index k! If k is smaller, than we search
	// the  left  subtree  for  index  k. Otherwise, we search the right
	// subtree for index k - L - 1. (Why - 1?)
	int leftSize = treeSize(t->left);
	if (k == leftSize) {
		return t->value;
	} else if (k < leftSize) {
		return treeGetKth(t->left, k);
	} else {
		return treeGetKth(t->right, k - leftSize - 1);
	}
}

static int treeSize(Tree t) {
	if (t == NULL) {
		return 0;
	} else {
		return 1 + treeSize(t->left) + treeSize(t->right);
	}
}

