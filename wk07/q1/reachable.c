
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Set.h"

void doReachable(Graph g, Vertex v, Set s);

Set reachable(Graph g, Vertex v) {
	Set s = SetNew();
	doReachable(g, v, s);
	return s;
}

void doReachable(Graph g, Vertex v, Set s) {
	SetAdd(s, v);
	int nV = GraphNumVertices(g);
	for (int w = 0; w < nV; w++) {
		if (GraphIsAdjacent(g, v, w) && !SetContains(s, w)) {
			doReachable(g, w, s);
		}
	}
}
