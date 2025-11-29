#include "frontend.h"

void print_field(int (*field_back)[10], WINDOW *win) {
  for (int i = 0; i < HEIGHT; ++i) {
    for (int j = 0; j < WIDTH; ++j) {
      wattron(win, COLOR_PAIR(field_back[i][j] + 1));
      mvwprintw(win, i, j * 2, " ");
      mvwprintw(win, i, j * 2 + 1, " ");
      wattroff(win, COLOR_PAIR(field_back[i][j] + 1));
    }
  }
  wrefresh(win);
}
