#include <stdio.h>
#include <math.h>
#include <string.h>

#include "s21_decimal.h"

void print_decimal_bin(unsigned int decimal_bin[]) {
        printf("We are in print_decimal_bin function.\n");
    for (int i = 0; i < 4; i++) {
        unsigned int temp_number = 0, exp = 1;
        printf("decimal.bin[%2d-%3d]=", i * 32, i * 32 + 31);
        for (int j = 0; j < 32; j++) {
            printf("%u", decimal_bin[i * 32 + j]);
            temp_number += (unsigned int) (decimal_bin[i * 32 + j] * exp);
            exp *= 2;
        }
        printf(" as dec=%10u as X=%8x ", temp_number, temp_number);
        printf("\n");
    }
    printf("We are out of print_decimal_bin\n");
}



void floor_simple_decimal_dec(int rezult_decimal_dec[], int decimal_dec[]) {
    int temp_rezult_decimal_dec[121] = {0}; temp_rezult_decimal_dec[0] = 1;
    int temp_decimal_dec[121] = {0}; temp_decimal_dec[0] = 1;
    int zero_decimal_dec[121] = {0}; zero_decimal_dec[0] = 1;
    copy_simple_decimal_dec(rezult_decimal_dec, temp_rezult_decimal_dec);
    copy_simple_decimal_dec(temp_decimal_dec, decimal_dec);
    truncate_simple_decimal_dec(temp_rezult_decimal_dec, temp_decimal_dec);
    if (less_simple_decimal_dec(decimal_dec, zero_decimal_dec)) {
        if (not_equal_simple_decimal_dec(temp_rezult_decimal_dec, temp_decimal_dec)) {
            int one_decimal_dec[121] = {0}; one_decimal_dec[0] = 1; one_decimal_dec[60] = 1;
            int temp2_decimal_dec[121] = {0};
            sub_simple_decimal_dec(temp2_decimal_dec, temp_decimal_dec, one_decimal_dec);
            truncate_simple_decimal_dec(temp_rezult_decimal_dec, temp2_decimal_dec);
        }
    }
    copy_simple_decimal_dec(rezult_decimal_dec, temp_rezult_decimal_dec);
}

void print_decimal(s21_decimal number) {
    int decimal_dec[121] = {0};
    convert_decimal_to_decimal_dec(decimal_dec, number);
    print_simple_decimal_dec(decimal_dec);
}

int equal_to_infinity(s21_decimal *rezult_number, int decimal_dec[]) {
    s21_decimal max_number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}, s21_NORMAL_VALUE};
    s21_decimal min_number = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}, s21_NORMAL_VALUE};
    int max_decimal_dec[121] = {0}, min_decimal_dec[121] = {0}, equal_to_infinity = 0;
    convert_decimal_to_decimal_dec(max_decimal_dec, max_number);
    convert_decimal_to_decimal_dec(min_decimal_dec, min_number);
    if (greater_simple_decimal_dec(decimal_dec, max_decimal_dec)) {
        equal_to_infinity = 1;
        rezult_number->bits[3] = 0;
        rezult_number->value_type = 1;
    }
    if (less_simple_decimal_dec(decimal_dec, min_decimal_dec)) {
        equal_to_infinity = 1;
        rezult_number->bits[3] = 0;
        rezult_number->value_type = 2;
    }
    return equal_to_infinity;
}

int near_to_zero(int decimal_dec[]) {
    s21_decimal near_zero_plus_number = {{1, 0, 0, 0x001c0000}, s21_NORMAL_VALUE};
    s21_decimal near_zero_minus_number = {{1, 0, 0, 0x801c0000}, s21_NORMAL_VALUE};
    int near_zero_plus_decimal_dec[121] = {0}, near_zero_minus_decimal_dec[121] = {0};
    int near_near_zero = 0;
    convert_decimal_to_decimal_dec(near_zero_plus_decimal_dec, near_zero_plus_number);
    convert_decimal_to_decimal_dec(near_zero_minus_decimal_dec, near_zero_minus_number);
    if (greater_simple_decimal_dec(decimal_dec, near_zero_minus_decimal_dec)) {
        if (less_simple_decimal_dec(decimal_dec, near_zero_plus_decimal_dec)) {
            near_near_zero = 1;
        }
    }
    return near_near_zero;
}

