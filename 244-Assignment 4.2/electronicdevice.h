#ifndef ELECTRONICDEVICE_H_
#define ELECTRONICDEVICE_H_
#include<string>

using namespace std;

class electronic_device {
public:
	electronic_device();
	electronic_device(string, int, string, double);
	virtual ~electronic_device();
	electronic_device(const electronic_device &other);

	virtual void print();

	void setBrand(string);
	void setSerialNumber(int);
	void setColor(string);
	void setPrice(double);

	string getBrand();
	int getSerialNumber();
	string getColor();
	double getPrice();

private:
	string brand;
	int serial_number;
	string color;
	double price;

};

#endif /* ELECTRONICDEVICE_H_ */
