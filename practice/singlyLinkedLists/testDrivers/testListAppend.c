
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void) {
	printf("Enter list 1: ");
	List l1 = readList();
	printf("Enter list 2: ");
	List l2 = readList();

	printf("-----------------------------------\n"
	       " Before appending List 2 to List 1 \n"
	       "-----------------------------------\n");
	printf("List 1: ");
	listPrint(l1);
	printf("List 2: ");
	listPrint(l2);
	
	listAppend(l1, l2);
	
	printf("----------------------------------\n"
	       " After appending List 2 to List 1 \n"
	       "----------------------------------\n");
	printf("List 1: ");
	listPrint(l1);
	printf("List 2: ");
	listPrint(l2);
}

