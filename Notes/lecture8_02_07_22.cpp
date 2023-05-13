//02-07-22
/*

see testing for perfect number checker

object-oriented concepts

    c++ strings
    message passing (calling member functions)
    encapsulation

what is an object?
a thing (or a representation of a thing)
encapsulates data and methods
responds to message passing ("invoking methods")

*/

#include <iostream>

using std::cin, std::cout, std::endl;
using std::string;

int main() {
    string str = "Howdy";
    cout << str << endl;

    string::size_type len = str.length(); // size_t len = ...
    cout << len << endl;

    //str.operator+=(" world!");
    str += " world!";
    cout << str << endl;
    cout << str.length() << endl;

    cout << "str[3] = " << str[3] << endl;
    cout << "str.at(3) = " << str.at(3) << endl; //USE .at() so you don't read or write out of bounds!!!

    cout << "str[12] = " << str[12] << endl;
    //cout << "str.at(12) = " << str.at(12) << endl; //crashes oof

    str.at(6) = 'W'; // strings in c++ are MUTABLE!!
                     // unlike in python! -- once you make a string in python, you cannot change it
    cout << str << endl;

    /*
    // encapsulation
    {data, methods} - bundle data and methods together into one thing

    string: {
        data:
            array of characters
            number of characters / length of string
            
        methods:
            length() - return length of string
            at(index) - return character at given index
            find(string) - return first index of string in this string, or -1 (npos) if not found
            ...
    }
    */

    for(unsigned i = 0; i < len; i++){ //"int = i" would've used a signed integer but "len" is unsigned!!
        cout << str.at(i) << endl;
    }

    cout << "-------" << endl;

    for(char c: str){
        cout << c << endl;  
    }
    
    //write out of bounds - BAD!!!!
    str[12] = '.';
    str[13] = 'X';
    //str[14] = '\0';
    cout << str << endl; //LOOKS like nothing happened, but this stuff out of bounds is overwriting the objects next to it in memory-- MEGA BAD!!
    cout << str.data() << endl;
    return 0;
}