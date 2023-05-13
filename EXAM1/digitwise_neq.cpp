//Katelyn Nguyen 132000282 QUESTION 1
//593 Tuesday March 1st, 2022; 12:45pm Ritchey

/*
#include <iostream>
#include <stdexception>

using std::cout, std::endl;


digitwise_neq(int left, int right){
    int answer = 0;
    return answer;
}

int main(){
    digitwise_neq(11110000,10101010);
    return 0;
}


/////PSEUDOCODE/////
function digitwise_neq 
input: int left, int right
output: int answer (each digit is the corresponding digits in left and right NOT equaled together)
    check if invalid input (<=8 digits total; all digits must be 0 or 1)
        throw a domain error for an invalid input       //throw std::domain_error("Invalid Input");
    else [occurs when input is valid]
        let int placeCount = 0      //<-- this is counting which place we are at in our answer integer 
                                    //[in an 8 digit number: 0 is ones place, 7 is 10mils place] _ _ _ _ _ _ _ _
        number peeling-- uses integer division and modulo operator within a loop
            let int digitL = one's place digit in left
            let int digitR = one's place digit in right
            if digitL and digitR are the same,
                answer will have a 0 in its ones place 
            if digitL and digitR are different,
                answer will have a 1 in its ones place
            add 1 to placeCount
            //NOTE: each time placeCount goes up, the digit to be put into answer will go into the corresponding place (via multiplication of 10*placeCount)
    return the answer

*/