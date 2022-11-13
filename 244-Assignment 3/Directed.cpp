#include "Directed.h"


Directed::Directed(){

}

Directed::Directed(int v_size, int e_size) {
	vertex_size = v_size;
	edge_size = e_size;
	vertex_array = new Vertex[v_size];
	edge_array = new Edge[e_size];
}

Directed::~Directed() {

}

/*Directed::Directed(const Directed &other) {
 this->edge_size = other.edge_size;
 this->vertex_size = other.vertex_size;
 this->vertex_array = other.vertex_array;
 this->edge_array = other.edge_array;
 }*/

//add in one vertex; bool returns if it is added successfully.
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
// The amount of vertex is asked to check if the created vertex array has enough space to fill in
bool Directed::addVertices(Vertex *vArray) {
	int number;
	cout << "How many vertices are you adding (Enter integer = 3 for the purpose of this demo): ";
	cin >> number;
	cout <<endl;
	if (vertex_size <= number) {
		vertex_array = vArray;
		vertex_counter = number;
		return true;
	}
	return false;
}

//the edges that has connection with this vertex need to be removed;
bool Directed::removeVertex(Vertex &v) {
	for (int i = 0; i < vertex_size; i++) {
		if (vertex_array[i] == v) {
			for (int o = i; o < vertex_size-1; o++) {
				vertex_array[o] = vertex_array[o + 1];
			}
			vertex_counter--;

			for (int i = 0; i < edge_size; i++){
				if (edge_array[i].getEdgeStart()== v || edge_array[i].getEdgeEnd()==v){
					for (int o = i; o < edge_size-1; o++){
						edge_array[o] = edge_array[o+1];

					}
					edge_counter--;
				}
			}

			return true;
		}
	}
	return false;
}

//add an edge
bool Directed::addEdge(Edge &e) {
	for (int i = 0; i < edge_size; i++){
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

// remove the edge as a result, some node may remain as orphan.
bool Directed::removeEdge(Edge &e) {
	for (int i = 0; i < edge_size; i++) {
		if (edge_array[i] == e) {
			for (int o = i; o < edge_size-1; o++) {
				edge_array[o] = edge_array[o + 1];
			}
			edge_counter--;
			return true;
		}
	}
	return false;
}

// return bool if a vertex exists in a graph;
bool Directed::searchVertex(const Vertex &v) {
	for (int i = 0; i < vertex_counter; i++) {
		if (vertex_array[i] == v)
			return true;
	}
	return false;
}

// return bool if a Edge exists in a graph;
bool Directed::searchEdge(const Edge &e) {
	for (int i = 0; i < edge_size; i++) {
		if (edge_array[i] == e){
			return true;}
	}
	return false;
}

//path is separated by ';'
// define your own format of a string representation of the graph.
void Directed::toString() const {
	bool andcount = false;
	bool noedge = true;
	cout << "==================================" << endl;
	cout << "String Representation of the Graph" << endl;
	cout << "==================================" << endl;
	for (int i = 0; i < vertex_counter; i++){
		cout << "Vertex (" <<vertex_array[i].getVertex() << ") is unidirectionaly connected to ";
		for (int o = 0; o < edge_counter; o++){
			if (vertex_array[i] == edge_array[o].getEdgeStart()){
				if (andcount == true)
					cout << "and ";
				cout << "("<<(edge_array[o].getEdgeEnd()).getVertex() << ") ";
				andcount = true;
				noedge = false;

			}
		}
		if (noedge == true)
			cout << "nothing";
		andcount = false;
		noedge = true;
		cout << endl;
	}
	cout <<endl;
}

//remove all the vertices and edges;
bool Directed::clean() {
	delete[] vertex_array;
	delete[] edge_array;
	return true;
}

//1
bool Directed::operator == (const Directed & other) const{
	if (vertex_size != other.vertex_size || edge_size != other.edge_size)
		return false;
	for (int i = 0; i < vertex_size; i++){
		if (vertex_array[i] != other.vertex_array[i])
			return false;
		else if (edge_array[i] != other.edge_array[i])
			return false;
	}
	return true;
}

//2
Directed& Directed::operator = (const Directed &other){
	if (this != &other){
		vertex_array = other.vertex_array;
		edge_array = other.edge_array;
		vertex_counter = other.vertex_counter;
		vertex_size = other.vertex_size;
		edge_counter = other.edge_counter;
		edge_size = other.edge_size;
	}
	return *this;
}

//3
Directed& Directed::operator ++ (){ 	// Pre-increment operator.
	edge_counter++; // I am guessing when they say weights of edges, they mean the number of edges in the edge array. In my case the number of edges in the array is equal to edge_counter
	return *this;
}
Directed Directed::operator ++ (int number){	// Post-increment operator.
	Directed temp = *this;
	++(*this);
	return temp;
}

//4
Directed Directed::operator+ (Directed &other){
	Directed temp;
	int counter1 = 0;
	int counter2 = 0;
	temp.vertex_size = vertex_size + other.vertex_size;
	temp.edge_size = edge_size + other.edge_size;
	temp.vertex_array = new Vertex [temp.vertex_size];
	temp.edge_array = new Edge [temp.edge_size];

	for (int i = temp.vertex_counter; i < vertex_size; i++){
		temp.vertex_array[i] = vertex_array[i];
	}
	temp.vertex_counter = temp.vertex_counter + vertex_size;
	for (int o = temp.vertex_counter; o <(temp.vertex_counter + other.vertex_size); o++){
		temp.vertex_array[o] = other.vertex_array[counter1];
		++counter1;
	}
	temp.vertex_counter = temp.vertex_counter + other.vertex_size;

	for (int i = temp.edge_counter; i < edge_size; i++){
			temp.edge_array[i] = edge_array[i];
		}
		temp.edge_counter = temp.edge_counter + edge_size;
		for (int o = temp.edge_counter; o <(temp.edge_counter + other.edge_size); o++){
			temp.edge_array[o] = other.edge_array[counter2];
			++counter2;
		}
		temp.edge_counter = temp.edge_counter + other.edge_size;

		return temp;
}

//5
bool Directed::operator > (const Directed& other) const{
	if (edge_size > other.edge_size)
		return true;
	else
		return false;
}

//6
ostream& operator << (ostream& output, Directed other){ // Didn't have time to fully implement
	output << other.graph << endl;
	return output;
}
