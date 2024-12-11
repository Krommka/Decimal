#include "conversion.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int code = OK;

  if (!dst)
    code = ERROR;
  else {
    *dst = DECIMAL(0);

    if (src < 0) {
      s21_decimal_set_sign(dst, NEGATIVE);

      if (src != INT_MIN) src = -src;
    }

    dst->bits[0] = src;
  }

  return code;
}