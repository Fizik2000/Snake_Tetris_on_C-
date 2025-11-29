#include <iostream>

#include "backend.h"

int snake_move_hangling_back(int (&field_back)[][10], point& head, point& tail,
                             std::list<point>& next_tails,
                             const int& direction) {
  int r = 0;  // 0 - move is forbidden || 1 - move is allowed
  point new_head;
  new_head = head;
  if (direction == UP)
    --new_head.y;
  else if (direction == RIGHT)
    ++new_head.x;
  else if (direction == DOWN)
    ++new_head.y;
  else if (direction == LEFT)
    --new_head.x;
  if (new_head.x > -1 && new_head.x < M && new_head.y > -1 && new_head.y < N &&
      field_back[new_head.y][new_head.x] != 1) {
    if (field_back[new_head.y][new_head.x] == 2) {
      r = 2;
    } else {
      field_back[tail.y][tail.x] = 0;
      tail = next_tails.front();
      next_tails.pop_front();
      r = 1;
    }
    field_back[new_head.y][new_head.x] = 1;
    head = new_head;
    next_tails.push_back(new_head);
  }
  return r;
}