#ifndef ARITHMETIC_SERVICE_H
#define ARITHMETIC_SERVICE_H

#include "../../binary/binary.h"
#include "../../comparison/comparison.h"
#include "../../other/other.h"
#include "../../type.h"

#define OK 0
#define DECIMAL_BIG 1
#define DECIMAL_SMALL 2
#define DIV_BY_ZERO 3
#define INCORRECT_DATA 4

#define ERROR 1
#define NEGATIVE 1
#define POSITIVE 0

#define DECIMAL(value) ((s21_decimal){.bits[0] = (value)})

#define DECIMAL_TO_INT256(d) \
  ((s21_int256){.decimals[0].bits = {d.bits[0], d.bits[1], d.bits[2], 0}})

#define INT256_TO_DECIMAL(d) ((d).decimals[0])

#define DECIMAL_MAX                             \
  (s21_decimal) {                               \
    { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0 } \
  }

#define DECIMAL_INF                                    \
  (s21_decimal) {                                      \
    { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF } \
  }

#define BIT3(decimal) ((decimal_bit3)(decimal).bits[3])

#define FLOAT_PART(float) ((float_part)(float))

#define MANTISS(bit3) ((bit3).parse.mantiss)

#define EXP(bit3) ((bit3).parse.exp)

#define SIGN(bit3) ((bit3).parse.sign)

#define BLANKS(decimal) \
  (BIT3(decimal).parse.blank1 + BIT3(decimal).parse.blank2)

#define EXP_DEC(decimal) (EXP(BIT3((decimal))))

#define SIGN_DEC(decimal) (SIGN(BIT3(decimal)))

#define MAX(a, b) ((a) > (b) ? a : b)

s21_int256 s21_decimal_exp(s21_decimal decimal, int exp);

int s21_int256_to_decimal(s21_int256 data, s21_decimal *decimal,
                          decimal_bit3 bit3);
int s21_preprocessing(s21_decimal value_1, s21_decimal value_2,
                      s21_int256 *data_1, s21_int256 *data_2);

int s21_check_is_zero(s21_decimal decimal);
int s21_check_bit3_decimal(s21_decimal decimal);
int s21_check_input(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result);

void s21_decimal_set_sign(s21_decimal *decimal, int sign);
void s21_decimal_set_exp(s21_decimal *decimal, int exp);

int s21_int256_highest_digit(s21_int256 data);

typedef enum round_mode {
  TRUNCATE_ROUND,
  FLOOR_ROUND,
  BANK_ROUND,
  BASIC_ROUND,
  CEIL_ROUND
} round_mode;

s21_int256 s21_round_to_decimal(s21_int256 data, int rounder, round_mode mode);
int s21_round_decimal(s21_decimal value, s21_decimal *result, round_mode mode);
int s21_find_rounder(s21_int256 data);

#endif