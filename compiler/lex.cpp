/*
 * Copyright: Copyright nsoul97 (Soulounias Nikolaos) 2019.
 * License:   $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
 * Authors:   nsoul97 (Soulounias Nikolaos)
 */

#include "lex.h"
#include "tokens.h"
#include <cstdint>
#include <cstdio>
#include <ctype.h>

Token token;
static const char *input;

/*
The character-properties map array.
ch_map[c] is the properties of the character c.
The bits of ch_map[c] correspond to it's properties.

ch_map[c] & CM_DEC
will be true if c is a decimal digit.

ch_map[c] == CM_DEC
will be true if the ONLY property of c is that it's
decimal. Use the '==' with great caution!

ch_map[c] & (CM_BLANK | CM_DEC)
will be true if c is either a blank character or a
decimal digit.
*/
enum CM_TYPE {
  CM_NO_PROPERTY = 0,
  CM_BLANK = 1,           // space, new-line or tab
  CM_IDENTIFIER = 1 << 1, // if could be in an ident
  CM_OCT = 1 << 2,        // '0' to '7'
  CM_DEC = 1 << 3,        // '0' to '9'
  CM_HEX = 1 << 4         // '0'-'9', 'a'-'f', 'A'-'F'
};
// Tells in what category the character falls.
static int ch_map[128] = {};
// Converts character digits to their numerical value.
static int8_t digit_to_val[256];

/*
Initialize the digit_to_val array.
If a character is a number (with an octal, decimal or hexadecimal base), store
the decimal value of the digit in the digit_to_val array. Else store -1.
*/
void init_digit_to_val() {
  for (int c = 0; c < 256; c++) {
    char lc = tolower(c);
    if ('0' <= c && c <= '9')
      digit_to_val[c] = c - '0';
    else if (lc >= 'a' && lc <= 'f')
      digit_to_val[c] = lc - 'a' + 10;
  }
}

/*
Return: -1 in case of error. Otherwise, return the numerical integer
base based on the prefix of the number.
Decimal numbers have no prefix. Octal numbers have prefix 0. Hexadecimal
numbers have prefix 0x or 0X.

NOTE: 0 is a decimal number without prefix.
*/
static int find_base() {
  int base = 10;
  if (*input == '0') {
    ++input;
    if (tolower(*input) == 'x') {
      base = 16;
      ++input;
      if (!(ch_map[*input] & CM_HEX)) {
        // TODO: warning()
        printf("Invalid hex literal\n");
        return -1;
      }
    } else if (ch_map[*input] & CM_OCT) {
      base = 8;
    } else if (ch_map[*input] & CM_HEX) {
      // TODO: warning()
      printf("Invalid octal literal\n");
      return -1;
    }
  }
  return base;
}

/*
The function returns the integer value of the digit character passed as an
argument depending on the digit's base `num_base`.
If the digit is out of bounds, the function returns -1.
*/
static int char_to_dec(char digit, const int num_base) {
  int dec_val = digit_to_val[digit];
  if (dec_val < 0 || dec_val >= num_base)
    return -1;
  return dec_val;
}

/*
This function should be called only when we're supposed to have an integer
literal following. It fills `token.val` with the integer value.
On error, token.val = 0;
*/
static void scan_int() {
  // TODO: On error, eat remaining digits.
  token.val = 0;
  const int int_base = find_base();
  if (int_base == -1) {
    token.val = 0;
    return;
  }
  int sum = 0;
  while (*input) {
    int dec_dig = digit_to_val[*input];
    // Note that with this, for hexadecimals,
    // we can't ever have out of base error since
    // any other letter will just be considered
    // part of another token (12a is considered though).
    if (dec_dig == 0 && *input != '0')
      break;
    if (dec_dig >= int_base) {
      token.val = 0;
      // TODO: warning()
      printf("Out of base error\n");
      return;
    }
    sum = sum * int_base + dec_dig;
    if (sum < 0) {
      token.val = 0;
      // TODO: warning()
      printf("Overflow error\n");
      return;
    }
    input++;
  }
  token.val = sum;
}

