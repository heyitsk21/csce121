#include <iostream>
using std::cout, std::endl;

void print2d(int** matrix) {
  int i, j;
  for (i = 0; i < 5; ++i) {
    for (j = 0; j < 5; ++j)
      printf("  %d  ", matrix[i][j]);
    printf("\n");
  }
}

void print1d(int* matrix) {
  int i;
  for (i = 0; i < 5; ++i) {
    printf("  %d  ", matrix[i]);
  }
}

void minusOddColumn(int** mat, int n){
    //int numOddPrev = 0;
    int numOddCurr = 0;
    //int colWithMostOdd = 0;

    int* smallarray = new int[n];
    for (int index = 0; index < n; index++){
        smallarray[index] = 0;
    }

    for(int col = 0; col < n; col++){
        for (int row = 0; row < n; row++){
            if (mat[row][col] % 2 != 0){
                numOddCurr++;
            }
        }
        smallarray[col]=numOddCurr;
        numOddCurr = 0;
        // if (numOddPrev < numOddCurr){
        //     colWithMostOdd = col;
        //     numOddPrev = numOddCurr;
        //     numOddCurr = 0;
        // } else {
        //     numOddCurr = 0;
        // }
    }

    int max = smallarray[0];
    int maxCol = 0;
    for (int index = 0; index < n; index++){
        if (smallarray[index] > max){
            max = smallarray[index];
            maxCol = index;
        }
    }

    for(int col = maxCol; col < maxCol+1; col++){
        for (int row = 0; row < n; row++){
            mat[row][col] = -1;
        }
    }

    cout<<"small array: "<<endl;
    print1d(smallarray);
    cout<<endl<<endl;


    if (smallarray){
        delete[] smallarray;
    }
}

int main() {
    int** bigarray = new int*[5]; 
    
    int* arr0 = new int[5] {0,30,10,70,10};
    int* arr1 = new int[5] {30,0,45,100,50};
    int* arr2 = new int[5] {10,45,0,85,20};
    int* arr3 = new int[5] {70,100,85,0,100};
    int* arr4 = new int[5] {10,50,20,100,0};

    bigarray[0] = arr0;
    bigarray[1] = arr1;
    bigarray[2] = arr2;
    bigarray[3] = arr3;
    bigarray[4] = arr4;
    cout<<"before: "<<endl;
    print2d(bigarray);
    cout<<endl;

    minusOddColumn(bigarray,5);

    cout<<"after: "<<endl;
    print2d(bigarray);
    cout<<endl;

    if (bigarray) {
        for (int row = 0; row < 5; row++) {
            delete[] bigarray[row];
        }
        delete[] bigarray;
    }

    return 0;
}
