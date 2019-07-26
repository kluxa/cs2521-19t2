
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

	long long cache[n + 1];
	// Initialise the cache to -1
	for (int i = 0; i <= n; i++) {
		cache[i] = -1;
	}
	return fibR(n, cache);
}

long long fibR(int n, long long *cache) {
	// If the result is already in the cache, return it
	if (cache[n] != -1) {
		return cache[n];
	}
	
	long long res;
	if (n == 0) res = 0; // Base case
	if (n == 1) res = 1; // Base case
	if (n >= 2) res = fibR(n - 1, cache) + fibR(n - 2, cache);
	// Store the result in the cache
	cache[n] = res;
	return res;
}
