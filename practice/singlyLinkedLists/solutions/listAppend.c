
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void listAppend(List l1, List l2) {
	// l1 is empty
	if (l1->head == NULL) {
		l1->head = l2->head;
	
	} else {
		// Stop at the last node of l1
		// and append l2
		Node curr = l1->head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = l2->head;
	}
	
	l2->head = NULL;
}
