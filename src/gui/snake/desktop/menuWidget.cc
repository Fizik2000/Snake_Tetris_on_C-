#include "frontend.h"

MenuWidget::MenuWidget(int &highscore, int &score, GameFieldWidget *game_win)
    : QWidget(), game_win(game_win), score(score), high_score(high_score) {
  QFont font("Arial", 19, QFont::Bold);
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
  menuWidgetLayout->addStretch();

  game_win->initialize(this);

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
      game_win->setFocus();
      game_win->timer->start();
    } else
      qApp->quit();
  }
  labels[menu_choice]->setStyleSheet("color: blue;");
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
  label->setText(QString("Level\n%1").arg(score / 5 + 1));
  label->setAlignment(Qt::AlignCenter);
  label->setFont(font);
  menuWidgetLayout->addWidget(label);
}

void MenuWidget::showRecord(QLabel *label, int &highscore) {
  QFont font("Arial", 19, QFont::Bold);
  label->setText(QString("Record\n%1").arg(highscore));
  label->setAlignment(Qt::AlignCenter);
  label->setFont(font);
  menuWidgetLayout->addWidget(label);
}
