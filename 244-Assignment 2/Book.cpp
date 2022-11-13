#include<iostream>
#include<string>
#include"Reference.h"
#include"Book.h"

using namespace std;

Book::Book() {
	publisher = "To be determined";
	pages_of_book = 0;
}

Book::Book(string pub, int pages, string title, string author, int year) :
		Reference(title, author, year) {
	publisher = pub;
	pages_of_book = pages;
}

Book::Book(const Book &other) :
		Reference(other) {
	publisher = this->publisher;
	pages_of_book = this->pages_of_book;
}

Book::~Book() {
}

void Book::setPublisher(string a) {
	publisher = a;
}

void Book::setPagesOfBook(int b) {
	pages_of_book = b;
}

string Book::getPublisher() {
	return publisher;
}

int Book::getNumberOfPages() {
	return pages_of_book;
}

void Book::print() {
	Reference::print();//calls the base class print function first then prints the derived class
	cout << "Publisher Name: " << publisher << endl;
	cout << "Number of Pages in the Book: " << pages_of_book << endl;

}
