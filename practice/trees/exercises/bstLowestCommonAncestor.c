
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
int bstLowestCommonAncestor(Tree bst, int val1, int val2) {
	return 0;
}

