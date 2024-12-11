#include "comparison.h"

int s21_compare(s21_decimal value_1, s21_decimal value_2) {
  s21_int256 data_1 = NEW;
  s21_int256 data_2 = NEW;

  s21_preprocessing(value_1, value_2, &data_1, &data_2);

  if (!s21_int256_is_not_zero(data_1)) s21_decimal_set_sign(&value_1, POSITIVE);
  if (!s21_int256_is_not_zero(data_2)) s21_decimal_set_sign(&value_2, POSITIVE);

  int sign = SIGN_DEC(value_1) ^ SIGN_DEC(value_2) ? -1 : 1;

  return s21_compare_int256(data_1, data_2) * sign;
}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  return (s21_compare(value_1, value_2) == 0);
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  return (s21_compare(value_1, value_2) != 0);
}

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  return (s21_compare(value_1, value_2) < 0);
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return (s21_compare(value_1, value_2) <= 0);
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  return (s21_compare(value_1, value_2) > 0);
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return (s21_compare(value_1, value_2) >= 0);
}
