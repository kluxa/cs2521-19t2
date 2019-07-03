
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main(void) {
	Tree t = readTree(NULL);	
	printf("\n");
	
	// ---------------------
	
	printf("--------------------------\n"
	       " Before doubling the tree \n"
	       "--------------------------\n");
	showTree(t);
	
	// ---------------------
	
	treeDouble(t);
	
	// ---------------------
	
	printf("-------------------------\n"
	       " After doubling the tree \n"
	       "-------------------------\n");
	showTree(t);
	
	// ---------------------
	
	cleanupTree(t);
}

