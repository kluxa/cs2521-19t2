
#ifndef BSTREE_H
#define BSTREE_H

typedef struct BSTNode *BSTree;
typedef struct BSTNode {
    int value;
    BSTree left;
    BSTree right;
} BSTNode;

/**
 * Returns the number of nodes in the tree.
 */
int TreeNumNodes(BSTree t);

/**
 * Returns  the  height of the given tree. The height of a tree is the
 * number  of  edges  on the longest path from the root node to a leaf
 * node. The height of an empty tree is 0 (this can be -1 depending on
 * the specification).
 */
int TreeHeight(BSTree t);

/**
 * Returns  the number of internal nodes in the tree. An internal node
 * is a node that has one or more children, i.e., a node that is not a
 * leaf.
 */
int countInternal(BSTree t);

/**
 * Returns  the depth of the node containing the given key in the tree
 * if it exists, or -1 otherwise.
 */
int nodeDepth(BSTree t, int key);

/**
 * Returns  the  maximum  branch length of the given tree. The maximum
 * branch length is defined as the number of edges on the longest path
 * from the root to a leaf.
 */
int BSTreeMaxBranchLen(BSTree t);

/**
 * Returns the width of the given tree. Width is defined as follows:
 * - an empty tree has width zero
 * - a tree with just one node has width three
 * - all  other trees have width which is three more than the combined
 *   width of the subtrees
 */
int BSTWidth(BSTree t);

#endif
