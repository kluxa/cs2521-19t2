
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main(void) {
	Tree t = readTree(NULL);	
	ensureTreeIsBst(t);
	
	printf("Enter min: ");
	int min;
	scanf("%d", &min);
	printf("Enter max: ");
	int max;
	scanf("%d", &max);
	printf("\n");
	
	// ---------------------
	
	printf("-----------------\n"
	       " Before trimming \n"
	       "-----------------\n");
	showTree(t);
	
	printf("min: %d\n", min);
	printf("max: %d\n", max);
	printf("\n");
	
	// ---------------------
	
	t = bstTrim(t, min, max);
	
	// ---------------------
	
	printf("----------------\n"
	       " After trimming \n"
	       "----------------\n");
	showTree(t);
	
	// ---------------------
	
	cleanupTree(t);
}

