#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QKeyEvent>
#include <QLineEdit>
#include <QMainWindow>
#include <QWidget>
#include <cstring>

#include "credit.h"
#include "graph.h"

extern "C" {
#include "../smart_calc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 protected:
  void keyPressEvent(QKeyEvent *e) override;

 public slots:
  void on_clicked();
  void on_clear();
  void math_operation();
  void equal();
  void slot();
  void on_CreditCalc_stateChanged(int arg1);
  void on_PIZZA_TIME_clicked();
  void on_graph_stateChanged(int arg1);

 private:
  Ui::MainWindow *ui;
  MainWindow *smartCalc;
  graph Graph;
  Credit CreditCalc;

 signals:
  void Plot(const char *);
};
#endif  // MAINWINDOW_H
