
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define RECURSIVE 1

static Node newNode(int value);

#if RECURSIVE //////////////////////////////////////////////////////////

static Node doListInsertNth(Node curr, int value, int n);

void listInsertNth(List l, int value, int n) {
	l->head = doListInsertNth(l->head, value, n);
}

static Node doListInsertNth(Node curr, int value, int n) {
	if (curr == NULL && n != 0) {
		fprintf(stderr, "listInsertNth: n out of range\n");
		exit(EXIT_FAILURE);
	}
	
	// n == 0  means  we insert at the beginning of the list, before the
	// first  node. So create a new node, and place it before the entire
	// list. Then we return the new node, because it is now the new head
	// of the list.
	if (n == 0) {
		Node new = newNode(value);
		new->next = curr;
		return new;
	
	// Otherwise,  insert  in the (n - 1)'th position in the rest of the
	// list,  and  return  the  head of the current list (which does not
	// change)
	} else {
		curr->next = doListInsertNth(curr->next, value, n - 1);
		return curr;
	}
}

#else // ITERATIVE /////////////////////////////////////////////////////

void listInsertNth(List l, int value, int n) {
	Node new = newNode(value);
	if (n == 0) {
		new->next = l->head;
		l->head = new;
	} else {
		Node curr = l->head;
		int i = 0;
		// You could use a prev here, but
		// using just a curr and stopping
		// at the (n - 1)th node leads to
		// shorter code
		while (i != n - 1) {
			curr = curr->next;
			i++;
		}
		new->next = curr->next;
		curr->next = new;
	}
}

#endif /////////////////////////////////////////////////////////////////

// Helper function
static Node newNode(int value) {
	Node n = malloc(sizeof(*n));
	if (n == NULL) {
		fprintf(stderr, "Insufficient memory!\n");
		exit(EXIT_FAILURE);
	}
	
	n->value = value;
	n->next = NULL;
	return n;
}
