
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void) {
	printf("Enter list: ");
	List l = readList();

	printf("-----------------------------\n"
	       " Before preserving ascending \n"
	       "-----------------------------\n");
	printf("List: ");
	listPrint(l);

	listPreserveAscending(l);
	
	printf("----------------------------\n"
	       " After preserving ascending \n"
	       "----------------------------\n");
	printf("List: ");
	listPrint(l);
}

