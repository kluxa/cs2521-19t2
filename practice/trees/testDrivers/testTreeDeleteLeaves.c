
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main(void) {
	Tree t = readTree(NULL);	
	printf("\n");
	
	// ---------------------
	
	printf("------------------------\n"
	       " Before deleting leaves \n"
	       "------------------------\n");
	showTree(t);
	
	// ---------------------
	
	t = treeDeleteLeaves(t);
	
	// ---------------------
	
	printf("-----------------------\n"
	       " After deleting leaves \n"
	       "-----------------------\n");
	showTree(t);
	
	// ---------------------
	
	cleanupTree(t);
}

