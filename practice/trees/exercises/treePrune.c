
#include <stdlib.h>

#include "tree.h"

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
Tree treePrune(Tree t, int depth) {
	return NULL;
}

