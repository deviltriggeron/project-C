#ifndef CREDIT_H
#define CREDIT_H

#include <QIntValidator>
#include <QWidget>

namespace Ui {
class Credit;
}

class Credit : public QWidget {
  Q_OBJECT

 public:
  explicit Credit(QWidget *parent = nullptr);
  ~Credit();

 private slots:

  void on_equal_clicked();

 private:
  Ui::Credit *ui;
};

#endif  // CREDIT_H
