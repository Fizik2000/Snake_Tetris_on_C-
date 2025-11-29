#include "frontend.h"

int game_process(int (&field_back)[][10], int& score, long int& trigger,
                 int& direction, point& apple, int& highscore, point& head,
                 point& tail, std::list<point>& next_tails, WINDOW* win,
                 WINDOW* win2) {
  print_game_info(win2, score, highscore);

  long int before = clock() * 1000000 / CLOCKS_PER_SEC;
  int c = custom_getch(trigger, &before);

  int exit_flag = 0;
  while (c != 'p' && !exit_flag) {
    if (c == KEY_UP && direction != DOWN)
      direction = UP;
    else if ((c == KEY_RIGHT) && direction != LEFT)
      direction = RIGHT;
    else if ((c == KEY_DOWN) && direction != UP)
      direction = DOWN;
    else if ((c == KEY_LEFT) && direction != RIGHT)
      direction = LEFT;

    point temporary_tail = tail;
    int l = 0;
    if (l = snake_move_hangling_back(field_back, head, tail, next_tails,
                                     direction)) {
      update_field_after_move(head, temporary_tail, l, win);
      if (l == 2) {
        set_apple_rand(field_back, apple);
        set_apple_in_field_back(field_back, apple);
        wattron(win, COLOR_PAIR(3));
        mvwprintw(win, apple.y, apple.x * 2, " ");
        mvwprintw(win, apple.y, apple.x * 2 + 1, " ");
        wattroff(win, COLOR_PAIR(3));
        wrefresh(win);
        if (++score > highscore) {
          highscore = score;

          FILE* file = fopen("games/snake_cli_build/high_score.txt", "w");
          fprintf(file, "%d", highscore);
          fclose(file);
        }
      }
      print_game_info(win2, score, highscore);
    } else {
      score = 0;
      direction = UP;
      next_tails.clear();
      init_field_back(field_back, apple);
      init_head_and_tail(head, tail, next_tails);
      init_field(win);
      print_field(field_back, win);
      exit_flag = 1;
      wrefresh(win);
    }

    if (!exit_flag) c = custom_getch(trigger, &before);
  }

  return 0;
}