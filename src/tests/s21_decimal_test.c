#include "s21_decimal_test.h"

int main(void) {
  int failed = 0;

  Suite* tests[] = {s21_add_test(),
                    s21_div_test(),
                    s21_mul_test(),
                    s21_sub_test(),
                    s21_float_to_decimal_test(),
                    s21_decimal_to_float_test(),
                    s21_int_to_decimal_test(),
                    s21_less_test(),
                    s21_less_or_equal_test(),
                    s21_greater_test(),
                    s21_greater_or_equal_test(),
                    s21_equal_test(),
                    s21_not_equal_test(),
                    s21_negate_test(),
                    s21_truncate_test(),
                    s21_floor_test(),
                    s21_round_test(),
                    s21_decimal_to_int_test()};
  for (int i = 0; i < 18; i++) {
    SRunner* runner = srunner_create(tests[i]);
    srunner_run_all(runner, CK_NORMAL);
    if (srunner_ntests_failed(runner) != 0) {
      failed = srunner_ntests_failed(runner);
    }
    srunner_free(runner);
  }

  return (failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}
