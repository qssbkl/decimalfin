#include <stdio.h>
#include <string.h>
#include <math.h>
#include <check.h>
#include "s21_decimal.h"

s21_decimal create_decimal(unsigned int x0, unsigned int x1,
unsigned x2, unsigned int x3, value_type_t type) {
    s21_decimal number;
    number.bits[0] = x0;
    number.bits[1] = x1;
    number.bits[2] = x2;
    number.bits[3] = x3;
    number.value_type = type;
    return number;
}

s21_decimal decimal_presentation(unsigned int bit_0, unsigned int bit_1,
                             unsigned int bit_2, int sign, int exp, int val) {
  s21_decimal tmp;
  tmp.bits[0] = bit_0;
  tmp.bits[1] = bit_1;
  tmp.bits[2] = bit_2;
  tmp.bits[3] = 0;
  tmp.bits[3] = (unsigned int)(exp << 16);
  tmp.bits[3] = tmp.bits[3] + (unsigned int)(sign ? 0x80000000 : 0);
  tmp.value_type = (value_type_t)val;
  return (tmp);
}

int equal_decimal_for_test(s21_decimal first_number, s21_decimal second_number) {
    int rezult = 0;
    if (first_number.bits[0] != second_number.bits[0]) rezult = 1;
    if (first_number.bits[1] != second_number.bits[1]) rezult = 1;
    if (first_number.bits[2] != second_number.bits[2]) rezult = 1;
    if (first_number.bits[3] != second_number.bits[3]) rezult = 1;
    if (first_number.value_type != second_number.value_type) rezult = 1;
    return rezult;
}

