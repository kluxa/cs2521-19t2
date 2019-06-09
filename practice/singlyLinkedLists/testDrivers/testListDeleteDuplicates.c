
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void) {
	printf("Enter list: ");
	List l = readList();

	printf("----------------------------\n"
	       " Before deleting duplicates \n"
	       "----------------------------\n");
	printf("List: ");
	listPrint(l);

	listDeleteDuplicates(l);
	
	printf("---------------------------\n"
	       " After deleting duplicates \n"
	       "---------------------------\n");
	printf("List: ");
	listPrint(l);
}