void convert_decimal_dec_to_decimal(s21_decimal *number, int decimal_dec[]) {
    number->bits[0] = 0; number->bits[1] = 0; number->bits[2] = 0;
    number->bits[3] = 0; number->value_type = 0;
    int temp_decimal_dec[121] = {0}, start_sign = decimal_dec[0];
    int temp2_decimal_dec[121] = {0}; temp2_decimal_dec[0] = 1;
    int  zero_to_dot = 0;
    copy_simple_decimal_dec(temp_decimal_dec, decimal_dec); temp_decimal_dec[0] = 1;
    int nmbr_before_dot = numbers_before_dot_decimal_dec(temp_decimal_dec), exp = 0;
    unsigned int temp_number = 0, sign = 1; sign = sign << 31;
    if (nmbr_before_dot > 0) {
         move_simple_dec_to_the_left(temp_decimal_dec, 29 - nmbr_before_dot);
    } else {
        move_simple_dec_to_the_left(temp_decimal_dec, 28);
    }
    round_simple_decimal_dec(temp2_decimal_dec, temp_decimal_dec);
    for (int i = 60; i > 32; i--) {
        if (temp2_decimal_dec[i] != 0) break;
        zero_to_dot++;
    }
    if (nmbr_before_dot <= 28 && nmbr_before_dot > 0) {
        exp = 29 - nmbr_before_dot;
        if (zero_to_dot <= exp) {
            move_simple_dec_to_the_right(temp2_decimal_dec, zero_to_dot);
            exp = exp - zero_to_dot;
        } else {
            move_simple_dec_to_the_right(temp2_decimal_dec, exp);
            exp = 0;
        }
    } else if (nmbr_before_dot <= 0 && nmbr_before_dot > -29) {
        exp = 28 - zero_to_dot;
        if (zero_to_dot > 0) {
            move_simple_dec_to_the_right(temp2_decimal_dec, zero_to_dot);
        }
    }
    convert_decimal_dec_to_3_int(number, temp2_decimal_dec);
    if (nmbr_before_dot <= 28 && nmbr_before_dot >= 0) {
             temp_number = exp;
    } else {
        temp_number = exp;
    }
    temp_number = temp_number << 16;
    if (start_sign == - 1) {
        temp_number = temp_number + sign;
    }
    number->bits[3] = temp_number;
}

void convert_decimal_dec_to_3_int(s21_decimal *number, int temp_decimal_dec[]) {
     int temp2_decimal_dec[121] = {0}; temp2_decimal_dec[0] = 1;
     int number_two_decimal[121] = {0}; number_two_decimal[0] = 1; number_two_decimal[60] = 2;
     int zero_decimal_dec[121] = {0}, counter = 0; zero_decimal_dec[0] = 1;
    copy_simple_decimal_dec(temp2_decimal_dec, temp_decimal_dec);
    for (int i = 0; i < 3; i++) {
        int two_exp = 1, zero_flag = 0;
        unsigned int temp_number = 0;
        for (int j = 0 ; j < 32; j++) {
            counter++;
            mod_simple_decimal_dec(temp_decimal_dec, temp2_decimal_dec, number_two_decimal);
            temp_number = temp_number + two_exp * temp_decimal_dec[60];
            two_exp = two_exp * 2;
            temp2_decimal_dec[60] -= temp_decimal_dec[60];
            if (equal_simple_decimal_dec(temp2_decimal_dec, zero_decimal_dec)) {
                zero_flag = 1;
                break;
            }
            div_simple_decimal_dec(temp_decimal_dec, temp2_decimal_dec, number_two_decimal);
            copy_simple_decimal_dec(temp2_decimal_dec, temp_decimal_dec);
        }
        number->bits[i] = temp_number;
        if (zero_flag) break;
    }
}

void round_simple_decimal_dec(int rezult_decimal_dec[], int decimal_dec[]) {
    int temp_rezult_decimal_dec[121] = {0}; temp_rezult_decimal_dec[0] = 1;
    int simple_dec_one[121] = {0}; simple_dec_one[0] = 1; simple_dec_one[60] = 1;
    int simple_dec_truncate[121] = {0}; simple_dec_truncate[0] = 1;
    copy_simple_decimal_dec(temp_rezult_decimal_dec, decimal_dec);
    int negative = 1;
    if (decimal_dec[0] == -1) {
        negative = -1;
    }
    truncate_simple_decimal_dec(simple_dec_truncate, temp_rezult_decimal_dec);
    int decimal_dec_diff[121], decimal_dec_half[121] = {0}; decimal_dec_half[61] = 5; decimal_dec_half[0] = 1;
    sub_simple_decimal_dec(decimal_dec_diff, temp_rezult_decimal_dec, simple_dec_truncate);
    decimal_dec_diff[0] = 1;
    int even_no = temp_rezult_decimal_dec[60] % 2;
    if ((greater_simple_decimal_dec(decimal_dec_diff, decimal_dec_half) && even_no == 0) ||
    (greater_or_equal_simple_decimal_dec(decimal_dec_diff, decimal_dec_half) && even_no == 1)) {
        if (negative == 1) {
            add_simple_decimal_dec(temp_rezult_decimal_dec, simple_dec_truncate, simple_dec_one);
        } else {
            sub_simple_decimal_dec(temp_rezult_decimal_dec, simple_dec_truncate, simple_dec_one);
        }
    } else {
        copy_simple_decimal_dec(temp_rezult_decimal_dec, simple_dec_truncate);
    }
    copy_simple_decimal_dec(rezult_decimal_dec, temp_rezult_decimal_dec);
}

void round_simple_decimal_dec_for_round(int rezult_decimal_dec[], int decimal_dec[]) {
    int temp_rezult_decimal_dec[121] = {0}, addition = 0; temp_rezult_decimal_dec[0] = 1;
    copy_simple_decimal_dec(temp_rezult_decimal_dec, decimal_dec);
    for (int i = 119; i > 59; i--) {
        if (temp_rezult_decimal_dec[i + 1] > 4 || (temp_rezult_decimal_dec[i + 1] == 0 && addition == 1)) {
            if (temp_rezult_decimal_dec[i] == 9) {
                temp_rezult_decimal_dec[i] = 0;
                addition = 1;
            } else {
                temp_rezult_decimal_dec[i] += 1;
                addition = 0;
            }
        }
        temp_rezult_decimal_dec[i + 1] = 0;
    }
    copy_simple_decimal_dec(rezult_decimal_dec, temp_rezult_decimal_dec);
}



