#include "arithmetic_service.h"

int s21_round_decimal(s21_decimal value, s21_decimal *result, round_mode mode) {
  int rc = 0;

  if (!(rc = !!s21_check_bit3_decimal(value)) && !(rc = !result)) {
    s21_int256 data =
        s21_round_to_decimal(DECIMAL_TO_INT256(value), EXP_DEC(value), mode);

    *result = INT256_TO_DECIMAL(data);

    s21_decimal_set_sign(result, SIGN_DEC(value));
  }

  return rc;
}

int s21_round_conditions(int remainder, round_mode mode) {
  int round = (mode == CEIL_ROUND) ? 1 : 0;

  if (mode == BASIC_ROUND || mode == BANK_ROUND) round = remainder < 5 ? 0 : 1;

  return round;
}

int s21_find_rounder(s21_int256 data) {
  s21_int256 result = NEW;
  s21_int256 remainder = NEW;

  result =
      s21_binary_division(data, DECIMAL_TO_INT256(DECIMAL_MAX), &remainder);

  if (s21_compare_int256(result, remainder) > 0)
    result = s21_binary_addition(result, s21_negative_int256(INT256(1)));

  return s21_int256_highest_digit(result);
}

s21_int256 s21_find_remainder(s21_int256 *data, int rounder) {
  s21_int256 remainder = NEW;

  *data = s21_binary_division(*data, s21_decimal_exp(DECIMAL(1), rounder),
                              &remainder);

  return remainder;
}

int s21_round_float_part(s21_int256 data, s21_int256 remainder, int exp,
                         round_mode mode) {
  int round = 0;
  s21_int256 rem_remainder = NEW;

  remainder = s21_binary_division(
      remainder, s21_decimal_exp(DECIMAL(1), exp - 1), &rem_remainder);

  if (mode == BANK_ROUND &&
      s21_is_equal(INT256_TO_DECIMAL(remainder), DECIMAL(5)) &&
      !s21_int256_is_not_zero(rem_remainder))
    round = s21_is_set_bit(data, 0);
  else if (s21_int256_is_not_zero(remainder) ||
           s21_int256_is_not_zero(rem_remainder))
    round = s21_round_conditions(GET_GRADE(remainder, 0), mode);

  return round;
}

s21_int256 s21_round_to_decimal(s21_int256 data, int rounder, round_mode mode) {
  s21_int256 remainder = NEW;

  remainder = s21_find_remainder(&data, rounder);

  if (s21_round_float_part(data, remainder, rounder, mode))
    data = s21_binary_addition(data, INT256(1));

  return data;
}
