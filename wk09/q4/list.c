
#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static List newNode(int value);

List selectSort(List ls) {
	return NULL;
}

//////////////////////////////////////////////////
// Basic list functions

void printList(List l) {
	for (List curr = l; curr != NULL; curr = curr->next) {
		printf("[%d] -> ", curr->value);
	}
	printf("X\n");
}

/*
 * Creates a list from an arbitrary list of numbers
 * You don't have to know how to do this,  but it's
 * interesting!
 */
List newList(int size, ...) {
	List head = NULL;
	List curr = NULL;

	va_list args;
	va_start(args, size);

	for (int i = 0; i < size; i++) {
		int num = va_arg(args, int);

		List node = newNode(num);
		if (head == NULL) {
			head = node;
		} else {
			curr->next = node;
		}
		curr = node;
	}

	va_end(args);
	return head;
}

static List newNode(int value) {
	List n = malloc(sizeof(*n));
	if (n == NULL) {
		fprintf(stderr, "Insufficient memory!\n");
		exit(EXIT_FAILURE);
	}
	n->value = value;
	n->next = NULL;
	return n;
}
