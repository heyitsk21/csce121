/*
* Dynamically Allocated Arrays
    + 1D
    + 2D (1D array of 1D arrays)
* (Dynamically Allocated) Arrays as Function Parameters
    + Contrast with Stack-Allocated, esp. 2D arrays
*/

#include <iostream>

#define PRINT(X) cout << "("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << endl;

using std::cout, std::endl;

// int* A or int A[]
void takes_1d_array(int A[], size_t size) {
    if (A) {
        cout << A[0] << endl;
    } else {
        cout << "[]" << endl;
    }
}

void takes_2d_stack_array(int A[][5], size_t rows) {
    if (A) {
        cout << A[0][0] << endl;
    } else {
        cout << "[][]" << endl;
    }
}


// int** A or int* A[]
void takes_2d_heap_array(int* A[], size_t rows, size_t cols) {
    //cout << sizeof(A) << endl;
    //cout << sizeof(*A) << endl; // 8. ~~or 20?~~
    //cout << sizeof(**A) << endl;
    if (A) {
        cout << A[0][0] << endl;
    } else {
        cout << "[][]" << endl;
    }
}


void dynamically_allocated_arrays() {
    // 1D array
    int* array_1d = new int[12]{1};
    // this can be a variable^  ^
    // initialization-----------|
    // 1st element is 1, rest are 0
    
    
    // 2D array
    int rows = 3;
    int cols = 5;
    int** array_2d = new int*[rows]{};
    for (int row = 0; row < rows; row++) {
        array_2d[row] = new int[cols]{3};
    }
    
    
    // stack
    // 1d
    int A[12] = {2};
    // 2d
    int A2[][5]{{},{},{}};
    int A3[5][5]{{5}};
    
    takes_1d_array(array_1d, 12);
    takes_1d_array(A, 12);
    
    takes_2d_heap_array(array_2d, rows, cols);
    takes_2d_stack_array(A2, 3);
    takes_2d_stack_array(A3, 5);
    
    //takes_2d_stack_array(array_2d);
    //takes_2d_heap_array(A2);
    
    // deallocating dynamically-allocated arrays
    delete[] array_1d;
    
    for (int row = 0; row < rows; row++) {
        delete[] array_2d[row];
    }
    delete[] array_2d;
}

void size_of_stuff() {
    cout << "sizeof(size_t) = " << sizeof(size_t) << endl;
    cout << "size_t -> " << typeid(size_t).name() << endl;
    cout << "unsigned int -> " << typeid(unsigned int).name() << endl;
    cout << endl;
}

int main() {
    dynamically_allocated_arrays();
    //size_of_stuff();
    
    return 0;
}