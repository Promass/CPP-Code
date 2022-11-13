#ifndef IMAGE_H_
#define IMAGE_H_
#include<string>
#include<vector>

class Image {
public:
	Image();
	virtual ~Image();

	bool addImage(std::string);
	bool outputImage(std::string);

	short getPixelValue(unsigned int, unsigned int);
	void setPixelValue(unsigned int, unsigned int, short);

	bool operator==(const Image&) const;

private:
	unsigned int rows;
	unsigned int cols;
	short pixel_max;
	std::string format;
	std::string name;
	std::vector<short> pixel_value;
};

#endif
