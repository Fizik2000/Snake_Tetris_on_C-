#ifndef SNAKE_BACKEND_H
#define SNAKE_BACKEND_H

#define N 20
#define M 10

#define UP 1
#define RIGHT 2
#define LEFT 3
#define DOWN 4

#include <stdio.h>

#include <cstdlib>
#include <list>

typedef struct {
  int x;
  int y;
} point;

void init_field_back(int (&field_back)[][10], point& apple);
void init_head_and_tail(point& head, point& tail, std::list<point>& next_tails);
void set_apple_in_field_back(int (&field_back)[][10], const point& apple);
void set_apple_rand(int (&field_back)[][10], point& a);
int snake_move_hangling_back(int (&field_back)[][10], point& head, point& tail,
                             std::list<point>& tails, const int& direction);

#endif