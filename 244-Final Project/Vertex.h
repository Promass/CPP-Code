#ifndef VERTEX_H_
#define VERTEX_H_
#include<iostream>
#include<string>

// Vertex Class: This is the class of Node/Vertex which will be linked to other Node/Vertex using Edge class

using namespace std;

class Vertex {
public:
// Constructors
	Vertex();
	Vertex(string name);
	~Vertex();
	Vertex(const Vertex&);

// Op-Overloading
	bool operator ==(const Vertex&) const; // Equality Operator to compare Vertex objects
	bool operator !=(const Vertex&) const; // Inequality Operator to compare Vertex objects

//Member Functions
	string getVertex(); // Return Vertex name, mainly used in print functions
	void setVertex(string); // Set Vertex Name

private:
	string vertex_name;
};

#endif
