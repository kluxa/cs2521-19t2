
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void) {
	printf("Enter list 1: ");
	List l1 = readList();
	printf("Enter list 2: ");
	List l2 = readList();

	printf("-----------------\n"
	       " Before deleting \n"
	       "-----------------\n");
	printf("List 1: ");
	listPrint(l1);
	printf("List 2: ");
	listPrint(l2);
	
	listDeleteIntersection(l1, l2);
	
	printf("----------------\n"
	       " After deleting \n"
	       "----------------\n");
	printf("List 1: ");
	listPrint(l1);
	printf("List 2: ");
	listPrint(l2);
}

