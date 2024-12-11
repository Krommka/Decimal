#ifndef CHECK_DECIMAL_TEST_H
#define CHECK_DECIMAL_TEST_H

#include "s21_test_help.h"

#define TEST_ERROR_CODE_OK 0
#define TEST_ERROR_CODE_BIG 1
#define TEST_ERROR_CODE_SMALL 2
#define TEST_ERROR_CODE_DIV_ZERO 3
#define TEST_ERROR_CODE_FLOAT 1
#define TEST_ERROR_CODE_INT 1
#define TRUE 1
#define FALSE 0

Suite *s21_add_test(void);
Suite *s21_div_test(void);
Suite *s21_mul_test(void);
Suite *s21_sub_test(void);

Suite *s21_float_to_decimal_test(void);
Suite *s21_decimal_to_float_test(void);
Suite *s21_int_to_decimal_test(void);
Suite *s21_decimal_to_int_test(void);

Suite *s21_less_test(void);
Suite *s21_less_or_equal_test(void);
Suite *s21_greater_test(void);
Suite *s21_greater_or_equal_test(void);
Suite *s21_equal_test(void);
Suite *s21_not_equal_test(void);

Suite *s21_negate_test(void);
Suite *s21_truncate_test(void);
Suite *s21_floor_test(void);
Suite *s21_round_test(void);

#endif
