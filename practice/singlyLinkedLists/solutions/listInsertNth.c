
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define RECURSIVE 0

#if RECURSIVE
static Node doListInsertNth(Node curr, int value, int n);
#endif

static Node newNode(int value);

/**
 * Inserts a value into the n'th position in the list.
 * If n is 0, the new value is inserted at the beginning of the list.
 * If n is equal to the length of the list, the new value is inserted at
 * the end of the list.
 * Otherwise,  the  new value should be inserted somewhere in the middle
 * of the list, depending on the value of n.
 * You can assume n is between 0 and N (inclusive).
 *
 * Examples:
 *        input list      |  value  |  n  |       resulting list
 * -----------------------+---------+-----+----------------------------
 *  4 -> 6 -> 1 -> 8 -> X |    5    |  0  | 5 -> 4 -> 6 -> 1 -> 8 -> X
 *  4 -> 6 -> 1 -> 8 -> X |    5    |  2  | 4 -> 6 -> 5 -> 1 -> 8 -> X
 *  4 -> 6 -> 1 -> 8 -> X |    5    |  4  | 4 -> 6 -> 1 -> 8 -> 5 -> X
 *  1 -> X                |    8    |  0  | 8 -> 1 -> X
 *  1 -> X                |    4    |  1  | 1 -> 4 -> X
 *  X                     |    3    |  0  | 3 -> X
 */
void listInsertNth(List l, int value, int n) {
	#if RECURSIVE
	l->head = doListInsertNth(l->head, value, n);
	
	#else // ITERATIVE
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
	#endif
}

#if RECURSIVE
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
#endif

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

