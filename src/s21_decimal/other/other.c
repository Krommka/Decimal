#include "other.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int rc = OK;

  if (!(rc = !!s21_check_bit3_decimal(value)) && !(rc = !result)) {
    s21_decimal_set_sign(&value, !SIGN_DEC(value));

    *result = value;
  }

  return rc;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  return s21_round_decimal(value, result, TRUNCATE_ROUND);
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  return s21_round_decimal(value, result,
                           SIGN_DEC(value) ? CEIL_ROUND : FLOOR_ROUND);
}

int s21_round(s21_decimal value, s21_decimal *result) {
  return s21_round_decimal(value, result, BASIC_ROUND);
}
