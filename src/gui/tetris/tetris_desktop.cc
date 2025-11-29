#include "desktop/frontend.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  int highscore;
  FILE *file;
  file = fopen("games/tetris_desktop_build/high_score.txt", "r");
  fscanf(file, "%d", &highscore);
  fclose(file);

  QWidget win;
  win.setWindowTitle("Tetris");
  win.resize(691, 800);

  QHBoxLayout *winLayout = new QHBoxLayout(&win);
  winLayout->setContentsMargins(0, 0, 0, 0);
  winLayout->setSpacing(0);

  QFrame *divider = new QFrame();
  divider->setFrameShape(QFrame::VLine);
  divider->setLineWidth(2);
  divider->setStyleSheet("background-color: black;");

  GameFieldWidget win1(file, highscore);
  MenuWidget menu(highscore, win1.next_figure, win1.styles, win1.score, &win1);

  winLayout->addWidget(&win1, 11);
  winLayout->addWidget(divider, 1);
  winLayout->addWidget(&menu, 7);

  win.show();

  return app.exec();
}