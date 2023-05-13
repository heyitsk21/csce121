/*
g++ -std=c++17 -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -g lecture5_01_28_22.cpp
*/

#include <iostream>

#define DEBUG(X) std::cout<<"("<<__FUNCTION__<<":"<<__LINE__<<") [DEBUG] "<<X<<std::endl;
#define DEBUG2(X) std::cout<<"("<<__FUNCTION__<<":"<<__LINE__<<") [DEBUG] "<<#X<<<<" := "<<X<<std::endl;

using std::cout, std::endl;

void foo(){
    
}

int main(){
    foo();
    return 0;
}