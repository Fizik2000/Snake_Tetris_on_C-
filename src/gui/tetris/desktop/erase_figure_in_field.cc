#include "frontend.h"

void GameFieldWidget::erase_figure_in_field(int (*figure)[4], int figure_x,
                                            int figure_y) {
  QVector<QString> styles;
  styles.push_front("background-color: white;");
  int l = 4 < figure_y + 1 ? 4 : figure_y + 1;
  for (int i = 0; i < l; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (figure[3 - i][j]) {
        setCellColor(figure_y - i, figure_x + j, styles, 0);
      }
    }
  }
}