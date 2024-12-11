#include "conversion.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int code = OK;
  double df = 0;
  int exponent = EXP_DEC(src);
  s21_int256 data = DECIMAL_TO_INT256(src);

  if (!dst || s21_check_bit3_decimal(src))
    code = ERROR;
  else if (!s21_int256_is_not_zero(DECIMAL_TO_INT256(src))) {
    float_part f_p = NEW;

    if (SIGN_DEC(src) == NEGATIVE) SIGN(f_p) = NEGATIVE;

    *dst = f_p.f;
  } else if (s21_int256_is_not_zero(data)) {
    s21_int256_to_double(&data, &df);

    double div = 1.0;
    while (exponent-- > 0) div *= 10;

    df /= div;

    if (SIGN_DEC(src)) df *= -1.;
    if (dst) *dst = (float)df;
  }

  return code;
}

void s21_int256_to_double(s21_int256 *data, double *src) {
  s21_int256 mantiss = *data;
  int highest_bit_of_data = s21_highest_bit(mantiss);
  int shift = 52 - highest_bit_of_data;

  if (shift >= 0)
    mantiss = s21_shift_left(mantiss, shift);
  else {
    mantiss = s21_shift_right(mantiss, (-shift) - 1);

    if (s21_is_set_bit(mantiss, 0)) s21_set_bit(&mantiss, 1);

    mantiss = s21_shift_right(mantiss, 1);
  }
  s21_reset_bit(&mantiss, 52);

  double_part parsed_src = NEW;
  uint64_t_part parsed_uint;
  parsed_uint.parse.bit0 = mantiss.decimals[0].bits[0];
  parsed_uint.parse.bit1 = mantiss.decimals[0].bits[1];
  parsed_src.parse.mantiss = parsed_uint.uint;
  parsed_src.parse.exponent = 1023 + highest_bit_of_data;

  *src = parsed_src.df;
}
