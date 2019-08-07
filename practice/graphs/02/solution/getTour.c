
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

static void getTourRecurse(Graph g, Vertex v, bool *visited,
                           Vertex *tour, int *tourLength);

Vertex *getTour(Graph g, int *tourLength) {
	int nV = GraphNumVertices(g);
	
	// This method is guaranteed to produce a path of length
	// 2N - 1, where N is the number of vertices
	Vertex *tour = malloc(2 * nV * sizeof(Vertex));
	bool visited[nV];
	for (Vertex v = 0; v < nV; v++) {
		visited[v] = false;
	}
	
	// We choose to start at 0, but you could start anywhere
	*tourLength = 0;
	getTourRecurse(g, 0, visited, tour, tourLength);
	
	return tour;
}

// Very similar to DFS
static void getTourRecurse(Graph g, Vertex v, bool *visited,
                           Vertex *tour, int *tourLength) {
	// Visiting v for the first time
	tour[(*tourLength)++] = v;
	visited[v] = true;
    
	int nV = GraphNumVertices(g);
	for (Vertex w = 0; w < nV; w++) {
		if (GraphIsAdjacent(g, v, w) && visited[w] == false) {
			getTourRecurse(g, w, visited, tour, tourLength);
			
			// Coming back to v after visiting an adjacent location
			tour[(*tourLength)++] = v;
		}
	}
}

