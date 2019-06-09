
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void) {
	printf("Enter list: ");
	List l = readList();
	printf("Enter k: ");
	int k;
	scanf("%d", &k);
	
	printf("-----------------\n"
	       " Before deleting \n"
	       "-----------------\n");
	printf("List: ");
	listPrint(l);
	printf("k: %d\n", k);

	listDeleteEveryKth(l, k);
	
	printf("----------------\n"
	       " After deleting \n"
	       "----------------\n");
	printf("List: ");
	listPrint(l);
}

