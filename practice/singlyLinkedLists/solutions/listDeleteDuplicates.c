
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static Node listDelete(Node curr, int value);

void listDeleteDuplicates(List l) {
	// The general strategy is this:  For every node, delete all
	// nodes *after* it that have the same value.
	// QUESTION 1: Notice that in this function, we never update
	// the head of the list, nor do we need to.  Can you explain
	// why? (answers below)
	Node curr = l->head;
	while (curr != NULL) {
		curr->next = listDelete(curr->next, curr->value);
		curr = curr->next;
	}
}

// A recursive function to delete all nodes with the given value
// and then return the head of the list
static Node listDelete(Node curr, int value) {
	// If the list is empty, there's nothing to delete, hence we
	// return NULL
	if (curr == NULL) {
		return NULL;
	}
	
	// Firstly, we delete all the nodes after this one that have
	// the given value by calling this function recursively.
	curr->next = listDelete(curr->next, value);
	
	// QUESTION 2: What happens if we just had
	//                listDelete(curr->next, value);
	// and did not assign the return value to curr->next?
	
	// Now we deal with the current node. If it has the value we
	// want  to  delete, then we want to delete the node, so the
	// new head of the list becomes the next node.
	// QUESTION 3:  Is it possible for the next node to have the
	// value that we want to delete? Why/why not?
	if (curr->value == value) {
		Node temp = curr->next;
		free(curr);
		return temp;
	} else {
		return curr;
	}
}

// Answers to questions:
// 1. The head node will never be deleted by this function, because if
//    the value in the head node occurs more than once in the list, we
//    keep the first occurrence (as stated in the question).
//
// 2. Then if the next node is actually deleted by the recursive call,
//    curr->next would still be pointing to it,  and our list would be
//    inconsistent.
//
// 3. No, because the recursive call
//              curr->next = listDelete(curr->next, value);
//    ensures that the value does not occur in the rest of the list.
