
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void) {
	printf("Enter list: ");
	List l = readList();
	
	printf("List: ");
	listPrint(l);

	bool result = listIsPalindromic(l);
	
	printf("listIsPalindromic returned %s\n", result ? "TRUE" : "FALSE");
}

