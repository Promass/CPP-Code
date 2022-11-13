#include<iostream>
#include "electronicdevice.h"

using namespace std;

electronic_device::electronic_device() {}

electronic_device::electronic_device(string a, int b, string c, double d) {
	brand = a;
	serial_number = b;
	color = c;
	price = d;
}

electronic_device::~electronic_device() {}

electronic_device::electronic_device(const electronic_device &other) {
	this->brand = other.brand;
	this->serial_number = other.serial_number;
	this->color = other.color;
	this->price = other.price;
}

void electronic_device::setBrand(string a){
	this->brand = a;
}


void electronic_device::setSerialNumber(int b){
	this->serial_number = b;
}

void electronic_device::setColor(string c){
	this->color = c;
}

void electronic_device::setPrice(double d){
	this->price = d;
}

string electronic_device::getBrand(){
	return brand;
}

int electronic_device::getSerialNumber(){
	return serial_number;
}

string electronic_device::getColor(){
	return color;
}
double electronic_device::getPrice(){
	return price;
}

void electronic_device::print(){
	cout << "Brand: " << brand;
	cout << "Serial Number: " << serial_number;
	cout << "Color: " << color;
	cout << "Price: " << price;
}
