#include "../s21_decimal_test.h"

START_TEST(test_equal_1) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  int expected = TRUE;

  s21_test_equal(decimal1, decimal2, expected, 1);
}

START_TEST(test_equal_2) {
  // 481516.2342
  s21_decimal decimal1 = {{0x1F018BE6, 0x1, 0x0, 0x40000}};
  // 481516.2342
  s21_decimal decimal2 = {{0x1F018BE6, 0x1, 0x0, 0x40000}};
  int expected = TRUE;

  s21_test_equal(decimal1, decimal2, expected, 2);
}

START_TEST(test_equal_3) {
  //-0.17456847232188684569862656
  s21_decimal decimal1 = {{0xF282E200, 0x95AE8703, 0xE70A1, 0x801B0000}};
  //-0.17456847232188684569862656
  s21_decimal decimal2 = {{0xF282E200, 0x95AE8703, 0xE70A1, 0x801B0000}};
  int expected = TRUE;

  s21_test_equal(decimal1, decimal2, expected, 3);
}

START_TEST(test_equal_4) {
  //-1.0000000000000000000008
  s21_decimal decimal1 = {{0xB2400008, 0x19E0C9BA, 0x21E, 0x80160000}};
  //-1.0000000000000000000008
  s21_decimal decimal2 = {{0xB2400008, 0x19E0C9BA, 0x21E, 0x80160000}};
  int expected = TRUE;

  s21_test_equal(decimal1, decimal2, expected, 4);
}

START_TEST(test_equal_5) {
  ////5.000016
  s21_decimal decimal1 = {{0x4C4B50, 0x0, 0, 0x60000}};
  ////5.000016
  s21_decimal decimal2 = {{0x4C4B50, 0x0, 0, 0x60000}};
  int expected = TRUE;

  s21_test_equal(decimal1, decimal2, expected, 5);
}

START_TEST(test_equal_6) {
  //-123412341234.12341234
  s21_decimal decimal1 = {{0x6FEC01F2, 0xAB44DF0C, 0x0, 0x80080000}};
  //-123412341234.12341234
  s21_decimal decimal2 = {{0x6FEC01F2, 0xAB44DF0C, 0x0, 0x80080000}};
  int expected = TRUE;

  s21_test_equal(decimal1, decimal2, expected, 6);
}

START_TEST(test_equal_7) {
  // max
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // max
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int expected = TRUE;

  s21_test_equal(decimal1, decimal2, expected, 7);
}

START_TEST(test_equal_8) {
  //-0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  int expected = TRUE;

  s21_test_equal(decimal1, decimal2, expected, 8);
}

START_TEST(test_equal_9) {
  // 1717178965432198
  s21_decimal decimal1 = {{0xE2401786, 0x619C3, 0x0, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  int expected = FALSE;

  s21_test_equal(decimal1, decimal2, expected, 9);
}

START_TEST(test_equal_10) {
  // 10
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x0}};
  // 10.1
  s21_decimal decimal2 = {{0x65, 0x0, 0x0, 0x10000}};
  int expected = FALSE;

  s21_test_equal(decimal1, decimal2, expected, 10);
}

START_TEST(test_equal_11) {
  //-7896452314745.56984
  s21_decimal decimal1 = {{0x809F4038, 0xAF56227, 0x0, 0x80050000}};
  //-789645231474.556984
  s21_decimal decimal2 = {{0x809F4038, 0xAF56227, 0x0, 0x80060000}};
  int expected = FALSE;

  s21_test_equal(decimal1, decimal2, expected, 11);
}

START_TEST(test_equal_12) {
  // 0.11
  s21_decimal decimal1 = {{0xB, 0x0, 0x0, 0x20000}};
  // 0.1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x10000}};
  int expected = FALSE;

  s21_test_equal(decimal1, decimal2, expected, 12);
}

START_TEST(test_equal_13) {
  //-1.0000000000000000000007
  s21_decimal decimal1 = {{0xB2400007, 0x19E0C9BA, 0x21E, 0x80160000}};
  //-1.0000000000000000000008
  s21_decimal decimal2 = {{0xB2400008, 0x19E0C9BA, 0x21E, 0x80160000}};
  int expected = FALSE;

  s21_test_equal(decimal1, decimal2, expected, 13);
}

START_TEST(test_equal_14) {
  // 7.777777
  s21_decimal decimal1 = {{0x76ADF1, 0x0, 0x0, 0x60000}};
  // 25565584854.265656565
  s21_decimal decimal2 = {{0x019C74F5, 0x62CB33F9, 0x1, 0x0}};
  int expected = FALSE;

  s21_test_equal(decimal1, decimal2, expected, 14);
}

START_TEST(test_equal_15) {
  //-80000513
  s21_decimal decimal1 = {{0x4C4B601, 0x0, 0x0, 0x80000000}};
  //-17
  s21_decimal decimal2 = {{0x11, 0x0, 0x0, 0x80000000}};
  int expected = FALSE;

  s21_test_equal(decimal1, decimal2, expected, 15);
}

Suite *s21_equal_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_equal_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_equal_1);
  tcase_add_test(core, test_equal_2);
  tcase_add_test(core, test_equal_3);
  tcase_add_test(core, test_equal_4);
  tcase_add_test(core, test_equal_5);
  tcase_add_test(core, test_equal_6);
  tcase_add_test(core, test_equal_7);
  tcase_add_test(core, test_equal_8);
  tcase_add_test(core, test_equal_9);
  tcase_add_test(core, test_equal_10);
  tcase_add_test(core, test_equal_11);
  tcase_add_test(core, test_equal_12);
  tcase_add_test(core, test_equal_13);
  tcase_add_test(core, test_equal_14);
  tcase_add_test(core, test_equal_15);

  suite_add_tcase(suite, core);

  return (suite);
}
