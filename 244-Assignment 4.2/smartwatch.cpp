#include<iostream>
#include "smartwatch.h"

using namespace std;

smartwatch::smartwatch() {}

smartwatch::smartwatch(string a, int b, string c, double d, int e): electronic_device(a,b,c,d) {
	battery_life = e;
}

smartwatch::~smartwatch() {}

smartwatch::smartwatch(const smartwatch &other) : electronic_device(other) {
	this->battery_life = other.battery_life;
}

void smartwatch::setBatteryLife(int a){
	this->battery_life = a;
}

int smartwatch::getBatteryLife(){
	return battery_life;
}

void smartwatch::print(){
	cout << "Brand: " << this->getBrand();
	cout << "Serial Number: " << this->getSerialNumber();
	cout << "Color: " << this->getColor();
	cout << "Price: " << this->getPrice();
	cout << "Battery Life: " << battery_life << endl;
}