/*
The function sets the kind member of the global variable token to the fist token
found in the input string, if that token is a keyword or a special character.
If a blank character, an integer literal, an identifier or a non-DIL string is
encoutered, kind is set to UNDEFINED.
*/
void identify_token(const char *input) {
  // Skip whitespace
  while (ch_map[input[0]] & CM_BLANK)
    input++;

  switch (input[0]) {
  case 'b':
    if (input[1] == 'o' && input[2] == 'o' && input[3] == 'l' &&
        !(ch_map[input[4]] & CM_IDENTIFIER)) {
      token.kind = TOK::BOOL;
      return;
    }
    break;
  case 'e':
    if (input[1] == 'l' && input[2] == 's' && input[3] == 'e' &&
        !(ch_map[input[4]] & CM_IDENTIFIER)) {
      token.kind = TOK::ELSE;
      return;
    }
    break;
  case 'f':
    if (input[1] == 'a' && input[2] == 'l' && input[3] == 's' &&
        input[4] == 'e' && !(ch_map[input[5]] & CM_IDENTIFIER)) {
      token.kind = TOK::FALSE;
      return;
    }
    if (input[1] == 'u' && input[2] == 'n' && input[3] == 'c' &&
        !(ch_map[input[4]] & CM_IDENTIFIER)) {
      token.kind = TOK::FUNC;
      return;
    }
    break;
  case 'i':
    if (input[1] == 'f' && !(ch_map[input[2]] & CM_IDENTIFIER)) {
      token.kind = TOK::IF;
      return;
    }
    if (input[1] == 'n' && input[2] == 't' &&
        !(ch_map[input[3]] & CM_IDENTIFIER)) {
      token.kind = TOK::INT;
      return;
    }
    break;
  case 'n':
    if (input[1] == 'e' && input[2] == 'w' &&
        !(ch_map[input[3]] & CM_IDENTIFIER)) {
      token.kind = TOK::NEW;
      return;
    }
    break;
  case 'r':
    if (input[1] == 'e' && input[2] == 't' && input[3] == 'u' &&
        input[4] == 'r' && input[5] == 'n' &&
        !(ch_map[input[6]] & CM_IDENTIFIER)) {
      token.kind = TOK::RETURN;
      return;
    }
    break;
  case 's':
    if (input[1] == 't' && input[2] == 'r' && input[3] == 'u' &&
        input[4] == 'c' && input[5] == 't' &&
        !(ch_map[input[6]] & CM_IDENTIFIER)) {
      token.kind = TOK::STRUCT;
      return;
    }
    break;
  case 't':
    if (input[1] == 'r' && input[2] == 'u' && input[3] == 'e' &&
        !(ch_map[input[4]] & CM_IDENTIFIER)) {
      token.kind = TOK::TRUE;
      return;
    }
    break;
  case 'w':
    if (input[1] == 'h' && input[2] == 'i' && input[3] == 'l' &&
        input[4] == 'e' && !(ch_map[input[5]] & CM_IDENTIFIER)) {
      token.kind = TOK::WHILE;
      return;
    }
    break;
  case '=':
    if (input[1] == '=') {
      token.kind = TOK::EQ;
      return;
    }
    token.kind = TOK::ASSIGN;
    return;
  case '!':
    if (input[1] == '=') {
      token.kind = TOK::NEQ;
      return;
    }
    token.kind = TOK::NOT;
    return;
  case '>':
    if (input[1] == '=') {
      token.kind = TOK::GEQ;
      return;
    }
    token.kind = TOK::GT;
    return;
  case '<':
    if (input[1] == '=') {
      token.kind = TOK::LEQ;
      return;
    }
    token.kind = TOK::LT;
    return;
  case '&':
    if (input[1] == '&') {
      token.kind = TOK::AND_AND;
      return;
    }
    break;
  case '|':
    if (input[1] == '|') {
      token.kind = TOK::OR_OR;
      return;
    }
    break;
  case '+':
    token.kind = TOK::PLUS;
    return;
  case '-':
    token.kind = TOK::MINUS;
    return;
  case '*':
    token.kind = TOK::MUL;
    return;
  case '/':
    token.kind = TOK::DIV;
    return;
  case '%':
    token.kind = TOK::MOD;
    return;
  case ':':
    token.kind = TOK::COLON;
    return;
  case ',':
    token.kind = TOK::COMMA;
    return;
  case '[':
    token.kind = TOK::LBRACKET;
    return;
  case ']':
    token.kind = TOK::RBRACKET;
    return;
  case '(':
    token.kind = TOK::LPAR;
    return;
  case ')':
    token.kind = TOK::RPAR;
    return;
  case '{':
    token.kind = TOK::LBRACE;
    return;
  case '}':
    token.kind = TOK::RBRACE;
    return;
  case '.':
    token.kind = TOK::DOT;
    return;
  case ';':
    token.kind = TOK::SEMICOLON;
    return;
  case '0' ... '9':
    token.kind = TOK::INT_LIT;
    scan_int();
    if (*input == '.' || *input == 'e') {
      // TODO: warning()
      printf("Floating numbers are not supported.");
    }
    return;
  case '\0':
    token.kind = TOK::EOI;
    return;
  }
  token.kind = TOK::UNDEFINED;
}

void initialize_lexer(const char *_input) {
  input = _input;
  // characters allowed in identifiers
  for (int i = '0'; i <= '9'; ++i)
    ch_map[i] |= CM_IDENTIFIER;

  for (int i = 'a'; i <= 'z'; ++i) {
    ch_map[i] |= CM_IDENTIFIER;
    ch_map[toupper(i)] |= CM_IDENTIFIER;
  }
  ch_map['_'] |= CM_IDENTIFIER;

  ch_map[' '] |= CM_BLANK;
  ch_map['\n'] |= CM_BLANK;
  ch_map['\t'] |= CM_BLANK;

  // numericals
  for (int i = '0'; i <= '7'; ++i)
    ch_map[i] |= CM_OCT | CM_DEC | CM_HEX;

  for (int i = '8'; i <= '9'; ++i)
    ch_map[i] |= CM_DEC | CM_HEX;

  for (int i = 'a'; i <= 'f'; ++i) {
    ch_map[i] |= CM_HEX;
    ch_map[toupper(i)] |= CM_HEX;
  }

  init_digit_to_val();
};
