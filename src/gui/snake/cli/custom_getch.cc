#include <sys/select.h>
#include <termios.h>
#include <unistd.h>

#include "frontend.h"

int custom_getch(long int timeout_ms, long int *before) {
  struct timeval tv;
  fd_set fds;
  int c = -1;
  struct termios oldt, newt;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;

  newt.c_lflag &= ~(ICANON);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  tv.tv_sec = timeout_ms / 1000;
  tv.tv_usec = (timeout_ms % 1000) * 1000;

  FD_ZERO(&fds);
  FD_SET(STDIN_FILENO, &fds);

  int res = select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);

  int flag = 1;
  while (flag) {
    if (clock() * 1000000 / CLOCKS_PER_SEC - *before > timeout_ms) {
      *before = clock() * 1000000 / CLOCKS_PER_SEC;
      c = -1;
      flag = 0;
    } else if (res > 0) {
      c = getch();
      if (c == KEY_UP || c == KEY_DOWN || c == KEY_RIGHT || c == KEY_LEFT ||
          c == 'p')
        flag = 0;
    }
  }
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

  return c;
}