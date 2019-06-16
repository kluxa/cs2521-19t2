
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/**
 * Reverses the given list.
 */
void listReverse(List l) {
	Node prev = NULL;
	Node curr = l->head;
	while (curr != NULL) {
		Node temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	l->head = prev;
}

