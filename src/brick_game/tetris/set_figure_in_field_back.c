#include "backend.h"

void set_figure_in_field_back(int (*field_back)[10], int (*figure)[4],
                              int figure_x, int figure_y) {
  int l = 4 < figure_y + 1 ? 4 : figure_y + 1;
  for (int i = 0; i < l; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (figure[3 - i][j])
        field_back[figure_y - i][figure_x + j] = figure[3 - i][j];
    }
  }
}