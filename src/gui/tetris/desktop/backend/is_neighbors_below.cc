#include "backend.h"
#include "stdio.h"

int is_neighbors_below(int (*field_back)[10], int (*figure)[4], int figure_x,
                       int figure_y) {
  int return_value = 0;
  int l = 4 < figure_y + 1 ? 4 : figure_y + 1;
  int m = 4 < M - figure_x ? 4 : M - figure_x;
  
  for (int j = 0; j < m; ++j) {
    int i = 0;
    while (i < l && !figure[3 - i][j]) ++i;
      if (i != l) {
        if (figure_y - i + 1 == N)
          return_value = 1;
        else if (field_back[figure_y - i + 1][figure_x + j])
          return_value = 1;
      }
    }
  return return_value;
}

// void set_figure_in_field_back ()