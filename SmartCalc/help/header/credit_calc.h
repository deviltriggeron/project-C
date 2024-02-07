/**
 *
 * @file credit_calc.h
 *
 */
#ifndef CREDIT_CALC_H
#define CREDIT_CALC_H

#include "../../smart_calc.h"

/**
 * @brief Рассчитывает ежемесячный платеж для аннуитетного кредита
 * @return значение ежемесячного платежа
 */
long double get_monthly_payment_annuity(long double loan_amount,
                                        long double interest_rate, int term);

/**
 * @brief Рассчитывает общую сумму, которая будет выплачена при погашении
 * аннуитетного кредита
 * @return значение общей суммы выплаты
 */
long double get_total_payment_annuity(long double annuity, int term);

/**
 * @brief Рассчитывает ежемесячный платеж для дифференцированного кредита
 * @return значение ежемесячного платежа
 */
long double get_monthly_payment_diff(long double total_payment, int term);

/**
 * @brief Рассчитывает общую сумму, которая будет выплачена при погашении
 * дифференцированного кредита
 * @return значение общей суммы выплаты
 */
long double get_total_payment_diff(long double loan_amount, int term,
                                   long double interest_rate);

/**
 * @brief Расчет погашения кредита
 * @return сумма погашения
 */
long double get_overpayment_on_credit(long double loan_amount,
                                      long double total_payment);

#endif
