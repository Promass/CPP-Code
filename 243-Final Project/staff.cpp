#include<iostream>
#include<string>
#include<limits>
#include"staff.h"

using namespace std;

//Constructor

Staff::Staff() {
}
;

//Set Functions

void Staff::setEmployeeFirstName(string a) {
	employee_first_name = a;
}

void Staff::setEmployeeLastName(string b) {
	employee_last_name = b;
}

void Staff::setEmployeeId(int c) {
	employee_id = c;
}

void Staff::setEmployeePhoneNumber(string d) {
	employee_phone_number = d;
}

void Staff::setDateOfHiring(int e) {
	date_of_hiring = e;
}

void Staff::setBonusCode(string f) {
	bonus_code = f;
}

void Staff::setCurrentSalary(double g) {
	current_salary = g;
}

//Get Functions

string Staff::getEmployeeFirstName() {
	return employee_first_name;
}

string Staff::getEmployeeLastName() {
	return employee_last_name;
}

int Staff::getEmployeeId() {
	return employee_id;
}

string Staff::getEmployeePhoneNumber() {
	return employee_phone_number;
}

int Staff::getDateOfHiring() {
	return date_of_hiring;
}

string Staff::getBonusCode() {
	return bonus_code;
}

double Staff::getCurrentSalary() {
	return current_salary;
}

//Other Functions

void Staff::Print_Stf_Info(int staffid, Staff *arr, int size) {
	int arrayindex;
	bool idfound = false;

	for (int count = 0; count < size; count++) {
		if (arr[count].getEmployeeId() == staffid) {
			arrayindex = count;
			break;
		}
	}
	while (idfound != true) {

		cout << "\nProgram: The Id number " << staffid
				<< " was not found in the database\n";
		cout << "\nEnter a valid Staff Id number: ";
		cin >> staffid;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\nProgram: Input has to be of type integer" << endl;
			cout << "\nEnter a valid Staff Id number: ";
			cin >> staffid;
		}
		for (int count = 0; count < size; count++) {
			if (arr[count].getEmployeeId() == staffid) {
				arrayindex = count;
				idfound = true;
				break;
			}
		}
	}
	cout << "First Name of the staff: "
			<< arr[arrayindex].getEmployeeFirstName() << endl;
	cout << "Last Name of the staff: " << arr[arrayindex].getEmployeeLastName()
			<< endl;
	cout << "Staff Id: " << arr[arrayindex].getEmployeeId() << endl;
	cout << "Staff phone number: " << arr[arrayindex].getEmployeePhoneNumber()
			<< endl;
	cout << "Hired year of the staff: " << arr[arrayindex].getDateOfHiring()
			<< endl;
	cout << "Bonus Code for the staff: " << arr[arrayindex].getBonusCode()
			<< endl;
	cout << "Current Salary of the Staff: "
			<< arr[arrayindex].getCurrentSalary() << endl << endl;
}

double Staff::Calculate_Salary(int &staffid, Staff *arr, int size) {
	bool idfound = false;
	int arrayindex;
	for (int count = 0; count < size; count++) {
		if (arr[count].getEmployeeId() == staffid) {
			arrayindex = count;
			idfound = true;
			break;
		}
	}
	while (idfound != true) {

		cout << "\nProgram: The Id number " << staffid
				<< " was not found in the database\n";
		cout << "\nEnter a valid Staff Id number: ";
		cin >> staffid;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\nProgram: Input has to be of type integer" << endl;
			cout << "\nEnter a valid Staff Id number: ";
			cin >> staffid;
		}
		for (int count = 0; count < size; count++) {
			if (arr[count].getEmployeeId() == staffid) {
				arrayindex = count;
				idfound = true;
				break;
			}
		}
	}

	if (arr[arrayindex].getBonusCode() == "A") {
		return ((arr[arrayindex].getCurrentSalary()) * 1.08);
	} else if (arr[arrayindex].getBonusCode() == "B") {
		return ((arr[arrayindex].getCurrentSalary()) * 1.06);
	} else if (arr[arrayindex].getBonusCode() == "C") {
		return ((arr[arrayindex].getCurrentSalary()) * 1.03);
	} else if (arr[arrayindex].getBonusCode() == "D") {
		return ((arr[arrayindex].getCurrentSalary()) * 1.01);
	} else if (arr[arrayindex].getBonusCode() == "E") {
		return (arr[arrayindex].getCurrentSalary());
	}
}

string Staff::Compare_Exp(int &staff1, int &staff2, Staff *arr, int size) {
	int stfindex1, stfindex2;
	bool id1found = false, id2found = false;
	for (int count = 0; count < size; count++) {
		if (arr[count].getEmployeeId() == staff1) {
			stfindex1 = count;
			id1found = true;
		}
		if (arr[count].getEmployeeId() == staff2) {
			stfindex2 = count;
			id2found = true;
		}
	}

	while (id1found == false || id2found == false) {

		if (id1found == false) {
			cout << "\nProgram: The Id number " << staff1
					<< " was not found in the database\n";
			cout << "\nEnter a valid Staff Id number for the first Staff: ";
			cin >> staff1;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "\nProgram: Input has to be of type integer" << endl;
				cout << "\nEnter a valid Staff Id number for the first Staff: ";
				cin >> staff1;

			}
			for (int count = 0; count < size; count++) {
				if (arr[count].getEmployeeId() == staff1) {
					stfindex1 = count;
					id1found = true;
					break;
				}
			}
		} else if (id2found == false) {
			cout << "\nProgram: The Id number " << staff2
					<< " was not found in the database\n";
			cout << "\nEnter a valid Staff Id number for the second Staff: ";
			cin >> staff2;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "\nProgram: Input has to be of type integer" << endl;
				cout
						<< "\nEnter a valid Staff Id number for the second Staff: ";
				cin >> staff2;

			}
			for (int count = 0; count < size; count++) {
				if (arr[count].getEmployeeId() == staff2) {
					stfindex2 = count;
					id2found = true;
					break;
				}
			}
		}

	}

	if (arr[stfindex1].getDateOfHiring() > arr[stfindex2].getDateOfHiring())
		return (arr[stfindex2].getEmployeeFirstName() + " "
				+ arr[stfindex2].getEmployeeLastName());
	else if (arr[stfindex1].getDateOfHiring()
			< arr[stfindex2].getDateOfHiring())
		return (arr[stfindex1].getEmployeeFirstName() + " "
				+ arr[stfindex1].getEmployeeLastName());
	else if (arr[stfindex1].getDateOfHiring()
			== arr[stfindex2].getDateOfHiring())
		return "equal";
}
