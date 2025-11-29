#include "frontend.h"

void GameFieldWidget::set_field_after_full_rows(int (*field_back)[10],
                                                QVector<QString>& styles,
                                                int figure_y) {
  // wattron(win, COLOR_PAIR(4));
  for (int i = figure_y; i >= 0; --i) {
    for (int j = 0; j < 10; ++j) {
      setCellColor(i, j, styles, field_back[i][j]);
    }
  }
}
