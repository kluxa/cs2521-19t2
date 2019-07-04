
#include <stdlib.h>

#include "tree.h"

/**
 * Returns  an  array  containing the inorder traversal of the given BST
 * and sets *size to the size of the BST.
 *
 * Examples:
 *       input tree     | expected returned array | expected value of *size
 * ---------------------+-------------------------+-------------------------
 *           4          |                         |
 *          / \         |                         |
 *         2   7        |     [1, 2, 3, 4, 7]     |            5
 *        / \           |                         |
 *       1   3          |                         |
 * ---------------------+-------------------------+-------------------------
 *           1          |                         |
 *            \         |                         |
 *             7        |                         |
 *            /         |      [1, 4, 5, 7]       |            4
 *           4          |                         |
 *            \         |                         |
 *             5        |                         |
 * ---------------------+-------------------------+-------------------------
 *           7          |          [7]            |            1
 * ---------------------+-------------------------+-------------------------
 *           X          |          [ ]            |            0
 */
int *bstGetInorderTraversal(Tree t, int *size) {
	return NULL;
}

