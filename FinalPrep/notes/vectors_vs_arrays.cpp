/*
object: a grouping of data (variables) and operations that can be performed on that data (functions)

abstraction: to have the user interact with an item at a high-level, with lower-level internal details hidden from the user
    * aka Information Hiding
    * aka Encapsulation

Abstract Data Type (ADT): a data type whose creation and update are constrained to specific well-defined operations
    * a class can be used to implement an ADT.

vector: an ordered list of items of a given data type. 
element: each item in a vector


VECTORS
    vector<dataType> vectorName(numElements);
        - all elements are automatically initialized to 0s during vector declaration
    vector<int> myVector(3, -1);
        - creates a vector named myVector with three elements, each with value -1.
    vector<int> carSales = {5, 7, 11}; 
        - creates a vector of three integer elements initialized with values 5, 7, and 11. Such vector declaration and initialization does not require specifying the vector size, because the vector's size is automatically set to the number of elements within the braces.

    * {} braces
    * <> angle brackets or chevrons
    * safer, more powerful form of arrays

    * at(index): function used to access elements at indicated index
        * [] brackets can be used for accessing, but does NOT automatically range check.
        * .at() DOES automatically range check
    * unsigned int size(): function that returns the number of vector element
    * void resize(): set or change a vector's size while a program executes 
        * possible because a vector's size doesn't need to be specified in the vector's declaration. 
        * If the new size is larger, resize() adds elements at the end.
        * If smaller, resize() deletes elements from the end. 
    * void push_back(): append a new element to the END of an existing vector
    * int back(): last element is returned
    * void pop_back(): last element is removed

    don't forget to    #include <vector>    !!!

    
    


ARRAYS
    int myList[10]
    * accessed as myList[i]
        * this accessing involves NO CHECKS ON WHETHER THE INDEX IS IN A VALID RANGE
*/