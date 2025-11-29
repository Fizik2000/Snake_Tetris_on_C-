#include "frontend.h"

GameFieldWidget::GameFieldWidget(FILE *file, int &high_score)
    : QWidget(), file(file), high_score(high_score) {
  QGridLayout *layout = new QGridLayout(this);
  layout->setSpacing(1);
  layout->setContentsMargins(0, 0, 0, 0);

  init_styles(styles);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) field_back[i][j] = 0;
  }

  cells.resize(rows);
  for (int i = 0; i < rows; ++i) {
    cells[i].resize(cols);
    for (int j = 0; j < cols; ++j) {
      QWidget *cell = new QLabel();
      cell->setStyleSheet(styles[0]);
      layout->addWidget(cell, i, j);
      cells[i][j] = cell;
    }
  }
  set_figure(figure, n_figure);
  set_figure(next_figure, n_next_figure);  // maybe delete later
  set_figure_in_field_back(field_back, figure, figure_x, figure_y);
  set_figure_in_field(figure, figure_x, figure_y, styles);

  timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &GameFieldWidget::onTimer);
  timer->setInterval(800);
}

void GameFieldWidget::onTimer() {
  if (!is_neighbors_below(field_back, figure, figure_x, figure_y)) {
    erase_figure_in_field(figure, figure_x, figure_y);
    erase_figure_in_field_back(field_back, figure, figure_x, figure_y);
    ++figure_y;
    set_figure_in_field(figure, figure_x, figure_y, styles);
    set_figure_in_field_back(field_back, figure, figure_x, figure_y);
  } else {
    if (figure_y == 0) {
      timer->stop();
      menu->setFocus();
      for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 10; ++j) {
          field_back[i][j] = 0;
          setCellColor(i, j, styles, 0);
        }
      }
      if (score > high_score) {
        high_score = score;
        file = fopen("games/tetris_desktop_build/high_score.txt", "w");
        fprintf(file, "%d", high_score);
        menu->High_scoreLabel->setText(QString("Record\n%1").arg(high_score));
        fclose(file);
      }
    } else {
      int l, l2 = 0;
      while ((l = is_four_row_full(field_back, figure_y)) != -1) {
        set_field_back_after_full_row(field_back, l);
        set_field_after_full_rows(field_back, styles, l);
        score += 100 * ++l2;
      }
      menu->ScoreLabel->setText(QString("Score\n%1").arg(score));
      menu->LevelLabel->setText(QString("Level\n%1").arg(score / 1000));
      figure_y = 0;
      figure_x = 3;
      set_figure(figure, n_next_figure);
      n_figure = n_next_figure;
      n_next_figure = rand() % 7 + 1;
      set_figure(next_figure, n_next_figure);
      menu->set_next_figure_in_menu(next_figure, styles);
    }
  }
}

void GameFieldWidget::setCellColor(int row, int col, QVector<QString> &styles,
                                   int color) {
  cells[row][col]->setStyleSheet(styles[color]);
}

void GameFieldWidget::initialize(MenuWidget *menu) { this->menu = menu; }

void GameFieldWidget::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Right) {
    if (!is_neighbors_right(field_back, figure, figure_x, figure_y)) {
      erase_figure_in_field(figure, figure_x, figure_y);
      erase_figure_in_field_back(field_back, figure, figure_x, figure_y);
      ++figure_x;
      set_figure_in_field(figure, figure_x, figure_y, styles);
      set_figure_in_field_back(field_back, figure, figure_x, figure_y);
    }
  } else if (event->key() == Qt::Key_Left) {
    if (!is_neighbors_left(field_back, figure, figure_x, figure_y)) {
      erase_figure_in_field(figure, figure_x, figure_y);
      erase_figure_in_field_back(field_back, figure, figure_x, figure_y);
      --figure_x;
      set_figure_in_field(figure, figure_x, figure_y, styles);
      set_figure_in_field_back(field_back, figure, figure_x, figure_y);
    }
  } else if (event->key() == Qt::Key_Down) {
    if (!is_neighbors_below(field_back, figure, figure_x, figure_y)) {
      erase_figure_in_field(figure, figure_x, figure_y);
      erase_figure_in_field_back(field_back, figure, figure_x, figure_y);
      ++figure_y;
      set_figure_in_field(figure, figure_x, figure_y, styles);
      set_figure_in_field_back(field_back, figure, figure_x, figure_y);
    }
  } else if (event->key() == Qt::Key_Up) {
    erase_figure_in_field(figure, figure_x, figure_y);
    erase_figure_in_field_back(field_back, figure, figure_x, figure_y);
    if (is_rotation_possible(field_back, figure, figure_x, figure_y))
      rotate(field_back, figure, figure_x);
    set_figure_in_field(figure, figure_x, figure_y, styles);
    set_figure_in_field_back(field_back, figure, figure_x, figure_y);
  } else if (event->key() == Qt::Key_P) {
    menu->setFocus();
    timer->stop();
  }
}