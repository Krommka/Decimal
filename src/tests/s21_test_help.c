#include "s21_test_help.h"

#ifdef DEBUG

void s21_int256_to_string(s21_int256 data, char *result, int *index) {
  s21_int256 remainder = NEW;

  data = s21_binary_division(data, INT256(10), &remainder);

  if (s21_int256_is_not_zero(data)) s21_int256_to_string(data, result, index);

  result[(*index)++] = remainder.decimals[0].bits[0] + '0';
}

void s21_print_decimal(s21_decimal data) {
  s21_int256 int256 = (s21_int256){.decimals[0] = data};

  for (int i = FULL_DECIMAL - 1; i >= 0; i--) {
    printf("%d", s21_is_set_bit(int256, i));
    if (!(i % 32)) printf(" ");
    if (!(i % (32 * 2))) printf("\n");
  }

  printf("\n");
}

void s21_print_int256(s21_int256 int256) {
  char str_result[256];
  int size = 0;

  s21_int256_to_string(int256, str_result, &size);
  str_result[size] = '\0';
  printf("\n%-33s%s%d\n\n", str_result, "size: ", size);
}

#endif
