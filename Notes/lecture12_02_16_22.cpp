/* agenda
    traversing arrays
        "traverse"
        basic structure of a traversal
    arrays and pointers
        array parameters in functions
            arrays decay to pointers
        access: offset and dereference
    memory safety
        access out of bounds --> undefined / segfault
        read uninitialized memory --> undefined
    2D arrays
        declare, define, initialize
        access
        traverse
        as function parameter
*/

/* Objectives
    1) read and write C++ code to traverse an array
    2) explain the relationship between arrays and pointers in C++
    3) identify memory safety concerns involving arrays
    4) read and write C++ code to ensure memory saftey with arrays
    5) explain 2D arrays 
    6) read and write C++ code to create, initialize, and access stack-allocated 2D arrays
    *7) read and write C++ code that uses pointers to traverse arrays
*/

/* Traversing Arrays
    * "traverse" := go through each element in [some] order
    
    * recipe
    
    const unsigned int size = 7;
    int A[size] = {8,6,7,5,3,0,9};
    for (unsigned int index = 0; index < size; index++) {
        // process A[index]
    }
    
    * example: linear search
    
    procedure linear-search
    inputs:
        A: {a1, ..., an}, array of n integers
        k: value being searched for
    output: index of k in A, or -1 if not found
    
    for i from 1 to |A| do
        e <- element at index i in A
        if e = k then
            return i // found at index i
        end
    end
    return -1 // not found
*/

/* Arrays and Pointers
    * Recall:
    + arrays "are" pointers
    + arrays don't know their own size --> arrays don't do bounds-checking
    + int A[20]; defines an array with space for 20 integers
        - 80 bytes, referenced by A, value/address of A is the address of first element of A
    + A[15] accesses the element at index 15 in A (no bounds checking!)
    
    * Array access using pointers --> Offset and Dereference
    + A[index] --> *(A + index)
    + A[15] --> *(A + 15)
    + 15[A] --> *(15 + A)
    
    * Pointer Arithmetic
    + A[15] --> *(A + 15)
    + typeid(A) => (not really, but basically) Pi  // Pointer to int
    + typeid(15) => i  // int
    + A + 15 --> <Pi> + <i> --> <Pi> + sizeof(int)*<i> --> <Pi>
        - the integer offset is multiplied by the size of type to get the byte offset, yielding a new address
    suppose int A[10] is "at" 0x7fffff00
    A[0] is at 0x7fffff00 + 4*0 = 0x7fffff00
    A[1] is at 0x7fffff00 + 4*1 = 0x7fffff04
    A[2] is at 0x7fffff00 + 4*2 = 0x7fffff08
    A[3] is at 0x7fffff00 + 4*3 = 0x7fffff0c
    ...
    A[9] is at 0x7fffff00 + 4*9 = 0x7fffff24
                            ^
                            because type is int
                            sizeof(int) --> 4
                            
    it is like...
    you write: int* p = A + 5; // bytes + element-size
    compiler writes: byte* p = A + 20; // bytes + bytes
    the units of a pointer value is bytes
    the units of an index value is element-size = sizeof(type)
    for int A[], A[index] means A + index elements
        e.g. A[5] means A + 5 ints = A + 20 bytes
*/

/* Arrays as function parameters
    int A[10];
    // all of these are OK:
    void foo(int A[10]) {} // only accepts int arrays of size 10? nope. can take an int array of any size!
    void bar(int A[]) {} // can take an int array of any size
    void baz(int* A) {} // can take an int array of any size
    // Q: what's up with baz(int*)?
    // A: arrays "decay" to pointers
        arrays are not "merely" pointers
        arrays are pointer (address + type) + capacity
        array decay to pointer loses the capacity part
        ... so does bar(int A[])!!!
        ... so does foo(int A[10])!!!!!
        
    // you should try this at home
    void foo(int A[10]) {
        cout << sizeof(A)/sizeof(A[0]) << endl;
    }
    void bar(int A[]) {
        cout << sizeof(A)/sizeof(A[0]) << endl;
    }
    void baz(int* A) {
        cout << sizeof(A)/sizeof(A[0]) << endl;
    }
    int main() {    
        int A[5];
        foo(A);
        bar(A);
        baz(A);
    }
    compiler:
    warning: ‘sizeof’ on array function parameter ‘A’ will return size of ‘int*’ [-Wsizeof-array-argument]
    stdout:
    2
    2
    2
    // Q: why 2?
    // A: sizeof(int*) --> 8
    //    sizeof(int) --> 4
    //    typeid(A) --> Pi "pointer to int" / int*
    // Q: is there any hope?
    // A: sortof.
    // this one expects a reference to an array of 10 ints and so REALLY only accepts int arrays of size 10
    void foo2(int(&A)[10]) {
        cout << sizeof(A)/sizeof(A[0]) << endl;
    }
    // const version
    void foo2(const int(&A)[10]) {
        cout << sizeof(A)/sizeof(A[0]) << endl;
    }
    // this is a parametrically polymorphic function ("function template") that can be used to accept an int array of any size and retain access to the size data
    template <typename T>
    void bar2(T& A) {
        cout << sizeof(A)/sizeof(A[0]) << endl;
    }
    * pass by value does NOT copy the array
    + pass array by value --> pass a pointer value
    + pass array by reference --> pass a pointer reference (sort of)
    + essentially the same thing
        - contents can be changed
        - value of array (address) cannot be changed
        * pointer value: it's a copy, modifications don't affect original
        * array reference: references can only be assigned once --> int[] is not assignable
        - PbR includes capacity information
    void foo(int A[]) {
        A[0] = 8;
        A[1] = 6;
        A[2] = 7;
        A[3] = 5;
        A[4] = 3;
        A[5] = 0;
        A[6] = 9;
    }
    int main() {
        int A[7];
        for (int i = 0; i < 7; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
        foo(A);
        for (int i = 0; i < 7; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    4196752 0 4196160 0 1484185120 32767 0 
    8 6 7 5 3 0 9
*/

