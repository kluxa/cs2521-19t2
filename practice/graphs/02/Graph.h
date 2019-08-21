// Interface for an Undirected Graph ADT where vertices are identified
// by integers between 0 and N - 1, where N is the number of vertices.

#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

typedef int Vertex;
typedef struct {
	Vertex v;
	Vertex w;
} Edge;

typedef struct graph *Graph;

////////////////////////////////////////////////////////////////////////
// Constructors

/**
 * Creates a new graph with the given number of vertices and no edges.
 */
Graph GraphNew(int nV);

/**
 * Creates a new graph with edges as given in the boolean matrix.
 * @param nV - the number of vertices
 * @param edges - a  matrix of booleans indicating which edges the graph
 *                should contain (true = edge, false = no edge)
 * @pre - for all v, edges[v][v] is false
 */
Graph GraphNewFromMatrix(int nV, bool edges[nV][nV]);

/**
 * Creates a new graph with edges as given in the array of edges.
 * @param nV - the number of vertices
 * @param nE - the number of edges
 * @param edges - an  array of edges, where each edge is an array of two
 *                vertices
 * @pre - for all edges {v, w}, v != w
 *
 * Example Usage:
 *  Edge edges[] = {
 *  	{0, 1}, {1, 2}, {2, 3}, {3, 0}
 *  };
 *  Graph g = GraphNewFromEdgeArray(4, 4, edges);
 */
Graph GraphNewFromEdgeArray(int nV, int nE, Edge *edges);

/**
 * Creates a copy of the given graph.
 */
Graph GraphCopy(Graph g);

////////////////////////////////////////////////////////////////////////
// Destructors

/**
 * Frees all the memory allocated for the given graph.
 */
void GraphFree(Graph g);

////////////////////////////////////////////////////////////////////////
// General Graph Functions

/**
 * Returns the number of vertices in the given graph.
 */
int GraphNumVertices(Graph g);

/**
 * Checks  whether two vertices are adjacent in the given graph. Returns
 * true or false as appropriate.
 */
bool GraphIsAdjacent(Graph g, Vertex v, Vertex w);

////////////////////////////////////////////////////////////////////////
// Displaying the Graph

void GraphDump(Graph g, FILE *fp);

////////////////////////////////////////////////////////////////////////
// Graph Search Algorithms

typedef struct {
	int     src;
	Vertex *pred;
	Vertex *visitOrder;
	int     numVisited;
} Traversal;

/**
 * Performs  a  breadth-first  search on the graph starting at the given
 * vertex.
 * @returns - a  struct  containing information about the traversal with
 *            these fields:
 *            src        - the starting vertex
 *            pred       - a  dynamically allocated array of predecessor
 *                         vertices.  The  predecessor  of src is set to
 *                         be itself.  If  a  vertex is unreachable, its
 *                         predecessor is set to -1.
 *            visitOrder - the order in which the vertices were visited
 *            numVisited - the number of vertices that were visited
 */
Traversal GraphBfs(Graph g, Vertex src);

/**
 * Performs  a  depth-first  search  on  the graph starting at the given
 * vertex.
 * @returns - a  struct  containing information about the traversal with
 *            these fields:
 *            src        - the starting vertex
 *            pred       - a  dynamically allocated array of predecessor
 *                         vertices.  The  predecessor  of src is set to
 *                         be itself.  If  a  vertex is unreachable, its
 *                         predecessor is set to -1.
 *            visitOrder - the order in which the vertices were visited
 *            numVisited - the number of vertices that were visited
 */
Traversal GraphDfs(Graph g, Vertex src);

#endif

