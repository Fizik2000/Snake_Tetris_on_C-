#include "frontend.h"

int strlen_int(int a) {
  int r = 1;
  for (a = a / 10; a != 0; a = a / 10) ++r;
  return r;
}

void print_game_info(WINDOW *win, int score, int highscore) {
  int level = score / 5 + 1;
  if (level > 10) level = 10;

  wattron(win, COLOR_PAIR(4));

  mvwprintw(win, 1, (WIDTH2 - 1 - strlen("Record")) / 2 + 1, "%s", "Record");
  mvwprintw(win, 2, (WIDTH2 - 1 - strlen_int(highscore)) / 2 + 1, "%d",
            highscore);

  mvwprintw(win, 9, (WIDTH2 - 1 - strlen("Score")) / 2 + 1, "%s", "Score");
  mvwprintw(win, 10, (WIDTH2 - 1 - strlen_int(score)) / 2 + 1, "%d", score);

  mvwprintw(win, 16, (WIDTH2 - 1 - strlen("level")) / 2 + 1, "%s", "level");
  mvwprintw(win, 17, (WIDTH2 - 1 - strlen_int(level)) / 2 + 1, "%d", level);

  wattroff(win, COLOR_PAIR(4));

  wrefresh(win);
  werase(win);
}
