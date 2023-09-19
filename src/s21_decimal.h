#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

typedef enum {
    s21_NORMAL_VALUE = 0,
    s21_INFINITY = 1,
    s21_NEGATIVE_INFINITY = 2,
    s21_NAN = 3
} value_type_t;

typedef struct {
    unsigned int bits[4];
    value_type_t value_type;
} s21_decimal;

s21_decimal s21_add(s21_decimal first_number, s21_decimal second_number);
s21_decimal s21_sub(s21_decimal first_number, s21_decimal second_number);
s21_decimal s21_mul(s21_decimal first_number, s21_decimal second_number);
s21_decimal s21_div(s21_decimal first_number, s21_decimal second_number);
s21_decimal s21_mod(s21_decimal first_number, s21_decimal second_number);
int s21_is_less(s21_decimal first_number, s21_decimal second_number);
int s21_is_less_or_equal(s21_decimal first_number, s21_decimal second_number);
int s21_is_greater(s21_decimal first_number, s21_decimal second_number);
int s21_is_greater_or_equal(s21_decimal first_number, s21_decimal second_number);
int s21_is_equal(s21_decimal first_number, s21_decimal second_number);
int s21_is_not_equal(s21_decimal first_number, s21_decimal second_number);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
s21_decimal s21_truncate(s21_decimal number);
s21_decimal s21_round(s21_decimal number);
s21_decimal s21_negate(s21_decimal number);
s21_decimal s21_floor(s21_decimal number);


void s21_print_decimal_bin(s21_decimal number);
void s21_print_decimal_dec(s21_decimal number);

void add_simple_decimal_dec(int rezult_decimal_dec[], int decimal_dec_1[], int decimal_dec_2[]);
void sub_simple_decimal_dec(int rezult_decimal_dec[], int decimal_dec_1[], int decimal_dec_2[]);
void sub_simple_decimal_dec_for_positive_both(int rezult_decimal_dec[], int decimal_dec_1[],
int decimal_dec_2[]);
void print_simple_decimal_dec(int decimal_dec[]);
void copy_simple_decimal_dec(int decimal_dec_1[], const int decimal_dec_2[]);
void multip_simple_decimal_dec_with_multiplier(int rezult_decimal_dec[], int decimal_dec_1[], int multiplier);
void multip_simple_decimal_dec(int rezult_decimal_dec[], int decimal_dec_1[], int decimal_dec_2[]);
void pow_simple_decimal_dec_with_exp(int rezult_decimal_dec[], int decimal_dec_1[], int exp);
void convert_decimal_to_decimal_dec(int rezult_decimal_dec[], s21_decimal number);
void convert_number_to_decimal_bin(unsigned int decimal_bin[], s21_decimal number);
void print_decimal_bin(unsigned int decimal_bin[]);

void div_simple_decimal_dec(int rezult_decimal_dec[], int decimal_dec_1[], int decimal_dec_2[]);
int numbers_before_dot_decimal_dec(const int decimal_dec[]);
void move_simple_dec_to_the_left(int decimal_dec[], int shift);
void move_simple_dec_to_the_right(int decimal_dec[], int shift);

int equal_simple_decimal_dec(const int decimal_dec_1[], const int decimal_dec_2[]);
int greater_simple_decimal_dec(int decimal_dec_1[], int decimal_dec_2[]);
int less_simple_decimal_dec(int decimal_dec_1[], int decimal_dec_2[]);
int less_or_equal_simple_decimal_dec(int decimal_dec_1[], int decimal_dec_2[]);
int greater_or_equal_simple_decimal_dec(int decimal_dec_1[], int decimal_dec_2[]);
int not_equal_simple_decimal_dec(int decimal_dec_1[], int decimal_dec_2[]);

void truncate_simple_decimal_dec(int rezult_decimal_dec[], int decimal_dec[]);
void mod_simple_decimal_dec(int rezult_decimal_dec[], int decimal_dec_1[], int decimal_dec_2[]);
void convert_decimal_dec_to_decimal(s21_decimal *number, int decimal_dec[]);
void convert_decimal_dec_to_3_int(s21_decimal *number, int temp_decimal_dec[]);
void round_simple_decimal_dec(int rezult_decimal_dec[], int decimal_dec[]);
void round_simple_decimal_dec_for_round(int rezult_decimal_dec[], int decimal_dec[]);
void floor_simple_decimal_dec(int rezult_decimal_dec[], int decimal_dec[]);

int equal_to_infinity(s21_decimal *rezult_number, int decimal_dec[]);
int near_to_zero(int decimal_dec[]);
void print_decimal(s21_decimal number);

void if_inf_or_nan_3(s21_decimal *rezult_number, s21_decimal first_number, s21_decimal second_number);
void if_inf_or_nan_2(s21_decimal *rezult_number, s21_decimal first_number, s21_decimal second_number);
void if_near_to_zero_2(s21_decimal *rezult_number, s21_decimal first_number, s21_decimal second_number);
void if_inf_or_nan(s21_decimal *rezult_number, s21_decimal first_number, s21_decimal second_number);
void if_near_to_zero(s21_decimal *rezult_number, s21_decimal first_number, s21_decimal second_number);

#endif  // SRC_S21_DECIMAL_H_
