
#include <stdio.h>
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

static Tree newTreeNode(int value, Tree left);

void treeDouble(Tree t) {
	if (t != NULL) {
		treeDouble(t->left);
		treeDouble(t->right);
		
		// Giving the newTreeNode function a pointer to the left subtree
		// saves  us  from having to set the left pointer after creating
		// the node.
		t->left = newTreeNode(t->value, t->left);
		
		/*
		What you would do if your new node function only set the value.
		Tree newLeft = newTreeNode(t->value);
		newLeft->left = t->left;
		t->left = newLeft;
		 */
	}
}

// Creates a new node with the given value and left subtree
static Tree newTreeNode(int value, Tree left) {
	Tree t = malloc(sizeof(*t));
	if (t == NULL) {
		fprintf(stderr, "Insufficient memory!\n");
		exit(EXIT_FAILURE);
	}
	
	t->value = value;
	t->left = left;
	t->right = NULL;
	return t;
}

