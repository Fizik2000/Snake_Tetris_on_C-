#include "backend.h"
void init_field_back(int (&field_back)[][10], point& apple) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      field_back[i][j] = 0;
    }
  }
  for (int i = 11; i < 15; ++i) field_back[i][7] = 1;
  set_apple_rand(field_back, apple);
  set_apple_in_field_back(field_back, apple);
}