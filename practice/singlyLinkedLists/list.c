// Printing and reading a linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

static List newList(void);
static Node newNode(int value);

void listPrint(List l) {
	Node curr = l->head;
	while (curr != NULL) {
		printf("[%d] -> ", curr->value);
		curr = curr->next;
	}
	printf("X\n");
}

List strToList(char *s) {
	char *copy = strdup(s);
	Node head = NULL;
	Node curr = NULL;
	char *token = strtok(copy, " \n\t");
	while (token != NULL) {
		Node n = newNode(atoi(token));
		if (head == NULL) {
			head = n;
		} else {
			curr->next = n;
		}
		curr = n;
		token = strtok(NULL, " \n\t");
	}
	free(copy);
	List l = newList();
	l->head = head;
	return l;
}

List readList(void) {
	char buf[1024];
	fgets(buf, 1024, stdin);
	return strToList(buf);
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

