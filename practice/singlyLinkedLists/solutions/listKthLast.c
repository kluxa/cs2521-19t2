
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define ALTERNATIVE 1

#if !ALTERNATIVE
static int listLength(List l);
#endif

/**
 * Returns the k'th last element in the list. You can assume that k will
 * be between 1 and N where N is the length of the list.  You can assume
 * that the list contains at least one element (i.e., it is not empty).
 */
int listKthLast(List l, int k) {
	#if ALTERNATIVE
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
	
	#else 
	int length = listLength(l);
	Node curr = l->head;
	int i = 0;
	while (i < length - k) {
		curr = curr->next;
		i++;
	}
	return curr->value;
	#endif
}

#if !ALTERNATIVE
static int listLength(List l) {
	int length = 0;
	Node curr;
	for (curr = l->head; curr != NULL; curr = curr->next) {
		length++;
	}
	return length;
}
#endif

