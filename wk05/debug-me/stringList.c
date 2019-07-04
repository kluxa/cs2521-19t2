
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stringList.h"

static Node newNode(char *str);

List listNew(void) {
	List l = malloc(sizeof(*l));
	if (l == NULL) {
		fprintf(stderr, "Insufficient memory!\n");
		exit(EXIT_FAILURE);
	}

	l->head = NULL;
	return l;
}

void listInsertEnd(List list, char *str) {
	Node n = newNode(str);
	if (list->head == NULL) {
		list->head = n;
	} else {
		Node curr = list->head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = n;
	}
}

static Node newNode(char *str) {
	Node n = malloc(sizeof(*n));
	if (n == NULL) {
		fprintf(stderr, "Insufficient memory!\n");
		exit(EXIT_FAILURE);
	}

	n->value = str;
	n->next = NULL;
	return n;
}

void listPrint(List list) {
	printf("\nList: ");
	Node curr = list->head;
	while (curr != NULL) {
		printf("\"%s\" -> ", curr->value);
		curr = curr->next;
	}
	printf("X\n");
}
