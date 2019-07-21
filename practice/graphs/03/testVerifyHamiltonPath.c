
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

bool verifyHamiltonPath(Graph g, Vertex *path, int pathLength);

static void test(int nV, Edge *edges, int nE, Vertex *path,
                 int pathLength, bool expected);
static void showSummary(void);


int main(void) {
	{///////////////////////////////////////////////////////////////////
	
		Edge edges[] = {
			{0, 1}, {1, 2}, {2, 3}, {3, 4}
		};
		Vertex path1[] = {0, 1, 2, 3, 4};
		Vertex path2[] = {0, 1, 2, 4, 3};
		Vertex path3[] = {0, 1, 2, 3};
		Vertex path4[] = {0, 1, 2, 3, 4, 3};
		Vertex path5[] = {0, 1, 2, 3, 1000000, 4};
		Vertex path6[] = {4, 3, 2, 1, 0};
	
		test(5, edges, 4, path1, 5, true);
		test(5, edges, 4, path2, 5, false);
		test(5, edges, 4, path3, 4, false);
		test(5, edges, 4, path4, 6, false);
		test(5, edges, 4, path5, 6, false);
		test(5, edges, 4, path6, 5, true);
	
	}///////////////////////////////////////////////////////////////////
	
	{
		// TODO: Add your own tests
	}
	
	showSummary();
}

static int nTests = 0;
static int nPassed = 0;
static int nFailed = 0;

static void showPath(Vertex *path, int pathLength);

static void test(int nV, Edge *edges, int nE, Vertex *path,
                 int pathLength, bool expected) {
	printf("\nTest %2d\n", ++nTests);
	
	Graph g = GraphNewFromEdgeArray(nV, nE, edges);
	GraphDump(g, stdout);
	showPath(path, pathLength);
	
	bool observed = verifyHamiltonPath(g, path, pathLength);
	printf("Expected: verifyHamiltonPath(g%02d, path%02d) => %s\n",
	       nTests, nTests, expected ? "true" : "false");
	printf("Observed: verifyHamiltonPath(g%02d, path%02d) => %s\n",
	       nTests, nTests, observed ? "true" : "false");
	
	if (observed == expected) {
		printf("\033[32mTest passed\033[0m\n");
		nPassed++;
	} else {
		printf("\033[31mTest failed\033[0m\n");
		nFailed++;
	}
	
	GraphFree(g);
}

static void showPath(Vertex *path, int pathLength) {
	printf("Path: ");
	if (pathLength == 0) return;
	printf("%d", path[0]);
	for (int i = 1; i < pathLength; i++) {
		printf(" -> %d", path[i]);
	}
	printf("\n");
}

static void showSummary(void) {
	printf("\n\033[32;1m%d tests passed \033[31;1m%d tests failed\033[00m\n",
	       nPassed, nFailed);
	if (nPassed > 0 && nFailed == 0) {
		printf("All tests passed! Have you added your own tests?\n");
	}
}

