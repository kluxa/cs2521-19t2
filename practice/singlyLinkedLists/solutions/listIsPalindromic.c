
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static int listGetKthLast(List l, int k);
static int listGetLength(List l);

/**
 * Returns  true  if the given list is palindromic, and false otherwise.
 * An empty list is considered to be palindromic.
 */
bool listIsPalindromic(List l) {
	Node curr = l->head;
	int k = 1;
	while (curr != NULL) {
		if (curr->value != listGetKthLast(l, k)) {
			return false;
		}
		curr = curr->next;
		k++;
	}
	return true;
}

static int listGetKthLast(List l, int k) {
	int length = listGetLength(l);
	Node curr = l->head;
	int i = 0;
	while (i < length - k) {
		curr = curr->next;
		i++;
	}
	return curr->value;
}

static int listGetLength(List l) {
	int length = 0;
	Node curr;
	for (curr = l->head; curr != NULL; curr = curr->next) {
		length++;
	}
	return length;
}

