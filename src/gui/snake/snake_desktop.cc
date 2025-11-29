#include "desktop/frontend.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  int highscore;
  FILE *file;
  file = fopen("games/snake_desktop_build/high_score.txt", "r");
  fscanf(file, "%d", &highscore);
  fclose(file);

  QWidget win;
  win.setWindowTitle("Snake");
  win.resize(691, 800);

  QHBoxLayout *winLayout = new QHBoxLayout(&win);
  winLayout->setContentsMargins(0, 0, 0, 0);
  winLayout->setSpacing(0);

  QFrame *divider = new QFrame();
  divider->setFrameShape(QFrame::VLine);
  divider->setLineWidth(2);
  divider->setStyleSheet("background-color: black;");

  GameFieldWidget game_win(file, highscore);
  MenuWidget menu(highscore, game_win.score, &game_win);

  winLayout->addWidget(&game_win, 11);
  winLayout->addWidget(divider, 1);
  winLayout->addWidget(&menu, 7);

  win.show();

  return app.exec();
}