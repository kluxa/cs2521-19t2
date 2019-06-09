
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static List newList(void);
static Node newNode(int value);

/**
 * Merges  the  values from two sorted lists into a new sorted list. The
 * original  lists  should remain unchanged. The lists can be assumed to
 * be sorted (in ascending order).
 *
 * Examples:
 *        input l1        |       input l2        |               returned list
 * -----------------------+-----------------------+-------------------------------------------
 *  1 -> 4 -> 7 -> 9 -> X | 2 -> 3 -> 4 -> 5 -> X | 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 7 -> 9 -> X
 *  1 -> 2 -> 3 -> X      | 7 -> 8 -> 9 -> X      | 1 -> 2 -> 3 -> 7 -> 8 -> 9 -> X
 *  4 -> 5 -> X           | 3 -> 6 -> X           | 3 -> 4 -> 5 -> 6 -> X
 *  2 -> 8 -> 9 -> X      | X                     | 2 -> 8 -> 9 -> X
 *  X                     | X                     | X
 */
List listMergeSorted(List l1, List l2) {
	(void) l1;
	(void) l2;
	return NULL;
}


////////////////////////////////////////////////////////////////////////
// Some functions to help you out

static List newList(void) {
	List l = malloc(sizeof(*l));
	if (l == NULL) {
		fprintf(stderr, "Insufficient memory!\n");
		exit(EXIT_FAILURE);
	}
	l->head = NULL;
	return l;
}

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

