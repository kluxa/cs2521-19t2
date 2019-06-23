
#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"

/**
 * Returns  the  height of the given tree. The height of a tree is the
 * number  of  edges  on the longest path from the root node to a leaf
 * node. The height of an empty tree is 0 (this can be -1 depending on
 * the specification).
 */
int TreeHeight(BSTree t) {
    if (t == NULL) {
        return -1;
    } else {
        int l = TreeHeight(t->left);
        int r = TreeHeight(t->right);
        return 1 + (l > r ? l : r);
    }
}

/**
 * Prints the height difference between the left subtree and the right
 * subtree  of  every  node  in the given binary tree, and returns the
 * height of the binary tree.
 */
int printHeightDiff(BSTree t) {
    return -1;
}

/**
 * Returns  the  height of the given binary tree if it is an AVL tree,
 * and -1 otherwise.
 */
int isAVL(BSTree t) {
    return -1;
}
