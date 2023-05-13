/*
INTRODUCTION TO ERRORS AND ERROR HANDLING

    Types of Errors
    Syntax
        Compile line errors
            Use before declare
            and more...
        Linear errors
            Use before define
            and more...
        Typographical errors
            missing ;, ), },
            and more...
    Runtime errors
        Divide by zero
            integer --> crash, a hardware-level crash
            float --> ~~NaN~~ (not a number), inf
                0/0 ==> -NaN
        Null dereference --> crash
        Access out of bounds --> crash | unpredictable behavior
        and more...
    Semantic / Logic errors
        Incorrect algorithm
        Uninitiated variable
        Off by one (usually has to do with count variables)
        Wrong sign (+/-, >/<, etc.)
        Memory leaks/"hoarding" <<<<< Jeff Bezos lol
        Concurrency errors
            Race conditions (conflicts over resources/memory)
        and more...

Input Validation

    Range checking

*/

/*
g++ -std=c++17 -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -g lecture5_01_28_22.cpp
*/

#include <iostream>

#define DEBUG(X) std::cout<<"("<<__FUNCTION__<<":"<<__LINE__<<") [DEBUG] "<<X<<std::endl;
#define DEBUG2(X) std::cout<<"("<<__FUNCTION__<<":"<<__LINE__<<") [DEBUG] "<<#X<<<<" := "<<X<<std::endl;

using std::cout, std::endl, std::cin;

void foo(){
    int a = 1;
    int b = 0;
    if (b == 0){
        cout << "no way, jose!" << endl;
    } else {
        cout << a/b << endl;
    }
    
}

int main(){
    foo();
    
    // guarding IS input validation!
    int x; // suppose this comes from user
    cin >> x;
    if (x >= 1 && x <= 10){
        cout << 70/x << endl;
    } else {
        cout << "invalid input." << endl;
    }
    
    return 0;
}