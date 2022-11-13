#ifndef SMARTWATCH_H_
#define SMARTWATCH_H_
#include"electronicdevice.h"

class smartwatch: public electronic_device {
public:
	smartwatch();
	smartwatch(string, int, string, double, int);
	virtual ~smartwatch();
	smartwatch(const smartwatch &other);

	void setBatteryLife(int);

	int getBatteryLife();

	void print();
private:
	int battery_life;
};

#endif /* SMARTWATCH_H_ */
