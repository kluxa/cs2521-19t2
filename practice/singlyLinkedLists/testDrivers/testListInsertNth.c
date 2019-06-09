
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void) {
	printf("Enter list: ");
	List l = readList();
	printf("Enter value to insert: ");
	int value;
	scanf("%d", &value);
	printf("Enter n: ");
	int n;
	scanf("%d", &n);
	
	printf("------------------\n"
	       " Before inserting \n"
	       "------------------\n");
	printf("List: ");
	listPrint(l);
	printf("value: %d\n", value);
	printf("n: %d\n", n);

	listInsertNth(l, value, n);
	
	printf("-----------------\n"
	       " After inserting \n"
	       "-----------------\n");
	printf("List: ");
	listPrint(l);
}

