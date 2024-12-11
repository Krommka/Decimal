#ifndef CHECK_TEST_HELP_H
#define CHECK_TEST_HELP_H

#include <check.h>
#include <math.h>

#include "../s21_decimal.h"

#ifdef DEBUG

#include "stdio.h"

void s21_print_int256(s21_int256 int256);
void s21_print_decimal(s21_decimal data);

#endif

void s21_test_div(s21_decimal decimal1, s21_decimal decimal2,
                  s21_decimal expected, int expected_error_code, int test_num);
void s21_test_mul(s21_decimal decimal1, s21_decimal decimal2,
                  s21_decimal expected, int expected_error_code, int test_num);
void s21_test_sub(s21_decimal decimal1, s21_decimal decimal2,
                  s21_decimal expected, int expected_error_code, int test_num);
void s21_test_add(s21_decimal decimal1, s21_decimal decimal2,
                  s21_decimal expected, int expected_error_code, int test_num);

void s21_test_float_to_decimal(float flt, s21_decimal expected,
                               int expected_error_code, int test_num);
void s21_test_decimal_to_float(s21_decimal decimal, float flt,
                               int expected_error_code, int test_num);
void s21_test_int_to_decimal(int num, s21_decimal expected,
                             int expected_error_code, int test_num);
void s21_test_decimal_to_int(s21_decimal decimal, int expected,
                             int expected_error_code, int test_num);

void s21_test_less(s21_decimal decimal1, s21_decimal decimal2, int expected,
                   int test_num);
void s21_test_less_or_equal(s21_decimal decimal1, s21_decimal decimal2,
                            int expected, int test_num);
void s21_test_greater(s21_decimal decimal1, s21_decimal decimal2, int expected,
                      int test_num);
void s21_test_greater_or_equal(s21_decimal decimal1, s21_decimal decimal2,
                               int expected, int test_num);
void s21_test_equal(s21_decimal decimal1, s21_decimal decimal2, int expected,
                    int test_num);
void s21_test_not_equal(s21_decimal decimal1, s21_decimal decimal2,
                        int expected, int test_num);

void s21_test_negate(s21_decimal decimal, s21_decimal expected,
                     int expected_error_code, int test_num);
void s21_test_truncate(s21_decimal decimal, s21_decimal expected,
                       int expected_error_code, int test_num);
void s21_test_floor(s21_decimal decimal, s21_decimal expected,
                    int expected_error_code, int test_num);
void s21_test_round(s21_decimal decimal, s21_decimal expected,
                    int expected_error_code, int test_num);

#endif
