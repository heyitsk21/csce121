//Katelyn Nguyen 132000282 QUESTION 2
//593 Tuesday March 1st, 2022; 12:45pm Ritchey

/*

/////NOTES/////
n can't be negative
if n is <= 2, n is returned


/////TEST CASES/////
foo(-5); <-- should throw an exception
foo(0);  <-- should return itself
foo(3);  <-- should return 6
foo(8);  <-- should return 840
*/

#include <iostream>
#include <stdexcept>

using std::cout, std::endl;
int GCD(int a, int b){ //2,3    //6,4
    if(a < 0){
        a *= (-1);
    }
    if(b < 0){
        b *= (-1);
    }
    while (b > 0){
        int t = b;//t=3  =1
        b = a % b;//b=1 =0
        a = t;//a=1 
    }
    return a;
}

int foo(int n){
    if(n < 0){
        throw std::domain_error("n cannot be negative");
    } else if(n <= 2){
        return n;
    }

    int t = 2;
    for(int i = 3; i <= n; i++){
        int g = GCD(t,i); //(2,3)=1     (6,4)=
        t = (t * i)/g;//(2*3)/1=6
    }
    return t;//=3
}


int main(){
    //cout<<"TEST CASE 1: "<<foo(-5)<<endl;
    cout<<"TEST CASE 2: "<<foo(0)<<endl;
    cout<<"TEST CASE 3: "<<foo(3)<<endl;
    cout<<"TEST CASE 4: "<<foo(8)<<endl;
    return 0;
}