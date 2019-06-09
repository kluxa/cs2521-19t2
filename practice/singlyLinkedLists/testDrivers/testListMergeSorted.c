
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static void checkSorted(List l);

int main(void) {
	printf("Enter list 1: ");
	List l1 = readList();
	printf("Enter list 2: ");
	List l2 = readList();

	printf("List 1: ");
	listPrint(l1);
	checkSorted(l1);
	printf("List 2: ");
	listPrint(l2);
	checkSorted(l2);
	
	List l3 = listMergeSorted(l1, l2);
	
	printf("listMergeSorted returned: ");
	listPrint(l3);
}

static void checkSorted(List l) {
	if (l->head == NULL) {
		return;
	}
	
	Node curr = l->head;
	while (curr->next != NULL) {
		if (curr->value > curr->next->value) {
			fprintf(stderr, "Error: The list is not sorted!\n");
			exit(EXIT_FAILURE);
		}
		curr = curr->next;
	}
}

