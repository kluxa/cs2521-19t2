// Implementation of the Undirected Graph ADT

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

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
			g->edges[i][j] = edges[i][j];
		}
	}
	
	return g;
}

static Graph doGraphNew(int nV) {
	Graph g = malloc(sizeof(*g));
	if (g == NULL) {
		fprintf(stderr, "GraphNew: Couldn't allocate Graph!\n");
		exit(EXIT_FAILURE);
	}
	
	g->nV = nV;
	
	g->edges = malloc(nV * sizeof(bool *));
	if (g->edges == NULL) {
		fprintf(stderr, "GraphNew: Couldn't allocate Graph!\n");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < nV; i++) {
		g->edges[i] = malloc(nV * sizeof(bool));
		if (g->edges[i] == NULL) {
			fprintf(stderr, "GraphNew: Couldn't allocate Graph!\n");
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

bool GraphIsAdjacent(Graph g, Vertex v, Vertex w) {
	assert(g != NULL);
	assert(validVertex(g, v));
	assert(validVertex(g, w));
	
	return g->edges[v][w];
}

////////////////////////////////////////////////////////////////////////
// Displaying the Graph

void GraphDump(Graph g, FILE *fp) {
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
// Search Algorithms

////////
// BFS
Vertex *GraphBfs(Graph g, Vertex src) {
	Vertex *pred = malloc(g->nV * sizeof(Vertex));
	assert(pred != NULL);
	for (Vertex i = 0; i < g->nV; i++) {
		pred[i] = -1; //  not visited
	}
	pred[src] = src;
	
	Queue q = QueueNew();
	QueueEnqueue(q, src);
	while (!QueueIsEmpty(q)) {
		Vertex v = QueueDequeue(q);
		for (Vertex w = 0; w < g->nV; w++) {
			if (g->edges[v][w] == true && pred[w] == -1) {
				pred[w] = v;
				QueueEnqueue(q, w);
			}
		}
	}
	
	QueueDrop(q);
	return pred;
}

////////
// DFS
static void dfsRecurse(Graph g, Vertex v, Vertex *pred);

Vertex *GraphDfs(Graph g, Vertex src) {
	Vertex *pred = malloc(g->nV * sizeof(Vertex));
	assert(pred != NULL);
	for (Vertex v = 0; v < g->nV; v++) {
		pred[v] = -1; // not visited
	}
	pred[src] = src;
	
	dfsRecurse(g, src, pred);
	return pred;
}

static void dfsRecurse(Graph g, Vertex v, Vertex *pred) {
	for (Vertex w = 0; w < g->nV; w++) {
		if (g->edges[v][w] == true && pred[w] != -1) {
			pred[w] = v;
			dfsRecurse(g, w, pred);
		}
	}
}

////////////////////////////////////////////////////////////////////////
// Helper Functions

static bool validVertex(Graph g, Vertex v) {
	return (v >= 0 && v < g->nV);
}

