/******************************************************************************

File: main.cpp
Author: Prof. Lupoli & Andrew Nemec
Date: 2/16/2021
Section: 
E-mail: slupoli@tamu.edu
Description:
This file contains C++  code that will simulate data collected from a track 
event with 9 lanes. The code will sort the order, then display the results

Updates
Author: J. Michael Moore & Paul Taele

Data File Information
name: data.text
content: The text file will contain data in the constant form of:
<Time (double)> <Abbreviated Country (String)> <Uniform number (int)> <Lastname (String)>
32.7 USA 12 Moore
36.5 RUS 35 Polsley
45.8 ENG 73 Teale
52.34 CHN 14 Nemec
76.45 ITY 23 Lupoli     

*******************************************************************************/

#include <iostream>
#include "parallel_tracks.h"

using std::cin; using std::cout; using std::endl;
using std::string; using std::getline; using std::ifstream;
using std::invalid_argument; using std::domain_error;

int main()
{
    // TODO: create arrays needed
	double Times[SIZE] = {};
    string Countries[SIZE] = {};
    unsigned int Uniforms[SIZE] = {};
    string LastNames[SIZE] = {};
    unsigned int Ranks[SIZE] = {};

    // TOTO: prep all arrays
    prep_double_array(Times);
    prep_string_array(Countries);
    prep_unsigned_int_array(Uniforms);
    prep_string_array(LastNames);
    prep_unsigned_int_array(Ranks);
	
    // TODO: prompt until both the file and the contained data are valid
    string fileName;
    bool fileValid = false;
    while (!fileValid){
        cout << "Enter file name: ";
        cin >> fileName;
        try{
            get_runner_data(fileName,Times,Countries,Uniforms,LastNames);
            fileValid = true; //(this gets skipped if it crashes)
        } catch (const std::domain_error& e){
            cout<<"Invalid File: "<<e.what()<<endl;
        } catch (const std::invalid_argument& e){
            cout<<"Invalid File: "<<e.what()<<endl;
        }
    }
    get_runner_data(fileName,Times,Countries,Uniforms,LastNames);

    // TODO: determine ranking, notice the rank array receives the results
    get_ranking(Times, Ranks);

    // TODO: Output results
    print_results(Times, Countries, LastNames, Ranks);

    return 0;
}

