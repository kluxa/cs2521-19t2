
#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"

int main(void) {
	BSTree t = NULL;
	bstInsert(t, 5);
	bstInsert(t, 3);
	bstInsert(t, 1);
	bstInsert(t, 6);
	bstInsert(t, 8);
	
	printf("Tree:\n");
	bstPrint(t);
}
