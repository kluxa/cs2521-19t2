
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void) {
	printf("Enter list: ");
	List l = readList();
	
	printf("-------------------------\n"
	       " Before deleting largest \n"
	       "-------------------------\n");
	printf("List: ");
	listPrint(l);

	int max = listDeleteLargest(l);
	
	printf("------------------------\n"
	       " After deleting largest \n"
	       "------------------------\n");
	printf("List: ");
	listPrint(l);
	printf("Deleted element: %d\n", max);
}

