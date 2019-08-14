
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define SOLUTION 1

#if SOLUTION == 1 //////////////////////////////////////////////////////

static int listLength(List l);

int listKthLast(List l, int k) {
	int length = listLength(l);
	Node curr = l->head;
	int i = 0;
	while (i < length - k) {
		curr = curr->next;
		i++;
	}
	return curr->value;
}

static int listLength(List l) {
	int length = 0;
	Node curr;
	for (curr = l->head; curr != NULL; curr = curr->next) {
		length++;
	}
	return length;
}

#else // SOLUTION 2 ////////////////////////////////////////////////////

int listKthLast(List l, int k) {
	// Does not need to know the length of the list beforehand
	Node curr1 = l->head;
	Node curr2 = l->head;
	for (int i = 0; i < k; i++) {
		curr2 = curr2->next;
	}
	while (curr2 != NULL) {
		curr1 = curr1->next;
		curr2 = curr2->next;
	}
	return curr1->value;
}

#endif
