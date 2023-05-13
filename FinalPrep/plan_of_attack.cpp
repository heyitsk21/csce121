/*

Explode
- iterate through the array.
- every time you encounter an element, resize to (currSize + the value at that index)
    - have an index start from 0 up to the value
    - whatever that value is, keep inserting it at 
    - have
    - nested for loop
        - first loop goes through the original array size (before edits)
        - second loop adds the 

*/
#include <iostream>
#include <stdexcept>
using std::cout, std::endl;
void explode(unsigned int *&array, size_t &size) {
    size_t newSize = 0;
    for (unsigned int i = 0; i<size; ++i){
        // if (array[i] < 0){
        //     throw std::invalid_argument("Cannot have negative numbers");
        // }
        newSize += array[i];
    }
    cout<<"newSize: "<<newSize<<endl;
    unsigned int* myArr = new unsigned int[newSize];

    int count = 0;
    for (size_t original = 0; original < size; ++original){
        //count = array[original];
        //while (count != 0){
            for (size_t newIndex = 0; newIndex < array[original]; ++newIndex){
                myArr[count] = array[original];
                count++;
            }
        //}
    }

    //WHAT DOES IT DO WHEN THERE IS A VALUE OF 0

    delete[] array;
    array = myArr;
    size = newSize;
}

// void print(unsigned int *&array, size_t &size){
//     for (int i = 0; i < size; ++i){
//         cout << array[i] << ", ";
//     }
//     cout << endl;
// }
int main(){
    size_t size = 3;
    unsigned int* originalArr = new unsigned int[size];
    originalArr[0] = 3;
    originalArr[1] = 1;
    originalArr[2] = 3;

    //print(originalArr, 3);
    cout << "original array: "<< endl;
    for (int i = 0; i < 3; ++i){
        cout << originalArr[i] << ", ";
    }
    cout << endl;


    explode(originalArr, size);


    //print(originalArr, )
    cout << "new array: "<< endl;
    for (int i = 0; i < 7; ++i){
        cout << originalArr[i] << ", ";
    }
    cout << endl;

    delete[] originalArr;
    return 0;
}