
#include <stdlib.h>

#include "tree.h"

#define SIMPLE_INEFFICIENT 1

/**
 * Returns  true  if  the  given  tree is size-balanced. A tree is size-
 * balanced  if, for every node, the difference in size between its left
 * and right subtrees is no greater than 1.
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
 *          2       3         |             false
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

static int treeSize(Tree t);

bool treeIsSizeBalanced(Tree t) {
	if (t == NULL) {
		return true;
	}
	
	// Like treeIsHeightBalanced, there are no tricks here - we find the
	// size  of  the left and right subtrees, check if the difference is
	// greater  than 1, and return false if so. Otherwise, we repeat for
	// the left and right subtrees and ensure those are size-balanced.
	// Also like treeIsHeightBalanced, there is a more efficient bottom-
	// up approach.
	int l = treeSize(t->left);
	int r = treeSize(t->right);
	if (l - r > 1 || r - l > 1) {
		return false;
	} else {
		return treeIsSizeBalanced(t->left) &&
		       treeIsSizeBalanced(t->right);
	}
}

static int treeSize(Tree t) {
	if (t == NULL) {
		return 0;
	} else {
		return 1 + treeSize(t->left) + treeSize(t->right);
	}
}

#else // EFFICIENT /////////////////////////////////////////////////////

#define NOT_BALANCED -99

static int doIsSizeBalanced(Tree t);

bool treeIsSizeBalanced(Tree t) {
	int size = doIsSizeBalanced(t);
	if (size == NOT_BALANCED) {
		return false;
	} else {
		return true;
	}
}

// Returns the size of the given tree if it is height-balanced, and NOT_
// BALANCED otherwise. This is similar to isAVL in Week 4 Tutorial
static int doIsSizeBalanced(Tree t) {
	if (t == NULL) {
		return 0;
	} else {
		int l = doIsSizeBalanced(t->left);
		int r = doIsSizeBalanced(t->right);
		if (l == NOT_BALANCED || r == NOT_BALANCED ||
				l - r > 1 || r - l > 1) {
			return NOT_BALANCED;
		} else {
			return 1 + l + r;
		}
	}
}

#endif

