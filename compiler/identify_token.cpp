/*
 * Copyright: Copyright nsoul97 (Soulounias Nikolaos) 2019.
 * License:   $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
 * Authors:   nsoul97 (Soulounias Nikolaos)
 */

#include "identify_token.h"
#include "tokens.h"
#include <cstdint>
#include <ctype.h>

Token token;

uint8_t isIdChar[256];
uint8_t isBlankChar[256];
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
    The function intializes the isBlankChar array. If a character c:
    ---> is newline, space or tab character, then isBlankChar[c]=1
    ---> Otherwise, isBlankChar[c]=0
*/
void init_isBlankChar() {
  isBlankChar[' ']=1;
  isBlankChar['\t']=1;
  isBlankChar['\n']=1;
}

/*
The function sets the kind member of the global variable token to the fist token
found in the input string, if that token is a keyword or a special character.
If a blank character, an integer literal, an identifier or a non-DIL string is
encoutered, kind is set to UNDEFINED.
*/
void identify_token(const char *input) {
  int ind=0;
  while (isBlankChar[input[ind]])
    ind++;
  switch (input[ind]) {
  case 'b':
    if (input[ind+1] == 'o' && input[ind+2] == 'o' && input[ind+3] == 'l' &&
        !isIdChar[input[ind+4]]) {
      token.kind = TOK::BOOL;
      return;
    }
    break;
  case 'e':
    if (input[ind+1] == 'l' && input[ind+2] == 's' && input[ind+3] == 'e' &&
        !isIdChar[input[ind+4]]) {
      token.kind = TOK::ELSE;
      return;
    }
    break;
  case 'f':
    if (input[ind+1] == 'a' && input[ind+2] == 'l' && input[ind+3] == 's' &&
        input[ind+4] == 'e' && !isIdChar[input[ind+5]]) {
      token.kind = TOK::FALSE;
      return;
    }
    if (input[ind+1] == 'u' && input[ind+2] == 'n' && input[ind+3] == 'c' &&
        !isIdChar[input[ind+4]]) {
      token.kind = TOK::FUNC;
      return;
    }
    break;
  case 'i':
    if (input[ind+1] == 'f' && !isIdChar[input[ind+2]]) {
      token.kind = TOK::IF;
      return;
    }
    if (input[ind+1] == 'n' && input[ind+2] == 't' && !isIdChar[input[ind+3]]) {
      token.kind = TOK::INT;
      return;
    }
    break;
  case 'n':
    if (input[ind+1] == 'e' && input[ind+2] == 'w' && !isIdChar[input[ind+3]]) {
      token.kind = TOK::NEW;
      return;
    }
    break;
  case 'r':
    if (input[ind+1] == 'e' && input[ind+2] == 't' && input[ind+3] == 'u' &&
        input[ind+4] == 'r' && input[ind+5] == 'n' && !isIdChar[input[ind+6]]) {
      token.kind = TOK::RETURN;
      return;
    }
    break;
  case 's':
    if (input[ind+1] == 't' && input[ind+2] == 'r' && input[ind+3] == 'u' &&
        input[ind+4] == 'c' && input[ind+5] == 't' && !isIdChar[input[ind+6]]) {
      token.kind = TOK::STRUCT;
      return;
    }
    break;
  case 't':
    if (input[ind+1] == 'r' && input[ind+2] == 'u' && input[ind+3] == 'e' &&
        !isIdChar[input[ind+4]]) {
      token.kind = TOK::TRUE;
      return;
    }
    break;
  case 'w':
    if (input[ind+1] == 'h' && input[ind+2] == 'i' && input[ind+3] == 'l' &&
        input[ind+4] == 'e' && !isIdChar[input[ind+5]]) {
      token.kind = TOK::WHILE;
      return;
    }
    break;
  case '=':
    if (input[ind+1] == '=') {
      token.kind = TOK::EQ;
      return;
    }
    token.kind = TOK::ASSIGN;
    return;
  case '!':
    if (input[ind+1] == '=') {
      token.kind = TOK::NEQ;
      return;
    }
    token.kind = TOK::NOT;
    return;
  case '>':
    if (input[ind+1] == '=') {
      token.kind = TOK::GEQ;
      return;
    }
    token.kind = TOK::GT;
    return;
  case '<':
    if (input[ind+1] == '=') {
      token.kind = TOK::LEQ;
      return;
    }
    token.kind = TOK::LT;
    return;
  case '&':
    if (input[ind+1] == '&') {
      token.kind = TOK::AND_AND;
      return;
    }
    break;
  case '|':
    if (input[ind+1] == '|') {
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
  case '\0':
    token.kind = TOK::EOI;
    return;
  }
  token.kind = TOK::UNDEFINED;
}
