/*
    Rule of Three helpers: 
        clear():   transforms data structure (or whatever object this is) to pristine "new" state
                   invoked by: destructor and copy assignment operator
        copy(rhs): transforms data structure (or whatever object this is) to deep copy of rhs argument
                   invoked by: copy constructor and copy assignment operator
    
    List ADT
        ADT := Abstract Data Type
            what, not how
        data structure
            data & operations
        represents a sequential collection
            e.g. 8, 6, 7, 5, 3, 0, 9
               1st, 2nd, ........, 7th
        data:
            - container, e.g. array, linked list
            - administrative data, e.g. array needs size & capacity
        operations:
            + size() := the number of elements in the list
            + at(index) := reference to value at specified index, or excpetion if index out of bounds (index >= size)
            + insert(index, value) := insert value at specified index, or exception if index is out of bounds (index > size)
            + remove(index) := remove the element is the specified index, or exception is index out of bounds (index >= size)
*/

#define debug(x) cout << "[DEBUG] (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") " << #x << " := " << x << endl;

#include <iostream>
#include "tests.h"

using std::cout, std::endl;

int main() {
    bool pass = true;

    // Stack demonstrates Rule of 3 Helpers
    pass &= stack_tests();

    // ArrayList implements List ADT
    pass &= arraylist_tests();

    cout << (pass ? "OK" : "FAIL") << endl;

    return 0;
}