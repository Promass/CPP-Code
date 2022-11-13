#ifndef TEXTBOOK_H_
#define TEXTBOOK_H_

#include<iostream>
#include<string>
#include"Book.h"

using namespace std;

class TextBook: public Book { //Derived class of Book

private:

	string URL;

public:

	//Default constructor
	TextBook();

	//Constructor with inputs
	TextBook(string, string, int, string, string, int);

	//Copy constructor
	TextBook(const TextBook&);

	//Destructor
	virtual ~TextBook();

	//Set functions
	void setTextBookURL(string);

	//Get functions
	string getTextBookURL();

	void print();

};

#endif
