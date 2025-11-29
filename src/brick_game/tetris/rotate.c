#include "backend.h"

int is_row_empty(int (*figure)[4], int n);
int is_column_empty(int (*figure)[4], int n);
void move_figure_below(int (*figure)[4]);
void move_figure_left(int (*figure)[4]);

int is_rotation_possible(int (*field_back)[10], int (*figure)[4], int *figure_x,
                         int figure_y) {
  int return_value = 1;
  int f[4][4];
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) f[i][j] = figure[i][j];
  }
  rotate(f);
  int col = 3;
  while (is_column_empty(f, col)) --col;
  while (*figure_x + col > M - 1) --(*figure_x);
  int l = 4 < figure_y + 1 ? 4 : figure_y + 1;
  for (int i = 0; i < l; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (f[3 - i][j] && field_back[figure_y - i][*figure_x + j])
        return_value = 0;
    }
  }
  return return_value;
}

void rotate(int (*figure)[4]) {
  int f[4][4];
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      f[3 - j][i] = figure[i][j];
    }
  }
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      figure[i][j] = f[i][j];
    }
  }
  while (is_row_empty(figure, 3)) move_figure_below(figure);
  while (is_column_empty(figure, 0)) move_figure_left(figure);
}

int is_row_empty(int (*figure)[4], int n) {
  int return_value = 1;
  for (int i = 0; i < 4; ++i) {
    if (figure[n][i]) return_value = 0;
  }
  return return_value;
}

int is_column_empty(int (*figure)[4], int n) {
  int return_value = 1;
  for (int i = 0; i < 4; ++i) {
    if (figure[i][n]) return_value = 0;
  }
  return return_value;
}

void move_figure_below(int (*figure)[4]) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 4; ++j) {
      figure[3 - i][j] = figure[2 - i][j];
    }
  }
  for (int j = 0; j < 4; ++j) figure[0][j] = 0;
}

void move_figure_left(int (*figure)[4]) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 4; ++j) {
      figure[j][i] = figure[j][i + 1];
    }
  }
  for (int i = 0; i < 4; ++i) figure[i][3] = 0;
}