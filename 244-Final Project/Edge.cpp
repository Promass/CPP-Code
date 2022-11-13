#include<iostream>
#include"Edge.h"
#include"Vertex.h"

using namespace std;

Edge::Edge() {
}

Edge::Edge(Vertex start, Vertex end) {
	this->edge_start = start;
	this->edge_end = end;
}

Edge::~Edge() {

}

Edge::Edge(const Edge &other) {
	this->edge_start = other.edge_start;
	this->edge_end = other.edge_end;
}

bool Edge::operator==(const Edge &other) const {
	return (edge_start == other.edge_start && edge_end == other.edge_end);

}

bool Edge::operator !=(const Edge &other) const {
	if (edge_start != other.edge_start && edge_end != other.edge_end)
		return true;
	else
		return false;
}

Vertex Edge::getEdgeStart() {
	return edge_start;
}

Vertex Edge::getEdgeEnd() {
	return edge_end;
}

Edge Edge::swapEdge() {
	Edge temp;
	temp.edge_start = this->edge_end;
	temp.edge_end = this->edge_start;
	return temp;
}
