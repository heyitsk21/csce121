/*
/////PROMPT/////
Consider the following triangle of numbers:
       1^2
     2^2  3^2
   4^2  5^2  6^2
7^2  8^2  9^2  10^2 
     ...
What is the sum of the nth row? 
(assume n sufficiently small that 
the sum will not overflow an unsigned long)
*/

/*
/////TEST CASES/////

what if nth row is negative?
what if nth row is positive?
what if nth row is 0?
what if nth row supplied is not an integer?

what if the value is too large?

*/


#include <iostream>
using std::cout,std::endl;

unsigned long sumOfNthRow(int n){
    unsigned long sum = 0;
    int firstValue = 0;
    //find the first value of n'th row
    for(int i = 1; i<=n-1; ++i){    //summate row from i = 1 to the (n'th - 1) row
        firstValue += i;                //add 1 to firstValue
    }                               //end
    firstValue += 1;                //add 1 to firstValue at the end
        
    // ##debugging## cout << firstValue << endl;
    
    //find the number of values within n'th row (simple enough, remember num = n)
    int numOfValues = n;            //numValues = n (numValues = row number)
    
    //sumate each squared value together to find answer <-- loop
    for(int i = firstValue; i<firstValue+numOfValues; ++i){    //from (i = first value I found) to (first value + # of values within nth row)
        sum += i * i;    //add i^2 to total
    }
    
    
    //////PREVIOUS VERSION BELOW/////////
    //find the first value of n'th row
        //summate row from i = 1 to the (n'th row - 1), and add 1 at the end
        
           //n-1
        //SUMMATION {i} + 1
           //i=1

            //from i = 1 to the nth-1 row
                //add i to firstValue
            //end
            //add 1 to firstValue
    
    //find the number of values within n'th row (simple enough, remember num = n)
        //numValues = n
    
    //sumate each squared value together to find answer <-- loop
        //from (i = first value I found) to (first value + # of values within nth row)
            //add i^2 to total
    return sum;
}


int main(){
    cout << sumOfNthRow(3) <<endl;
    return 0;
}