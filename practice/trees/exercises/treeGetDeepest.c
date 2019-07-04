
#include <stdlib.h>

#include "tree.h"

/**
 * Returns  the  deepest  node in the given tree, or NULL if the tree is
 * empty. If there are multiple deepest nodes, return the rightmost one.
 *
 * Examples:
 *          input tree        |     expected return value
 * ---------------------------+--------------------------------
 *              6             |
 *             / \            |
 *            4   8           |  pointer to node containing 5
 *             \              |
 *              5             |
 * ---------------------------+--------------------------------
 *              5             |
 *             / \            |
 *            1   7           |
 *             \   \          |  pointer to node containing 4
 *              3   9         |
 *             / \            |
 *            2   4           |
 * ---------------------------+--------------------------------
 *              5             |
 *             / \            |
 *            3   7           |
 *           /     \          |  pointer to node containing 1
 *          2       8         |
 *         /                  |
 *        1                   |
 * ---------------------------+--------------------------------
 *              4             |  pointer to node containing 4
 * ---------------------------+--------------------------------
 *              X             |              NULL
 */
Tree treeGetDeepest(Tree t) {
	return NULL;
}

