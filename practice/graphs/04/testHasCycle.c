
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

static void test(Graph g, bool expected);
static void showSummary(void);

int main(void) {
	{///////////////////////////////////////////////////////////////////
		
		Edge edges[] = {
			{0, 1}, {1, 2}, {2, 0}
		};
		Graph g = GraphNewFromEdgeArray(3, 3, edges);
		test(g, true);
		GraphFree(g);
		
	}
	{///////////////////////////////////////////////////////////////////
	
		Edge edges[] = {
			{0, 1}, {0, 2}, {0, 3}
		};
		Graph g = GraphNewFromEdgeArray(4, 3, edges);
		test(g, false);
		GraphFree(g);
	
	}
	{///////////////////////////////////////////////////////////////////
	
		Edge edges[] = {
			{0, 1}, {1, 2}, {3, 4}, {3, 5}, {4, 5}
		};
		Graph g = GraphNewFromEdgeArray(6, 5, edges);
		test(g, true);
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
		test(g, true);
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

static void test(Graph g, bool expected) {
	printf("\nTest %2d\n", ++nTests);
	
	GraphDump(g, stdout);
	
	bool observed = hasCycle(g);
	printf("Expected: getDistance(g%02d) => %s\n",
	       nTests, expected ? "TRUE" : "FALSE");
	printf("Observed: getDistance(g%02d) => %s\n",
	       nTests, observed ? "TRUE" : "FALSE");
	
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

