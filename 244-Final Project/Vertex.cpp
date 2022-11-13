#include<iostream>
#include<string>
#include"Vertex.h"

using namespace std;

Vertex::Vertex() {
}

Vertex::Vertex(string name) {
	this->vertex_name = name;
}

Vertex::~Vertex() {

}

Vertex::Vertex(const Vertex &other) {
	this->vertex_name = other.vertex_name;
}

bool Vertex::operator ==(const Vertex &other) const {
	return (vertex_name == other.vertex_name);
}

bool Vertex::operator !=(const Vertex &other) const {
	if (vertex_name != other.vertex_name)
		return true;
	else
		return false;
}

string Vertex::getVertex() {
	return vertex_name;
}

void Vertex::setVertex(string a){
	vertex_name = a;
}

