#include "arithmetic_service.h"

s21_int256 s21_decimal_exp(s21_decimal decimal, int exp) {
  s21_int256 result = DECIMAL_TO_INT256(decimal);

  while (exp-- > 0) result = s21_mul10(result);

  return result;
}

int s21_leveling(s21_decimal value_1, s21_decimal value_2, s21_int256 *data_1,
                 s21_int256 *data_2) {
  int exp_1 = EXP_DEC(value_1);
  int exp_2 = EXP_DEC(value_2);

  *data_1 = s21_decimal_exp(value_1, exp_2 - exp_1);
  *data_2 = s21_decimal_exp(value_2, exp_1 - exp_2);

  return MAX(exp_1, exp_2);
}

int s21_preprocessing(s21_decimal value_1, s21_decimal value_2,
                      s21_int256 *data_1, s21_int256 *data_2) {
  int exp = s21_leveling(value_1, value_2, data_1, data_2);

  if (SIGN_DEC(value_1)) *data_1 = s21_negative_int256(*data_1);
  if (SIGN_DEC(value_2)) *data_2 = s21_negative_int256(*data_2);

  return exp;
}

int s21_int256_to_decimal(s21_int256 data, s21_decimal *decimal,
                          decimal_bit3 bit3) {
  int rc = OK;

  int rounder = MAX(s21_find_rounder(data), EXP(bit3) - EXP_LIMIT);

  if (rounder > EXP(bit3))
    rc = SIGN(bit3) ? DECIMAL_SMALL : DECIMAL_BIG;
  else if (s21_int256_is_not_zero(data)) {
    data = s21_round_to_decimal(data, rounder, BANK_ROUND);

    if (!s21_int256_is_not_zero(data)) rc = DECIMAL_SMALL;
  }

  if (s21_highest_bit(data) > FULL_DECIMAL - BLOCK - 1)
    rc = SIGN(bit3) ? DECIMAL_SMALL : DECIMAL_BIG;
  else {
    EXP(bit3) -= rounder;
    *decimal = INT256_TO_DECIMAL(data);
    decimal->bits[3] = bit3.i;
  }

  return rc;
}

void s21_decimal_set_sign(s21_decimal *decimal, int sign) {
  decimal_bit3 bit3 = {.i = decimal->bits[3]};
  SIGN(bit3) = sign;

  decimal->bits[3] = bit3.i;
}

void s21_decimal_set_exp(s21_decimal *decimal, int exp) {
  decimal_bit3 bit3 = {.i = decimal->bits[3]};
  EXP(bit3) = exp;

  decimal->bits[3] = bit3.i;
}

int s21_int256_highest_digit(s21_int256 data) {
  int highest_digit = 0;
  s21_int256 ten = INT256(10);

  while (s21_int256_is_not_zero(data))
    data = s21_binary_division(data, ten, NULL), highest_digit++;

  return highest_digit;
}
