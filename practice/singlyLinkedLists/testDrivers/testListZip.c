
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void) {
	printf("Enter list 1: ");
	List l1 = readList();
	printf("Enter list 2: ");
	List l2 = readList();

	printf("List 1: ");
	listPrint(l1);
	printf("List 2: ");
	listPrint(l2);
	
	List l3 = listZip(l1, l2);
	
	printf("listZip returned: ");
	listPrint(l3);
}

