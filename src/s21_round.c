#include <stdio.h>
#include <math.h>
#include "s21_decimal.h"

s21_decimal s21_round(s21_decimal number) {
    s21_decimal rezult_number = {{0, 0, 0, 0}, s21_NORMAL_VALUE};
    if (number.value_type == 0) {
        int decimal_dec[121] = {0}, rezult_decimal_dec[121] = {0};
        convert_decimal_to_decimal_dec(decimal_dec, number);
        round_simple_decimal_dec_for_round(rezult_decimal_dec, decimal_dec);
        convert_decimal_dec_to_decimal(&rezult_number, rezult_decimal_dec);
    } else if (number.value_type == s21_NAN) {
        rezult_number.value_type = s21_NAN;
    } else if (number.value_type == s21_INFINITY) {
        rezult_number.value_type = s21_INFINITY;
    } else {
        rezult_number.value_type = s21_NEGATIVE_INFINITY;
        rezult_number.bits[3] = 0;
    }
    return rezult_number;
}
