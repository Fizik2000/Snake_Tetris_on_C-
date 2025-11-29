#include "frontend.h"
#include "stdio.h"

NextFigureInMenu::NextFigureInMenu() : QWidget() {
  QGridLayout *layout = new QGridLayout(this);
  layout->setSpacing(1);
  layout->setContentsMargins(0, 0, 0, 0);
  this->setFixedSize(152, 114);

  cells.resize(3);
  for (int i = 0; i < 3; ++i) {
    cells[i].resize(4);
    for (int j = 0; j < 4; ++j) {
      QWidget *cell = new QLabel();
      cell->setStyleSheet("background-color: green;");
      layout->addWidget(cell, i, j);
      cells[i][j] = cell;
    }
  }
}

void NextFigureInMenu::setCellColor(int row, int col, QVector<QString> &styles,
                                    int color) {
  cells[row][col]->setStyleSheet(styles[color]);
}

MenuWidget::MenuWidget(int &highscore, int (&figure)[][4],
                       QVector<QString> &styles, int &score,
                       GameFieldWidget *win1)
    : QWidget(), win1(win1) {
  QFont font("Arial", 19, QFont::Bold);
  // menuWidgetLayout->addStretch();
  QWidget *UpWiget = new QWidget;
  QHBoxLayout *UpWigetLayout = new QHBoxLayout(UpWiget);
  UpWigetLayout->addStretch();
  set_next_figure_in_menu(figure, styles);
  UpWigetLayout->addWidget(&nextFigure);
  UpWigetLayout->addStretch();
  QLabel *ll = new QLabel("Next", this);
  ll->setAlignment(Qt::AlignCenter);
  ll->setFont(font);
  menuWidgetLayout->addWidget(ll);
  menuWidgetLayout->addWidget(UpWiget);
  menuWidgetLayout->addStretch();
  ScoreLabel = new QLabel;
  showScore(ScoreLabel, score);
  menuWidgetLayout->addStretch();

  QStringList texts = {"Start", "Exit"};
  menu_choice = 0;

  for (const QString &text : texts) {
    QLabel *label = new QLabel(text, this);
    label->setAlignment(Qt::AlignCenter);
    label->setFont(font);
    menuWidgetLayout->addWidget(label);
    labels.append(label);
  }
  menuWidgetLayout->addStretch();

  LevelLabel = new QLabel;
  showLevel(LevelLabel, score);
  menuWidgetLayout->addStretch();
  High_scoreLabel = new QLabel;
  showRecord(High_scoreLabel, highscore);

  win1->initialize(this);

  setFocusPolicy(Qt::StrongFocus);
  setFocus();
  labels[menu_choice]->setStyleSheet("color: blue;");
}

void MenuWidget::keyPressEvent(QKeyEvent *event) {
  labels[menu_choice]->setStyleSheet("color: black;");
  if (event->key() == Qt::Key_Up && menu_choice > 0)
    menu_choice--;
  else if (event->key() == Qt::Key_Down && menu_choice < 1)
    menu_choice++;
  else if (event->key() == Qt::Key_Return) {
    if (menu_choice == 0) {
      win1->setFocus();
      win1->timer->start();
    } else
      qApp->quit();
  }
  labels[menu_choice]->setStyleSheet("color: blue;");
}

void MenuWidget::showRecord(QLabel *label, int &highscore) {
  QFont font("Arial", 19, QFont::Bold);
  label->setText(QString("Record\n%1").arg(highscore));
  label->setAlignment(Qt::AlignCenter);
  label->setFont(font);
  menuWidgetLayout->addWidget(label);
}

void MenuWidget::showScore(QLabel *label, int &score) {
  QFont font("Arial", 19, QFont::Bold);
  label->setText(QString("Score\n%1").arg(score));
  label->setAlignment(Qt::AlignCenter);
  label->setFont(font);
  menuWidgetLayout->addWidget(label);
}

void MenuWidget::showLevel(QLabel *label, int &score) {
  QFont font("Arial", 19, QFont::Bold);
  label->setText(QString("Level\n%1").arg(score / 1000));
  label->setAlignment(Qt::AlignCenter);
  label->setFont(font);
  menuWidgetLayout->addWidget(label);
}