#include "frontend.h"

void init_ncurs() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, 1);

  curs_set(0);
  srand(time(0));
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  init_pair(2, COLOR_BLACK, COLOR_GREEN);
  init_pair(3, COLOR_BLACK, COLOR_RED);
  init_pair(4, COLOR_BLACK, COLOR_WHITE);
  init_pair(5, COLOR_GREEN, COLOR_WHITE);
  refresh();
}