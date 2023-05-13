//02-04-22
//oops i skipped this one
//watched zoom on 02-06-22

/*
design and planning LIFE CYCLE
    analyze <--> design <--> implement <--> test <--> deploy --> (analyze)
        analyze
       /       \
      /         \
deploy           design
      \         /
       \       / 
     test & implement  
    pseudocode
    flowcharts
    top-down design: perfect number checker
    bottom-up design: [nand game](https://nandgame.com/)
*/

/*
pseudocode for perfect number checker
a perfect number is one which is equal to sum of its proper divisors (divisors strcitly less than itself).

e.g. 6 is perfect
6 is divisible by 1, 2, 3
1 + 2 + 3 = 6
6: |------|
6: |12-3--|

e.g. 28 is perfect
28 is divisible by 1, 2, 4, 7, 14
1 + 2 + 4 + 7 + 14 = 28
28: |----------------------------|
28: |12-4---7------14------------|

e.g. 12 is not perfect
12 is divisible by 1, 2, 3, 4, 6
1 + 2 + 3 + 4 + 6 = 16

e.g. 16 is not perfect
16 is divisible by 1, 2, 4, 8
1 + 2 + 4 + 8 = 15

function main
input: an integer from the user
output: prints whether input is a perfect number
throws: none
    try to get an integer from the user
        if catch invalid_argument, then print "invalid input" and return 0 (exit with code 0)
        if catch anything else, then print "generic exception" and return 1 (exit with code 1)
    if integer is perfect, then
        print "perfect"
    else
        print "not perfect"
    end
    return 0 (exit with code 0)
end

function get_integer
input: input stream from which to read
output: integer read from stream
throws: invalid_argument
    extract an integer from the stream
    if extraction fails, then
        throw invalid_argument (invalid input)
    end
    return integer
end

function is_perfect
input: integer
output: true iff integer is a perfect number
throws: none
    if integer <= 0, then return false (negative and 0 are not perfect)
    get sum of integer's proper divisors
    return true iff sum of divisors equals integer
end

function sum_of_proper_divisors
input: positive integer (>0)
output: sum of the proper divisors of the input integer
throws: none
    if integer = 0, then return 0 (0 is divisible by all non-0 integers)
    guarantee that integer is positive
    set sum = 0
    for each number from 1 to integer/2, do
        if number divides integer evenly (no remainder), then
            update sum = sum + number
        end
    end
    return sum
end

===== begin OBSOLETE =====

function sum_of_divisors
input: positive integer (>0)
output: sum of the proper divisors of the input integer
throws: none
    if integer = 0, then return -1 (0 is divisible by all non-0 integers)
    guarantee that integer is positive
    [
        get list of divisors of integer
        sum the list
    ] do 'online' (do the sum without making the list)
    return the sum
end

function list_of_proper_divisors
input: positive integer
output: list of proper divisors of integer
throws: none
    make empty list
    guarantee integer is positive
    for each number from 1 to integer/2, do
        if number divides integer evenly (no remainder), then
            add number to list
        end
    end
    return list
end

function sum_list
input: list of numbers
output: sum of numbers in list
throws: none
    set sum = 0
    for each number in list, do
        set sum = sum + number
    end
    return sum
end

===== end OBSOLETE =====

function divides
input: positive integers a and b
output: true iff a divides b without remainder
throws: none
    if a = 0, then return false (0 does not divide any number)
    if b = 0, then return true (0 is divisible by all numbers)
    guarantee a and b are positive
    return whether b/a has remainder 0
end
*/

/*
next steps:
BEFORE implementing:
    do design review (i caught a few errors in the design and fixed them, also refined the design for efficiency and simplicity)
    write tests for each unit (function)
implement from the bottom up (i.e. start with divides)
test each unit completely before moving on/up
if design changes must be made, update the design and the tests first then the code
*/

#include <iostream>

using std::cout, std::endl;

int main() {

    return 0;
}