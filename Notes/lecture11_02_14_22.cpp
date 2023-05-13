/*
intro to arrays
    homogeneous, aggregate
    capacity, size
    parallel arrays --> pseudoheterogeneity
declaring, defining and initializing arrays
    C-style
        declare = define
        always use literal or const for capacity
        brace-enclosed initialization
accessing arrays
    "index"
    operator[]
*/

/*
Objectives
1) Explain arrays at a conceptual/abstract level.
2) Explain how arrays are stored and accessed in memory.
3) Read and write C++ code to create and access stack-allocated arrays.
-----
An array is a homogenous aggregate data type
* A block of contiguous memory that stores many elements of the same data type.
* C/C++: Represented by a pointer (address) to the start of the memory block
      +---+---+---+---+---+---+---+
  +-->| 8 | 6 | 7 | 5 | 3 | 0 | 9 | <-- array
  |   +---+---+---+---+---+---+---+
  |     0   1   2   3   4   5   6 <-- index
  |
0x7ffd1ea6ba20 <-- address
* Two (or more) arrays can be used to achieve pseudoheterogeneity
          +---+---+---+---+---+---+---+
  +------>| 8 | 6 | 7 | 5 | 3 | 0 | 9 | <-- array
  |       +---+---+---+---+---+---+---+
  |         0   1   2   3   4   5   6 <-- index
  |
  |       +---+---+---+---+---+---+---+
  |   +-->| a | b | c | d | e | f | g | <-- array
  |   |   +---+---+---+---+---+---+---+
  |   |     0   1   2   3   4   5   6 <-- index
  |   |
  | 0x7ffd1ea6ba40 <-- address
  |
0x7ffd1ea6ba20 <-- address
-----
Declaring and defining arrays on the stack
int A[7];
^   ^ ^
|   |  \
|   \   - capacity
\    - name
 -type
 
* Array declaration is definition.
* Allocates space on the stack for 7 integers.
* The variable A "holds" the address of the first byte.
    (but not really)
 A    = 0x7ffd1ea6ba20  <-- the "value" of A
&A    = 0x7ffd1ea6ba20  <-- the address of A
&A[0] = 0x7ffd1ea6ba20  <-- the address of A[0]
A[0]  = 8               <-- some integer
* The value of A = the address of A = the address of the first element in A.
* The variable A _refers to_ the address of the first element of an array of 7 integers.
* The capacity MUST be 
  + integer literal, e.g. 7
  + const, e.g. const int size = 7
-----
Initializing arrays
* Can declare/define and initialize in one line
int A[] = {8, 6, 7, 5, 3, 0, 9};
* Can initialize elements after declaration/definition
int A[7];
for (int n = 0; n < 7; n++) {
    double a = (5760. + n*(-1440. + (n-1)*(1080. + (n-2)*(-720. + (n-3)*(270. + (n-4)*(-78 + (n-5)*31.))))))/720.;
    A[n] = static_cast<int>(a);
}
* "Shorthand" for initializing to all 0s (only works for 0 / default value)
int A[10]{};
int A[10]{0};
int A[10] = {};
int A[10] = {0};
-----
Accessing array elements
ARRAY[INDEX] := access the element at the specified index in the array
      +---+---+---+---+---+---+---+
  +-->| 8 | 6 | 7 | 5 | 3 | 0 | 9 | <-- array
  |   +---+---+---+---+---+---+---+
  |     0   1   2   3   4   5   6 <-- index
  |
0x7ffd1ea6ba20 <-- address
int A[7];
int size = 7;
int A1 = A[1]; // gets the value of the 1th element of A
A[2] = 7;      // sets the value of the 2th element of A
int A3 = 3[A]; // weird, but works

WAR CRIMES!!!!!!!!! NEVER ACCESS OUT OF BOUNDS:
A[-1]
A[7]
-----
*/

#include <iostream>

using std::cout, std::cin, std::endl;

int main() {

    const unsigned CAPACITY = 10;
    int arr[CAPACITY] = {8,6,7,5,3,0,9};
    // int arr[10] = ...
    unsigned size = 7;

    /*
             capacity = 10
            v-----------------v
    arr := [8|6|7|5|3|0|9| | | ]
            0 1 2 3 4 5 6 7 8 9 <-- index
            ^-----------^
             size = 7
    */
    /*
    std::string title[] = {"my neighbor totoro", "howl's moving castle", "sprited away"};
    int year[] = {1988, 2004, 2001};
    */
    /*
    title := ["my neighbor totoro", "howl's moving castle", "sprited away"]
    year :=  [               1988 ,                  2004 ,          2001 ]
    */ 

    for (unsigned i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    /*
    //cout << arr << endl;  // 0x7fffd4f70f60
    //cout << year << endl; // 0x7fffd4f70f40
    //cout << year[8] << year[9] << year[10] << endl;
    year[8] = -1;
    year[9] = -2;
    year[10] = -3;
    for (unsigned i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    */

    return 0;
}s