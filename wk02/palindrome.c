
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <string>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	char *s = argv[1];
	int n = strlen(s);
	bool result = true;

	for (int i = 0; i < n / 2; i++) {
		if (s[i] != s[n - i - 1]) {
			result = false;
			break;
		}
	}

	printf("%s\n", result ? "yes" : "no");
}
