#include "credit.h"

#include "mainwindow.h"
#include "ui_credit.h"

Credit::Credit(QWidget *parent) : QWidget(parent), ui(new Ui::Credit) {
  ui->setupUi(this);
}

Credit::~Credit() { delete ui; }

/**
 *
 * @brief метод вывода подсчета кредитного калькулятора
 *
 */
void Credit::on_equal_clicked() {
  if (ui->loan->text().isEmpty() || ui->term->text().isEmpty() ||
      ui->percent->text().isEmpty()) {
    ui->total->setText("Error");
    ui->mounthly_pay->setText("Error");
    ui->overpayment->setText("Error");
  } else {
    long double loan_amount = ui->loan->text().toDouble();
    long double interest_rate = ui->percent->text().toDouble();
    int term = ui->term->text().toInt();
    long double total_payment;
    long double monthly_payment;
    long double overpayment;
    if (ui->diff->isChecked()) {
      total_payment = get_total_payment_diff(loan_amount, term, interest_rate);
      monthly_payment = get_monthly_payment_diff(total_payment, term);
      overpayment = get_overpayment_on_credit(loan_amount, total_payment);
    } else {
      monthly_payment =
          get_monthly_payment_annuity(loan_amount, interest_rate, term);
      total_payment = get_total_payment_annuity(monthly_payment, term);
      overpayment = get_overpayment_on_credit(loan_amount, total_payment);
    }
    QString tp = QString::number(total_payment, 'g', 7);
    QString mp = QString::number(monthly_payment, 'g', 7);
    QString over = QString::number(overpayment, 'g', 7);
    ui->total->setText(tp);
    ui->mounthly_pay->setText(mp);
    ui->overpayment->setText(over);
  }
}
