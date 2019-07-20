
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

long long fib(int n);
long long fibR(int n, long long *cache);

int main(void) {
	for (int i = 0; i < 60; i++) {
		printf("fib(%d) = %lld\n", i, fib(i));
	}
}

long long fib(int n) {
	assert(n >= 0);
	return 0;
}

long long fibR(int n, long long *cache) {
	return 0;
}
