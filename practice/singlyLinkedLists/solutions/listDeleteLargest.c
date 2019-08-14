
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define RECURSIVE 1 // <-- Set this to 0 and the iterative solution will
                    //     be compiled instead

static int listGetLargest(List l);

#if RECURSIVE //////////////////////////////////////////////////////////

static Node listDeleteOnce(Node curr, int value);

int listDeleteLargest(List l) {
	if (l->head == NULL) {
		fprintf(stderr, "listDeleteLargest: empty list\n");
		exit(EXIT_FAILURE);
	}
	
	int max = listGetLargest(l);
	l->head = listDeleteOnce(l->head, max);
	return max;
}

// Uses recursion to delete the first instance of a value from the list,
// and return the head of the list.
static Node listDeleteOnce(Node curr, int value) {
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
		curr->next = listDeleteOnce(curr->next, value);
		return curr;
	}
}

#else // ITERATIVE /////////////////////////////////////////////////////

int listDeleteLargest(List l) {
	if (l->head == NULL) {
		fprintf(stderr, "listDeleteLargest: empty list\n");
		exit(EXIT_FAILURE);
	}
	
	int max = listGetLargest(l);
	
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
	
	return max;
}

#endif /////////////////////////////////////////////////////////////////

// Helper function
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
