#include "Undirected.h"

Undirected::Undirected() {
}

Undirected::Undirected(int v_size, int e_size) {
	vertex_size = v_size;
	edge_size = 2 * e_size;
	vertex_array = new Vertex[v_size];
	edge_array = new Edge[2 * e_size];
	path_1 = new Edge[e_size];
	path_2 = new Edge[e_size];
}

Undirected::~Undirected() {
}

Undirected::Undirected(const Undirected &other) {
	this->edge_size = other.edge_size;
	this->vertex_size = other.vertex_size;
	this->vertex_array = other.vertex_array;
	this->edge_array = other.edge_array;
	this->path_1 = other.path_1;
	this->path_2 = other.path_2;
}

// Adds one Vertex to the array
bool Undirected::addVertex(Vertex &v) {
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
// The number of vertex is asked to check if the created vertex array has enough space to fill in
bool Undirected::addVertices(Vertex *vArray, int number) {
	if (vertex_size <= number) {
		vertex_array = vArray;
		vertex_counter = number;
		return true;
	}
	return false;
}

// Remove Vertex. The edges that has connection with this vertex will be removed
bool Undirected::removeVertex(Vertex &v) {
	for (int i = 0; i < vertex_size; i++) {
		if (vertex_array[i] == v) {
			for (int o = i; o < vertex_size - 1; o++) {
				vertex_array[o] = vertex_array[o + 1];
			}
			vertex_counter--;

			for (int j = 0; j < edge_size; j++) {
				if (edge_array[j].getEdgeStart() == v
						|| edge_array[j].getEdgeEnd() == v) {
					for (int o = j; o < edge_size - 1; o++) {
						edge_array[o] = edge_array[o + 1];

					}
					edge_counter--;
				}
			}

			for (int idx = 0; idx < edge_size / 2; idx++) {
				if (path_1[idx].getEdgeStart() == v
						|| path_1[idx].getEdgeEnd() == v) {
					for (int o = idx; o < edge_size / 2 - 1; o++) {
						path_1[o] = path_1[o + 1];

					}
				}
				if (path_2[idx].getEdgeStart() == v
						|| path_2[idx].getEdgeEnd() == v) {
					for (int o = idx; o < edge_size / 2 - 1; o++) {
						path_2[o] = path_2[o + 1];

					}
				}
				path_idx--;
			}

			return true;
		}
	}
	return false;
}

// Add an Edge
bool Undirected::addEdge(Edge &e) {
	for (int i = 0; i < edge_size; i++) {
		if (edge_array[i] == e)
			return false;
	}
	if (edge_counter + 1 < edge_size) {

		path_1[path_idx] = e;
		path_2[path_idx] = e.swapEdge();
		path_idx++;

		edge_array[edge_counter] = e;
		edge_counter++;
		edge_array[edge_counter] = e.swapEdge();
		edge_counter++;
		return true;
	} else
		return false;
}

// Remove the edge as a result some node may remain as orphan.
bool Undirected::removeEdge(Edge &e) {
	bool alldeleted = false;
	for (int i = 0; i < edge_size; i++) {
		if (edge_array[i] == e || edge_array[i] == e.swapEdge()) {
			for (int o = i; o < edge_size - 1; o++) {
				edge_array[o] = edge_array[o + 1];
			}
			edge_counter--;
			alldeleted = true;
		}
	}
	return alldeleted;
}

// Return bool if a vertex exists in a graph;
bool Undirected::searchVertex(const Vertex &v) {
	for (int i = 0; i < vertex_counter; i++) {
		if (vertex_array[i] == v)
			return true;
	}
	return false;
}

// Return bool if an Edge exists in a graph;
bool Undirected::searchEdge(const Edge &e) {
	for (int i = 0; i < edge_size; i++) {
		if (edge_array[i] == e) {
			return true;
		}
	}
	return false;
}

// String representation of the graph.
void Undirected::toString() const {
	bool andcount = false;
	bool noedge = true;
	cout << "=============================================" << endl;
	cout << "String Representation of the Undirected Graph" << endl;
	cout << "=============================================" << endl;
	for (int i = 0; i < vertex_counter; i++) {
		cout << vertex_array[i].getVertex() << " <----> ";
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

// List all possible paths from a starting Vertex
void Undirected::path(Vertex test) {
	path1(test);
	path2(test);
}

void Undirected::path1(Vertex test1) {
	bool isthere = false;
	for (int idx = 0; idx < path_idx; idx++) {
		if (path_1[idx].getEdgeStart() == test1) {
			isthere = true;
			cout << (path_1[idx].getEdgeStart()).getVertex() << " ----> ";
			Vertex temp;
			temp = path_1[idx].getEdgeEnd();
			this->path1(temp);
		}

	}
	if (isthere == false)
		cout << test1.getVertex() << endl;
}

void Undirected::path2(Vertex test2) {

	bool isthere = false;
	for (int idx = 0; idx < path_idx; idx++) {
		if (path_2[idx].getEdgeStart() == test2) {
			isthere = true;
			cout << (path_2[idx].getEdgeStart()).getVertex() << " ----> ";
			Vertex temp;
			temp = path_2[idx].getEdgeEnd();
			this->path2(temp);
		}

	}
	if (isthere == false)
		cout << test2.getVertex() << endl;
}
