
#include <stdlib.h>

#include "tree.h"

/**
 * Doubles a tree. Every node in the original tree gets a new left child
 * that contains the same value. If the node already had a left child in
 * the original tree, that child becomes the new child's left child.
 *
 * Examples:
 *          input tree        |     resulting tree
 * ---------------------------+------------------------
 *              6             |            6
 *             / \            |           / \
 *            4   8           |          6   8
 *                            |         /   /
 *                            |        4   8
 *                            |       /
 *                            |      4
 * ---------------------------+------------------------
 *              5             |            5
 *               \            |           / \
 *                7           |          5   7
 *                 \          |             / \
 *                  9         |            7   9
 *                            |               /
 *                            |              9
 * ---------------------------+------------------------
 *              7             |            7
 *             /              |           /
 *            1               |          7
 *                            |         /
 *                            |        1
 *                            |       /
 *                            |      1
 * ---------------------------+------------------------
 *              4             |            4
 *                            |           /
 *                            |          4
 * ---------------------------+------------------------
 *              X             |            X
 */
void treeDouble(Tree t) {

}

