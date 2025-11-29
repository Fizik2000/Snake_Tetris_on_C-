#include "frontend.h"

void set_figure_in_field(int (*figure)[4], WINDOW *win, int figure_x,
                         int figure_y, int n) {
  int l = 4 < figure_y + 1 ? 4 : figure_y + 1;
  wattron(win, COLOR_PAIR(n));
  for (int i = 0; i < l; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (figure[3 - i][j]) {
        mvwprintw(win, figure_y - i, (figure_x + j) * 2, " ");
        mvwprintw(win, figure_y - i, (figure_x + j) * 2 + 1, " ");
      }
    }
  }
  wattroff(win, COLOR_PAIR(n));
}