void truncate_simple_decimal_dec(int rezult_decimal_dec[], int decimal_dec[]) {
    int temp_rezult_decimal_dec[121] = {0};
    copy_simple_decimal_dec(temp_rezult_decimal_dec, decimal_dec);
    for (int i = 61; i < 121; i++) {
        temp_rezult_decimal_dec[i] = 0;
    }
    copy_simple_decimal_dec(rezult_decimal_dec, temp_rezult_decimal_dec);
}

void mod_simple_decimal_dec(int rezult_decimal_dec[], int decimal_dec_1[], int decimal_dec_2[]) {
    int temp_rezult_decimal_dec[121] = {0}; temp_rezult_decimal_dec[0] = 1;
    int temp_decimal_dec_1[121] = {0}, temp_decimal_dec_2[121] = {0};
    int temp_decimal_dec[121] = {0}; temp_decimal_dec[0] = 1;
    int temp2_decimal_dec[121] = {0}; temp2_decimal_dec[0] = 1;
    copy_simple_decimal_dec(rezult_decimal_dec, temp_rezult_decimal_dec);
    copy_simple_decimal_dec(temp_decimal_dec_1, decimal_dec_1);
    copy_simple_decimal_dec(temp_decimal_dec_2, decimal_dec_2);
    div_simple_decimal_dec(temp2_decimal_dec, temp_decimal_dec_1, temp_decimal_dec_2);
    truncate_simple_decimal_dec(temp_decimal_dec, temp2_decimal_dec);
    multip_simple_decimal_dec(temp2_decimal_dec, temp_decimal_dec, temp_decimal_dec_2);
    sub_simple_decimal_dec(temp_rezult_decimal_dec, temp_decimal_dec_1, temp2_decimal_dec);
    copy_simple_decimal_dec(rezult_decimal_dec, temp_rezult_decimal_dec);
    rezult_decimal_dec[0] = decimal_dec_1[0];
}

void div_simple_decimal_dec(int rezult_decimal_dec[], int decimal_dec_1[], int decimal_dec_2[]) {
    int temp_rezult_decimal_dec[121] = {0}; temp_rezult_decimal_dec[0] = 1;
    int temp_decimal_dec_1[121] = {0}, temp_decimal_dec_2[121] = {0};
    int zero_decimal_dec[121] = {0}; zero_decimal_dec[0] = 1;
    int temp_decimal_dec[121] = {0}; temp_decimal_dec[0] = 1;
    copy_simple_decimal_dec(rezult_decimal_dec, temp_rezult_decimal_dec);
    copy_simple_decimal_dec(temp_decimal_dec_1, decimal_dec_1);
    copy_simple_decimal_dec(temp_decimal_dec_2, decimal_dec_2);
    temp_decimal_dec_1[0] = 1; temp_decimal_dec_2[0] = 1;
    int nmbr_before_dot_1 = numbers_before_dot_decimal_dec(temp_decimal_dec_1);
    int nmbr_before_dot_2 = numbers_before_dot_decimal_dec(temp_decimal_dec_2);
    int diff = nmbr_before_dot_1 - nmbr_before_dot_2, shift;
    if (diff > 0) {
        move_simple_dec_to_the_left(temp_decimal_dec_2, diff);
    } else if (diff < 0) {
        move_simple_dec_to_the_right(temp_decimal_dec_2, - diff);
    }
    if (less_simple_decimal_dec(temp_decimal_dec_1, temp_decimal_dec_2)) {
        move_simple_dec_to_the_right(temp_decimal_dec_2, 1); diff -= 1;
    }
    if (nmbr_before_dot_1 < 0) {
        shift = nmbr_before_dot_1 - 1;
        move_simple_dec_to_the_left(temp_decimal_dec_1, - shift);
        move_simple_dec_to_the_left(temp_decimal_dec_2, - shift);
    }
    if (nmbr_before_dot_1 > 0) {
        shift = nmbr_before_dot_1 - 1;
        move_simple_dec_to_the_right(temp_decimal_dec_1, shift);
        move_simple_dec_to_the_right(temp_decimal_dec_2, shift);
    }
    if (nmbr_before_dot_1 > -57) {
        for (int i = 60; i < 91; i++) {
            int counter = 0;
            while (greater_or_equal_simple_decimal_dec(temp_decimal_dec_1, temp_decimal_dec_2)) {
                sub_simple_decimal_dec(temp_decimal_dec, temp_decimal_dec_1, temp_decimal_dec_2);
                copy_simple_decimal_dec(temp_decimal_dec_1, temp_decimal_dec);
                counter++;
            }
            temp_rezult_decimal_dec[i] = counter;
            if (greater_simple_decimal_dec(temp_decimal_dec_1, zero_decimal_dec)) {
                move_simple_dec_to_the_left(temp_decimal_dec_1, 1);
            }
        }
    }
    if (diff > 0) {
        move_simple_dec_to_the_left(temp_rezult_decimal_dec, diff);
    } else if (diff < 0) {
        move_simple_dec_to_the_right(temp_rezult_decimal_dec, - diff);
    }
    temp_rezult_decimal_dec[0] = decimal_dec_1[0] * decimal_dec_2[0];
    copy_simple_decimal_dec(rezult_decimal_dec, temp_rezult_decimal_dec);
}

