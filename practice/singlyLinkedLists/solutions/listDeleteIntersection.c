
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static bool listContains(List l, int value);
static void listDeleteAll(List l, int value);
static Node listDelete(Node curr, int value);

/**
 * Deletes all values that occur in both lists from both lists.
 */
void listDeleteIntersection(List l1, List l2) {
	// Okay, this is 
	Node curr = l1->head;
	while (curr != NULL) {
		if (listContains(l2, curr->value)) {
			int toBeDeleted = curr->value;
			// Since the value in curr is contained in both lists,
			// we will end up deleting curr, so we should advance
			// curr until it points to a node that won't be
			// deleted
			while (curr != NULL && curr->value == toBeDeleted) {
				curr = curr->next;
			}
			
			listDeleteAll(l1, toBeDeleted);
			listDeleteAll(l2, toBeDeleted);
		} else {
			curr = curr->next;
		}
	}
}

static bool listContains(List l, int value) {
	Node curr;
	for (curr = l->head; curr != NULL; curr = curr->next) {
		if (curr->value == value) {
			return true;
		}
	}
	return false;
}

// Deletes all instances of a given value from a list
static void listDeleteAll(List l, int value) {
	l->head = listDelete(l->head, value);
}

// A recursive function to delete all nodes with the given value
// and then return the head of the list
static Node listDelete(Node curr, int value) {
	if (curr == NULL) {
		return NULL;
	}
	
	curr->next = listDelete(curr->next, value);

	if (curr->value == value) {
		Node temp = curr->next;
		free(curr);
		return temp;
	} else {
		return curr;
	}
}

