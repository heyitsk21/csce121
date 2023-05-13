#include "tests.h"
#include "functions.h"

namespace {
  bool test_passed = true;
}

bool remove_only_rows();
bool remove_only_columns();
bool remove_rows_and_columns();
bool keep_everything();
bool partially_out_of_bounds();
bool completely_out_of_bounds();

bool crop_tests() {
  bool test_result = true;
  
  test(remove_only_rows);
  test(remove_only_columns);
  test(remove_rows_and_columns);
  test(keep_everything);
  test(partially_out_of_bounds);
  test(completely_out_of_bounds);

  test_passed = test_result;
  
  END_TEST;
}

bool remove_only_rows() {
  /*
  before
  array :=
  |  1  2  3  4  5  6  7 |
  |  8  9 10 11 12 13 14 |
  | 15 16 17 18 19 20 21 |
  | 22 23 24 25 26 27 28 |
  | 29 30 31 32 33 34 35 |
  */
  size_t row_capacity = 5, rows = 5;
  size_t column_capacity = 7, columns = 7;
  int **array = new int *[5] {
    new int[7]{1, 2, 3, 4, 5, 6, 7}, new int[7]{8, 9, 10, 11, 12, 13, 14},
        new int[7]{15, 16, 17, 18, 19, 20, 21},
        new int[7]{22, 23, 24, 25, 26, 27, 28},
        new int[7]{29, 30, 31, 32, 33, 34, 35},
  };

  // BoundingBox bb = {1,0,3,6};
  // crop(array, row_capacity, column_capacity, rows, columns, bb);
  crop(array, row_capacity, column_capacity, rows, columns, {1, 0, 3, 6});

  /*
  after
  array :=
  |  8  9 10 11 12 13 14 |
  | 15 16 17 18 19 20 21 |
  | 22 23 24 25 26 27 28 |
  */
  expect(row_capacity to_be 3);
  expect(column_capacity to_be 7);
  expect(rows to_be 3);
  expect(columns to_be 7);
  expect(array[0][0] to_be 8);
  expect(array[0][6] to_be 14);
  expect(array[2][0] to_be 22);
  expect(array[2][6] to_be 28);

  delete[] array[0];
  delete[] array[1];
  delete[] array[2];
  delete[] array;

  END_TEST;
}

bool remove_only_columns() {
  /*
  before
  array :=
  |  1  2  3  4  5  6  7 |
  |  8  9 10 11 12 13 14 |
  | 15 16 17 18 19 20 21 |
  | 22 23 24 25 26 27 28 |
  | 29 30 31 32 33 34 35 |
  */
  size_t row_capacity = 5, rows = 5;
  size_t column_capacity = 7, columns = 7;
  int **array = new int *[5] {
    new int[7]{1, 2, 3, 4, 5, 6, 7}, new int[7]{8, 9, 10, 11, 12, 13, 14},
        new int[7]{15, 16, 17, 18, 19, 20, 21},
        new int[7]{22, 23, 24, 25, 26, 27, 28},
        new int[7]{29, 30, 31, 32, 33, 34, 35},
  };
  const int *const *old_array = array;

  BoundingBox bb = {0, 2, 4, 5};
  crop(array, row_capacity, column_capacity, rows, columns, bb);

  /*
  after
  array :=
  |  3  4  5  6 |
  | 10 11 12 13 |
  | 17 18 19 20 |
  | 24 25 26 27 |
  | 31 32 33 34 |
  */
  expect(row_capacity to_be 5);
  expect(column_capacity to_be 4);
  expect(rows to_be 5);
  expect(columns to_be 4);
  expect(array[0][0] to_be 3);
  expect(array[0][3] to_be 6);
  expect(array[4][0] to_be 31);
  expect(array[4][3] to_be 34);
  expect(array not_to_be old_array);

  delete[] array[0];
  delete[] array[1];
  delete[] array[2];
  delete[] array[3];
  delete[] array[4];
  delete[] array;

  END_TEST;
}

bool remove_rows_and_columns() {
  /*
  before
  array :=
  |  1  2  3  4  5  6  7 |
  |  8  9 10 11 12 13 14 |
  | 15 16 17 18 19 20 21 |
  | 22 23 24 25 26 27 28 |
  | 29 30 31 32 33 34 35 |
  */
  size_t row_capacity = 5, rows = 5;
  size_t column_capacity = 7, columns = 7;
  int **array = new int *[5] {
    new int[7]{1, 2, 3, 4, 5, 6, 7}, new int[7]{8, 9, 10, 11, 12, 13, 14},
        new int[7]{15, 16, 17, 18, 19, 20, 21},
        new int[7]{22, 23, 24, 25, 26, 27, 28},
        new int[7]{29, 30, 31, 32, 33, 34, 35},
  };
  const int *const *old_array = array;

  BoundingBox bb = {1, 1, 3, 5};
  crop(array, row_capacity, column_capacity, rows, columns, bb);

  /*
  after
  array :=
  |  9 10 11 12 13 |
  | 16 17 18 19 20 |
  | 23 24 25 26 27 |
  */
  expect(row_capacity to_be 3);
  expect(column_capacity to_be 5);
  expect(rows to_be 3);
  expect(columns to_be 5);
  expect(array[0][0] to_be 9);
  expect(array[0][4] to_be 13);
  expect(array[2][0] to_be 23);
  expect(array[2][4] to_be 27);
  expect(array not_to_be old_array);

  delete[] array[0];
  delete[] array[1];
  delete[] array[2];
  delete[] array;

  END_TEST;
}

