#ifndef STUDENT_H_
#define STUDENT_H_
#include<iostream>
#include<string>
using namespace std;

class Student {

private:

	string student_first_name;
	string student_last_name;
	int student_id;
	string date_of_birth;
	double current_gpa;
	int start_year;
	double completed_credit;
	string program;

public:

	//Constructor
	Student();

	//Set functions
	void setStudentFirstName(string);
	void setStudentLastName(string);
	void setStudentId(int);
	void setDateOfBirth(string);
	void setCurrentGPA(double);
	void setStartYear(int);
	void setCompletedCredit(double);
	void setProgram(string);

	//Get functions
	string getStudentFirstName();
	string getStudentLastName();
	int getStudentId();
	string getDateOfBirth();
	double getCurrentGPA();
	int getStartYear();
	int getCompletedCredit();
	string getProgram();

	//Other functions
	bool CompleteProgram(int&, Student*, int);
	string StudentStatus(double);
	void Print_Std_Info(int, Student*, int);
	int Compare_GPA(int&, int&, Student*, int);

};

#endif
