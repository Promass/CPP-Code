#include<iostream>
#include<string>
#include"Node.h"
#include"NodeList.h"

using namespace std;

NodeList::NodeList() {
	items = new Node[LIST_SIZE];
	numitems = 0;
}

NodeList::~NodeList() { //The destructor is called automatically when the scope of the main function ends.
	delete [] items;
	cout << "The list has been deleted" << endl;
}

size_t NodeList::listsize() const {
	return numitems;
}

Node* NodeList::listbegin() const {
	return items;
}

NodeList::NodeList(const NodeList &obj) {
	items = new Node[LIST_SIZE];
	numitems = 0;
	for (size_t d = 0; d < obj.listsize(); d++) {
		items[d] = obj.listbegin()[d];
		numitems++;
	}
}

void NodeList::printlist() {
	cout << endl;
	for (size_t a = 0; a < numitems; a++) {
		cout << "Node " << a + 1 << ", ID: " << items[a].getnodeid()
				<< ", Data Value: " << items[a].getdatavalue() << endl;
	}
	cout << endl;
}

bool NodeList::nodecheckbyid(int id) {
	for (size_t b = 0; b < numitems; b++) {
		if (items[b].getnodeid() == id)
			return true;
	}
	return false;
}

bool NodeList::nodecheckbyvalue(string value) {
	for (size_t c = 0; c < numitems; c++) {
		if (items[c].getdatavalue() == value)
			return true;
	}
	return false;
}

void NodeList::addnode(Node &newnode) {
	if (numitems < LIST_SIZE) {
		items[numitems] = newnode;
		numitems++;
		cout << "Node " << numitems << " was added successfully" << endl;
	} else
		cout << "Node cannot be added since the list is full" << endl;
}
