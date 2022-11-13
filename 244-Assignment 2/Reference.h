#ifndef REFERENCE_H_
#define REFERENCE_H_

#include<iostream>
#include<string>

using namespace std;

class Reference {

private:

	int reference_id;
	string reference_title;
	string reference_author;
	int publication_year;

public:

	//Default Constructor
	Reference();

	//Constructor with input variables
	Reference(string, string, int); //Note that the reference id variable cannot be inputed directly as every time a reference is created an unique Id is automatically assigned to it

	//Copy constructor
	Reference(const Reference&);

	//Destructor
	virtual ~Reference();

	//Set functions
	void setReferenceId(int); //The unique Id can only be changed via setReferenceId function
	void setReferenceTitle(string);
	void setReferenceAuthor(string);
	void setPublicationYear(int);

	//Get functions
	int getReferenceId();
	string getreferenceTitle();
	string getReferenceAuthor();
	int getPublicationYear();

	//Print function
	virtual void print(); //Set to virtual for function override

};

#endif
