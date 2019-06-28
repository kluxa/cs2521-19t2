
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
    if (t == NULL) {
        return -1;
    } else {
        int l = printHeightDiff(t->left);
        int r = printHeightDiff(t->right);
        printf("At node %d, height(left) - height(right) = %d\n",
               t->value, l - r);
        return 1 + (l > r ? l : r);
    }
}

/**
 * Returns  the  height of the given binary tree if it is an AVL tree,
 * and NOT_AVL otherwise.
 */
int isAVL(BSTree t) {
    if (t == NULL) {
        return -1;
    } else {
        int l = isAVL(t->left);
        int r = isAVL(t->right);
        // If  the left or right subtree is not an AVL tree, then the
        // the current tree is also not an AVL tree.
        if (l == NOT_AVL || r == NOT_AVL) {
            return NOT_AVL;
        }
        // If  the  difference  in  height between the left and right
        // subtrees is greater than 1, then the tree is not AVL.
        if (l - r > 1 || r - l > 1) {
            return NOT_AVL;
        }

        return 1 + (l > r ? l : r);
    }
}
