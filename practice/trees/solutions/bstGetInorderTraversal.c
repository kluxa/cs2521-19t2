
#include <stdio.h>
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

static int treeSize(Tree t);
static void doBstGetInorderTraversal(Tree t, int *array, int *i);

// The function signature is not suitable for recursion, so we must
// create our own helper function to do the recursion.
int *bstGetInorderTraversal(Tree t, int *size) {
	int numNodes = treeSize(t);
	int *array = malloc(numNodes * sizeof(int));
	if (array == NULL) {
		fprintf(stderr, "Insufficient memory!\n");
		exit(EXIT_FAILURE);
	}
	
	int i = 0;
	doBstGetInorderTraversal(t, array, &i);
	*size = numNodes;
	return array;
}

static int treeSize(Tree t) {
	if (t == NULL) {
		return 0;
	} else {
		return 1 + treeSize(t->left) + treeSize(t->right);
	}
}

// Normal BST inorder traversal. 'Visiting' the node simply involves
// adding the value to the array. We must therefore include two more
// parameters - one  for  a  pointer to the array, and another for a
// pointer  to the index where the next value should be inserted. We
// use  a  pointer  to the index so that it can be updated globally,
// across all function calls.
static void doBstGetInorderTraversal(Tree t, int *array, int *i) {
	if (t != NULL) {
		doBstGetInorderTraversal(t->left, array, i);
		array[*i] = t->value;
		(*i)++;
		doBstGetInorderTraversal(t->right, array, i);
	}
}

