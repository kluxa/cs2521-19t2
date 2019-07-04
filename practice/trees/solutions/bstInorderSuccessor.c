
#include <stdlib.h>

#include "tree.h"

#define RECURSIVE 1

/**
 * Returns a pointer to the node containing the inorder successor of the
 * given  number  in the tree. Returns NULL if the given number does not
 * exist in the tree or does not have an inorder successor. Assumes that
 * the given tree is a BST.
 *
 * Examples:
 *          input tree        |  num  |     expected return value
 * ---------------------------+-------+--------------------------------
 *              6             |       |
 *             / \            |       |
 *            4   8           |   8   |  pointer to node containing 9
 *                 \          |       |
 *                  9         |       |
 * ---------------------------+-------+--------------------------------
 *              5             |       |
 *             / \            |       |
 *            1   8           |   2   |  pointer to node containing 5
 *             \              |       |
 *              2             |       |
 * ---------------------------+-------+--------------------------------
 *              5             |       |
 *               \            |       |
 *                8           |   9   |             NULL
 *               / \          |       |
 *              6   9         |       |
 * ---------------------------+-------+--------------------------------
 *              3             |       |
 *             / \            |   6   |             NULL
 *            1   7           |       |
 * ---------------------------+-------+--------------------------------
 *              8             |       |
 *             /              |       |
 *            7               |   5   |  pointer to node containing 7
 *           /                |       |
 *          5                 |       |
 * ---------------------------+-------+--------------------------------
 *              1             |       |
 *               \            |       |
 *                5           |   1   |  pointer to node containing 4
 *               / \          |       |
 *              4   8         |       |
 */

static Tree getSmallest(Tree bst);

#if RECURSIVE //////////////////////////////////////////////////////////

static Tree getLargest(Tree bst);

Tree bstInorderSuccessor(Tree bst, int num) {
	// The given number was not found, so return NULL.
	if (bst == NULL) return NULL;
	
	// If  the given number is less than the value in the root, then the
	// root may be the inorder successor. If it is not, then the inorder
	// successor is in the left subtree.
	if (num < bst->value) {
		Tree maxR = getLargest(bst->left);
		if (maxR != NULL && maxR->value == num) {
			return bst;
		} else {
			return bstInorderSuccessor(bst->left, num);
		}
	
	// If  the  given number is greater than the value in the root, then
	// the inorder successor must be in the right subtree.
	} else if (num > bst->value) {
		return bstInorderSuccessor(bst->right, num);
	
	// If  the  root contains the given number, then return the leftmost
	// node in the right subtree (which could be NULL).
	} else { // (num == bst->value)
		return getSmallest(bst->right);
	}
}

static Tree getLargest(Tree bst) {
	if (bst == NULL) {
		return NULL;
	} else if (bst->right == NULL) {
		return bst;
	} else {
		return getLargest(bst->right);
	}
}

#else // ITERATIVE /////////////////////////////////////////////////////

Tree bstInorderSuccessor(Tree bst, int num) {
	Tree curr = bst;
	Tree succ = NULL;

	// look for num in the tree
	while (curr != NULL && curr->value != num) {
		// if we move left, the successor is (potentially) what curr was
		if (num < curr->value) {
			succ = curr;
			curr = curr->left;
		
		// if  we move right, don't set succ to curr because curr is not
		// a successor
		} else {
			curr = curr->right;
		}
	}
	
	// num not found, return NULL
	if (curr == NULL) return NULL;
	
	// if num doesn't have a right child, the successor is the last node
	// before we moved left (curr = curr->left)
	if (curr->right == NULL) {
		return succ;
	
	// otherwise the successor is the leftmost node in the right subtree
	// i.e., the smallest value in the right subtree
	} else {
		return getSmallest(curr->right);
	}
}

#endif

////////////////////////////////////////////////////////////////////////
// Helper function

static Tree getSmallest(Tree bst) {
	if (bst == NULL) {
		return NULL;
	} else if (bst->left == NULL) {
		return bst;
	} else {
		return getSmallest(bst->left);
	}
}

