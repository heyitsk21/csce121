#include <iostream>
using std::cout, std::endl;

void avgMatrix (double** inArray, int rows, int columns, double** outArray){
    if (rows < 1 || cols < 1){
        cout<<"INVALID: Row/Col too small"<<endl;
    }

    double sum = 0;
    int nums = 0;
    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            if ()

            // if (r-1 >= 0 && r+1 < rows){ //top left
            //     if (c-1 >= 0 && c+1 < cols){
                    
            //     } 
                
            // } 
            // if (r-1 >= 0){             //top mid
            //     sum+=inArray[r-1][c];
            //     nums++;
            // }
            // if (r-1 >= 0 && c+1 >= 0){ //top right
            //     sum+=inArray[r-1][c+1];
            //     nums++;
            // }
            outArray[r][c] = sum/nums;
        }
    }
}
void print(const double& matrix) {
  int i, j;
  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 4; ++j)
      printf("%d ", matrix[i][j]);
    printf("\n");
  }
}

int main() {
    double** inArray = new double*[3];
    double* row0 = new double[4] {.5,2,1.2,3};
    double* row1 = new double[4] {-1,1.5,3,2.4};
    double* row2 = new double[4] {0,1,1.5,2};
    inArray[0] = row0;
    inArray[1] = row1;
    inArray[2] = row2;

    double** outArray = new double*[3];
    for (int row = 0; row < 3; row++){
        outArray[row]= new double[4];
    }

    cout<<"inArray: "<<endl;
    print(inArray);
    cout<<endl;
    cout<<"outArray: "<<endl;
    print(outArray);
    cout<<endl;
    avgMatrix(inArray, 3, 4, outArray);
    cout<<"inArray: "<<endl;
    print(inArray);
    cout<<endl;
    cout<<"outArray: "<<endl;
    print(outArray);
    cout<<endl;

    if (inArray){
        for (int row = 0; row < 3; row++){
            delete[] inArray[row];
        }
        delete[] inArray;
    }
    if (outArray){
        for (int row = 0; row < 3; row++){
            delete[] outArray[row];
        }
        delete[] outArray;
    }
    return 0;
}