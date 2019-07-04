
#include <limits.h>
#include <stdlib.h>

#include "tree.h"

#define SIMPLE_INEFFICIENT 1

/**
 * Returns true if the given tree is a BST, and false otherwise.
 *
 * Examples:
 *          input tree        |     expected return value
 * ---------------------------+--------------------------------
 *              6             |
 *             / \            |
 *            4   8           |             true
 *             \              |
 *              5             |
 * ---------------------------+--------------------------------
 *              2             |
 *             / \            |             false
 *            3   1           |
 * ---------------------------+--------------------------------
 *              6             |
 *             / \            |
 *            3   7           |             false
 *           /   / \          |
 *          2   5   8         |
 * ---------------------------+--------------------------------
 *              4             |             true
 * ---------------------------+--------------------------------
 *              X             |             true
 */

#if SIMPLE_INEFFICIENT /////////////////////////////////////////////////

static bool allLessThan(Tree t, int val);
static bool allGreaterThan(Tree t, int val);

// An empty tree is a BST. A non-empty tree is a BST if:
// 1. Every value in its left subtree is less than the root value
// 2. Every value in its right subtree is greater than the root value
// 3. The left subtree is a BST and the right subtree is a BST
// Following this definition to a T gives us this:

bool treeIsBst(Tree t) {
	if (t == NULL) {
		return true;
	}
	
	return allLessThan(t->left, t->value)
	           && allGreaterThan(t->right, t->value)
	           && treeIsBst(t->left) && treeIsBst(t->right);
}

// Returns  true if all values in the given tree are less than the given
// value, and false otherwise.
static bool allLessThan(Tree t, int val) {
	if (t == NULL) {
		return true;
	}
	
	return t->value < val
	           && allLessThan(t->left, val)
	           && allLessThan(t->right, val);
}

// Returns  true if all values in the given tree are less than the given
// value, and false otherwise.
static bool allGreaterThan(Tree t, int val) {
	if (t == NULL) {
		return true;
	}
	
	return t->value > val
	           && allGreaterThan(t->left, val)
	           && allGreaterThan(t->right, val);
}

// This is simple, but it is inefficient and it requires us to write two
// helper functions.

#else // EFFICIENT /////////////////////////////////////////////////////

static bool doTreeIsBst(Tree t, int min, int max);

// This  solution  uses  a helper function with two extra arguments that
// restrict the range of values that the tree can contain. As we recurse
// down  to  the subtrees, we restrict the range of values based on what
// the root value was.

bool treeIsBst(Tree t) {
	// Initially, there is no restriction on the range of values.
	return doTreeIsBst(t, INT_MIN, INT_MAX);
}

// Returns  true  if  the  given tree is a BST and all of its values are
// between min and max.
static bool doTreeIsBst(Tree t, int min, int max) {
	if (t == NULL) return true;
	
	if (t->value < min || t->value > max) {
		return false;
	} else {
		// Now  if,  for  example, the root value is 7, then the maximum
		// value that is allowed to be in the left subtree is 6, and the
		// minimum value that is allowed to be in the right subtree is 8
		// (assuming no duplicates).
		return doTreeIsBst(t->left, min, t->value - 1) &&
		       doTreeIsBst(t->right, t->value + 1, max);
	}
}

#endif

