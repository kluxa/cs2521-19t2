
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

int getDistance(Graph g, Vertex src, Vertex dest);

static void test(Graph g, Vertex src, Vertex dest, int expected);
static void showSummary(void);

int main(void) {
	{///////////////////////////////////////////////////////////////////
		
		Edge edges[] = {
			{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}
		};
		Graph g = GraphNewFromEdgeArray(6, 5, edges);
		test(g, 0, 0, 0);
		test(g, 0, 3, 3);
		test(g, 4, 0, 4);
		test(g, 1, 5, 4);
		GraphFree(g);
		
	}
	{///////////////////////////////////////////////////////////////////
	
		Edge edges[] = {
			{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 0}
		};
		Graph g = GraphNewFromEdgeArray(7, 7, edges);
		test(g, 4, 2, 2);
		test(g, 4, 0, 3);
		test(g, 1, 5, 3);
		test(g, 6, 0, 1);
		GraphFree(g);
	
	}
	{///////////////////////////////////////////////////////////////////
		/*
			0-----1-----3-----4
			|     |     |
			|     |     |
			2     6     5-----7-----8
            |           |
            |           |
		    9-----------
		*/
	
		Edge edges[] = {
			{0, 1}, {0, 2}, {1, 3}, {1, 6}, {2, 9},
			{3, 4}, {3, 5}, {5, 7}, {5, 9}, {7, 8}
		};
		Graph g = GraphNewFromEdgeArray(10, 10, edges);
		test(g, 0, 7, 4);
		test(g, 8, 2, 4);
		test(g, 2, 6, 3);
		test(g, 4, 9, 3);
		test(g, 1, 9, 3);
		test(g, 8, 0, 5);
		test(g, 3, 9, 2);
		test(g, 5, 6, 3);
		GraphFree(g);
	}
	{///////////////////////////////////////////////////////////////////
	
		// TODO: Add your own tests
	}
	
	showSummary();
}

static int nTests = 0;
static int nPassed = 0;
static int nFailed = 0;

static void test(Graph g, Vertex v, Vertex w, int expected) {
	printf("\nTest %2d\n", ++nTests);
	
	GraphDump(g, stdout);
	
	int observed = getDistance(g, v, w);
	printf("Expected: getDistance(g%02d, %d, %d) => %d\n",
	       nTests, v, w, expected);
	printf("Observed: getDistance(g%02d, %d, %d) => %d\n",
	       nTests, v, w, observed);
	
	if (observed == expected) {
		printf("\033[32mTest passed\033[0m\n");
		nPassed++;
	} else {
		printf("\033[31mTest failed\033[0m\n");
		nFailed++;
	}
}

static void showSummary(void) {
	printf("\n\033[32;1m%d tests passed \033[31;1m%d tests failed\033[00m\n",
	       nPassed, nFailed);
	if (nPassed > 0 && nFailed == 0) {
		printf("All tests passed! Have you added your own tests?\n");
	}
}

