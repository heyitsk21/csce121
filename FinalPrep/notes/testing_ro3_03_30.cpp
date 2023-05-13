/*
review rule of 3
    * destructor - prevent memory leaks
    * copy constructor - constructs deep copy
    * copy assignment operator - prevents memory leaks AND makes deep copy

integration testing
    * test using several methods, e.g. an entire class
        - contrast with unit testing: unit testing tests ONE method 
                                      integration testing tests several together

testing rule of 3
    * destructor: don't bother (no effective unit test)
        BUT! compile with sanitizers and look for memory leaks
    * copy constructor:
        make a Thing
        put values in Thing
        in local scope
            construct a copy of Thing
            verify a deep copy (incl. unchanged original)
                def: different dynamic memory addresses
                behave: changes to one do not affect the other
        verify that original is unchanged (after destruction of copy)
    * copy assignment:
        make a Thing
        put values in Thing
        in local scope
            make another Thing
            put values in other Thing
            assign one to the other (make a copy by assignment)
            verify a deep copy (incl. unchanged original)
                def: different dynamic memory addresses
                behave: changes to one do not affect the other
        verify that original is unchanged (after destruction of copy)

iterator

*/

#include <iostream>

using std::cout, std::endl;

int main() {

    return 0;
}