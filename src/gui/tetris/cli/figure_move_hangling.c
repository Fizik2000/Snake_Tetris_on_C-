#include "frontend.h"

void figure_move_hangling(int (*field_back)[10], int (*figure)[4],
                          int (*next_figure)[4], WINDOW *win, WINDOW *win2,
                          int *figure_x, int *figure_y, int *n_figure,
                          int *n_next_figure, long int *trigger, int *score,
                          int highscore, int *c, long int *before,
                          int *exit_flag) {
  if (is_neighbors_below(field_back, figure, *figure_x, *figure_y)) {
    erase_figure_in_field(figure, win, *figure_x, *figure_y);
    *c = custom_getch(*trigger, before);

    user_input_hangling(*c, field_back, figure, figure_x, figure_y);

    set_figure_in_field(figure, win, *figure_x, *figure_y, *n_figure);
    wrefresh(win);
  }
  if (is_neighbors_below(field_back, figure, *figure_x, *figure_y)) {
    set_figure_in_field_back(field_back, figure, *figure_x, *figure_y);

    int r = is_four_row_full(field_back, *figure_y);
    int flag = 0;
    while (r >= 0) {
      set_field_back_after_full_row(field_back, r);
      r = is_four_row_full(field_back, *figure_y);
      if (flag == 0)
        *score += 100;
      else if (flag == 1)
        *score += 200;
      else if (flag == 2)
        *score += 400;
      else if (flag == 3)
        *score += 800;
      if (*trigger > 100) *trigger = 1100 - *score / 600 * 100;
      ++flag;
    }
    if (flag) set_field_after_full_rows(field_back, *figure_y, win);
    *n_figure = *n_next_figure;
    *n_next_figure = rand() % 7 + 1;
    set_figure(figure, *n_figure);
    set_figure(next_figure, *n_next_figure);
    if (!*figure_y) *exit_flag = 1;
    *figure_x = M / 2 - 2;
    *figure_y = 0;
    set_figure_in_field(figure, win, *figure_x, *figure_y, *n_figure);
    wrefresh(win);
    print_game_info(win2, next_figure, *n_next_figure, *score, highscore);
  }
  erase_figure_in_field(figure, win, *figure_x, *figure_y);
}