bool keep_everything() {
  /*
  before
  array :=
  |  1  2  3  4  5  6  7 |
  |  8  9 10 11 12 13 14 |
  | 15 16 17 18 19 20 21 |
  | 22 23 24 25 26 27 28 |
  | 29 30 31 32 33 34 35 |
  */
  size_t row_capacity = 5, rows = 5;
  size_t column_capacity = 7, columns = 7;
  int **array = new int *[5] {
    new int[7]{1, 2, 3, 4, 5, 6, 7}, new int[7]{8, 9, 10, 11, 12, 13, 14},
        new int[7]{15, 16, 17, 18, 19, 20, 21},
        new int[7]{22, 23, 24, 25, 26, 27, 28},
        new int[7]{29, 30, 31, 32, 33, 34, 35},
  };
  const int *const *old_array = array;

  BoundingBox bb = {0, 0, rows - 1, columns - 1};
  crop(array, row_capacity, column_capacity, rows, columns, bb);

  /*
  after
  no change
  */
  expect(row_capacity to_be 5);
  expect(column_capacity to_be 7);
  expect(rows to_be 5);
  expect(columns to_be 7);
  expect(array[0][0] to_be 1);
  expect(array[0][6] to_be 7);
  expect(array[4][0] to_be 29);
  expect(array[4][6] to_be 35);
  expect(array to_be old_array);

  delete[] array[0];
  delete[] array[1];
  delete[] array[2];
  delete[] array[3];
  delete[] array[4];
  delete[] array;

  END_TEST;
}

bool partially_out_of_bounds() {
  /*
  before
  array :=
  |  1  2  3  4  5  6  7 |
  |  8  9 10 11 12 13 14 |
  | 15 16 17 18 19 20 21 |
  | 22 23 24 25 26 27 28 |
  | 29 30 31 32 33 34 35 |
  */
  size_t row_capacity = 5, rows = 5;
  size_t column_capacity = 7, columns = 7;
  int **array = new int *[5] {
    new int[7]{1, 2, 3, 4, 5, 6, 7}, new int[7]{8, 9, 10, 11, 12, 13, 14},
        new int[7]{15, 16, 17, 18, 19, 20, 21},
        new int[7]{22, 23, 24, 25, 26, 27, 28},
        new int[7]{29, 30, 31, 32, 33, 34, 35},
  };
  const int *const *old_array = array;

  BoundingBox bb = {2, 3, 6, 9};
  //crop(array, row_capacity, column_capacity, rows, columns, bb);
  expect_throw(crop(array, row_capacity, column_capacity, rows, columns, bb), std::exception);

  /*
  after
  array :=
  | 18 19 20 21 |
  | 25 26 27 28 |
  | 32 33 34 35 |
  */
/*
  expect(row_capacity to_be 3);
  expect(column_capacity to_be 4);
  expect(rows to_be 3);
  expect(columns to_be 4);
  expect(array[0][0] to_be 18);
  expect(array[0][3] to_be 21);
  expect(array[2][0] to_be 32);
  expect(array[2][3] to_be 35);
  expect(array not_to_be old_array);
*/

  expect(row_capacity to_be 5);
  expect(column_capacity to_be 7);
  expect(rows to_be 5);
  expect(columns to_be 7);
  expect(array[0][0] to_be 1);
  expect(array[0][6] to_be 7);
  expect(array[4][0] to_be 29);
  expect(array[4][6] to_be 35);
  expect(array to_be old_array);
    
  delete[] array[0];
  delete[] array[1];
  delete[] array[2];
  delete[] array[3];
  delete[] array[4];
  delete[] array;

  END_TEST;
}

bool completely_out_of_bounds() {
  /*
  before
  array :=
  |  1  2  3  4  5  6  7 |
  |  8  9 10 11 12 13 14 |
  | 15 16 17 18 19 20 21 |
  | 22 23 24 25 26 27 28 |
  | 29 30 31 32 33 34 35 |
  */
  size_t row_capacity = 5, rows = 5;
  size_t column_capacity = 7, columns = 7;
  int **array = new int *[5] {
    new int[7]{1, 2, 3, 4, 5, 6, 7}, new int[7]{8, 9, 10, 11, 12, 13, 14},
        new int[7]{15, 16, 17, 18, 19, 20, 21},
        new int[7]{22, 23, 24, 25, 26, 27, 28},
        new int[7]{29, 30, 31, 32, 33, 34, 35},
  };
  const int *const *old_array = array;

  BoundingBox bb = {6, 8, 10, 14};
  // crop(array, row_capacity, column_capacity, rows, columns, bb);
  expect_throw(crop(array, row_capacity, column_capacity, rows, columns, bb),
               std::exception);

  /*
  after
  array := empty
  */
/*
  expect(row_capacity to_be 0);
  expect(column_capacity to_be 0);
  expect(rows to_be 0);
  expect(columns to_be 0);
  expect(array to_be nullptr);
*/

  expect(row_capacity to_be 5);
  expect(column_capacity to_be 7);
  expect(rows to_be 5);
  expect(columns to_be 7);
  expect(array[0][0] to_be 1);
  expect(array[0][6] to_be 7);
  expect(array[4][0] to_be 29);
  expect(array[4][6] to_be 35);
  expect(array to_be old_array);
    
  delete[] array[0];
  delete[] array[1];
  delete[] array[2];
  delete[] array[3];
  delete[] array[4];
  delete[] array;

  END_TEST;
}
