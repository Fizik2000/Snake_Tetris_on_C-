#ifndef SNAKE_FRONTEND_H
#define SNAKE_FRONTEND_H

#include <QApplication>
#include <QFrame>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QLabel>
#include <QTimer>
#include <QWidget>
#include <iostream>  // delete later

#include "../../../brick_game/snake/backend.h"

class GameFieldWidget;
class MenuWidget;

class GameFieldWidget : public QWidget {
  Q_OBJECT
 private:
  MenuWidget *menu;

 public:
  QTimer *timer;
  int score = 0;
  int &high_score;
  FILE *file;
  int field_back[N][M];
  QVector<QVector<QWidget *>> cells;
  point apple;
  point head;
  point tail;
  int direction = UP;
  std::list<point> next_tails;

 private:
  void update_field_after_move(point new_head, point old_tail, int l);
  void onTimer();

 public:
  explicit GameFieldWidget(FILE *file, int &high_score);
  void initialize(MenuWidget *menu);

 protected:
  void keyPressEvent(QKeyEvent *event) override;
};

class MenuWidget : public QWidget {
  Q_OBJECT
 private:
  GameFieldWidget *game_win;
  QList<QLabel *> labels;
  QVBoxLayout *menuWidgetLayout = new QVBoxLayout(this);
  int menu_choice;

 public:
  QTimer *timer;
  int &score;
  int &high_score;
  FILE *file;
  QLabel *ScoreLabel;
  QLabel *LevelLabel;
  QLabel *High_scoreLabel;

 private:
 public:
  explicit MenuWidget(int &highscore, int &score, GameFieldWidget *win1);
  void showRecord(QLabel *label, int &highscore);
  void showLevel(QLabel *label, int &score);
  void showScore(QLabel *label, int &score);

 protected:
  void keyPressEvent(QKeyEvent *event) override;
};

#endif
