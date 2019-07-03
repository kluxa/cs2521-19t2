
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main(void) {
	Tree t = readTree(NULL);	
	ensureTreeIsBst(t);
	
	printf("Enter val1: ");
	int val1;
	scanf("%d", &val1);
	printf("Enter val2: ");
	int val2;
	scanf("%d", &val2);
	printf("\n");
	
	// ---------------------
	
	printf("Tree:\n");
	showTree(t);
	
	printf("val1: %d\n", val1);
	printf("val2: %d\n", val2);
	printf("\n");
	
	// ---------------------
	
	int ancestor = bstLowestCommonAncestor(t, val1, val2);
	
	// ---------------------
	
	printf("bstLowestCommonAncestor returned: %d\n", ancestor);
	
	// ---------------------
	
	cleanupTree(t);
}

