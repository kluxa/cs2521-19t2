
#include <stdlib.h>

#include "tree.h"

#define RECURSIVE1 1
#define RECURSIVE2 0

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

// We provide three different solutions.

#if RECURSIVE1 /////////////////////////////////////////////////////////

// A struct to return two values
struct depthResult {
	Tree deepest;
	int depth;
};
typedef struct depthResult Result;

static Result doTreeGetDeepest(Tree t);

Tree treeGetDeepest(Tree t) {
	Result res = doTreeGetDeepest(t);
	return res.deepest;
}

// Returns the deepest node in the given tree and its depth.
// If the tree is empty, NULL and -1 are returned.
static Result doTreeGetDeepest(Tree t) {
	Result res;
	
	if (t == NULL) {
		res.deepest = NULL;
		res.depth = -1;
	
	} else if (t->left == NULL && t->right == NULL) {
		res.deepest = t;
		res.depth = 0;
	
	} else {
		Result l = doTreeGetDeepest(t->left);
		Result r = doTreeGetDeepest(t->right);
		if (l.depth > r.depth) {
			res.deepest = l.deepest;
			res.depth = l.depth + 1;
		} else {
			res.deepest = r.deepest;
			res.depth = r.depth + 1;
		}
	}
	
	return res;
}

#elif RECURSIVE2 ///////////////////////////////////////////////////////

static int getHeight(Tree t);

// Here is a simpler recursive solution which does not involve returning
// multiple values, but is less efficient.
Tree treeGetDeepest(Tree t) {
	if (t == NULL) {
		return NULL;
	} else if (t->left == NULL && t->right == NULL) {
		return t;
	} else {
		Tree l = treeGetDeepest(t->left);
		Tree r = treeGetDeepest(t->right);
		if (getHeight(t->left) > getHeight(t->right)) {
			return l;
		} else {
			return r;
		}
	}
}

static int getHeight(Tree t) {
	if (t == NULL) {
		return -1;
	}
	
	int l = getHeight(t->left);
	int r = getHeight(t->right);
	return 1 + (l > r ? l : r);
}

#else // ITERATIVE /////////////////////////////////////////////////////

// Another solution would be to do a level-order traversal of the tree.
// The deepest node would be the last node that you take off the queue.
// If you were not provided with a queue in the exam, you would not be
// able to use this approach (unless you wrote up a queue yourself).
Tree treeGetDeepest(Tree t) {
	if (t == NULL) return NULL;
	
	Queue q = QueueNew();
	QueueEnqueue(q, t);
	Tree curr;
	while (!QueueIsEmpty(q)) {
		curr = QueueDequeue(q);
		if (curr->left != NULL) {
			QueueEnqueue(q, curr->left);
		}
		if (curr->right != NULL) {
			QueueEnqueue(q, curr->right);
		}
	}
	QueueDrop(q);
	return curr;
}

#endif

