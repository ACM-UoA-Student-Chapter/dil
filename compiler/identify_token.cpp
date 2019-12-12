/*
 * Copyright: Copyright nsoul97 (Soulounias Nikolaos) 2019.
 * License:   $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
 * Authors:   nsoul97 (Soulounias Nikolaos)
 */

#include <cstdint>
#include <ctype.h>
#include "identify_token.h"
#include "tokens.h"

Token token;

uint8_t isIdChar[256];
/*
    The function intializes the isIdChar array. If a character c:
    ---> CAN be part of an identifier, then isIdChar[c]=1
    ---> CANNOT be part of an identifier, the isIdChar[c]=0
*/
void init_isIdChar() {
  for (int c = 'A'; c <= 'Z'; c++) {
    isIdChar[c] = 1;
    isIdChar[tolower(c)] = 1;
  }
  for (int c = '0'; c <= '9'; c++)
    isIdChar[c] = 1;
  isIdChar['_'] = 1;
}

/*
The function prints the fist token found in the input string, if that token is a
keyword or a special character. If an integer literal or an identifier is
encoutered, a "Not a keyword token" message is printed .
*/
void identify_token(const char *input) {
  switch (input[0]) {
  case 'b':
    if (input[1] == 'o' && input[2] == 'o' && input[3] == 'l' &&
        !isIdChar[input[4]]) {
      token.kind=TOK::BOOL;
      return;
    }
    break;
  case 'e':
    if (input[1] == 'l' && input[2] == 's' && input[3] == 'e' &&
        !isIdChar[input[4]]) {
      token.kind=TOK::ELSE;
      return;
    }
    break;
  case 'f':
    if (input[1] == 'a' && input[2] == 'l' && input[3] == 's' &&
        input[4] == 'e' && !isIdChar[input[5]]) {
      token.kind=TOK::FALSE;
      return;
    }
    if (input[1] == 'u' && input[2] == 'n' && input[3] == 'c' &&
        !isIdChar[input[4]]) {
      token.kind=TOK::FUNC;
      return;
    }
    break;
  case 'i':
    if (input[1] == 'f' && !isIdChar[input[2]]) {
      token.kind=TOK::IF;
      return;
    }
    if (input[1] == 'n' && input[2] == 't' && !isIdChar[input[3]]) {
      token.kind=TOK::INT;
      return;
    }
    break;
  case 'n':
    if (input[1] == 'e' && input[2] == 'w' && !isIdChar[input[3]]) {
      token.kind=TOK::NEW;
      return;
    }
    break;
  case 'r':
    if (input[1] == 'e' && input[2] == 't' && input[3] == 'u' &&
        input[4] == 'r' && input[5] == 'n' && !isIdChar[input[6]]) {
      token.kind=TOK::RETURN;
      return;
    }
    break;
  case 's':
    if (input[1] == 't' && input[2] == 'r' && input[3] == 'u' &&
        input[4] == 'c' && input[5] == 't' && !isIdChar[input[6]]) {
      token.kind=TOK::STRUCT;
      return;
    }
    break;
  case 't':
    if (input[1] == 'r' && input[2] == 'u' && input[3] == 'e' &&
        !isIdChar[input[4]]) {
      token.kind=TOK::TRUE;
      return;
    }
    break;
  case 'w':
    if (input[1] == 'h' && input[2] == 'i' && input[3] == 'l' &&
        input[4] == 'e' && !isIdChar[input[5]]) {
      token.kind=TOK::WHILE;
      return;
    }
    break;
  case '=':
    if (input[1] == '=') {
      token.kind=TOK::EQ;
      return;
    }
    token.kind=TOK::ASSIGN;
    return;
  case '!':
    if (input[1] == '=') {
      token.kind=TOK::NEQ;
      return;
    }
    token.kind=TOK::NOT;
    return;
  case '>':
    if (input[1] == '=') {
      token.kind=TOK::GEQ;
      return;
    }
    token.kind=TOK::GT;
    return;
  case '<':
    if (input[1] == '=') {
      token.kind=TOK::LEQ;
      return;
    }
    token.kind=TOK::LT;
    return;
  case '&':
    if (input[1] == '&') {
      token.kind=TOK::AND_AND;
      return;
    }
    break;
  case '|':
    if (input[1] == '|') {
      token.kind=TOK::OR_OR;
      return;
    }
    break;
  case '+':
    token.kind=TOK::PLUS;
    return;
  case '-':
    token.kind=TOK::MINUS;
    return;
  case '*':
    token.kind=TOK::MUL;
    return;
  case '/':
    token.kind=TOK::DIV;
    return;
  case '%':
    token.kind=TOK::MOD;
    return;
  case ':':
    token.kind=TOK::COLON;
    return;
  case ',':
    token.kind=TOK::COMMA;
    return;
  case '[':
    token.kind=TOK::LBRACKET;
    return;
  case ']':
    token.kind=TOK::RBRACKET;
    return;
  case '(':
    token.kind=TOK::LPAR;
    return;
  case ')':
    token.kind=TOK::RPAR;
    return;
  case '{':
    token.kind=TOK::LBRACE;
    return;
  case '}':
    token.kind=TOK::RBRACE;
    return;
  case '.':
    token.kind=TOK::DOT;
    return;
  case ';':
    token.kind=TOK::SEMICOLON;
    return;
  case '\0':
    token.kind=TOK::EOI;
    return;
  }
  token.kind=TOK::UNDEFINED;
}
