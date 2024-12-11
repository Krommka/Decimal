#include "../s21_decimal_test.h"

START_TEST(test_negate_1) {
  s21_decimal decimal = {{0x019C74F5, 0x62CB33F9, 0x1, 0x0}};
  s21_decimal expected = {{0x019C74F5, 0x62CB33F9, 0x1, 0x80000000}};

  s21_test_negate(decimal, expected, TEST_ERROR_CODE_OK, 1);
}

START_TEST(test_negate_2) {
  s21_decimal decimal = {{0x019C74F5, 0x62CB33F9, 0x1, 0x0}};
  s21_decimal expected = {{0x019C74F5, 0x62CB33F9, 0x1, 0x80000000}};

  s21_test_negate(decimal, expected, TEST_ERROR_CODE_OK, 2);
}

START_TEST(test_negate_3) {
  s21_decimal decimal = {{0x6BB, 0x0, 0x0, 0x20000}};
  s21_decimal expected = {{0x6BB, 0x0, 0x0, 0x80020000}};

  s21_test_negate(decimal, expected, TEST_ERROR_CODE_OK, 3);
}

START_TEST(test_negate_4) {
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  s21_decimal expected = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};

  s21_test_negate(decimal, expected, TEST_ERROR_CODE_OK, 4);
}

START_TEST(test_negate_5) {
  s21_decimal decimal = {{0xE052FAB1, 0x1B69B4B, 0x0, 0x90000}};
  s21_decimal expected = {{0xE052FAB1, 0x1B69B4B, 0x0, 0x80090000}};

  s21_test_negate(decimal, expected, TEST_ERROR_CODE_OK, 5);
}

START_TEST(test_negate_6) {
  s21_decimal decimal = {{0xB2400007, 0x19E0C9BA, 0x21E, 0x80160000}};
  s21_decimal expected = {{0xB2400007, 0x19E0C9BA, 0x21E, 0x160000}};

  s21_test_negate(decimal, expected, TEST_ERROR_CODE_OK, 6);
}

START_TEST(test_negate_7) {
  s21_decimal decimal = {{0x11, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = {{0x11, 0x0, 0x0, 0x0}};

  s21_test_negate(decimal, expected, TEST_ERROR_CODE_OK, 7);
}

START_TEST(test_negate_8) {
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal expected = {{0x0, 0x0, 0x0, 0x80000000}};

  s21_test_negate(decimal, expected, TEST_ERROR_CODE_OK, 8);
}

START_TEST(test_negate_9) {
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  s21_test_negate(decimal, expected, TEST_ERROR_CODE_OK, 9);
}

START_TEST(test_negate_10) {
  s21_decimal decimal = {{0xF282E200, 0x95AE8703, 0xE70A1, 0x801B0000}};
  s21_decimal expected = {{0xF282E200, 0x95AE8703, 0xE70A1, 0x1B0000}};

  s21_test_negate(decimal, expected, TEST_ERROR_CODE_OK, 10);
}

START_TEST(test_negate_11) {
  s21_decimal decimal = {{0xF, 0x0, 0x0, 0x80020000}};
  s21_decimal expected = {{0xF, 0x0, 0x0, 0x20000}};

  s21_test_negate(decimal, expected, TEST_ERROR_CODE_OK, 11);
}

START_TEST(test_negate_12) {
  s21_decimal decimal = {{0x15470DCC, 0x0, 0x0, 0x50000}};
  s21_decimal expected = {{0x15470DCC, 0x0, 0x0, 0x80050000}};

  s21_test_negate(decimal, expected, TEST_ERROR_CODE_OK, 12);
}

START_TEST(test_negate_13) {
  // NULL
  s21_decimal decimal = {0};
  s21_decimal *result = NULL;
  int expected_error_code = 1;
  int error_code = s21_negate(decimal, result);
  ck_assert_int_eq(error_code, expected_error_code);
}

START_TEST(test_negate_14) {
  s21_decimal decimal = {{0x93BC012F, 0x6124FEE9, 0x0, 0x80030000}};
  s21_decimal expected = {{0x93BC012F, 0x6124FEE9, 0x0, 0x30000}};

  s21_test_negate(decimal, expected, TEST_ERROR_CODE_OK, 14);
}

START_TEST(test_negate_15) {
  s21_decimal decimal = {{0x3AC3ACF0, 0xBE2A10D, 0x0, 0x40000}};
  s21_decimal expected = {{0x3AC3ACF0, 0xBE2A10D, 0x0, 0x80040000}};

  s21_test_negate(decimal, expected, TEST_ERROR_CODE_OK, 15);
}

Suite *s21_negate_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_negate_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_negate_1);
  tcase_add_test(core, test_negate_2);
  tcase_add_test(core, test_negate_3);
  tcase_add_test(core, test_negate_4);
  tcase_add_test(core, test_negate_5);
  tcase_add_test(core, test_negate_6);
  tcase_add_test(core, test_negate_7);
  tcase_add_test(core, test_negate_8);
  tcase_add_test(core, test_negate_9);
  tcase_add_test(core, test_negate_10);
  tcase_add_test(core, test_negate_11);
  tcase_add_test(core, test_negate_12);
  tcase_add_test(core, test_negate_13);
  tcase_add_test(core, test_negate_14);
  tcase_add_test(core, test_negate_15);

  suite_add_tcase(suite, core);

  return (suite);
}
