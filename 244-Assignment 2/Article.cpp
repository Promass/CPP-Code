#include<iostream>
#include<string>
#include"Reference.h"
#include"Article.h"

using namespace std;

Article::Article() {
	journal_info = "To be determined";
	start_page = 0;
	end_page = 0;
}

Article::Article(string info, int start, int end, string title, string author,
		int year):Reference(title, author, year) {

	journal_info = info;
	start_page = start;
	end_page = end;
}

Article::Article(const Article &other) :
		Reference(other) {
	journal_info = this->journal_info;
	start_page = this->start_page;
	end_page = this->end_page;

}

Article::~Article() {
}

void Article::setJournalInfo(string a) {
	journal_info = a;
}

void Article::setStartPage(int b) {
	start_page = b;
}

void Article::setEndPage(int c) {
	end_page = c;
}

string Article::getJournalInfo() {
	return journal_info;
}

int Article::getStartPage() {
	return start_page;
}

int Article::getEndPage() {
	return end_page;
}

int Article::getNumberOfPages() {
	return (end_page - start_page);
}

void Article::print() {
	Reference::print(); //calls the base class print function first then prints the derived class
	cout << "Article Information: " << this->journal_info << endl;
	cout << "Total Pages of Article: " << this->getNumberOfPages() << endl;

}

