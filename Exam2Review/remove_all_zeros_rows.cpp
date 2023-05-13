#include <iostream>
using std::cout, std::endl;

void print2d(int** matrix, int r, int c) {
  int i, j;
  for (i = 0; i < r; ++i) {
    for (j = 0; j < c; ++j)
      printf("  %d  ", matrix[i][j]);
    printf("\n");
  }
}

int** remove_allzeros_rows(int** matrix, int nrows, int ncols, int& new_nrows) {
    new_nrows = 0;
    bool notAZero = false;

    for (int r = 0; r < nrows; r++){
        for (int c = 0; c < ncols; c++){
            if (matrix[r][c] != 0){
                notAZero = true;
            }
        }
        if (notAZero){
            new_nrows++;
            notAZero = false;
        }
    }

    int** newMatrix = new int*[new_nrows];
    int holder = 0;
    for (int r2 = 0; r2 < nrows; r2++){
        for (int c2 = 0; c2 < ncols; c2++){
            if (holder>=new_nrows){
                break;
            }
            newMatrix[holder][c2] = matrix[r2][c2];
        }
        holder++;
    }

    return newMatrix;
}

int main() {
    int nrows = 5;
    int ncols = 5;
    int** bigarray = new int*[nrows]; 
    
    int* arr0 = new int[nrows] {0,0,0,0,0};
    int* arr1 = new int[nrows] {0,0,45,0,0};
    int* arr2 = new int[nrows] {0,45,0,85,0};
    int* arr3 = new int[nrows] {0,0,0,0,0};
    int* arr4 = new int[nrows] {0,0,0,0,0};

    bigarray[0] = arr0;
    bigarray[1] = arr1;
    bigarray[2] = arr2;
    bigarray[3] = arr3;
    bigarray[4] = arr4;

    cout<<"before: "<<endl;
    print2d(bigarray, nrows, ncols);
    cout<<endl;
    int m = 0;
    int** newArray = remove_allzeros_rows(bigarray,nrows,ncols,m);

    cout<<"after: "<<endl;
    print2d(newArray, nrows, ncols);
    cout<<endl;

    if (bigarray) {
        for (int row = 0; row < nrows; row++) {
            delete[] bigarray[row];
        }
        delete[] bigarray;
    }
    if (newArray) {
        for (int row = 0; row < m; row++) {
            delete[] newArray[row];
        }
        delete[] newArray;
    }
    return 0;
}