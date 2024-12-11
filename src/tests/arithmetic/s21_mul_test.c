#include "../s21_decimal_test.h"

START_TEST(test_mul_1) {
  s21_decimal decimal1 = NEW;
  s21_decimal decimal2 = NEW;
  s21_decimal expected = NEW;

  s21_test_mul(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 1);
}

START_TEST(test_mul_2) {
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  s21_decimal expected = {{0xAAAAAAA8, 0xAAAAAAAA, 0x2AAAAAAA, 0x150000}};

  s21_test_mul(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 2);
}

START_TEST(test_mul_3) {
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  s21_decimal expected = {{0x55555558, 0x55555555, 0x55555555, 0x80150000}};

  s21_test_mul(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 3);
}

START_TEST(test_mul_4) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = NEW;

  s21_test_mul(decimal1, decimal2, expected, TEST_ERROR_CODE_BIG, 4);
}

START_TEST(test_mul_5) {
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  s21_decimal expected = NEW;

  s21_test_mul(decimal1, decimal2, expected, TEST_ERROR_CODE_SMALL, 5);
}

START_TEST(test_mul_6) {
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x1C0000}};
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  s21_decimal expected = {{0x1, 0x0, 0x0, 0x1C0000}};

  s21_test_mul(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 6);
}

START_TEST(test_mul_7) {
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x801C0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  s21_decimal expected = {{0x96EE45A, 0x359A3B3E, 0xCAD2F7F5, 0xE0000}};

  s21_test_mul(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 7);
}

START_TEST(test_mul_8) {
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0}};
  s21_decimal decimal2 = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  s21_test_mul(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 8);
}

START_TEST(test_mul_9) {
  s21_decimal decimal1 = {{0, 0, 0, 0}};
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  s21_test_mul(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 9);
}

START_TEST(test_mul_10) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  s21_decimal expected = {{0x9999999A, 0x99999999, 0x19999999, 0xD0000}};

  s21_test_mul(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 10);
}

START_TEST(test_mul_11) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  s21_decimal expected = {{0x70D42573, 0x2D093, 0x0, 0x1C0000}};

  s21_test_mul(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 11);
}

START_TEST(test_mul_12) {
  s21_decimal decimal1 = {{0, 0, 0, 0x80000000}};
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  s21_decimal expected = {{0, 0, 0, 0}};

  s21_test_mul(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 12);
}

START_TEST(test_mul_13) {
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80150000}};
  s21_decimal expected = {{0, 0, 0, 0}};

  s21_test_mul(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 13);
}

START_TEST(test_mul_14) {
  s21_decimal decimal1 = {{0, 0, 0, 0}};
  s21_decimal decimal2 = {{0x5, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  s21_test_mul(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 14);
}

START_TEST(test_mul_15) {
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  s21_decimal expected = {{0x588A3D1C, 0x5F33F93, 0x8C2FC260, 0x60000}};

  s21_test_mul(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 15);
}

START_TEST(test_mul_16) {
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  s21_decimal decimal2 = {{0xD42B4895, 0x339BF28D, 0xB9B77ADA, 0x90000}};
  s21_decimal expected = {{0xCE81D02E, 0xDA391347, 0x8309D38C, 0x50000}};

  s21_test_mul(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 16);
}

START_TEST(test_mul_17) {
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  s21_decimal expected = {{0xF079B07C, 0x741E2292, 0x3C35ACDC, 0x80110000}};

  s21_test_mul(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 17);
}

START_TEST(test_mul_18) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0}};
  s21_decimal expected = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

  s21_test_mul(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 18);
}

START_TEST(test_mul_19) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  s21_test_mul(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 19);
}

START_TEST(test_mul_20) {
  s21_decimal decimal1 = {{0x19, 0x0, 0x0, 0x80100000}};
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  s21_decimal expected = {{0xC41E9000, 0x16BC, 0x0, 0x1C0000}};

  s21_test_mul(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 20);
}

Suite *s21_mul_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_mul_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_mul_1);
  tcase_add_test(core, test_mul_2);
  tcase_add_test(core, test_mul_3);
  tcase_add_test(core, test_mul_4);
  tcase_add_test(core, test_mul_5);
  tcase_add_test(core, test_mul_6);
  tcase_add_test(core, test_mul_7);
  tcase_add_test(core, test_mul_8);
  tcase_add_test(core, test_mul_9);
  tcase_add_test(core, test_mul_10);
  tcase_add_test(core, test_mul_11);
  tcase_add_test(core, test_mul_12);
  tcase_add_test(core, test_mul_13);
  tcase_add_test(core, test_mul_14);
  tcase_add_test(core, test_mul_15);
  tcase_add_test(core, test_mul_16);
  tcase_add_test(core, test_mul_17);
  tcase_add_test(core, test_mul_18);
  tcase_add_test(core, test_mul_19);
  tcase_add_test(core, test_mul_20);

  suite_add_tcase(suite, core);

  return (suite);
}
