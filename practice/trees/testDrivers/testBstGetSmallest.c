
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
	
	Tree smallest = bstGetSmallest(t);
	
	// ---------------------
	
	printf("bstGetSmallest returned: ");
	if (smallest == NULL) {
		printf("NULL\n");
	} else {
		printf("%d\n", smallest->value);
	}
	
	// ---------------------
	
	cleanupTree(t);
}

