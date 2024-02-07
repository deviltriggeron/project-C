/**
 *
 * @file main.cpp
 *
 */
#include <QApplication>

#include "mainwindow.h"

/**
 * @mainpage Документация по проекту SmartCalc v1.0
 *
 * В данном проекте на языке программирования C реализован расширенный
 * калькулятор с использованием структурного подхода. Он включает базовые
 * арифметические операции, а также возможность вычисления сложных
 * арифметических выражений с приоритетами. Кроме того, калькулятор поддерживает
 * математические функции, такие как синус, косинус, логарифм и другие. Он также
 * предоставляет возможность использования переменной "x" и построения графика
 * соответствующей функции. Так же есть возможность то как будет выглядить
 * выражение в обратной польской нотации.
 *
 */
int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow *smartCalc = new MainWindow;
  smartCalc->setFixedWidth(739);
  smartCalc->setFixedHeight(577);
  smartCalc->show();
  return a.exec();
}
