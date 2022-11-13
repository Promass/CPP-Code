#ifndef TA_H_
#define TA_H_
#include<iostream>
#include<string>

using namespace std;

class TA{

private:
	int Student_Id;
	string First_Name;
	string Last_Name;
	string Hire_Year;
	string Classification;
	int number_of_working_hours;

public:

	TA();
	TA(const TA&);
	~TA();

	void setStudentId(int);
	void setFirstName(string);
	void setLastName(string);
	void setHireYear(string);
	void setClassification(string);
	void setNumberOfWorkingHours(int);

	int getStudentId();
	string getFirstName();
	string getLastName();
	string getHireYear();
	string getClassification();
	int getNumberOfWorkingHours();

	bool AddnewTA();

};

extern vector<TA> TAarray;
extern int arraysize, arrayindex;

#endif /* TA_H_ */
