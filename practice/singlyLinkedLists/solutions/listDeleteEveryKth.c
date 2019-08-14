
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

Node deleteEveryKthHelper(Node curr, int k, int i);

void listDeleteEveryKth(List l, int k) {
	l->head = deleteEveryKthHelper(l->head, k, 1);
}

// Uses  recursion to delete all nodes in the list whose position (i) is
// divisible  by  k. This function follows a very similar pattern to the
// listDelete  helper  function  in  listDeleteDuplicates - what are the
// differences?
Node deleteEveryKthHelper(Node curr, int k, int i) {
	if (curr == NULL) {
		return NULL;
	}
	
	curr->next = deleteEveryKthHelper(curr->next, k, i + 1);
	
	if (i % k == 0) {
		Node temp = curr->next;
		free(curr);
		return temp;
	} else {
		return curr;
	}
}

// P.S.  Writing an iterative solution for this problem is possible, but
//       it won't be as elegant as the recursive solution.  That's why I
//       highly recommend using recursion to solve these :)
