#include "frontend.h"

int init_menu(WINDOW *win) {
  const char *items[] = {"Start", "Exit"};
  const int niteams = 2;

  for (int i = 0; i < niteams; i++) {
    mvwprintw(win, (HEIGHT - niteams) / 2 + i,
              (WIDTH2 - 1 - strlen(items[i])) / 2 + 1, "%s", items[i]);
  }

  wbkgd(win, COLOR_PAIR(4));

  wrefresh(win);

  int choice = 0, c = 0;
  while (c != 10) {
    wattron(win, COLOR_PAIR(5));
    mvwprintw(win, (HEIGHT - niteams) / 2 + choice,
              (WIDTH2 - 1 - strlen(items[choice])) / 2 + 1, "%s",
              items[choice]);
    wattroff(win, COLOR_PAIR(5));
    wrefresh(win);
    mvwprintw(win, (HEIGHT - niteams) / 2 + choice,
              (WIDTH2 - 1 - strlen(items[choice])) / 2 + 1, "%s",
              items[choice]);
    switch (c) {
      case KEY_UP:
        if (choice > 0) --choice;
        break;
      case KEY_DOWN:
        if (choice < niteams - 1) ++choice;
        break;
    }
    wattron(win, COLOR_PAIR(5));
    mvwprintw(win, (HEIGHT - niteams) / 2 + choice,
              (WIDTH2 - 1 - strlen(items[choice])) / 2 + 1, "%s",
              items[choice]);
    wattroff(win, COLOR_PAIR(5));
    wrefresh(win);
    c = getch();
  }

  werase(win);  // Maybe to delete in the future

  return choice == 1 ? -1 : 1;
}
