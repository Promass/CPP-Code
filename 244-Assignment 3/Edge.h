#ifndef EDGE_H_
#define EDGE_H_
#include<iostream>
#include"Edge.h"
#include"Vertex.h"

using namespace std;

class Edge {
public:
	Edge();
	Edge(Vertex, Vertex);
	~Edge();
	//Edge(const Edge &other);

	bool operator == (const Edge&)const ;
	bool operator != (const Edge&) const;

	Vertex getEdgeStart();
	Vertex getEdgeEnd();

private:
	Vertex edge_start;
	Vertex edge_end;
};

#endif
