
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int listRemoveDuplicate(List l) {
	Node curr1 = l->head;
	while (curr1 != NULL) {
		// Look for a node containing the same value as curr1
		Node prev2 = curr1;
		Node curr2 = curr1->next;
		while (curr2 != NULL) {
			// If we find such a node, delete it
			if (curr1->value == curr2->value) {
				prev2->next = curr2->next;
				free(curr2);
				return curr1->value;
			}
			prev2 = curr2;
			curr2 = curr2->next;
		}
		curr1 = curr1->next;
	}
	return NO_DUPLICATE;
}
