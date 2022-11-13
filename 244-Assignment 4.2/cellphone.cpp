#include<iostream>
#include "cellphone.h"

using namespace std;

cellphone::cellphone() {}

cellphone::cellphone(string a, int b, string c, double d, int e): electronic_device(a,b,c,d){
	number_of_cameras = e;
}

cellphone::~cellphone() {}

cellphone::cellphone(const cellphone &other) : electronic_device(other) {
	number_of_cameras = other.number_of_cameras;
}

void cellphone::setNumberOfCameras(int a){
	this->number_of_cameras = a;
}

int cellphone::getNumberOfCameras(){
	return number_of_cameras;
}

void cellphone::print(){
	cout << "Brand: " << this->getBrand();
	cout << "Serial Number: " << this->getSerialNumber();
	cout << "Color: " << this->getColor();
	cout << "Price: " << this->getPrice();
	cout << "Number Of Cameras: " << number_of_cameras;
}
