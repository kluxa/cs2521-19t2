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

bool hasCycle(Graph g) {
	// TODO
	return false;
}
