#include <iostream>
#include <cassert>
#include "tests.hpp"

using std::cout, std::endl;

void test_contructor(){
    {
        vector<int> v;
        assert(v.capacity() > 0);
        assert(v.size() == 0);
        assert(v.data() != nullptr);
    }

    {
        vector<int> v(101){
            assert(v.capacity() >= 101);
            assert(v.size() == 101);
            assert(v.data() != nullptr);
            for (size_t index = 0; index < 101; index++){
                v.data()[index] = 0;
            }
        }
    }
}
void test_push_back(){
    cout << "SKIPPED" << __FUNCTION__ << endl;
}
void test_pop_back(){
    cout << "SKIPPED" << __FUNCTION__ << endl;
}
void test_back(){
    cout << "SKIPPED" << __FUNCTION__ << endl;
}