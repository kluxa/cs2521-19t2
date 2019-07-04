
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
		
	int result = treeNumInternal(t);
	
	// ---------------------
		
	printf("treeNumInternal returned: %d\n", result);
	
	// ---------------------
	
	cleanupTree(t);
}

