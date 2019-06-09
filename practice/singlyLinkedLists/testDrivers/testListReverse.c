
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void) {
	printf("Enter list: ");
	List l = readList();
	
	printf("------------------\n"
	       " Before reversing \n"
	       "------------------\n");
	printf("List: ");
	listPrint(l);

	listReverse(l);
	
	printf("-----------------\n"
	       " After reversing \n"
	       "-----------------\n");
	printf("List: ");
	listPrint(l);
}

