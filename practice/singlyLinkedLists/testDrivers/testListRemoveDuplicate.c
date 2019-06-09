
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void) {
	printf("Enter list: ");
	List l = readList();
	
	printf("---------------------------\n"
	       " Before removing duplicate \n"
	       "---------------------------\n");
	printf("List: ");
	listPrint(l);

	int value = listRemoveDuplicate(l);
	
	printf("--------------------------\n"
	       " After removing duplicate \n"
	       "--------------------------\n");
	printf("List: ");
	listPrint(l);
	
	if (value == NO_DUPLICATE) {
		printf("listRemoveDuplicate returned NO_DUPLICATE\n");
	} else {
		printf("Removed value: %d\n", value);
	}
}

