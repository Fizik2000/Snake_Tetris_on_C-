#include "backend.h"

int is_four_row_full(int (*field_back)[10], int figure_y) {
  int return_value = 1;
  int l = 4 < (figure_y + 1) ? 4 : figure_y + 1;
  // ntf("l = %d\n", l);
  for (int i = 0; i < l; ++i) {
    return_value = 1;
    for (int j = 0; j < M; ++j) {
      if (field_back[figure_y - i][j] == 0)
        return_value = -1;
    }
    if (return_value == 1) {
      return_value = figure_y - i;
      i = l + 1;
    }
  }
  return return_value;
}