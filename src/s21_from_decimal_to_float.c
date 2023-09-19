#include <stdio.h>
#include <math.h>
#include <string.h>
#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
    int rezult = 1;
    if (src.value_type == 1) {
        *dst = 1.0/0.0;
    } else if (src.value_type == 2) {
        *dst = -1.0/0.0;
    } else if (src.value_type == 3) {
        float nan = 0;
        memset(dst, 0xFF, sizeof(nan));
    } else {
        int decimal_dec[121] = {0}, counter = 1;
        convert_decimal_to_decimal_dec(decimal_dec, src);
        char number[123];
        for (int i = 0; i < 123; i++) {
            number[i] = '0';
        }
        if (decimal_dec[0] == 1) {
            number[0] = '+';
        } else {
            number[0] = '-';
        }
        for (int i = 1; i < 121; i++) {
            number[counter] = decimal_dec[i] + 48;
            counter++;
            if (i == 60) {
                number[counter] = '.';
                counter++;
            }
        }
        number[122] = '\0';
        sscanf(number, "%f", dst);
        rezult = 0;
    }
    return rezult;
}
