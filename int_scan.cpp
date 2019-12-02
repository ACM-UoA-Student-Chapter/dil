/*
* Copyright: Copyright nsoul97 (Soulounias Nikolaos) 2019.
* License:   $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
* Authors:   nsoul97 (Soulounias Nikolaos)
*/


#include "int_scan.hpp"
#include <cassert>
#include <cstdint>
#include <ctype.h>

int8_t char_to_digit[256];

/*
Initialize the char_to_digit array.
If a character is a number (with an octal, decimal or hexadecimal base), store
the decimal value of the digit in the char_to_digit array. Else store -1.
*/
void init_char_to_digit() {
  for (int c = 0; c < 256; c++) {
    char lc = tolower(c);
    if ('0' <= c && c <= '9')
      char_to_digit[c] = c - '0';
    else if (lc >= 'a' && lc <= 'f')
      char_to_digit[c] = lc - 'a' + 10;
    else
      char_to_digit[c] = -1;
  }
}

/*
The function returns the index of the character after the prefix of the given
input. Decimal numbers have no prefix. Octal numbers have prefix 0. Hexadecimal
numbers have prefix 0x or 0X.

NOTE:: 0 is a decimal number without prefix.
*/
static int skip_prefix(const char *input) {
  if (input[0] != '0' || input[1] == '\0')
    return 0;
  if (tolower(input[1]) != 'x')
    return 1;
  return 2;
}

/*
The function returns the base of the input, based on the index of the character
after the prefix of the input. Decimal numbers have no prefix, so start_pos=0.
Octal numbers have prefix 0, so start_pos=1.
Hexadecimal numbers have prefix 0x or 0X, so start_pos=2.
Any other start_pos is invalid.
*/
static int find_base(int start_pos) {
  switch (start_pos) {
  case 0:
    return 10;
  case 1:
    return 8;
  case 2:
    return 16;
  default:
    assert(0);
  }
}

/*
The function returns the integer value of the digit character passed as an
argument depending on the digit's base. The digit's base is specified by the
num_base argument of the function If the digit is out of bounds, the function
returns -1.
*/
static int char_to_dec(char digit, const int num_base) {
  int dec_val = char_to_digit[digit];
  if (dec_val < 0 || dec_val >= num_base)
    return -1;
  return dec_val;
}

/*
The function scans the numerical input string passed as an argument and strores
its value in the val pointer. This function returns the respective error code in
case of error or the success code when the integer is successfully scanned. Ther
error codes are defined as:
-->OVERFLOW_ERROR
-->OUT_OF_BOUNDS_ERROR
-->EMPTY_NUM_EXPR_ERROR
The success code is INT_SCANNED.
*/
int read_int(const char *input, int *val) {
  int position = skip_prefix(input);
  const int int_base = find_base(position);
  if (input[position] == '\0')
    return EMPTY_NUM_EXPR_ERROR;
  int sum = 0;
  for (int i = position; input[i] != '\0'; i++) {
    int dec_dig = char_to_dec(input[i], int_base);
    if (dec_dig == -1)
      return OUT_OF_BOUNDS_ERROR;
    sum = sum * int_base + dec_dig;
    if (sum < 0)
      return OVERFLOW_ERROR;
  }
  *val = sum;
  return INT_SCANNED;
}
