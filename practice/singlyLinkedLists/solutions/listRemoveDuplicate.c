
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/**
 * Removes  the  second  instance of the duplicate in the list (if there
 * is  one),  and returns the value that was deleted, or NO_DUPLICATE if
 * there was no duplicate. You can assume that there is at most one
 * duplicate value.
 *
 * Examples:
 *       input list       |  return value  |    resulting list
 * -----------------------+----------------------------------------
 *  2 -> 4 -> 6 -> 4 -> X |       4        | 2 -> 4 -> 6 -> X
 *  4 -> 5 -> 6 -> 4 -> X |       4        | 4 -> 5 -> 6 -> X
 *  6 -> 6 -> 1 -> 8 -> X |       6        | 6 -> 1 -> 8 -> X
 *  1 -> 2 -> 3 -> 4 -> X |  NO_DUPLICATE  | 1 -> 2 -> 3 -> 4 -> X
 *  4 -> X                |  NO_DUPLICATE  | 4 -> X
 *  X                     |  NO_DUPLICATE  | X
 */
int listRemoveDuplicate(List l) {
	Node curr1 = l->head;
	while (curr1 != NULL) {
		Node prev = curr1;
		Node curr2 = curr1->next;
		while (curr2 != NULL) {
			if (curr1->value == curr2->value) {
				prev->next = curr2->next;
				free(curr2);
				return curr1->value;
			}
			prev = curr2;
			curr2 = curr2->next;
		}
		curr1 = curr1->next;
	}
	return NO_DUPLICATE;
}

