#include "binary.h"

void s21_shift_left_one(s21_int256 *data);
void s21_shift_right_one(s21_int256 *data);

s21_int256 s21_shift_left(s21_int256 data, int shifts) {
  while (shifts-- > 0) s21_shift_left_one(&data);

  return data;
}

s21_int256 s21_shift_right(s21_int256 data, int shifts) {
  while (shifts-- > 0) s21_shift_right_one(&data);

  return data;
}

void s21_shift_left_one(s21_int256 *data) {
  int overflow = 0;

  for (int block_index = 0; block_index < FULL_INT256; block_index += BLOCK) {
    overflow |= s21_is_set_grade_bit(GET_GRADE(*data, block_index), BLOCK - 1);

    GET_GRADE(*data, block_index) <<= 1;

    if (s21_is_set_grade_bit(overflow, 1))
      s21_set_grade_bit(&GET_GRADE(*data, block_index), 0);

    overflow <<= 1;
  }
}

void s21_shift_right_one(s21_int256 *data) {
  int overflow = 0;

  for (int grade_index = FULL_INT256 - BLOCK; grade_index >= 0;
       grade_index -= BLOCK) {
    overflow |= s21_is_set_bit(*data, grade_index);

    GET_GRADE(*data, grade_index) >>= 1;

    if (s21_is_set_grade_bit(overflow, 1))
      s21_set_bit(data, grade_index + BLOCK - 1);
    else if (s21_is_set_grade_bit(GET_GRADE(*data, grade_index), BLOCK - 1))
      s21_reset_bit(data, grade_index + BLOCK - 1);

    overflow <<= 1;
  }
}
