#include "frontend.h"

void init_field(WINDOW *win) {
  wbkgd(win, COLOR_PAIR(4));
  wrefresh(win);
}
