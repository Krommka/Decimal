#include "../s21_decimal_test.h"

START_TEST(test_int_to_decimal_1) {
  int num = 0;
  s21_decimal expected = {{0x0, 0x0, 0x0, 0x0}};

  s21_test_int_to_decimal(num, expected, TEST_ERROR_CODE_OK, 1);
}

START_TEST(test_int_to_decimal_2) {
  int num = 1000000;
  s21_decimal expected = {{0xF4240, 0x0, 0x0, 0x0}};

  s21_test_int_to_decimal(num, expected, TEST_ERROR_CODE_OK, 2);
}

START_TEST(test_int_to_decimal_3) {
  int num = 2147483647;
  s21_decimal expected = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};

  s21_test_int_to_decimal(num, expected, TEST_ERROR_CODE_OK, 3);
}

START_TEST(test_int_to_decimal_4) {
  int num = -2147483648;
  s21_decimal expected = {{0x80000000, 0x0, 0x0, 0x80000000}};

  s21_test_int_to_decimal(num, expected, TEST_ERROR_CODE_OK, 4);
}

START_TEST(test_int_to_decimal_5) {
  int num = -17;
  s21_decimal expected = {{0x11, 0x0, 0x0, 0x80000000}};

  s21_test_int_to_decimal(num, expected, TEST_ERROR_CODE_OK, 5);
}

START_TEST(test_int_to_decimal_6) {
  int num = -80000513;
  s21_decimal expected = {{0x4C4B601, 0x0, 0x0, 0x80000000}};

  s21_test_int_to_decimal(num, expected, TEST_ERROR_CODE_OK, 6);
}

START_TEST(test_int_to_decimal_7) {
  int num = -0;
  s21_decimal expected = {{0x0, 0x0, 0x0, 0x0}};

  s21_test_int_to_decimal(num, expected, TEST_ERROR_CODE_OK, 7);
}

START_TEST(test_int_to_decimal_8) {
  int num = 1234567;
  s21_decimal expected = {{0x12D687, 0x0, 0x0, 0x0}};

  s21_test_int_to_decimal(num, expected, TEST_ERROR_CODE_OK, 8);
}

START_TEST(test_int_to_decimal_9) {
  int num = 5;
  s21_decimal expected = {{0x5, 0x0, 0x0, 0x0}};

  s21_test_int_to_decimal(num, expected, TEST_ERROR_CODE_OK, 9);
}

START_TEST(test_int_to_decimal_10) {
  int num = 894563127;
  s21_decimal expected = {{0x3551F337, 0x0, 0x0, 0x0}};

  s21_test_int_to_decimal(num, expected, TEST_ERROR_CODE_OK, 10);
}

START_TEST(test_int_to_decimal_11) {
  int num = 1132;
  s21_decimal expected = {{0x46C, 0x0, 0x0, 0x0}};

  s21_test_int_to_decimal(num, expected, TEST_ERROR_CODE_OK, 11);
}

START_TEST(test_int_to_decimal_12) {
  int num = 9999999;
  s21_decimal expected = {{0x98967F, 0x0, 0x0, 0x0}};

  s21_test_int_to_decimal(num, expected, TEST_ERROR_CODE_OK, 12);
}

START_TEST(test_int_to_decimal_13) {
  int num = -9999999;
  s21_decimal expected = {{0x98967F, 0x0, 0x0, 0x80000000}};

  s21_test_int_to_decimal(num, expected, TEST_ERROR_CODE_OK, 13);
}

START_TEST(test_int_to_decimal_14) {
  int num = -36478899;
  s21_decimal expected = {{0x22C9FB3, 0x0, 0x0, 0x80000000}};

  s21_test_int_to_decimal(num, expected, TEST_ERROR_CODE_OK, 14);
}

START_TEST(test_int_to_decimal_15) {
  int num = -8465215;
  s21_decimal expected = {{0x812B3F, 0x0, 0x0, 0x80000000}};

  s21_test_int_to_decimal(num, expected, TEST_ERROR_CODE_OK, 15);
}

START_TEST(test_int_to_decimal_16) {
  float a = 0;
  int expected_error_code = 1;
  int error_code = s21_from_int_to_decimal(a, NULL);
  ck_assert_int_eq(error_code, expected_error_code);
}

Suite *s21_int_to_decimal_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_int_to_decimal_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_int_to_decimal_1);
  tcase_add_test(core, test_int_to_decimal_2);
  tcase_add_test(core, test_int_to_decimal_3);
  tcase_add_test(core, test_int_to_decimal_4);
  tcase_add_test(core, test_int_to_decimal_5);
  tcase_add_test(core, test_int_to_decimal_6);
  tcase_add_test(core, test_int_to_decimal_7);
  tcase_add_test(core, test_int_to_decimal_8);
  tcase_add_test(core, test_int_to_decimal_9);
  tcase_add_test(core, test_int_to_decimal_10);
  tcase_add_test(core, test_int_to_decimal_11);
  tcase_add_test(core, test_int_to_decimal_12);
  tcase_add_test(core, test_int_to_decimal_13);
  tcase_add_test(core, test_int_to_decimal_14);
  tcase_add_test(core, test_int_to_decimal_15);
  tcase_add_test(core, test_int_to_decimal_16);

  suite_add_tcase(suite, core);

  return (suite);
}