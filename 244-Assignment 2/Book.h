#ifndef BOOK_H_
#define BOOK_H_

#include<iostream>
#include<string>
#include"Reference.h"

using namespace std;

class Book: public Reference { //Derived class of Reference

private:

	string publisher;
	int pages_of_book;

public:

	//Default constructor
	Book();

	//Constructor with inputs
	Book(string, int, string, string, int);

	//Copy constructor
	Book(const Book&);

	//Destructor
	virtual ~Book();

	//Set functions
	void setPublisher(string);
	void setPagesOfBook(int);

	//Get functions
	string getPublisher();
	int getNumberOfPages();

	void print();
};

#endif
