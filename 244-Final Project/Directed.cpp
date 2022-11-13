#include "Directed.h"

Directed::Directed() {}

Directed::Directed(int v_size, int e_size) {
	vertex_size = v_size;
	edge_size = e_size;
	vertex_array = new Vertex[v_size];
	edge_array = new Edge[e_size];
}

Directed::~Directed() {}

Directed::Directed(const Directed &other) {
	this->edge_size = other.edge_size;
	this->vertex_size = other.vertex_size;
	this->vertex_array = other.vertex_array;
	this->edge_array = other.edge_array;
}

// Adds one Vertex to the array
bool Directed::addVertex(Vertex &v) {
	for (int i = 0; i < vertex_size; i++) {
		if (vertex_array[i] == v)
			return false;
	}
	if (vertex_counter >= vertex_size)
		return false;
	else {
		vertex_array[vertex_counter] = v;
		vertex_counter++;
		return true;
	}
}

// Adds multiple Vertices to the array. The number of vertex is asked to check if the created Vertex array has enough space to fill in
bool Directed::addVertices(Vertex *vArray, int number) {
	if (vertex_size <= number) {
		vertex_array = vArray;
		vertex_counter = number;
		return true;
	}
	return false;
}

// Removes one Vertex from the array. The Edges that links this Vertex with another also gets removed
bool Directed::removeVertex(Vertex &v) {
	for (int i = 0; i < vertex_size; i++) {
		if (vertex_array[i] == v) {
			for (int o = i; o < vertex_size - 1; o++) {
				vertex_array[o] = vertex_array[o + 1];
			}
			vertex_counter--;

			for (int i = 0; i < edge_size; i++) {
				if (edge_array[i].getEdgeStart() == v
						|| edge_array[i].getEdgeEnd() == v) {
					for (int o = i; o < edge_size - 1; o++) {
						edge_array[o] = edge_array[o + 1];

					}
					edge_counter--;
				}
			}

			return true;
		}
	}
	return false;
}

// Adds an Edge to the array
bool Directed::addEdge(Edge &e) {
	for (int i = 0; i < edge_size; i++) {
		if (edge_array[i] == e)
			return false;
	}
	if (edge_counter < edge_size) {
		edge_array[edge_counter] = e;
		edge_counter++;
		return true;
	} else
		return false;
}

// Remove the given Edge as a result some Vertex may remain as orphan.
bool Directed::removeEdge(Edge &e) {
	for (int i = 0; i < edge_size; i++) {
		if (edge_array[i] == e) {
			for (int o = i; o < edge_size - 1; o++) {
				edge_array[o] = edge_array[o + 1];
			}
			edge_counter--;
			return true;
		}
	}
	return false;
}

// Return true if a vertex exists in a graph;
bool Directed::searchVertex(const Vertex &v) {
	for (int i = 0; i < vertex_counter; i++) {
		if (vertex_array[i] == v)
			return true;
	}
	return false;
}

// Return true if an Edge exists in a graph;
bool Directed::searchEdge(const Edge &e) {
	for (int i = 0; i < edge_size; i++) {
		if (edge_array[i] == e) {
			return true;
		}
	}
	return false;
}

// String representation of the graph.
void Directed::toString() const {
	bool andcount = false;
	bool noedge = true;
	cout << "===========================================" << endl;
	cout << "String Representation of the Directed Graph" << endl;
	cout << "===========================================" << endl;
	for (int i = 0; i < vertex_counter; i++) {
		cout << vertex_array[i].getVertex() << " ----> ";
		for (int o = 0; o < edge_counter; o++) {
			if (vertex_array[i] == edge_array[o].getEdgeStart()) {
				if (andcount == true)
					cout << "and ";
				cout << (edge_array[o].getEdgeEnd()).getVertex() << " ";
				andcount = true;
				noedge = false;

			}
		}
		if (noedge == true)
			cout << "Nothing";
		andcount = false;
		noedge = true;
		cout << endl;
	}
	cout << endl;
}

// Lists all possible paths starting from the given Vertex
void Directed::path(Vertex test) {
	bool isthere = false;
	for (int idx = 0; idx < edge_counter; idx++) {
		if (edge_array[idx].getEdgeStart() == test) {
			isthere = true;
			cout << (edge_array[idx].getEdgeStart()).getVertex() << " ----> ";
			Vertex temp;
			temp = edge_array[idx].getEdgeEnd();
			this->path(temp);
		}
	}
	if (isthere == false){
		cout << test.getVertex() << endl;
	}
}
