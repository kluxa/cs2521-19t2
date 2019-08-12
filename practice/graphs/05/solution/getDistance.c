
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

int getDistance(Graph g, Vertex src, Vertex dest) {
	// The most standard BFS you'll ever see
	int nV = GraphNumVertices(g);
	int pred[nV];
	for (int i = 0; i < nV; i++) {
		pred[i] = -1;
	}
	pred[src] = src;
	
	Queue q = QueueNew();
	QueueEnqueue(q, src);
	while (!QueueIsEmpty(q)) {
		Vertex curr = QueueDequeue(q);
		for (Vertex next = 0; next < nV; next++) {
			if (GraphIsAdjacent(g, curr, next) && pred[next] == -1) {
				pred[next] = curr;
				QueueEnqueue(q, next);
			}
		}
	}
	QueueFree(q);
	
	// Calculate the distance using the predecessor array
	if (pred[dest] == -1) {
		return -1;
	}

	int distance = 0;
	Vertex curr = dest;
	while (curr != src) {
		distance++;
		curr = pred[curr];
	}
	return distance;
}