int numbers_before_dot_decimal_dec(const int decimal_dec[]) {
    int number = 60;
    for (int i = 1; i < 121; i++) {
        if (decimal_dec[i] != 0) {
            break;
        }
        number--;
    }
    return number;
}

void move_simple_dec_to_the_left(int decimal_dec[], int shift) {
    for (int j=0; j < shift; j++) {
        for (int i = 1; i < 120; i++) {
            decimal_dec[i] = decimal_dec[i+1];
        }
        decimal_dec[120] = 0;
    }
}

void move_simple_dec_to_the_right(int decimal_dec[], int shift) {
    for (int j = 0; j < shift; j++) {
        for (int i = 120; i > 1; i--) {
            decimal_dec[i] = decimal_dec[i-1];
        }
        decimal_dec[1] = 0;
    }
}

void convert_decimal_to_decimal_dec(int rezult_decimal_dec[], s21_decimal number) {
    unsigned int decimal_bin[128] = {0}, temp = number.bits[3], exp = number.bits[3];
    convert_number_to_decimal_bin(decimal_bin, number);
    int decimal_dec_1[121] = {0}, decimal_dec_2[121] = {0}, decimal_dec_3[121] = {0}, counter = 1;
    decimal_dec_1[0] = 1; decimal_dec_2[0] = 1; decimal_dec_3[0] = 1;
    decimal_dec_1[60] = 2;
    copy_simple_decimal_dec(rezult_decimal_dec, decimal_dec_2);
    rezult_decimal_dec[60] = decimal_bin[0];
    for (int i = 1; i < 96; i++) {
        if (decimal_bin[i] == 1) {
            copy_simple_decimal_dec(decimal_dec_3, rezult_decimal_dec);
            pow_simple_decimal_dec_with_exp(decimal_dec_2, decimal_dec_1, counter);
            add_simple_decimal_dec(rezult_decimal_dec, decimal_dec_3, decimal_dec_2);
        }
        counter++;
    }
    counter = 60;
    exp = exp << 8;
    exp = exp >> 24;
    if (exp) {
        for (int i = 60 + exp; i > 0; i--) {
            if (counter > 0) {
                rezult_decimal_dec[i] = rezult_decimal_dec[i - exp];
            } else {
                rezult_decimal_dec[i + exp] = 0;
            }
            counter--;
        }
    }
    temp = temp >> 31;
    if (temp) {
        rezult_decimal_dec[0] = -1;
    } else {
        rezult_decimal_dec[0] = 1;
    }
}

void convert_number_to_decimal_bin(unsigned int decimal_bin[], s21_decimal number) {
    unsigned int temp, counter = 0;
    for (int i = 0; i < 3; i++) {
        for (int j=0; j < 32; j++) {
            temp = number.bits[i]%2;
            decimal_bin[counter] = temp;
            counter++;
            number.bits[i] /= 2;
        }
    }
        for (int j=0; j < 32; j++) {
            temp = number.bits[3]%2;
            decimal_bin[counter] = temp;
            counter++;
            number.bits[3] /= 2;
        }
}

int equal_simple_decimal_dec(const int decimal_dec_1[], const int decimal_dec_2[]) {
    int rezult = 1;
    for (int i = 120; i > -1; i--) {
        if (decimal_dec_1[i] != decimal_dec_2[i]) {
            rezult = 0;
            break;
        }
    }
    return rezult;
}

int greater_simple_decimal_dec(int decimal_dec_1[], int decimal_dec_2[]) {
    int rezult;
    if (equal_simple_decimal_dec(decimal_dec_1, decimal_dec_2)) {
        rezult = 0;
    } else if (decimal_dec_1[0] == 1 && decimal_dec_2[0] == -1) {
        rezult = 1;
    } else if (decimal_dec_1[0] == -1 && decimal_dec_2[0] == -1) {
        rezult = 1;
        for (int i = 1; i < 121; i++) {
            if (decimal_dec_1[i] > decimal_dec_2[i]) {
                rezult = 0;
                break;
            } else if (decimal_dec_1[i] < decimal_dec_2[i]) {
                rezult = 1;
                break;
            }
        }
    } else if (decimal_dec_1[0] == 1 && decimal_dec_2[0] == 1) {
        rezult = 1;
        for (int i = 1; i < 121; i++) {
            if (decimal_dec_1[i] < decimal_dec_2[i]) {
                rezult = 0;
                break;
            } else if (decimal_dec_1[i] > decimal_dec_2[i]) {
                rezult = 1;
                break;
            }
        }
    } else {
        rezult = 0;
    }
    return rezult;
}

int less_simple_decimal_dec(int decimal_dec_1[], int decimal_dec_2[]) {
    int rezult = 1;
    if (equal_simple_decimal_dec(decimal_dec_1, decimal_dec_2)) {
        rezult = 0;
    } else if (greater_simple_decimal_dec(decimal_dec_1, decimal_dec_2)) {
        rezult = 0;
    }
    return rezult;
}

