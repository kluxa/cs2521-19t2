
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
		
	int result = treeSumEvens(t);
	
	// ---------------------
		
	printf("treeSumEvens returned: %d\n", result);
	
	// ---------------------
	
	cleanupTree(t);
}