/* Memory Safety
    int A[10];
    A[-1]; // out of bounds --> segfault or undefined behavior
    A[10]; // out of bounds --> segfault or undefined behavior
    // try this:
    void dangerous() {
        char A[10];
        int index = 0;
        while (true) {
            cout << A[index];
            index++;
        }
    }
    int main() {
        char canary[] = "     THIS IS MAIN     ";
        dangerous();
    }
    * ALWAYS remember to guard against array access out of bounds!
*/

/* 2D arrays
    * declare/define
    //    1st     2nd
    int A[rows][columns];
    + represented in memory as a 1D array:
    
    A0,0 | A0,1 | ... | A0,columns-1 | A1,0 | A1,1 | ...
    * initialize
    // OK: both dimension defined
    int A[2][3] = {
        {1,2,3},
        {4,5,6}
        };
    // OK: 2nd dimension defined
    int B[][3] = {
        {1,2,3},
        {4,5,6}
        };
    // WRONG: 2nd dimension not defined
    //        error: array has incomplete element type 
    int C[][] = {
        {1,2,3},
        {4,5,6}
        };
    // OK: both dimensions defined
    //     all elements initialized to 0
    int D[2][3]{};
    * access
        
    A[0][0] = 1; // element in row 0 and column 0 is 1
    A[0][1] = 2; // element in row 0 and column 1 is 2
    A[1][0] = 4; // element in row 1 and column 0 is 4
    + offset and dereference (pointer arithmetic)
    std::cout << "   A = " << A << " = &A[0][0] = " << &A[0][0] << " --> " << A[0][0] << " = A[0][0]" << std::endl;
    std::cout << " A+1 = " << A+1 << " = &A[1][0] = " << &A[1][0] << " --> " << A[1][0] << " = A[1][0]" << std::endl;
    std::cout << "  *A = " << *A << " = &A[0][0] = " << &A[0][0] << " --> " << A[0][0] << " = A[0][0]" << std::endl;
    std::cout << "*A+1 = " << *A+1 << " = &A[0][1] = " << &A[0][1] << " --> " << A[0][1] << " = A[0][1]" << std::endl;
    std::cout << "*A+2 = " << *A+2 << " = &A[0][2] = " << &A[0][2] << " --> " << A[0][2] << " = A[0][2]" << std::endl;
    std::cout << "*(A+1)+2 = " << *(A+1)+2 << " = &A[1][2] = " << &A[1][2] << " --> " << A[1][2] << " = A[1][2]" << std::endl;
    A = 0x7ffec607cb20 = &A[0][0] = 0x7ffec607cb20 --> 1 = A[0][0]
    A+1 = 0x7ffec607cb2c = &A[1][0] = 0x7ffec607cb2c --> 4 = A[1][0]
    *A = 0x7ffec607cb20 = &A[0][0] = 0x7ffec607cb20 --> 1 = A[0][0]
    *A+1 = 0x7ffec607cb24 = &A[0][1] = 0x7ffec607cb24 --> 2 = A[0][1]
    *A+2 = 0x7ffec607cb28 = &A[0][2] = 0x7ffec607cb28 --> 3 = A[0][2]
    *(A+1)+2 = 0x7ffec607cb34 = &A[1][2] = 0x7ffec607cb34 --> 6 = A[1][2]
        the type of A is "array of 2 arrays of 3 ints"
            A is pointer to array of 3 ints
        the type of *A is "array of 3 ints"
            A[index] is pointer to int
        sizeof("array of 3 ints") = 3*sizeof(int) = 12
        thats why "A + index" jumps down the column (rows)
        and why "*A + index" goes across the row (columns)
    + 2 dimensions mapped to 1:
    std::cout << "*A+4 = " << *A+4 << " = &A[0][4] = " << &A[0][4] << " --> " << A[0][4] << " = A[0][4]" << std::endl;
    std::cout << "     = " << *A+4 << " = &A[1][1] = " << &A[1][1] << " --> " << A[1][1] << " = A[1][1]" << std::endl;
    *A+4 = 0x7ffec607cb30 = &A[0][4] = 0x7ffec607cb30 --> 5 = A[0][4]
        = 0x7ffec607cb30 = &A[1][1] = 0x7ffec607cb30 --> 5 = A[1][1]
    
    index(row,col) = row*columns + col
    * traversal
    int A[rows][columns];
    // 1st dimension-major order, e.g. row-major
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            // process A[row][column]
        }
    }
    // 2nd dimension-major order, e.g. column-major
    for (int column = 0; column < columns; column++) {
        for (int row = 0; row < rows; row++) {
            // process A[row][column]
        }
    }
    // pointer arithmetic as 1D array (row-major order)
    // V1
    for (int i = 0; i < 6; i++) {
        // process (*A)[i] --> A[i/columns][i%columns]
        cout << (*A)[i] << endl;
    }
    // V2
    int* p = *A;   // like "int p[] = *A;"
    for (int i = 0; i < 6; i++) {
        // process p[i] = *(p+i) --> A[i/columns][i%columns]
    }
    * as function parameter  
    + must specify all dimensions (except first is optional)
    // OK
    void foo(int A[2][3]) {}
    // OK
    void bar(int A[][3]) {}
    // WRONG: error: declaration of ‘A’ as multidimensional array must have bounds for all dimensions except the first
    void baz(int A[2][]) {}
    int main() {
        int A[2][3];
        foo(A);
        bar(A);
        baz(A);
    }
*/

#include <iostream>

using std::cout, std::endl;

int main() {

    return 0;
}