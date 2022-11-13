#ifndef ARTICLE_H_
#define ARTICLE_H_

#include<iostream>
#include<string>
#include"Reference.h"

using namespace std;

class Article: public Reference { //Derived class of Reference

private:

	string journal_info;
	int start_page;
	int end_page;

public:

	//Default constructor
	Article();

	//Constructor with inputs
	Article(string, int, int, string, string, int);

	//Copy constructor
	Article(const Article&);

	//Destructor
	virtual ~Article();

	//Set functions
	void setJournalInfo(string);
	void setStartPage(int);
	void setEndPage(int);

	//Get functions
	string getJournalInfo();
	int getStartPage();
	int getEndPage();

	int getNumberOfPages();

	void print();

};

#endif
