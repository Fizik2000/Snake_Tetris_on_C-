#include "backend.h"

int is_neighbors_left(int (*field_back)[10], int (*figure)[4], int figure_x,
                      int figure_y) {
  int return_value = 0;
  int l = 4 < figure_y + 1 ? 4 : figure_y + 1;
  int m = 4 < M - figure_x ? 4 : M - figure_x;
  for (int i = 0; i < l; ++i) {
    for (int j = 0; j < m; ++j) {
      if (figure[3 - i][j]) {
        if (figure_x + j - 1 == -1)
          return_value = 1;
        else if (field_back[figure_y - i][figure_x + j - 1])
          return_value = 1;
      }
    }
  }
  return return_value;
}