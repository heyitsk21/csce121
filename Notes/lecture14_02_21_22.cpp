/*
structs
type conversion
references and pointers
*/

#include <iostream>
#include <string>
#include <array>

#define DEBUG(X) std::cout<<"[DEBUG] ("<<__FUNCTION__<<":"<<__LINE__<<") "<<#X<<" := "<<X<<std::endl;

using std::cout, std::endl, std::string;

struct Person {
    //private <--DOESN"T COMPILE
    //don't initialize within the struct !!!!!!! bad form
    string name;
    int age;
}; //<<<< SEMICOLON NECESSARY!!!! THIS IS A DEFINITION; WE ARE DEFINING SOMETHING

void struct_example() {
    Person prof_ritchey{"prof. ritchey", 101};
    //Person prof_ritchey;
    //prof_ritchey.name = "prof. ritchey";
    //prof_ritchey.age = 100;
    DEBUG(prof_ritchey.name);
    DEBUG(prof_ritchey.age);
    
    std::array<Person, 4> csce12x_instructors = {
        Person{"moore", 1000},
        Person{"taele", 38},
        Person{"ritchey", 101},
        Person{"taylor", 28}
    };
    
    for (const Person& person : csce12x_instructors) {
        cout << person.name << " " << person.age << endl;
    }
}

void type_conversion_example() {
    int x = 5;
    
    DEBUG(x);
    DEBUG(x/2);
    
    // convert to double
    double d = (double)x; // c-style
    //double d = double(x); // function-style
    //double d = static_cast<double>(x); // c++-style  //RECOMMENDED!!!!!!!!! 
    //double d = x; // implicit cast
    
    DEBUG(d);
    DEBUG(d/2);
    
    int y = d/2; // implicit cast (loss of precision)

    DEBUG(y);
    
    d = 1.9999999;
    y = (int)d;
    
    DEBUG(y);
    
    // 01000011 01000010 01000001
    // 'C'      'B'      'A'
    long* number = new long;        //////////////////////POINTERS //dynamic memory point allocation
    *number = 67; // 'C'
    *number <<= 8; // make room for next char
    *number += 66; // 'B'
    *number <<= 8; // make room
    *number += 65; // 'A'
    double* d_number = reinterpret_cast<double*>(number); ///////////////REINTERPRET
    char* c = reinterpret_cast<char*>(number);
    DEBUG(*number);
    DEBUG(*d_number);
    DEBUG(c);
    DEBUG((char*)number);
    DEBUG(*(int*)number); ///TRY PUTTING MORE CHARS (>4) IN NUMBER
    
    delete number; //DEALLOCATES THE MEMORY //not doing so causes a memory leak!
}

void references_and_pointers() {
    // int
    int w = 6;
    int x = 7; // on the stack
    int y = 8;
    
    // pointer to int
    cout << "pointer" << endl;
    int* p_x = &x;  // & := "address of"    //int* is basically unsigned long
                    // on the stack         //address will change each compilation
    DEBUG(x);
    DEBUG(p_x);
    DEBUG(*p_x); // * := "dereference"
    
    p_x++; //add one //moving pointer to a different place IS BAD--> "stack-buffer-overflow on this address"
    DEBUG(x);
    DEBUG(p_x);
    DEBUG(*p_x); // * := "dereference"
    
    // reference to int
    cout << endl << "reference" << endl;
    int& r_x = x;
    //r_x = x;
    
    DEBUG(x);
    DEBUG(r_x);
    
    r_x = 10;
    
    DEBUG(x);
    DEBUG(r_x);
    
    x = 12;
    
    DEBUG(x);
    DEBUG(r_x);
    
    // traversal with pointer
    cout << endl << "array traversal with pointer" << endl;
    char a[] = "hello world.\0";
    // null terminator byte ^
    char* p = a;
    cout << "cout << p << endl;" << endl;
    cout << p << endl;
    cout << endl;
    
    cout << "traversal" << endl;
    while(*p) {
        cout << *p;
        p++;
    }
    cout << endl;
}


int main() {
    struct_example();
    //type_conversion_example();
    //references_and_pointers();

    return 0;
}
