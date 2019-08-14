
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define RECURSIVE 1

#if RECURSIVE //////////////////////////////////////////////////////////

static Node doListDeleteNth(Node curr, int n, int *value);

int listDeleteNth(List l, int n) {
	int value;
	l->head = doListDeleteNth(l->head, n, &value);
	return value;
}

// Uses  recursion  to  delete  the  n'th value from the list, store the
// deleted value in *value, and return the head of the list.
// Since we also need to return the value that was deleted, we pass in a
// pointer to an int so we can 'return' two values.
static Node doListDeleteNth(Node head, int n, int *value) {
	if (head == NULL) {
		fprintf(stderr, "listDeleteNth: n out of range\n");
		exit(EXIT_FAILURE);
	}
	
	// If  n  is 0 then we must delete the head node and return the next
	// node, since the next node becomes the new head of the list.
	if (n == 0) {
		*value = head->value;
		Node newHead = head->next;
		free(head);
		return newHead;
	
	// Otherwise,  recurse to delete the (n - 1)'th value of the rest of
	// the list. The head doesn't change so just return it.
	} else {
		head->next = doListDeleteNth(head->next, n - 1, value);
		return head;
	}
}

#else // ITERATIVE /////////////////////////////////////////////////////

int listDeleteNth(List l, int n) {
	int value;
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
	
	return value;
}

#endif