int less_or_equal_simple_decimal_dec(int decimal_dec_1[], int decimal_dec_2[]) {
    int rezult = 1;
    if (greater_simple_decimal_dec(decimal_dec_1, decimal_dec_2)) {
        rezult = 0;
    }
    return rezult;
}

int greater_or_equal_simple_decimal_dec(int decimal_dec_1[], int decimal_dec_2[]) {
    int rezult = 1;
    if (less_simple_decimal_dec(decimal_dec_1, decimal_dec_2)) {
        rezult = 0;
    }
    return rezult;
}

int not_equal_simple_decimal_dec(int decimal_dec_1[], int decimal_dec_2[]) {
    int rezult = 1;
    if (equal_simple_decimal_dec(decimal_dec_1, decimal_dec_2)) {
        rezult = 0;
    }
    return rezult;
}


void sub_simple_decimal_dec(int rezult_decimal_dec[], int decimal_dec_1[], int decimal_dec_2[]) {
    int temp_decimal_dec_1[121] = {0}, temp_decimal_dec_2[121] = {0};
    copy_simple_decimal_dec(temp_decimal_dec_1, decimal_dec_1);
    copy_simple_decimal_dec(temp_decimal_dec_2, decimal_dec_2);

    if (greater_or_equal_simple_decimal_dec(decimal_dec_1, decimal_dec_2) &&
    decimal_dec_1[0] == 1 && decimal_dec_2[0] == 1) {
        sub_simple_decimal_dec_for_positive_both(rezult_decimal_dec, temp_decimal_dec_1, temp_decimal_dec_2);

    } else if (less_simple_decimal_dec(decimal_dec_1, decimal_dec_2) &&
    decimal_dec_1[0] == 1 && decimal_dec_2[0] == 1) {
        sub_simple_decimal_dec(rezult_decimal_dec, temp_decimal_dec_2, temp_decimal_dec_1);
        rezult_decimal_dec[0] *= - 1;

    } else if (less_simple_decimal_dec(decimal_dec_1, decimal_dec_2) &&
    decimal_dec_1[0] == - 1 && decimal_dec_2[0] == - 1) {
        temp_decimal_dec_1[0] = 1; temp_decimal_dec_2[0] = 1;
        sub_simple_decimal_dec(rezult_decimal_dec, temp_decimal_dec_1, temp_decimal_dec_2);
        rezult_decimal_dec[0] *= -1;

    } else if (greater_or_equal_simple_decimal_dec(decimal_dec_1, decimal_dec_2) &&
    decimal_dec_1[0] == - 1 && decimal_dec_2[0] == - 1) {
        temp_decimal_dec_1[0] = 1; temp_decimal_dec_2[0] = 1;
        sub_simple_decimal_dec(rezult_decimal_dec, temp_decimal_dec_1, temp_decimal_dec_2);
        rezult_decimal_dec[0] *= -1;

    } else if (decimal_dec_1[0] == 1 && decimal_dec_2[0] == - 1) {
        temp_decimal_dec_2[0] = 1;
        add_simple_decimal_dec(rezult_decimal_dec, temp_decimal_dec_1, temp_decimal_dec_2);

    } else if (decimal_dec_1[0] == - 1 && decimal_dec_2[0] == 1) {
        temp_decimal_dec_1[0] = 1;
        add_simple_decimal_dec(rezult_decimal_dec, temp_decimal_dec_1, temp_decimal_dec_2);
        rezult_decimal_dec[0] *= -1;
    }
}

void sub_simple_decimal_dec_for_positive_both(int rezult_decimal_dec[],
int decimal_dec_1[], int decimal_dec_2[]) {
    int temp_decimal_dec_1[121] = {0}, temp_decimal_dec_2[121] = {0};
    copy_simple_decimal_dec(temp_decimal_dec_1, decimal_dec_1);
    copy_simple_decimal_dec(temp_decimal_dec_2, decimal_dec_2);
    int temp = 0, sub;
    for (int i = 120; i > 0; i--) {
        if (temp_decimal_dec_1[i] - temp >= temp_decimal_dec_2[i]) {
            sub = temp_decimal_dec_1[i] - temp_decimal_dec_2[i] - temp;
            temp = 0;
        } else {
            sub = temp_decimal_dec_1[i] + 10 - temp_decimal_dec_2[i] - temp;
            temp = 1;
        }
        rezult_decimal_dec[i] = sub % 10;
    }
    rezult_decimal_dec[0] = 1;
}

void add_simple_decimal_dec(int rezult_decimal_dec[], int decimal_dec_1[], int decimal_dec_2[]) {
    if (decimal_dec_1[0] == 1 && decimal_dec_2[0] == 1) {
        int temp = 0;
        for (int i = 120; i > 0; i--) {
            int sum;
            sum = decimal_dec_1[i] + decimal_dec_2[i] + temp;
            rezult_decimal_dec[i] = sum % 10;
            temp  = sum / 10;
        }
        rezult_decimal_dec[0] = 1;
    } else if (decimal_dec_1[0] == -1 && decimal_dec_2[0] == 1) {
        decimal_dec_1[0] = 1;
        sub_simple_decimal_dec(rezult_decimal_dec, decimal_dec_2, decimal_dec_1);
    } else if (decimal_dec_1[0] == 1 && decimal_dec_2[0] == -1) {
        decimal_dec_2[0] = 1;
        sub_simple_decimal_dec(rezult_decimal_dec, decimal_dec_1, decimal_dec_2);
    } else {
        decimal_dec_1[0] = 1;
        decimal_dec_2[0] = 1;
        add_simple_decimal_dec(rezult_decimal_dec, decimal_dec_2, decimal_dec_1);
        rezult_decimal_dec[0] = -1;
    }
}

