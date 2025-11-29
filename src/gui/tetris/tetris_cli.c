
#include "cli/frontend.h"

int main() {
  init_ncurs();

  WINDOW *win = newwin(HEIGHT, WIDTH * 2, (LINES - HEIGHT) / 2,
                       (COLS - WIDTH * 2) / 2 - 6);
  WINDOW *win2 =
      newwin(HEIGHT2, WIDTH2, (LINES - HEIGHT) / 2, (COLS + WIDTH) / 2 + 1);
  int field_back[N][M];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) field_back[i][j] = 0;
  }
  int figure[4][4];
  int n_figure = rand() % 7 + 1;
  set_figure(figure, n_figure);
  int next_figure[4][4];
  int n_next_figure = rand() % 7 + 1;
  set_figure(next_figure, n_next_figure);
  int figure_x = M / 2 - 2;
  int figure_y = 0;
  long int trigger = 1100;
  int score = 0;

  FILE *file;
  file = fopen("games/tetris_cli_build/high_score.txt", "r");
  int highscore;
  fscanf(file, "%d", &highscore);
  init_field(win);

  int condition = -1;
  while (condition != 2) {
    if (condition == -1) condition = init_menu(win2);
    if (condition == 0) {
      condition = game_process(field_back, figure, next_figure, win, win2,
                               &figure_x, &figure_y, &n_figure, &n_next_figure,
                               &trigger, &score, highscore);
    } else if (condition == 1) {
      set_values_to_start(field_back, figure, next_figure, &highscore, &score,
                          file, &n_figure, &n_next_figure, &figure_x, &figure_y,
                          &trigger);
      werase(win);
      wrefresh(win);
      condition = 0;
    }
  }
  set_values_to_start(field_back, figure, next_figure, &highscore, &score, file,
                      &n_figure, &n_next_figure, &figure_x, &figure_y,
                      &trigger);
  fclose(file);
  endwin();
  return 0;
}