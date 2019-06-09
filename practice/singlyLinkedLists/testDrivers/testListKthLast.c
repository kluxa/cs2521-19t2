
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void) {
	printf("Enter list: ");
	List l = readList();
	printf("Enter k: ");
	int k;
	scanf("%d", &k);
	
	printf("List: ");
	listPrint(l);
	printf("k: %d\n", k);

	int value = listKthLast(l, k);
	printf("listKthLast returned the value %d\n", value);
}

