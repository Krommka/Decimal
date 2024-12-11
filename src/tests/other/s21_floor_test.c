#include "../s21_decimal_test.h"

START_TEST(test_floor_1) {
  // 481516.2342
  s21_decimal decimal = {{0x1F018BE6, 0x1, 0x0, 0x40000}};
  // 481516
  s21_decimal expected = {{0x758EC, 0x0, 0x0, 0x0}};

  s21_test_floor(decimal, expected, TEST_ERROR_CODE_OK, 1);
}

START_TEST(test_floor_2) {
  // 75691211548654.6545118461
  s21_decimal decimal = {{0xBBE88CFD, 0x49BA56C0, 0xA048, 0xA0000}};
  // 75691211548654
  s21_decimal expected = {{0x3BC6E7EE, 0x44D7, 0x0, 0x0}};

  s21_test_floor(decimal, expected, TEST_ERROR_CODE_OK, 2);
}

START_TEST(test_floor_3) {
  // 35309188505043.582404850638318
  s21_decimal decimal = {{0x1E585DEE, 0x4B1DBED3, 0x72171380, 0xF0000}};
  // 35309188505043
  s21_decimal expected = {{0xFA35DD3, 0x201D, 0x0, 0x0}};

  s21_test_floor(decimal, expected, TEST_ERROR_CODE_OK, 3);
}

START_TEST(test_floor_4) {
  // 1237.0000000777777
  s21_decimal decimal = {{0x0FEAFE31, 0x2BF273, 0x0, 0xD0000}};
  // 1237
  s21_decimal expected = {{0x4D5, 0x0, 0x0, 0x0}};

  s21_test_floor(decimal, expected, TEST_ERROR_CODE_OK, 4);
}

START_TEST(test_floor_5) {
  // 0.9454416741519591
  s21_decimal decimal = {{0xEF6FD0E7, 0x2196BD, 0x0, 0x100000}};
  // 0
  s21_decimal expected = {{0x0, 0x0, 0x0, 0x0}};

  s21_test_floor(decimal, expected, TEST_ERROR_CODE_OK, 5);
}

START_TEST(test_floor_6) {
  //-1.0000000000000000000007
  s21_decimal decimal = {{0xB2400007, 0x19E0C9BA, 0x21E, 0x80160000}};
  //-2
  s21_decimal expected = {{0x2, 0x0, 0x0, 0x80000000}};

  s21_test_floor(decimal, expected, TEST_ERROR_CODE_OK, 6);
}

START_TEST(test_floor_7) {
  //-7896452314745.56984
  s21_decimal decimal = {{0x809F4038, 0xAF56227, 0x0, 0x80050000}};
  //-7896452314746
  s21_decimal expected = {{0x893C367A, 0x72E, 0x0, 0x80000000}};

  s21_test_floor(decimal, expected, TEST_ERROR_CODE_OK, 7);
}

START_TEST(test_floor_8) {
  //-0.0000000795672222222
  s21_decimal decimal = {{0x41C29A0E, 0xB9, 0x0, 0x80130000}};
  //-1
  s21_decimal expected = {{0x1, 0x0, 0x0, 0x80000000}};

  s21_test_floor(decimal, expected, TEST_ERROR_CODE_OK, 8);
}

START_TEST(test_floor_9) {
  // -792281625142643375935440
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  //-792281625142643375935440
  s21_decimal expected = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x80000000}};

  s21_test_floor(decimal, expected, TEST_ERROR_CODE_OK, 9);
}

START_TEST(test_floor_10) {
  //-123412341234.12341234
  s21_decimal decimal = {{0x6FEC01F2, 0xAB44DF0C, 0x0, 0x80080000}};
  //-123412341235
  s21_decimal expected = {{0xBBF2E1F3, 0x1C, 0x0, 0x80000000}};

  s21_test_floor(decimal, expected, TEST_ERROR_CODE_OK, 10);
}

START_TEST(test_floor_11) {
  ////-5.000016
  s21_decimal decimal = {{0x4C4B50, 0x0, 0, 0x80060000}};
  //-6
  s21_decimal expected = {{0x6, 0x0, 0x0, 0x80000000}};

  s21_test_floor(decimal, expected, TEST_ERROR_CODE_OK, 11);
}

START_TEST(test_floor_12) {
  //-5896
  s21_decimal decimal = {{0x1708, 0x0, 0x0, 0x80000000}};
  //-5896
  s21_decimal expected = {{0x1708, 0x0, 0x0, 0x80000000}};

  s21_test_floor(decimal, expected, TEST_ERROR_CODE_OK, 12);
}

START_TEST(test_floor_13) {
  // NULL
  s21_decimal decimal = {0};
  s21_decimal *result = NULL;
  int expected_error_code = 1;
  int error_code = s21_floor(decimal, result);
  ck_assert_int_eq(error_code, expected_error_code);
}

START_TEST(test_floor_14) {
  // 0.11
  s21_decimal decimal = {{0xB, 0x0, 0x0, 0x20000}};
  // 0
  s21_decimal expected = {{0x0, 0x0, 0x0, 0x0}};

  s21_test_floor(decimal, expected, TEST_ERROR_CODE_OK, 14);
}

START_TEST(test_floor_15) {
  // 7.777777;
  s21_decimal decimal = {{0x76ADF1, 0x0, 0x0, 0x60000}};
  // 7
  s21_decimal expected = {{0x7, 0x0, 0x0, 0x0}};

  s21_test_floor(decimal, expected, TEST_ERROR_CODE_OK, 15);
}

Suite *s21_floor_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_floor_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_floor_1);
  tcase_add_test(core, test_floor_2);
  tcase_add_test(core, test_floor_3);
  tcase_add_test(core, test_floor_4);
  tcase_add_test(core, test_floor_5);
  tcase_add_test(core, test_floor_6);
  tcase_add_test(core, test_floor_7);
  tcase_add_test(core, test_floor_8);
  tcase_add_test(core, test_floor_9);
  tcase_add_test(core, test_floor_10);
  tcase_add_test(core, test_floor_11);
  tcase_add_test(core, test_floor_12);
  tcase_add_test(core, test_floor_13);
  tcase_add_test(core, test_floor_14);
  tcase_add_test(core, test_floor_15);

  suite_add_tcase(suite, core);

  return (suite);
}
