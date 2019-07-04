
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main(void) {
	Tree t = readTree(NULL);	
	ensureTreeIsBst(t);
	printf("\n");
	
	// ---------------------
	
	printf("Tree:\n");
	showTree(t);
	
	// ---------------------
	
	int size;
	int *inorder = bstGetInorderTraversal(t, &size);
	
	// ---------------------
	
	printf("Returned array:");
	for (int i = 0; i < size; i++) {
		printf(" %d", inorder[i]);
	}
	printf("\n");
	free(inorder);
	
	// ---------------------
	
	cleanupTree(t);
}

