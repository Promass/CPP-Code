#ifndef STUDENT_STAFF_H_
#define STUDENT_STAFF_H_
#include<iostream>
#include<string>
#include"student.h"
#include"staff.h"

using namespace std;

class Student_Staff {

private:

	int student_info_size, staff_info_size;
	Student *array_of_student;
	Staff *array_of_staff;

public:

	//Constructor
	Student_Staff();

	//Member Functions
	void Highest_GPA();
	int N_of_UnderGrad();
	void Same_Hire_Year(int);
	void controller();

};

#endif
