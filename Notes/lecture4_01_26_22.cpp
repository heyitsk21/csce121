#include <iostream>
#define DEBUG(X) std::cout<<"("<<__FUNCTION__<<":"<<__LINE__<<") [DEBUG] "<<X<<std::endl;
#define DEBUG2(X) std::cout<<"("<<__FUNCTION__<<":"<<__LINE__<<") [DEBUG] "<<#X<<" := "<<X<<std::endl;

using std::cout, std::endl;

int foo(){

    DEBUG("in foo");
    return 0;
}

bool test_foo(){
    //expect foo() to return 1
    if (foo()!= 1){
        cout <<"[FAIL] expected foo() to return 1"<<endl;
        return false;
    }
    return true;
}

int main(){
    DEBUG(1+2);
    DEBUG2(1+2);
    DEBUG2(foo());

    if (!test_foo()){
        cout<<"[FAIL] foo() failed a test." << endl;
    }
    else{
        cout<<"[PASS] foo() passed all tests." <<endl;
    }
    return 0;
}