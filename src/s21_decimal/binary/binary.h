#ifndef BINARY_H
#define BINARY_H

#include "../type.h"

#define INT256(value) ((s21_int256){.decimals[0].bits[0] = (value)})

#define GET_BLOCK(index) ((index) / BLOCK)
#define GET_GRADE(int256, index)         \
  ((int256)                              \
       .decimals[(index) / FULL_DECIMAL] \
       .bits[GET_BLOCK((index) % FULL_DECIMAL)])

s21_int256 s21_binary_addition(s21_int256 value_1, s21_int256 value_2);
s21_int256 s21_binary_multiplication(s21_int256 value_1, s21_int256 value_2);
s21_int256 s21_binary_division(s21_int256 divisible, s21_int256 divider,
                               s21_int256 *remainder);
s21_int256 s21_binary_fractional_division(s21_int256 divisible,
                                          s21_int256 divider,
                                          s21_int256 *remainder, int *exp);

s21_int256 s21_mul10(s21_int256 data);

int s21_compare_int256(s21_int256 value_1, s21_int256 value_2);
int s21_int256_is_not_zero(s21_int256 data);
int s21_highest_bit(s21_int256 data);

s21_int256 s21_shift_right(s21_int256 data, int shifts);
s21_int256 s21_shift_left(s21_int256 data, int shifts);

s21_int256 s21_negative_int256(s21_int256 data);

void s21_reset_grade_bit(int *grade, int index);
void s21_reset_bit(s21_int256 *data, int index);
void s21_set_bit(s21_int256 *data, int index);
void s21_set_grade_bit(int *grade, int index);
int s21_is_set_bit(s21_int256 data, int index);
int s21_is_set_grade_bit(int grade, int index);

#endif