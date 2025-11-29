#include "frontend.h"

GameFieldWidget::GameFieldWidget(FILE *file, int &high_score)
    : QWidget(), file(file), high_score(high_score) {
  QGridLayout *layout = new QGridLayout(this);
  layout->setSpacing(1);
  layout->setContentsMargins(0, 0, 0, 0);

  init_field_back(field_back, apple);
  init_head_and_tail(head, tail, next_tails);

  cells.resize(N);
  for (int i = 0; i < N; ++i) {
    cells[i].resize(M);
    for (int j = 0; j < M; ++j) {
      QWidget *cell = new QLabel();
      if (field_back[i][j] == 0)
        cell->setStyleSheet("background-color: white;");
      else if (field_back[i][j] == 1)
        cell->setStyleSheet("background-color: green;");
      else if (field_back[i][j] == 2)
        cell->setStyleSheet("background-color: red;");
      layout->addWidget(cell, i, j);
      cells[i][j] = cell;
    }
  }

  timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &GameFieldWidget::onTimer);
  timer->setInterval(990);
}

void GameFieldWidget::onTimer() {
  point temporary_tail = tail;
  int l = 0;
  if (l = snake_move_hangling_back(field_back, head, tail, next_tails,
                                   direction)) {
    update_field_after_move(head, temporary_tail, l);
    if (l == 2) {
      set_apple_rand(field_back, apple);
      set_apple_in_field_back(field_back, apple);
      cells[apple.y][apple.x]->setStyleSheet("background-color: red;");
      menu->ScoreLabel->setText(QString("Score\n%1").arg(++score));
      menu->LevelLabel->setText(QString("Level\n%1").arg(score / 5 + 1));
      if (score > high_score) {
        high_score = score;
        menu->High_scoreLabel->setText(QString("Record\n%1").arg(high_score));
        file = fopen("games/snake_desktop_build/high_score.txt", "w");
        fprintf(file, "%d", high_score);
        fclose(file);
      }
    }
  } else {
    menu->setFocus();
    timer->stop();
    score = 0;
    menu->ScoreLabel->setText(QString("Score\n%1").arg(++score));

    direction = UP;

    next_tails.clear();
    init_field_back(field_back, apple);
    init_head_and_tail(head, tail, next_tails);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (field_back[i][j] == 0)
          cells[i][j]->setStyleSheet("background-color: white;");
        else if (field_back[i][j] == 1)
          cells[i][j]->setStyleSheet("background-color: green;");
        else if (field_back[i][j] == 2)
          cells[i][j]->setStyleSheet("background-color: red;");
      }
    }
  }
}

void GameFieldWidget::initialize(MenuWidget *menu) { this->menu = menu; }

void GameFieldWidget::update_field_after_move(point new_head, point old_tail,
                                              int l) {
  cells[new_head.y][new_head.x]->setStyleSheet("background-color: green;");
  if (l == 1)
    cells[old_tail.y][old_tail.x]->setStyleSheet("background-color: white;");
}

void GameFieldWidget::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Up && direction != DOWN)
    direction = UP;
  else if ((event->key() == Qt::Key_Right) && direction != LEFT)
    direction = RIGHT;
  else if ((event->key() == Qt::Key_Down) && direction != UP)
    direction = DOWN;
  else if ((event->key() == Qt::Key_Left) && direction != RIGHT)
    direction = LEFT;
  if ((event->key() == Qt::Key_P)) {
    menu->setFocus();
    timer->stop();
  } else {
    point temporary_tail = tail;
    int l = 0;
    if (l = snake_move_hangling_back(field_back, head, tail, next_tails,
                                     direction)) {
      update_field_after_move(head, temporary_tail, l);
      if (l == 2) {
        set_apple_rand(field_back, apple);
        set_apple_in_field_back(field_back, apple);
        cells[apple.y][apple.x]->setStyleSheet("background-color: red;");
        menu->ScoreLabel->setText(QString("Score\n%1").arg(++score));
        menu->LevelLabel->setText(QString("Level\n%1").arg(score / 5 + 1));
        if (score > high_score) {
          high_score = score;
          menu->High_scoreLabel->setText(QString("Record\n%1").arg(high_score));
          file = fopen("high_score.txt", "w");
          fprintf(file, "%d", high_score);
          fclose(file);
        }
      }
    } else {
      menu->setFocus();
      timer->stop();
      score = 0;
      menu->ScoreLabel->setText(QString("Score\n%1").arg(++score));
      direction = UP;
      next_tails.clear();
      init_field_back(field_back, apple);
      init_head_and_tail(head, tail, next_tails);
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
          if (field_back[i][j] == 0)
            cells[i][j]->setStyleSheet("background-color: white;");
          else if (field_back[i][j] == 1)
            cells[i][j]->setStyleSheet("background-color: green;");
          else if (field_back[i][j] == 2)
            cells[i][j]->setStyleSheet("background-color: red;");
        }
      }
    }
  }
}