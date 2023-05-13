/*
*/

#include <iostream>

#define NEWLINE cout<<endl;
#define LOCATION_STAMP "("<<__FILE__<<":"<<__FUNCTION__<<":"<<__LINE__<<")"
#define PRINT(X) cout << LOCATION_STAMP << " " << #X << " = " << X << endl;

using std::cout, std::endl;

/*
* Functions (review)
    + Pass By Reference
    + Pass by Pointer Value
    + Memory Diagram
* Pointer Review
* Allocation and Deallocation
    + new
    + delete
        - #define deallocate delete
* Memory Leaks
*/

void pass_by_value(int x) {
    PRINT(x);
    x *= 2;
    PRINT(x);
}

void pass_by_reference(int& x) {
    PRINT(x);
    x *= 2;
    PRINT(x);
}

void pass_by_pointer_value(int* x) {
    PRINT(x);
    PRINT(*x);
    *x *= 2;
    PRINT(x);
    PRINT(*x);
    x++;
    PRINT(x);
    PRINT(*x);
    *x += 1;
    PRINT(x);
    PRINT(*x);
}

void pass_by_pointer_reference(int*& x) {
    PRINT(x);
    PRINT(*x);
    *x *= 2;
    PRINT(x);
    PRINT(*x);
    x++;
    PRINT(x);
    PRINT(*x);
    *x += 1;
    PRINT(x);
    PRINT(*x);
}

void function_arg_type_example() {
    int a = 1;
    int b = 10;
    int c = 100;
    int* d = new int{1000};
    int* e = new int{10000};
    PRINT(a);
    PRINT(b);
    PRINT(c);
    PRINT(d);
    PRINT(*d);
    PRINT(e);
    PRINT(*e);
    
    NEWLINE
    
    PRINT(a);
    pass_by_value(a);
    PRINT(a);
    
    NEWLINE
    
    PRINT(b);
    pass_by_reference(b);
    PRINT(b);
    
    PRINT(a);
    
    NEWLINE
    
    PRINT(&c);
    PRINT(*(&c));
    pass_by_pointer_value(&c);
    PRINT(&c);
    PRINT(*(&c));
    
    PRINT(a);
    
    NEWLINE
    
    PRINT(d);
    PRINT(*d);
    pass_by_value(*d);
    PRINT(d);
    PRINT(*d);
    
    PRINT(a);
    
    NEWLINE
    
    PRINT(d);
    PRINT(*d);
    pass_by_pointer_value(d);
    PRINT(d);
    PRINT(*d);
    
    PRINT(a);
    
    NEWLINE
    
    PRINT(e);
    PRINT(*e);
    pass_by_pointer_reference(e);
    PRINT(e);
    PRINT(*e);
    
    NEWLINE
    
    PRINT(a);
    PRINT(b);
    PRINT(c);
    PRINT(d);
    PRINT(*d);
    PRINT(e);
    PRINT(*e);
    
    delete d;
    e--; // have to fix what the last function call broke
    PRINT(e);
    PRINT(*e);
    delete e;
    
    NEWLINE
}

