#include <gtest/gtest.h>

#include "../brick_game/snake/backend.h"

TEST(init_field_back, case1) {
  int field_back[N][M];
  point apple;
  init_field_back(field_back, apple);
  EXPECT_EQ(field_back[apple.y][apple.x], 2);
}

TEST(init_head_and_tail, case1) {
  point head;
  point tail;
  std::list<point> tails;
  init_head_and_tail(head, tail, tails);
  EXPECT_EQ(head.x, 7);
  EXPECT_EQ(head.y, 11);
  EXPECT_EQ(tail.x, 7);
  EXPECT_EQ(tail.y, 14);
}

TEST(snake_move_hangling_back, case1) {
  int field_back[N][M];
  point head, tail, apple;
  std::list<point> tails;
  init_field_back(field_back, apple);
  init_head_and_tail(head, tail, tails);
  snake_move_hangling_back(field_back, head, tail, tails, UP);
  snake_move_hangling_back(field_back, head, tail, tails, LEFT);
  snake_move_hangling_back(field_back, head, tail, tails, LEFT);
  snake_move_hangling_back(field_back, head, tail, tails, LEFT);
  snake_move_hangling_back(field_back, head, tail, tails, DOWN);
  snake_move_hangling_back(field_back, head, tail, tails, RIGHT);

  EXPECT_EQ(head.x, 5);
  EXPECT_EQ(head.y, 11);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}