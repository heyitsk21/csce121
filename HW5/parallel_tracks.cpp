#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <limits>
#include <cctype>
#include "parallel_tracks.h"

using std::string;

using std::cout, std::cin, std::endl;

using std::ifstream;


//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays , and a legit filename is pass
// PostCondition: all arrays contain data from the text file given
//---------------------------------------------------------
void get_runner_data( const std::string& file, double timeArray[], std::string countryArray[], 
		unsigned int numberArray[], std::string lastnameArray[]) 
{
	//TODO
	
	//open the file
	ifstream myFile;//NOT: ifstream myFile(file);
	myFile.open(file);

	//throw exception if file doesn't open correctly
	if(!myFile.is_open()){
		throw std::invalid_argument("Cannot open file");
	}

	//instantiate variables for time, country, number, and name + line!
	double time = 0.0;
	string country = "";
	unsigned int number = 0;
	string lastName = "";
	string line = "";

	//iterate through each item in the file, L to R, top to bottom
	for (unsigned int i = 0; i < SIZE; i++){
		
		getline(myFile, line);

		if(line == ""){
		throw std::domain_error("File missing data");
		}

		std::istringstream iSS(line);
		
		//throw exception if file doesn't open correctly
		if(!myFile.is_open()){
			throw std::invalid_argument("Cannot open file");
		}




		//TIME
		iSS >> time;
		if (iSS.fail() || time <= 0){
			throw std::domain_error("File contains invalid data (time)");
		}
		timeArray[i] = time;

		//COUNTRY
		iSS >> country;
		if (iSS.fail() || country == "" || country.size()!=3){
			throw std::domain_error("File contains invalid data (country)");
		} else {
			for (unsigned int j = 0; j<3; j++){
				if(!(isupper(country.at(j)))){
					throw std::domain_error("File contains invalid data (country)");
				}
			}
		}
		countryArray[i] = country;

		//NUMBER
		iSS >> number;
		if (iSS.fail() || number > 99){
			throw std::domain_error("File contains invalid data (number)");
		}
		numberArray[i] = number;

		//NAME
		iSS >> lastName;
		
		if (iSS.fail()){
			throw std::domain_error("File contains invalid data (name)");
		}
		
		lastName = trim(lastName);
		
		for (unsigned int k = 0; k < lastName.size(); k++){
			char temp = lastName.at(k);
			if (!isalpha(temp)){
				throw std::domain_error("File contains invalid data (name)");
			}
		}
		if (lastName.size()<2){
			throw std::domain_error("File contains invalid data (name)");
		}
		lastnameArray[i] = lastName;
		
	}
}

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  a double arrays is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{
	//TODO
	for(unsigned int index = 0; index < SIZE; index++){
		ary[index] = 0.0;
	}
}

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an unsigned int arrays is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
	//TODO
	for(unsigned int index = 0; index < 10; index++){
		ary[index] = 0;
}
}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  a string arrays is pass in
// PostCondition: data in the array is "N/A" out to determine if
// a value has changed
//---------------------------------------------------------
void prep_string_array(std::string ary[])
// making sure all values within the array are set to "N/A";
{
	//TODO
	for(unsigned int index = 0; index < SIZE; index++){
		ary[index] = "N/A";
	}
}

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements 
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[])
{
	//TODO
	double fastest_time = timeArray[0];
	for (unsigned int index = 0; index < SIZE; index++){
		if(timeArray[index]<fastest_time){
			fastest_time = timeArray[index];
			rankArray[index]=1;
		}
	}

	double second_fastest = 100.0;
	for (unsigned int index = 0; index < SIZE; index++){
		if(timeArray[index]<second_fastest && timeArray[index]>fastest_time){
			second_fastest = timeArray[index];
			rankArray[index]=2;
		}
	}

	double third_fastest = 100.0;
	for (unsigned int index = 0; index < SIZE; index++){
		if(timeArray[index]<third_fastest && timeArray[index]>second_fastest){
			third_fastest = timeArray[index];
			rankArray[index]=3;
		}
	}

	double forth_fastest = 100.0;
	for (unsigned int index = 0; index < SIZE; index++){
		if(timeArray[index]<forth_fastest && timeArray[index]>third_fastest){
			forth_fastest = timeArray[index];
			rankArray[index]=4;
		}
	}

	double fifth_fastest = 100.0;
	for (unsigned int index = 0; index < SIZE; index++){
		if(timeArray[index]<fifth_fastest && timeArray[index]>forth_fastest){
			fifth_fastest = timeArray[index];
			rankArray[index]=5;
		}
	}

	double sixth_fastest = 100.0;
	for (unsigned int index = 0; index < SIZE; index++){
		if(timeArray[index]<sixth_fastest && timeArray[index]>fifth_fastest){
			sixth_fastest = timeArray[index];
			rankArray[index]=6;
		}
	}

	double seventh_fastest = 100.0;
	for (unsigned int index = 0; index < SIZE; index++){
		if(timeArray[index]<seventh_fastest && timeArray[index]>sixth_fastest){
			seventh_fastest = timeArray[index];
			rankArray[index]=7;
		}
	}

	double eighth_fastest = 100.0;
	for (unsigned int index = 0; index < SIZE; index++){
		if(timeArray[index]<eighth_fastest && timeArray[index]>seventh_fastest){
			eighth_fastest = timeArray[index];
			rankArray[index]=8;
		}
	}

	double nineth_fastest = 100.0;
	for (unsigned int index = 0; index < SIZE; index++){
		if(timeArray[index]<nineth_fastest && timeArray[index]>eighth_fastest){
			nineth_fastest = timeArray[index];
			rankArray[index]=9;
		}
	}
}


//-------------------------------------------------------
// Name: print_results
// PreCondition:  almost all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays then along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const std::string countryArray[],
		const std::string lastnameArray[], const unsigned int rankArray[])
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;
		
	// print the results, based on rank, but measure the time difference_type
	for(unsigned int j = 1; j <= SIZE; j++)
	{
		
		// go thru each array, find who places in "i" spot
		for(unsigned int i = 0; i < SIZE; i++)
		{
			if(rankArray[i] == 1) // has to be a better way, but need the starting time
			{
				best_time = timeArray[i];
			}
			
			
			if(rankArray[i] == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl; 
			}
			
		}
	}	
}

std::string trim(std::string ret) {
	// remove whitespace from the beginning
	while (!ret.empty() && isspace(ret.at(0))) {
			ret.erase(0, 1);
		}

	// remove whitespace from the end
	//  Note: last index is (.size() - 1) due to 0 based indexing
	while (!ret.empty() && isspace(ret.at(ret.size()-1))) {
		ret.erase(ret.size()-1, 1);
	}
	
	return ret;
}