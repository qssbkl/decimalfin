#include <stdio.h>
#include <math.h>
#include "s21_decimal.h"

int s21_is_equal(s21_decimal first_number, s21_decimal second_number) {
    int rezult;
    if (first_number.value_type == 0 && second_number.value_type == 0) {
        int decimal_dec_1[121] = {0}, decimal_dec_2[121]= {0};
        convert_decimal_to_decimal_dec(decimal_dec_1, first_number);
        convert_decimal_to_decimal_dec(decimal_dec_2, second_number);
        rezult = not_equal_simple_decimal_dec(decimal_dec_1, decimal_dec_2);
    } else {
            rezult = 1;
    }
    return rezult;
}
