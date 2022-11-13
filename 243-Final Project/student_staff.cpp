#include<iostream>
#include<string>
#include<fstream>
#include<limits>
#include"student_staff.h"

using namespace std;

//Constructor

Student_Staff::Student_Staff() {

	ifstream studentinput;
	ifstream staffinput;
	studentinput.open("student_info.txt");
	staffinput.open("staff_info.txt");

	if (!studentinput) {
		cout << "Student information file could not be opened" << endl;
	}
	if (!staffinput) {
		cout << "Staff information file could not be opened" << endl;
	} else {
		int intinput, studentcounter = 0, staffcounter = 0;
		double doubleinput;
		string stringinput;

		studentinput >> intinput;
		student_info_size = intinput / 8;
		array_of_student = new Student[student_info_size];

		do {
			//set First Name
			studentinput >> stringinput;
			array_of_student[studentcounter].setStudentFirstName(stringinput);

			//Set Last Name
			studentinput >> stringinput;
			array_of_student[studentcounter].setStudentLastName(stringinput);

			//Set Student Id
			studentinput >> intinput;
			array_of_student[studentcounter].setStudentId(intinput);

			//Set Birth Date
			studentinput >> stringinput;
			array_of_student[studentcounter].setDateOfBirth(stringinput);

			//Set GPA
			studentinput >> doubleinput;
			array_of_student[studentcounter].setCurrentGPA(doubleinput);

			//Set Start Year
			studentinput >> intinput;
			array_of_student[studentcounter].setStartYear(intinput);

			//Set Completed Credit
			studentinput >> intinput;
			array_of_student[studentcounter].setCompletedCredit(intinput);

			//Set Program
			studentinput >> stringinput;
			array_of_student[studentcounter].setProgram(stringinput);

			studentcounter++;

		} while (!studentinput.eof());

		studentinput.close();

		staffinput >> intinput;
		staff_info_size = intinput / 7;
		array_of_staff = new Staff[staff_info_size];

		do {
			//Set First Name
			staffinput >> stringinput;
			array_of_staff[staffcounter].setEmployeeFirstName(stringinput);

			//Set Last Name
			staffinput >> stringinput;
			array_of_staff[staffcounter].setEmployeeLastName(stringinput);

			//Set Employee ID
			staffinput >> intinput;
			array_of_staff[staffcounter].setEmployeeId(intinput);

			//Set Employee Phone Number
			staffinput >> stringinput;
			array_of_staff[staffcounter].setEmployeePhoneNumber(stringinput);

			//Set Hired Year
			staffinput >> intinput;
			array_of_staff[staffcounter].setDateOfHiring(intinput);

			//Set Bonus Code
			staffinput >> stringinput;
			array_of_staff[staffcounter].setBonusCode(stringinput);

			//Set Current Salary
			staffinput >> intinput;
			array_of_staff[staffcounter].setCurrentSalary(intinput);

			staffcounter++;

		} while (!staffinput.eof());

		staffinput.close();

		cout << "\nProgram: Successfully imported " << studentcounter
				<< " student(s) from student_info.txt" << endl;
		cout << "Program: Successfully imported " << staffcounter
				<< " staff(s) from staff_info.txt" << endl;
	}
}

//Member Functions

void Student_Staff::Highest_GPA() { //Note that this function does not take into account "eqaul number of highest GPA" (first come first serve). If another student has same GPA, he will be ignored.
	double highestGPA = 0.0;
	int studentid;
	for (int count = 0; count < student_info_size; count++) {
		if (array_of_student[count].getCurrentGPA() > highestGPA) {
			highestGPA = array_of_student[count].getCurrentGPA();
		}
	}
	for (int count = 0; count < student_info_size; count++) {
		if (array_of_student[count].getCurrentGPA() == highestGPA) {
			studentid = array_of_student[count].getStudentId();
			break;
		}
	}
	array_of_student[0].Print_Std_Info(studentid, array_of_student,
			student_info_size);
}

