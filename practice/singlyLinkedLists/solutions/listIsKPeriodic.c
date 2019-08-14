
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

bool listIsKPeriodic(List l, int k) {
	Node curr = l->head;
	Node ahead = curr;
	
	// Move the ahead pointer k nodes ahead
	// of l->head
	int i = 0;
	while (ahead != NULL && i < k) {
		ahead = ahead->next;
		i++;
	}
	
	// Now move curr and ahead forward
	// simultaneously, comparing the values
	while (ahead != NULL) {
		if (curr->value != ahead->value) {
			return false;
		}
		curr = curr->next;
		ahead = ahead->next;
	}
	
	return true;
}
