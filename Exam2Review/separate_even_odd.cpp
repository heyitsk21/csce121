#include <iostream>
using std::cout, std::endl;

void print1d(int* matrix, unsigned int n) {
  unsigned int i;
  for (i = 0; i < n; ++i) {
    printf("  %d  ", matrix[i]);
  }
}

int* separate_even_odd(int* A, unsigned int n){
    unsigned int count = 0;
    int* B = new int[n];
    for (unsigned int index = 0; index < n; index++){
        if (A[index] % 2 == 0){
            B[count] = A[index];
            count++;
        } else if (A[index] %2 != 0){
            B[count] = A[index];
            count++;
        }
    }

    return B;
}

int main() {
    unsigned int n = 5;
    int* arr = new int[n] {0,3,7,6,8};

    cout<<"before: "<<endl;
    print1d(arr,n);
    cout<<endl<<endl;
    
    int* newArr = separate_even_odd(arr,n);
    cout<<"new array: "<<endl;
    print1d(newArr,n);
    cout<<endl<<endl;

    cout<<"after: "<<endl;
    print1d(arr,n);
    cout<<endl<<endl;

    if (arr){
        delete[] arr;
    }
    if (newArr){
        delete[] newArr;
    }
    return 0;
}