int Student_Staff::N_of_UnderGrad() {
	int undergradcounter = 0;
	for (int count = 0; count < student_info_size; count++) {
		if (array_of_student[count].getProgram() == "B")
			undergradcounter++;
	}
	return undergradcounter;
}

void Student_Staff::Same_Hire_Year(int hiringyear) {
	bool hired = false;
	bool morethanone = false;
	for (int count = 0; count < staff_info_size; count++) {
		if (array_of_staff[count].getDateOfHiring() == hiringyear) {
			if (morethanone == true) {
				cout << "and ";
				cout << array_of_staff[count].getEmployeeFirstName() << " "
						<< array_of_staff[count].getEmployeeLastName() << " ";
				hired = false;
				continue;
			}
			cout << array_of_staff[count].getEmployeeFirstName() << " "
					<< array_of_staff[count].getEmployeeLastName() << " ";
			morethanone = true;
			hired = true;
		}
	}
	if (hired == true && morethanone == true)
		cout << "was hired in the year " << hiringyear << endl << endl;
	else if (hired == false && morethanone == true)
		cout << "were hired in the year " << hiringyear << endl << endl;
	else
		cout << "No one was hired in the year " << hiringyear << endl << endl;
}

void Student_Staff::controller() {

	cout << "\n-------------------------------------------------------------"
			<< endl;
	cout << "      Welcome to Student and Staff class Sub-Management" << endl;
	cout << "-------------------------------------------------------------"
			<< endl;
	cout
			<< "\nProgram: Enter \"Help\" to see the list of Sub-Management commands\n"
			<< endl;

	string stringinput;
	int intinput;
	double doubleinput;

	do {

		try {

			cout << "Sub-Management Command: ";
			cin >> stringinput;

			if (stringinput == "Exit_Sub_Management") {
				cout
						<< "\n-------------------------------------------------------------"
						<< endl;
				cout << "       You exit Student and Staff class Sub-Management"
						<< endl;
				cout
						<< "-------------------------------------------------------------\n"
						<< endl;
				break;
			} else if (stringinput == "Help") {
				cout
						<< "\n1. Exit_Sub_Management: Exits the Sub-Management control and goes back to Management control\n"
								"2. Complete_Program: Checks if a given student has completed all the credits required for his/her specific program\n"
								"3. Student_Status: Gives the letter grade associated with the given GPA\n"
								"4. Print_Std_Info: Prints all the information of a given student\n"
								"5. Compare_GPA: Compares the GPA of two given students\n"
								"6. Print_Stf_Info: Prints all the information of a given staff\n"
								"7. Calculate_Salary: Calculates the new year salary based on the bonus code of a given staff\n"
								"8. Compare_Exp: Compares the total years of work experience between two given staff and give the name of the more experienced staff\n"
						<< endl;
			} else if (stringinput == "Complete_Program") {
				cout << "\nEnter the Id number of the student: ";
				cin >> intinput;

				while (cin.fail()) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(),
							'\n');
					cout << "\nProgram: Input has to be of type integer"
							<< endl;
					cout << "\nEnter the Id number of the student: ";
					cin >> intinput;
				}

				if (array_of_student[0].CompleteProgram(intinput,
						array_of_student, student_info_size) == true) {
					cout << "The student with Id number " << intinput
							<< " completed all required credits for his/her program"
							<< endl << endl;
				} else
					cout << "The student with Id number " << intinput
							<< " did not complete all required credits for his/her program"
							<< endl << endl;
			} else if (stringinput == "Student_Status") {
				cout << "\nEnter the GPA of the student: ";
				cin >> doubleinput;
				while (cin.fail()) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(),
							'\n');
					cout << "\nProgram: Input has to be of type integer/float"
							<< endl;
					cout << "\nEnter the GPA of the student: ";
					cin >> doubleinput;
				}
				cout << "The student with GPA " << doubleinput
						<< " has a letter grade: "
						<< array_of_student[0].StudentStatus(doubleinput)
						<< endl << endl;
			} else if (stringinput == "Print_Std_Info") {
				cout
						<< "\nEnter the Id number of the student to print his/her information: ";
				cin >> intinput;
				while (cin.fail()) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(),
							'\n');
					cout << "\nProgram: Input has to be of type integer"
							<< endl;
					cout
							<< "\nEnter the Id number of the student to print his/her information: ";
					cin >> intinput;
				}
				array_of_student[0].Print_Std_Info(intinput, array_of_student,
						student_info_size);
			} else if (stringinput == "Compare_GPA") {
				int stdone, stdtwo;
				cout << "\nEnter the Id number of the first student: ";
				cin >> intinput;
				while (cin.fail()) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(),
							'\n');
					cout << "\nProgram: Input has to be of type integer"
							<< endl;
					cout << "\nEnter the Id number of the first student: ";
					cin >> intinput;
				}
				stdone = intinput;
				cout << "Enter the Id number of the second student: ";
				cin >> intinput;
				while (cin.fail()) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(),
							'\n');
					cout << "\nProgram: Input has to be of type integer"
							<< endl;
					cout << "\nEnter the Id number of the second student: ";
					cin >> intinput;
				}
				stdtwo = intinput;
				if (array_of_student[0].Compare_GPA(stdone, stdtwo,
						array_of_student, student_info_size) == 0)
					cout << "Both students have the same GPA" << endl << endl;
				else
					cout << "The student with Id number "
							<< array_of_student[0].Compare_GPA(stdone, stdtwo,
									array_of_student, student_info_size)
							<< " has a greater_GPA" << endl << endl;
			} else if (stringinput == "Print_Stf_Info") {
				cout
						<< "\nEnter the Id number of the staff to print his/her information: ";
				cin >> intinput;
				while (cin.fail()) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(),
							'\n');
					cout << "\nProgram: Input has to be of type integer"
							<< endl;
					cout
							<< "\nEnter the Id number of the staff to print his/her information: ";
					cin >> intinput;
				}
				array_of_staff[1].Print_Stf_Info(intinput, array_of_staff,
						staff_info_size);
			} else if (stringinput == "Calculate_Salary") {
				double newsalary;
				cout
						<< "\nEnter the Id number of the staff for bonus salary calculation: ";
				cin >> intinput;
				while (cin.fail()) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(),
							'\n');
					cout << "\nProgram: Input has to be of type integer"
							<< endl;
					cout
							<< "\nEnter the Id number of the staff for bonus salary calculation: ";
					cin >> intinput;
				}
				newsalary = array_of_staff[0].Calculate_Salary(intinput,
						array_of_staff, staff_info_size);
				cout
						<< "The new year salary based on the bonus code of staff with Id number "
						<< intinput << " is " << newsalary << endl << endl;
			} else if (stringinput == "Compare_Exp") {
				int stfone, stftwo;
				cout << "\nEnter the Id number of the first staff: ";
				cin >> intinput;
				while (cin.fail()) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(),
							'\n');
					cout << "\nProgram: Input has to be of type integer"
							<< endl;
					cout << "\nEnter the Id number of the first staff: ";
					cin >> intinput;
				}
				stfone = intinput;
				cout << "Enter the Id number of the second staff: ";
				cin >> intinput;
				while (cin.fail()) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(),
							'\n');
					cout << "\nProgram: Input has to be of type integer"
							<< endl;
					cout << "\nEnter the Id number of the second staff: ";
					cin >> intinput;
				}
				stftwo = intinput;
				if (array_of_staff[0].Compare_Exp(stfone, stftwo,
						array_of_staff, staff_info_size) == "equal") {
					cout << "They both have same work experience" << endl
							<< endl;
				} else
					cout
							<< array_of_staff[0].Compare_Exp(stfone, stftwo,
									array_of_staff, staff_info_size)
							<< " has more work experience" << endl << endl;
			} else
				throw -1;
		} catch (int i) {
			cout
					<< "\nProgram: Commands are case sensitive. Please enter a valid command\n"
					<< endl;
		}

	} while (stringinput != "Exit_Sub_Management");

}
