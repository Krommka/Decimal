#include "../s21_decimal_test.h"

START_TEST(test_truncate_1) {
  // 481516.2342
  s21_decimal decimal = {{0x1F018BE6, 0x1, 0x0, 0x40000}};
  s21_decimal expected = {{0x758EC, 0x0, 0x0, 0x0}};

  s21_test_truncate(decimal, expected, TEST_ERROR_CODE_OK, 1);
}

START_TEST(test_truncate_2) {
  //-0.14569721534856
  s21_decimal decimal = {{0x47139988, 0xD40, 0x0, 0x800E0000}};
  s21_decimal expected = {{0x0, 0x0, 0x0, 0x0}};

  s21_test_truncate(decimal, expected, TEST_ERROR_CODE_OK, 2);
}

START_TEST(test_truncate_3) {
  s21_decimal decimal = {{0x12D4CB, 0x0, 0x0, 0x0}};
  s21_decimal expected = {{0x12D4CB, 0x0, 0x0, 0x0}};

  s21_test_truncate(decimal, expected, TEST_ERROR_CODE_OK, 3);
}

START_TEST(test_truncate_4) {
  //-7896452314745.56984
  s21_decimal decimal = {{0x809F4038, 0xAF56227, 0x0, 0x80050000}};
  s21_decimal expected = {{0x893C3679, 0x72E, 0x0, 0x80000000}};

  s21_test_truncate(decimal, expected, TEST_ERROR_CODE_OK, 4);
}

START_TEST(test_truncate_5) {
  // 85642395734636.4656
  s21_decimal decimal = {{0x3AC3ACF0, 0xBE2A10D, 0x0, 0x40000}};
  s21_decimal expected = {{0x2C93526C, 0x4DE4, 0x0, 0x0}};

  s21_test_truncate(decimal, expected, TEST_ERROR_CODE_OK, 5);
}

START_TEST(test_truncate_6) {
  //-0.0000000795672222222
  s21_decimal decimal = {{0x41C29A0E, 0xB9, 0x0, 0x80130000}};
  s21_decimal expected = {{0x0, 0x0, 0x0, 0x0}};

  s21_test_truncate(decimal, expected, TEST_ERROR_CODE_OK, 6);
}

START_TEST(test_truncate_7) {
  //-123412341234.12341234
  s21_decimal decimal = {{0x6FEC01F2, 0xAB44DF0C, 0x0, 0x80080000}};
  s21_decimal expected = {{0xBBF2E1F2, 0x1C, 0x0, 0x80000000}};

  s21_test_truncate(decimal, expected, TEST_ERROR_CODE_OK, 7);
}

START_TEST(test_truncate_8) {
  // 792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  s21_decimal expected = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x0}};

  s21_test_truncate(decimal, expected, TEST_ERROR_CODE_OK, 8);
}

START_TEST(test_truncate_9) {
  //-1.0000000000000000000008
  s21_decimal decimal = {{0xB2400008, 0x19E0C9BA, 0x21E, 0x80160000}};
  s21_decimal expected = {{0x1, 0x0, 0x0, 0x80000000}};

  s21_test_truncate(decimal, expected, TEST_ERROR_CODE_OK, 9);
}

START_TEST(test_truncate_10) {
  // NULL
  s21_decimal decimal = {0};
  s21_decimal *result = NULL;
  int expected_error_code = 1;
  int error_code = s21_truncate(decimal, result);
  ck_assert_int_eq(error_code, expected_error_code);
}

START_TEST(test_truncate_11) {
  // min
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal expected = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  s21_test_truncate(decimal, expected, TEST_ERROR_CODE_OK, 11);
}

START_TEST(test_truncate_12) {
  // 7.77777
  s21_decimal decimal = {{0x76ADF1, 0x0, 0x0, 0x60000}};
  s21_decimal expected = {{0x7, 0x0, 0x0, 0x0}};

  s21_test_truncate(decimal, expected, TEST_ERROR_CODE_OK, 12);
}

START_TEST(test_truncate_13) {
  // 1237.0000000777777
  s21_decimal decimal = {{0x0FEAFE31, 0x2BF273, 0x0, 0xD0000}};
  s21_decimal expected = {{0x4D5, 0x0, 0x0, 0x0}};

  s21_test_truncate(decimal, expected, TEST_ERROR_CODE_OK, 13);
}

START_TEST(test_truncate_14) {
  // 35309188505043.582404850638318
  s21_decimal decimal = {{0x1E585DEE, 0x4B1DBED3, 0x72171380, 0xF0000}};
  s21_decimal expected = {{0xFA35DD3, 0x201D, 0x0, 0x0}};

  s21_test_truncate(decimal, expected, TEST_ERROR_CODE_OK, 14);
}

START_TEST(test_truncate_15) {
  // 10.1
  s21_decimal decimal = {{0x65, 0x0, 0x0, 0x10000}};
  s21_decimal expected = {{0xA, 0x0, 0x0, 0x0}};

  s21_test_truncate(decimal, expected, TEST_ERROR_CODE_OK, 14);
}

Suite *s21_truncate_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_truncate_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_truncate_1);
  tcase_add_test(core, test_truncate_2);
  tcase_add_test(core, test_truncate_3);
  tcase_add_test(core, test_truncate_4);
  tcase_add_test(core, test_truncate_5);
  tcase_add_test(core, test_truncate_6);
  tcase_add_test(core, test_truncate_7);
  tcase_add_test(core, test_truncate_8);
  tcase_add_test(core, test_truncate_9);
  tcase_add_test(core, test_truncate_10);
  tcase_add_test(core, test_truncate_11);
  tcase_add_test(core, test_truncate_12);
  tcase_add_test(core, test_truncate_13);
  tcase_add_test(core, test_truncate_14);
  tcase_add_test(core, test_truncate_15);

  suite_add_tcase(suite, core);

  return (suite);
}