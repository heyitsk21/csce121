#include "functions.h"
#include <stdexcept>

void crop(int**& array,
          size_t& row_capacity,
          size_t& column_capacity,
          size_t& rows,
          size_t& columns,
          BoundingBox selected_area) {
  // TODO(student): implement this method

  if (/*selected_area.min_row_idx < 0 || */selected_area.max_row_idx >= rows){
    throw std::out_of_range("Selected Area goes beyond image bounds");
  }
  if (/*selected_area.min_col_idx < 0 || */selected_area.max_col_idx >= columns){
    throw std::out_of_range("Selected Area goes beyond image bounds");
  }

  int** newArray = new int*[selected_area.max_row_idx - selected_area.min_row_idx + 1];
  for (size_t i = selected_area.min_row_idx; i < selected_area.max_row_idx; i++){
    newArray[i - selected_area.min_row_idx] = new int[selected_area.max_col_idx - selected_area.min_col_idx + 1];
  }

  size_t holder_row = 0;
  size_t holder_col = 0;
  for (size_t r = 0; r < row_capacity; r++){
    for (size_t c = 0; c < column_capacity; c++){
      if (r >= selected_area.min_row_idx && r <= selected_area.max_row_idx
          && c >= selected_area.min_col_idx && c <= selected_area.max_col_idx){
            newArray[holder_row][holder_col] = array[r][c];
            holder_col++;
      }
    }
    holder_col = 0;
    holder_row++;
  }

  if (array) {
      for (size_t row = 0; row < rows; row++) {
          delete[] array[row];
      }
      delete[] array;
  }

  array = newArray;

  row_capacity = selected_area.max_row_idx-selected_area.min_row_idx;
  column_capacity = selected_area.max_col_idx-selected_area.min_col_idx;
  rows = selected_area.max_row_idx-selected_area.min_row_idx;
  columns = selected_area.max_col_idx-selected_area.min_col_idx;
  
  if (newArray) {
      for (size_t row = 0; row < row_capacity; row++) {
          delete[] newArray[row];
      }
      delete[] newArray;
  }


  /* Example
  array with 5 rows and 7 columns:
  |  1  2  3  4  5  6  7 |
  |  8  9 10 11 12 13 14 |
  | 15 16 17 18 19 20 21 |
  | 22 23 24 25 26 27 28 |
  | 29 30 31 32 33 34 35 |

  crop {min_row_idx=1, min_col_idx=1, max_row_idx=3, max_col_idx=5}

       |                |
  |  X |        X       |  X | <-- deleted row
--+----+----------------+----+--
  |    |  9 10 11 12 13 |    | <-- row 1 (min_row_idx)
  |  X | 16 17 18 19 20 |  X |
  |    | 23 24 25 26 27 |    | <-- row 3 (max_row_idx)
--+----+----------------+----+--
  |  X |        X       |  X | <-- deleted row
     ^ | ^           ^  |  ^-- deleted column
     |   |           +-- column 5 (max_col_idx)       
     |   +-- column 1 (min_col_idx)
     +-- deleted column

  new array has 3 rows and 5 columns
  |  9 10 11 12 13 |
  | 16 17 18 19 20 |
  | 23 24 25 26 27 |
  */
}
