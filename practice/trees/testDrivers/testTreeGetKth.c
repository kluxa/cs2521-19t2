
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
	
	int k;
	printf("Enter k: ");
	while (scanf("%d", &k) == 1) {
		printf("k: %d\n", k);
		int value = treeGetKth(t, k);
		printf("treeGetKth returned: %d\n", value);
		printf("\n");
		printf("Enter k: ");
	}
	
	// ---------------------
	
	cleanupTree(t);
}

