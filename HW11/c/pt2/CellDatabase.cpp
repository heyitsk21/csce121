#include <iostream>
#include <string>
#include <sstream>
#include "CellDatabase.h"
#include "CellData.h"
#include <fstream>

using std::cout;
using std::string;
using std::fstream;
using std::ofstream;
using std::endl;

// Default constructor/destructor. Modify them if you need to.
CellDatabase::CellDatabase(): records(){}
CellDatabase::~CellDatabase() {}


void CellDatabase::loadData(const string& filename) {
    fstream i_stream(filename);
    // can it open
    if(!i_stream.is_open()){
        cout << "Error: Unable to open"<< endl;
    }
    i_stream >> filename.id;
    int count = 0;
    //invalid format
    while(){
        count += 1;
        if(){
            cout << "Error, Invalid Input: "<< count << endl;
        }
        if(){
            cout << "Error, Invalid Input: "<< count << endl;
        }
        if(){
            cout << "Error, Invalid Input: "<< count << endl;
        } 
    }


}

// Do not modify
void CellDatabase::outputData(const string& filename) {
    ofstream dataout("sorted." + filename);

    if (!dataout.is_open()) 
    {
        cout << "Error: Unable to open " << filename << endl;
        exit(1);
    }
    dataout << records.print();
}

void CellDatabase::performQuery(const string& filename) 
{
    // Implement this function
}
