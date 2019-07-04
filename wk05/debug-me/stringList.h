
#ifndef STRING_LIST_H
#define STRING_LIST_H

typedef struct node *Node;
struct node {
	char *value;
	Node next;
};

typedef struct list *List;
struct list {
	Node head;
};

// Creates a new list
List listNew(void);

// Adds a string to the end of a list
void listInsertEnd(List list, char *str);

// Prints a list
void listPrint(List list);

#endif
