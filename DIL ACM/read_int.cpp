// info about me at the bottom
#include "read_int.h"
#include <cctype>
using std::isdigit;

int base_of(const char *token) {

  if (token[0] == '\0') { // error
    return 0;
  }

  if (token[0] == '0') {

    if (token[1] == '\0') { // token is "0"?
      return 10;

    } else if (token[1] == 'x') { // dexahecimal
      return 16;

    } else if (token[1] == 'b') { // binary
      return 2;

    } else { // octal
      return 8;
    }
  } else {
    if (isdigit(token[0]))
      return 10; // decimal
  }

  return 0; // error
}

int read_int(char c, const int base) {

  int number = -1;
  // an invalid value that should change

  if (base == 16) { // base 16

    number = read_int(c, 10);
    if (number != -1)
      return number;

    if ('a' <= c && c <= 'f')
      return c - 'a' + 10;

    if ('A' <= c && c <= 'F')
      return c - 'A' + 10;

    return -1;
  } 
  // any other base
  number = c - '0';
  if (number < 0 || number >= base)
    return -1;

  return number;
}

int read_int(const char *token, int *number) {

  *number = 0;

  int base = base_of(token);
  if (!base)
    return 0;
  // moving after the "0b.." or "0x..." ("0.." is fine)
  if (base == 2 || base == 16)
    token += 2;

  int digit;

  // the pointer 'token' is pushed to the end
  while (*token != '\0') {
    digit = read_int(*token, base);
    if (digit == -1)
      return 0; // invalid character as digit

    *number *= base;
    *number += digit;
    if (*number < 0)
      return 0; // overflow

    ++token;
  }

  return 1; // the number is fine
}

/*

name:			Theodoros Dimakopoulos
GitHub:		TheodoreAlenas (nickname is Alenas)
e-mail:		dimakopt732@gmail.com
place:		Greece, UOA (known there as sdi1900048)
last edit:	4-12-19

*/