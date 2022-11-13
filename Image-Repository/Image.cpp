#include "Image.h"
#include<fstream>
#include<iostream>

Image::Image(){}

Image::~Image() {}

bool Image::addImage(std::string file) {
	std::ifstream imageinput;
	imageinput.open(file);
	if (!imageinput) {
		std::cout << "File could not be opened" << std::endl;
		return false;
	}
	std::cin.clear();
	getline(imageinput, this->format);
	if (format != "P2") {
		std::cout << "Invalid Image Format" << std::endl;
		return false;
	}

	getline(imageinput, this->name);

	imageinput >> this->cols;
	imageinput >> this->rows;
	pixel_value.resize(cols * rows);
	imageinput >> pixel_max;

	for (unsigned int idx = 0; idx < cols * rows; idx++) {
		imageinput >> pixel_value[idx];
	}
	imageinput.close();
	return true;
}

short Image::getPixelValue(unsigned int r, unsigned int c) {
	if ((this->rows * this->cols) < (r * c)) {
		std::cout << "The image does not include the given index" << std::endl;
		return 0;
	} else if (r * c <= 0) {
		std::cout << "Negative Index cannot be accepted" << std::endl;
		return 0;
	} else
		return (pixel_value[(r - 1) * (c - 1)]);
}
void Image::setPixelValue(unsigned int r, unsigned int c, short value) {
	if (r * c > rows * cols) {
		std::cout << "The image does not include the given index" << std::endl;
	} else if (r * c <= 0) {
		std::cout << "Negative Index cannot be accepted" << std::endl;
	} else {
		pixel_value[(r - 1) * (c - 1)] = value;
		std::cout << "Successfully modified pixel value" << std::endl;
	}
}

bool Image::outputImage(std::string file) {
	std::ofstream imageoutput;
	imageoutput.open(file);
	if (!imageoutput) {
		std::cout << "File could not be opened" << std::endl;
		return false;
	}
	imageoutput << this->format << std::endl;
	imageoutput << this->name << std::endl;
	imageoutput << this->cols << " " << this->rows << std::endl;
	imageoutput << this->pixel_max << std::endl;

	for (unsigned int idx = 0; idx < rows * cols; idx++) {
		if ((idx + 1) % 70 == 0)
			imageoutput << std::endl;
		imageoutput << pixel_value[idx] << " ";
	}
	imageoutput.close();
	return true;
}

bool Image::operator ==(const Image &other) const {
	if (cols != other.cols || rows != other.rows)
		return false;
	for (unsigned int idx = 0; idx < rows * cols; idx++) {
		if (pixel_value[idx] != other.pixel_value[idx])
			return false;
	}
	return true;
}
