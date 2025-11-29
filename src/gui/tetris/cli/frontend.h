#ifndef FRONTEND_H
#define FRONTEND_H

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#include "../../../brick_game/tetris/backend.h"

#define HEIGHT 20
#define HEIGHT2 20
#define WIDTH 10
#define WIDTH2 16

void init_ncurs();
void init_field(WINDOW *win);
int init_menu(WINDOW *win);

int custom_getch(long int timeout_ms, long int *before);
void user_input_hangling(int c, int (*field_back)[10], int (*figure)[4],
                         int *figure_x, int *figure_y);

int game_process(int (*field_back)[10], int (*figure)[4], int (*next_figure)[4],
                 WINDOW *win, WINDOW *win2, int *figure_x, int *figure_y,
                 int *n_figure, int *n_next_figure, long int *trigger,
                 int *score, int highscore);
void set_values_to_start(int (*field_back)[10], int (*figure)[4],
                         int (*next_figure)[4], int *highscore, int *score,
                         FILE *file, int *n_figure, int *n_next_figure,
                         int *figure_x, int *figure_y, long int *trigger);
void figure_move_hangling(int (*field_back)[10], int (*figure)[4],
                          int (*next_figure)[4], WINDOW *win, WINDOW *win2,
                          int *figure_x, int *figure_y, int *n_figure,
                          int *n_next_figure, long int *trigger, int *score,
                          int highscore, int *c, long int *before,
                          int *exit_flag);
void print_game_info(WINDOW *win, int (*next_figure)[4], int n_next_figure,
                     int score, int highscore);
void erase_figure_in_field(int (*figure)[4], WINDOW *win, int figure_x,
                           int figure_y);
void set_figure_in_field(int (*figure)[4], WINDOW *win, int figure_x,
                         int figure_y, int n);
void print_field(int (*field_back)[10], WINDOW *win);
void set_field_after_full_rows(int (*field_back)[10], int figure_y,
                               WINDOW *win);

#endif