// Implementation of the Undirected Graph ADT

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

struct graph {
	int nV;
	bool **edges;
};

static bool validVertex(Graph g, Vertex v);

Graph GraphNew(int nV) {
	assert(nV > 0);
	
	Graph g = malloc(sizeof(*g));
	if (g == NULL) {
		fprintf(stderr, "GraphNew: Couldn't allocate Graph!\n");
		exit(EXIT_FAILURE);
	}
	
	g->nV = nV;
	
	g->edges = malloc((size_t)nV * sizeof(bool *));
	if (g->edges == NULL) {
		fprintf(stderr, "GraphNew: Couldn't allocate Graph!\n");
		exit(EXIT_FAILURE);
	}
	for (Vertex v = 0; v < nV; v++) {
		g->edges[v] = malloc((size_t)nV * sizeof(bool));
		if (g->edges[v] == NULL) {
			fprintf(stderr, "GraphNew: Couldn't allocate Graph!\n");
			exit(EXIT_FAILURE);
		}
		
		for (Vertex w = 0; w < nV; w++) {
			g->edges[v][w] = false;
		}
	}
	
	return g;
}

void GraphFree(Graph g) {
	assert(g != NULL);
	
	for (Vertex v = 0; v < g->nV; v++) {
		free(g->edges[v]);
	}
	free(g);
}

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

int GraphNumNeighbours(Graph g, Vertex v) {
	assert(g != NULL);
	assert(validVertex(g, v));
	
	int count = 0;
	for (Vertex w = 0; w < g->nV; w++) {
		if (g->edges[v][w] == true) {
			count++;
		}
	}
	return count;
}

////////////////////////////////////////////////////////////////////////
// Helper Functions

static bool validVertex(Graph g, Vertex v) {
	return (v >= 0 && v < g->nV);
}