void multip_simple_decimal_dec_with_multiplier(int rezult_decimal_dec[],
int decimal_dec_1[], int multiplier) {
    int temp_rezult_decimal_dec[121] = {0}; temp_rezult_decimal_dec[0] = 1;
    if (multiplier > 0) {
        int decimal_dec_2[121] = {0}, decimal_dec_3[121] = {0};
        decimal_dec_2[0] = 1; decimal_dec_3[0] = 1;
        copy_simple_decimal_dec(decimal_dec_2, decimal_dec_1);
        for (int i = 0; i < multiplier; i++) {
            add_simple_decimal_dec(temp_rezult_decimal_dec, decimal_dec_3, decimal_dec_2);
            copy_simple_decimal_dec(decimal_dec_3, temp_rezult_decimal_dec);
        }
    }
    copy_simple_decimal_dec(rezult_decimal_dec, temp_rezult_decimal_dec);
}

void multip_simple_decimal_dec(int rezult_decimal_dec[], int decimal_dec_1[], int decimal_dec_2[]) {
    rezult_decimal_dec[0] = 1;
    int decimal_dec_4[121] = {0}; decimal_dec_4[0] = 1;
    int temp_rezult_decimal_dec[121] = {0}; temp_rezult_decimal_dec[0] = 1;
    int temp_decimal_dec_1[121] = {0}, temp_decimal_dec_2[121] = {0};
    int temp_decimal_dec[121] = {0}; temp_decimal_dec[0] = 1;
    copy_simple_decimal_dec(rezult_decimal_dec, temp_rezult_decimal_dec);
    copy_simple_decimal_dec(temp_decimal_dec_1, decimal_dec_1);
    copy_simple_decimal_dec(temp_decimal_dec_2, decimal_dec_2);
    temp_decimal_dec_1[0] = 1; temp_decimal_dec_2[0] = 1;
    for (int i = 120; i > 0; i--) {
        if (decimal_dec_2[i] != 0) {
            int shift = 60 - i;
            multip_simple_decimal_dec_with_multiplier(temp_decimal_dec,
            temp_decimal_dec_1, temp_decimal_dec_2[i]);
            if (shift > 0) {
                move_simple_dec_to_the_left(temp_decimal_dec, shift);
            } else if (shift < 0) {
                move_simple_dec_to_the_right(temp_decimal_dec, - shift);
            }
            add_simple_decimal_dec(temp_rezult_decimal_dec, temp_decimal_dec, decimal_dec_4);
            copy_simple_decimal_dec(decimal_dec_4, temp_rezult_decimal_dec);
        }
    }
    temp_rezult_decimal_dec[0] = decimal_dec_1[0] * decimal_dec_2[0];
    copy_simple_decimal_dec(rezult_decimal_dec, temp_rezult_decimal_dec);
}

void pow_simple_decimal_dec_with_exp(int rezult_decimal_dec[], int decimal_dec_1[], int exp) {
    int decimal_dec_2[121] = {0};
    decimal_dec_2[0] = 1;
    copy_simple_decimal_dec(rezult_decimal_dec, decimal_dec_2);
    copy_simple_decimal_dec(decimal_dec_2, decimal_dec_1);
    if (exp == 0) {
        rezult_decimal_dec[60] = 1;
    } else if (exp == 1) {
        copy_simple_decimal_dec(rezult_decimal_dec, decimal_dec_1);
    } else {
        for (int i = 0; i < exp - 1; i++) {
            multip_simple_decimal_dec(rezult_decimal_dec, decimal_dec_2, decimal_dec_1);
            copy_simple_decimal_dec(decimal_dec_2, rezult_decimal_dec);
        }
    }
}

