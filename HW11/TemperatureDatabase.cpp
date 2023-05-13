#include "TemperatureDatabase.h"

#include <string>
#include <fstream>
#include <sstream>
using namespace std;
using std::cout, std::endl;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	// Implement this function for part 1
	ifstream myFile;
	myFile.open(filename);
	if (!myFile.is_open()){
		//throw std::invalid_argument("Invalid File: Cannot open file");
		cout << "Error: Unable to open input.dat" << endl;
	}

	string line;
	string id;
	int year;
	int month;
	double temperature;
	string extra;

	while (getline(myFile, line)){
		if (line == "") {
			//cout << "Error: Other invalid input" << endl;
		}

		std::istringstream iSS(line);

		if (!myFile.is_open()){
			//cout << "Error: Unable to open " << filename << ".dat" << endl;
		}
	
		//id
		iSS >> id;
		if (iSS.fail() ){//|| id.size() <= 0
			//throw std::domain_error("File contains invalid data (id)");
			cout << "Error: Other invalid input" << endl;
			continue;
			//cout << id << endl;
		}

		//year
		iSS >> year;
		if (iSS.fail()){
			cout << "Error: Other invalid input" << endl;
			continue;
			//cout << id << endl;
		} else if(!(year >= 1800 && year <= 2022)){
			cout << "Error: Invalid year " << year << endl;
		}


		//month
		iSS >> month;
		if (iSS.fail()){
			cout << "Error: Other invalid input" << endl;
			continue;
			//cout << id << endl;
		} else if(!(month > 0 && month < 13)){
			cout << "Error: Invalid month " << month << endl;
		}

		//temperature
		iSS >> temperature;
		if (iSS.fail()){
			cout << "Error: Other invalid input" << endl;
			continue;
			//cout << id << endl;
		} else if(!(temperature >= -50.0 && temperature <= 50.0)){
			cout << "Error: Invalid temperature " << temperature << endl;
		}

		//extra
		if (iSS >> extra){
			cout << "Error: Other invalid input" << endl;
			continue;
			//cout << id << endl;
		}
	}
}

// Do not modify
void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}
	dataout << records.print();
}



void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
	//  Leave it blank for part 1

	ifstream myFile;
	myFile.open(filename);
	if (!myFile.is_open()){
		//throw std::invalid_argument("Invalid File: Cannot open file");
		cout << "Error: Unable to open input.dat" << endl;
	}


	loadData(filename);
	
	
	// string line;
	// string id;
	// int year;
	// int month;
	// double temperature;
	// string extra;

	// while (getline(myFile, line)){
	// 	if (line == "") {
	// 		//cout << "Error: Other invalid input" << endl;
	// 	}

	// 	std::istringstream iSS(line);

	// 	if (!myFile.is_open()){
	// 		//cout << "Error: Unable to open " << filename << ".dat" << endl;
	// 	}
	
	// 	//id
	// 	iSS >> id;
	// 	if (iSS.fail() ){//|| id.size() <= 0
	// 		//throw std::domain_error("File contains invalid data (id)");
	// 		cout << "Error: Other invalid input" << endl;
	// 		continue;
	// 		//cout << id << endl;
	// 	}

	// 	//year
	// 	iSS >> year;
	// 	if (iSS.fail()){
	// 		cout << "Error: Other invalid input" << endl;
	// 		continue;
	// 		//cout << id << endl;
	// 	} else if(!(year >= 1800 && year <= 2022)){
	// 		cout << "Error: Invalid year " << year << endl;
	// 	}


	// 	//month
	// 	iSS >> month;
	// 	if (iSS.fail()){
	// 		cout << "Error: Other invalid input" << endl;
	// 		continue;
	// 		//cout << id << endl;
	// 	} else if(!(month > 0 && month < 13)){
	// 		cout << "Error: Invalid month " << month << endl;
	// 	}

	// 	//temperature
	// 	iSS >> temperature;
	// 	if (iSS.fail()){
	// 		cout << "Error: Other invalid input" << endl;
	// 		continue;
	// 		//cout << id << endl;
	// 	} else if(!(temperature >= -50.0 && temperature <= 50.0)){
	// 		cout << "Error: Invalid temperature " << temperature << endl;
	// 	}

	// 	//extra
	// 	if (iSS >> extra){
	// 		cout << "Error: Other invalid input" << endl;
	// 		continue;
	// 		//cout << id << endl;
	// 	}
	// }	
}
