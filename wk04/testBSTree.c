
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"

#define LF(value)              newBSTLink(value, NULL,  NULL) // leaf
#define LC(value, left)        newBSTLink(value, left,  NULL) // left child only
#define RC(value, right)       newBSTLink(value, NULL, right) // right child only
#define LR(value, left, right) newBSTLink(value, left, right) // two children

static void initTrees(void);

static void testTreeHeight(void);
static void testPrintHeightDiff(void);
static void testIsAVL(void);

static BSTree newBSTLink(int value, BSTree left, BSTree right);

static BSTree t01, t02, t03, t04, t05, t06, t07, t08, t09, t10,
              t11, t12, t13;


int main(void) {
    initTrees();
    
    testTreeHeight();
    testPrintHeightDiff();
    testIsAVL();
    
    printf("All tests passed!\n");
}

static void initTrees(void) {
    /*
        3
     */
    t01 =
        LF(3);
    
    /*
          6
         /
        3
     */
    t02 =
        LC(6,
            LF(3)
        );
    
    /*
        3
         \
          8
     */
    t03 =
        RC(3,
            LF(8)
        );
    
    /*
          6
         / \
        3   8
     */
    t04 =
        LR(6,
            LF(3),
            LF(8)
        );
    
    /*
            6
           /
          5
         /
        2
     */
    t05 =
        LC(6,
            LC(5,
                LF(2)
            )
        );
    
    /*
        3
         \
          4
           \
            7
     */
    t06 =
        RC(3,
            RC(4,
                LF(7)
            )
        );
    
    /*
          5
         / \
        2   6
             \
              8
     */
    t07 =
        LR(5,
            LF(2),
            RC(6,
                LF(8)
            )
        );

    /*
             5
            / \
           /   \
          3     7
         / \   / \
        2   4 6   8
     */
    t08 =
        LR(5,
            LR(3,
                LF(2),
                LF(4)
            ),
            LR(7,
                LF(6),
                LF(8)
            )
        );
    
    /*
            8
           /
          2
         / \
        1   7
     */
    t09 =
        LC(8,
            LR(2,
                LF(1),
                LF(7)
            )
        );
    
    /*
          2
         / \
        0   6
           / \
          4   8
     */
    t10 =
        LR(2,
            LF(0),
            LR(6,
                LF(4),
                LF(8)
            )
        );
    
    /*
        1
         \
          8
         /
        3
         \
          6
     */
    t11 =
        RC(1,
            LC(8,
                RC(3,
                    LF(6)
                )
            )
        );
    
    /*
              5
             / \
            4   6
           /     \
          3       7
         /         \
        2           8
     */
    t12 =
        LR(5,
            LC(4,
                LC(3,
                    LF(2)
                )
            ),
            RC(6,
                RC(7,
                    LF(8)
                )
            )
        );
    
    /*
                6
               / \
              /   \
             /     \
            4       8
           / \     /
          3   5   7
         /
        1
     */
    t13 =
        LR(6,
            LR(4,
                LC(3,
                    LF(1)
                ),
                LF(5)
            ),
            LC(8,
                LF(7)
            )
        );
}

static void testTreeHeight(void) {
    assert(TreeHeight(t01) == 0);
    assert(TreeHeight(t02) == 1);
    assert(TreeHeight(t03) == 1);
    assert(TreeHeight(t04) == 1);
    assert(TreeHeight(t05) == 2);
    assert(TreeHeight(t06) == 2);
    assert(TreeHeight(t07) == 2);
    assert(TreeHeight(t08) == 2);
    assert(TreeHeight(t09) == 2);
    assert(TreeHeight(t10) == 2);
    assert(TreeHeight(t11) == 3);
    assert(TreeHeight(t12) == 3);
    assert(TreeHeight(t13) == 3);

    printf("TreeHeight tests passed!\n");
}

static void testPrintHeightDiff(void) {
    printf("\n"
           "-----------------------\n"
           " printHeightDiff tests \n"
           "-----------------------\n");

    printf("\nt12:\n");
    printHeightDiff(t12);

    printf("\nt13:\n");
    printHeightDiff(t13);

    printf("\n");
}

static void testIsAVL(void) {
    assert(isAVL(t01) ==  0);
    assert(isAVL(t02) ==  1);
    assert(isAVL(t03) ==  1);
    assert(isAVL(t04) ==  1);
    assert(isAVL(t05) == -1);
    assert(isAVL(t06) == -1);
    assert(isAVL(t07) ==  2);
    assert(isAVL(t08) ==  2);
    assert(isAVL(t09) == -1);
    assert(isAVL(t10) ==  2);
    assert(isAVL(t11) == -1);
    assert(isAVL(t12) == -1);
    assert(isAVL(t13) ==  3);

    printf("isAVL tests passed!\n");
}

// ----------------------------------------

static BSTree newBSTLink(int value, BSTree left, BSTree right) {
    BSTree t = malloc(sizeof(*t));
    if (t == NULL) {
        fprintf(stderr, "Insufficient memory!\n");
        exit(EXIT_FAILURE);
    }

    t->value = value;
    t->right = right;
    t->left = left;
    return t;
}
