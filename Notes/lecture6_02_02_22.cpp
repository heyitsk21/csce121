//01-31-22 no lecture notes
//02-02-22

/*
Exceptions and Exception Handling
    throw
    try / catch
    built-in exception types
    impact on control flow

    only throw an exception when you have no other option
    e.g.
        return an error code
        correct the value / change to a fail-safe default
        reprompt

    search "std::exception" on cppreference.com 
    to see all the exceptions that can be thrown

    always catch as "const std::<exception_type>& <name>"
    e.g. const std::invalid_argument& err
*/

#include <iostream>
using std::cout, std::endl;

void exceptional_method(int x){
    if (x<0){
        cout<<__FUNCTION__<<" throws an exception"<<endl;
        throw std::invalid_argument("negative value");
        //unreachable
    }
    cout<<__FUNCTION__<<" returns normally"<<endl;
}

void foo(int x){
    exceptional_method(x);
}

int main(){
    try{
        //exceptional_method(1);
        //exceptional_method(-1);
        foo(1);
        foo(-1);
        //begin
        //code that happens to be skipped due to exception thrown in foo(-1)
        cout<<__FUNCTION__<< "reached line "<<__LINE__<<endl; //control NEVER gets to this line because the previous line threw an exception
        //end
    } catch (const std::invalid_argument& err){
        cout<<__FUNCTION__<<" caught an exception: "
        <<err.what()<<endl; //".what() is a string ("negative value") (line 30!!)
    } catch (const std::exception& err){
        cout<<__FUNCTION__<<" caught any base exception: "
        <<err.what()<<endl; 
    } catch (...){
        cout<<__FUNCTION__<<" caught literally anything (but you won't know the kind): "
        <<err.what()<<endl; //".what() is a string ("negative value") (line 30!!)
    }
    return 0;


}