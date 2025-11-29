#include "backend.h"

void erase_figure_in_field_back(int (*field_back)[10], int (*figure)[4],
                                int figure_x, int figure_y) {
  int l = 4 < figure_y + 1 ? 4 : figure_y + 1;
  int m = 4 < M - figure_x ? 4 : M - figure_x;
  for (int i = 0; i < l; ++i) {
    for (int j = 0; j < m; ++j) {
      if (figure[3 - i][j]) field_back[figure_y - i][figure_x + j] = 0;
    }
  }
}