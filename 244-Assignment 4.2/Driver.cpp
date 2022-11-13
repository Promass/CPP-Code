#include<iostream>
#include<array>
#include"electronicdevice.h"
#include"cellphone.h"
#include"smartwatch.h"
#include"laptop.h"
#include<fstream>
#include<string>
#include<typeinfo> //Using typeinfo to verify the class of each object

using namespace std;

int func(electronic_device *a) {
	if (a != nullptr) {

		const std::type_info &type_info = typeid(*a); // typeid on reference to a polymorphic type

		if (type_info == typeid(cellphone))
			return 1;
		else if (type_info == typeid(laptop))
			return 2;
		else if (type_info == typeid(smartwatch))
			return 3;
		else
			return 0;
	}
}

int main() {

	int size = 6;
	electronic_device **basearray = new electronic_device*[size];

	cellphone cell("Apple", 110002, "blue", 1000, 3);
	laptop lap("Dell", 22342, "black", 800.5, 5, 0);
	smartwatch smart("Samsung", 123456, "gray", 600, 24);
	laptop top("Lenovo", 23345, "black", 1000, 7, 1);
	smartwatch watch("Apple", 2324395, "gray", 800, 36);
	cellphone phone("LG", 345522, "silver", 650, 1);

	basearray[0] = &cell;
	basearray[1] = &lap;
	basearray[2] = &smart;
	basearray[3] = &top;
	basearray[4] = &watch;
	basearray[5] = &phone;

	string file = "information.txt";
	ofstream outputfile;
	outputfile.open(file);

	if (!outputfile) {
		cout << "File " << file << " could not be opened" << endl;
		exit(1);
	}

	for (int idx = 0; idx < size; idx++) {
		if (func(basearray[idx]) == 1) {
			outputfile << "cellphone ";
			outputfile << static_cast<cellphone*>(basearray[idx])->getBrand() << " ";
			outputfile << static_cast<cellphone*>(basearray[idx])->getSerialNumber() << " ";
			outputfile << static_cast<cellphone*>(basearray[idx])->getColor() << " ";
			outputfile << static_cast<cellphone*>(basearray[idx])->getPrice() << " ";
			outputfile << static_cast<cellphone*>(basearray[idx])->getNumberOfCameras() << endl; //Using type casting to get access to derive class attributes

		} else if (func(basearray[idx]) == 2) {
			outputfile << "laptop ";
			outputfile << static_cast<laptop*>(basearray[idx])->getBrand() << " ";
			outputfile << static_cast<laptop*>(basearray[idx])->getSerialNumber() << " ";
			outputfile << static_cast<laptop*>(basearray[idx])->getColor() << " ";
			outputfile << static_cast<laptop*>(basearray[idx])->getPrice() << " ";
			outputfile << static_cast<laptop*>(basearray[idx])->getNumberOfCores() << " ";
			outputfile << static_cast<laptop*>(basearray[idx])->getTouchscreen() << endl; //Using type casting to get access to derive class attributes

		} else if (func(basearray[idx]) == 3) {
			outputfile << "smartwatch ";
			outputfile << static_cast<smartwatch*>(basearray[idx])->getBrand() << " ";
			outputfile << static_cast<smartwatch*>(basearray[idx])->getSerialNumber() << " ";
			outputfile << static_cast<smartwatch*>(basearray[idx])->getColor() << " ";
			outputfile << static_cast<smartwatch*>(basearray[idx])->getPrice() << " ";
			outputfile << static_cast<smartwatch*>(basearray[idx])->getBatteryLife() << endl; //Using type casting to get access to derive class attributes

		}

	}

	outputfile.close();

}
