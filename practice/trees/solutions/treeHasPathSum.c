
#include <stdlib.h>

#include "tree.h"

/**
 * Returns  true  if  there  is  a  path from the root of the tree to an
 * external node that has the given sum, or false otherwise. An external
 * node is a node that has one or zero children.
 *
 * Examples:
 *          input tree        |  sum  |  expected return value
 * ---------------------------+-------+-------------------------
 *              6             |   6   |         false
 *             / \            |  10   |         true
 *            4   8           |  14   |         true
 *             \              |  15   |         true
 *              5             |  18   |         false
 *                            |  23   |         false
 * ---------------------------+-------+-------------------------
 *              5             |   5   |         false
 *             / \            |   6   |         true
 *            1   7           |   9   |         false
 *             \   \          |  11   |         true
 *              3   9         |  12   |         true
 *             / \            |  13   |         true
 *            2   4           |  15   |         false
 *                            |  21   |         true
 * ---------------------------+-------+-------------------------
 *              1             |   1   |         false
 *             / \            |   2   |         false
 *            /   \           |   3   |         false
 *           /     \          |   4   |         false
 *          2       3         |   5   |         false
 *         / \     / \        |   6   |         false
 *        4   5   6   7       |   7   |         true
 *                            |   8   |         true
 *  (the tree doesn't have to |   9   |         false
 *          be a BST)         |  10   |         true
 *                            |  11   |         true
 *                            |  12   |         false
 * ---------------------------+-------+-------------------------
 *              4             |  -4   |         false
 *             / \            |   0   |         true
 *            0   5           |   4   |         true
 *           /                |   9   |         true
 *         -4                 |       |
 * ---------------------------+-------+-------------------------
 *              X             |   0   |         true
 * ---------------------------+-------+-------------------------
 *              7             |   7   |         true
 */

// Here is the idea: If there is a path with a given sum starting at the
// root,  then  there  must  be  a path with the sum (sum - root->value)
// starting at root->left or root->right. The reverse is also true.
bool treeHasPathSum(Tree t, int sum) {
	// If the root is NULL then there is a path with sum 0 (empty path),
	// so return true if the sum is 0 and false otherwise.
	if (t == NULL) {
		return (sum == 0);
	
	// Otherwise, subtract the value in the root node from the given sum
	// and  check if there is a path whose sum is the remainder starting
	// at the root of the left or right subtree.
	} else {
		int remainder = sum - t->value;
		return treeHasPathSum(t->left, remainder) ||
		       treeHasPathSum(t->right, remainder);
	}
}

