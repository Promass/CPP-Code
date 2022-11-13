#ifndef UNDIRECTED_H_
#define UNDIRECTED_H_
#include"Graph.h"

// Undirected Class: Graph where links are bi-directional

class Undirected: public Graph {
public:
// Constructors
	Undirected();
	Undirected(int, int);
	virtual ~Undirected();
	Undirected(const Undirected &other);

// Member Functions
	virtual bool addVertex(Vertex &v);
	virtual bool addVertices(Vertex *vArray, int);
	virtual bool removeVertex(Vertex &v);

	virtual bool addEdge(Edge &e);
	virtual bool removeEdge(Edge &e);

	virtual bool searchVertex(const Vertex &v);
	virtual bool searchEdge(const Edge &e);

	virtual void toString() const;

/* The path function in Undirected graphs uses two separate arrays to store the linking paths. Since Vertices are bi-directionally connected to each other, they are both
* the tail and the head of an arrow. So, to show all possible paths, we basically separate the bi-directional arrow to two uni-directional arrows pointing to different
* sides (Head and Tail). Path1 stores the Vertex only when it is at the head of an arrow. Similarly, path2 stores the same Vertex only when it is at the tail of an arrow
* There are more efficient ways to implement the path function using list, however we decided to work with only what we learned in this course.*/
	virtual void path(Vertex);
	void path1(Vertex);
	void path2(Vertex);

private:
	int vertex_counter = 0;
	int edge_counter = 0;
	int vertex_size;
	int edge_size;
	Vertex *vertex_array;
	Edge *edge_array;
	Edge *path_1; // Stores one of the Uni-directional links
	Edge *path_2; // Stores one of the Uni-directional links
	int path_idx = 0; // Keeps track of the number of links
};

#endif

