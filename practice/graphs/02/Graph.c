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

Graph GraphCopy(Graph g) {
	Graph copy = doGraphNew(g->nV);
	for (int i = 0; i < g->nV; i++) {
		for (int j = 0; j < g->nV; j++) {
			copy->edges[i][j] = g->edges[i][j];
		}
	}
	return copy;
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
static Traversal newTraversal(Graph g, Vertex src);

////////
// BFS
Traversal GraphBfs(Graph g, Vertex src) {
	assert(g != NULL);
	assert(validVertex(g, src));
	
	Traversal t = newTraversal(g, src);
	t.pred[src] = src;
	
	Queue q = QueueNew();
	QueueEnqueue(q, src);
	while (!QueueIsEmpty(q)) {
		Vertex v = QueueDequeue(q);
		t.visitOrder[t.numVisited++] = v;
		for (Vertex w = 0; w < g->nV; w++) {
			if (g->edges[v][w] == true && t.pred[w] == -1) {
				t.pred[w] = v;
				QueueEnqueue(q, w);
			}
		}
	}
	
	QueueDrop(q);
	return t;
}

////////
// DFS
static void dfsRecurse(Graph g, Vertex v, Traversal *t);

Traversal GraphDfs(Graph g, Vertex src) {
	assert(g != NULL);
	assert(validVertex(g, src));
	
	Traversal t = newTraversal(g, src);
	t.pred[src] = src;
	
	dfsRecurse(g, src, &t);
	return t;
}

static void dfsRecurse(Graph g, Vertex v, Traversal *t) {
	t->visitOrder[t->numVisited++] = v;
	for (Vertex w = 0; w < g->nV; w++) {
		if (g->edges[v][w] == true && t->pred[w] != -1) {
			t->pred[w] = v;
			dfsRecurse(g, w, t);
		}
	}
}

////////////////////////////////////////////////////////////////////////
// Helper Functions

static bool validVertex(Graph g, Vertex v) {
	return (v >= 0 && v < g->nV);
}

static Traversal newTraversal(Graph g, Vertex src) {
	Traversal t = {
		.src        = src,
		.pred       = malloc(g->nV * sizeof(Vertex)),
		.visitOrder = malloc(g->nV * sizeof(Vertex)),
		.numVisited = 0
	};
	
	if (t.pred == NULL || t.visitOrder == NULL) {
		fprintf(stderr, "newTraversal: Insufficient memory!\n");
		exit(EXIT_FAILURE);
	}
	
	for (Vertex v = 0; v < g->nV; v++) {
		t.pred[v] = -1;
	}
	
	return t;
}

