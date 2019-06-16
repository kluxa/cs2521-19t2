
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static List newList(void);
static void listInsertTail(List l, int value);
static Node newNode(int value);

/**
 * Creates  a  new  list that is formed from zipping values from the two
 * given lists. The original lists should remain unchanged. Zip means to
 * take  values  from alternating lists. If one list is exhausted before
 * the  other,  repeatedly take values from the non-exhausted list until
 * both lists are exhausted.
 *
 * Examples:
 *        input l1        |       input l2        |          returned list       
 * -----------------------+-----------------------+---------------------------------
 *  1 -> 4 -> 7 -> X      | 8 -> 5 -> 6 -> X      | 1 -> 8 -> 4 -> 5 -> 7 -> 6 -> X
 *  6 -> 2 -> X           | 1 -> 9 -> 5 -> 3 -> X | 6 -> 1 -> 2 -> 9 -> 5 -> 3 -> X
 *  8 -> 1 -> 5 -> 5 -> X | 7 -> 3 -> X           | 8 -> 7 -> 1 -> 3 -> 5 -> 5 -> X
 *  X                     | 3 -> 7 -> 2 -> X      | 3 -> 7 -> 2 -> X
 *  5 -> 3 -> 5 -> 3 -> X | 4 -> X                | 5 -> 4 -> 3 -> 5 -> 3 -> X
 *  X                     | X                     | X
 */
List listZip(List l1, List l2) {
	List l = newList();
	Node curr1 = l1->head;
	Node curr2 = l2->head;
	while (curr1 != NULL || curr2 != NULL) {
		if (curr1 != NULL) {
			listInsertTail(l, curr1->value);
			curr1 = curr1->next;
		}
		if (curr2 != NULL) {
			listInsertTail(l, curr2->value);
			curr2 = curr2->next;
		}
	}
	return l;
}

static List newList(void) {
	List l = malloc(sizeof(*l));
	if (l == NULL) {
		fprintf(stderr, "Insufficient memory!\n");
		exit(EXIT_FAILURE);
	}
	l->head = NULL;
	return l;
}

static void listInsertTail(List l, int value) {
	Node n = newNode(value);
	if (l->head == NULL) {
		l->head = n;
	} else {
		Node curr = l->head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = n;
	}
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

