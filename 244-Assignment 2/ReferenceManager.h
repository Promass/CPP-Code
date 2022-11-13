#ifndef REFERENCEMANAGER_H_
#define REFERENCEMANAGER_H_
#include<iostream>
#include<array>
#include"Reference.h"

using namespace std;

class ReferenceManager {

public:

	//Constructor with Capacity input
	ReferenceManager(int capacity);

	//Destructor
	~ReferenceManager();

	//Copy constructor
	ReferenceManager(const ReferenceManager &other);

	//Other functions
	bool addReference(Reference&); //returns true if reference is added to the array, returns false if maximum capacity is reached
	int getReference(int);  //Returns the Id number of the given index
	bool deleteReference(int); //Deletes the element from the array at the given index and pushes everything after it back by one index
	bool searchReference(int); //Search the array for the element with the given Id number
	int getSize() {return size_track;}; //This function was not included in the question but I decided to insert it to keep track on the number of references in the manager array

	//Print function prints all the elements in the manager array and their information
	void print();

private:

	int size_track = 0; // Number of elements in the reference_array
	int array_capacity; // The maximum capacity of the array determined by the user after the laucnh of the code
	Reference **reference_array; //Created pointer to a pointer so that function overridding works

};

#endif
