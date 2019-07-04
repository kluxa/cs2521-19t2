
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main(void) {
	Tree t = readTree(NULL);	
	ensureTreeIsBst(t);
	
	printf("Enter num: ");
	int num;
	scanf("%d", &num);
	printf("\n");
	
	// ---------------------
	
	printf("Tree:\n");
	showTree(t);
	printf("num: %d\n", num);
	printf("\n");
	
	// ---------------------
		
	Tree successor = bstInorderSuccessor(t, num);
	
	// ---------------------
		
	printf("bstInorderSuccessor returned: ");
	if (successor == NULL) {
		printf("NULL\n");
	} else {
		printf("%d\n", successor->value);
	}
	
	// ---------------------
	
	cleanupTree(t);
}

