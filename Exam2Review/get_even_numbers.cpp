#include <iostream>
using std::cout, std::endl;

void print1d(int* matrix, unsigned int n) {
  unsigned int i;
  for (i = 0; i < n; ++i) {
    printf("  %d  ", matrix[i]);
  }
}

int* get_even_numbers(int* A, unsigned int n, unsigned int& m){
    unsigned int count = 0;
    
    for (unsigned int index = 0; index < n; index++){
        if (A[index] % 2 == 0){
            //evenNums[count] = A[index];
            count++;
        }
    }
    m = count;
    unsigned int holder = 0;

    int *evenNums = new int[m];
    for (unsigned int index = 0; index < n; index++){
        if (A[index] % 2 == 0){
            if (holder >= m){
                break;
            }
            evenNums[holder] = A[index];
            holder += 1;
        }
    }

    return evenNums;
}

int main() {
    unsigned int n = 5;
    int* arr = new int[n] {0,3,7,6,8};
    unsigned int m = 0;

    cout<<"before: "<<endl;
    print1d(arr,n);
    cout<<endl<<endl;
    
    // int* newArr = new int[n];
    // newArr = get_even_numbers(arr,n,m);
    int* newArr = get_even_numbers(arr,n,m);
    cout<<"new array: "<<endl;
    print1d(newArr,m);
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