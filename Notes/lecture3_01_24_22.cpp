//01-24-22

/*endl vs \n
--flushing????

cmath in the std thingie <-- en cppreference website (encyclopedia)
*/

//Functions in C++
    #include <iostream>
    
    #define DEBUG(X) std::cout<<"("<<__FUNCTION__<<":"<<__LINE__<<") [DEBUG] "<<x<<std::endl;
    
    using std::cout,std::endl;
    
    /*
    name: "foo"
    parameters:
        1. "x": int
    return type: int
    */
    
    int foo(int x) {
        x += 1;
        cout << x << endl;
        return x;
    }
    void bar(int x) {
        x += 1;
        //returns nothing.
        //[return;]
    }
    void functions() {
        int x = 12;
        //store it
        int y = foo(x);
        cout << y << endl;

        //use it
        cout << foo(x) << endl;

        //lose it
        cout << x << endl;
        foo(x);
        cout << x << endl;

        return 0;
    }
    void bool_logic() {
        //AND, OR, NOT
        
        cout << std::boolalpha;

        //NOT  <-- ! = "bang"
        cout << "!true"<< !true << endl;
        cout << "!false"<< !false << endl;
        cout << "0 == " << (bool)0 << endl;
        cout << endl;

        //AND
        cout << "true && true == " << (true && true) << endl;
        cout << "true && false == " << (true && false) << endl;
        cout << "false && true == " << (false && true) << endl;
        cout << "false && false == " << (false && false) << endl;

        //OR
        cout << "true || true == " << (true || true) << endl;
        cout << "true || false == " << (true || false) << endl;
        cout << "false || true == " << (false || true) << endl;
        cout << "false || false == " << (false || false) << endl;

        bool bool_variable = true;
        if (bool_variable /*""== true" is NOT necessary*/) {
            cout << "bool_variable is true" << endl;
        }
        if (!bool_variable) {
            cout << "bool_variable is NOT true" << endl;
        } else {
            cout << "bool_variable is true" << endl;
        }

        int x=7;
        if (x>5 && x%3==1) {
            cout << "bingo!" << endl;
        }
    }
    void unsigned_counting() {
        size_t length = 10;
        for (unsigned index = 9; index > 0; index--) {
            cout << index << endl;
        }
        unsigned char i = 250;
        while (i < 255) {
            cout << i+1 << endl;
            i++;
            //char only goes up to 255. canNOT go up to 256
        }

            //if (index > 9) {
            //    break;
            //}

            // 0 - 1 = a big ass garbage number
    }
    void overflow_avoidance() {
        int x,y;
        x=50000;
        y=64000;
        //int z = x*y;
        //cout << x << " * " << y << " = " << endl; 
        //leads to overflow

        //only do the mult if it will not overflow
        //  cannot trust answer if overflow
        int z;
        if(x*y <= INT32_MAX/*largest value of a signed integer*/){
        //if (x <= INT32_MAX/y){        //dividing by zero is bad!
        //if (y!=0 && (x <= INT32_MAX/y)){
            z=x*y;
            cout << x << " * " << y << " = " << endl; 
        } else {
            cout << "[ERROR] operation would overflow" << endl; 
        }
    }
    int main() {
        //functions();
        //bool_logic();
        //unsigned_counting();
        //overflow_avoidance();
        
        DEBUG(1+2); //same as print statement debugging

        return 0;

    }