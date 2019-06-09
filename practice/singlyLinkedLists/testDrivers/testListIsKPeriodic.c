
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void) {
	printf("Enter list: ");
	List l = readList();
	printf("Enter k: ");
	int k = 0;
	scanf("%d", &k);
	
	printf("List: ");
	listPrint(l);
	printf("k: %d\n", k);

	bool result = listIsKPeriodic(l, k);
	
	printf("listIsKPeriodic returned %s\n", result ? "TRUE" : "FALSE");
}

