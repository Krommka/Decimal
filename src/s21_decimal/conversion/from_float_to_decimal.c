#include <math.h>

#include "conversion.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int code = OK;

  s21_int256 data = NEW;
  decimal_bit3 bit3 = NEW;

  if (!dst)
    code = ERROR;
  else if (src == 0.0) {
    data = INT256(0);

    if (SIGN(FLOAT_PART(src)) == NEGATIVE) SIGN(bit3) = NEGATIVE;
  } else if (isinf(src) || isnan(src)) {
    code = ERROR;
    data = DECIMAL_TO_INT256(DECIMAL_INF);
  } else
    s21_float_to_int256(src, &data, &bit3);

  if (!code) code = s21_int256_to_decimal(data, dst, bit3);

  if (!code) {
    s21_decimal tmp = *dst;
    data = DECIMAL_TO_INT256(tmp);
    s21_int256_round_seven_digit(&data);
    *dst = INT256_TO_DECIMAL(data);
    dst->bits[3] = tmp.bits[3];
  }

  return !!code;
}

void s21_float_to_int256(float src, s21_int256 *data, decimal_bit3 *bit3) {
  float_part parsed_src = FLOAT_PART(src);
  s21_int256 mantiss = INT256(MANTISS(parsed_src));
  int exponent = EXP(parsed_src) - BIAS;
  int exponent_decimal = 0;

  s21_set_bit(&mantiss, MAX_BIT_DECIMAL_MANTISS);

  if (exponent < MAX_BIT_DECIMAL_MANTISS) {
    s21_int256 max_mantiss = NEW;

    s21_set_bit(&max_mantiss, MAX_BIT_DECIMAL_MANTISS - exponent);
    *data = s21_binary_fractional_division(mantiss, max_mantiss, NULL,
                                           &exponent_decimal);
  } else
    *data = s21_shift_left(mantiss, exponent - MAX_BIT_DECIMAL_MANTISS);

  SIGN(parsed_src) ? SIGN(*bit3) = 1 : 0;
  EXP(*bit3) = exponent_decimal;
}

void s21_int256_round_seven_digit(s21_int256 *data) {
  int highest_digit = s21_int256_highest_digit(*data);
  int rounder = highest_digit > 7 ? highest_digit - 7 : 0;

  *data = s21_round_to_decimal(*data, rounder, BANK_ROUND);

  *data =
      s21_binary_multiplication(*data, s21_decimal_exp(DECIMAL(1), rounder));
}
