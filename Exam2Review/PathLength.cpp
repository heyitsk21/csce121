#include <iostream>

using std::cout, std::endl;

double pathLength(double** distance, int n, int* path, int m){
    // distance: n by n 2d array that position "distance[i][j]" stores the road distance in miles from city i to city j
    // path: int array with m elements that store a sequence of cities visited in a trip
        //0 <= path[i] < n for all i such that 0 <= i < m
    //n and m are greater than zero
    //returns a length in miles of the path

    // pathLength(distance=(see below), n=5, path=[0,1,2], m=3) returns 30+45 = 75
        //distance=[[0,30,10,70,10],
        //          [30,0,45,100,50],
        //          [10,45,0,85,20],
        //          [70,100,85,0,100],
        //          [10,50,20,100,0]]

    if (m < 0){
        cout<<"Invalid m"<<endl;
        return 0;
    }
    if (n < 0){
        cout<<"Invalid n"<<endl;
        return 0;
    }

    int row;
    int col;
    double totalDist;

    for (int i = 0; i < m-1; i++){
        row = path[i];
        col = path[i+1];
        totalDist += distance[row][col];
    }
    
    return totalDist;
}

int main() {
    double** bigarray = new double*[5]; 
    
    double* arr0 = new double[5] {0,30,10,70,10};
    double* arr1 = new double[5] {30,0,45,100,50};
    double* arr2 = new double[5] {10,45,0,85,20};
    double* arr3 = new double[5] {70,100,85,0,100};
    double* arr4 = new double[5] {10,50,20,100,0};

    bigarray[0] = arr0;
    bigarray[1] = arr1;
    bigarray[2] = arr2;
    bigarray[3] = arr3;
    bigarray[4] = arr4;

    int* smallarray1 = new int[3] {0,1,2};
    int* smallarray2 = new int[6] {0,1,0,3,2,0};
    double distance;
    distance = pathLength(bigarray,5,smallarray1,3);
    cout << distance << endl;
    distance = pathLength(bigarray,5,smallarray2,6);
    cout << distance << endl;

    if (bigarray) {
        for (int row = 0; row < 5; row++) {
            delete[] bigarray[row];
        }
        delete[] bigarray;
    }
    if (smallarray1) {
        delete[] smallarray1;
    }
    if (smallarray2) {
        delete[] smallarray2;
    }
    return 0;
}