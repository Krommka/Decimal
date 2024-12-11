#include "../s21_decimal_test.h"

START_TEST(test_div_1) {
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x40000}};
  s21_decimal expected = {{0x0, 0x0, 0x1, 0x80180000}};

  s21_test_div(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 1);
}

START_TEST(test_div_2) {
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x80030000}};
  s21_decimal expected = {{0x7D, 0x7D, 0x0, 0x80030000}};

  s21_test_div(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 2);
}

START_TEST(test_div_3) {
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  s21_decimal expected = {{0x129776EC, 0x9FC9D0A2, 0x8AA3A528, 0x130000}};

  s21_test_div(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 3);
}

START_TEST(test_div_4) {
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  s21_decimal expected = {{0x1, 0x1, 0x0, 0x10000}};

  s21_test_div(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 4);
}

START_TEST(test_div_5) {
  s21_decimal decimal1 = {{0x1F4, 0, 0, 0}};
  s21_decimal decimal2 = {{0xA, 0, 0, 0}};
  s21_decimal expected = {{0x32, 0, 0, 0}};

  s21_test_div(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 5);
}

START_TEST(test_div_6) {
  s21_decimal decimal1 = {{0x6A528800, 0x74, 0, 0}};
  s21_decimal decimal2 = {{0xA, 0, 0, 0}};
  s21_decimal expected = {{0xA43B7400, 0xB, 0, 0}};

  s21_test_div(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 6);
}

START_TEST(test_div_7) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  s21_decimal expected = NEW;

  s21_test_div(decimal1, decimal2, expected, TEST_ERROR_CODE_BIG, 7);
}

START_TEST(test_div_8) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  s21_decimal expected = NEW;

  s21_test_div(decimal1, decimal2, expected, TEST_ERROR_CODE_SMALL, 8);
}

START_TEST(test_div_9) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = NEW;
  s21_decimal expected = NEW;

  s21_test_div(decimal1, decimal2, expected, TEST_ERROR_CODE_DIV_ZERO, 9);
}

START_TEST(test_div_10) {
  s21_decimal decimal1 = NEW;
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0}};
  s21_decimal expected = NEW;

  s21_test_div(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 10);
}

START_TEST(test_div_11) {
  s21_decimal decimal1 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x130000}};
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  s21_decimal expected = {{0x3C2CB79D, 0x3E0B91AF, 0x7623FB44, 0x130000}};

  s21_test_div(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 11);
}

START_TEST(test_div_12) {
  s21_decimal decimal1 = NEW;
  s21_decimal decimal2 = NEW;
  s21_decimal expected = NEW;

  s21_test_div(decimal1, decimal2, expected, TEST_ERROR_CODE_DIV_ZERO, 12);
}

START_TEST(test_div_13) {
  s21_decimal decimal1 = {{0x1F40, 0x0, 0x0, 0x30000}};
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x80000000}};
  s21_decimal expected = {{0xFA0, 0x0, 0x0, 0x80030000}};

  s21_test_div(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 13);
}

START_TEST(test_div_14) {
  s21_decimal decimal1 = {{0x3E9, 0x0, 0x0, 0x80030000}};
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x801B0000}};
  s21_decimal expected = {{0x16D55555, 0x1F453787, 0x8A0055, 0x1C0000}};

  s21_test_div(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 14);
}

START_TEST(test_div_15) {
  s21_decimal decimal1 = {{0x3E9, 0x0, 0x0, 0x80030000}};
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x801B0000}};
  s21_decimal expected = {{0x16D55555, 0x1F453787, 0x8A0055, 0x1C0000}};

  s21_test_div(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 15);
}

START_TEST(test_div_16) {
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80000000}};
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  s21_decimal expected = {{0x74000019, 0x4FE8401E, 0x19D971E, 0x801A0000}};

  s21_test_div(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 16);
}

START_TEST(test_div_17) {
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  s21_decimal expected = {{0x0, 0x0, 0x0, 0x801B0000}};

  s21_test_div(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 17);
}

START_TEST(test_div_18) {
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x80000}};
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  s21_decimal expected = {{0x0, 0x2, 0x0, 0x80000}};

  s21_test_div(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 18);
}

START_TEST(test_div_19) {
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  s21_decimal expected = {{0x0, 0x0, 0x0, 0x801B0000}};

  s21_test_div(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 19);
}

START_TEST(test_div_20) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal expected = {{0x1, 0x0, 0x0, 0x0}};

  s21_test_div(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 20);
}

Suite *s21_div_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_div_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_div_1);
  tcase_add_test(core, test_div_2);
  tcase_add_test(core, test_div_3);
  tcase_add_test(core, test_div_4);
  tcase_add_test(core, test_div_5);
  tcase_add_test(core, test_div_6);
  tcase_add_test(core, test_div_7);
  tcase_add_test(core, test_div_8);
  tcase_add_test(core, test_div_9);
  tcase_add_test(core, test_div_10);
  tcase_add_test(core, test_div_11);
  tcase_add_test(core, test_div_12);
  tcase_add_test(core, test_div_13);
  tcase_add_test(core, test_div_14);
  tcase_add_test(core, test_div_15);
  tcase_add_test(core, test_div_16);
  tcase_add_test(core, test_div_17);
  tcase_add_test(core, test_div_18);
  tcase_add_test(core, test_div_19);
  tcase_add_test(core, test_div_20);

  suite_add_tcase(suite, core);

  return (suite);
}
