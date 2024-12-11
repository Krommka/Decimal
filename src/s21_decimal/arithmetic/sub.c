#include "arithmetic.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int rc = OK;

  if (!(rc = s21_check_input(value_1, value_2, result)))
    if (!(rc = s21_negate(value_2, &value_2)))
      rc = s21_add(value_1, value_2, result);

  return rc;
}
