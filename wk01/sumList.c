
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int value;
	struct _Node *next;
} Node;

typedef Node *List; // pointer to first Node

List arrayToList(int array[], int size);
List insertEnd(List l, int value);
List newNode(int value);

int sumList1(List head);
int sumList2(List head);
int sumList3(List head);

int main(void) {
	// The more complex the problem
	// is, the more tests you need.
	
	// A 'common' case
	int A1[] = {6, 1, 5};
	List l1 = arrayToList(A1, 3);
	assert(sumList1(l1) == 12);
	assert(sumList2(l1) == 12);
	assert(sumList3(l1) == 12);
	
	// An 'edge' case
	int A2[] = {};
	List l2 = arrayToList(A2, 0);
	assert(sumList1(l2) == 0);
	assert(sumList2(l2) == 0);
	assert(sumList3(l2) == 0);
	
	int A3[] = {7};
	List l3 = arrayToList(A3, 1);
	assert(sumList1(l3) == 7);
	assert(sumList2(l3) == 7);
	assert(sumList3(l3) == 7);
	
	printf("All tests passed.\n");
	
	return 0;
}

// sum a list using a while loop

int sumList1(List head) {
	List curr = head; // initialisation
	int sum = 0;
	while (curr != NULL) { // condition
		sum += curr->value;
		curr = curr->next; // increment
	}
	return sum;
}

// sum a list using a for loop
int sumList2(List head) {
	List curr;
	int sum = 0;
	// A for loop is simply a more compact while loop
	// The for statement combines the initialisation,
	// condition, and increment statements from a
	// while loop
	for (curr = head; curr != NULL; curr = curr->next) {
		sum += curr->value;
	}
	return sum;
}

// sum a list using recursion
//
// A recursive function calls itself.
// This is useful if you have a structure that is recursively
// defined,  or contains smaller instances of itself, such as
// a linked list.
// For example, the linked list 2 -> 4 -> 5 -> X contains smaller
// linked lists within it.  For example, 4 -> 5 -> X, 5 -> X, and
// X (the empty list).
// Almost all lists contain a smaller list within them. The only
// exception is the empty list.  So we can divide all lists into
// two categories:
// 1. an empty list
// 2. a node with a value, followed by a list
// Handling the empty list case is simple - we return 0, because
// there is nothing more to add.  In the second case, we rely on
// the fact that our function should work on all lists, whatever
// their sizes are.  So we add the value in the head node to the
// sum of the remaining part of the list (head->next),  which is
// in and of itself a list.
int sumList3(List head) {
	if (head == NULL) {
		return 0;
	}
	return head->value + sumList3(head->next);
}

// Creates a list with the elements
// in the given array.
List arrayToList(int array[], int size) {
	List l = NULL;
	for (int i = 0; i < size; i++) {
		l = insertEnd(l, array[i]);
	}
	return l;
}

// Inserts a value at the end of the
// list l and returns the pointer to
// the first node in the list
List insertEnd(List l, int value) {
	List n = newNode(value);
	
	// If the list is empty,  the new
	// node becomes the first node
	if (l == NULL) {
		return n;
	
	// Otherwise, insert the new node
	// after the last node
	} else {
		List curr = l;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = n;
		return l;
	}
}

List newNode(int value) {
	List n = malloc(sizeof(*n));
	if (n == NULL) {
		fprintf(stderr, "Insufficient memory!\n");
		exit(1);
	}
	n->value = value;
	n->next = NULL;
	return n;
}

