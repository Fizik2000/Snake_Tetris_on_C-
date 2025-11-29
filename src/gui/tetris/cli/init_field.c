#include "frontend.h"

void init_field(WINDOW *win) {
  wbkgd(win, COLOR_PAIR(8));
  wrefresh(win);
}
