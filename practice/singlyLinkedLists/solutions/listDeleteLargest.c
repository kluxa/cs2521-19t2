
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define RECURSIVE 1 // <-- Set this to 0 and the iterative solution will
                    //     be compiled instead

static int listGetLargest(List l);

#if RECURSIVE
static Node listDeleteOne(Node curr, int value);
#endif

/**
 * Deletes  the  largest  value from the list and returns the value that
 * was deleted.
 * If  the  list  is empty, the function should exit with an appropriate
 * error message (not tested).
 * If  the  largest  value  occurs more than once, delete only the first
 * instance.
 *
 * Examples:
 *        input list      | expected return value |  resulting list
 * -----------------------+-----------------------+------------------
 *  3 -> 7 -> 2 -> 7 -> X |           7           | 3 -> 2 -> 7 -> X
 *  4 -> 5 -> 7 -> 1 -> X |           7           | 4 -> 5 -> 1 -> X
 *  8 -> 4 -> 1 -> X      |           8           | 4 -> 1 -> X
 *  5 -> X                |           5           | X
 */
int listDeleteLargest(List l) {
	if (l->head == NULL) {
		fprintf(stderr, "listDeleteLargest: empty list\n");
		exit(EXIT_FAILURE);
	}
	
	int max = listGetLargest(l);
	
	#if RECURSIVE
	l->head = listDeleteOne(l->head, max);
	
	#else // Below is the iterative solution
	Node prev = NULL;
	Node curr = l->head;
	while (curr->value != max) {
		prev = curr;
		curr = curr->next;
	}
	
	if (curr == l->head) {
		l->head = curr->next;
	} else {
		prev->next = curr->next;
	}
	free(curr);
	#endif
	
	return max;
}

static int listGetLargest(List l) {
	int max = l->head->value;
	Node curr = l->head;
	while (curr != NULL) {
		if (curr->value > max) {
			max = curr->value;
		}
		curr = curr->next;
	}
	return max;
}

#if RECURSIVE
// Uses recursion to delete the first instance of a value from the list,
// and return the head of the list.
static Node listDeleteOne(Node curr, int value) {
	if (curr == NULL) {
		return NULL;
	}
	
	// If  the value in the current node is the value we want to delete,
	// free the node, and return the next node (since it becomes the new
	// head of the list), but *don't* recurse, since we're only deleting
	// the first instance of the value!
	if (curr->value == value) {
		Node temp = curr->next;
		free(curr);
		return temp;
	} else {
		curr->next = listDeleteOne(curr->next, value);
		return curr;
	}
}
#endif

