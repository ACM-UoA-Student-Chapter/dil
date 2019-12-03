#include "int_scan.hpp"
#include <cassert>
#include <ctype.h>

static const int OCT = 8;
static const int DEC = 10;
static const int HEX = 16;

/*
The function returns a member of the Base enumeration, which represents the base
of the input string. If the input string starts with the character 0 (zero),
then the input string represents an octal number. If the input string starts
with the characters 0x or 0X (zero x/X), then the input string represents a
hexadecimal number. If the input string does not have one of these prefixes,
then the input string represents a decimal number. The function starts looking
for the prefix from the index specified by the position pointer. The function
also returns the position of the next character of the input to be read after
the prefix (if it exists).
*/
static int check_base(const char *input, int *position) {
  int pos = 0;
  if (input[pos] != '0') {
    *position = pos;
    return DEC;
  }
  pos++;
  if (tolower(input[pos]) == 'x') {
    pos++;
    *position = pos;
    return HEX;
  }
  *position = pos;
  return OCT;
}

/*
The function returns the integer value of the digit character passed as an
argument. The digit's base is 10. If the digit is out of bounds, the function
returns -1.
*/
static int base10_char_to_dec(char digit) {
  if ('0' <= digit && digit <= '9')
    return digit - '0';
  return -1;
}

/*
The function returns the integer value of the digit character passed as an
argument. The digit's base is 8. If the digit is out of bounds, the function
returns -1.
*/
static int base8_char_to_dec(char digit) {
  if ('0' <= digit && digit <= '7')
    return digit - '0';
  return -1;
}

/*
The function returns the integer value of the digit character passed as an
argument. The digit's base is 16. If the digit is out of bounds, the function
returns -1. Both uppercase and lowercase letters a-f and A-F are considered to
be valid.
*/
static int base16_char_to_dec(char digit) {
  if ('0' <= digit && digit <= '9')
    return digit - '0';
  char ldigit = tolower(digit);
  if ('a' <= ldigit && ldigit <= 'f')
    return 10 + ldigit - 'a';
  return -1;
}

/*
The function returns the integer value of the digit character passed as an
argument depending on the digit's base. The digit's base is specified by the
num_base argument of the function If the digit is out of bounds, the function
returns -1.
*/
static int char_to_dec(char digit, const int num_base) {
  if (num_base == DEC)
    return base10_char_to_dec(digit);
  if (num_base == OCT)
    return base8_char_to_dec(digit);
  assert(num_base == HEX);
  return base16_char_to_dec(digit);
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
  int position;
  const int int_base = check_base(input, &position);
  if (input[position] == '\0' &&
      int_base != OCT) // input string may be the zero literal "0".
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
