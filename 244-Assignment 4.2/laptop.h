#ifndef LAPTOP_H_
#define LAPTOP_H_
#include"electronicdevice.h"

class laptop: public electronic_device {
public:
	laptop();
	laptop(string, int, string, double, int, bool);
	virtual ~laptop();
	laptop(const laptop &other);

	void setNumberOfCores(int);
	void setTouchscreen(bool);

	int getNumberOfCores();
	bool getTouchscreen();

	void print();
private:
	int number_of_cores;
	bool touchscreen;
};

#endif /* LAPTOP_H_ */
