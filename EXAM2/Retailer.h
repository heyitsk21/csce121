// Katelyn Nguyen 132000282
// csce 121 - 593
// 05 April 2022
// Exam 2, Question 2, Retailer.h


#include <iostream>
#include <string>
#include <vector>
#include "LAPTOP.H"
using std::cout, std::endl, std::vector, std::string;

class Retailer {
    string name;
    vector<Laptop> inventory; 
public:
    Retailer();
    Retailer(string name);
    const string& getName();
    void addLaptop(const Laptop& newLaptop);
};