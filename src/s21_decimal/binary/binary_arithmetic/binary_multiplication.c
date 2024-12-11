#include "../binary.h"

s21_int256 s21_binary_multiplication(s21_int256 value_1, s21_int256 value_2) {
  s21_int256 result = NEW;

  int size = s21_highest_bit(value_2);

  for (int i = 0; i <= size; i++)
    if (s21_is_set_bit(value_2, i))
      result = s21_binary_addition(result, s21_shift_left(value_1, i));

  return result;
}

s21_int256 s21_mul10(s21_int256 data) {
  return s21_binary_addition(s21_shift_left(data, 1), s21_shift_left(data, 3));
}
