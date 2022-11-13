#include<iostream>
#include<string>
#include"Reference.h"

using namespace std;

int unique_id = 0; // A global integer variable which is used for reference_id. Even if the reference is deleted the id will never be re-used.

Reference::Reference(){ //Default constructor inputs default values
	reference_id = ++unique_id;
	publication_year = 0;
	reference_author = "To be determined";
	reference_title = "To be determined";
}

Reference::Reference(string title, string author, int year) {
	reference_id = ++unique_id;
	publication_year = year;
	reference_author = author;
	reference_title = title;
}

Reference::Reference(const Reference &other) {
	reference_id = this->reference_id;
	publication_year = this->publication_year;
	reference_author = this->reference_author;
	reference_title = this->reference_title;
}

Reference::~Reference() {
}

void Reference::setReferenceId(int a) {
	reference_id = a;
}
void Reference::setReferenceTitle(string b) {
	reference_title = b;
}
void Reference::setReferenceAuthor(string c) {
	reference_author = c;
}
void Reference::setPublicationYear(int d) {
	publication_year = d;
}

int Reference::getReferenceId() {
	return reference_id;
}
string Reference::getreferenceTitle() {
	return reference_title;
}
string Reference::getReferenceAuthor() {
	return reference_author;
}
int Reference::getPublicationYear() {
	return publication_year;
}

void Reference::print() {
	cout << "Reference Id: " << this->reference_id << endl;
	cout << "Reference Title: " << this->reference_title << endl;
	cout << "Reference Author: " << this->reference_author << endl;
	cout << "Reference Publication year: " << this->publication_year << endl;
}
