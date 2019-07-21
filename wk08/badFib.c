
#include <assert.h>
#include <stdio.h>

long long fib(int n);

int main(void) {
	for (int i = 0; i < 60; i++) {
		printf("fib(%d) = %lld\n", i, fib(i));
	}
}

long long fib(int n) {
	assert(n >= 0);
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (fib(n - 1) + fib(n - 2));
}
