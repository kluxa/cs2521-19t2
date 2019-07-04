
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main(void) {
	Tree t = readTree(NULL);	
	printf("\n");
	
	// ---------------------
		
	printf("Tree:\n");
	showTree(t);
	
	// ---------------------
	
	Tree deepest = treeGetDeepest(t);
	
	// ---------------------
	
	printf("treeGetDeepest returned: ");
	if (deepest == NULL) {
		printf("NULL\n");
	} else {
		printf("%d\n", deepest->value);
	}
	
	// ---------------------
	
	cleanupTree(t);
}

