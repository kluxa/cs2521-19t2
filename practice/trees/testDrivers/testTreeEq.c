
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main(void) {
	int num1 = 1;
	Tree t1 = readTree(&num1);
	int num2 = 2;
	Tree t2 = readTree(&num2);	
	printf("\n");
	
	// ---------------------
	
	printf("Tree 1:\n");	
	showTree(t1);
	printf("Tree 2:\n");	
	showTree(t2);
	
	// ---------------------
	
	bool eq = treeEq(t1, t2);
	
	// ---------------------
	
	printf("treeEq returned: %s\n", eq ? "TRUE" : "FALSE");
	
	// ---------------------
	
	cleanupTree(t1);
	cleanupTree(t2);
}

