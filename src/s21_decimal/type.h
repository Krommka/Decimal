#ifndef TYPE_H
#define TYPE_H

#include <stdint.h>
#include <stdlib.h>

#define NEW \
  { 0 }

#define BLOCK 32
#define FULL_DECIMAL 128
#define FULL_INT256 256
#define EXP_LIMIT 28

typedef struct s21_decimal {
  int bits[4];
} s21_decimal;

typedef struct s21_int256 {
  s21_decimal decimals[2];
} s21_int256;

typedef union decimal_bit3 {
  int i;
  struct {
    uint32_t blank2 : 16;
    uint32_t exp : 8;
    uint32_t blank1 : 7;
    uint32_t sign : 1;
  } parse;
} decimal_bit3;

typedef union float_part {
  float f;
  struct {
    uint32_t mantiss : 23;
    uint32_t exp : 8;
    uint32_t sign : 1;
  } parse;
} float_part;

#endif
