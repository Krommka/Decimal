#include "arithmetic.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int rc = OK;

  if (!(rc = s21_check_input(value_1, value_2, result))) {
    s21_int256 data_res = NEW;
    s21_int256 data_1 = NEW;
    s21_int256 data_2 = NEW;

    decimal_bit3 bit3 = NEW;

    EXP(bit3) = s21_preprocessing(value_1, value_2, &data_1, &data_2);

    data_res = s21_binary_addition(data_1, data_2);

    if (s21_is_set_bit(data_res, FULL_INT256 - 1))
      data_res = s21_negative_int256(data_res), SIGN(bit3) = 1;

    rc = s21_int256_to_decimal(data_res, result, bit3);
  }

  return rc;
}
