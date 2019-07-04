
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main(void) {
	Tree t = readTree(NULL);	
	printf("\n");
	
	// ---------------------
	
	printf("----------------------------\n"
	       " Before reflecting the tree \n"
	       "----------------------------\n");
	showTree(t);
	
	// ---------------------
	
	treeReflect(t);
	
	// ---------------------
	
	printf("---------------------------\n"
	       " After reflecting the tree \n"
	       "---------------------------\n");
	showTree(t);
	
	// ---------------------
	
	cleanupTree(t);
}

