
#include <stdbool.h>

#include "Graph.h"

static bool allVerticesValid(Graph g, Vertex *path, int pathLength);
static bool allEdgesExistInGraph(Graph g, Vertex *path, int pathLength);
static bool allVerticesVisited(Graph g, Vertex *path, int pathLength);

bool verifyHamiltonPath(Graph g, Vertex *path, int pathLength) {
	// Check path length
	if (pathLength != GraphNumVertices(g)) {
		return false;
	}
	
	return allVerticesValid(g, path, pathLength) &&
	       allEdgesExistInGraph(g, path, pathLength) &&
	       allVerticesVisited(g, path, pathLength);
}

// Check all the vertices are valid
static bool allVerticesValid(Graph g, Vertex *path, int pathLength) {
	int N = GraphNumVertices(g);
	for (int i = 0; i < pathLength; i++) {
		if (path[i] < 0 || path[i] >= N) {
			return false;
		}
	}
	return true;
}

// Check all the edges exist in the graph
static bool allEdgesExistInGraph(Graph g, Vertex *path, int pathLength) {
	for (int i = 1; i < pathLength; i++) {
		if (!GraphIsAdjacent(g, path[i - 1], path[i])) {
			return false;
		}
	}
	return true;
}

// Check all the vertices are visited
static bool allVerticesVisited(Graph g, Vertex *path, int pathLength) {
	int N = GraphNumVertices(g);
	bool visited[N];
	for (Vertex v = 0; v < N; v++) {
		visited[v] = false;
	}
	for (int i = 0; i < pathLength; i++) {
		visited[path[i]] = true;
	}
	for (Vertex v = 0; v < N; v++) {
		if (!visited[path[v]]) {
			return false;
		}
	}
	return true;
}

