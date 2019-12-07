#ifndef __INT_SCAN_HPP
#define __INT_SCAN_HPP

#define INT_SCANNED 0;
#define OVERFLOW_ERROR -1;
#define OUT_OF_BOUNDS_ERROR -2;
#define EMPTY_NUM_EXPR_ERROR -3;

int read_int(const char *input, int *val);
void init_char_to_digit();

#endif
