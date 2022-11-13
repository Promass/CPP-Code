#include<iostream>
#include<string>
#include"Node.h"
#include"NodeList.h"

using namespace std;

int main() {

	//Creating five Nodes
	Node node1("First Node Data Value");
	Node node2("Second Node Data Value");
	Node node3("Third Node Data Value");
	Node node4("Fourth Node Data Value");
	Node node5 = node1; //Showing that copy constructor works (Check List Print)

	//Adding all five Nodes into the list
	NodeList list;
	list.addnode(node1);
	list.addnode(node2);
	list.addnode(node3);
	list.addnode(node4);
	list.addnode(node5);

	//First list print
	list.printlist();

	//Search by ID: 3
	if (list.nodecheckbyid(3) == true)
		cout << "The Node with id number 3 is in the list\n" << endl;
	else
		cout << "The Node with id number 3 is not in the list\n" << endl;

	//Search by a wrong Value: Sixth Node Data Value (DNE)
	if (list.nodecheckbyvalue("Sixth Node Data Value") == true)
		cout << "The Node with the given data value is in the list\n" << endl;
	else
		cout << "The Node with the given data value is not in the list\n" << endl;

	//The size of first list
	cout << "The size of list: " << list.listsize() << endl;

	//Cloning the list
	NodeList copylist = list;

	//Copy list print
	copylist.printlist();

	//The size of the cloned list
	cout << "The size of list clone: " << copylist.listsize() << endl << endl;

}
