#include<iostream>
#include<string>
#include<limits>
#include"student.h"

using namespace std;

//Constructor

Student::Student() {
}

//Set functions

void Student::setStudentFirstName(string a) {
	student_first_name = a;
}

void Student::setStudentLastName(string b) {
	student_last_name = b;
}

void Student::setStudentId(int c) {
	student_id = c;
}

void Student::setDateOfBirth(string d) {
	date_of_birth = d;
}

void Student::setCurrentGPA(double e) {
	current_gpa = e;
}

void Student::setStartYear(int f) {
	start_year = f;
}

void Student::setCompletedCredit(double g) {
	completed_credit = g;
}

void Student::setProgram(string h) {
	program = h;
}

//Get functions

string Student::getStudentFirstName() {
	return student_first_name;
}

string Student::getStudentLastName() {
	return student_last_name;
}

int Student::getStudentId() {
	return student_id;
}

string Student::getDateOfBirth() {
	return date_of_birth;
}

double Student::getCurrentGPA() {
	return current_gpa;
}

int Student::getStartYear() {
	return start_year;
}

int Student::getCompletedCredit() {
	return completed_credit;
}

string Student::getProgram() {
	return program;
}

//Other functions

bool Student::CompleteProgram(int &studentid, Student *arr, int size) {
	int arrayindex;
	bool trueorfalse = false, idfound = false;
	for (int count = 0; count < size; count++) {
		if (arr[count].getStudentId() == studentid) {
			arrayindex = count;
			idfound = true;
			break;
		}
	}
	while (idfound == false) {
		cout << "\nProgram: The Id number " << studentid
				<< " was not found in the database\n";
		cout << "\nEnter a valid Student Id number: ";
		cin >> studentid;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\nProgram: Input has to be of type integer" << endl;
			cout << "\nEnter a valid Student Id number: ";
			cin >> studentid;
		}
		for (int count = 0; count < size; count++) {
			if (arr[count].getStudentId() == studentid) {
				arrayindex = count;
				idfound = true;
				break;
			}
		}
	}
	if (arr[arrayindex].getProgram() == "B") {
		if (arr[arrayindex].getCompletedCredit() == 140)
			trueorfalse = true;
	} else if (arr[arrayindex].getProgram() == "M") {
		if (arr[arrayindex].getCompletedCredit() == 16)
			trueorfalse = true;
	} else if (arr[arrayindex].getProgram() == "P") {
		if (arr[arrayindex].getCompletedCredit() == 12)
			trueorfalse = true;
	}
	return trueorfalse;
}

string Student::StudentStatus(double k) {
	if (k >= 3.5)
		return "A+";
	else if (k >= 3.0 && k < 3.5)
		return "A";
	else if (k >= 2.5 && k < 3.0)
		return "B";
	else if (k >= 2.0 && k < 2.5)
		return "C";
	else if (k < 2)
		return "D";
	else
		return "Invalid GPA";
}

void Student::Print_Std_Info(int studentid, Student *arr, int size) {
	bool idfound = false;
	int arrayindex;

	for (int count = 0; count < size; count++) {
		if (arr[count].getStudentId() == studentid) {
			arrayindex = count;
			idfound = true;
			break;
		}
	}
	while (idfound != true) {

		cout << "\nProgram: The Id number " << studentid
				<< " was not found in the database\n";
		cout << "\nEnter a valid Student Id number: ";
		cin >> studentid;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\nProgram: Input has to be of type integer" << endl;
			cout << "\nEnter a valid Student Id number: ";
			cin >> studentid;
		}
		for (int count = 0; count < size; count++) {
			if (arr[count].getStudentId() == studentid) {
				arrayindex = count;
				idfound = true;
				break;
			}
		}
	}

	cout << "First Name of the student: "
			<< arr[arrayindex].getStudentFirstName() << endl;
	cout << "Last Name of the student: " << arr[arrayindex].getStudentLastName()
			<< endl;
	cout << "Student Id: " << arr[arrayindex].getStudentId() << endl;
	cout << "Student date of birth: " << arr[arrayindex].getDateOfBirth()
			<< endl;
	cout << "Current GPA of student: " << arr[arrayindex].getCurrentGPA()
			<< endl;
	cout << "Start year of student: " << arr[arrayindex].getStartYear() << endl;
	cout << "Completed credit(s): " << arr[arrayindex].getCompletedCredit()
			<< endl;
	cout << "Program: " << arr[arrayindex].getProgram() << endl << endl;
}

int Student::Compare_GPA(int &m, int &n, Student *arr, int size) {
	int stdindex1, stdindex2;
	bool id1found = false, id2found = false;
	for (int count = 0; count < size; count++) {
		if (arr[count].getStudentId() == m) {
			id1found = true;
			stdindex1 = count;
		}
		if (arr[count].getStudentId() == n) {
			stdindex2 = count;
			id2found = true;
		}
	}

	while (id1found == false || id2found == false) {

		if (id1found == false) {
			cout << "\nProgram: The Id number " << m
					<< " was not found in the database\n";
			cout << "\nEnter a valid Student Id number for the first student: ";
			cin >> m;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "\nProgram: Input has to be of type integer" << endl;
				cout
						<< "\nEnter a valid Student Id number for the first student: ";
				cin >> m;

			}
			for (int count = 0; count < size; count++) {
				if (arr[count].getStudentId() == m) {
					stdindex1 = count;
					id1found = true;
					break;
				}
			}
		} else if (id2found == false) {
			cout << "\nProgram: The Id number " << n
					<< " was not found in the database\n";
			cout
					<< "\nEnter a valid Student Id number for the second student: ";
			cin >> n;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "\nProgram: Input has to be of type integer" << endl;
				cout
						<< "\nEnter a valid Student Id number for the second student: ";
				cin >> n;

			}
			for (int count = 0; count < size; count++) {
				if (arr[count].getStudentId() == n) {
					stdindex2 = count;
					id2found = true;
					break;
				}
			}
		}

	}

	if (arr[stdindex1].getCurrentGPA() > arr[stdindex2].getCurrentGPA())
		return m;
	else if (arr[stdindex1].getCurrentGPA() < arr[stdindex2].getCurrentGPA())
		return n;
	else if (arr[stdindex1].getCurrentGPA() == arr[stdindex2].getCurrentGPA())
		return 0;
}
