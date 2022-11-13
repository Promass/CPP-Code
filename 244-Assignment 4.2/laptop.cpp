#include<iostream>
#include "laptop.h"

using namespace std;

laptop::laptop() {}

laptop::laptop(string a, int b, string c, double d, int e, bool f): electronic_device(a,b,c,d){
	number_of_cores = e;
	touchscreen = f;
}

laptop::~laptop() {}

laptop::laptop(const laptop &other) : electronic_device(other) {
	this->number_of_cores = other.number_of_cores;
	this->touchscreen = other.touchscreen;
}

void laptop::setNumberOfCores(int a){
	this->number_of_cores = a;
}

void laptop::setTouchscreen(bool b){
	this->touchscreen = b;
}

int laptop::getNumberOfCores(){
	return number_of_cores;
}

bool laptop::getTouchscreen(){
	return touchscreen;
}

void laptop::print(){
	cout << "Brand: " << this->getBrand();
	cout << "Serial Number: " << this->getSerialNumber();
	cout << "Color: " << this->getColor();
	cout << "Price: " << this->getPrice();
	cout << "Number Of Cores: " << number_of_cores;
	if (touchscreen == true)
		cout << "Touch Screen: Yes";
	else
		cout << "Touch Screen: No";
	cout << endl;
}
