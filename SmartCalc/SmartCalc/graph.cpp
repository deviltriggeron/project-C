#include "graph.h"

#include "mainwindow.h"
#include "ui_graph.h"

graph::graph(QWidget *parent) : QWidget(parent), ui(new Ui::graph) {
  ui->setupUi(this);
  ui->customPlot->addGraph();
  ui->customPlot->xAxis->setRange(x_max, y_min);
  ui->customPlot->xAxis->setLabel("X");
  ui->customPlot->yAxis->setRange(y_max, y_min);
  ui->customPlot->yAxis->setLabel("Y");
  ui->customPlot->replot();
}

graph::~graph() { delete ui; }

/**
 *
 * @brief метод построения поля графика
 *
 */
void graph::on_build_graph_clicked() {
  x_min = ui->lineEdit_x_min->text().toDouble();
  x_max = ui->lineEdit_x_max->text().toDouble();
  y_min = ui->lineEdit_y_min->text().toDouble();
  y_max = ui->lineEdit_y_max->text().toDouble();
  X_temp = x_min;
  N = (x_max - x_min) / h_step + 2;
  ui->customPlot->addGraph();
  ui->customPlot->graph(0)->setData(x_vector, y_vector);
  ui->customPlot->xAxis->setRange(x_min, x_max);
  ui->customPlot->xAxis->setLabel("X");
  ui->customPlot->yAxis->setRange(y_min, y_max);
  ui->customPlot->yAxis->setLabel("Y");
  ui->customPlot->replot();
}

/**
 * @brief полученный сигнал
 * @param str полученное выражение
 */
void graph::plot_slot(const char *str) {
  strncpy(math_expression, str, MAX_LEN);
  ui->customPlot->clearGraphs();
  draw_graph();
}

/**
 * @brief отрисовка графика
 */
void graph::draw_graph() {
  h_step = 0.01;
  long double res;
  x_max += h_step;
  N = (x_max - x_min) / h_step + 2;
  for (long double X = x_min; X <= x_max; X += h_step) {
    x_vector.push_back(X);
    calc_with_x(math_expression, X, &res);
    y_vector.push_back(res);
  }

  ui->customPlot->addGraph();
  ui->customPlot->graph(0)->addData(x_vector, y_vector);
  ui->customPlot->replot();

  x_vector.clear();
  y_vector.clear();
}