void if_inf_or_nan_3(s21_decimal *rezult_number, s21_decimal first_number, s21_decimal second_number) {
    if (first_number.value_type == s21_NAN || second_number.value_type == s21_NAN) {
        rezult_number->value_type = s21_NAN;
    } else if (first_number.value_type == 1 && second_number.value_type == 1) {
        rezult_number->value_type = 1;
    } else if (first_number.value_type == 1 && second_number.value_type == 0) {
        if (second_number.bits[3] < 0x80000000) {
            rezult_number->value_type = 1;
        } else {
            rezult_number->value_type = 3;
        }
    } else if (first_number.value_type == 0 && second_number.value_type == 1) {
        if (second_number.bits[3] < 0x80000000) {
            rezult_number->value_type = 0;
            rezult_number->bits[0] = first_number.bits[0];
            rezult_number->bits[1] = first_number.bits[1];
            rezult_number->bits[2] = first_number.bits[2];
            rezult_number->bits[3] = first_number.bits[3];
        } else {
            rezult_number->value_type = 3;
        }

    } else if (first_number.value_type == 2 && second_number.value_type == 2) {
        rezult_number->value_type = 3;
    } else if (first_number.value_type == 0 && second_number.value_type == 2) {
        if (second_number.bits[3] < 0x80000000) {
            rezult_number->value_type = 0;
            rezult_number->bits[0] = first_number.bits[0];
            rezult_number->bits[1] = first_number.bits[1];
            rezult_number->bits[2] = first_number.bits[2];
            rezult_number->bits[3] = first_number.bits[3];
        } else {
            rezult_number->value_type = 3;
        }
    } else if (first_number.value_type == 2 && second_number.value_type == 0) {
        if (second_number.bits[3] >= 0x80000000) {
            rezult_number->value_type = 1;
        } else {
            rezult_number->value_type = 3;
        }
    } else if (first_number.value_type == 1 && second_number.value_type == 2) {
        if (first_number.bits[3] < 0x80000000 && second_number.bits[3] < 0x80000000) {
            rezult_number->value_type = 3;
        } else if (first_number.bits[3] >= 0x80000000 && second_number.bits[3] >= 0x80000000) {
            rezult_number->value_type = 3;
        } else {
            rezult_number->value_type = 2;
        }
    } else if (first_number.value_type == 2 && second_number.value_type == 1) {
        if (first_number.bits[3] < 0x80000000 && second_number.bits[3] < 0x80000000) {
            rezult_number->value_type = 3;
        } else if (first_number.bits[3] >= 0x80000000 && second_number.bits[3] >= 0x80000000) {
            rezult_number->value_type = 3;
        } else {
            rezult_number->value_type = 2;
        }
    } else {
        rezult_number->value_type = s21_NEGATIVE_INFINITY;
        rezult_number->bits[3] = 0;
    }
}

void if_inf_or_nan_2(s21_decimal *rezult_number, s21_decimal first_number, s21_decimal second_number) {
    if (first_number.value_type == s21_NAN || second_number.value_type == s21_NAN) {
        rezult_number->value_type = s21_NAN;
    } else if (first_number.value_type == 1 && second_number.value_type == 1) {
        rezult_number->value_type = 1;
    } else if (first_number.value_type == 1 && second_number.value_type == 0) {
        if (second_number.bits[3] < 0x80000000) {
            rezult_number->value_type = 1;
        } else {
            rezult_number->value_type = 3;
        }
    } else if (first_number.value_type == 0 && second_number.value_type == 1) {
        rezult_number->bits[3] = 0;
    } else if (first_number.value_type == 2 && second_number.value_type == 2) {
        rezult_number->value_type = 3;
    } else if (first_number.value_type == 0 && second_number.value_type == 2) {
        rezult_number->bits[3] = 0x80000000;
    } else if (first_number.value_type == 2 && second_number.value_type == 0) {
        if (second_number.bits[3] >= 0x80000000) {
            rezult_number->value_type = 1;
        } else {
            rezult_number->value_type = 3;
        }
    } else if (first_number.value_type == 1 && second_number.value_type == 2) {
        if (first_number.bits[3] < 0x80000000 && second_number.bits[3] < 0x80000000) {
            rezult_number->value_type = 3;
        } else if (first_number.bits[3] >= 0x80000000 && second_number.bits[3] >= 0x80000000) {
            rezult_number->value_type = 3;
        } else {
            rezult_number->value_type = 2;
        }
    } else if (first_number.value_type == 2 && second_number.value_type == 1) {
        if (first_number.bits[3] < 0x80000000 && second_number.bits[3] < 0x80000000) {
            rezult_number->value_type = 3;
        } else if (first_number.bits[3] >= 0x80000000 && second_number.bits[3] >= 0x80000000) {
            rezult_number->value_type = 3;
        } else {
            rezult_number->value_type = 2;
        }
    } else {
        rezult_number->value_type = s21_NEGATIVE_INFINITY;
        rezult_number->bits[3] = 0;
    }
}

void if_near_to_zero_2(s21_decimal *rezult_number, s21_decimal first_number, s21_decimal second_number) {
    int first_number_zero = 0, second_number_zero = 0;
    if (first_number.bits[0] == 0 && first_number.bits[1] == 0 &&
    first_number.bits[2] == 0) first_number_zero = 1;
    if (second_number.bits[0] == 0 && second_number.bits[1] == 0 &&
    second_number.bits[2] == 0) second_number_zero = 1;
    if (first_number_zero && second_number_zero) {
        if (first_number.bits[3] >= 0x80000000 && second_number.bits[3] < 0x80000000) {
            rezult_number->bits[3] = 0x80000000;
        } else if (first_number.bits[3] < 0x80000000 && second_number.bits[3] >= 0x80000000) {
            rezult_number->bits[3] = 0x80000000;
        }
    } else if (first_number_zero) {
        if (second_number.bits[3] >= 0x80000000) {
            rezult_number->bits[3] = 0x80000000;
        } else if (first_number.bits[3] >= 0x80000000) {
            rezult_number->bits[3] = 0x80000000;
        }
    } else if (second_number_zero) {
        if (first_number.bits[3] >= 0x80000000) {
            rezult_number->bits[3] = 0x80000000;
        } else if (second_number.bits[3] >= 0x80000000) {
            rezult_number->bits[3] = 0x80000000;
        }
    } else if (first_number.bits[3] < 0x80000000 && second_number.bits[3] >= 0x80000000) {
            rezult_number->bits[3] = 0x80000000;
    } else if (first_number.bits[3] >= 0x80000000 && second_number.bits[3] < 0x80000000) {
            rezult_number->bits[3] = 0x80000000;
    }
}

