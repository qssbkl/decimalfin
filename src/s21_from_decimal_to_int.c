#include <stdio.h>
#include <math.h>
#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    int decimal_dec[121] = {0}, temp_decimal_dec[121] = {0}, rezult = 1;
    int one_half_decimal_dec_plus[121] = {0}, one_half_decimal_dec_minus[121] = {0};
    convert_decimal_to_decimal_dec(decimal_dec, src);
    truncate_simple_decimal_dec(temp_decimal_dec, decimal_dec);
    s21_decimal one_half_plus = {{0x80000000, 0, 0, 0}, 0};
    s21_decimal one_half_minus = {{0x80000000, 0, 0, 0x80000000}, 0};
    convert_decimal_to_decimal_dec(one_half_decimal_dec_plus, one_half_plus);
    convert_decimal_to_decimal_dec(one_half_decimal_dec_minus, one_half_minus);
    if (less_simple_decimal_dec(temp_decimal_dec, one_half_decimal_dec_plus)) {
        if (greater_or_equal_simple_decimal_dec(temp_decimal_dec, one_half_decimal_dec_minus)) {
            int temp_dst = 0;
            int exp = 1;
            for (int i = 0; i < 10; i++) {
                temp_dst += temp_decimal_dec[60 - i] * exp;
                exp *= 10;
            }
            temp_dst *= temp_decimal_dec[0];
            *dst = temp_dst;
            rezult = 0;
        }
    }
    return rezult;
}
