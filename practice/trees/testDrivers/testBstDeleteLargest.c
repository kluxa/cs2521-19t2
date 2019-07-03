
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main(void) {
	Tree t = readTree(NULL);	
	ensureTreeIsBst(t);
	printf("\n");
	
	// ---------------------
		
	printf("-------------------------\n"
	       " Before deleting largest \n"
	       "-------------------------\n");
	showTree(t);
	
	// ---------------------
	
	int num = 0;
	t = bstDeleteLargest(t, &num);
	
	// ---------------------
	
	printf("------------------------\n"
	       " After deleting largest \n"
	       "------------------------\n");
	showTree(t);
	
	printf("Deleted value: %d\n", num);
	
	// ---------------------
	
	cleanupTree(t);
}

