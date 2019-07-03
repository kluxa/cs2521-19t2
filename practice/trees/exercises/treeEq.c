
#include <stdlib.h>

#include "tree.h"

/**
 * Returns true if the two trees are identical, and false otherwise.
 *
 * Examples:
 *       input t1      |      input t2      |  expected return value
 * --------------------+--------------------+-------------------------
 *          4          |         4          |
 *         / \         |        / \         |
 *        2   7        |       2   7        |          false
 *       /             |                    |
 *      1              |                    |
 * --------------------+--------------------+-------------------------
 *          5          |         5          |
 *         / \         |        / \         |
 *        3   8        |       3   8        |          true
 *       /   / \       |      /   / \       |
 *      1   7   9      |     1   7   9      |
 * --------------------+--------------------+-------------------------
 *          7          |         X          |          false
 * --------------------+--------------------+-------------------------
 *          X          |         X          |          true
 */
bool treeEq(Tree t1, Tree t2) {
	return false;
}

