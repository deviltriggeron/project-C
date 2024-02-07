/**
 *
 * @file mainwindow.cpp
 *
 */
#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  slot();
  connect(this, &MainWindow::Plot, &Graph, &graph::plot_slot);
}

MainWindow::~MainWindow() { delete ui; }
/**
 *
 * @brief метод ввода чисел из клавиатуры
 *
 */
void MainWindow::keyPressEvent(QKeyEvent *e) {
  QString newText = ui->label->text();
  if (ui->label->text() == "0") ui->label->setText("");
  if (e->key() == Qt::Key_Backspace) {
    if (!newText.isEmpty()) {
      newText.chop(1);
      ui->label->setText(newText);
    } else if (newText == "") {
      ui->label->setText("0");
    }
  }
  if (e->key() == Qt::Key_C) ui->label->setText("0");
  if (e->key() == Qt::Key_0) ui->label->setText(ui->label->text() + '0');
  if (e->key() == Qt::Key_1) ui->label->setText(ui->label->text() + '1');
  if (e->key() == Qt::Key_2) ui->label->setText(ui->label->text() + '2');
  if (e->key() == Qt::Key_3) ui->label->setText(ui->label->text() + '3');
  if (e->key() == Qt::Key_4) ui->label->setText(ui->label->text() + '4');
  if (e->key() == Qt::Key_5) ui->label->setText(ui->label->text() + '5');
  if (e->key() == Qt::Key_6) ui->label->setText(ui->label->text() + '6');
  if (e->key() == Qt::Key_7) ui->label->setText(ui->label->text() + '7');
  if (e->key() == Qt::Key_8) ui->label->setText(ui->label->text() + '8');
  if (e->key() == Qt::Key_9) ui->label->setText(ui->label->text() + '9');
  if (e->key() == Qt::Key_Plus) ui->label->setText(ui->label->text() + "+");
  if (e->key() == Qt::Key_Minus) ui->label->setText(ui->label->text() + "-");
  if (e->key() == Qt::Key_Asterisk) ui->label->setText(ui->label->text() + "*");
  if (e->key() == Qt::Key_Slash) ui->label->setText(ui->label->text() + "/");
  if (e->key() == Qt::Key_AsciiCircum)
    ui->label->setText(ui->label->text() + "^");
  if (e->key() == Qt::Key_Period) ui->label->setText(ui->label->text() + ".");
  if (e->key() == Qt::Key_ParenLeft)
    ui->label->setText(ui->label->text() + "(");
  if (e->key() == Qt::Key_ParenRight)
    ui->label->setText(ui->label->text() + ")");
  if (e->key() == Qt::Key_Return || e->key() == Qt::Key_Equal) equal();
}

/**
 *
 * @brief соеденение кнопок калькулятора с самим калькулятором
 *
 */
