
#ifndef BSTREE_H
#define BSTREE_H

typedef struct BSTNode *BSTree;
struct BSTNode {
	int value;
	BSTree left;
	BSTree right;
};

BSTree bstInsert(BSTree t, int value);

void bstPrint(BSTree t);

#endif
