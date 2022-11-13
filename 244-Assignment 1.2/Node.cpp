#include<iostream>
#include<string>
#include"Node.h"

using namespace std;

int uniqueid = 1; // Unique ID assigned to each node at its creation

Node::Node(){
	nodeid = uniqueid;
	uniqueid++;
}

Node::Node(string valuestring){ //Secondary constructor for direct value assignment
	nodeid = uniqueid;
	uniqueid++;
	datavalue = valuestring;
}

Node::~Node() {
}

int Node::getnodeid() {
	return nodeid;
}

string Node::getdatavalue() const{
	return datavalue;
}

void Node::setdatavalue(string dvalue) {
	datavalue = dvalue;
}

Node::Node(const Node &obj) { //Even if the copy constructor copies the Node into a new Node, the new Node will have an unique ID
	nodeid = uniqueid;
	uniqueid++;
	datavalue = obj.getdatavalue();
}
