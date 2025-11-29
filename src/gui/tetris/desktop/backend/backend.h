#ifndef BACKEND_H
#define BACKEND_H

#ifdef __cplusplus
extern "C" {
#endif

#include <time.h>

#include "stdlib.h"

#define N 20
#define M 10

void set_figure(int (*figure)[4], int n);
void set_figure_in_field_back(int (*field_back)[10], int (*figure)[4],
                              int figure_x, int figure_y);
void erase_figure_in_field_back(int (*field_back)[10], int (*figure)[4],
                                int figure_x, int figure_y);
int is_neighbors_below(int (*field_back)[10], int (*figure)[4], int figure_x,
                       int figure_y);
int is_four_row_full(int (*field_back)[10], int figure_y);
void set_field_back_after_full_row(int (*field_back)[10], int figure_y);
int is_neighbors_left(int (*field_back)[10], int (*figure)[4], int figure_x,
                      int figure_y);
int is_neighbors_right(int (&field_back)[][10], int (&figure)[][4], int figure_x,
                       int figure_y);
int is_rotation_possible(int (*field_back)[10], int (*figure)[4], int figure_x,
                         int figure_y);
void rotate(int (*field_back)[10], int (*figure)[4], int& figure_x);

#ifdef __cplusplus
}
#endif

#endif