#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include"TA.h"

using namespace std;

vector<TA> TAarray(100);
int arraysize, arrayindex = 0;

int main() {

	ifstream inputfile;
	ofstream outputfile;
	inputfile.open("TAs.txt");
	if (!inputfile) {
		cout << "File TAs.txt could not be opened" << endl;
	}
	inputfile >> arraysize;

	for (int idx = 0; idx < arraysize; idx++) {
		string stringinput;
		int intinput;

		inputfile >> intinput;
		TAarray[idx].setStudentId(intinput);

		inputfile >> stringinput;
		TAarray[idx].setFirstName(stringinput);

		inputfile >> stringinput;
		TAarray[idx].setLastName(stringinput);

		inputfile >> stringinput;
		string start = stringinput;
		inputfile >> stringinput;
		TAarray[idx].setHireYear(start + " " + stringinput);


		inputfile >> stringinput;
		TAarray[idx].setClassification(stringinput);

		inputfile >> intinput;
		TAarray[idx].setNumberOfWorkingHours(intinput);

		arrayindex++;

	}

	inputfile.close();

	for (int idx = 0; idx < arraysize; idx++){
		if (TAarray[idx].getClassification() == "Alum"){
			TAarray.erase(TAarray.begin()+idx);
			arrayindex--;
		}
	}

	cout << "=====================================================" << endl;
	cout << "          Welcome to Employee List Modifier" << endl;
	cout << "=====================================================\n" << endl;

	cout << "Enter \"help\" to see all available commands\n" << endl;



	do{
		string stringinput;
		cout << "Enter Command: ";
		cin >> stringinput;

		if (stringinput == "help"){
			cout << "quit: to exit the list modifier program" << endl;
			cout << "add: to add a new TA to the list" << endl;
			cout << "print: to print the eligible TA list" << endl << endl;
		}

		else if (stringinput == "add"){
			if (TAarray[arrayindex].AddnewTA() == 1)
				cout << "New TA successfully added" << endl << endl;
			else
				cout << "Could not add new TA" << endl << endl;
		}

		else if (stringinput == "print"){
			for (int idx = 0; idx < arrayindex; idx++){
				cout << idx+1 << "| Student ID: " << TAarray[idx].getStudentId() << endl;
				cout << idx+1 << "| First Name: " << TAarray[idx].getFirstName() << endl;
				cout << idx+1 << "| Last Name: " << TAarray[idx].getLastName() << endl;
				cout << idx+1 << "| Year Hired: " << TAarray[idx].getHireYear() << endl;
				cout << idx+1 << "| Classification: " << TAarray[idx].getClassification() << endl;
				cout << idx+1 << "| Number of Working Hours: " << TAarray[idx].getNumberOfWorkingHours() << endl << endl;
			}
		}

		else if (stringinput == "quit"){
			cout << "You successfully quit the program" << endl;
			break;
		}

		else
			cout << "Invalid command" << endl << endl;

	}while(true);

	outputfile.open("TAs.txt");
	if (!outputfile)
		cout << "File TAs.txt could not be opened" << endl;
	else{
		outputfile << arrayindex << endl;
		for (int idx = 0; idx < arrayindex; idx++){
			outputfile << TAarray[idx].getStudentId() << " " ;
			outputfile << TAarray[idx].getFirstName() << " " ;
			outputfile << TAarray[idx].getLastName() << " " ;
			outputfile << TAarray[idx].getHireYear() << " " ;
			outputfile << TAarray[idx].getClassification() << " " ;
			outputfile << TAarray[idx].getNumberOfWorkingHours() << endl;
		}
	}

	return 0;
}

