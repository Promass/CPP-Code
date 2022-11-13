#include<iostream>
#include<string>
#include<limits>
#include<vector>
#include"TA.h"

using namespace std;

bool inttest(int test) {
	if (sizeof(test) == 4)
		return true;
	else
		return false;
}

TA::TA() {
}

TA::TA(const TA &other) {
	this->Student_Id = other.Student_Id;
	this->First_Name = other.First_Name;
	this->Last_Name = other.Last_Name;
	this->Hire_Year = other.Hire_Year;
	this->Classification = other.Classification;
	this->number_of_working_hours = other.number_of_working_hours;
}

TA::~TA() {
}

void TA::setStudentId(int a) {
	Student_Id = a;
}
void TA::setFirstName(string b) {
	First_Name = b;
}
void TA::setLastName(string c) {
	Last_Name = c;
}
void TA::setHireYear(string d) {
	Hire_Year = d;
}
void TA::setClassification(string e) {
	Classification = e;
}
void TA::setNumberOfWorkingHours(int f) {
	number_of_working_hours = f;
}

int TA::getStudentId() {
	return Student_Id;
}
string TA::getFirstName() {
	return First_Name;
}
string TA::getLastName() {
	return Last_Name;
}
string TA::getHireYear() {
	return Hire_Year;
}
string TA::getClassification() {
	return Classification;
}
int TA::getNumberOfWorkingHours() {
	return number_of_working_hours;
}

bool TA::AddnewTA() {

	int intinput;
	string stringinput;

	cout << "Enter the Id number of the TA: ";
	cin >> intinput;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\nInput has to be of type integer" << endl;
		cout << "\nEnter the Id number of the TA: ";
		cin >> intinput;
	}

	for (int idx = 0; idx < arrayindex; idx++) {
		if (TAarray[idx].getStudentId() == intinput) {
			cout << "This Id number already exist" << endl;
			return false;
		}
	}
	TAarray[arrayindex].setStudentId(intinput);

	cout << "Enter the First Name of the TA: ";
	cin >> stringinput;
	TAarray[arrayindex].setFirstName(stringinput);

	cout << "Enter the Last Name of the TA: ";
	cin >> stringinput;
	TAarray[arrayindex].setLastName(stringinput);

	cout << "Enter his Hire Year (Start year followed by the End year): ";
	cin >> stringinput;
	string start = stringinput;
	cin >> stringinput;
	TAarray[arrayindex].setHireYear(start + " " + stringinput);

	cout << "Enter his Classification (Grad): ";
	cin >> stringinput;
	TAarray[arrayindex].setClassification(stringinput);

	cout << "Enter his number of Working Hours: ";
	cin >> intinput;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\nInput has to be of type integer" << endl;
		cout << "\nEnter his number of Working Hours: ";
		cin >> intinput;
	}
	TAarray[arrayindex].setNumberOfWorkingHours(intinput);

	cout << endl;

	arrayindex++;

	return true;

}
