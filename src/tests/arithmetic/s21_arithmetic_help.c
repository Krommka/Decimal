#include "../s21_test_help.h"

#ifdef DEBUG

void s21_print_debug(s21_decimal decimal1, s21_decimal decimal2,
                     s21_decimal result, s21_decimal expected, int error_code,
                     int expected_error_code, char *test_name, int test_num) {
  printf(
      "\n\033[36m------------------------- %s - %02d "
      "-------------------------\033[0m\n\n",
      test_name, test_num);

  printf("\033[33m%s\033[0m\n", "decimal 1:");
  s21_print_int256(DECIMAL_TO_INT256(decimal1));

  printf("\033[33m%s\033[0m\n", "decimal 2:");
  s21_print_int256(DECIMAL_TO_INT256(decimal2));

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

void s21_test_func(s21_decimal decimal1, s21_decimal decimal2,
                   s21_decimal expected, int expected_error_code, int test_num,
                   int (*func)(s21_decimal, s21_decimal, s21_decimal *),
                   char *test_name) {
  s21_decimal result = NEW;
  (void)test_name;
  (void)test_num;
  int error_code = func(decimal1, decimal2, &result);

#ifdef DEBUG
  if (!s21_is_equal(result, expected) || error_code != expected_error_code)
    s21_print_debug(decimal1, decimal2, result, expected, error_code,
                    expected_error_code, test_name, test_num);
#endif

  ck_assert_uint_eq(s21_is_equal(result, expected), 1);
  ck_assert_uint_eq(error_code, expected_error_code);
}

void s21_test_div(s21_decimal decimal1, s21_decimal decimal2,
                  s21_decimal expected, int expected_error_code, int test_num) {
  s21_test_func(decimal1, decimal2, expected, expected_error_code, test_num,
                s21_div, "DIV TEST");
}

void s21_test_mul(s21_decimal decimal1, s21_decimal decimal2,
                  s21_decimal expected, int expected_error_code, int test_num) {
  s21_test_func(decimal1, decimal2, expected, expected_error_code, test_num,
                s21_mul, "MUL TEST");
}

void s21_test_sub(s21_decimal decimal1, s21_decimal decimal2,
                  s21_decimal expected, int expected_error_code, int test_num) {
  s21_test_func(decimal1, decimal2, expected, expected_error_code, test_num,
                s21_sub, "SUB TEST");
}

void s21_test_add(s21_decimal decimal1, s21_decimal decimal2,
                  s21_decimal expected, int expected_error_code, int test_num) {
  s21_test_func(decimal1, decimal2, expected, expected_error_code, test_num,
                s21_add, "ADD TEST");
}
