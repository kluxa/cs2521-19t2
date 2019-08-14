
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define RECURSIVE 1

#if RECURSIVE //////////////////////////////////////////////////////////

static Node doListPreserveAscending(Node head);

void listPreserveAscending(List l) {
	l->head = doListPreserveAscending(l->head);
}

static Node doListPreserveAscending(Node head) {
	// An  empty  list  or  a  list  with  only  one value is already in
	// ascending order.
	if (head == NULL || head->next == NULL) {
		return head;
	}

	// If the first value is larger than the second value, we remove the
	// second  value,  and recursively call the function with the *same*
	// head  node,  since  we need to again compare the first value with
	// the second value, which has now changed.
	if (head->value > head->next->value) {
		Node temp = head->next;
		head->next = temp->next;
		free(temp);
		return doListPreserveAscending(head);
	
	// Otherwise,  the  first  two  values  are  in  order,  so call the
	// function recursively on the next node.
	} else {
		head->next = doListPreserveAscending(head->next);
		return head;
	}
}

#else // ITERATIVE /////////////////////////////////////////////////////

void listPreserveAscending(List l) {
	if (l->head == NULL) {
		return;
	}
	
	Node curr = l->head->next;
	Node prev = l->head;
	
	while (curr != NULL) {
		if (curr->value < prev->value) {
			prev->next = curr->next;
			free(curr);
			curr = prev->next;
		} else {
			prev = curr;
			curr = curr->next;
		}
	}
}

#endif
