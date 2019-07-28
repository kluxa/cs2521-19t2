// Interface for an Undirected Graph ADT where vertices are identified
// by integers between 0 and N - 1, where N is the number of vertices.

#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

typedef int Vertex;

typedef struct graph *Graph;

/**
 * Creates a new Graph with the given number of vertices and no edges.
 */
Graph GraphNew(int nV);

/**
 * Frees all the memory allocated for the given Graph.
 */
void GraphFree(Graph g);

/**
 * Returns the number of edges in the given Graph.
 */
int GraphNumVertices(Graph g);

/**
 * Adds  an  undirected edge between two vertices to the given Graph. If
 * the edge already exists, this function does nothing.
 * @pre - v != w
 */
void GraphAddEdge(Graph g, Vertex v, Vertex w);

/**
 * Removes an undirected edge between two vertices from the given Graph.
 * If the edge does not exist, this function does nothing.
 * @pre - v != w
 */
void GraphRemoveEdge(Graph g, Vertex v, Vertex w);

/**
 * Checks  whether two vertices are adjacent in the given Graph. Returns
 * true or false as appropriate.
 */
bool GraphIsAdjacent(Graph g, Vertex v, Vertex w);

/**
 * Returns  the  number of neighbours of a given vertex. A vertex is not
 * considered to be a neighbour of itself.
 */
int GraphNumNeighbours(Graph g, Vertex v);

#endif
