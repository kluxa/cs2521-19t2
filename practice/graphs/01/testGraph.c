
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

static void test1(void);
static void test2(void);
static void test3(void);
static void test4(void);
static void test5(void);

int main(void) {

	test1();
	test2();
	test3();
	test4();
	test5();
	
	printf("All tests passed!\n");
	
}

static void test1(void) {
	Graph g = GraphNew(6);
	
	assert(GraphNumNeighbours(g, 0) == 0);
	assert(GraphNumNeighbours(g, 1) == 0);
	assert(GraphNumNeighbours(g, 2) == 0);
	assert(GraphNumNeighbours(g, 3) == 0);
	assert(GraphNumNeighbours(g, 4) == 0);
	assert(GraphNumNeighbours(g, 5) == 0);
	
	GraphAddEdge(g, 0, 2);
	GraphAddEdge(g, 1, 2);
	GraphAddEdge(g, 2, 3);
	GraphAddEdge(g, 3, 4);
	GraphAddEdge(g, 3, 5);
	
	assert(GraphNumNeighbours(g, 0) == 1);
	assert(GraphNumNeighbours(g, 1) == 1);
	assert(GraphNumNeighbours(g, 2) == 3);
	assert(GraphNumNeighbours(g, 3) == 3);
	assert(GraphNumNeighbours(g, 4) == 1);
	assert(GraphNumNeighbours(g, 5) == 1);
	
	GraphFree(g);
	
	printf("\033[32mTest 1 passed!\033[0m\n");
}

static void test2(void) {
	Graph g = GraphNew(7);
	
	GraphAddEdge(g, 0, 1);
	GraphAddEdge(g, 1, 2);
	GraphAddEdge(g, 2, 0);
	GraphAddEdge(g, 0, 3);
	GraphAddEdge(g, 1, 3);
	GraphAddEdge(g, 2, 3);
	GraphAddEdge(g, 3, 4);
	GraphAddEdge(g, 4, 5);
	
	assert(GraphNumNeighbours(g, 0) == 3);
	assert(GraphNumNeighbours(g, 1) == 3);
	assert(GraphNumNeighbours(g, 2) == 3);
	assert(GraphNumNeighbours(g, 3) == 4);
	assert(GraphNumNeighbours(g, 4) == 2);
	assert(GraphNumNeighbours(g, 5) == 1);
	assert(GraphNumNeighbours(g, 6) == 0);
	
	GraphRemoveEdge(g, 3, 0);
	GraphRemoveEdge(g, 3, 1);
	GraphRemoveEdge(g, 3, 2);
	
	assert(GraphNumNeighbours(g, 0) == 2);
	assert(GraphNumNeighbours(g, 1) == 2);
	assert(GraphNumNeighbours(g, 2) == 2);
	assert(GraphNumNeighbours(g, 3) == 1);
	assert(GraphNumNeighbours(g, 4) == 2);
	assert(GraphNumNeighbours(g, 5) == 1);
	assert(GraphNumNeighbours(g, 6) == 0);
	
	GraphFree(g);
	
	printf("\033[32mTest 2 passed!\033[0m\n");
}

static void test3(void) {
	Graph g = GraphNew(5);
	
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			GraphAddEdge(g, i, j);
		}
	}
	
	assert(GraphNumNeighbours(g, 0) == 4);
	assert(GraphNumNeighbours(g, 1) == 4);
	assert(GraphNumNeighbours(g, 2) == 4);
	assert(GraphNumNeighbours(g, 3) == 4);
	assert(GraphNumNeighbours(g, 4) == 4);

	GraphRemoveEdge(g, 0, 2);
	GraphRemoveEdge(g, 0, 3);
	GraphRemoveEdge(g, 1, 3);
	GraphRemoveEdge(g, 1, 4);
	GraphRemoveEdge(g, 2, 4);
	
	assert(GraphNumNeighbours(g, 0) == 2);
	assert(GraphNumNeighbours(g, 1) == 2);
	assert(GraphNumNeighbours(g, 2) == 2);
	assert(GraphNumNeighbours(g, 3) == 2);
	assert(GraphNumNeighbours(g, 4) == 2);
	
	GraphFree(g);
	
	printf("\033[32mTest 3 passed!\033[0m\n");
}

static void test4(void) {
	Graph g = GraphNew(5);
	
	GraphAddEdge(g, 0, 1);
	GraphAddEdge(g, 0, 2);
	GraphAddEdge(g, 0, 3);
	GraphAddEdge(g, 0, 4);
	GraphAddEdge(g, 4, 0);
	
	assert(GraphNumNeighbours(g, 0) == 4);
	assert(GraphNumNeighbours(g, 1) == 1);
	assert(GraphNumNeighbours(g, 2) == 1);
	assert(GraphNumNeighbours(g, 3) == 1);
	assert(GraphNumNeighbours(g, 4) == 1);
	
	GraphFree(g);
	
	printf("\033[32mTest 4 passed!\033[0m\n");
}

static void test5(void) {
	Graph g = GraphNew(5);
	
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			GraphAddEdge(g, i, j);
		}
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != j) {
				GraphRemoveEdge(g, i, j);
			}
		}
	}
	
	assert(GraphNumNeighbours(g, 0) == 2);
	assert(GraphNumNeighbours(g, 1) == 2);
	assert(GraphNumNeighbours(g, 2) == 2);
	assert(GraphNumNeighbours(g, 3) == 4);
	assert(GraphNumNeighbours(g, 4) == 4);
	
	GraphFree(g);
	
	printf("\033[32mTest 5 passed!\033[0m\n");
}

