
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stringList.h"

int main(void) {
	List l = listNew();

	char buf[256];
	printf("Enter word to insert (Ctrl+D to stop): ");
	while (fgets(buf, 256, stdin) != NULL) {
		// Remove newline
		buf[strlen(buf) - 1] = '\0';
		listInsertEnd(l, buf);

		printf("Enter word to insert (Ctrl+D to stop): ");
	}

	listPrint(l);
}
