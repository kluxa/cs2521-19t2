
#include <stdio.h>

void swap(int *A, int i, int j);
void swap2(int *A, int i, int j);

int main(void) {

	int a[] = {5, 8, 1, 4, 7};
	int i = 1;
	int j = 3;

	printf("Before swap: %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4]);
	swap(a, i, j);
	printf(" After swap: %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4]);
	swap(a, i, j);
	printf("After swap2: %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4]);
}

// Swaps the i'th and j'th elements of the array A
void swap(int *A, int i, int j) {
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

// Challenge: swap the i'th and j'th elements
//            without a temp variable
void swap2(int *A, int i, int j) {
	A[i] = A[i] + A[j];
	A[j] = A[i] - A[j];
	A[i] = A[i] - A[j];
}

