#include<iostream>
#include<string>
#include"Book.h"
#include"TextBook.h"

TextBook::TextBook() {
	URL = "To be determined";
}

TextBook::TextBook(string link, string pub, int pages, string title,
		string author, int year) :
		Book(pub, pages, title, author, year) {
	URL = link;
}

TextBook::TextBook(const TextBook &other) :
		Book(other) {
	URL = this->URL;
}

TextBook::~TextBook() {
}

void TextBook::setTextBookURL(string a) {
	URL = a;
}

string TextBook::getTextBookURL() {
	return URL;
}

void TextBook::print() {
	Book::print();//calls the base class print function first then prints the derived class
	cout << "The link of the textbook: " << URL << endl;
}
