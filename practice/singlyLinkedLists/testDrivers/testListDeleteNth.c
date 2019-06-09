
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void) {
	printf("Enter list: ");
	List l = readList();
	printf("Enter n: ");
	int n;
	scanf("%d", &n);
	
	printf("-----------------\n"
	       " Before deleting \n"
	       "-----------------\n");
	printf("List: ");
	listPrint(l);
	printf("n: %d\n", n);

	int value = listDeleteNth(l, n);
	
	printf("----------------\n"
	       " After deleting \n"
	       "----------------\n");
	printf("List: ");
	listPrint(l);
	printf("Deleted value: %d\n", value);
}

