#ifndef NODELIST_H_
#define NODELIST_H_
#include<iostream>
#include<string>

using namespace std;

class NodeList {

private:

	//As shown in the Question paper
	static const size_t LIST_SIZE = 500;
	Node *items;
	size_t numitems;

public:

	//Constructor
	NodeList();

	//Destructor
	~NodeList();

	//Copy constructor
	NodeList(const NodeList &obj);

	//Prints the content of the list
	void printlist();

	//Checks the list for Nodes with given ID or Value
	bool nodecheckbyid(int);
	bool nodecheckbyvalue(string);

	//Gives the number of Node objects in the list
	size_t listsize() const;

	//Points to the beginning of the list
	Node* listbegin() const;

	//Adds a Node object to the list
	void addnode(Node &n);

};

#endif
