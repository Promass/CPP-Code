#include<iostream>
#include<string>
#include"Node.h"

using namespace std;

int main() {

	Node first_node; //Creating a node using default constructor
	Node second_node("second data value"); //Creating a node using direct default constructor

	first_node.setDataValue("first data value");

	cout << "The ID of first node: " << first_node.getNodeID() << endl;
	cout << "The data value of first node: " << first_node.getDataValue()
			<< endl;

	cout << "\nThe ID of second node: " << second_node.getNodeID() << endl;
	cout << "The data value of second node: " << second_node.getDataValue()
			<< endl;

	Node first_copy_node = second_node.nodeClone();//Showing the functionality of node clone function

	cout << "\nThe ID of cloned node: " << first_copy_node.getNodeID() << endl;
	cout << "The data value of cloned node: " << first_copy_node.getDataValue()
			<< endl;

	Node second_copy_node = first_node.nodeClone();

	cout << "\nThe ID of cloned node: " << second_copy_node.getNodeID() << endl;
	cout << "The data value of cloned node: " << second_copy_node.getDataValue()
			<< endl;

	return 0;

}
