#include "backend.h"

void init_head_and_tail(point& head, point& tail, std::list<point>& tails) {
  head.x = 7;
  head.y = 11;

  point p;
  p.x = 7;
  for (int y = 11; y < 15; ++y) {
    p.y = y;
    tails.push_front(p);
  }
  tail = tails.front();
  tails.pop_front();
}