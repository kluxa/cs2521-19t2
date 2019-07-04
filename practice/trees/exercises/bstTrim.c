
#include <stdlib.h>

#include "tree.h"

/**
 * Deletes  and  frees  all  nodes in the given BST that contain a value
 * that  is  less than min or greater than max. Assumes that min is less
 * than or equal to max. Returns the root of the updated tree.
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
	return NULL;
}

