#include "frontend.h"

void set_field_after_full_rows(int (*field_back)[10], int figure_y,
                               WINDOW *win) {
  // wattron(win, COLOR_PAIR(4));
  for (int i = figure_y; i >= 0; --i) {
    for (int j = 0; j < WIDTH; ++j) {
      if (field_back[i][j]) {
        wattron(win, COLOR_PAIR(field_back[i][j]));
        mvwprintw(win, i, j * 2, " ");
        mvwprintw(win, i, j * 2 + 1, " ");
        wattroff(win, COLOR_PAIR(field_back[i][j]));
      } else {
        wattron(win, COLOR_PAIR(8));
        mvwprintw(win, i, j * 2, " ");
        mvwprintw(win, i, j * 2 + 1, " ");
        wattroff(win, COLOR_PAIR(8));
      }
    }
  }
}

// void set_figure_in_field_back_back ()