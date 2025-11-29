#include "frontend.h"

int strlen_int(int a) {
  int r = 1;
  for (a = a / 10; a != 0; a = a / 10) ++r;
  return r;
}

void print_game_info(WINDOW *win, int (*next_figure)[4], int n_next_figure,
                     int score, int highscore) {
  int level = score / 600 + 1;
  if (level > 10) level = 10;

  wattron(win, COLOR_PAIR(8));

  mvwprintw(win, 0, (WIDTH2 - 1 - strlen("Record")) / 2 + 1, "%s", "Record");
  mvwprintw(win, 1, (WIDTH2 - 1 - strlen_int(highscore)) / 2 + 1, "%d",
            highscore);

  mvwprintw(win, 4, (WIDTH2 - 1 - strlen("Next")) / 2 + 1, "%s", "Next");
  set_figure_in_field(next_figure, win, 3, 6, n_next_figure);

  mvwprintw(win, 10, (WIDTH2 - 1 - strlen("Score")) / 2 + 1, "%s", "Score");
  mvwprintw(win, 11, (WIDTH2 - 1 - strlen_int(score)) / 2 + 1, "%d", score);

  mvwprintw(win, 17, (WIDTH2 - 1 - strlen("level")) / 2 + 1, "%s", "level");
  mvwprintw(win, 18, (WIDTH2 - 1 - strlen_int(level)) / 2 + 1, "%d", level);

  wattroff(win, COLOR_PAIR(8));

  wrefresh(win);
  werase(win);
}
