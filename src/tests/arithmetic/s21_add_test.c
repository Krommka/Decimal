#include "../s21_decimal_test.h"

START_TEST(test_add_1) {
  s21_decimal decimal1 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  s21_decimal expected = {{0x4D0E2E5F, 0xF8D511A6, 0xA09A2FB3, 0x120000}};

  s21_test_add(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 1);
}

START_TEST(test_add_2) {
  s21_decimal decimal1 = {{0, 0, 0x1BC16D67, 0}};
  s21_decimal decimal2 = {{0, 0, 0x1BC16D67, 0}};
  s21_decimal expected = {{0, 0, 0x3782DACE, 0}};

  s21_test_add(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 2);
}

START_TEST(test_add_3) {
  s21_decimal decimal1 = NEW;
  s21_decimal decimal2 = NEW;
  s21_decimal expected = NEW;

  s21_test_add(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 3);
}

START_TEST(test_add_4) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = NEW;

  s21_test_add(decimal1, decimal2, expected, TEST_ERROR_CODE_BIG, 4);
}

START_TEST(test_add_5) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal expected = NEW;

  s21_test_add(decimal1, decimal2, expected, TEST_ERROR_CODE_SMALL, 5);
}

START_TEST(test_add_6) {
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  s21_decimal expected = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  s21_test_add(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 6);
}

START_TEST(test_add_7) {
  s21_decimal decimal1 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  s21_test_add(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 7);
}

START_TEST(test_add_8) {
  s21_decimal decimal1 = {{0x8, 0x0, 0x0, 0x0}};
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = {{0x192F9A3, 0x0, 0x0, 0x80000000}};

  s21_test_add(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 8);
}

START_TEST(test_add_9) {
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  s21_decimal expected = {{0x88000000, 0x1F128130, 0x1027E72F, 0x1C0000}};

  s21_test_add(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 9);
}

START_TEST(test_add_10) {
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  s21_decimal expected = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  s21_test_add(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 10);
}

START_TEST(test_add_11) {
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x1C0000}};
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  s21_decimal expected = {{0x8800000B, 0x1F128130, 0x1027E72F, 0x1C0000}};

  s21_test_add(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 11);
}

START_TEST(test_add_12) {
  s21_decimal decimal1 = {{0xA05F2000, 0x12, 0x0, 0x0}};
  s21_decimal decimal2 = {{0x37, 0x0, 0x0, 0x0}};
  s21_decimal expected = {{0xA05F2037, 0x12, 0x0, 0x0}};

  s21_test_add(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 12);
}

START_TEST(test_add_13) {
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x1C0000}};
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  s21_decimal expected = {{0xA, 0x0, 0x0, 0x1C0000}};

  s21_test_add(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 13);
}

START_TEST(test_add_14) {
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x801C0000}};
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  s21_decimal expected = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};

  s21_test_add(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 14);
}

START_TEST(test_add_15) {
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  s21_decimal expected = {{0x33F55555, 0x35C9ADC6, 0x5555558B, 0x80150000}};

  s21_test_add(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 15);
}

START_TEST(test_add_16) {
  s21_decimal decimal1 = {{0x8, 0x0, 0x0, 0x0}};
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = {{0x7, 0x0, 0x0, 0x0}};

  s21_test_add(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 16);
}

START_TEST(test_add_17) {
  s21_decimal decimal1 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  s21_decimal expected = {{0x4D0E2E5F, 0xF8D511A6, 0xA09A2FB3, 0x120000}};

  s21_test_add(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 17);
}

START_TEST(test_add_18) {
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x80120000}};
  s21_decimal expected = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x80120000}};

  s21_test_add(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 18);
}

START_TEST(test_add_19) {
  s21_decimal decimal1 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x60000}};
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  s21_decimal expected = {{0x4BB0FD76, 0x9636572A, 0xFFFF8926, 0x80010000}};

  s21_test_add(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 19);
}

START_TEST(test_add_20) {
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  s21_decimal decimal2 = NEW;
  s21_decimal expected = NEW;

  s21_test_add(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 20);
}

Suite *s21_add_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_add_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_add_1);
  tcase_add_test(core, test_add_2);
  tcase_add_test(core, test_add_3);
  tcase_add_test(core, test_add_4);
  tcase_add_test(core, test_add_5);
  tcase_add_test(core, test_add_6);
  tcase_add_test(core, test_add_7);
  tcase_add_test(core, test_add_8);
  tcase_add_test(core, test_add_9);
  tcase_add_test(core, test_add_10);
  tcase_add_test(core, test_add_11);
  tcase_add_test(core, test_add_12);
  tcase_add_test(core, test_add_13);
  tcase_add_test(core, test_add_14);
  tcase_add_test(core, test_add_15);
  tcase_add_test(core, test_add_16);
  tcase_add_test(core, test_add_17);
  tcase_add_test(core, test_add_18);
  tcase_add_test(core, test_add_19);
  tcase_add_test(core, test_add_20);

  suite_add_tcase(suite, core);

  return (suite);
}
