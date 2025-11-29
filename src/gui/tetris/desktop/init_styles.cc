#include "frontend.h"

void GameFieldWidget::init_styles(QVector<QString>& styles) {
  styles.resize(8);
  styles[0] = "background-color: white;";
  styles[1] = "background-color: green;";
  styles[2] = "background-color:  #0000FF;";
  styles[3] = "background-color: red;";
  styles[4] = "background-color: yellow;";
  styles[5] = "background-color: purple;";
  styles[6] = "background-color: #FF7700;";
  styles[7] = "background-color: #008888;";
}