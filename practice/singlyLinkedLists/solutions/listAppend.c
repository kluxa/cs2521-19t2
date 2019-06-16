
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/**
 * Appends  the second list to the end of the first list. The first list
 * should end up with the values from both of the original lists and the
 * second list should end up empty.
 *
 * Examples:
 *      input l1     |     input l2     |         resulting l1       | resulting l2
 * ------------------+------------------+----------------------------+--------------
 *  4 -> 7 -> 1 -> X | 3 -> 2 -> X      | 4 -> 7 -> 1 -> 3 -> 2 -> X |       X
 *  2 -> 6 -> X      | X                | 2 -> 6 -> X                |       X
 *  X                | 2 -> 8 -> 9 -> X | 2 -> 8 -> 9 -> X           |       X
 *  1 -> X           | 1 -> X           | 1 -> 1 -> X                |       X
 */
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

