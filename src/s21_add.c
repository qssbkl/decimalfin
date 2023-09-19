#include <stdio.h>
#include <math.h>
#include "s21_decimal.h"

s21_decimal s21_add(s21_decimal first_number, s21_decimal second_number) {
    s21_decimal rezult_number = {{0, 0, 0, 0}, s21_NORMAL_VALUE};
    if (first_number.value_type == 0 && second_number.value_type == 0) {
        int decimal_dec_1[121] = {0}, decimal_dec_2[121]= {0}, rezult_decimal_dec[121] = {0};
        convert_decimal_to_decimal_dec(decimal_dec_1, first_number);
        convert_decimal_to_decimal_dec(decimal_dec_2, second_number);
        add_simple_decimal_dec(rezult_decimal_dec, decimal_dec_1, decimal_dec_2);
        if (!equal_to_infinity(&rezult_number, rezult_decimal_dec)) {
            if (!near_to_zero(rezult_decimal_dec)) {
                convert_decimal_dec_to_decimal(&rezult_number, rezult_decimal_dec);
            } else if ((first_number.bits[0] == 0 && first_number.bits[1] == 0 &&
            first_number.bits[2] == 0) &&
            (second_number.bits[0] == 0 && second_number.bits[1] == 0 && second_number.bits[2] == 0)) {
                if (first_number.bits[3] < 0x80000000 && second_number.bits[3] < 0x80000000) {
                    rezult_number.bits[3] = 0;
                } else if (first_number.bits[3] < 0x80000000 && second_number.bits[3] >= 0x80000000) {
                    rezult_number.bits[3] = 0x80000000;
                } else if (first_number.bits[3] >= 0x80000000 && second_number.bits[3] < 0x80000000) {
                    rezult_number.bits[3] = 0;
                }
            }
        }
    } else if (first_number.value_type == s21_NAN || second_number.value_type == s21_NAN) {
        rezult_number.value_type = s21_NAN;
    } else if (first_number.value_type == 1 && second_number.value_type == 1) {
        rezult_number.value_type = 1;
    } else if (first_number.value_type == 1 && second_number.value_type == 0) {
        rezult_number.value_type = 1;
    } else if (first_number.value_type == 0 && second_number.value_type == 1) {
        rezult_number.value_type = 1;
    } else if (first_number.value_type == 2 && second_number.value_type == 2) {
        rezult_number.value_type = 2;
    } else if (first_number.value_type == 0 && second_number.value_type == 2) {
        rezult_number.value_type = 2;
    } else if (first_number.value_type == 2 && second_number.value_type == 0) {
        rezult_number.value_type = 2;
    } else if (first_number.value_type == 1 && second_number.value_type == 2) {
        rezult_number.value_type = 3;
    } else {
        rezult_number.value_type = 3;
    }
    return rezult_number;
}
