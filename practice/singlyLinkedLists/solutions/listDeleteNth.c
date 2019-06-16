
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define RECURSIVE 1

#if RECURSIVE
static Node doListDeleteNth(Node curr, int n, int *value);
#endif

/**
 * Deletes  the  value  in the n'th position of the list and returns the
 * value that was deleted.
 * If  n  is 0, the value at the beginning of the list should be deleted
 * and returned.
 * If  n  is equal to N - 1 where N is the length of the list, the value
 * at the end of the list should be deleted and returned.
 * You  can  assume n is between 0 and N - 1 (inclusive). You can assume
 * the list is non-empty.
 *
 * Examples:
 *        input list      |  n  |  return value  |  resulting list
 * -----------------------+-----+----------------+------------------
 *  5 -> 2 -> 7 -> 1 -> X |  0  |       5        | 2 -> 7 -> 1 -> X
 *  5 -> 2 -> 7 -> 1 -> X |  1  |       2        | 5 -> 7 -> 1 -> X
 *  5 -> 2 -> 7 -> 1 -> X |  3  |       1        | 5 -> 2 -> 7 -> X
 *  4 -> X                |  0  |       4        | X
 */
int listDeleteNth(List l, int n) {
	int value;
	
	#if RECURSIVE
	l->head = doListDeleteNth(l->head, n, &value);
	
	#else // ITERATIVE
	Node prev = NULL;
	Node curr = l->head;

	// Deleting the first element
	if (n == 0) {
		value = l->head->value;
		l->head = curr->next;
		free(curr);
	
	} else {
		int i = 0;
		// Loop until the nth node
		while (i < n) {
			prev = curr;
			curr = curr->next;
			i++;
		}
		
		value = curr->value;
		prev->next = curr->next;
		free(curr);
	}
	#endif
	
	return value;
}

#if RECURSIVE
// Uses  recursion  to  delete  the  n'th value from the list, store the
// deleted value in *value, and return the head of the list.
// Since we also need to return the value that was deleted, we pass in a
// pointer to an int so we can 'return' two values.
static Node doListDeleteNth(Node curr, int n, int *value) {
	if (curr == NULL) {
		fprintf(stderr, "listDeleteNth: n out of range\n");
		exit(EXIT_FAILURE);
	}
	
	// If  we  need  to delete the current value, free it and return the
	// next node, since it becomes the new head of the list.
	if (n == 0) {
		*value = curr->value;
		Node temp = curr->next;
		free(curr);
		return temp;
	
	// Otherwise,  recurse to delete the (n - 1)'th value of the rest of
	// the list.
	} else {
		curr->next = doListDeleteNth(curr->next, n - 1, value);
		return curr;
	}
}
#endif

