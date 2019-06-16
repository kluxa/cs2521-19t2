
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static List newList(void);
static void listInsertTail(List l, int value);
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
	List l = newList();
	Node curr1 = l1->head;
	Node curr2 = l2->head;
	while (curr1 != NULL || curr2 != NULL) {
		if (curr1 == NULL) {
			listInsertTail(l, curr2->value);
			curr2 = curr2->next;
		} else if (curr2 == NULL) {
			listInsertTail(l, curr1->value);
			curr1 = curr1->next;
		} else if (curr1->value <= curr2->value) {
			listInsertTail(l, curr1->value);
			curr1 = curr1->next;
		} else {
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