void pointer_review() {
    cout << "this is a pointer to an int:" << endl << endl;
    cout << "    int* pointer_to_int;" << endl << endl;
    int* pointer_to_int;
    
    cout << "a pointer is an ADDRESS and a TYPE" << endl;
    cout << "this pointer's TYPE is int (the datatype of the pointer itself is \"pointer to int\")" << endl;
    cout << "this pointer's ADDRESS is uninitialized, so the value is garbage. (the address of the pointer itself, on the stack, is "<< (&pointer_to_int) <<", but that's not very interesting or important right now)" << endl << endl;
    
    cout << "this is an int:" << endl << endl;
    cout << "    int integer = 4138;" << endl << endl;
    int integer = 4138;
    cout << "this is the address of the int (on the stack):" << endl << endl;
    cout << "    " << &integer << endl << endl;
    cout << "this assigns the address of that int to the pointer variable:" << endl << endl;
    cout << "    pointer_to_int = &integer;" << endl << endl;
    pointer_to_int = &integer;
    cout << "now, the value of the pointer is: " << endl << endl;
    cout << "    " << pointer_to_int << endl << endl;
    
    cout << "we can \"dereference\" the pointer variable to get a reference to the int to which it points:"<< endl << endl;
    cout << "    int& reference_to_int = *pointer_to_int;" << endl << endl;
    int& reference_to_int = *pointer_to_int;
    cout << "the value to which this reference refers is the value of the integer:" << endl << endl;
    cout << "    reference_to_int := " << reference_to_int << endl;
    cout << "    integer := " << integer << endl << endl;
    
    cout << "if we change the value of integer" << endl << endl;
    cout << "    integer = 130;" << endl << endl;
    integer = 130;
    cout << "then we see:" << endl << endl;
    cout << "    reference_to_int := " << reference_to_int << endl;
    cout << "    *pointer_to_int := " << *pointer_to_int << endl << endl;
    
    cout << "likewise, if we change the value to which the pointer points" << endl << endl;
    cout << "    *pointer_to_int = 121;" << endl << endl;
    *pointer_to_int = 121;
    cout << "then we see:" << endl << endl;
    cout << "    reference_to_int := " << reference_to_int << endl;
    cout << "    integer := " << integer << endl << endl;

    cout << "the memory diagram looks something like this:" << endl << endl;
    cout << "+-- reference_to_int | & (not actually stored on the stack)" << endl;
    cout << "|                    |" << endl;
    cout << "+----------> integer | " << integer << " <----------------+" << endl;
    cout << "                     |                      |" << endl; 
    cout << "      pointer_to_int | * (" << pointer_to_int << ") --+" << endl;
    cout << "      _______________|___________________" << endl << endl;
    
    cout << "in the context of a memory diagram, dereferencing a pointer means following the arrow from the pointer's address to the value to which the pointer points (the value at the address stored in the pointer variable)." << endl << endl;
}

void dynamic_allocation() {
    cout << "this is an int on the stack:" << endl << endl;
    cout << "    int on_the_stack = 111;" << endl << endl;
    int on_the_stack = 111;

    cout << "this is an int on the heap:" << endl << endl;
    cout << "    new int{222};" << endl << endl;

    cout << "except, as written, we don't have a way to refer to the int on the heap!" << endl << endl;
    cout << "new dynamically allocates memory on the heap and returns a pointer to the memory" << endl;
    cout << "so, as with any return value, we need to either use the value immediately, store it for later, or we lose it." << endl << endl;
    cout << "let's use it! (by printing it)" << endl << endl;
    cout << "    new int{222} := " << new int{222} << endl << endl;
    cout << "again! again!" << endl << endl;
    cout << "    new int{222} := " << new int{222} << endl;
    cout << "    new int{222} := " << new int{222} << endl << endl;

    // OH NO.... so many leaks!   oh well...
    // sanitizers will complain, but we're learning
    
    cout << "note that the address is different each time." << endl << endl;
    
    cout << "now, let's store the value so we can use it later" << endl << endl;
    cout << "    int* on_the_heap = new int{222};" << endl << endl;
    int* on_the_heap = new int{222};
    
    cout << "we can dereference to read:" << endl << endl;
    cout << "    *on_the_heap := " << *on_the_heap << endl << endl;
    
    cout << "and to modify:" << endl << endl;
    cout << "    *on_the_heap = 19;" << endl;
    *on_the_heap = 19;
    cout << "    *on_the_heap := " << *on_the_heap << endl << endl; 
    
    cout << "the memory diagram looks something like this:" << endl << endl;
    cout << " on_the_heap | * (" << on_the_heap << ") ----------> " << *on_the_heap << endl;
    cout << "             |" << endl; 
    cout << "on_the_stack | " << on_the_stack << endl;
    cout << "_____________|___________________" << endl;
    cout << "  variables       stack                     heap" << endl << endl;
}

/*
    STACK & HEAP
    areas of memory
    stack: working memory for use by functions, managed by the compiler, instructions written at compile time
    heap: dynamically allocated memory, for use by programmer, managed by programmer, allocation and deallocation depends on code (at runtime)
    0x0                       0x7f
    +-----------...--------------+
    | HEAP -->         <-- STACK |
    +-----------...--------------+ 
    +-------+ 0x7f
    | STACK |
    |   |   |
    |   |   |
    |   v   |
    .       .
    .       .
    .       .
    |   ^   |
    |   |   |
    |   |   |
    | HEAP  |
    +-------+ 0x0
*/


