#ifndef GRAPH_H
#define GRAPH_H

#include <QDoubleValidator>
#include <QVector>
#include <QWidget>

#include "qcustomplot.h"

namespace Ui {
class graph;
}

class graph : public QWidget {
  Q_OBJECT

 public:
  explicit graph(QWidget *parent = nullptr);
  ~graph();

 public slots:
  void plot_slot(const char *str);

 private slots:
  void on_build_graph_clicked();
  void draw_graph();

 private:
  Ui::graph *ui;
  QVector<double> x_vector, y_vector;
  double x_min = -5, x_max = 5, y_min = -5, y_max = 5, X_temp, h_step;
  char math_expression[255];
  int N;
};

#endif  // GRAPH_H
