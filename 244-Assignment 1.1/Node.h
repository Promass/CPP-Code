#ifndef NODE_H_
#define NODE_H_
#include<iostream>
#include<string>

using namespace std;

class Node {

private:

	string dataValue;
	int nodeID;

public:

	//Constructor
	Node();
	Node(string);

	//Get Functions
	int getNodeID();
	string getDataValue();

	//Set Function. Note that setting the Id function is unavailable to insure that all Node IDs are unique and initialized automatically.
	void setDataValue(string);

	//Cloning the Node function
	Node nodeClone();

};

#endif
