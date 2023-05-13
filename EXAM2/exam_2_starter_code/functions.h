#ifndef FUNCTIONS
#define FUNCTIONS

#include <cstddef>  // for size_t

// encapsulate bounding box indices
struct BoundingBox { size_t min_row_idx, min_col_idx, max_row_idx, max_col_idx; };

void crop(int**& array,
          size_t& row_capacity,
          size_t& column_capacity,
          size_t& rows,
          size_t& columns,
          BoundingBox selected_area);

#endif  // FUNCTIONS