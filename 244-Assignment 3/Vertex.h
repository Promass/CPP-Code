#ifndef VERTEX_H_
#define VERTEX_H_
#include<iostream>
#include<string>

using namespace std;

class Vertex {
public:
	Vertex();
	Vertex(string name);
	~Vertex();
	//Vertex(const Vertex&);

	bool operator == (const Vertex&) const;
	bool operator != (const Vertex&) const;

	string getVertex();

private:
	string vertex_name;
};

#endif
