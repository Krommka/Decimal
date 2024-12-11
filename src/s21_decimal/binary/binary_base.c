#include "binary.h"

s21_int256 s21_inverse_int256(s21_int256 data) {
  for (int grade_index = 0; grade_index < FULL_INT256; grade_index += BLOCK)
    GET_GRADE(data, grade_index) = ~GET_GRADE(data, grade_index);

  return data;
}

s21_int256 s21_negative_int256(s21_int256 data) {
  return s21_binary_addition(s21_inverse_int256(data), INT256(1));
}

void s21_set_grade_bit(int *grade, int index) { *grade |= (1U << index); }

void s21_set_bit(s21_int256 *data, int index) {
  s21_set_grade_bit(&GET_GRADE(*data, index), index % BLOCK);
}

int s21_is_set_grade_bit(int grade, int index) {
  return !!(grade & (1U << index));
}

int s21_is_set_bit(s21_int256 data, int index) {
  return s21_is_set_grade_bit(GET_GRADE(data, index), index % BLOCK);
}

void s21_reset_grade_bit(int *grade, int index) { *grade &= ~(1U << index); }

void s21_reset_bit(s21_int256 *data, int index) {
  s21_reset_grade_bit(&GET_GRADE(*data, index), index % BLOCK);
}
