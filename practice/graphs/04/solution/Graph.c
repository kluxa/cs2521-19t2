// Implementation of the Undirected Graph ADT

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"
#include "Stack.h"

struct graph {
	int nV;
	bool **edges;
};

static bool validVertex(Graph g, Vertex v);

////////////////////////////////////////////////////////////////////////
// Constructors
static Graph doGraphNew(int nV);

Graph GraphNew(int nV) {
	assert(nV > 0);
	
	Graph g = doGraphNew(nV);
	for (int i = 0; i < nV; i++) {
		for (int j = 0; j < nV; j++) {
			g->edges[i][j] = false;
		}
	}
	
	return g;
}

Graph GraphNewFromMatrix(int nV, bool edges[nV][nV]) {
	assert(nV > 0);
	
	Graph g = doGraphNew(nV);
	for (int i = 0; i < nV; i++) {
		for (int j = 0; j < nV; j++) {
			if (edges[i][j] == true) {
				assert(i != j);
				assert(edges[j][i] == true);
				g->edges[i][j] = true;
			} else {
				g->edges[i][j] = false;
			}
		}
	}
	
	return g;
}

Graph GraphNewFromEdgeArray(int nV, int nE, Edge *edges) {
	assert(nV > 0);
	assert(nE >= 0);
	
	Graph g = GraphNew(nV);
	for (int i = 0; i < nE; i++) {
		Vertex v = edges[i].v;
		Vertex w = edges[i].w;
		assert(v != w);
		g->edges[v][w] = true;
		g->edges[w][v] = true;
	}
	
	return g;
}

static Graph doGraphNew(int nV) {
	Graph g = malloc(sizeof(*g));
	if (g == NULL) {
		fprintf(stderr, "GraphNew: Insufficient memory!\n");
		exit(EXIT_FAILURE);
	}
	
	g->nV = nV;
	
	g->edges = malloc(nV * sizeof(bool *));
	if (g->edges == NULL) {
		fprintf(stderr, "GraphNew: Insufficient memory!\n");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < nV; i++) {
		g->edges[i] = malloc(nV * sizeof(bool));
		if (g->edges[i] == NULL) {
			fprintf(stderr, "GraphNew: Insufficient memory!\n");
			exit(EXIT_FAILURE);
		}
	}
	
	return g;
}

////////////////////////////////////////////////////////////////////////
// Destructors

void GraphFree(Graph g) {
	assert(g != NULL);
	
	for (int i = 0; i < g->nV; i++) {
		free(g->edges[i]);
	}
	free(g);
}

////////////////////////////////////////////////////////////////////////
// General Graph Functions

int GraphNumVertices(Graph g) {
	assert(g != NULL);
	
	return g->nV;
}

void GraphAddEdge(Graph g, Vertex v, Vertex w) {
	assert(g != NULL);
	assert(validVertex(g, v));
	assert(validVertex(g, w));
	assert(v != w);
	
	g->edges[v][w] = true;
	g->edges[w][v] = true;
}

void GraphRemoveEdge(Graph g, Vertex v, Vertex w) {
	assert(g != NULL);
	assert(validVertex(g, v));
	assert(validVertex(g, w));
	assert(v != w);
	
	g->edges[v][w] = false;
	g->edges[w][v] = false;
}

bool GraphIsAdjacent(Graph g, Vertex v, Vertex w) {
	assert(g != NULL);
	assert(validVertex(g, v));
	assert(validVertex(g, w));
	
	return g->edges[v][w];
}

////////////////////////////////////////////////////////////////////////
// Displaying the Graph

void GraphDump(Graph g, FILE *fp) {
	assert(g != NULL);
	assert(fp != NULL);
	
	fprintf(fp, "Graph: nV = %d\n", g->nV);
	fprintf(fp, "Edges:\n");
	for (Vertex v = 0; v < g->nV; v++) {
		fprintf(fp, "%2d:", v);
		for (Vertex w = 0; w < g->nV; w++) {
			if (g->edges[v][w] == true) {
				fprintf(fp, " %d-%d", v, w);
			}
		}
		fprintf(fp, "\n");
	}
	fprintf(fp, "\n");
}

////////////////////////////////////////////////////////////////////////
// Helper Functions

static bool validVertex(Graph g, Vertex v) {
	return (v >= 0 && v < g->nV);
}

////////////////////////////////////////////////////////////////////////
// Your task
static bool hasCycleHelper(Graph g, Vertex v, Vertex prev, bool *visited);

bool hasCycle(Graph g) {
	bool visited[g->nV];
	for (Vertex v = 0; v < g->nV; v++) {
		visited[v] = false;
	}
	
	// There  may  be multiple connected components, so we need to check
	// each  of  them.  That's why we use a loop to loop through all the
	// vertices.
	for (Vertex v = 0; v < g->nV; v++) {
		// If v belongs to a connected component that we haven't checked
		// yet
		if (visited[v] == false) {
			if (hasCycleHelper(g, v, v, visited)) {
				return true;
			}
		}
	}
	return false;
}

// This is DFS with a few modifications.
// prev is the vertex BEFORE v, i.e., the predecessor of v
static bool hasCycleHelper(Graph g, Vertex v, Vertex prev, bool *visited) {
	visited[v] = true; // visit v
	for (Vertex w = 0; w < g->nV; w++) {
		if (g->edges[v][w]) {
			// If there is an edge from v to w and we've already visited
			// w,  then we might have found a cycle, BUT we want to make
			// sure  that  we're not going back along the same edge that
			// we just used to get to v.
			if (visited[w] && w != prev) {
				return true;
			} else if (!visited[w]) {
				if (hasCycleHelper(g, w, v, visited)) {
					return true;
				}
			}
		}
	}
	return false;
}

