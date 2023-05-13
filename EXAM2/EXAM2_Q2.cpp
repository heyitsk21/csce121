// Katelyn Nguyen 132000282
// csce 121 - 593
// 05 April 2022
// Exam 2, Question 2


#include <iostream>
#include <string>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

//write only definitions
class Retailer {
    string name;
    vector<Laptop> inventory; 
public:
    Retailer(string name);
    const string& getName();
    void addLaptop(const Laptop& newLaptop);
}
class Laptop {
    string brand;
    double batterLife;
    bool MeetsBYODRequirements;
public:
    Laptop(string brand, double batterLife, bool MeetsBYODRequirements);
    const string& getBrand();
    const double& getBatterLife();
    const bool& getMeetsBYODRequirements();
}

// int main(){
//     return 0;
// }