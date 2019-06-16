
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static Node doListDeleteMultiples(List l, Node n);
static bool isMultipleOfAnother(List l, Node n);

/**
 * Delete all values in the list that are an integer multiple of another
 * value in the list.
 *
 * Examples:
 *             input list           |       resulting list
 * ---------------------------------+-----------------------------
 *  1 -> 2 -> 3 -> 4 -> 5 -> 6 -> X | 1 -> X
 *  2 -> 4 -> 8 -> 6 -> 3 -> X      | 2 -> 3 -> X
 *  5 -> 5 -> 3 -> 3 -> 7 -> 7 -> X | X
 *  1 -> 1 -> 8 -> 123 -> -42 -> X  | X
 *  0 -> X                          | 0 -> X
 *  1 -> X                          | 1 -> X
 *  1 -> 0 -> X                     | 1 -> X
 *  2 -> 3 -> 5 -> 7 -> 11 -> X     | 2 -> 3 -> 5 -> 7 -> 11 -> X
 *  X                               | X
 */
void listDeleteMultiples(List l) {
	l->head = doListDeleteMultiples(l, l->head);
}

// Uses recursion
static Node doListDeleteMultiples(List l, Node curr) {
	if (curr == NULL) {
		return NULL;
	}
	
	// Firstly,  we  check if the current value is a multiple of another
	// value in the list. Regardless of whether it is or not, we recurse
	// down  the  list, so that ALL nodes do this check before ANY nodes
	// are deleted. Finally, we delete the current node if its value was
	// a multiple of another.
	// Question: What can happen if we start deleting nodes before every
	//           node  has checked if its value is a multiple of another
	//           value in the list?
	bool isMultiple = isMultipleOfAnother(l, curr);
	curr->next = doListDeleteMultiples(l, curr->next);
	if (isMultiple) {
		Node temp = curr->next;
		free(curr);
		return temp;
	} else {
		return curr;
	}
}

// Question: Why  must  we  pass the node to this function rather than a
//           value?
static bool isMultipleOfAnother(List l, Node n) {
	Node curr = l->head;
	while (curr != NULL) {
		if (curr != n) {
			if (n->value == 0) {
				return true;
			} else if (curr->value != 0 && n->value % curr->value == 0) {
				return true;
			}
		}
		curr = curr->next;
	}
	return false;
}

// Answers to questions:
// 1) Suppose  we  had this list: [5] -> [5] -> X. Since 5 is a multiple
//    of  itself,  both  values  should be deleted, and we should end up
//    with  the  empty list. If we delete the first 5 before we check if
//    the  second 5 is a multiple of another value in the list, we would
//    end  up  with  the  list [5] -> X. If we now did the check on this
//    remaining 5, we wouldn't find any multiples, so the 5 would not be
//    deleted.
//
// 2) Because we only want to delete a node if it contains a value which
//    is  a  multiple  of ANOTHER value in the list. If we only pass the
//    value  to the list, we don't know which node it belongs to, and we
//    might end up deleting it because it is a multiple of itself.

