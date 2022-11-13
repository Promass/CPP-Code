#include<iostream>
#include<limits>
#include<vector>
#include"Image.h"

int main() {

	//-----------------------------------------------------------------Creating Demo Objects-----------------------------------------------------------------

	unsigned int idx_counter = 0;
	std::vector<Image> Ivector(50);

	std::cout << "==================================================="
			<< std::endl;
	std::cout << "            Welcome to Image Repository" << std::endl;
	std::cout << "==================================================="
			<< std::endl;

	if (Ivector[idx_counter].addImage("mona_lisa.ascii.pgm") == 1) {
		idx_counter++;
		std::cout << "Successfully added first demo image (Index = 0)"
				<< std::endl;
	} else
		std::cout << "Could not add first demo image" << std::endl;

	if (Ivector[idx_counter].addImage("mona_lisa.ascii.pgm") == 1) {
		idx_counter++;
		std::cout << "Successfully added second demo image (Index = 1)"
				<< std::endl;
	} else
		std::cout << "Could not add second demo image" << std::endl;

	if (Ivector[idx_counter].addImage("balloons.ascii.pgm") == 1) {
		idx_counter++;
		std::cout << "Successfully added third demo image (Index = 2)"
				<< std::endl;
	} else
		std::cout << "Could not add third demo image" << std::endl;

	std::cout
			<< "\nThe second image is the same as the first image for demonstration purpose \nInsert 'help' to see the list of available commands\n"
			<< std::endl;

	std::string command;

	do {

		std::cout << "> ";
		std::cin >> command;

		if (command == "help") {
			std::cout << "input - To add a new image to the repository\n";
			std::cout
					<< "output - to delete the image from the repository and to output a '.pgm' image file\n";
			std::cout
					<< "getValue - to get the value of a given pixel of an image\n";
			std::cout << "setValue - to modify a given pixel of an image\n";
			std::cout << "compare - to compare two images";
			std::cout << "quit - to exit the program\n";
		}

		//-----------------------------------------------------------------addImage Function Demo-----------------------------------------------------------------

		else if (command == "input") {
			std::cout
					<< "Enter the name or the directory of the Image file you want to add: ";
			std::cin >> command;
			if (Ivector[idx_counter].addImage(command) == 1) {
				idx_counter++;
				std::cout << "Image successfully added to the repository\n"
						<< std::endl;
			} else
				std::cout << "Could not add image to the repository\n"
						<< std::endl;
		}

		//-----------------------------------------------------------------outputImage Function Demo-----------------------------------------------------------------

		else if (command == "output") {
			unsigned int number;
			std::cout << "Enter the index of the output image: ";
			std::cin >> number;

			while (std::cin.fail()) { //Accepts Integer Type Input Only
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
						'\n');
				std::cout << "\nProgram: Input has to be of type integer"
						<< std::endl;
				std::cout << "\nPlease Enter a valid index: ";
				std::cin >> number;
			}

			if (number > idx_counter) {
				std::cout << "Index value not found\n" << std::endl;
				continue;
			}
			std::cout
					<< "Enter the name of the output image (Enter extension .pgm to get an image file): ";
			std::cin >> command;
			if (Ivector[number].outputImage(command) == 1) {
				Ivector.erase(Ivector.begin() + number);
				idx_counter--;
				std::cout << "Image output successful\n" << std::endl;
			} else
				std::cout << "Could not output image\n" << std::endl;

			//-----------------------------------------------------------------getPixelValue Function Demo-----------------------------------------------------------------

		} else if (command == "getValue") {
			unsigned int number;
			unsigned int row, col;
			std::cout << "Enter the index of the image: ";
			std::cin >> number;

			while (std::cin.fail()) { //Accepts Integer Type Input Only
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
						'\n');
				std::cout << "\nProgram: Input has to be of type integer"
						<< std::endl;
				std::cout << "\nPlease Enter a valid index: ";
				std::cin >> number;
			}

			if (number > idx_counter) {
				std::cout << "Index value not found\n" << std::endl;
				continue;
			}
			std::cout << "Enter the row number: ";
			std::cin >> row;

			while (std::cin.fail()) { //Accepts Integer Type Input Only
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
						'\n');
				std::cout << "\nProgram: Input has to be of type integer"
						<< std::endl;
				std::cout << "\nPlease Enter a valid row: ";
				std::cin >> row;
			}

			std::cout << "Enter the column number: ";
			std::cin >> col;

			while (std::cin.fail()) { //Accepts Integer Type Input Only
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
						'\n');
				std::cout << "\nProgram: Input has to be of type integer"
						<< std::endl;
				std::cout << "\nPlease Enter a valid column: ";
				std::cin >> number;
			}

			if (Ivector[number].getPixelValue(row, col) != 0)
				std::cout << "The pixel value at this index is "
						<< Ivector[number].getPixelValue(row, col) << std::endl
						<< std::endl;
			else
				std::cout << "The pixel value at this index is 0" << std::endl
						<< std::endl;

			//-----------------------------------------------------------------setPixelValue Function Demo-----------------------------------------------------------------

		} else if (command == "setValue") {
			unsigned int number;
			unsigned int row, col;
			short value;
			std::cout << "Enter the index of the image: ";
			std::cin >> number;

			while (std::cin.fail()) { //Accepts Integer Type Input Only
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
						'\n');
				std::cout << "\nProgram: Input has to be of type integer"
						<< std::endl;
				std::cout << "\nPlease Enter a valid index: ";
				std::cin >> number;
			}

			if (number > idx_counter) {
				std::cout << "Index value not found\n" << std::endl;
				continue;
			}
			std::cout << "Enter the row number: ";
			std::cin >> row;

			while (std::cin.fail()) { //Accepts Integer Type Input Only
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
						'\n');
				std::cout << "\nProgram: Input has to be of type integer"
						<< std::endl;
				std::cout << "\nPlease Enter a valid row: ";
				std::cin >> row;
			}

			std::cout << "Enter the col number: ";
			std::cin >> col;

			while (std::cin.fail()) { //Accepts Integer Type Input Only
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
						'\n');
				std::cout << "\nProgram: Input has to be of type integer"
						<< std::endl;
				std::cout << "\nPlease Enter a valid column: ";
				std::cin >> number;
			}

			std::cout << "Enter the new value of the pixel: ";
			std::cin >> value;
			Ivector[number].setPixelValue(row, col, value);
			std::cout << std::endl;

			//-----------------------------------------------------------------Operator '==' Overloading Function Demo-----------------------------------------------------------------
		} else if (command == "compare") {
			unsigned int num1, num2;
			std::cout << "Enter the index of the first image: ";
			std::cin >> num1;

			while (std::cin.fail()) { //Accepts Integer Type Input Only
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
						'\n');
				std::cout << "\nProgram: Input has to be of type integer"
						<< std::endl;
				std::cout << "\nPlease Enter a valid index: ";
				std::cin >> num1;
			}

			std::cout << "Enter the index of the second image: ";
			std::cin >> num2;

			while (std::cin.fail()) { //Accepts Integer Type Input Only
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
						'\n');
				std::cout << "\nProgram: Input has to be of type integer"
						<< std::endl;
				std::cout << "\nPlease Enter a valid index: ";
				std::cin >> num2;
			}

			if (num1 > idx_counter) {
				std::cout << "First index value not found\n" << std::endl;
				continue;
			} else if (num2 > idx_counter) {
				std::cout << "Second index value not found\n" << std::endl;
				continue;
			} else if ((Ivector[num1] == Ivector[num2]) == 1) {
				std::cout << "They are same images" << std::endl << std::endl;
			} else {
				std::cout << "These two images are not similar" << std::endl
						<< std::endl;
			}
		}

		else {
			std::cout
					<< "The commands are case sensitive. Please insert a new command.\n"
					<< std::endl;
		}

	} while (command != "quit");

	std::cout << "=================================================="
			<< std::endl;
	std::cout << "     Image Repository Successfully Terminated" << std::endl;
	std::cout << "=================================================="
			<< std::endl;

	return 0;

}
