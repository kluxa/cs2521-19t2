
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void) {
	printf("Enter list: ");
	List l = readList();

	printf("---------------------------\n"
	       " Before deleting multiples \n"
	       "---------------------------\n");
	printf("List: ");
	listPrint(l);

	listDeleteMultiples(l);
	
	printf("--------------------------\n"
	       " After deleting multiples \n"
	       "--------------------------\n");
	printf("List: ");
	listPrint(l);
}

