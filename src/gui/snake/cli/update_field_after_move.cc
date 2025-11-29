#include "frontend.h"

void update_field_after_move(point& new_head, point& old_tail, int l,
                             WINDOW* win) {
  wattron(win, COLOR_PAIR(2));
  mvwprintw(win, new_head.y, new_head.x * 2, " ");
  mvwprintw(win, new_head.y, new_head.x * 2 + 1, " ");
  wattroff(win, COLOR_PAIR(2));
  if (l == 1) {
    wattron(win, COLOR_PAIR(1));
    mvwprintw(win, old_tail.y, old_tail.x * 2, " ");
    mvwprintw(win, old_tail.y, old_tail.x * 2 + 1, " ");
    wattroff(win, COLOR_PAIR(1));
  }
  wrefresh(win);
}