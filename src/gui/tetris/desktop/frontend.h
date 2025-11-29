#ifndef FRONTEND_H
#define FRONTEND_H

#include <QApplication>
#include <QFrame>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QLabel>
#include <QString>
#include <QTimer>
#include <QVector>
#include <QWidget>

#include "backend/backend.h"

class MenuWidget;
class GameFieldWidget;

class NextFigureInMenu : public QWidget {
 public:
  QVector<QVector<QWidget*>> cells;
  NextFigureInMenu();
  void setCellColor(int row, int col, QVector<QString>& styles, int color);
};

class GameFieldWidget : public QWidget {
  Q_OBJECT
 private:
  MenuWidget* menu;

 public:
  QVector<QString> styles;
  QTimer* timer;
  int field_back[N][M];
  int figure[4][4];
  int n_figure = rand() % 7 + 1;
  int next_figure[4][4];
  int n_next_figure = rand() % 7 + 1;
  int figure_x = 3;
  int figure_y = 0;
  int score = 0;
  int& high_score;
  FILE* file;

 private:
  void onTimer();

 public:
  void init_styles(QVector<QString>& styles);
  void set_figure_in_field(int (&figure)[][4], int figure_x, int figure_y,
                           QVector<QString>& styles);
  void set_field_after_full_rows(int (*field_back)[10],
                                 QVector<QString>& styles, int figure_y);

 public:
  const int rows = 20;
  const int cols = 10;
  QVector<QVector<QWidget*>> cells;
  explicit GameFieldWidget(FILE* file, int& high_score);
  void setCellColor(int row, int col, QVector<QString>& styles, int color);
  void initialize(MenuWidget* menu);
  void erase_figure_in_field(int (*figure)[4], int figure_x, int figure_y);

 protected:
  void keyPressEvent(QKeyEvent* event) override;
};

class MenuWidget : public QWidget {
  Q_OBJECT
  QList<QLabel*> labels;
  QVBoxLayout* menuWidgetLayout = new QVBoxLayout(this);
  GameFieldWidget* win1;

 public:
  int menu_choice;
  int high_score;
  QLabel* ScoreLabel;
  QLabel* LevelLabel;
  QLabel* High_scoreLabel;
  explicit MenuWidget(int& highscore, int (&figure)[][4],
                      QVector<QString>& styles, int& score,
                      GameFieldWidget* win1);
  NextFigureInMenu nextFigure;
  void set_next_figure_in_menu(int (&figure)[][4], QVector<QString>& styles);
  void showRecord(QLabel* label, int& highscore);
  void showScore(QLabel* label, int& score);
  void showLevel(QLabel* label, int& score);

 protected:
  void keyPressEvent(QKeyEvent* event) override;
};

#endif
