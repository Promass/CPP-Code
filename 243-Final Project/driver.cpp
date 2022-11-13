#include<iostream>
#include<string>
#include<limits>
#include"student_staff.h"

using namespace std;

int main() {

	cout << "-------------------------------------------------------------"
			<< endl;
	cout << "          Welcome to Student_Staff class Management" << endl;
	cout << "-------------------------------------------------------------"
			<< endl;

	Student_Staff studentstaffclass;
	string command;
	int intinput;

	cout << "Program: Enter \"Help\" to see the list of Management commands\n"
			<< endl;

	do {

		try {

			cout << "Management Command: ";
			cin >> command;

			if (command == "Exit_Management") {
				cout
						<< "\n-------------------------------------------------------------"
						<< endl;
				cout
						<< "  You exit Student_Staff class Management. Have a nice day!"
						<< endl;
				cout
						<< "-------------------------------------------------------------\n"
						<< endl;
				break;
			} else if (command == "Help") {
				cout
						<< "\n1. Exit_Management: Exit the student_staff class management program\n"
								"2. Highest_GPA: Prints the information of the student with highest GPA\n"
								"3. N_of_UnderGrad: Prints the total number of student in the Bachelors program\n"
								"4. Same_Hire_Year: Prints the information of all staff member that were hired in the given year\n"
								"5. Sub_Management: Gives control over student and staff class (to test their member functions)\n"
						<< endl;
			} else if (command == "Highest_GPA") {
				cout << endl;
				studentstaffclass.Highest_GPA();
			} else if (command == "N_of_UnderGrad") {
				cout << "\nNumber of undergraduates: "
						<< studentstaffclass.N_of_UnderGrad() << endl << endl;
			} else if (command == "Same_Hire_Year") {
				cout << "\nEnter the year when the employees were hired: ";

				cin >> intinput;
				while (cin.fail()) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(),
							'\n');
					cout << "\nProgram: Input has to be of type integer"
							<< endl;
					cout << "\nEnter the year when the employees were hired: ";
					cin >> intinput;
				}
				if (intinput < 0 || intinput > 9999)
					throw -2;
				else
					studentstaffclass.Same_Hire_Year(intinput);
			} else if (command == "Sub_Management") {
				studentstaffclass.controller();
			} else {
				throw -1;
			}
		}

		catch (int i) {
			if (i == -1)
				cout
						<< "\nProgram: Commands are case sensitive. Please enter a valid command\n"
						<< endl;
			else if (i == -2)
				cout << "\nProgram: Entered year was not valid\n" << endl;
		}

	} while (command != "Exit_Management");

	return 0;

}
