#ifndef NODE_H_
#define NODE_H_
#include<iostream>
#include<string>

using namespace std;

class Node {

private:

	string datavalue;
	int nodeid;

public:

	//Constructors
	Node();
	Node(string);

	//Copy constructor
	Node(const Node &obj);

	//Destructor
	~Node();

	//Get functions
	int getnodeid();
	string getdatavalue() const;

	//Set functions. Note that there are no set ID functions because the id are automatically to keep them unique.
	void setdatavalue(string);


};

#endif
