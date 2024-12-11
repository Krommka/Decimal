#include "arithmetic.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int rc = OK;

  if (!(rc = s21_check_input(value_1, value_2, result))) {
    s21_int256 data_res = NEW;

    decimal_bit3 bit3 = NEW;

    SIGN(bit3) = SIGN_DEC(value_1) ^ SIGN_DEC(value_2);
    EXP(bit3) = EXP_DEC(value_1) + EXP_DEC(value_2);

    data_res = s21_binary_multiplication(DECIMAL_TO_INT256(value_1),
                                         DECIMAL_TO_INT256(value_2));

    rc = s21_int256_to_decimal(data_res, result, bit3);
  }

  return rc;
}
