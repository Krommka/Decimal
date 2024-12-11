#include "arithmetic_service.h"

int s21_check_is_zero(s21_decimal decimal) {
  return s21_is_equal(decimal, DECIMAL(0)) ? DIV_BY_ZERO : OK;
}

int s21_check_bit3_decimal(s21_decimal decimal) {
  return (BLANKS(decimal) || EXP_DEC(decimal) > EXP_LIMIT) ? INCORRECT_DATA
                                                           : OK;
}

int s21_check_input(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result) {
  return (!result || s21_check_bit3_decimal(value_1) ||
          s21_check_bit3_decimal(value_2))
             ? INCORRECT_DATA
             : OK;
}
