#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {

	vector<int> highTemp;
	vector<int> goodTemp;
	vector<int> lowTemp;

	ifstream myfile;
	myfile.open("temperature.txt");

	if (!myfile) {
		cout << "Error!";
	}
	else {
		int indexer = 0; 
		myfile >> indexer;
		for (int idx = 0; idx < indexer; idx++) {
			int temp = 0;
			myfile >> temp;
			if (temp >= 35) {
				highTemp.push_back(temp);
			}
			else if (temp < 35 && temp > 9) {
				goodTemp.push_back(temp);
			}
			else {
				lowTemp.push_back(temp);
			}
		}
	}
	myfile.close();

	ofstream hfw("High_Temp.txt", std::ofstream::out);
	if (hfw.is_open())
	{
		hfw << highTemp.size() << "\n";
		for (int i = 0; i < highTemp.size(); i++) {
			hfw << highTemp[i] << "\n";
		}
		hfw.close();
	}
	else {
		cout << "Problem with opening file";
	}

	ofstream gfw("Good_Temp.txt", std::ofstream::out);
	if (gfw.is_open())
	{
		gfw << goodTemp.size() << "\n";
		for (int i = 0; i < goodTemp.size(); i++) {
			gfw << goodTemp[i] << "\n";
		}
		gfw.close();
	}
	else {
		cout << "Problem with opening file";
	}

	ofstream lfw("Low_Temp.txt", std::ofstream::out);
	if (lfw.is_open())
	{
		lfw << lowTemp.size() << "\n";
		for (int i = 0; i < lowTemp.size(); i++) {
			lfw << lowTemp[i] << "\n";
		}
		lfw.close();
	}
	else {
		cout << "Problem with opening file";
	}

	return 0;
}