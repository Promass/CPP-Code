#ifndef CELLPHONE_H_
#define CELLPHONE_H_
#include"electronicdevice.h"

class cellphone: public electronic_device {
public:
	cellphone();
	cellphone(string, int, string, double, int);
	virtual ~cellphone();
	cellphone(const cellphone &other);

	void setNumberOfCameras(int);

	int getNumberOfCameras();

	void print();
private:
	int number_of_cameras;
};

#endif /* CELLPHONE_H_ */
