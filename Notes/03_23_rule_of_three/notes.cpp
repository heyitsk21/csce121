/*
    Memory Diagram with Class
    The Rule of Three := "if you need one, you need all three."
        Copy Constructor - make deep copies
        Copy Assignment Operator - make deep copies and prevent memory leaks
        Destructor - prevent memory leaks
    RAII revisited - the constructor is responsible for aquiring memory, the destructor is responsible for releasing memory
    (resource acquisition is initiallized)
*/

#include <iostream>

using std::cout, std::endl;

class String {
    size_t _capacity;
    size_t _size;
    char* _data;

    public:
    String() : _capacity{10}, _size{0}, _data{new char[10]{}} {}

    // what happens if the rule of 3 is missing?
    //   or, as in this case, does not do the right thing
    String(const String& rhs) : _capacity{rhs._capacity}, _size{rhs._size}, _data{rhs._data} {
        cout << "String copy constructor invoked" << endl;
    }

    ~String() {
        cout << "String destructor invoked." << endl;
        delete[] _data;
    }

    String& operator=(const String& rhs) {
        cout << "String copy assignment operator invoked" << endl;
        _capacity = rhs._capacity;
        _size = rhs._size;
        _data = rhs._data;
        return *this;
    }
};

class Object {
    int x;
    String s;
    int* p;

    public:
    Object() : x{}, s{}, p{new int{}} {}

    // copy constructor
    Object(const Object& rhs) : x{rhs.x}, s{rhs.s}, p{new int{*rhs.p}} {
        cout << "Object copy constructor invoked" << endl;
    }

    // destructor --> TILDE[class name]
    ~Object() {
        cout << "Object destructor invoked" << endl;
        // deallocate any memory that was allocated at construction
        delete p;
        // s will get destructed by String destructor
    }

    // copy assignment operator //makes a DEEP COPY and PREVENTS LEAKS
    Object& operator=(const Object& rhs) {
        cout << "Object copy assignment operator invoked" << endl;
        // 1. self-assignment check
        if (this != &rhs) { //this object does not equal address of rhs
            // 2. deallocate memory that was allocated at construction
            delete p;
            // 3. allocate memory
            p = new int;
            // 4. copy values
            x = rhs.x;
            s = rhs.s; // copy handled by String copy assignment operator
            *p = *rhs.p;
        }
        // finally. return a reference to this object
        return *this;
    }
};

int main() {
    Object obj;
    Object* p_obj = new Object;

    /*
    function | var   | value on stack                 heap
    ---------|-------|----------------------------    -------------------------------------------------------------------------------------------
    main     | obj   | |---|--------------------|          |----|----|----|----|----|----|----|----|----|----|
             |       | | x | 0                  |     |--->| \0 | \0 | \0 | \0 | \0 | \0 | \0 | \0 | \0 | \0 |
             |       | |---|--------------------|     |    |----|----|----|----|----|----|----|----|----|----|
             |       | | s | |-----------|----| |     |
             |       | |   | | _capacity | 10 | |     |          |---|--------------------|
             |       | |   | |-----------|----| |     |       |->| x | 0                  |
             |       | |   | | _size     | 0  | |     |       |  |---|--------------------|
             |       | |   | |-----------|----| |     |       |  | s | |-----------|----| |
             |       | |   | | _data     | *----------|       |  |   | | _capacity | 10 | |    
             |       | |   | |-----------|----| |             |  |   | |-----------|----| |
             |       | |---|--------------------|      |---|  |  |   | | _size     | 0  | |
             |       | | p | *------------------------>| 0 |  |  |   | |-----------|----| |   |----|----|----|----|----|----|----|----|----|----|
             |       | |---|--------------------|      |---|  |  |   | | _data     | *------->| \0 | \0 | \0 | \0 | \0 | \0 | \0 | \0 | \0 | \0 |
             |       |                                        |  |   | |-----------|----| |   |----|----|----|----|----|----|----|----|----|----|
             | p_obj | *--------------------------------------|  |---|--------------------|   |---|
    ---------|-------|----------------------------               | p | *--------------------->| 0 |
                                                                 |---|--------------------|   |---|
    */

    // copy by construction
    Object obj_copy = obj;

    // copy by assignment
    obj_copy = *p_obj;

    /*
    Integer a = 1;
    Integer b = 2;
    b = a;
              copy
          deep  | shallow
       ---------+---------
          +---+ |    +---+
       a->| 1 | | a->| 1 |
          +---+ |    +---+
                |      ^
          +---+ |      |
       b->| 1 | | b----+
          +---+ |
    shallow copy:
        generally not desirable
        two variables refer to the same object (or part(s) of it)
        updates to a affect b (and vice versa)
    deep copy:
        generally what is meant by "copy"
        two variables refer to two distinct objects with the same values
        updates to a do not affect b
    */

    return 0;
}