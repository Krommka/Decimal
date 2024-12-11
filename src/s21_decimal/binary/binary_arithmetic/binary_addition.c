#include "../binary.h"

int s21_binary_addition_algorithm(const s21_int256 value_1,
                                  const s21_int256 value_2, s21_int256 *result,
                                  int index) {
  int overflow = 0;

  if (index > 0)
    overflow =
        s21_binary_addition_algorithm(value_1, value_2, result, index - 1);

  int sum = s21_is_set_bit(value_1, index) + s21_is_set_bit(value_2, index) +
            overflow;

  if (sum % 2 != 0) s21_set_bit(result, index);

  return sum > 1 ? 1 : 0;
}

s21_int256 s21_binary_addition(s21_int256 value_1, s21_int256 value_2) {
  s21_int256 result = NEW;

  s21_binary_addition_algorithm(value_1, value_2, &result, FULL_INT256 - 1);

  return result;
}
