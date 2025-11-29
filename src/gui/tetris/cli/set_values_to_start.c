#include "frontend.h"

void set_values_to_start(int (*field_back)[10], int (*figure)[4],
                         int (*next_figure)[4], int *highscore, int *score,
                         FILE *file, int *n_figure, int *n_next_figure,
                         int *figure_x, int *figure_y, long int *trigger) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) field_back[i][j] = 0;
  }
  if (*highscore < *score) {
    file = fopen("games/tetris_cli_build/high_score.txt", "w");
    fprintf(file, "%d", *score);
    *highscore = *score;
  }
  *n_figure = rand() % 7 + 1;
  set_figure(figure, *n_figure);
  *n_next_figure = rand() % 7 + 1;
  set_figure(next_figure, *n_next_figure);
  *figure_x = M / 2 - 2;
  *figure_y = 0;
  *trigger = 1100;
  *score = 0;
}