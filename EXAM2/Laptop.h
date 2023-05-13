// Katelyn Nguyen 132000282
// csce 121 - 593
// 05 April 2022
// Exam 2, Question 2, Laptop.h


#include <iostream>
#include <string>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Laptop {
    string brand;
    double batterLife;
    bool MeetsBYODRequirements;
public:
    Laptop();
    Laptop(string brand, double batterLife, bool MeetsBYODRequirements);
    const string& getBrand();
    const double& getBatterLife();
    const bool& getMeetsBYODRequirements();
};