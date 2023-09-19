#include <stdio.h>
#include <math.h>
#include "s21_decimal.h"


s21_decimal s21_div(s21_decimal first_number, s21_decimal second_number) {
    s21_decimal rezult_number = {{0, 0, 0, 0}, s21_NORMAL_VALUE};
    if (second_number.value_type == 0 && second_number.bits[0] == 0 &&
    second_number.bits[1] == 0 && second_number.bits[2] == 0) {
        if (first_number.value_type == 0 && first_number.bits[3] >= 0x80000000) {
            if (second_number.bits[3] < 0x80000000) {
                rezult_number.value_type = 2;
            } else {
                 rezult_number.value_type = 1;
            }
        } else if (first_number.value_type == 0 && first_number.bits[3] < 0x80000000) {
            if (second_number.bits[3] < 0x80000000) {
                rezult_number.value_type = 1;
            } else {
                 rezult_number.value_type = 2;
            }
        } else {
            rezult_number.value_type = 3;
        }
    } else if (first_number.value_type == 0 && second_number.value_type == 0) {
        int decimal_dec_1[121] = {0}, decimal_dec_2[121]= {0}, rezult_decimal_dec[121] = {0};
        convert_decimal_to_decimal_dec(decimal_dec_1, first_number);
        convert_decimal_to_decimal_dec(decimal_dec_2, second_number);
        div_simple_decimal_dec(rezult_decimal_dec, decimal_dec_1, decimal_dec_2);
        if (!equal_to_infinity(&rezult_number, rezult_decimal_dec)) {
            if (!near_to_zero(rezult_decimal_dec)) {
                convert_decimal_dec_to_decimal(&rezult_number, rezult_decimal_dec);
            } else {
                if_near_to_zero_2(&rezult_number, first_number, second_number);
            }
        } else if (first_number.bits[3] >= 0x80000000 && second_number.bits[3] >= 0x80000000) {
            rezult_number.value_type = 1;
        } else if (first_number.bits[3] < 0x80000000 && second_number.bits[3] < 0x80000000) {
            rezult_number.value_type = 1;
        } else {
            rezult_number.value_type = 2;
            rezult_number.bits[3] = 0x80000000;
        }
    } else {
        if_inf_or_nan_2(&rezult_number, first_number, second_number);
    }
    return rezult_number;
}
