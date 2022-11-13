#ifndef GRAPH_H_
#define GRAPH_H_
#include<iostream>
#include<string>
#include"Edge.h"
#include"Vertex.h"

using namespace std;

// Graph Class: An abstract class that makes a directed or undirected graph by using Vertex/Node and Edges

class Graph {
public:
// Constructors
	Graph();
	virtual ~Graph();
	Graph(const Graph&);

// Member Functions
	virtual bool addVertex(Vertex &v)=0; // Adds one Vertex to the array
	virtual bool addVertices(Vertex *vArray, int) = 0; // Adds multiple an array of Vertex to the array
	virtual bool removeVertex(Vertex&) = 0; // Removes one Vertex from the array. The Edges that links this Vertex with another also gets removed

	virtual bool addEdge(Edge &e) = 0; // Adds one Edge to the array
	virtual bool removeEdge(Edge&)=0; // Removes one Edge which makes its Vertex unlinked/orphan

	virtual bool searchVertex(const Vertex &v) = 0; // Returns true if the given Vertex is found in the array
	virtual bool searchEdge(const Edge &e) =0; // Returns true if the given Edge is found in the array

	virtual void toString() const = 0; // Displays the Graph in string format
	virtual void path(Vertex) = 0; // List all possible paths to a dead-end, starting from the given Vertex
};

#endif
