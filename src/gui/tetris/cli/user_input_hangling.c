#include "frontend.h"

void user_input_hangling(int c, int (*field_back)[10], int (*figure)[4],
                         int *figure_x, int *figure_y) {
  if (c == KEY_DOWN || c == -1) {
    if (!is_neighbors_below(field_back, figure, *figure_x, *figure_y))
      ++*figure_y;
  } else if (c == KEY_LEFT) {
    if (!is_neighbors_left(field_back, figure, *figure_x, *figure_y))
      --*figure_x;
  } else if (c == KEY_RIGHT) {
    if (!is_neighbors_right(field_back, figure, *figure_x, *figure_y))
      ++*figure_x;
  } else if (c == KEY_UP) {
    if (is_rotation_possible(field_back, figure, figure_x, *figure_y))
      rotate(figure);
  }
}