
#include <assert.h>
#include <stdlib.h>

#include "tree.h"

/**
 * Deletes  the  largest  value in the given BST and returns the updated
 * root  of  the tree. Also sets *max to the value that was deleted. The
 * function also assumes that the given BST is not empty.
 *
 * Examples:
 *       input tree     | expected returned tree | expected value of *max
 * ---------------------+------------------------+------------------------
 *           2          |           X            |           2
 * ---------------------+------------------------+------------------------
 *           6          |           2            |
 *          /           |          / \           |
 *         2            |         1   4          |           6
 *        / \           |                        |
 *       1   4          |                        |
 * ---------------------+------------------------+------------------------
 *           2          |           2            |
 *            \         |            \           |
 *             3        |             3          |
 *              \       |              \         |           7
 *               7      |               5        |
 *              /       |                        |
 *             5        |                        |
 */
Tree bstDeleteLargest(Tree bst, int *max) {
	assert(bst != NULL);
	return NULL;
}

