
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main(void) {
	Tree t = readTree(NULL);	
	
	printf("Enter depth: ");
	int depth;
	scanf("%d", &depth);
	printf("\n");
	
	// ---------------------
	
	printf("----------------\n"
	       " Before pruning \n"
	       "----------------\n");
	showTree(t);
	
	printf("depth: %d\n", depth);
	printf("\n");
	
	// ---------------------
	
	t = treePrune(t, depth);
	
	// ---------------------
	
	printf("---------------\n"
	       " After pruning \n"
	       "---------------\n");
	showTree(t);
	
	// ---------------------
	
	cleanupTree(t);
}

