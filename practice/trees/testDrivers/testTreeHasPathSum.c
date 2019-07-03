
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
	
	int sum;
	printf("Enter sum: ");
	while (scanf("%d", &sum) == 1) {
		printf("sum: %d\n", sum);
		bool result = treeHasPathSum(t, sum);
		printf("treeHasPathSum returned: %s\n", result ? "TRUE" : "FALSE");
		printf("\n");
		printf("Enter sum: ");
	}
	
	// ---------------------
	
	cleanupTree(t);
}

