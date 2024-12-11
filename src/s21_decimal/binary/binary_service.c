#include "binary.h"

int s21_compare_int256(s21_int256 value_1, s21_int256 value_2) {
  int result = 0;

  for (int index = FULL_INT256 - 1; !result && index >= 0; index--)
    result = s21_is_set_bit(value_1, index) - s21_is_set_bit(value_2, index);

  return result;
}

int s21_int256_is_not_zero(s21_int256 data) {
  int result = 0;

  for (int block_index = 0; !result && block_index < FULL_INT256;
       block_index += BLOCK)
    result = !!(GET_GRADE(data, block_index));

  return result;
}

int s21_highest_bit(s21_int256 data) {
  int result_index = 0;

  for (int i = FULL_INT256 - 1; !result_index && i >= 0; i--)
    if (s21_is_set_bit(data, i)) result_index = i;

  return result_index;
}
