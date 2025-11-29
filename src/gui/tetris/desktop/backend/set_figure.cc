#include "backend.h"

void set_figure(int (*figure)[4], int n) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j)
      figure[i][j] = 0;
  }
  switch (n - 1) {
  case 0:
    figure[3][0] = n;
    figure[3][1] = n;
    figure[3][2] = n;
    figure[3][3] = n;
    break;
  case 1:
    figure[2][0] = n;
    figure[3][0] = n;
    figure[3][1] = n;
    figure[3][2] = n;
    break;
  case 2:
    figure[3][0] = n;
    figure[3][1] = n;
    figure[3][2] = n;
    figure[2][2] = n;
    break;
  case 3:
    figure[2][0] = n;
    figure[2][1] = n;
    figure[3][0] = n;
    figure[3][1] = n;
    break;
  case 4:
    figure[3][0] = n;
    figure[3][1] = n;
    figure[2][1] = n;
    figure[2][2] = n;
    break;
  case 5:
    figure[3][0] = n;
    figure[3][1] = n;
    figure[2][1] = n;
    figure[3][2] = n;
    break;
  case 6:
    figure[2][0] = n;
    figure[2][1] = n;
    figure[3][1] = n;
    figure[3][2] = n;
    break;
  }
}