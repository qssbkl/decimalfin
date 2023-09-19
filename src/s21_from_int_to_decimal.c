#include <stdio.h>
#include <math.h>
#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    int flag = 1;
    if (dst != NULL) {
        int negative = 1;
        unsigned int temp_number;
        if (src < 0) {
            negative *= -1;
            if (src == - 2147483648) {
                temp_number = 2147483648;
            } else {
                temp_number = src * (-1);
            }
        } else {
            temp_number = src;
        }
        dst->bits[0] = temp_number;
        dst->bits[1] = 0;
        dst->bits[2] = 0;
        dst->bits[3] = 0;
        if (negative == - 1) dst->bits[3] = 0x80000000;
        flag = 0;
        dst->value_type = 0;
    }
    return flag;
}
