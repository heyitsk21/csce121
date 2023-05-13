#include
#include <iostream> // C++ library
#include <cstdio> // c library "stdio.h"
#include "my_header.h" // local header

//using-declarations

/* no! --> */ using namespace std; // SO VERY VERY VERY WRONG //same as import java.io.*; <-- BAD!

using std::cout, std::endl; // THIS IS THE WAY


int main() { 
    //control starts here (this is where the prgram begins)

    /*do work*/  
    
    //keep this function short and simple 
    //less than ~24 lines
    
    return 0; 
} 

//java= public static void main(){      }



I/O in C++
    streams
        operators
            std::ostream& operator<<
            std::istream& operator>>
        console streams
            std::cout
            std::cin
        file streams
            std::ifstream //input file stream 
            std::ofstream //output file stream
            std::fstream //stream flows in both directions. no need to use this
        string streams
            std::istringstream
            std::ostringstream
            std::stringstream 
////////////////////////////////////////////////
// VERY IMPORTANT
Compiling and Running from the Terminal

    This is a REQUIRED skill for my students.

    compilation command:
        g++ -std=c++17 hello_world_streams.cpp
    
    run command:
        ./a.out

    full 121 compile command:
        g++ -std=c++17 -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -g code.cpp more_code.cpp

    -o <name> flag:
        g++ [options] -o prgram_name <source>
    names the executable output as "prgram_name" --> ./program_name
    //be careful!!!
    g++ -o main.cpp code.cpp <-- THIS WILL OVERWRITE YOUR CODE WITH GARBAGE MACHINE CODE
////////////////////////////////////////////////