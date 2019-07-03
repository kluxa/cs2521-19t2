
#include <assert.h>
#include <stdlib.h>

#include "tree.h"

/**
 * Returns  the value of the lowest common ancestor of two values in the
 * given  BST. Assumes that the given values are in the tree. The lowest
 * ancestor of a value is considered to be itself.
 *
 * Examples:
 *          input tree        |  val1  |  val2  |  expected return value
 * ---------------------------+--------+--------+-------------------------
 *              6             |        |        |
 *             / \            |        |        |
 *            4   8           |   8    |   5    |           6
 *           / \   \          |        |        |
 *          2   5   9         |        |        |
 * ---------------------------+--------+--------+-------------------------
 *              3             |        |        |
 *             / \            |        |        |
 *            1   6           |        |        |
 *               / \          |   4    |   8    |           6
 *              5   8         |        |        |
 *             /              |        |        |
 *            4               |        |        |
 * ---------------------------+--------+--------+-------------------------
 *              1             |        |        |
 *               \            |        |        |
 *                3           |        |        |
 *                 \          |   9    |   3    |           3
 *                  4         |        |        |
 *                   \        |        |        |
 *                    9       |        |        |
 * ---------------------------+--------+--------+-------------------------
 *              4             |        |        |
 *             / \            |   2    |   2    |           2
 *            2   6           |        |        |
 */

static int doBstLowestCommonAncestor(Tree bst, int val1, int val2);
static void swap(int *num1, int *num2);

int bstLowestCommonAncestor(Tree bst, int val1, int val2) {
	assert(bst != NULL);
	
	if (val1 > val2) {
		swap(&val1, &val2);
	}
	
	return doBstLowestCommonAncestor(bst, val1, val2);
}

// We  created this recursive helper function which can assume that val1
// is less than or equal to val2. The original function cannot make this
// assumption.
static int doBstLowestCommonAncestor(Tree bst, int val1, int val2) {
	// If val1 is in the left subtree, and val2 is in the right subtree,
	// or  the root value is equal to one or both of them, then the root
	// must be the lowest common ancestor.
	if (val1 <= bst->value && bst->value <= val2) {
		return bst->value;
	
	// If  both  values  are less than the value in the root, then there
	// must be a lower common ancestor in the left subtree
	} else if (val1 < bst->value && val2 < bst->value) {
		return doBstLowestCommonAncestor(bst->left, val1, val2);
	} else {
		return doBstLowestCommonAncestor(bst->right, val1, val2);
	}
}

static void swap(int *num1, int *num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

