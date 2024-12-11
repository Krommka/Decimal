#ifndef CONVERSION_H
#define CONVERSION_H

#include <limits.h>

#include "../arithmetic/service/arithmetic_service.h"
#include "../type.h"

#define BIAS 127
#define MAX_BIT_DECIMAL_MANTISS 23
#define DEC_INT_MIN                      \
  (s21_decimal) {                        \
    { 0x80000000, 0x0, 0x0, 0x80000000 } \
  }
#define DEC_INT_MAX               \
  (s21_decimal) {                 \
    { 0x7FFFFFFF, 0x0, 0x0, 0x0 } \
  }

int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);

void s21_float_to_int256(float src, s21_int256 *data, decimal_bit3 *bit3);
void s21_int256_round_seven_digit(s21_int256 *data);
void s21_int256_to_double(s21_int256 *data, double *src);

typedef union double_part {
  double df;
  struct {
    uint64_t mantiss : 52;
    uint64_t exponent : 11;
    uint64_t sign : 1;
  } parse;
} double_part;

typedef union uint64_t_part {
  uint64_t uint;
  struct {
    int bit0 : 32;
    int bit1 : 32;
  } parse;

} uint64_t_part;

#endif