void if_inf_or_nan(s21_decimal *rezult_number, s21_decimal first_number, s21_decimal second_number) {
    if (first_number.value_type == s21_NAN || second_number.value_type == s21_NAN) {
        rezult_number->value_type = s21_NAN;
    } else if (first_number.value_type == 1 && second_number.value_type == 1) {
        rezult_number->value_type = 1;
    } else if (first_number.value_type == 1 && second_number.value_type == 0) {
        rezult_number->value_type = 3;
    } else if (first_number.value_type == 0 && second_number.value_type == 1) {
        rezult_number->value_type = 3;
    } else if (first_number.value_type == 2 && second_number.value_type == 2) {
        rezult_number->value_type = 1;
    } else if (first_number.value_type == 0 && second_number.value_type == 2) {
        rezult_number->value_type = 3;
    } else if (first_number.value_type == 2 && second_number.value_type == 0) {
        rezult_number->value_type = 3;
    } else if (first_number.value_type == 1 && second_number.value_type == 2) {
        if (first_number.bits[3] < 0x80000000 && second_number.bits[3] < 0x80000000) {
            rezult_number->value_type = 3;
        } else if (first_number.bits[3] >= 0x80000000 && second_number.bits[3] >= 0x80000000) {
            rezult_number->value_type = 3;
        } else {
            rezult_number->value_type = 2;
        }
    } else if (first_number.value_type == 2 && second_number.value_type == 1) {
        if (first_number.bits[3] < 0x80000000 && second_number.bits[3] < 0x80000000) {
            rezult_number->value_type = 3;
        } else if (first_number.bits[3] >= 0x80000000 && second_number.bits[3] >= 0x80000000) {
            rezult_number->value_type = 3;
        } else {
            rezult_number->value_type = 2;
        }
    } else {
        rezult_number->value_type = s21_NEGATIVE_INFINITY;
        rezult_number->bits[3] = 0;
    }
}

void if_near_to_zero(s21_decimal *rezult_number, s21_decimal first_number, s21_decimal second_number) {
    int first_number_zero = 0, second_number_zero = 0;
    if (first_number.bits[0] == 0 && first_number.bits[1] == 0 &&
    first_number.bits[2] == 0) first_number_zero = 1;
    if (second_number.bits[0] == 0 && second_number.bits[1] == 0 &&
    second_number.bits[2] == 0) second_number_zero = 1;
    if (first_number_zero && second_number_zero) {
        if (first_number.bits[3] >= 0x80000000 && second_number.bits[3] < 0x80000000) {
            rezult_number->bits[3] = 0x80000000;
        } else if (first_number.bits[3] < 0x80000000 && second_number.bits[3] >= 0x80000000) {
            rezult_number->bits[3] = 0x80000000;
        }
    } else if (first_number_zero) {
        if (second_number.bits[3] >= 0x80000000) {
            rezult_number->bits[3] = 0x80000000;
        } else if (first_number.bits[3] >= 0x80000000) {
            rezult_number->bits[3] = 0x80000000;
        }
    } else if (second_number_zero) {
        if (first_number.bits[3] >= 0x80000000) {
            rezult_number->bits[3] = 0x80000000;
        } else if (second_number.bits[3] >= 0x80000000) {
            rezult_number->bits[3] = 0x80000000;
        }
    } else if (first_number.bits[3] < 0x80000000 && second_number.bits[3] >= 0x80000000) {
            rezult_number->bits[3] = 0x80000000;
    } else if (first_number.bits[3] >= 0x80000000 && second_number.bits[3] < 0x80000000) {
            rezult_number->bits[3] = 0x80000000;
    }
}


void print_simple_decimal_dec(int decimal_dec[]) {
    printf("decimal_dec = ");
    if (decimal_dec[0] == 1) {
        printf("+");
    } else {
        printf("-");
    }
    for (int i = 31; i < 61; i++) {
        printf("%d", decimal_dec[i]);
    }
    printf(".");
    for (int i = 61; i < 91; i++) {
        printf("%d", decimal_dec[i]);
    }
    printf("\n");
}

void copy_simple_decimal_dec(int decimal_dec_1[], const int decimal_dec_2[]) {
        for (int i = 120; i > -1; i--) {
        decimal_dec_1[i] = decimal_dec_2[i];
    }
}

void s21_print_decimal_dec(s21_decimal number) {
    unsigned int decimal_bin[128];
    int decimal_dec[121] = {0};
    convert_number_to_decimal_bin(decimal_bin, number);
    print_decimal_bin(decimal_bin);
    convert_decimal_to_decimal_dec(decimal_dec, number);
    printf("\t   value-type = %d\n", number.value_type);
    printf("\t  "); print_simple_decimal_dec(decimal_dec);
    printf("\n");
}

void s21_print_decimal_bin(s21_decimal number) {
    unsigned int decimal_bin[128];
    convert_number_to_decimal_bin(decimal_bin, number);
    print_decimal_bin(decimal_bin);
}