void deallocation() {
    cout << "unlike stack-allocated variables, which are managed by the compiler (instructions for allocation and deallocation written at compile time based on the number and types of parameters and local variables), heap-allocated memory must be managed by the programmer (i.e. YOU)." << endl << endl;
    
    cout << "the rule is: if you allocate it, you (eventually) delete it." << endl << endl;
    
    cout << "deallocation is done using the \"delete\" keyword." << endl;
    cout << "delete tells the operating system that the program is done with a piece of memory and that the memory is now free to be reallocated by some request for memory that may come later." << endl << endl;
    
    cout << "allocating memory looks like this:" << endl << endl;
    cout << "    int* four_bytes = new int;" << endl << endl;
    int* four_bytes = new int;
    
    // now we can make the sanitizer happy (and do the right thing, anyways)
    cout << "deallocating memory looks like this:" << endl << endl;
    cout << "    delete four_bytes;" << endl << endl;
    delete four_bytes;
    
    cout << "every new must have a corresponding delete." << endl;
    cout << "it is the programmer's responsibility to ensure that all dynamically allocated memory is freed before the program ends." << endl;
    
    
}

void memory_leaks() {
    cout << "what happens if you don't delete memory you allocated?" << endl << endl;
    cout << "your program leaks memory, that's what!" << endl << endl;
    
    cout << "memory is said to be leaked when the last reference to the memory (the last variable which stores the address of the memory) goes out of scope." << endl << endl;
    
    cout << "memory which is leaked cannot be reallocated;  it is marooned, all alone, on the heap, waiting until the program ends and the OS reclaims all memory allocated to the program." << endl << endl;
    
    cout << "if too much memory is in use (or leaked), the program will crash, possibly the entire machine (though this is less likely in modern OSes" << endl << endl;
    
    cout << "here are two pieces of memory:" << endl << endl;
    cout << "    int* this_is_leaked = new int;" << endl;
    cout << "    int* this_is_NOT_leaked = new int;" << endl << endl;
    int* this_is_leaked = new int;
    int* this_is_NOT_leaked = new int;
    PRINT(this_is_leaked)
    PRINT(this_is_NOT_leaked)
    NEWLINE
    
    cout << "preventing memory leaks is simple: when you are done with memory that you have previously allocated on the heap, delete it." << endl << endl;
    cout << "you must delete (deallocate) it before you lose access to the address." << endl;
    cout << "you must NOT delete (deallocate) it until AFTER you are done using it." << endl;
    cout << "if you attempt to use memory that you have deallocated after you deallocate it, bad things can happen.  this is called \"use after free\"." << endl << endl;
    cout << "you must also NOT delete the same memory twice. exactly once is exactly enough." << endl;
    cout << "if you try to delete memory that has already been deleted, this is called \"double free\" and bad things can happen." << endl << endl;
    
    cout << "to prevent use after free and double free when a variable which holds the address of the memory is still in scope, you can set the value to nullptr." << endl;
    cout << "attempts to dereference (use) the nullptr will segfault and crash (preferable to the bad things that can happen with use after free, and easier to debug, too)." << endl;
    cout << "attempts to delete the nullptr will be ignored.  the nullptr is the only address which can be safely deallocated multiple times (because it cannot be deallocated at all so deallocations of it are ignored: saftey by inaction)" << endl << endl;
    
    cout << "let's delete one of our allocations, but leave the other to be leaked:" << endl << endl;
    cout << "    delete this_is_NOT_leaked;" << endl << endl;
    delete this_is_NOT_leaked;
    //delete this_is_leaked;
    cout << "we'll run this program through valgrind (or compile with Address Sanitizer, but NOT both) and verify that the other block of memory got leaked." << endl << endl;
    
    cout << "valgrind instructions:" << endl << endl;
    cout << "    1. compile normally" << endl << endl;
    cout << "        g++ -std=c++17 -Wall -Wextra -Weffc++ -pedantic -g notes.cpp" << endl << endl;
    cout << "    2. run the executable through valgrind" << endl << endl;
    cout << "        valgrind --leak-check=full ./a.out" << endl << endl;
    
    cout << "Sanitizer instructions:" << endl << endl;
    cout << "    1. compile with Address Sanitizer flag" << endl << endl;
    cout << "        g++ -std=c++17 -Wall -Wextra -Weffc++ -pedantic -g -fsanitize=address notes.cpp" << endl << endl;
    cout << "    2. run the executable normally" << endl << endl;
    cout << "        ./a.out" << endl << endl;
}

int main() {
    // `make unsanitized && ./unsanitized_notes`
    function_arg_type_example();

    //pointer_review();
    /*
    int - value type
    int& - reference type
    int* - pointer type
    &var - "address of"
    *pointer - "dereference"
    */

    dynamic_allocation();
    deallocation();
    memory_leaks();

    return 0;
}


/*
int x;
int* y;
int z = x**y; // x * (*y)
*/