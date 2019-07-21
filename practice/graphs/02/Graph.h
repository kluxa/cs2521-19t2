// Interface for an Undirected Graph ADT where vertices are identified
// by integers between 0 and N - 1, where N is the number of vertices.

#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

typedef int Vertex;

typedef struct graph *Graph;

////////////////////////////////////////////////////////////////////////
// Constructors

/**
 * Creates a new Graph with the given number of vertices and no edges.
 */
Graph GraphNew(int nV);

/**
 * Creates a new Graph with edges as given in the boolean matrix.
 * @param nV - the number of vertices
 * @param edges - a  matrix of booleans indicating which edges the graph
 *                should contain (true = edge, false = no edge)
 * @pre - for all v, edges[v][v] is false
 */
Graph GraphNewFromMatrix(int nV, bool edges[nV][nV]);

////////////////////////////////////////////////////////////////////////
// Destructors

/**
 * Frees all the memory allocated for the given Graph.
 * @param g - the graph to be freed
 */
void GraphFree(Graph g);

////////////////////////////////////////////////////////////////////////
// General Graph Functions

/**
 * Returns the number of edges in the given Graph.
 */
int GraphNumVertices(Graph g);

/**
 * Checks  whether two vertices are adjacent in the given Graph. Returns
 * true or false as appropriate.
 */
bool GraphIsAdjacent(Graph g, Vertex v, Vertex w);

////////////////////////////////////////////////////////////////////////
// Displaying the Graph

void GraphDump(Graph g, FILE *fp);

////////////////////////////////////////////////////////////////////////
// Graph Search Algorithms

/**
 * Performs  a  breadth-first  search  on  a graph starting at the given
 * vertex.
 * @returns - a dynamically allocated array of predecessor vertices. The
 *            predecessor of the starting vertex is set to be itself. If
 *            a vertex is unreachable, its predecessor is set to -1.
 */
Vertex *GraphBfs(Graph g, Vertex src);

/**
 * Performs a depth-first search on a graph starting at the given vertex
 * @returns - a dynamically allocated array of predecessor vertices. The
 *            predecessor of the starting vertex is set to be itself. If
 *            a vertex is unreachable, its predecessor is set to -1.
 */
Vertex *GraphDfs(Graph g, Vertex src);

#endif

