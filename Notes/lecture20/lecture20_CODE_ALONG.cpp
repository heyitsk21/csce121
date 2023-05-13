#include <iostream>
#include "tests.hpp"

using std::cout, std::endl;


int main(){
    test_contructor();
    test_push_back();
    test_pop_back();
    test_back();

    test_reserve();
    test_resize();

    test_at();
    test_front();
    test_empty();
    test_shrink_to_fit();
    test_clear();
    test_insert();
    test_erase();

    cout <<"ALL TESTS PASSING"<<endl;
    
    return 0;
}