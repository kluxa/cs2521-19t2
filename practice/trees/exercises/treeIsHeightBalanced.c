
#include <stdlib.h>

#include "tree.h"

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
bool treeIsHeightBalanced(Tree t) {
	return false;
}

