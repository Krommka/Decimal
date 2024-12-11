#include "../s21_test_help.h"

#ifdef DEBUG

void s21_print_debug_other(s21_decimal decimal, s21_decimal result,
                           s21_decimal expected, int error_code,
                           int expected_error_code, char *test_name,
                           int test_num) {
  printf(
      "\n\033[36m------------------------- %s - %02d "
      "-------------------------\033[0m\n\n",
      test_name, test_num);

  printf("\033[33m%s\033[0m\n", "decimal:");
  s21_print_int256(DECIMAL_TO_INT256(decimal));

  printf("\033[31m%s\033[0m\n", "result:");
  s21_print_int256(DECIMAL_TO_INT256(result));
  s21_print_decimal(result);

  printf("\033[32m%s\033[0m\n", "expected:");
  s21_print_int256(DECIMAL_TO_INT256(expected));
  s21_print_decimal(expected);

  printf("\033[36m%-21s%d\n%s%d\033[0m\n\n", "error code: ", error_code,
         "expected error code: ", expected_error_code);

  printf(
      "\033[36m----------------------------------------------------------------"
      "-\033[0m\n");
}

#endif

void s21_test_other(s21_decimal decimal, s21_decimal expected,
                    int expected_error_code, int test_num,
                    int (*func)(s21_decimal, s21_decimal *), char *test_name) {
  s21_decimal result = NEW;
  (void)test_name;
  (void)test_num;
  int error_code = func(decimal, &result);

#ifdef DEBUG
  if (!s21_is_equal(result, expected) || error_code != expected_error_code)
    s21_print_debug_other(decimal, result, expected, error_code,
                          expected_error_code, test_name, test_num);
#endif

  ck_assert_uint_eq(s21_is_equal(result, expected), 1);
  ck_assert_uint_eq(error_code, expected_error_code);
}

void s21_test_negate(s21_decimal decimal, s21_decimal expected,
                     int expected_error_code, int test_num) {
  s21_test_other(decimal, expected, expected_error_code, test_num, s21_negate,
                 "NEGATE TEST");
}

void s21_test_truncate(s21_decimal decimal, s21_decimal expected,
                       int expected_error_code, int test_num) {
  s21_test_other(decimal, expected, expected_error_code, test_num, s21_truncate,
                 "TRUNCATE TEST");
}

void s21_test_floor(s21_decimal decimal, s21_decimal expected,
                    int expected_error_code, int test_num) {
  s21_test_other(decimal, expected, expected_error_code, test_num, s21_floor,
                 "FLOOR TEST");
}

void s21_test_round(s21_decimal decimal, s21_decimal expected,
                    int expected_error_code, int test_num) {
  s21_test_other(decimal, expected, expected_error_code, test_num, s21_round,
                 "ROUND TEST");
}