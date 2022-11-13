#include<iostream>
#include<string>
#include"Node.h"

using namespace std;

int uniqueID = 1; //Unique Id is given to each node at its creation and incremented.

Node::Node() {
	nodeID = uniqueID;
	uniqueID++;
}

Node::Node(string valuestring) {
	nodeID = uniqueID;
	uniqueID++;
	dataValue = valuestring;
}

int Node::getNodeID() {
	return nodeID;
}

string Node::getDataValue() {
	return dataValue;
}

void Node::setDataValue(string dvalue) {
	dataValue = dvalue;
}

Node Node::nodeClone() {
	Node nodeCopy; //The cloned node has only the data value copied but gets an unique ID from the constructor.
	nodeCopy.setDataValue(dataValue);
	return nodeCopy;
}

