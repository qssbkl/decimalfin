#include <stdio.h>
#include <math.h>
#include "s21_decimal.h"
#include <string.h>

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    int rezult = 1;
    if (dst != NULL) {
        int negative = 1;
        if (src < 0.0) {
            negative = -1;
            src = -src;
        }
        dst->value_type = 0; dst->bits[0] = 0; dst->bits[1] = 0; dst->bits[2] = 0; dst->bits[3] = 0;
        if (src > 79228162514264337593543950335.0 || (src > 0.0 && src < 1e-28) ||
            src != src) {
            rezult = 1;
            if (src != src) {
                dst->value_type = 3;
            } else if (src == 1.0/0.0 || src > 79228162514264337593543950335.0) {
                if (negative  == 1) {
                    dst->value_type = 1;
                } else {
                    dst->value_type = 2;
                }
            } else {
                dst->value_type = 0;
                dst->bits[0] = 0; dst->bits[1] = 0; dst->bits[2] = 0; dst->bits[3] = 0;
            }
        } else {
            char number[15], exp[5];
            int exp_number, decimal_dec[121] = {0};
            snprintf(number, sizeof(number), "%+.6e", src);
            decimal_dec[60] = number[1] - 48;
            for (int i = 3; i < 9; i++) {
                decimal_dec[58 + i] = number[i] - 48;
            }
            exp[0] = number[10]; exp[1] = number[11]; exp[2] = number[12]; exp[3] = number[13]; exp[4] = '\0';
            sscanf(exp, "%d", &exp_number);
            if (exp_number > 0) {
                move_simple_dec_to_the_left(decimal_dec, exp_number);
            } else if (exp_number < 0) {
                move_simple_dec_to_the_right(decimal_dec, -exp_number);
            }
            if (negative == 1) {
                decimal_dec[0] = 1;
            } else {
                decimal_dec[0] = -1;
            }
            convert_decimal_dec_to_decimal(dst, decimal_dec);
            rezult = 0;
        }
    }
    return rezult;
}
