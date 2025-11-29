#include "backend.h"

void set_field_back_after_full_row(int (*field_back)[10], int figure_y) {
  for (int i = figure_y; i > 0; --i) {
    for (int j = 0; j < M; ++j) {
      field_back[i][j] = field_back[i - 1][j];
    }
  }
}