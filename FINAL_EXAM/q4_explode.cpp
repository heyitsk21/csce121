/*

Explode
- iterate through the array.
- every time you encounter an element, resize to (currSize + the value at that index)
    - have an index start from 0 up to the value
    - whatever that value is, keep inserting it at ...
    - nested for loop
        - first loop goes through the original array size (before edits)
        - second loop adds the same value but that many times
    - change the size

*/
#include <iostream>
#include <stdexcept>
using std::cout, std::endl;
void explode(unsigned int *&array, size_t &size) {
    size_t newSize = 0;
    for (unsigned int i = 0; i<size; ++i){
        if (array[i] < 0){
            // this will NEVER happen because the array is made up of unsigned int -- NONNEGATIVE INTS
            throw std::invalid_argument("Cannot have negative numbers");
        }
        newSize += array[i];
    }
    //cout<<"newSize: "<<newSize<<endl;
    unsigned int* myArr = new unsigned int[newSize];

    int count = 0;
    for (size_t original = 0; original < size; ++original){
        if (array[original] != 0){
            for (size_t newIndex = 0; newIndex < array[original]; ++newIndex){
                myArr[count] = array[original];
                count++;
            }
        }
    }

    delete[] array;
    array = myArr;
    size = newSize;
}

// TESTING CODE BELOW!!!!

 int main(){
//     {
//         size_t size = 3;
//         unsigned int* originalArr = new unsigned int[size];
//         originalArr[0] = 3;
//         originalArr[1] = 1;
//         originalArr[2] = 3;

//         //print(originalArr, 3);
//         cout << "original array: ";
//         for (int i = 0; i < 3; ++i){
//             cout << originalArr[i] << ", ";
//         }
//         cout << endl;
//         cout << "oldSize: "<< size << endl;


//         explode(originalArr, size);


//         //print(originalArr, )
//         cout << "new array: ";
//         for (int i = 0; i < 7; ++i){
//             cout << originalArr[i] << ", ";
//         }
//         cout << endl;
//         cout << "newSize: " << size << endl;

//         delete[] originalArr;
//     }

//     {
//         size_t size = 3;
//         unsigned int* originalArr = new unsigned int[size];
//         originalArr[0] = 3;
//         originalArr[1] = 0;
//         originalArr[2] = 3;

//         //print(originalArr, 3);
//         cout << "original array: ";
//         for (int i = 0; i < 3; ++i){
//             cout << originalArr[i] << ", ";
//         }
//         cout << endl;
//         cout << "oldSize: "<< size << endl;

//         explode(originalArr, size);


//         //print(originalArr, )
//         cout << "new array: ";
//         for (int i = 0; i < 6; ++i){
//             cout << originalArr[i] << ", ";
//         }
//         cout << endl;
//         cout << "newSize: "<<size << endl;

//         delete[] originalArr;
//     }
     return 0;
 }