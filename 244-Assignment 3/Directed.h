#ifndef DIRECTED_H_
#define DIRECTED_H_
#include"Graph.h"

class Directed: public Graph {
public:

	Directed();
	Directed(int, int);
	virtual ~Directed();
	//Directed(const Directed &other);

	//add in one vertex; bool returns if it is added successfully.
	virtual bool addVertex(Vertex &v);
	virtual bool addVertices(Vertex *vArray);

	//the edges that has connection with this vertex need to be removed;
	virtual bool removeVertex(Vertex&v);

	//remove a edge; as a result, some node may remain as orphan.
	virtual bool addEdge(Edge &e);

	// remove the edge
	virtual bool removeEdge(Edge &e);

	// return bool if a vertex exists in a graph;
	virtual bool searchVertex(const Vertex &v);

	// return bool if a Edge exists in a graph;
	virtual bool searchEdge(const Edge &e);

	//path is separated by ';'
	// define your own format of a string representation of the graph.
	virtual void toString() const;

	//remove all the vertices and edges;
	virtual bool clean();

	//1
	bool operator== (const Directed &) const;

	//2
	Directed& operator = (const Directed&);

	//3
	Directed& operator ++ ();       // Pre-increment operator.
	Directed operator ++ (int);     // Post-increment operator.

	//4
	Directed operator+ (Directed &);

	//5
	bool operator > (const Directed&) const;

	//6
	friend ostream& operator << (ostream&, Directed&);

	int getEdgeCounter() {return edge_counter;};

	string graph = ("Graph display");

private:

	int vertex_counter = 0;
	int edge_counter = 0;
	int vertex_size;
	int edge_size;
	Vertex *vertex_array;
	Edge *edge_array;
};

#endif
