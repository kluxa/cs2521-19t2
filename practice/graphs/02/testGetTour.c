// Tests your getTour implementation

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

Vertex *getTour(Graph g, int *tourLength);

static void test(Graph g);
static void showSummary(void);

int main(void) {
	// Test 1
	bool edges1[2][2] = {
		{0, 1},
		{1, 0}
	};
	Graph g1 = GraphNewFromMatrix(2, edges1);
	test(g1);
	GraphFree(g1);
	
	// Test 2
	bool edges2[3][3] = {
		{0, 1, 0},
		{1, 0, 1},
		{0, 1, 0}
	};
	Graph g2 = GraphNewFromMatrix(3, edges2);
	test(g2);
	GraphFree(g2);
	
	// Test 3
	bool edges3[3][3] = {
		{0, 1, 1},
		{1, 0, 1},
		{1, 1, 0}
	};
	Graph g3 = GraphNewFromMatrix(3, edges3);
	test(g3);
	GraphFree(g3);
	
	// Test 4
	bool edges4[4][4] = {
		{0, 1, 0, 1},
		{1, 0, 1, 0},
		{0, 1, 0, 1},
		{1, 0, 1, 0}
	};
	Graph g4 = GraphNewFromMatrix(4, edges4);
	test(g4);
	GraphFree(g4);
	
	// Test 5
	bool edges5[5][5] = {
	//	 0  1  2  3  4
		{0, 1, 0, 0, 0}, // 0
		{1, 0, 1, 1, 0}, // 1
		{0, 1, 0, 0, 0}, // 2
		{0, 1, 0, 0, 1}, // 3
		{0, 0, 0, 1, 0}  // 4
	};
	Graph g5 = GraphNewFromMatrix(5, edges5);
	test(g5);
	GraphFree(g5);
	
	// TODO - Add your own tests here
	
	
	showSummary();
}

////////////////////////////////////////////////////////////////////////

static void fail(const char *format, ...);
static void pass(void);

static void showPath(int tourLength, Vertex *tour);
static int checkValidVertices(int tourLength, Vertex *tour, Graph g);
static int checkAdjacencies(int tourLength, Vertex *tour, Graph g);
static int checkAllVisited(int tourLength, Vertex *tour, Graph g);

static int nTests = 0;
static int nPassed = 0;
static int nFailed = 0;

static void test(Graph g) {
	printf("\nTest %2d\n", ++nTests);
	
	GraphDump(g, stdout);
	
	int tourLength = 0;
	Vertex *tour = getTour(g, &tourLength);
	
	printf("Your getTour returned this path: ");
	showPath(tourLength, tour);
	printf("\n");
	
	if (checkValidVertices(tourLength, tour, g) &&
			checkAdjacencies(tourLength, tour, g) &&
			checkAllVisited(tourLength, tour, g)) {
		pass();
	}
	
	free(tour);
}

static void fail(const char *format, ...) {
	nFailed++;
	printf("\033[33m");
	
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
	
	printf("\033[31mTest failed\033[00m\n");
}

static void pass(void) {
	nPassed++;
	printf("\033[32mTest passed\033[00m\n");
}

static void showSummary(void) {
	printf("\n\033[32;1m%d tests passed \033[31;1m%d tests failed\033[00m\n",
	       nPassed, nFailed);
	if (nPassed > 0 && nFailed == 0) {
		printf("All tests passed! Have you added your own tests?\n");
	}
}

////////////////////////////////////////////////////////////////////////

static void showPath(int tourLength, Vertex *tour) {
	if (tourLength == 0) return;
	printf("%d", tour[0]);
	for (int i = 1; i < tourLength; i++) {
		printf(" -> %d", tour[i]);
	}
}

static int checkValidVertices(int tourLength, Vertex *tour, Graph g) {
	int nV = GraphNumVertices(g);
	for (int i = 0; i < tourLength; i++) {
		if (tour[i] < 0 || tour[i] >= nV) {
			fail("Your tour visited %d, which is not a valid vertex\n",
			     tour[i]);
			return 0;
		}
	}
	return 1;
}

static int checkAdjacencies(int tourLength, Vertex *tour, Graph g) {
	for (int i = 1; i < tourLength; i++) {
		if (!GraphIsAdjacent(g, tour[i - 1], tour[i])) {
			fail("%d and %d are not adjacent\n", tour[i - 1], tour[i]);
			return 0;
		}
	}
	return 1;
}

static int checkAllVisited(int tourLength, Vertex *tour, Graph g) {
	int nV = GraphNumVertices(g);
	bool visited[nV];
	for (Vertex v = 0; v < nV; v++) {
		visited[v] = false;
	}
	for (int i = 0; i < tourLength; i++) {
		visited[tour[i]] = true;
	}
	for (Vertex v = 0; v < nV; v++) {
		if (visited[v] == false) {
			fail("Your tour did not visit vertex %d\n", v);
			return 0;
		}
	}
	return 1;
}