void MainWindow::slot() {
  connect(ui->pushButton0, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton1, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton2, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton3, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton4, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton5, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton6, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton7, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton8, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton9, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operation()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(math_operation()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(math_operation()));
  connect(ui->pushButton_divide, SIGNAL(clicked()), this,
          SLOT(math_operation()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(math_operation()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(math_operation()));
  connect(ui->pushButton_C, SIGNAL(clicked()), this, SLOT(math_operation()));
  connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(equal()));
  connect(ui->pushButton_equal, SIGNAL(clicked()), this,
          SLOT(math_operation()));
  connect(ui->pushButton_openBracket, SIGNAL(clicked()), this,
          SLOT(on_clicked()));
  connect(ui->pushButton_closeBracket, SIGNAL(clicked()), this,
          SLOT(on_clicked()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(math_operation()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_clear, SIGNAL(clicked()), this, SLOT(on_clear()));
  connect(ui->pushButtonX, SIGNAL(clicked()), this, SLOT(on_clicked()));
}

/**
 *
 * @brief метод вывода нажатой кнопки
 *
 */
void MainWindow::on_clicked() {
  QPushButton *pressed_btn = (QPushButton *)sender();
  QString new_label;
  if (ui->label->text() == "0")
    new_label = pressed_btn->text();
  else
    new_label = (ui->label->text() + pressed_btn->text());
  ui->label->setText(new_label);
}

/**
 *
 * @brief метод вывода математический операторов
 *
 */
void MainWindow::math_operation() {
  QPushButton *pressed_btn = (QPushButton *)sender();
  if (pressed_btn->text() == '+') {
    ui->label->setText(ui->label->text() + "+");
  }
  if (pressed_btn->text() == '-') {
    ui->label->setText(ui->label->text() + "-");
  }
  if (pressed_btn->text() == '*') {
    ui->label->setText(ui->label->text() + "*");
  }
  if (pressed_btn->text() == "÷") {
    ui->label->setText(ui->label->text() + "/");
  }
  if (pressed_btn->text() == '^') {
    ui->label->setText(ui->label->text() + "^");
  }
  if (pressed_btn->text() == "mod") {
    ui->label->setText(ui->label->text() + "m");
  }
  if (pressed_btn->text() == ".") {
    if (!(ui->label->text().at(ui->label->text().size() - 1) == '.'))
      ui->label->setText(ui->label->text() + ".");
  }
  if (pressed_btn->text() == "C") {
    QString newText = ui->label->text();
    if (!newText.isEmpty()) {
      newText.chop(1);
      ui->label->setText(newText);
    } else if (newText == "") {
      ui->label->setText("0");
    }
  }
}

/**
 *
 * @brief метод вывода графика
 *
 */
void MainWindow::on_graph_stateChanged(int arg1) {
  if (arg1) {
    Graph.show();
    Graph.setFixedWidth(739);
    Graph.setFixedHeight(577);
    Graph.move(1650, 367);
  } else {
    Graph.hide();
  }
}

/**
 *
 * @brief Метод для подсчёта результата и вывода его в строку ввода / вывода
 * при нажатии кпонки '=' тремя способами: кнопка '=' на клавиатуре вашего
 * девайса, кнопка '=' в самом калькуляторе, кнопка "enter" на вашей клавиатуре
 *
 */
void MainWindow::equal() {
  std::string str = ui->label->text().toStdString();
  const char *cstr = str.c_str();
  bool status = false;

  if (ui->pushButton_equal->text() == "=") {
    char res_str[MAX_LEN * 2] = {'\0'};
    status = calc_notation(cstr, res_str);
    if (!status) {
      ui->rpn->setText(res_str);
    } else {
      ui->rpn->setText("Error");
    }
    long double res = 0;
    status = calc_str(cstr, &res);
    if (!status) {
      QString result = QString::number(res, 'g', 7);
      ui->label->setText(result);
    } else {
      ui->label->setText("Error");
    }
    if (!ui->input_x->text().isEmpty()) {
      long double res_x = 0;
      status = calc_with_x(cstr, (long double)ui->input_x->text().toDouble(),
                           &res_x);
      if (!status) {
        QString res_with_x = QString::number(res_x, 'g', 7);
        ui->label->setText(res_with_x);
      } else {
        ui->label->setText("Error");
      }
    }
    emit Plot(cstr);
  }
}

/**
 *
 * @brief Метод для очистки строки ввода / вывода
 *
 */
void MainWindow::on_clear() { ui->label->setText("0"); }

/**
 *
 * @brief метод вывода кредитного калькулятора
 *
 */
void MainWindow::on_CreditCalc_stateChanged(int arg1) {
  if (arg1) {
    CreditCalc.show();
    CreditCalc.setFixedWidth(739);
    CreditCalc.setFixedHeight(454);
    CreditCalc.move(171, 367);
  } else {
    CreditCalc.hide();
  }
}

/**
 *
 * @brief PIZZA TIME!!!
 *
 */
void MainWindow::on_PIZZA_TIME_clicked() {
  QDesktopServices::openUrl(QUrl("https://dodopizza.ru/novosibirsk"));
}
