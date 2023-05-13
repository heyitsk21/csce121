/*

heap: region where the "new" operator allocates memory, and where the "delete" operator deallocates memory
    * aka Free Store
    * for dynamically allocated memory
    * grows upwards
    * programmer must allocate and deallocate memory

stack: region where a function's local variables are allocated during a function call.
    * aka Automatic Memory
    * compiler AUTOMATICALLY allocates STATIC memory
    * grows downwards

    static memory: The region where global variables (variables declared outside any function) as well as static local variables (variables declared inside functions starting with the keyword "static") are allocated. 

    new operator
        * returns a pointer to allocated memory
        * When used with a class type, the new operator allocates memory BEFORE calling the class's constructor.
        * The new operator allocates, but does not deallocate, memory.
        * always allocates an array as a contiguous block in memory

    -> member access operator
        * allows a pointer's member functions to be accessed

    delete operator
        * deallocates (frees) a block of memory that was allocated with the new operator
            * dereferencing a pointer whose memory has been deallocated is a COMMON ERROR
            * delete cannot be used on just any pointer. 
                It must be used on a pointer allocated with the new operator.

    delete[] operator
        * used to free an array allocated with the new operator

    memory leak
        * occurs when a program that allocates memory loses the ability to access the allocated memory, typically due to a failure to properly destroy/free dynamically allocated memory.
            Leaked memory becomes unusable.
        * some languages, like Java, use a mechanism called Garbage Collection wherein a program's executable includes automatic behavior that at various intervals finds all unreachable allocated memory locations

    pointer: a variable that contains a memory address

    >> c++ vector class: a container that internally uses a Dynamically Allocated Array, an array whose size can change during runtime
        each time the internal array is dynamically allocated, the array's location in memory will change

    this pointer: an implicit parameter that enables access to an object's data members within the object's class member functions


Inserting/erasing in vectors vs. linked lists
    * vector/arrays-- store a list of items in contiguous memory locations, which enables immediate access to any element of a vector userGrades by using userGrades.at(i) (or userGrades[i])
        * Stores items in contiguous memory locations
        * Supports quick access to i'th element via at(i)
            * May be slow for inserts or erases on large lists due to necessary shifting of elements
    * linked lists-- consist of items that contain both data and a pointer—a link—to the next list item
        * Stores each item anywhere in memory, with each item pointing to the next list item
        * Supports fast inserts or deletes
            * access to i'th element may be slow as the list must be traversed from the first item to the i'th item
        * Uses more memory due to storing a link for each item

*/