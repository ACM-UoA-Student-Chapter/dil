/*
 * Copyright: Copyright nsoul97 (Soulounias Nikolaos) 2019.
 * License:   $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
 * Authors:   nsoul97 (Soulounias Nikolaos)
 */

#include "identify_token.h"
#include "character_map.h"
#include "tokens.h"
#include <cstdint>
#include <ctype.h>

Token token;

/*
The function sets the kind member of the global variable token to the fist token
found in the input string, if that token is a keyword or a special character.
If a blank character, an integer literal, an identifier or a non-DIL string is
encoutered, kind is set to UNDEFINED.
*/
void identify_token(const char *input) {
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
  case '\0':
    token.kind = TOK::EOI;
    return;
  }
  token.kind = TOK::UNDEFINED;
}
