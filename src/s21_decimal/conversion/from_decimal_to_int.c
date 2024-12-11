#include "conversion.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int code = OK;

  if (!(code = !dst) && !(code = !!s21_check_bit3_decimal(src))) {
    *dst = 0;
    s21_decimal truncated = NEW;
    s21_truncate(src, &truncated);

    if (s21_is_less(truncated, DEC_INT_MIN))
      code = ERROR;
    else if (s21_is_greater(truncated, DEC_INT_MAX))
      code = ERROR;
    else
      *dst = truncated.bits[0];

    if ((SIGN_DEC(src) == NEGATIVE) && (*dst != INT32_MIN)) *dst = *dst * -1;
  }

  return code;
}