
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
		
	bool result = treeIsBst(t);
	
	// ---------------------
		
	printf("treeIsBst returned: %s\n", result ? "TRUE" : "FALSE");
	
	// ---------------------
	
	cleanupTree(t);
}

