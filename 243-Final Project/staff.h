#ifndef STAFF_H_
#define STAFF_H_
#include<iostream>
#include<string>

using namespace std;

class Staff {

private:

	string employee_first_name;
	string employee_last_name;
	int employee_id;
	string employee_phone_number;
	int date_of_hiring;
	string bonus_code;
	double current_salary;

public:

	//Constructor
	Staff();

	//Set functions
	void setEmployeeFirstName(string);
	void setEmployeeLastName(string);
	void setEmployeeId(int);
	void setEmployeePhoneNumber(string);
	void setDateOfHiring(int);
	void setBonusCode(string);
	void setCurrentSalary(double);

	//Get functions
	string getEmployeeFirstName();
	string getEmployeeLastName();
	int getEmployeeId();
	string getEmployeePhoneNumber();
	int getDateOfHiring();
	string getBonusCode();
	double getCurrentSalary();

	//Other functions
	void Print_Stf_Info(int, Staff*, int);
	double Calculate_Salary(int&, Staff*, int);
	string Compare_Exp(int&, int&, Staff*, int);

};

#endif
