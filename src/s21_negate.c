#include <stdio.h>
#include <math.h>
#include "s21_decimal.h"

s21_decimal s21_negate(s21_decimal number) {
    if (number.value_type == s21_NEGATIVE_INFINITY) {
        number.value_type = s21_INFINITY;
    } else if (number.value_type == s21_INFINITY) {
        number.value_type = s21_NEGATIVE_INFINITY;
    } else if (number.value_type == 0) {
        number.bits[3] ^= (1u << 31);
    }
    return number;
}
