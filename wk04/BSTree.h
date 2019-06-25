
#ifndef BSTREE_H
#define BSTREE_H

#define NOT_AVL -99

typedef struct BSTNode *BSTree;
typedef struct BSTNode {
    int value;
    BSTree left;
    BSTree right;
} BSTNode;

/**
 * Returns  the  height of the given tree. The height of a tree is the
 * number  of  edges  on the longest path from the root node to a leaf
 * node. The height of an empty tree is -1.
 */
int TreeHeight(BSTree t);

/**
 * Prints the height difference between the left subtree and the right
 * subtree  of  every  node  in the given binary tree, and returns the
 * height of the binary tree.
 */
int printHeightDiff(BSTree t);

/**
 * Returns  the  height of the given binary tree if it is an AVL tree,
 * and NOT_AVL otherwise.
 */
int isAVL(BSTree t);

#endif
