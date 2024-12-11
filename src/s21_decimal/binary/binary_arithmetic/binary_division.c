#include "../binary.h"

s21_int256 s21_binary_division(s21_int256 divisible, s21_int256 divider,
                               s21_int256 *remainder) {
  s21_int256 result = NEW;

  int sign = 0;
  int shifts = s21_highest_bit(divisible) - s21_highest_bit(divider);

  s21_int256 pos_shift = s21_shift_left(divider, shifts);
  s21_int256 neg_shift = s21_negative_int256(pos_shift);

  for (int i = shifts; i >= 0; i--) {
    divisible = s21_binary_addition(divisible, sign ? pos_shift : neg_shift);

    sign = s21_is_set_bit(divisible, FULL_INT256 - 1);

    if (i) divisible = s21_shift_left(divisible, 1);

    result = s21_shift_left(result, 1);

    if (!sign) s21_set_bit(&result, 0);
  }

  if (remainder) {
    if (s21_is_set_bit(divisible, FULL_INT256 - 1))
      divisible = s21_binary_addition(divisible, pos_shift);

    *remainder = s21_shift_right(divisible, shifts);
  }

  return result;
}

#include <stdio.h>

s21_int256 s21_binary_fractional_division(s21_int256 divisible,
                                          s21_int256 divider,
                                          s21_int256 *remainder, int *exp) {
  s21_int256 tmp_res_remainder = NEW;
  s21_int256 tmp_remainder = NEW;

  divisible = s21_binary_division(divisible, divider, &tmp_res_remainder);

  while (*exp < 0 || ((s21_highest_bit(divisible) < FULL_INT256 - BLOCK) &&
                      s21_int256_is_not_zero(tmp_res_remainder))) {
    divisible = s21_mul10(divisible);
    tmp_res_remainder = s21_mul10(tmp_res_remainder);
    tmp_res_remainder =
        s21_binary_division(tmp_res_remainder, divider, &tmp_remainder);
    divisible = s21_binary_addition(divisible, tmp_res_remainder);
    tmp_res_remainder = tmp_remainder;

    (*exp)++;
  }

  if (remainder) *remainder = tmp_res_remainder;

  return divisible;
}
