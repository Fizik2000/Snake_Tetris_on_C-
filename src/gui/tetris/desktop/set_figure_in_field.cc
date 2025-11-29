#include "frontend.h"

void GameFieldWidget::set_figure_in_field(int (&figure)[][4], int figure_x,
                                          int figure_y,
                                          QVector<QString>& styles) {
  int l = 4 < figure_y + 1 ? 4 : figure_y + 1;
  for (int i = 0; i < l; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (figure[3 - i][j]) {
        setCellColor(figure_y - i, figure_x + j, styles, figure[3 - i][j]);
      }
    }
  }
}

void MenuWidget::set_next_figure_in_menu(int (&figure)[][4],
                                         QVector<QString>& styles) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 4; ++j) {
      nextFigure.setCellColor(2 - i, j, styles, figure[3 - i][j]);
    }
  }
}