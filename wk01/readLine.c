// Reads lines from stdin and prints them out

// Try
// $ ./readLine
// and
// $ ./readLine < helloWorld.txt

#include <stdio.h>

#define BUFSIZE 1024

int main(void) {
	char buf[BUFSIZE];
	
	// stdin is provided by stdio.h
	while (fgets(buf, BUFSIZE, stdin) != NULL) {
		printf("Read line: %s", buf);
	}
}

