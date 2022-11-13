#ifndef EDGE_H_
#define EDGE_H_
#include<iostream>
#include"Edge.h"
#include"Vertex.h"

using namespace std;

// Edge Class: This class takes to Node/Vertex and links them together

class Edge {
public:
// Constructors
	Edge();
	Edge(Vertex, Vertex);
	~Edge();
	Edge(const Edge &other);

// Op-Overloading
	bool operator ==(const Edge&) const; // Equality Operator Overloading
	bool operator !=(const Edge&) const; // Inequality Operator Overloading

// Member Functions
	Vertex getEdgeStart();
	Vertex getEdgeEnd();
	Edge swapEdge(); // SwapEdge function switches the starting vertex with the ending vertex. This function is used in Undirected class to implement bidirectional edges

private:
	Vertex edge_start; //The tail of the arrow
	Vertex edge_end; // The head of the arrow
};

#endif
