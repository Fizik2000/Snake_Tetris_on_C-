#include "backend.h"

void set_apple_in_field_back(int (&field_back)[][10], const point& apple) {
  field_back[apple.y][apple.x] = 2;
}