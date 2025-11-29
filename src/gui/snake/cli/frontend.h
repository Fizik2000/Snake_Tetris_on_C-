#ifndef SNAKE_CLI_FRONT
#define SNAKE_CLI_FRONT

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../../../brick_game/snake/backend.h"

#define HEIGHT 20
#define HEIGHT2 20
#define WIDTH 10
#define WIDTH2 16

int custom_getch(long int timeout_ms, long int* before);
void init_ncurs();
int init_menu(WINDOW* win);
void init_field(WINDOW* win);
void print_field(int (*field_back)[10], WINDOW* win);
void print_game_info(WINDOW* win, int score, int highscore);
int game_process(int (&field_back)[][10], int& score, long int& trigger,
                 int& direction, point& apple, int& highscore, point& head,
                 point& tail, std::list<point>& next_tails, WINDOW* win,
                 WINDOW* win2);
void update_field_after_move(point& new_head, point& old_tail, int l,
                             WINDOW* win);

#endif