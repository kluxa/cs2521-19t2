
#include <stdlib.h>

#include "tree.h"

#define SIMPLE_INEFFICIENT 1

/**
 * Returns  true if the given tree is height-balanced. A tree is height-
 * balanced  if,  for  every  node, the difference in height between its
 * left and right subtrees is no greater than 1.
 * Hint: use -1 as the height of an empty tree.
 *
 * Examples:
 *          input tree        |     expected return value
 * ---------------------------+--------------------------------
 *              6             |
 *             / \            |             true
 *            4   8           |
 * ---------------------------+--------------------------------
 *              2             |
 *             / \            |
 *            3   1           |             true
 *           /     \          |
 *          9       7         |
 * ---------------------------+--------------------------------
 *              6             |
 *             /              |
 *            3               |             false
 *           /                |
 *          2                 |
 * ---------------------------+--------------------------------
 *              4             |             true
 * ---------------------------+--------------------------------
 *              X             |             true
 * ---------------------------+--------------------------------
 *              1             |
 *             / \            |
 *            /   \           |
 *           /     \          |
 *          2       3         |             true
 *         / \     /          |
 *        4   5   6           |
 *       /                    |
 *      7                     |
 * ---------------------------+--------------------------------
 *              5             |
 *             / \            |
 *            /   \           |
 *           /     \          |
 *          2       8         |             false
 *         / \     /          |
 *        1   4   7           |
 *           /   /            |
 *          3   6             |
 */

#if SIMPLE_INEFFICIENT /////////////////////////////////////////////////

static int treeHeight(Tree t);

bool treeIsHeightBalanced(Tree t) {
	// An empty tree is automatically height-balanced.
	if (t == NULL) {
		return true;
	}
	
	// No  clever tricks here - we find the height of the left and right
	// subtrees, then check if the difference is greater than 1. Then we
	// repeat  for  each  subtree. A more efficient solution would start
	// from the leaves and work its way upwards.
	int l = treeHeight(t->left);
	int r = treeHeight(t->right);
	if (l - r > 1 || r - l > 1) {
		return false;
	} else {
		return treeIsHeightBalanced(t->left) &&
		       treeIsHeightBalanced(t->right);
	}
}

static int treeHeight(Tree t) {
	if (t == NULL) {
		return -1;
	} else {
		int l = treeHeight(t->left);
		int r = treeHeight(t->right);
		return 1 + (l > r ? l : r);
	}
}

#else // EFFICIENT /////////////////////////////////////////////////////

#define NOT_BALANCED -99

static int doIsHeightBalanced(Tree t);

bool treeIsHeightBalanced(Tree t) {
	int height = doIsHeightBalanced(t);
	if (height == NOT_BALANCED) {
		return false;
	} else {
		return true;
	}
}

// Returns  the  height  of the given tree if it is height-balanced, and
// NOT_BALANCED otherwise. This is identical to isAVL in Week 4 Tutorial
static int doIsHeightBalanced(Tree t) {
	if (t == NULL) {
		return -1;
	} else {
		int l = doIsHeightBalanced(t->left);
		int r = doIsHeightBalanced(t->right);
		if (l == NOT_BALANCED || r == NOT_BALANCED ||
				l - r > 1 || r - l > 1) {
			return NOT_BALANCED;
		} else {
			return 1 + (l > r ? l : r);
		}
	}
}

#endif

