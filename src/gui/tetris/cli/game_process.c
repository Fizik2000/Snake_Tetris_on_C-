#include "frontend.h"

int game_process(int (*field_back)[10], int (*figure)[4], int (*next_figure)[4],
                 WINDOW *win, WINDOW *win2, int *figure_x, int *figure_y,
                 int *n_figure, int *n_next_figure, long int *trigger,
                 int *score, int highscore) {
  print_game_info(win2, next_figure, *n_next_figure, *score, highscore);

  long int before = clock() * 1000000 / CLOCKS_PER_SEC;

  int exit_flag = 0;
  int c = 's';
  while (c != 'p') {
    set_figure_in_field(figure, win, *figure_x, *figure_y, *n_figure);
    wrefresh(win);

    figure_move_hangling(field_back, figure, next_figure, win, win2, figure_x,
                         figure_y, n_figure, n_next_figure, trigger, score,
                         highscore, &c, &before, &exit_flag);
    if (exit_flag)
      c = 'p';
    else {
      c = custom_getch(*trigger, &before);
      user_input_hangling(c, field_back, figure, figure_x, figure_y);
    }
  }
  return exit_flag == 1 ? 1 : -1;
}