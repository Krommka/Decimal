#include "../s21_test_help.h"

#ifdef DEBUG

void s21_print_debug_comp(s21_decimal decimal1, s21_decimal decimal2,
                          int result, int expected, char *test_name,
                          int test_num) {
  printf(
      "\n\033[36m------------------------- %s - %02d "
      "-------------------------\033[0m\n\n",
      test_name, test_num);

  printf("\033[33m%s\033[0m\n", "decimal 1:");
  s21_print_int256(DECIMAL_TO_INT256(decimal1));

  printf("\033[33m%s\033[0m\n", "decimal 2:");
  s21_print_int256(DECIMAL_TO_INT256(decimal2));

  printf("\033[33m%s\033[0m\n", "expected :");
  printf("\n%d\n\n", expected);

  printf("\033[33m%s\033[0m\n", "result :");
  printf("\n%d\n\n", result);

  printf(
      "\033[36m----------------------------------------------------------------"
      "-\033[0m\n");
}

#endif

void s21_test_comp(s21_decimal decimal1, s21_decimal decimal2, int expected,
                   int test_num, int (*func)(s21_decimal, s21_decimal),
                   char *test_name) {
  int result = -1;
  (void)test_name;
  (void)test_num;
  result = func(decimal1, decimal2);

#ifdef DEBUG
  if (result != expected)
    s21_print_debug_comp(decimal1, decimal2, result, expected, test_name,
                         test_num);
#endif

  ck_assert_uint_eq(result, expected);
}

void s21_test_less(s21_decimal decimal1, s21_decimal decimal2, int expected,
                   int test_num) {
  s21_test_comp(decimal1, decimal2, expected, test_num, s21_is_less,
                "LESS TEST");
}

void s21_test_less_or_equal(s21_decimal decimal1, s21_decimal decimal2,
                            int expected, int test_num) {
  s21_test_comp(decimal1, decimal2, expected, test_num, s21_is_less_or_equal,
                "LESS OR EQUAL TEST");
}

void s21_test_greater(s21_decimal decimal1, s21_decimal decimal2, int expected,
                      int test_num) {
  s21_test_comp(decimal1, decimal2, expected, test_num, s21_is_greater,
                "GREATER TEST");
}

void s21_test_greater_or_equal(s21_decimal decimal1, s21_decimal decimal2,
                               int expected, int test_num) {
  s21_test_comp(decimal1, decimal2, expected, test_num, s21_is_greater_or_equal,
                "GREATER OR EQUAL TEST");
}

void s21_test_equal(s21_decimal decimal1, s21_decimal decimal2, int expected,
                    int test_num) {
  s21_test_comp(decimal1, decimal2, expected, test_num, s21_is_equal,
                "EQUAL TEST");
}

void s21_test_not_equal(s21_decimal decimal1, s21_decimal decimal2,
                        int expected, int test_num) {
  s21_test_comp(decimal1, decimal2, expected, test_num, s21_is_not_equal,
                "NOT EQUAL TEST");
}