int set_for_add(int count_number, s21_decimal *x, s21_decimal *y, s21_decimal *z) {
    int counter = count_number;
    s21_decimal temp_number = {0};
    switch (count_number) {
        case 1:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0, 0);
            break;
        case 2:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(0, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0, 1);
            break;
        case 3:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 1);
            *z = create_decimal(0, 0, 0, 0, 1);
            break;
        case 4:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(0, 0, 0, 0, 1);
            *z = create_decimal(0, 0, 0, 0, 1);
            break;
        case 5:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(0, 0, 0, 0, 2);
            *z = create_decimal(0, 0, 0, 0, 3);
            break;
        case 6:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 1);
            *z = create_decimal(0, 0, 0, 0, 3);
            break;
        case 7:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 2);
            *z = create_decimal(0, 0, 0, 0, 2);
            break;
        case 8:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 2);
            *z = create_decimal(0, 0, 0, 0, 2);
            break;
        case 9:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 2);
            *z = create_decimal(0, 0, 0, 0, 2);
            break;
        case 10:
            *x = create_decimal(0, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0, 0);
            break;
        case 11:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0x80000000, 0);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 12:
            *x = create_decimal(7, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *z = create_decimal(7, 0, 0, 0, 0);
            break;
        case 13:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(7, 0, 0, 0, 0);
            *z = create_decimal(7, 0, 0, 0, 0);
            break;
        case 14:
            *x = create_decimal(7, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(7, 0, 0, 0, 0);
            break;
        case 15:
            *x = create_decimal(0, 0, 0, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(7, 0, 0, 0, 0);
            *z = create_decimal(7, 0, 0, 0, 0);
            break;
        case 16:
            *x = create_decimal(7, 0, 0, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(0, 0, 0, 0, 0);
            *z = create_decimal(7, 0, 0, 0x80000000, 0);
            break;
        case 17:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(7, 0, 0, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(7, 0, 0, 0x80000000, 0);
            break;
        case 18:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            break;
        case 19:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            break;
        case 20:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            break;
        case 21:
            *x = create_decimal(0, 0, 0, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            break;
        case 22:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(0, 0, 0, 0, 0);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            break;
        case 23:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            break;
        case 24:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(0, 0, 0, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            break;
        case 25:
            *x = create_decimal(0, 0, 0, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            break;
        case 26:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *y = create_decimal(1, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0, 1);
            break;
        case 27:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *z = create_decimal(0, 0, 0, 0, 1);
            break;
        case 28:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *y = create_decimal(1, 0, 0, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0xfffffffe, 0xffffffff, 0xffffffff, 0x00000000, 0);
            break;
        case 29:
            *x = create_decimal(1, 0, 0, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *z = create_decimal(0xfffffffe, 0xffffffff, 0xffffffff, 0x00000000, 0);
            break;
        case 30:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(1, 0, 0, 0, 0);
            *z = create_decimal(0xfffffffe, 0xffffffff, 0xffffffff, 0x80000000, 0);
            break;
        case 31:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0xfffffffe, 0xffffffff, 0xffffffff, 0x80000000, 0);
            break;
        case 32:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(1, 0, 0, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0, 0, 0, 0, 2);
            break;
        case 33:
            *x = create_decimal(1, 0, 0, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0, 0, 0, 0, 2);
            break;
        case 34:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *z = create_decimal(0, 0, 0, 0, 1);
            break;
        case 35:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0, 0, 0, 0, 0);
            break;
        case 36:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *z = create_decimal(0, 0, 0, 0, 0);
            break;
        case 37:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0, 0, 0, 0, 2);
            break;
        case 38:
            *x = create_decimal(99, 0, 0, 0, 0);
            *y = create_decimal(1, 0, 0, 0, 0);
            *z = create_decimal(100, 0, 0, 0, 0);
            break;
        case 39:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(99, 0, 0, 0, 0);
            *z = create_decimal(100, 0, 0, 0, 0);
            break;
        case 40:
            *x = create_decimal(99, 0, 0, 0, 0);
            *y = create_decimal(1, 0, 0, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(98, 0, 0, 0, 0);
            break;
        case 41:
            *x = create_decimal(99, 0, 0, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(1, 0, 0, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(100, 0, 0, 0x80000000, 0);
            break;
        case 42:
            *x = create_decimal(1, 0, 0, 2 << 16, 0);
            *y = create_decimal(99, 0, 0, 0, 0);
            *z = create_decimal(9901, 0, 0, 2 << 16, 0);
            break;
        case 43:
            *x = create_decimal(99, 0, 0, 0, 0);
            *y = create_decimal(1, 0, 0, 2 << 16, 0);
            *y = s21_negate(*y);
            *z = create_decimal(9899, 0, 0, 2 << 16, 0);
            break;
        case 44:
            *x = create_decimal(0xfffffffe, 0xffffffff, 0xffffffff, 0, 0);
            *y = create_decimal(1, 0, 0, 0, 0);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            break;
        case 45:
            *x = create_decimal(0xffffffff, 0xfffffffe, 0xffffffff, 0, 0);
            *y = create_decimal(0, 1, 0, 0x80000000, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            break;
        case 46:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0xfffffffe, 0xffffffff, 0xffffffff, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            break;
        case 47:
            *x = create_decimal(4294967295, 4294967295, 4294967295, 0, 0);
            *y = create_decimal(1, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0, 1);
            break;
        case 48:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *y = create_decimal(1, 0, 0, 28 << 16, 0);
            *z = create_decimal(0, 0, 0, 0, 1);
            break;
        case 49:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *y = create_decimal(1, 0, 0, 28 << 16, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0, 0, 0, 0, 2);
            break;
        case 50:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 3);
            *z = create_decimal(0, 0, 0, 0, 3);
            break;
        case 51:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(1, 0, 0, 0x00090000, 0);
            *z = create_decimal(0, 0, 0, 0, 3);
            break;
        default:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            counter = 0;
    }
    return counter;
}

int set_for_sub(int count_number, s21_decimal *x, s21_decimal *y, s21_decimal *z) {
    int counter = count_number;
    s21_decimal temp_number = {0};
    switch (count_number) {
        case 1:
            *x = decimal_presentation(0, 0, 0, 0, 0, 1);
            *y = decimal_presentation(0, 0, 0, 0, 0, 1);
            *z = decimal_presentation(0, 0, 0, 0, 0, 3);
            break;
        case 2:
            *x = decimal_presentation(0, 0, 0, 0, 0, 1);
            *y = decimal_presentation(0, 0, 123123, 0, 0, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 1);
            break;
        case 3:
            *x = decimal_presentation(0, 0, 0, 0, 0, 1);
            *y = decimal_presentation(0, 0, 0, 0, 0, 2);
            *z = decimal_presentation(0, 0, 0, 0, 0, 1);
            break;
        case 4:
            *x = decimal_presentation(0, 0, 0, 0, 0, 2);
            *y = decimal_presentation(0, 0, 0, 0, 0, 1);
            *z = decimal_presentation(0, 0, 0, 0, 0, 2);
            break;
        case 5:
            *x = decimal_presentation(0, 0, 0, 0, 0, 2);
            *y = decimal_presentation(0, 0, 0, 0, 0, 2);
            *z = decimal_presentation(0, 0, 0, 0, 0, 3);
            break;
        case 6:
            *x = decimal_presentation(0, 0, 0, 0, 0, 2);
            *y = decimal_presentation(0, 31231312, 0, 0, 0, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 2);
            break;
        case 7:
            *x = decimal_presentation(0, 123, 123, 0, 0, 0);
            *y = decimal_presentation(0, 0, 0, 0, 0, 2);
            *z = decimal_presentation(0, 0, 0, 0, 0, 1);
            break;
        case 8:
            *x = decimal_presentation(0, 4422, 0, 0, 0, 0);
            *y = decimal_presentation(0, 0, 0, 0, 0, 1);
            *z = decimal_presentation(0, 0, 0, 0, 0, 2);
            break;
        case 9:
            *x = decimal_presentation(4294967295, 4294967295, 4294967295, 0, 0, 0);
            *y = decimal_presentation(1, 0, 0, 1, 0, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 1);
            break;
        case 10:
           *x = decimal_presentation(4294967295, 4294967295, 4294967295, 1, 0, 0);
           *y = decimal_presentation(1, 0, 0, 0, 0, 0);
           *z = decimal_presentation(0, 0, 0, 0, 0, 2);
            break;
        case 11:
           *x = decimal_presentation(1, 0, 0, 0, 0, 0);
           *y = decimal_presentation(4294967295, 4294967295, 4294967295, 1, 0, 0);
           *z = decimal_presentation(0, 0, 0, 0, 0, 1);
            break;
        case 12:
           *x = decimal_presentation(4294967295, 0, 0, 1, 0, 0);
           *y = decimal_presentation(4294967295, 4294967295, 4294967295, 1, 0, 0);
           *z = decimal_presentation(0, 4294967295, 4294967295, 0, 0, 0);
            break;
        case 13:
           *x = decimal_presentation(4294967295, 4294967295, 4294967295, 1, 0, 0);
           *y = decimal_presentation(4294967295, 4294967295, 4294967295, 1, 0, 0);
           *z = decimal_presentation(0, 0, 0, 0, 0, 0);
            break;
        case 14:
           *x = decimal_presentation(0, 0, 0, 0, 0, 0);
           *y = decimal_presentation(123, 456, 789, 0, 0, 0);
           *z = decimal_presentation(123, 456, 789, 1, 0, 0);
            break;
        case 15:
           *x = decimal_presentation(123, 456, 789, 0, 0, 0);
           *y = decimal_presentation(0, 0, 0, 0, 0, 0);
           *z = decimal_presentation(123, 456, 789, 0, 0, 0);
            break;
        case 16:
           *x = decimal_presentation(4294967295, 4294967295, 4294967295, 0, 0, 0);
           *y = decimal_presentation(4294967295, 4294967295, 4294967295, 0, 0, 0);
           *z = decimal_presentation(0, 0, 0, 0, 0, 0);
            break;
        case 17:
           *x = decimal_presentation(4294967295, 4294967295, 4294967295, 0, 0, 0);
           *y = decimal_presentation(4294967295, 4294967295, 4294967295, 1, 0, 0);
           *z = decimal_presentation(0, 0, 0, 0, 0, 1);
            break;
        case 18:
           *x = decimal_presentation(4294967294, 4294967295, 4294967295, 0, 0, 0);
           *y = decimal_presentation(4294967295, 4294967295, 4294967295, 0, 0, 0);
           *z = decimal_presentation(1, 0, 0, 1, 0, 0);
            break;
        case 19:
           *x = decimal_presentation(4294967294, 4294967295, 4294967295, 1, 0, 0);
           *y = decimal_presentation(4294967295, 4294967295, 4294967295, 1, 0, 0);
           *z = decimal_presentation(1, 0, 0, 0, 0, 0);
            break;
        case 20:
           *x = decimal_presentation(1000000, 0, 0, 1, 0, 0);
           *y = decimal_presentation(500000, 0, 0, 1, 0, 0);
           *z = decimal_presentation(500000, 0, 0, 1, 0, 0);
            break;
        case 21:
           *x = decimal_presentation(1000000, 0, 0, 1, 0, 0);
           *y = decimal_presentation(500000, 0, 0, 0, 0, 0);
           *z = decimal_presentation(1500000, 0, 0, 1, 0, 0);
            break;
        case 22:
           *x = decimal_presentation(2000000001, 0, 0, 0, 0, 0);
           *y = decimal_presentation(2000000000, 0, 0, 1, 0, 0);
           *z = decimal_presentation(4000000001, 0, 0, 0, 0, 0);
            break;
        case 23:
           *x = decimal_presentation(1000, 0, 0, 0, 0, 0);
           *y = decimal_presentation(2000, 0, 0, 0, 0, 0);
           *z = decimal_presentation(1000, 0, 0, 1, 0, 0);
            break;
        case 24:
           *x = decimal_presentation(1000, 0, 0, 1, 0, 0);
           *y = decimal_presentation(2000, 0, 0, 0, 0, 0);
           *z = decimal_presentation(3000, 0, 0, 1, 0, 0);
            break;
        case 25:
           *x = decimal_presentation(1000, 0, 0, 0, 0, 0);
           *y = decimal_presentation(2000, 0, 0, 1, 0, 0);
           *z = decimal_presentation(3000, 0, 0, 0, 0, 0);
            break;
        case 26:
           *x = decimal_presentation(10, 0, 0, 0, 0, 0);
           *y = decimal_presentation(1, 0, 0, 0, 1, 0);
           *z = decimal_presentation(99, 0, 0, 0, 1, 0);
            break;
        case 27:
           *x = decimal_presentation(105, 0, 0, 0, 1, 0);
           *y = decimal_presentation(10, 0, 0, 0, 0, 0);
           *z = decimal_presentation(5, 0, 0, 0, 1, 0);
            break;
        case 28:
           *x = decimal_presentation(1, 0, 0, 0, 0, 0);
           *y = decimal_presentation(1, 0, 0, 0, 9, 0);
           *z = decimal_presentation(999999999, 0, 0, 0, 9, 0);
            break;
        case 29:
           *x = decimal_presentation(1, 0, 0, 0, 9, 0);
           *y = decimal_presentation(1, 0, 0, 0, 0, 0);
           *z = decimal_presentation(999999999, 0, 0, 1, 9, 0);
            break;
        case 30:
           *x = decimal_presentation(1, 0, 0, 1, 0, 0);
           *y = decimal_presentation(1, 0, 0, 0, 9, 0);
           *z = decimal_presentation(1000000001, 0, 0, 1, 9, 0);
            break;
        case 31:
           *x = decimal_presentation(1, 0, 0, 1, 0, 0);
           *y = decimal_presentation(1, 0, 0, 1, 9, 0);
           *z = decimal_presentation(999999999, 0, 0, 1, 9, 0);
            break;
        case 32:
           *x = decimal_presentation(1000000, 0, 0, 0, 28, 0);
           *y = decimal_presentation(1000, 0, 0, 0, 25, 0);
           *z = decimal_presentation(0, 0, 0, 0, 0, 0);
            break;
        case 33:
           *x = decimal_presentation(1, 0, 0, 1, 9, 0);
           *y = decimal_presentation(1, 0, 0, 1, 0, 0);
           *z = decimal_presentation(999999999, 0, 0, 0, 9, 0);
            break;
        case 34:
           *x = decimal_presentation(0xffffffff, 0xffffffff, 0xffffffff, 0, 0, 0);
           *y = decimal_presentation(1, 0, 0, 0, 1, 0);
           *z = decimal_presentation(0xffffffff, 0xffffffff, 0xffffffff, 0, 0, 0);
            break;
        case 35:
           *x = decimal_presentation(4294967295, 4294967295, 4294967295, 0, 0, 0);
           *y = decimal_presentation(499, 0, 0, 0, 3, 0);
           *z = decimal_presentation(4294967295, 4294967295, 4294967295, 0, 0, 0);
            break;
        case 36:
           *x = decimal_presentation(4294967295, 4294967295, 4294967295, 0, 0, 0);
           *y = decimal_presentation(1499, 0, 0, 0, 3, 0);
           *z = decimal_presentation(4294967294, 4294967295, 4294967295, 0, 0, 0);
            break;
        case 37:
           *x = decimal_presentation(4294967295, 4294967295, 4294967295, 0, 0, 0);
           *y = decimal_presentation(1599, 0, 0, 0, 3, 0);
           *z = decimal_presentation(4294967293, 4294967295, 4294967295, 0, 0, 0);
            break;
        case 38:
           *x = decimal_presentation(4294967295, 4294967295, 4294967295, 0, 0, 0);
           *y = decimal_presentation(599, 0, 0, 0, 3, 0);
           *z = decimal_presentation(4294967294, 4294967295, 4294967295, 0, 0, 0);
            break;
        case 39:
           *x = decimal_presentation(4294967295, 4294967295, 4294967295, 0, 0, 0);
           *y = decimal_presentation(5, 0, 0, 0, 1, 0);
           *z = decimal_presentation(4294967294, 4294967295, 4294967295, 0, 0, 0);
            break;
        case 40:
           *x = decimal_presentation(4294967295, 4294967295, 4294967295, 0, 0, 0);
           *y = decimal_presentation(9111, 0, 0, 0, 4, 0);
           *z = decimal_presentation(4294967294, 4294967295, 4294967295, 0, 0, 0);
            break;
        case 41:
           *x = decimal_presentation(0, 0, 0, 1, 0, 0);
           *y = decimal_presentation(0, 0, 0, 0, 0, 0);
           *z = decimal_presentation(0, 0, 0, 0, 0, 0);
            break;
        case 42:
           *x = decimal_presentation(0, 0, 0, 0, 0, 0);
           *y = decimal_presentation(0, 0, 0, 1, 0, 0);
           *z = decimal_presentation(0, 0, 0, 1, 0, 0);
            break;
        case 43:
           *x = decimal_presentation(0, 0, 0, 0, 0, 3);
           *y = decimal_presentation(0, 0, 0, 0, 0, 0);
           *z = decimal_presentation(0, 0, 0, 0, 0, 3);
            break;

        default:
           *x = decimal_presentation(1000000, 0, 0, 0, 0, 0);
           *y = decimal_presentation(1, 0, 0, 0, 2, 0);
           *z = decimal_presentation(99999999, 0, 0, 0, 2, 0);
            counter = 0;
    }
    return counter;
}

int set_for_mul(int count_number, s21_decimal *x, s21_decimal *y, s21_decimal *z) {
    int counter = count_number;
    s21_decimal temp_number = {0};
    switch (count_number) {
        case 1:
            *x = decimal_presentation(0, 0, 0, 0, 0, 1);
            *y = decimal_presentation(0, 0, 0, 0, 0, 1);
            *z = decimal_presentation(0, 0, 0, 0, 0, 1);
            break;
        case 2:
            *x = decimal_presentation(0, 0, 0, 0, 0, 1);
            *y = decimal_presentation(0, 0, 0, 0, 0, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 3);
            break;
        case 3:
            *x = decimal_presentation(0, 0, 0, 0, 0, 2);
            *y = decimal_presentation(0, 0, 0, 0, 0, 3);
            *z = decimal_presentation(0, 0, 0, 0, 0, 3);
            break;
        case 4:
            *x = decimal_presentation(0, 0, 0, 0, 0, 1);
            *y = decimal_presentation(0, 0, 0, 0, 0, 3);
            *z = decimal_presentation(0, 0, 0, 0, 0, 3);
            break;
        case 5:
            *x = decimal_presentation(0, 0, 0, 0, 0, 1);
            *y = decimal_presentation(0, 0, 0, 0, 0, 2);
            *z = decimal_presentation(0, 0, 0, 0, 0, 3);
            break;
        case 6:
            *x = decimal_presentation(0, 0, 0, 0, 0, 2);
            *y = decimal_presentation(0, 0, 0, 0, 0, 2);
            *z = decimal_presentation(0, 0, 0, 0, 0, 1);
            break;
        case 7:
            *x = decimal_presentation(0, 0, 0, 0, 0, 0);
            *y = decimal_presentation(0, 0, 0, 0, 0, 2);
            *z = decimal_presentation(0, 0, 0, 0, 0, 3);
            break;
        case 8:
            *x = decimal_presentation(0, 0, 0, 0, 0, 3);
            *y = decimal_presentation(333, 0, 444, 0, 0, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 3);
            break;
        case 9:
            *x = decimal_presentation(0, 0, 0, 0, 0, 0);
            *y = decimal_presentation(0, 0, 0, 1, 0, 0);
            *z = decimal_presentation(0, 0, 0, 1, 0, 0);
            break;
        case 10:
           *x = decimal_presentation(0, 0, 0, 0, 0, 0);
           *y = decimal_presentation(777, 888, 999, 1, 0, 0);
           *z = decimal_presentation(0, 0, 0, 1, 0, 0);
            break;
        case 11:
           *x = decimal_presentation(0, 0, 0, 0, 0, 0);
           *y = decimal_presentation(1, 0, 0, 1, 0, 0);
           *z = decimal_presentation(0, 0, 0, 1, 0, 0);
            break;
        case 12:
           *x = decimal_presentation(2334, 3423, 12331, 0, 0, 0);
           *y = decimal_presentation(1, 0, 0, 1, 0, 0);
           *z = decimal_presentation(2334, 3423, 12331, 1, 0, 0);
            break;
        case 13:
           *x = decimal_presentation(2334, 3423, 0, 1, 0, 0);
           *y = decimal_presentation(5, 0, 0, 1, 0, 0);
           *z = decimal_presentation(11670, 17115, 0, 0, 0, 0);
            break;
        case 14:
           *x = decimal_presentation(4294967295, 4294967295, 4294967295, 0, 0, 0);
           *y = decimal_presentation(1, 0, 0, 0, 0, 0);
           *z = decimal_presentation(4294967295, 4294967295, 4294967295, 0, 0, 0);
            break;
        case 15:
           *x = decimal_presentation(4294967295, 0, 0, 0, 0, 0);
           *y = decimal_presentation(2, 1, 1, 0, 0, 0);
           *z = decimal_presentation(0, 0, 0, 0, 0, 1);
            break;
        case 16:
            *x = decimal_presentation(4294967295, 0, 0, 1, 0, 0);
            *y = decimal_presentation(2, 1, 1, 0, 0, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 2);
            break;
        case 17:
            *x = decimal_presentation(1, 0, 0, 0, 1, 0);
            *y = decimal_presentation(0, 0, 1, 0, 0, 0);
            *z = decimal_presentation(0, 0, 1, 0, 1, 0);
            break;
        case 18:
            *x = decimal_presentation(0, 0, 1, 1, 28, 0);
            *y = decimal_presentation(1, 0, 0, 0, 0, 0);
            *z = decimal_presentation(0, 0, 1, 1, 28, 0);
            break;
        case 19:
            *x = decimal_presentation(121, 0, 0, 0, 0, 0);
            *y = decimal_presentation(33, 0, 0, 0, 0, 0);
            *z = decimal_presentation(3993, 0, 0, 0, 0, 0);
            break;
        case 20:
            *x = decimal_presentation(33, 0, 0, 0, 0, 0);
            *y = decimal_presentation(121, 0, 0, 0, 0, 0);
            *z = decimal_presentation(3993, 0, 0, 0, 0, 0);
            break;
        case 21:
            *x = decimal_presentation(33, 0, 0, 1, 0, 0);
            *y = decimal_presentation(121, 0, 0, 0, 0, 0);
            *z = decimal_presentation(3993, 0, 0, 1, 0, 0);
            break;
        case 22:
            *x = decimal_presentation(33, 0, 0, 0, 0, 0);
            *y = decimal_presentation(121, 0, 0, 1, 0, 0);
            *z = decimal_presentation(3993, 0, 0, 1, 0, 0);
            break;
        case 23:
            *x = decimal_presentation(33, 0, 0, 1, 0, 0);
            *y = decimal_presentation(121, 0, 0, 1, 0, 0);
            *z = decimal_presentation(3993, 0, 0, 0, 0, 0);
            break;
        case 24:
            *x = decimal_presentation(33, 0, 0, 0, 1, 0);
            *y = decimal_presentation(121, 0, 0, 0, 1, 0);
            *z = decimal_presentation(3993, 0, 0, 0, 2, 0);
            break;
        case 25:
            *x = decimal_presentation(979, 0, 0, 0, 0, 0);
            *y = decimal_presentation(98, 0, 0, 0, 0, 0);
            *z = decimal_presentation(95942, 0, 0, 0, 0, 0);
            break;
        case 26:
            *x = decimal_presentation(98, 0, 0, 0, 0, 0);
            *y = decimal_presentation(979, 0, 0, 0, 0, 0);
            *z = decimal_presentation(95942, 0, 0, 0, 0, 0);
            break;
        case 27:
            *x = decimal_presentation(98, 0, 0, 1, 0, 0);
            *y = decimal_presentation(979, 0, 0, 0, 0, 0);
            *z = decimal_presentation(95942, 0, 0, 1, 0, 0);
            break;
        case 28:
            *x = decimal_presentation(98, 0, 0, 0, 0, 0);
            *y = decimal_presentation(979, 0, 0, 1, 0, 0);
            *z = decimal_presentation(95942, 0, 0, 1, 0, 0);
            break;
        case 29:
            *x = decimal_presentation(98, 0, 0, 1, 0, 0);
            *y = decimal_presentation(979, 0, 0, 1, 0, 0);
            *z = decimal_presentation(95942, 0, 0, 0, 0, 0);
            break;
        case 30:
            *x = decimal_presentation(98, 0, 0, 0, 1, 0);
            *y = decimal_presentation(979, 0, 0, 0, 1, 0);
            *z = decimal_presentation(95942, 0, 0, 0, 2, 0);
            break;
        case 31:
            *x = decimal_presentation(1, 0, 0, 0, 28, 0);
            *y = decimal_presentation(1, 0, 0, 1, 1, 0);
            *z = decimal_presentation(0, 0, 0, 1, 0, 0);
            break;
        case 32:
            *x = decimal_presentation(4294967295, 0, 0, 0, 28, 0);
            *y = decimal_presentation(1, 1, 1, 0, 20, 0);
            *z = decimal_presentation(792281625, 0, 0, 0, 28, 0);
            break;
        case 33:
            *x = decimal_presentation(1000000, 0, 0, 0, 28, 0);
            *y = decimal_presentation(1000000, 0, 0, 0, 12, 0);
            *z = decimal_presentation(1, 0, 0, 0, 28, 0);
            break;
        case 34:
            *x = decimal_presentation(4294967295, 4294967295, 4294967295, 1, 28, 0);
            // check is required!!!
            *y = decimal_presentation(4294967295, 4294967295, 4294967295, 1, 28, 0);
            *z = decimal_presentation(158262358, 899300158, 3402823669, 0, 27, 0);
        // bits[0] = 158262359 if use old round function in convert function
            break;
        case 35:
            *x = decimal_presentation(2000000, 0, 0, 0, 0, 0);
            *y = decimal_presentation(10, 0, 0, 0, 1, 0);
            *z = decimal_presentation(2000000, 0, 0, 0, 0, 0);
            break;
        case 36:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0, 0);
            break;
        case 37:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(0, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0, 3);
            break;
        case 38:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 1);
            *z = create_decimal(0, 0, 0, 0, 3);
            break;
        case 39:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(0, 0, 0, 0, 1);
            *z = create_decimal(0, 0, 0, 0, 1);
            break;
        case 40:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(0, 0, 0, 0, 2);
            *z = create_decimal(0, 0, 0, 0, 3);     // another var is value-type = 2 ???
            break;
        case 41:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 1);
            *z = create_decimal(0, 0, 0, 0, 3);     // another var is value-type = 2 ???
            break;
        case 42:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 2);
            *z = create_decimal(0, 0, 0, 0, 1);
            break;
        case 43:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 2);
            *z = create_decimal(0, 0, 0, 0, 3);
            break;
        case 44:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0, 3);
            break;
        case 45:
            *x = create_decimal(0, 0, 0, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(0, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 46:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 47:
            *x = create_decimal(7, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0, 0);
            break;
        case 48:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(7, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0, 0);
            break;
        case 49:
            *x = create_decimal(7, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 50:
            *x = create_decimal(0, 0, 0, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(7, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 51:
            *x = create_decimal(7, 0, 0, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(0, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 52:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(7, 0, 0, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 53:
            *x = create_decimal(0, 0, 0xffffffff, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0x00000000, 0);
            break;
        case 54:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0xffffffff, 0, 0);
            *z = create_decimal(0, 0, 0, 0, 0);
            break;
        case 55:
            *x = create_decimal(0, 0, 0xffffffff, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 56:
            *x = create_decimal(0, 0, 0, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(0, 0, 0xffffffff, 0, 0);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 57:
            *x = create_decimal(0, 0, 0xffffffff, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(0, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 58:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0xffffffff, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 59:
            *x = create_decimal(0, 0, 0xffffffff, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(0, 0, 0, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 60:
            *x = create_decimal(0, 0, 0, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(0, 0, 0xffffffff, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 61:
            *x = create_decimal(0xffffffff, 0, 0, 0, 0);
            *y = create_decimal(1, 1, 1, 0, 0);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            break;
        case 62:
            *x = create_decimal(1, 1, 1, 0, 0);
            *y = create_decimal(0xffffffff, 0, 0, 0, 0);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            break;
        case 63:
            *x = create_decimal(0xffffffff, 0, 0, 0, 0);
            *y = create_decimal(1, 1, 1, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            break;
        case 64:
            *x = create_decimal(1, 1, 1, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(0xffffffff, 0, 0, 0, 0);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            break;
        case 65:
            *x = create_decimal(0xffffffff, 0, 0, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(1, 1, 1, 0, 0);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            break;
        case 66:
            *x = create_decimal(1, 1, 1, 0, 0);
            *y = create_decimal(0xffffffff, 0, 0, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            break;
        case 67:
            *x = create_decimal(0xffffffff, 0, 0, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(1, 1, 1, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            break;
        case 68:
            *x = create_decimal(1, 1, 1, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(0xffffffff, 0, 0, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            break;
        case 69:
            *x = create_decimal(0xffffffff, 0, 0, 0, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *z = create_decimal(0, 0, 0, 0x00000000, 1);
            break;
        case 70:
            *x = create_decimal(0xffffffff, 0, 0, 0, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0, 0, 0, 0x00000000, 2);
            break;
        case 71:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *x = s21_negate(*x);
            *y = create_decimal(0xffffffff, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0x00000000, 2);
            break;
        case 72:
            *x = create_decimal(0xffffffff, 0, 0, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0, 0, 0, 0x00000000, 1);
            break;
        case 73:
            *x = create_decimal(99, 0, 0, 0, 0);
            *y = create_decimal(1, 0, 0, 0, 0);
            *z = create_decimal(99, 0, 0, 0x00000000, 0);
            break;
        case 74:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(99, 0, 0, 0, 0);
            *z = create_decimal(99, 0, 0, 0x00000000, 0);
            break;
        case 75:
            *x = create_decimal(99, 0, 0, 0x80000000, 0);
            *y = create_decimal(1, 0, 0, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(99, 0, 0, 0x00000000, 0);
            break;
        case 76:
            *x = create_decimal(99, 0, 0, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(1, 0, 0, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(99, 0, 0, 0x00000000, 0);
            break;
        case 77:
            *x = create_decimal(1, 0, 0, 2 << 16, 0);
            *y = create_decimal(99, 0, 0, 0, 0);
            *z = create_decimal(99, 0, 0, 0x00020000, 0);
            break;
        case 78:
            *x = create_decimal(99, 0, 0, 0, 0);
            *y = create_decimal(1, 0, 0, 2 << 16, 0);
            *z = create_decimal(99, 0, 0, 0x00020000, 0);
            break;
        case 79:
            *x = create_decimal(55, 0, 0, 0, 0);
            *y = create_decimal(4, 0, 0, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(220, 0, 0, 0x80000000, 0);
            break;
        case 80:
            *x = create_decimal(1, 0, 0, 25 << 16, 0);
            *y = create_decimal(1, 0, 0, 3 << 16, 0);
            *y = s21_negate(*y);
            *z = create_decimal(1, 0, 0, 0x801c0000, 0);
            break;
        case 81:
            *x = create_decimal(1, 0, 0, 25 << 16, 0);
            *y = create_decimal(1, 0, 0, 4 << 16, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 82:
            *x = create_decimal(1, 0, 0, 25 << 16, 0);
            *y = create_decimal(1, 0, 0, 4 << 16, 0);
            *z = create_decimal(0, 0, 0, 0x00000000, 0);
            break;
        case 83:
            *x = create_decimal(0, 0, 79229000, 0, 0);
            *y = create_decimal(10000000, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0x00000000, 1);
            break;
        case 84:
            *x = create_decimal(0, 0, 79229000, 0, 0);
            *x = s21_negate(*x);
            *y = create_decimal(10000000, 0, 0, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0, 0, 0, 0x00000000, 1);
            break;
        default:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0, 0);
            counter = 0;
    }
    return counter;
}




int set_for_div(int count_number, s21_decimal *x, s21_decimal *y, s21_decimal *z) {
    int counter = count_number;
    s21_decimal temp_number = {0};
    switch (count_number) {
        case 1:
            *x = decimal_presentation(0, 0, 0, 0, 0, 0);
            *y = decimal_presentation(0, 0, 0, 0, 0, 2);
            *z = decimal_presentation(0, 0, 0, 1, 0, 0);
            break;
        case 2:
            *x = decimal_presentation(0, 0, 0, 0, 0, 0);
            *y = decimal_presentation(0, 0, 0, 0, 0, 1);
            *z = decimal_presentation(0, 0, 0, 0, 0, 0);
            break;
        case 3:
            *x = decimal_presentation(0, 0, 0, 0, 0, 2);
            *y = decimal_presentation(0, 0, 0, 0, 0, 2);
            *z = decimal_presentation(0, 0, 0, 0, 0, 3);
            break;
        case 4:
            *x = decimal_presentation(0, 0, 0, 0, 0, 3);
            *y = decimal_presentation(0, 0, 0, 0, 0, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 3);
            break;
        case 5:
            *x = decimal_presentation(0, 0, 0, 0, 0, 0);
            *y = decimal_presentation(0, 0, 0, 0, 0, 3);
            *z = decimal_presentation(0, 0, 0, 0, 0, 3);
            break;
        case 6:
            *x = decimal_presentation(0, 0, 0, 0, 0, 1);
            *y = decimal_presentation(0, 0, 0, 0, 0, 2);
            *z = decimal_presentation(0, 0, 0, 0, 0, 3);
            break;
        case 7:
            *x = decimal_presentation(0, 0, 0, 0, 0, 0);
            *y = decimal_presentation(0, 0, 0, 0, 0, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 1);
            break;
        case 8:
            *x = decimal_presentation(1, 12, 1, 0, 0, 0);
            *y = decimal_presentation(0, 0, 0, 1, 0, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 2);
            break;
        case 9:
            *x = decimal_presentation(1, 2, 1, 1, 0, 0);
            *y = decimal_presentation(0, 0, 0, 1, 0, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 1);
            break;
        case 10:
            *x = decimal_presentation(1, 2, 1, 1, 0, 0);
            *y = decimal_presentation(0, 0, 0, 0, 0, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 2);
            break;
        case 11:
            *x = decimal_presentation(0, 0, 0, 0, 0, 0);
            *y = decimal_presentation(56278, 234279, 232356, 1, 0, 0);
            *z = decimal_presentation(0, 0, 0, 1, 0, 0);
            break;
        case 12:
            *x = decimal_presentation(0, 0, 0, 0, 0, 2);
            *y = decimal_presentation(1, 0, 0, 1, 0, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 1);
            break;
        case 13:
            *x = decimal_presentation(4294967295, 4294967295, 4294967295, 1, 0, 0);
            *y = decimal_presentation(4294967295, 0, 0, 0, 0, 0);
            *z = decimal_presentation(1, 1, 1, 1, 0, 0);
            break;
        case 14:
            *x = decimal_presentation(4294967295, 4294967295, 4294967295, 0, 0, 0);
            *y = decimal_presentation(4294967295, 4294967295, 4294967295, 1, 0, 0);
            *z = decimal_presentation(1, 0, 0, 1, 0, 0);
            break;
        case 15:
            *x = decimal_presentation(1, 0, 0, 0, 0, 0);
            *y = decimal_presentation(1, 0, 0, 0, 6, 0);
            *z = decimal_presentation(1000000, 0, 0, 0, 0, 0);
            break;
        case 16:
            *x = decimal_presentation(0, 1, 0, 0, 0, 0);
            *y = decimal_presentation(2, 0, 0, 1, 0, 0);
            *z = decimal_presentation(2147483648, 0, 0, 1, 0, 0);
            break;
        case 17:
            *x = decimal_presentation(1, 0, 0, 0, 0, 0);
            *y = decimal_presentation(4294967295, 4294967295, 4294967295, 0, 0, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 0);
            break;
        case 18:
            *x = decimal_presentation(1, 0, 0, 0, 1, 0);
            *y = decimal_presentation(1, 0, 0, 0, 0, 0);
            *z = decimal_presentation(1, 0, 0, 0, 1, 0);
            break;
        case 19:
            *x = decimal_presentation(1, 0, 0, 0, 28, 0);
            *y = decimal_presentation(1, 0, 0, 0, 1, 0);
            *z = decimal_presentation(1, 0, 0, 0, 27, 0);
            break;
        case 20:
            *x = decimal_presentation(1000, 0, 0, 0, 0, 0);
            *y = decimal_presentation(1, 0, 0, 0, 3, 0);
            *z = decimal_presentation(1000000, 0, 0, 0, 0, 0);
            break;
        case 21:
            *x = decimal_presentation(1000000, 0, 0, 0, 28, 0);
            *y = decimal_presentation(1000000, 0, 0, 0, 28, 0);
            *z = decimal_presentation(1, 0, 0, 0, 0, 0);
            break;
        case 22:
            *x = decimal_presentation(4294967294, 4294967295, 4294967295, 1, 0, 0);
            *y = decimal_presentation(4294967295, 4294967295, 2147483647, 1, 0, 0);
            *z = decimal_presentation(2, 0, 0, 0, 0, 0);
            break;
        case 23:
            *x = decimal_presentation(4294967294, 4294967295, 4294967295, 1, 28, 0);
            *y = decimal_presentation(4294967295, 4294967295, 2147483647, 0, 28, 0);
            *z = decimal_presentation(2, 0, 0, 1, 0, 0);
            break;
        case 24:
            *x = decimal_presentation(1, 0, 0, 0, 0, 0);
            *y = decimal_presentation(125, 0, 0, 0, 3, 0);
            *z = decimal_presentation(8, 0, 0, 0, 0, 0);
            break;
        case 25:
            *x = decimal_presentation(1, 0, 4294967295, 0, 0, 0);
            *y = decimal_presentation(125, 0, 0, 0, 28, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 1);
            break;
        case 26:
            *x = decimal_presentation(10, 0, 0, 0, 28, 0);
            *y = decimal_presentation(0, 0, 4294967295, 0, 0, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 0);
            break;
        case 27:
            *x = decimal_presentation(10, 0, 0, 0, 0, 0);
            *y = decimal_presentation(11, 0, 0, 0, 0, 0);
            *z = decimal_presentation(2586741667, 1338281420, 492819169, 0, 28,
                                0);  // 0.90909...091
            break;
        case 28:
            *x = decimal_presentation(5, 0, 0, 0, 0, 0);
            *y = decimal_presentation(3, 0, 0, 0, 0, 0);
            *z = decimal_presentation(447392427, 1737688055, 903501810, 0, 28, 0);
            break;
        case 29:
            *x = decimal_presentation(4294967288, 4294967295, 536870911, 0, 0, 0);
            *y = decimal_presentation(1, 0, 0, 0, 1, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 1);
            break;
        case 30:
            *x = create_decimal(1, 0, 0, 26 << 16, 0);
            *y = create_decimal(10, 0, 0, 0, 0);
            *z = create_decimal(1, 0, 0, 27 << 16, 0);
            break;
        case 31:
            *x = create_decimal(1, 0, 0, 27 << 16, 0);
            *y = create_decimal(10, 0, 0, 0, 0);
            *z = create_decimal(1, 0, 0, 28 << 16, 0);
            break;
        case 32:
            *x = create_decimal(1, 0, 0, 27 << 16, 0);
            *x = s21_negate(*x);
            *y = create_decimal(10, 0, 0, 0, 0);
            *z = create_decimal(1, 0, 0, 0x801c0000, 0);
            break;
        case 33:
            *x = create_decimal(1, 0, 0, 27 << 16, 0);
            *y = create_decimal(10, 0, 0, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(1, 0, 0, 0x801c0000, 0);
            break;
        case 34:
            *x = create_decimal(1, 0, 0, 28 << 16, 0);
            *y = create_decimal(10, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0, 0);
            break;
        case 35:
            *x = create_decimal(1, 0, 0, 28 << 16, 0);
            *x = s21_negate(*x);
            *y = create_decimal(10, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 36:
            *x = create_decimal(1, 0, 0, 28 << 16, 0);
            *y = create_decimal(10, 0, 0, 0, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 37:
            *x = create_decimal(1, 0, 0, 28 << 16, 0);
            *y = create_decimal(10000, 0, 0, 3 << 16, 0);
            *z = create_decimal(0, 0, 0, 0, 0);
            break;
        case 38:
            *x = create_decimal(1, 0, 0, 28 << 16, 0);
            *x = s21_negate(*x);
            *y = create_decimal(10000, 0, 0, 3 << 16, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0, 0, 0, 0, 0);
            break;
        case 39:
            *x = create_decimal(1, 0, 0, 28 << 16, 0);
            *x = s21_negate(*x);
            *y = create_decimal(10000, 0, 0, 3 << 16, 0);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 40:
            *x = create_decimal(1, 0, 0, 28 << 16, 0);
            *x = s21_negate(*x);
            *y = create_decimal(10000, 0, 0, 3 << 16, 0);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 41:
            *x = create_decimal(1, 0, 0, 27 << 16, 0);
            *y = create_decimal(10000, 0, 0, 3 << 16, 0);
            *z = create_decimal(1, 0, 0, 28 << 16, 0);
            break;
        case 42:
            *x = create_decimal(1, 0, 0, 27 << 16, 0);
            *x = s21_negate(*x);
            *y = create_decimal(10000, 0, 0, 3 << 16, 0);
            *y = s21_negate(*y);
            *z = create_decimal(1, 0, 0, 28 << 16, 0);
            break;
        case 43:
            *x = create_decimal(1, 0, 0, 27 << 16, 0);
            *x = s21_negate(*x);
            *y = create_decimal(10000, 0, 0, 3 << 16, 0);
            *z = create_decimal(1, 0, 0, 0x801c0000, 0);
            break;
        case 44:
            *x = create_decimal(1, 0, 0, 27 << 16, 0);
            *y = create_decimal(10000, 0, 0, 3 << 16, 0);
            *y = s21_negate(*y);
            *z = create_decimal(1, 0, 0, 0x801c0000, 0);
            break;
        case 45:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 28 << 16, 0);
            *y = create_decimal(1, 0, 0, 28 << 16, 0);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            break;
        case 46:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 28 << 16, 0);
            *x = s21_negate(*x);
            *y = create_decimal(1, 0, 0, 28 << 16, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            break;
        case 47:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 28 << 16, 0);
            *x = s21_negate(*x);
            *y = create_decimal(1, 0, 0, 28 << 16, 0);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            break;
        case 48:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 28 << 16, 0);
            *y = create_decimal(1, 0, 0, 28 << 16, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            break;
        case 49:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 27 << 16, 0);
            *y = create_decimal(1, 0, 0, 28 << 16, 0);
            *z = create_decimal(0, 0, 0, 0, 1);
            break;
        case 50:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 27 << 16, 0);
            *x = s21_negate(*x);
            *y = create_decimal(1, 0, 0, 28 << 16, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0, 0, 0, 0, 1);
            break;
        case 51:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 27 << 16, 0);
            *x = s21_negate(*x);
            *y = create_decimal(1, 0, 0, 28 << 16, 0);
            *z = create_decimal(0, 0, 0, 0x80000000, 2);
            break;
        case 52:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 27 << 16, 0);
            *y = create_decimal(1, 0, 0, 28 << 16, 0);
            *y = s21_negate(*y);
            *z = create_decimal(0, 0, 0, 0x80000000, 2);
            break;
        case 53:
            *x = create_decimal(2137863392, 0, 0, 0, 0);
            *y = create_decimal(32518, 0, 0, 0, 0);
            *z = create_decimal(65744, 0, 0, 0, 0);
            break;

        default:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0, 1);
            counter = 0;
    }
    return counter;
}

int set_for_float(int counter, float *test_number) {
    switch (counter) {
        case 1:
            *test_number = 1.0;
            break;
        case 2:
            *test_number = -1.0;
            break;
        case 3:
            *test_number = 1.0e-28;
            break;
        case 4:
            *test_number = -1.0e-28;
            break;
        case 5:
            *test_number = 1.0e28;
            break;
        case 6:
            *test_number = -1.0e28;
            break;
        case 7:
            *test_number = -1.0/0.0;
            break;
        case 8:
            *test_number = 1.0/0.0;
            break;
        case 9:
            *test_number = 123456;
            break;
        case 10:
            *test_number = 1234567;
            break;
        case 11:
            *test_number = -3E+10;
            break;
        case 12:
            *test_number = -1093.54;
            break;
        case 13:
            *test_number = -1093.54;
            break;
        case 14:
            *test_number = -0.1919192;
            break;
        case 15:
            *test_number = 100500;
            break;
        case 16:
            *test_number = -1E-11;
            break;
        case 17:
            *test_number = 10;
            break;
        case 18:
            *test_number = 2.000005;
            break;
        case 19:
            *test_number = 0.1234567;
            break;
        case 20:
            *test_number = 1.234568;
            break;
        default:
            *test_number = - NAN;
            counter = -1;
    }
    return counter;
}

int set_for_int(int counter, int *test_number) {
    switch (counter) {
        case 1:
            *test_number = 1.0;
            break;
        case 2:
            *test_number = -1.0;
            break;
        case 3:
            *test_number = 1.0;
            break;
        case 4:
            *test_number = -1.0;
            break;
        case 5:
            *test_number = 1.0;
            break;
        case 6:
            *test_number = -1.0;
            break;
        case 7:
            *test_number = -1.0;
            break;
        case 8:
            *test_number = 1.0;
            break;
        case 9:
            *test_number = 123456;
            break;
        case 10:
            *test_number = 1234567;
            break;
        case 11:
            *test_number = 12345678;
            break;
        case 12:
            *test_number = 123456789;
            break;
        case 13:
            *test_number = 123456789;
            break;
        case 14:
            *test_number = 1234567890;
            break;
        case 15:
            *test_number = 1234567890;
            break;
        case 16:
            *test_number = 23456789;
            break;
        case 17:
            *test_number = 345678901;
            break;
        case 18:
            *test_number = 456789012;
            break;
        case 19:
            *test_number = -345678901;
            break;
        case 20:
            *test_number = - 2147483648;
            break;
        default:
            *test_number = 0.0;
            counter = -1;
    }
    return counter;
}

int set_for_truncate(int count_number, s21_decimal *x, s21_decimal *z) {
    int counter = count_number;
    s21_decimal temp_number = {0};
    switch (count_number) {
        case 1:
            *x = create_decimal(0, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0, 0);
            break;
        case 2:
            *x = create_decimal(0, 0, 0, 0, 0);
            *x = s21_negate(*x);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 3:
            *x = create_decimal(0, 0, 0, 0, 1);
            *z = create_decimal(0, 0, 0, 0, 1);
            break;
        case 4:
            *x = create_decimal(0, 0, 0, 0, 2);
            *z = create_decimal(0, 0, 0, 0, 2);
            break;
        case 5:
            *x = create_decimal(0, 0, 0, 0, 3);
            *z = create_decimal(0, 0, 0, 0, 3);
            break;
        case 6:
            *x = create_decimal(7890, 0, 0, 0, 0);
            *z = create_decimal(7890, 0, 0, 0, 0);
            break;
        case 7:
            *x = create_decimal(7890, 0, 0, 0, 0);
            *x = s21_negate(*x);
            *z = create_decimal(7890, 0, 0, 0x80000000, 0);
            break;
        case 8:
            *x = create_decimal(7890, 0, 0, 1 << 16, 0);
            *z = create_decimal(789, 0, 0, 0, 0);
            break;
        case 9:
            *x = create_decimal(7890, 0, 0, 1 << 16, 0);
            *x = s21_negate(*x);
            *z = create_decimal(789, 0, 0, 0x80000000, 0);
            break;
        case 10:
            *x = create_decimal(7890, 0, 0, 2 << 16, 0);
            *z = create_decimal(78, 0, 0, 0, 0);
            break;
        case 11:
            *x = create_decimal(7890, 0, 0, 2 << 16, 0);
            *x = s21_negate(*x);
            *z = create_decimal(78, 0, 0, 0x80000000, 0);
            break;
        case 12:
            *x = create_decimal(7890, 0, 0, 3 << 16, 0);
            *z = create_decimal(7, 0, 0, 0, 0);
            break;
        case 13:
            *x = create_decimal(7890, 0, 0, 3 << 16, 0);
            *x = s21_negate(*x);
            *z = create_decimal(7, 0, 0, 0x80000000, 0);
            break;
        case 14:
            *x = create_decimal(7890, 0, 0, 4 << 16, 0);
            *z = create_decimal(0, 0, 0, 0, 0);
            break;
        case 15:
            *x = create_decimal(7890, 0, 0, 4 << 16, 0);
            *x = s21_negate(*x);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 16:
            *x = create_decimal(7890, 0, 0, 14 << 16, 0);
            *z = create_decimal(0, 0, 0, 0, 0);
            break;
        case 17:
            *x = create_decimal(7890, 0, 0, 14 << 16, 0);
            *x = s21_negate(*x);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 18:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            break;
        case 19:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *x = s21_negate(*x);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            break;
        default:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            counter = 0;
    }
    return counter;
}

int set_for_floor(int count_number, s21_decimal *x, s21_decimal *z) {
    int counter = count_number;
    s21_decimal temp_number = {0};
    switch (count_number) {
        case 1:
            *x = create_decimal(0, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0, 0);
            break;
        case 2:
            *x = create_decimal(0, 0, 0, 0, 0);
            *x = s21_negate(*x);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 3:
            *x = create_decimal(0, 0, 0, 0, 1);
            *z = create_decimal(0, 0, 0, 0, 1);
            break;
        case 4:
            *x = create_decimal(0, 0, 0, 0, 2);
            *z = create_decimal(0, 0, 0, 0, 2);
            break;
        case 5:
            *x = create_decimal(0, 0, 0, 0, 3);
            *z = create_decimal(0, 0, 0, 0, 3);
            break;
        case 6:
            *x = create_decimal(7890, 0, 0, 0, 0);
            *z = create_decimal(7890, 0, 0, 0, 0);
            break;
        case 7:
            *x = create_decimal(7890, 0, 0, 0, 0);
            *x = s21_negate(*x);
            *z = create_decimal(7890, 0, 0, 0x80000000, 0);
            break;
        case 8:
            *x = create_decimal(7890, 0, 0, 1 << 16, 0);
            *z = create_decimal(789, 0, 0, 0, 0);
            break;
        case 9:
            *x = create_decimal(7890, 0, 0, 1 << 16, 0);
            *x = s21_negate(*x);
            *z = create_decimal(789, 0, 0, 0x80000000, 0);
            break;
        case 10:
            *x = create_decimal(7890, 0, 0, 2 << 16, 0);
            *z = create_decimal(78, 0, 0, 0, 0);
            break;
        case 11:
            *x = create_decimal(7890, 0, 0, 2 << 16, 0);
            *x = s21_negate(*x);
            *z = create_decimal(79, 0, 0, 0x80000000, 0);
            break;
        case 12:
            *x = create_decimal(7890, 0, 0, 3 << 16, 0);
            *z = create_decimal(7, 0, 0, 0, 0);
            break;
        case 13:
            *x = create_decimal(7890, 0, 0, 3 << 16, 0);
            *x = s21_negate(*x);
            *z = create_decimal(8, 0, 0, 0x80000000, 0);
            break;
        case 14:
            *x = create_decimal(7890, 0, 0, 4 << 16, 0);
            *z = create_decimal(0, 0, 0, 0, 0);
            break;
        case 15:
            *x = create_decimal(7890, 0, 0, 4 << 16, 0);
            *x = s21_negate(*x);
            *z = create_decimal(1, 0, 0, 0x80000000, 0);
            break;
        case 16:
            *x = create_decimal(7890, 0, 0, 14 << 16, 0);
            *z = create_decimal(0, 0, 0, 0, 0);
            break;
        case 17:
            *x = create_decimal(7890, 0, 0, 14 << 16, 0);
            *x = s21_negate(*x);
            *z = create_decimal(1, 0, 0, 0x80000000, 0);
            break;
        case 18:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            break;
        case 19:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *x = s21_negate(*x);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            break;
        default:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            counter = 0;
    }
    return counter;
}

int set_for_round(int count_number, s21_decimal *x, s21_decimal *z) {
    int counter = count_number;
    s21_decimal temp_number = {0};
    switch (count_number) {
        case 1:
            *x = create_decimal(0, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0, 0);
            break;
        case 2:
            *x = create_decimal(0, 0, 0, 0, 0);
            *x = s21_negate(*x);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 3:
            *x = create_decimal(0, 0, 0, 0, 1);
            *z = create_decimal(0, 0, 0, 0, 1);
            break;
        case 4:
            *x = create_decimal(0, 0, 0, 0, 2);
            *z = create_decimal(0, 0, 0, 0, 2);
            break;
        case 5:
            *x = create_decimal(0, 0, 0, 0, 3);
            *z = create_decimal(0, 0, 0, 0, 3);
            break;
        case 6:
            *x = create_decimal(7890, 0, 0, 0, 0);
            *z = create_decimal(7890, 0, 0, 0, 0);
            break;
        case 7:
            *x = create_decimal(7890, 0, 0, 0, 0);
            *x = s21_negate(*x);
            *z = create_decimal(7890, 0, 0, 0x80000000, 0);
            break;
        case 8:
            *x = create_decimal(7890, 0, 0, 1 << 16, 0);
            *z = create_decimal(789, 0, 0, 0, 0);
            break;
        case 9:
            *x = create_decimal(7890, 0, 0, 1 << 16, 0);
            *x = s21_negate(*x);
            *z = create_decimal(789, 0, 0, 0x80000000, 0);
            break;
        case 10:
            *x = create_decimal(7890, 0, 0, 2 << 16, 0);
            *z = create_decimal(79, 0, 0, 0, 0);
            break;
        case 11:
            *x = create_decimal(7890, 0, 0, 2 << 16, 0);
            *x = s21_negate(*x);
            *z = create_decimal(79, 0, 0, 0x80000000, 0);
            break;
        case 12:
            *x = create_decimal(7890, 0, 0, 3 << 16, 0);
            *z = create_decimal(8, 0, 0, 0, 0);
            break;
        case 13:
            *x = create_decimal(7890, 0, 0, 3 << 16, 0);
            *x = s21_negate(*x);
            *z = create_decimal(8, 0, 0, 0x80000000, 0);
            break;
        case 14:
            *x = create_decimal(7890, 0, 0, 4 << 16, 0);
            *z = create_decimal(1, 0, 0, 0, 0);
            break;
        case 15:
            *x = create_decimal(7890, 0, 0, 4 << 16, 0);
            *x = s21_negate(*x);
            *z = create_decimal(1, 0, 0, 0x80000000, 0);
            break;
        case 16:
            *x = create_decimal(5, 0, 0, 1 << 16, 0);
            *z = create_decimal(1, 0, 0, 0, 0);
            break;
        case 17:
            *x = create_decimal(5, 0, 0, 1 << 16, 0);
            *x = s21_negate(*x);
            *z = create_decimal(1, 0, 0, 0x80000000, 0);
            break;
        case 18:
            *x = create_decimal(15, 0, 0, 1 << 16, 0);
            *z = create_decimal(2, 0, 0, 0, 0);
            break;
        case 19:
            *x = create_decimal(15, 0, 0, 0x80010000, 0);
            *z = create_decimal(2, 0, 0, 0x80000000, 0);
            break;
        case 20:
            *x = create_decimal(15555, 0, 0, 0x00040000, 0);
            *z = create_decimal(2, 0, 0, 0x00000000, 0);
            break;
        case 21:
            *x = create_decimal(15554, 0, 0, 0x00040000, 0);
            *z = create_decimal(2, 0, 0, 0x00000000, 0);
            break;
        case 22:
            *x = create_decimal(15556, 0, 0, 0x00040000, 0);
            *z = create_decimal(2, 0, 0, 0x00000000, 0);
            break;
        case 23:
            *x = create_decimal(15555, 0, 0, 0x80040000, 0);
            *z = create_decimal(2, 0, 0, 0x80000000, 0);
            break;
        case 24:
            *x = create_decimal(15554, 0, 0, 0x80040000, 0);
            *z = create_decimal(2, 0, 0, 0x80000000, 0);
            break;
        case 25:
            *x = create_decimal(14556, 0, 0, 0x80040000, 0);
            *z = create_decimal(2, 0, 0, 0x80000000, 0);
            // another variant is bits[0] = 1 (becouse of round  in bank style)
            break;
        case 26:
            *x = create_decimal(7890, 0, 0, 0x00140000, 0);
            *z = create_decimal(0, 0, 0, 0x00000000, 0);
            break;
        case 27:
            *x = create_decimal(7890, 0, 0, 0x00140000, 0);
            *x = s21_negate(*x);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 28:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            break;
        case 29:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *x = s21_negate(*x);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            break;

        default:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            counter = 0;
    }
    return counter;
}

int set_for_negate(int count_number, s21_decimal *x, s21_decimal *z) {
    int counter = count_number;
    switch (count_number) {
        case 1:
            *x = create_decimal(0, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0x80000000, 0);
            break;
        case 2:
            *x = create_decimal(0x87, 0, 0, 0x80010000, 0);
            *z = create_decimal(0x87, 0, 0, 1 << 16, 0);
            break;
        case 3:
            *x = create_decimal(0x87, 0, 0, 0x80010000, 0);
            *x = s21_negate(*x);
            *z = create_decimal(0x87, 0, 0, 0x80010000, 0);
            break;
        case 4:
            *x = create_decimal(0, 0, 0, 0, 1);
            *z = create_decimal(0, 0, 0, 0, 2);
            break;
        case 5:
            *x = create_decimal(0, 0, 0, 0, 2);
            *z = create_decimal(0, 0, 0, 0, 1);
            break;
        case 6:
            *x = create_decimal(0, 0, 0, 0, 3);
            *z = create_decimal(0, 0, 0, 0, 3);
            break;
        default:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *z = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            counter = 0;
    }
    return counter;
}

int set_for_mod(int count_number, s21_decimal *x, s21_decimal *y, s21_decimal *z) {
    int counter = count_number;
    s21_decimal temp_number = {0};
    switch (count_number) {
        case 1:
            *x = decimal_presentation(0, 0, 0, 0, 0, 1);
            *y = decimal_presentation(0, 0, 0, 0, 0, 2);
            *z = decimal_presentation(0, 0, 0, 0, 0, 3);
            break;
        case 2:
            *x = decimal_presentation(1, 0, 0, 0, 0, 0);
            *y = decimal_presentation(1, 0, 0, 0, 0, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 0);
            break;
        case 3:
            *x = decimal_presentation(1, 1, 1, 0, 0, 0);
            *y = decimal_presentation(1, 0, 0, 0, 0, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 0);
            break;
        case 4:
            *x = decimal_presentation(0, 1, 1, 0, 0, 0);
            *y = decimal_presentation(0, 0, 0, 0, 0, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 3);
            break;
        case 5:
            *x = decimal_presentation(0, 0, 0, 0, 0, 1);
            *y = decimal_presentation(2, 0, 0, 0, 0, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 1);
            break;
        case 6:
            *x = decimal_presentation(1, 1, 1, 0, 0, 0);
            *y = decimal_presentation(0, 0, 0, 0, 0, 1);
            *z = decimal_presentation(1, 1, 1, 0, 0, 0);
            break;
        case 7:
            *x = decimal_presentation(1, 1, 1, 0, 0, 0);
            *y = decimal_presentation(0, 0, 0, 0, 0, 2);
            *z = decimal_presentation(1, 1, 1, 0, 0, 0);
            break;
        case 8:
            *x = decimal_presentation(1, 1, 1, 0, 0, 0);
            *y = decimal_presentation(0, 0, 0, 0, 0, 3);
            *z = decimal_presentation(0, 0, 0, 0, 0, 3);
            break;
        case 9:
            *x = decimal_presentation(0, 0, 0, 0, 0, 2);
            *y = decimal_presentation(0, 0, 0, 0, 0, 1);
            *z = decimal_presentation(0, 0, 0, 0, 0, 3);
            break;
        case 10:
            *x = decimal_presentation(123123, 12311, 543453, 0, 0, 0);
            *y = decimal_presentation(0, 0, 0, 0, 0, 2);
            *z = decimal_presentation(123123, 12311, 543453, 0, 0, 0);
            break;
        case 11:
            *x = decimal_presentation(15, 0, 0, 0, 0, 0);
            *y = decimal_presentation(4, 0, 0, 0, 0, 0);
            *z = decimal_presentation(3, 0, 0, 0, 0, 0);
            break;
        case 12:
            *x = decimal_presentation(0, 0, 0, 0, 0, 1);
            *y = decimal_presentation(0, 0, 0, 0, 0, 2);
            *z = decimal_presentation(0, 0, 0, 0, 0, 3);
            break;
        case 13:
            *x = decimal_presentation(0, 0, 0, 0, 0, 2);
            *y = decimal_presentation(0, 0, 0, 0, 0, 2);
            *z = decimal_presentation(0, 0, 0, 0, 0, 3);
            break;
        case 14:
            *x = decimal_presentation(0, 0, 0, 0, 0, 0);
            *y = decimal_presentation(0, 0, 0, 0, 0, 2);
            *z = decimal_presentation(0, 0, 0, 0, 0, 0);
            break;
        case 15:
            *x = decimal_presentation(0, 0, 0, 0, 0, 3);
            *y = decimal_presentation(123, 0, 456, 0, 0, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 3);
            break;
        case 16:
            *x = decimal_presentation(0, 0, 0, 0, 0, 0);
            *y = decimal_presentation(0, 0, 0, 1, 0, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 3);
            break;
        case 17:
            *x = decimal_presentation(0, 0, 0, 0, 0, 0);
            *y = decimal_presentation(56278, 234279, 232356, 1, 0, 0);
            *z = decimal_presentation(0, 0, 0, 1, 0, 0);
            break;
        case 18:
            *x = decimal_presentation(0, 0, 0, 0, 0, 0);
            *y = decimal_presentation(1, 0, 0, 1, 0, 0);
            *z = decimal_presentation(0, 0, 0, 1, 0, 0);  // another var is bits[3] = 0 ????
            break;
        case 19:
            *x = decimal_presentation(2334, 3423, 12331, 0, 0, 0);
            *y = decimal_presentation(1, 0, 0, 1, 0, 0);
            *z = decimal_presentation(0, 0, 0, 1, 0, 0);
            break;
        case 20:
            *x = decimal_presentation(111, 0, 0, 0, 0, 0);
            *y = decimal_presentation(3, 0, 0, 0, 0, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 0);
            break;
        case 21:
            *x = decimal_presentation(4294967295, 0, 0, 0, 0, 0);
            *y = decimal_presentation(1, 1, 1, 0, 0, 0);
            *z = decimal_presentation(4294967295, 0, 0, 0, 0, 0);
            break;
        case 22:
            *x = decimal_presentation(0, 1, 0, 0, 0, 0);
            *y = decimal_presentation(4294967295, 0, 0, 0, 0, 0);
            *z = decimal_presentation(1, 0, 0, 0, 0, 0);
            break;
        case 23:
            *x = decimal_presentation(4294967295, 4294967295, 4294967295, 0, 0, 0);
            *y = decimal_presentation(4294967294, 4294967295, 4294967295, 0, 0, 0);
            *z = decimal_presentation(1, 0, 0, 0, 0, 0);
            break;
        case 24:
            *x = decimal_presentation(1, 0, 0, 0, 1, 0);
            *y = decimal_presentation(1, 0, 0, 0, 0, 0);
            *z = decimal_presentation(1, 0, 0, 0, 1, 0);
            break;
        case 25:
            *x = decimal_presentation(17, 0, 0, 1, 0, 0);
            *y = decimal_presentation(5, 0, 0, 0, 0, 0);
            *z = decimal_presentation(2, 0, 0, 1, 0, 0);
            break;
        case 26:
            *x = decimal_presentation(65, 0, 0, 1, 0, 0);
            *y = decimal_presentation(12, 0, 0, 1, 0, 0);
            *z = decimal_presentation(5, 0, 0, 1, 0, 0);
            break;
        case 27:
            *x = decimal_presentation(100, 0, 0, 0, 0, 0);
            *y = decimal_presentation(3, 0, 0, 1, 0, 0);
            *z = decimal_presentation(1, 0, 0, 0, 0, 0);
            break;
        case 28:
            *x = decimal_presentation(4294967295, 4294967295, 4294967295, 1, 0, 0);
            *y = decimal_presentation(4294967295, 4294967295, 4294967295, 1, 0, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 0);
            break;
        case 29:
            *x = decimal_presentation(2000000, 0, 0, 1, 0, 0);
            *y = decimal_presentation(11, 0, 0, 1, 0, 0);
            *z = decimal_presentation(2, 0, 0, 1, 0, 0);
            break;
        case 30:
            *x = decimal_presentation(175, 0, 0, 1, 1, 0);
            *y = decimal_presentation(5, 0, 0, 0, 0, 0);
            *z = decimal_presentation(25, 0, 0, 1, 1, 0);
            break;
        case 31:
            *x = decimal_presentation(225, 0, 0, 1, 2, 0);
            *y = decimal_presentation(5, 0, 0, 1, 0, 0);
            *z = decimal_presentation(225, 0, 0, 1, 2, 0);
            break;
        case 32:
            *x = decimal_presentation(1000567, 0, 0, 0, 3, 0);
            *y = decimal_presentation(9, 0, 0, 1, 0, 0);
            *z = decimal_presentation(1567, 0, 0, 0, 3, 0);
            break;
        case 33:
            *x = decimal_presentation(456, 0, 0, 1, 0, 0);
            *y = decimal_presentation(215, 0, 0, 1, 1, 0);
            *z = decimal_presentation(45, 0, 0, 1, 1, 0);
            break;
        case 34:
            *x = decimal_presentation(3199, 0, 0, 1, 2, 0);
            *y = decimal_presentation(8, 0, 0, 1, 0, 0);
            *z = decimal_presentation(799, 0, 0, 1, 2, 0);
            break;
        case 35:
            *x = decimal_presentation(3199, 0, 0, 0, 2, 0);
            *y = decimal_presentation(8, 0, 0, 1, 0, 0);
            *z = decimal_presentation(799, 0, 0, 0, 2, 0);
            break;
        case 36:
            *x = decimal_presentation(3199, 0, 0, 1, 2, 0);
            *y = decimal_presentation(8, 0, 0, 0, 0, 0);
            *z = decimal_presentation(799, 0, 0, 1, 2, 0);
            break;
        case 37:
            *x = decimal_presentation(33333, 0, 0, 1, 2, 0);
            *y = decimal_presentation(255, 0, 0, 0, 1, 0);
            *z = decimal_presentation(183, 0, 0, 1, 2, 0);
            break;
        case 38:
            *x = decimal_presentation(0xfffffffe, 0xffffffff, 0xffffffff, 0, 0, 0);
            *y = decimal_presentation(1, 0, 0, 0, 3, 0);
            *z = decimal_presentation(0, 0, 0, 0, 0, 0);
            break;
        default:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *z = create_decimal(0, 0, 0, 0, 3);
            counter = 0;
    }
    return counter;
}

int set_for_greater(int count_number, s21_decimal *x, s21_decimal *y, int *rezult) {
    int counter = count_number;
    switch (count_number) {
        case 1:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 2:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 3:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 4:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 0;
            break;
        case 5:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 6:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 7:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 8:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 9:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 10:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 11:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 1;
            break;
        case 12:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 13:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 1;
            break;
        case 14:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 15:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 0;
            break;
        case 16:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 17:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 18:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 19:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(1, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 20:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 0;
            break;
        case 21:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(1, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 22:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 23:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(1, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 24:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 25:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 26:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(1, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 27:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 0;
            break;
        case 28:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(1, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 29:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 30:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(1, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 31:
            *x = create_decimal(5, 0, 0, 0, 0);
            *y = create_decimal(5, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 32:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(5, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 33:
            *x = create_decimal(5, 0, 0, 0, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 34:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 35:
            *x = create_decimal(4, 0, 0, 0x80000000, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 36:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(4, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 37:
            *x = create_decimal(4, 0, 0, 0, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 38:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(4, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 39:
            *x = create_decimal(4, 0, 0, 0x80000000, 0);
            *y = create_decimal(5, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 40:
            *x = create_decimal(5, 0, 0, 0, 0);
            *y = create_decimal(4, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 41:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(4, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 42:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(4, 0, 0, 0x00000000, 0);
            *rezult = 1;
            break;
        case 43:
            *x = create_decimal(4, 0, 0, 0x00000000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 44:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 45:
            *x = create_decimal(4000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 46:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(4000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 47:
            *x = create_decimal(4000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 48:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(4000, 0, 0, 0x00030000, 0);
            *rezult = 1;
            break;
        case 49:
            *x = create_decimal(4000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x00030000, 0);
            *rezult = 1;
            break;
        case 50:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(4000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 51:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5000, 0, 0, 0x00030000, 0);
            *rezult = 1;
            break;
        case 52:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x00030000, 0);
            *rezult = 1;
            break;
        case 53:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 54:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 55:
            *x = create_decimal(4000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x00030000, 0);
            *rezult = 1;
            break;
        case 56:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(4000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 57:
            *x = create_decimal(4000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 58:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(4000, 0, 0, 0x00030000, 0);
            *rezult = 1;
            break;
        case 59:
            *x = create_decimal(4000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x00030000, 0);
            *rezult = 1;
            break;
        case 60:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(4000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 61:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *y = create_decimal(1, 0, 0, 0x001c0000, 0);
            *rezult = 0;
            break;
        case 62:
            *x = create_decimal(1, 0, 0, 0x001c0000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *rezult = 1;
            break;
        case 63:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *y = create_decimal(1, 0, 0, 0x001c0000, 0);
            *rezult = 1;
            break;
        case 64:
            *x = create_decimal(1, 0, 0, 0x001c0000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *rezult = 0;
            break;
        case 65:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *y = create_decimal(1, 0, 0, 0x801c0000, 0);
            *rezult = 1;
            break;
        case 66:
            *x = create_decimal(1, 0, 0, 0x801c0000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *rezult = 0;
            break;
        case 67:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *y = create_decimal(1, 0, 0, 0x801c0000, 0);
            *rezult = 0;
            break;
        case 68:
            *x = create_decimal(1, 0, 0, 0x801c0000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *rezult = 1;
            break;
        case 69:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *rezult = 1;
            break;
        case 70:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *rezult = 1;
            break;
        case 71:
            *x = create_decimal(1, 0, 0, 0x001c0000, 0);
            *y = create_decimal(1, 0, 0, 0x001c0000, 0);
            *rezult = 1;
            break;
        case 72:
            *x = create_decimal(1, 0, 0, 0x801c0000, 0);
            *y = create_decimal(1, 0, 0, 0x801c0000, 0);
            *rezult = 1;
            break;
        default:
            *x = create_decimal(1, 0, 0, 0x801b0000, 0);
            *y = create_decimal(1, 0, 0, 0x801b0000, 0);
            *rezult = 1;
            counter = -1;
    }
    return counter;
}

int set_for_greater_or_equal(int count_number, s21_decimal *x, s21_decimal *y, int *rezult) {
    int counter = count_number;
    switch (count_number) {
        case 1:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 2:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 3:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 4:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 0;
            break;
        case 5:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 6:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 7:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 8:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 9:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 10:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 11:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 1;
            break;
        case 12:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 13:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 1;
            break;
        case 14:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 15:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 0;
            break;
        case 16:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 17:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 18:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 19:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(1, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 20:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 0;
            break;
        case 21:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(1, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 22:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 23:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(1, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 24:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 25:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 26:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(1, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 27:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 0;
            break;
        case 28:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(1, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 29:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 30:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(1, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 31:
            *x = create_decimal(5, 0, 0, 0, 0);
            *y = create_decimal(5, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 32:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(5, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 33:
            *x = create_decimal(5, 0, 0, 0, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 34:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 35:
            *x = create_decimal(4, 0, 0, 0x80000000, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 36:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(4, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 37:
            *x = create_decimal(4, 0, 0, 0, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 38:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(4, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 39:
            *x = create_decimal(4, 0, 0, 0x80000000, 0);
            *y = create_decimal(5, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 40:
            *x = create_decimal(5, 0, 0, 0, 0);
            *y = create_decimal(4, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 41:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5, 0, 0, 0x00000000, 0);
            *rezult = 0;
            break;
        case 42:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5, 0, 0, 0x00000000, 0);
            *rezult = 1;
            break;
        case 43:
            *x = create_decimal(5, 0, 0, 0x00000000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 44:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 45:
            *x = create_decimal(4000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 46:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(4000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 47:
            *x = create_decimal(4000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 48:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(4000, 0, 0, 0x00030000, 0);
            *rezult = 1;
            break;
        case 49:
            *x = create_decimal(4000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5, 0, 0, 0x00000000, 0);
            *rezult = 1;
            break;
        case 50:
            *x = create_decimal(5, 0, 0, 0x00000000, 0);
            *y = create_decimal(4000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 51:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5000, 0, 0, 0x00030000, 0);
            *rezult = 0;
            break;
        case 52:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x00030000, 0);
            *rezult = 1;
            break;
        case 53:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 54:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 55:
            *x = create_decimal(4000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 56:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(4000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 57:
            *x = create_decimal(4000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 58:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(4000, 0, 0, 0x00030000, 0);
            *rezult = 1;
            break;
        case 59:
            *x = create_decimal(4000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x00030000, 0);
            *rezult = 1;
            break;
        case 60:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(4000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 61:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *y = create_decimal(1, 0, 0, 0x001c0000, 0);
            *rezult = 0;
            break;
        case 62:
            *x = create_decimal(1, 0, 0, 0x001c0000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *rezult = 1;
            break;
        case 63:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *y = create_decimal(1, 0, 0, 0x001c0000, 0);
            *rezult = 1;
            break;
        case 64:
            *x = create_decimal(1, 0, 0, 0x001c0000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *rezult = 0;
            break;
        case 65:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *y = create_decimal(1, 0, 0, 0x801c0000, 0);
            *rezult = 1;
            break;
        case 66:
            *x = create_decimal(1, 0, 0, 0x801c0000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *rezult = 0;
            break;
        case 67:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *y = create_decimal(1, 0, 0, 0x801c0000, 0);
            *rezult = 0;
            break;
        case 68:
            *x = create_decimal(1, 0, 0, 0x801c0000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *rezult = 1;
            break;
        case 69:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *rezult = 0;
            break;
        case 70:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *rezult = 0;
            break;
        case 71:
            *x = create_decimal(1, 0, 0, 0x001c0000, 0);
            *y = create_decimal(1, 0, 0, 0x001c0000, 0);
            *rezult = 0;
            break;
        case 72:
            *x = create_decimal(1, 0, 0, 0x801c0000, 0);
            *y = create_decimal(1, 0, 0, 0x801c0000, 0);
            *rezult = 0;
            break;
        default:
            *x = create_decimal(1, 0, 0, 0x801b0000, 0);
            *y = create_decimal(1, 0, 0, 0x801b0000, 0);
            *rezult = 0;
            counter = -1;
    }
    return counter;
}

int set_for_less(int count_number, s21_decimal *x, s21_decimal *y, int *rezult) {
    int counter = count_number;
    switch (count_number) {
        case 1:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 2:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 0;
            break;
        case 3:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 4:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 1;
            break;
        case 5:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 6:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 7:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 8:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 9:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 10:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 11:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 1;
            break;
        case 12:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 13:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 1;
            break;
        case 14:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 0;
            break;
        case 15:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 1;
            break;
        case 16:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 17:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 18:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 0;
            break;
        case 19:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(1, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 20:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 1;
            break;
        case 21:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(1, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 22:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 23:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(1, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 24:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 25:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 0;
            break;
        case 26:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(1, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 27:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 1;
            break;
        case 28:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(1, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 29:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 30:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(1, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 31:
            *x = create_decimal(5, 0, 0, 0, 0);
            *y = create_decimal(5, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 32:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(5, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 33:
            *x = create_decimal(5, 0, 0, 0, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 34:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 35:
            *x = create_decimal(4, 0, 0, 0x80000000, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 36:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(4, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 37:
            *x = create_decimal(4, 0, 0, 0, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 38:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(4, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 39:
            *x = create_decimal(4, 0, 0, 0x80000000, 0);
            *y = create_decimal(5, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 40:
            *x = create_decimal(5, 0, 0, 0, 0);
            *y = create_decimal(4, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 41:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(4, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 42:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(4, 0, 0, 0x00000000, 0);
            *rezult = 0;
            break;
        case 43:
            *x = create_decimal(4, 0, 0, 0x00000000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 44:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 45:
            *x = create_decimal(4000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 46:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(4000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 47:
            *x = create_decimal(4000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 48:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(4000, 0, 0, 0x00030000, 0);
            *rezult = 0;
            break;
        case 49:
            *x = create_decimal(4000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x00030000, 0);
            *rezult = 0;
            break;
        case 50:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(4000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 51:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5000, 0, 0, 0x00030000, 0);
            *rezult = 1;
            break;
        case 52:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x00030000, 0);
            *rezult = 0;
            break;
        case 53:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 54:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 55:
            *x = create_decimal(4000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 56:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(4000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 57:
            *x = create_decimal(4000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 58:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(4000, 0, 0, 0x00030000, 0);
            *rezult = 0;
            break;
        case 59:
            *x = create_decimal(4000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x00030000, 0);
            *rezult = 0;
            break;
        case 60:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(4000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 61:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *y = create_decimal(1, 0, 0, 0x001c0000, 0);
            *rezult = 1;
            break;
        case 62:
            *x = create_decimal(1, 0, 0, 0x001c0000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *rezult = 0;
            break;
        case 63:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *y = create_decimal(1, 0, 0, 0x001c0000, 0);
            *rezult = 0;
            break;
        case 64:
            *x = create_decimal(1, 0, 0, 0x001c0000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *rezult = 1;
            break;
        case 65:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *y = create_decimal(1, 0, 0, 0x801c0000, 0);
            *rezult = 0;
            break;
        case 66:
            *x = create_decimal(1, 0, 0, 0x801c0000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *rezult = 1;
            break;
        case 67:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *y = create_decimal(1, 0, 0, 0x801c0000, 0);
            *rezult = 1;
            break;
        case 68:
            *x = create_decimal(1, 0, 0, 0x801c0000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *rezult = 0;
            break;
        case 69:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *rezult = 1;
            break;
        case 70:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *rezult = 1;
            break;
        case 71:
            *x = create_decimal(1, 0, 0, 0x001c0000, 0);
            *y = create_decimal(1, 0, 0, 0x001c0000, 0);
            *rezult = 1;
            break;
        case 72:
            *x = create_decimal(1, 0, 0, 0x801c0000, 0);
            *y = create_decimal(1, 0, 0, 0x801c0000, 0);
            *rezult = 1;
            break;
        default:
            *x = create_decimal(1, 0, 0, 0x801b0000, 0);
            *y = create_decimal(1, 0, 0, 0x801b0000, 0);
            *rezult = 1;
            counter = -1;
    }
    return counter;
}

int set_for_less_or_equal(int count_number, s21_decimal *x, s21_decimal *y, int *rezult) {
    int counter = count_number;
    switch (count_number) {
        case 1:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 2:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 0;
            break;
        case 3:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 4:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 1;
            break;
        case 5:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 6:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 7:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 8:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 9:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 10:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 11:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 1;
            break;
        case 12:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 13:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 1;
            break;
        case 14:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 0;
            break;
        case 15:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 1;
            break;
        case 16:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 17:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 18:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 0;
            break;
        case 19:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(1, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 20:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 1;
            break;
        case 21:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(1, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 22:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 23:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(1, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 24:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 25:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 0;
            break;
        case 26:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(1, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 27:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 1;
            break;
        case 28:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(1, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 29:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 30:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(1, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 31:
            *x = create_decimal(5, 0, 0, 0, 0);
            *y = create_decimal(5, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 32:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(5, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 33:
            *x = create_decimal(5, 0, 0, 0, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 34:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 35:
            *x = create_decimal(4, 0, 0, 0x80000000, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 36:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(4, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 37:
            *x = create_decimal(4, 0, 0, 0, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 38:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(4, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 39:
            *x = create_decimal(4, 0, 0, 0x80000000, 0);
            *y = create_decimal(5, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 40:
            *x = create_decimal(5, 0, 0, 0, 0);
            *y = create_decimal(4, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 41:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(4, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 42:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(4, 0, 0, 0x00000000, 0);
            *rezult = 0;
            break;
        case 43:
            *x = create_decimal(4, 0, 0, 0x00000000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 44:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 45:
            *x = create_decimal(4000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 46:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(4000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 47:
            *x = create_decimal(4000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 48:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(4000, 0, 0, 0x00030000, 0);
            *rezult = 0;
            break;
        case 49:
            *x = create_decimal(4000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x00030000, 0);
            *rezult = 0;
            break;
        case 50:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(4000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 51:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5000, 0, 0, 0x00030000, 0);
            *rezult = 0;
            break;
        case 52:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x00030000, 0);
            *rezult = 0;
            break;
        case 53:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 54:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 55:
            *x = create_decimal(4000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 56:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(4000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 57:
            *x = create_decimal(4000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 58:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(4000, 0, 0, 0x00030000, 0);
            *rezult = 0;
            break;
        case 59:
            *x = create_decimal(4000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x00030000, 0);
            *rezult = 0;
            break;
        case 60:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(4000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 61:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *y = create_decimal(1, 0, 0, 0x001c0000, 0);
            *rezult = 1;
            break;
        case 62:
            *x = create_decimal(1, 0, 0, 0x001c0000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *rezult = 0;
            break;
        case 63:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *y = create_decimal(1, 0, 0, 0x001c0000, 0);
            *rezult = 0;
            break;
        case 64:
            *x = create_decimal(1, 0, 0, 0x001c0000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *rezult = 1;
            break;
        case 65:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *y = create_decimal(1, 0, 0, 0x801c0000, 0);
            *rezult = 0;
            break;
        case 66:
            *x = create_decimal(1, 0, 0, 0x801c0000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *rezult = 1;
            break;
        case 67:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *y = create_decimal(1, 0, 0, 0x801c0000, 0);
            *rezult = 1;
            break;
        case 68:
            *x = create_decimal(1, 0, 0, 0x801c0000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *rezult = 0;
            break;
        case 69:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *rezult = 0;
            break;
        case 70:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *rezult = 0;
            break;
        case 71:
            *x = create_decimal(1, 0, 0, 0x001c0000, 0);
            *y = create_decimal(1, 0, 0, 0x001c0000, 0);
            *rezult = 0;
            break;
        case 72:
            *x = create_decimal(1, 0, 0, 0x801c0000, 0);
            *y = create_decimal(1, 0, 0, 0x801c0000, 0);
            *rezult = 0;
            break;
        default:
            *x = create_decimal(1, 0, 0, 0x801b0000, 0);
            *y = create_decimal(1, 0, 0, 0x801b0000, 0);
            *rezult = 0;
            counter = -1;
    }
    return counter;
}

int set_for_equal(int count_number, s21_decimal *x, s21_decimal *y, int *rezult) {
    int counter = count_number;
    switch (count_number) {
        case 1:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 2:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 3:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 4:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 1;
            break;
        case 5:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 6:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 7:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 8:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 9:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 10:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 11:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 1;
            break;
        case 12:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 13:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 1;
            break;
        case 14:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 15:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 1;
            break;
        case 16:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 17:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 18:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 19:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(1, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 20:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 1;
            break;
        case 21:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(1, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 22:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 23:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(1, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 24:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 25:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 1;
            break;
        case 26:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(1, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 27:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 1;
            break;
        case 28:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(1, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 29:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 1;
            break;
        case 30:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(1, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 31:
            *x = create_decimal(5, 0, 0, 0, 0);
            *y = create_decimal(5, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 32:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(5, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 33:
            *x = create_decimal(5, 0, 0, 0, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 34:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 35:
            *x = create_decimal(4, 0, 0, 0x80000000, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 36:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(4, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 37:
            *x = create_decimal(4, 0, 0, 0, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 38:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(4, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 39:
            *x = create_decimal(4, 0, 0, 0x80000000, 0);
            *y = create_decimal(5, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 40:
            *x = create_decimal(5, 0, 0, 0, 0);
            *y = create_decimal(4, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 41:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5, 0, 0, 0x00000000, 0);
            *rezult = 0;
            break;
        case 42:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5, 0, 0, 0x00000000, 0);
            *rezult = 1;
            break;
        case 43:
            *x = create_decimal(5, 0, 0, 0x00000000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 44:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 45:
            *x = create_decimal(4000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 46:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(4000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 47:
            *x = create_decimal(4000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 48:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(4000, 0, 0, 0x00030000, 0);
            *rezult = 1;
            break;
        case 49:
            *x = create_decimal(4000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5, 0, 0, 0x00000000, 0);
            *rezult = 1;
            break;
        case 50:
            *x = create_decimal(5, 0, 0, 0x00000000, 0);
            *y = create_decimal(4000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 51:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5000, 0, 0, 0x00030000, 0);
            *rezult = 0;
            break;
        case 52:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x00030000, 0);
            *rezult = 1;
            break;
        case 53:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 54:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 55:
            *x = create_decimal(4000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 56:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(4000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 57:
            *x = create_decimal(4000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 58:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(4000, 0, 0, 0x00030000, 0);
            *rezult = 1;
            break;
        case 59:
            *x = create_decimal(4000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x00030000, 0);
            *rezult = 1;
            break;
        case 60:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(4000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 61:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *y = create_decimal(1, 0, 0, 0x001c0000, 0);
            *rezult = 1;
            break;
        case 62:
            *x = create_decimal(1, 0, 0, 0x001c0000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *rezult = 1;
            break;
        case 63:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *y = create_decimal(1, 0, 0, 0x001c0000, 0);
            *rezult = 1;
            break;
        case 64:
            *x = create_decimal(1, 0, 0, 0x001c0000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *rezult = 1;
            break;
        case 65:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *y = create_decimal(1, 0, 0, 0x801c0000, 0);
            *rezult = 1;
            break;
        case 66:
            *x = create_decimal(1, 0, 0, 0x801c0000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *rezult = 1;
            break;
        case 67:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *y = create_decimal(1, 0, 0, 0x801c0000, 0);
            *rezult = 1;
            break;
        case 68:
            *x = create_decimal(1, 0, 0, 0x801c0000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *rezult = 1;
            break;
        case 69:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *rezult = 0;
            break;
        case 70:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *rezult = 0;
            break;
        case 71:
            *x = create_decimal(1, 0, 0, 0x001c0000, 0);
            *y = create_decimal(1, 0, 0, 0x001c0000, 0);
            *rezult = 0;
            break;
        case 72:
            *x = create_decimal(1, 0, 0, 0x801c0000, 0);
            *y = create_decimal(1, 0, 0, 0x801c0000, 0);
            *rezult = 0;
            break;
        default:
            *x = create_decimal(1, 0, 0, 0x801b0000, 0);
            *y = create_decimal(1, 0, 0, 0x801b0000, 0);
            *rezult = 0;
            counter = -1;
    }
    return counter;
}

int set_for_not_equal(int count_number, s21_decimal *x, s21_decimal *y, int *rezult) {
    int counter = count_number;
    switch (count_number) {
        case 1:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 2:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 0;
            break;
        case 3:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 4:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 0;
            break;
        case 5:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 6:
            *x = create_decimal(0, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 0;
            break;
        case 7:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 8:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 0;
            break;
        case 9:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 0;
            break;
        case 10:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 0;
            break;
        case 11:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 0;
            break;
        case 12:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 0;
            break;
        case 13:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 0;
            break;
        case 14:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 0;
            break;
        case 15:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 0;
            break;
        case 16:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 0;
            break;
        case 17:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 18:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 0;
            break;
        case 19:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(1, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 20:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 0;
            break;
        case 21:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(1, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 22:
            *x = create_decimal(1, 0, 0, 0, 0);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 0;
            break;
        case 23:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(1, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 24:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 25:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 1);
            *rezult = 0;
            break;
        case 26:
            *x = create_decimal(0, 0, 0, 0, 1);
            *y = create_decimal(1, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 27:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 2);
            *rezult = 0;
            break;
        case 28:
            *x = create_decimal(0, 0, 0, 0, 2);
            *y = create_decimal(1, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 29:
            *x = create_decimal(1, 0, 0, 0x80000000, 0);
            *y = create_decimal(0, 0, 0, 0, 3);
            *rezult = 0;
            break;
        case 30:
            *x = create_decimal(0, 0, 0, 0, 3);
            *y = create_decimal(1, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 31:
            *x = create_decimal(5, 0, 0, 0, 0);
            *y = create_decimal(5, 0, 0, 0, 0);
            *rezult = 1;
            break;
        case 32:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(5, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 33:
            *x = create_decimal(5, 0, 0, 0, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 34:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 35:
            *x = create_decimal(4, 0, 0, 0x80000000, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 36:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(4, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 37:
            *x = create_decimal(4, 0, 0, 0, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 38:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(4, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 39:
            *x = create_decimal(4, 0, 0, 0x80000000, 0);
            *y = create_decimal(5, 0, 0, 0, 0);
            *rezult = 0;
            break;
        case 40:
            *x = create_decimal(5, 0, 0, 0, 0);
            *y = create_decimal(4, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 41:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5, 0, 0, 0x00000000, 0);
            *rezult = 1;
            break;
        case 42:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5, 0, 0, 0x00000000, 0);
            *rezult = 0;
            break;
        case 43:
            *x = create_decimal(5, 0, 0, 0x00000000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 44:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 1;
            break;
        case 45:
            *x = create_decimal(4000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 46:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(4000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 47:
            *x = create_decimal(4000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5, 0, 0, 0x80000000, 0);
            *rezult = 0;
            break;
        case 48:
            *x = create_decimal(5, 0, 0, 0x80000000, 0);
            *y = create_decimal(4000, 0, 0, 0x00030000, 0);
            *rezult = 0;
            break;
        case 49:
            *x = create_decimal(4000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5, 0, 0, 0x00000000, 0);
            *rezult = 0;
            break;
        case 50:
            *x = create_decimal(5, 0, 0, 0x00000000, 0);
            *y = create_decimal(4000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 51:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5000, 0, 0, 0x00030000, 0);
            *rezult = 1;
            break;
        case 52:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x00030000, 0);
            *rezult = 0;
            break;
        case 53:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 54:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 1;
            break;
        case 55:
            *x = create_decimal(4000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 56:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(4000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 57:
            *x = create_decimal(4000, 0, 0, 0x00030000, 0);
            *y = create_decimal(5000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 58:
            *x = create_decimal(5000, 0, 0, 0x80030000, 0);
            *y = create_decimal(4000, 0, 0, 0x00030000, 0);
            *rezult = 0;
            break;
        case 59:
            *x = create_decimal(4000, 0, 0, 0x80030000, 0);
            *y = create_decimal(5000, 0, 0, 0x00030000, 0);
            *rezult = 0;
            break;
        case 60:
            *x = create_decimal(5000, 0, 0, 0x00030000, 0);
            *y = create_decimal(4000, 0, 0, 0x80030000, 0);
            *rezult = 0;
            break;
        case 61:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *y = create_decimal(1, 0, 0, 0x001c0000, 0);
            *rezult = 0;
            break;
        case 62:
            *x = create_decimal(1, 0, 0, 0x001c0000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0, 0);
            *rezult = 0;
            break;
        case 63:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *y = create_decimal(1, 0, 0, 0x001c0000, 0);
            *rezult = 0;
            break;
        case 64:
            *x = create_decimal(1, 0, 0, 0x001c0000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *rezult = 0;
            break;
        case 65:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *y = create_decimal(1, 0, 0, 0x801c0000, 0);
            *rezult = 0;
            break;
        case 66:
            *x = create_decimal(1, 0, 0, 0x801c0000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *rezult = 0;
            break;
        case 67:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *y = create_decimal(1, 0, 0, 0x801c0000, 0);
            *rezult = 0;
            break;
        case 68:
            *x = create_decimal(1, 0, 0, 0x801c0000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *rezult = 0;
            break;
        case 69:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0);
            *rezult = 1;
            break;
        case 70:
            *x = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *y = create_decimal(0xffffffff, 0xffffffff, 0xffffffff, 0x80000000, 0);
            *rezult = 1;
            break;
        case 71:
            *x = create_decimal(1, 0, 0, 0x001c0000, 0);
            *y = create_decimal(1, 0, 0, 0x001c0000, 0);
            *rezult = 1;
            break;
        case 72:
            *x = create_decimal(1, 0, 0, 0x801c0000, 0);
            *y = create_decimal(1, 0, 0, 0x801c0000, 0);
            *rezult = 1;
            break;
        default:
            *x = create_decimal(1, 0, 0, 0x801b0000, 0);
            *y = create_decimal(1, 0, 0, 0x801b0000, 0);
            *rezult = 1;
            counter = -1;
    }
    return counter;
}


START_TEST(test_for_add) {
    s21_decimal x, y, z, rezult;
    int counter = 1;
    while (counter > 0) {
        counter = set_for_add(counter, &x, &y, &z);
        if (counter != 0) counter++;
        rezult = s21_add(x, y);
        ck_assert_msg(equal_decimal_for_test(z, rezult) == 0, "counter = %d", counter - 1);
    }
}
END_TEST

START_TEST(test_for_sub) {
    s21_decimal x, y, z, rezult;
    int counter = 1;
    while (counter > 0) {
        counter = set_for_sub(counter, &x, &y, &z);
        if (counter != 0) counter++;
        rezult = s21_sub(x, y);
        ck_assert_msg(equal_decimal_for_test(z, rezult) == 0, "counter = %d", counter - 1);
    }
}
END_TEST

START_TEST(test_for_mul) {
    s21_decimal x, y, z, rezult;
    int counter = 1;
    while (counter > 0) {
        counter = set_for_mul(counter, &x, &y, &z);
        int temp_decimal_dec[121] = {0}, temp_type_value = z.value_type;
        convert_decimal_to_decimal_dec(temp_decimal_dec, z);
        convert_decimal_dec_to_decimal(&z, temp_decimal_dec);
        z.value_type = temp_type_value;
        if (counter != 0) counter++;
        rezult = s21_mul(x, y);
        ck_assert_msg(equal_decimal_for_test(z, rezult) == 0, "counter = %d", counter - 1);
    }
}
END_TEST

START_TEST(test_for_div) {
    s21_decimal x, y, z, rezult;
    int counter = 1;
    while (counter > 0) {
        counter = set_for_div(counter, &x, &y, &z);
        if (counter != 0) counter++;
        rezult = s21_div(x, y);
        ck_assert_msg(equal_decimal_for_test(z, rezult) == 0, "counter = %d", counter - 1);
    }
}
END_TEST

START_TEST(test_for_float) {
    int counter = 1;
    while (counter > -1) {
        float test_float_in, test_float_out;
        s21_decimal test_decimal = {0};
        counter = set_for_float(counter, &test_float_in);
        int status_in = s21_from_float_to_decimal(test_float_in, &test_decimal);
        int status_out = s21_from_decimal_to_float(test_decimal, &test_float_out);
        if (counter > -1) counter++;
        ck_assert_msg(test_float_in == test_float_out ||
        (isnan(test_float_in) && isnan(test_float_out)), "counter = %d", counter - 1);
    }
}
END_TEST

START_TEST(test_for_int) {
    int counter = 1;
    while (counter > -1) {
        int test_int_in, test_int_out;
        s21_decimal test_decimal = {0};
        counter = set_for_int(counter, &test_int_in);
        int status_in = s21_from_int_to_decimal(test_int_in, &test_decimal);
        int status_out = s21_from_decimal_to_int(test_decimal, &test_int_out);
        if (counter > -1) counter++;
        ck_assert_msg(test_int_in == test_int_out, "counter = %d", counter - 1);
    }
}
END_TEST

START_TEST(test_for_truncate) {
    s21_decimal x, z, rezult;
    int counter = 1;
    while (counter > 0) {
        counter = set_for_truncate(counter, &x, &z);
        if (counter != 0) counter++;
        rezult = s21_truncate(x);
        ck_assert_msg(equal_decimal_for_test(z, rezult) == 0, "counter = %d", counter - 1);
    }
}
END_TEST

START_TEST(test_for_floor) {
    s21_decimal x, z, rezult;
    int counter = 1;
    while (counter > 0) {
        counter = set_for_floor(counter, &x, &z);
        if (counter != 0) counter++;
        rezult = s21_floor(x);
        ck_assert_msg(equal_decimal_for_test(z, rezult) == 0, "counter = %d", counter - 1);
    }
}
END_TEST

START_TEST(test_for_round) {
    s21_decimal x, z, rezult;
    int counter = 1;
    while (counter > 0) {
        counter = set_for_round(counter, &x, &z);
        if (counter != 0) counter++;
        rezult = s21_round(x);
        ck_assert_msg(equal_decimal_for_test(z, rezult) == 0, "counter = %d", counter - 1);
    }
}
END_TEST

START_TEST(test_for_negate) {
    int counter = 1;
    while (counter > 0) {
        s21_decimal x, z, rezult;
        counter = set_for_negate(counter, &x, &z);
        if (counter != 0) counter++;
        rezult = s21_negate(x);
        ck_assert_msg(equal_decimal_for_test(z, rezult) == 0, "counter = %d", counter - 1);
    }
}
END_TEST

START_TEST(test_for_mod) {
    s21_decimal x, y, z, rezult;
    int counter = 1;
    while (counter > 0) {
        counter = set_for_mod(counter, &x, &y, &z);
        if (counter != 0) counter++;
        rezult = s21_mod(x, y);
        ck_assert_msg(equal_decimal_for_test(z, rezult) == 0, "counter = %d", counter - 1);
    }
}
END_TEST

START_TEST(test_for_greater) {
    int counter = 1;
    while (counter > 0) {
        s21_decimal x, y;
        int z, rezult;
        counter = set_for_greater(counter, &x, &y, &z);
        if (counter != 0) counter++;
        rezult = s21_is_greater(x, y);
        ck_assert_msg(rezult == z, "counter = %d", counter - 1);
    }
}
END_TEST

START_TEST(test_for_greater_or_equal) {
    int counter = 1;
    while (counter > 0) {
        s21_decimal x, y;
        int z, rezult;
        counter = set_for_greater_or_equal(counter, &x, &y, &z);
        if (counter != 0) counter++;
        rezult = s21_is_greater_or_equal(x, y);
        ck_assert_msg(rezult == z, "counter = %d", counter - 1);
    }
}
END_TEST

START_TEST(test_for_less) {
    int counter = 1;
    while (counter > 0) {
        s21_decimal x, y;
        int z, rezult;
        counter = set_for_less(counter, &x, &y, &z);
        if (counter != 0) counter++;
        rezult = s21_is_less(x, y);
        ck_assert_msg(rezult == z, "counter = %d", counter - 1);
    }
}
END_TEST

START_TEST(test_for_less_or_equal) {
    int counter = 1;
    while (counter > 0) {
        s21_decimal x, y;
        int z, rezult;
        counter = set_for_less_or_equal(counter, &x, &y, &z);
        if (counter != 0) counter++;
        rezult = s21_is_less_or_equal(x, y);
        ck_assert_msg(rezult == z, "counter = %d", counter - 1);
    }
}
END_TEST

START_TEST(test_for_equal) {
    int counter = 1;
    while (counter > 0) {
        s21_decimal x, y;
        int z, rezult;
        counter = set_for_equal(counter, &x, &y, &z);
        if (counter != 0) counter++;
        rezult = s21_is_equal(x, y);
        ck_assert_msg(rezult == z, "counter = %d", counter - 1);
    }
}
END_TEST

START_TEST(test_for_not_equal) {
    int counter = 1;
    while (counter > 0) {
        s21_decimal x, y;
        int z, rezult;
        counter = set_for_not_equal(counter, &x, &y, &z);
        if (counter != 0) counter++;
        rezult = s21_is_not_equal(x, y);
        ck_assert_msg(rezult == z, "counter = %d", counter - 1);
    }
}
END_TEST

START_TEST(test_print_functions) {
    s21_decimal x = {{0}, 0};
    // int counter = 1;
    s21_print_decimal_dec(x);
    s21_print_decimal_bin(x);
    print_decimal(x);
    // convert_decimal_dec_to_decimal_bin(decimal_bin, decimal_dec);
    // ck_assert_msg(counter == 1, "counter = %d", counter - 1);
}
END_TEST

int main(void) {
Suite *s1 = suite_create("s21_decimal_test");
SRunner *sr = srunner_create(s1);
  int nf;

TCase *tc1_1 = tcase_create("s21_add");
  tcase_set_timeout(tc1_1, 360);
  tcase_add_test(tc1_1, test_for_add);
  suite_add_tcase(s1, tc1_1);

TCase *tc1_2 = tcase_create("s21_sub");
  tcase_set_timeout(tc1_2, 360);
  tcase_add_test(tc1_2, test_for_sub);
  suite_add_tcase(s1, tc1_2);

TCase *tc1_3 = tcase_create("s21_mul");
  tcase_set_timeout(tc1_3, 360);
  tcase_add_test(tc1_3, test_for_mul);
  suite_add_tcase(s1, tc1_3);

TCase *tc1_4 = tcase_create("s21_div");
  tcase_set_timeout(tc1_4, 360);
  tcase_add_test(tc1_4, test_for_div);
  suite_add_tcase(s1, tc1_4);

TCase *tc1_5 = tcase_create("s21_float");
  tcase_set_timeout(tc1_5, 15);
  tcase_add_test(tc1_5, test_for_float);
  suite_add_tcase(s1, tc1_5);

TCase *tc1_6 = tcase_create("s21_int");
  tcase_set_timeout(tc1_6, 15);
  tcase_add_test(tc1_6, test_for_int);
  suite_add_tcase(s1, tc1_6);

  TCase *tc1_7 = tcase_create("s21_truncate");
  tcase_set_timeout(tc1_7, 15);
  tcase_add_test(tc1_7, test_for_truncate);
  suite_add_tcase(s1, tc1_7);

  TCase *tc1_8 = tcase_create("s21_floor");
  tcase_set_timeout(tc1_8, 15);
  tcase_add_test(tc1_8, test_for_floor);
  suite_add_tcase(s1, tc1_8);

  TCase *tc1_9 = tcase_create("s21_round");
  tcase_set_timeout(tc1_9, 30);
  tcase_add_test(tc1_9, test_for_round);
  suite_add_tcase(s1, tc1_9);

  TCase *tc1_10 = tcase_create("s21_negate");
  tcase_set_timeout(tc1_10, 15);
  tcase_add_test(tc1_10, test_for_negate);
  suite_add_tcase(s1, tc1_10);

  TCase *tc1_11 = tcase_create("s21_mod");
  tcase_set_timeout(tc1_11, 15);
  tcase_add_test(tc1_11, test_for_mod);
  suite_add_tcase(s1, tc1_11);

  TCase *tc1_12 = tcase_create("s21_greater");
  tcase_set_timeout(tc1_12, 30);
  tcase_add_test(tc1_12, test_for_greater);
  suite_add_tcase(s1, tc1_12);

  TCase *tc1_13 = tcase_create("s21_greater_or_equal");
  tcase_set_timeout(tc1_13, 30);
  tcase_add_test(tc1_13, test_for_greater_or_equal);
  suite_add_tcase(s1, tc1_13);

  TCase *tc1_14 = tcase_create("s21_less");
  tcase_set_timeout(tc1_14, 30);
  tcase_add_test(tc1_14, test_for_less);
  suite_add_tcase(s1, tc1_14);

  TCase *tc1_15 = tcase_create("s21_less_or_equal");
  tcase_set_timeout(tc1_15, 30);
  tcase_add_test(tc1_15, test_for_less_or_equal);
  suite_add_tcase(s1, tc1_15);

  TCase *tc1_16 = tcase_create("s21_equal");
  tcase_set_timeout(tc1_16, 30);
  tcase_add_test(tc1_16, test_for_equal);
  suite_add_tcase(s1, tc1_16);

  TCase *tc1_17 = tcase_create("s21_not_equal");
  tcase_set_timeout(tc1_17, 30);
  tcase_add_test(tc1_17, test_for_not_equal);
  suite_add_tcase(s1, tc1_17);

  TCase *tc1_18 = tcase_create("s21_print_decimal");
  tcase_set_timeout(tc1_18, 15);
  tcase_add_test(tc1_18, test_print_functions);
  suite_add_tcase(s1, tc1_18);

  srunner_run_all(sr, CK_VERBOSE);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  return nf == 0 ? 0 : 1;
}
