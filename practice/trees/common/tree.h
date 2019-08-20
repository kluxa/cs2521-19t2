// Header file for tree exercises

#ifndef TREE_H
#define TREE_H

#include <stdbool.h> // Provides the constants 'true' and 'false'

#include "../common/Queue.h" // in case you need it

typedef struct node *Tree;
struct node {
	int value;
	Tree left;
	Tree right;
};

// !!! important !!!
// First,  make sure you understand and can write simple tree algorithms
// such as search, insert and delete!

/**
 * Returns the sum of all of the even values in the tree.
 */
int treeSumEvens(Tree t);

/**
 * Returns  the pointer to the node containing the smallest value in the
 * given tree, or NULL if the tree is empty. Assumes that the given tree
 * is a BST.
 */
Tree bstGetSmallest(Tree bst);

/**
 * Returns  the  number of internal nodes in the given tree. An internal
 * node is a node that has one or more children, i.e., is not a leaf.
 */
int treeNumInternal(Tree t);

/**
 * Returns the number of fully internal nodes in the given tree. A fully
 * internal node is a node that has two children.
 */
int treeNumFullyInternal(Tree t);

/**
 * Returns true if the two trees are identical, and false otherwise.
 */
bool treeEq(Tree t1, Tree t2);

/**
 * Deletes  the  largest  value in the given BST and returns the updated
 * root  of  the tree. Also sets *max to the value that was deleted. The
 * function also assumes that the given BST is not empty.
 */
Tree bstDeleteLargest(Tree bst, int *max);

/**
 * Deletes  and frees all leaf nodes in the given tree. Returns the root
 * of the updated tree.
 */
Tree treeDeleteLeaves(Tree t);

/**
 * Transforms a tree into the mirror image of itself.
 */
void treeReflect(Tree t);

/**
 * Returns  an  array  containing the inorder traversal of the given BST
 * and sets *size to the size of the BST.
 */
int *bstGetInorderTraversal(Tree t, int *size);

/**
 * Returns  true  if  there  is  a  path from the root of the tree to an
 * external node that has the given sum, or false otherwise. An external
 * node is a node that has one or zero children.
 */
bool treeHasPathSum(Tree t, int sum);

/**
 * Returns the value at index k in the tree. Assumes that k is between 0
 * and N - 1 where N is the size of the tree.
 */
int treeGetKth(Tree t, int k);

/**
 * Doubles a tree. Every node in the original tree gets a new left child
 * that contains the same value. If the node already had a left child in
 * the original tree, that child becomes the new child's left child.
 */
void treeDouble(Tree t);

/**
 * Deletes  and  frees  all  nodes in the given BST that contain a value
 * that  is  less than min or greater than max. Assumes that min is less
 * than or equal to max. Returns the root of the updated tree.
 */
Tree bstTrim(Tree bst, int min, int max);

/**
 * Returns  true if the given tree is height-balanced. A tree is height-
 * balanced  if,  for  every  node, the difference in height between its
 * left and right subtrees is no greater than 1.
 */
bool treeIsHeightBalanced(Tree t);

/**
 * Returns  true  if  the  given  tree is size-balanced. A tree is size-
 * balanced  if, for every node, the difference in size between its left
 * and right subtrees is no greater than 1.
 */
bool treeIsSizeBalanced(Tree t);

/**
 * Returns  the value of the lowest common ancestor of two values in the
 * given  BST. Assumes that the given values are in the tree. The lowest
 * ancestor of a value is considered to be itself.
 */
int bstLowestCommonAncestor(Tree bst, int val1, int val2);

/**
 * Deletes and frees all nodes that are below a given depth in the tree.
 * Frees  the  entire  tree if the given depth is 0 or negative. Returns
 * the root of the updated tree.
 */
Tree treePrune(Tree t, int depth);

/**
 * Returns a pointer to the node containing the inorder successor of the
 * given  number  in the tree. Returns NULL if the given number does not
 * exist in the tree or does not have an inorder successor. Assumes that
 * the given tree is a BST.
 */
Tree bstInorderSuccessor(Tree bst, int num);

/**
 * Returns true if the given tree is a BST, and false otherwise.
 */
bool treeIsBst(Tree t);

/**
 * Returns  true  if  the given tree is a max heap, and false otherwise.
 * Assumes that the given tree is complete.
 */
bool treeIsMaxHeap(Tree t);

/**
 * Returns  the  deepest  node in the given tree, or NULL if the tree is
 * empty. If there are multiple deepest nodes, return the rightmost one.
 */
Tree treeGetDeepest(Tree t);

////////////////////////////////////////////////////////////////////////
// Utility Functions

// You shouldn't use any of these functions in your code. (You shouldn't
// need to.)

Tree readTree(int *treeNo);

void showTree(Tree t);

void ensureTreeIsBst(Tree t);

void cleanupTree(Tree t);

#endif

