
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define RECURSIVE 1

#if RECURSIVE //////////////////////////////////////////////////////////

static bool doListIsAscending(Node curr);

bool listIsAscending(List l) {
	return doListIsAscending(l->head);
}

static bool doListIsAscending(Node curr) {
	// If  the  list  is  empty  or only contains one element, then it's
	// automatically sorted.
	if (curr == NULL || curr->next == NULL) {
		return true;
	
	// If  the  first  value  is greater than the second value, then the
	// list is not sorted :(
	} else if (curr->value > curr->next->value) {
		return false;
	
	// If  we reach this, then we know that the first value is less than
	// or  equal  to the second value, so all we need to do is check the
	// rest of the list :)
	} else {
		return doListIsAscending(curr->next);
	}
}

#else // ITERATIVE /////////////////////////////////////////////////////

/**
 * Returns  true if the list is in ascending order, and false otherwise.
 * For  example, 2 -> 3 -> 3 -> 5 -> X is ascending, 2 -> 5 -> 3 -> X is
 * not. An empty list is considered to be ascending.
 */
bool listIsAscending(List l) {
	if (l->head == NULL) {
		return true;
	}
	
	Node curr = l->head;
	while (curr->next != NULL) {
		if (curr->value > curr->next->value) {
			return false;
		}
		curr = curr->next;
	}
	return true;
}

#endif
