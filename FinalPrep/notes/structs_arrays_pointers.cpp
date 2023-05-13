/*

struct construct: defines a new type, which can be used to declare a variable with subitems
    * Each struct subitem is called a data member. 
    * For a declared variable, each struct data member can be accessed using ".", known as a member access operator, sometimes called dot notation.

array: a variable that has one name, but stores a list of data items, with each item being directly accessible.
    * element: Each item in an array
    * index: each element's location number
    * [] brackets
    * {} braces
    * copying an array requires a second array of the same size to be declared and a loop to copy each element one-by-one
const: keyword that can be prepended to an array variable declaration to prevent changes to the array
    const int YEARS[3] = {1865, 1920, 1964}; followed by YEARS[0] = 2000; yields a compiler error.


Multiple Arrays / Parallel Arrays
    * multiple same-sized arrays used to store related lists.


Char arrays / C strings
    * string: a sequence of characters
    * c strings: a char array, the only kinds of strings in the C language
        * end with a null character '\0'
    * string literals like "Star Wars" are automatically appended by a null character by the compiler
    * null-terminated string: an array of characters ending with a null character
        !!! common error !!! : traversing/looping through til an array's size rather than stopping at the null character
        for (i = 0;      userStr[i] != '\0'      ; ++i) {
            if (userStr[i] == '@') {
                cout << "Found '@'." << endl;
            }
        }
    * don't for get to      #include <cstring>      !!!



Pointer Variables
    * pointer: variable that holds a memory address, rather than holding data like most variables
        * has a data type
        * data type determines what type of address is held in the pointer
        * an asterisk (*) is used in the variable declaration before the pointer's name
        * reference operator (&) obtains the variable's address
        * dereference operator (*) is used before a pointer variable's name to retrieve the data to which the pointer variable points
        * nullptr: keyword that means "nothing"/Null
*/