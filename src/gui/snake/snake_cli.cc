
#include "cli/frontend.h"

int main() {
  init_ncurs();

  WINDOW *win = newwin(HEIGHT, WIDTH * 2, (LINES - HEIGHT) / 2,
                       (COLS - WIDTH * 2) / 2 - 6);
  WINDOW *win2 =
      newwin(HEIGHT2, WIDTH2, (LINES - HEIGHT) / 2, (COLS + WIDTH) / 2 + 1);

  int field_back[N][M];
  point apple;
  point head;
  point tail;
  int direction = UP;
  int score = 0;
  long int trigger = 600;
  std::list<point> next_tails;
  werase(win);
  wrefresh(win);
  init_field_back(field_back, apple);
  init_head_and_tail(head, tail, next_tails);
  init_field(win);
  print_field(field_back, win);

  FILE *file;
  file = fopen("games/snake_cli_build/high_score.txt", "r");
  int highscore;
  fscanf(file, "%d", &highscore);
  fclose(file);

  int condition = 0;
  while (condition != -1) {
    if (condition == 0)
      condition = init_menu(win2);
    else if (condition == 1)
      condition = game_process(field_back, score, trigger, direction, apple,
                               highscore, head, tail, next_tails, win, win2);
  }
  endwin();
  return 0;
}