#include "backend.h"

point get_next(point& a) {
  point b = a;
  if (b.x < M - 1) {
    b.x = b.x + 1;
  } else {
    if (b.y != N - 1) {
      b.x = 0;
      b.y = b.y + 1;
    } else {
      b.x = 0;
      b.y = 0;
    }
  }
  return b;
}

void set_apple_rand(int (&field_back)[][10], point& a) {
  a.x = rand() % M;
  a.y = rand() % N;
  while (field_back[a.y][a.x] != 0) a = get_next(a);
}