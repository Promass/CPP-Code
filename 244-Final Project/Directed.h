#ifndef DIRECTED_H_
#define DIRECTED_H_
#include"Graph.h"

// Directed Class: Graph where links are uni-derectional

class Directed: public Graph {
public:
// Constructors
	Directed();
	Directed(int, int);
	virtual ~Directed();
	Directed(const Directed &other);

// Member Functions
	virtual bool addVertex(Vertex &v);
	virtual bool addVertices(Vertex *vArray, int);
	virtual bool removeVertex(Vertex &v);

	virtual bool addEdge(Edge &e);
	virtual bool removeEdge(Edge &e);

	virtual bool searchVertex(const Vertex &v);
	virtual bool searchEdge(const Edge &e);

	virtual void toString() const;
	virtual void path(Vertex);

private:
	int vertex_counter = 0; // Keeps note of the amount of Vertices in the array
	int edge_counter = 0; // Keeps note of the amount of Edges in the array
	int vertex_size; // The amount of Vertices that can be stored in the array
	int edge_size; // The amount of Edges that can be stored in the array
	Vertex *vertex_array; // Dynamically created array of Vertices
	Edge *edge_array; // Dynamically created array of Edges
};

#endif
