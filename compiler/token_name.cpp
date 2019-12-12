/*
 * Copyright: Copyright nsoul97 (Soulounias Nikolaos) 2019.
 * License:   $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
 * Authors:   nsoul97 (Soulounias Nikolaos)
 */

#include "token_name.h"
#include "tokens.h"
#include <cassert>

/*
The function returns the name of the token that corresponds to the enumeration
which is passed as argument.
*/
const char *token_name(TOK kind) {
  switch (kind) {
  case TOK::EOI:
    return "end of input";
  case TOK::INT_LIT:
    return "integer literal";
  case TOK::INT:
    return "int keyword";
  case TOK::STRUCT:
    return "struct keyword";
  case TOK::BOOL:
    return "bool keyword";
  case TOK::FUNC:
    return "func keyword";
  case TOK::RETURN:
    return "return keyword";
  case TOK::IF:
    return "if keyword";
  case TOK::ELSE:
    return "else keyword";
  case TOK::WHILE:
    return "while keyword";
  case TOK::FALSE:
    return "false keyword";
  case TOK::TRUE:
    return "true keyword";
  case TOK::NEW:
    return "new keyword";
  case TOK::PLUS:
    return "plus operator \'+\'";
  case TOK::MINUS:
    return "minus operator \'-\'";
  case TOK::MUL:
    return "multiplication operator \'*\'";
  case TOK::DIV:
    return "division operator \'/\'";
  case TOK::MOD:
    return "modulo operator \'%\'";
  case TOK::ASSIGN:
    return "assignment operator \'=\'";
  case TOK::EQ:
    return "equality operator \'=\'";
  case TOK::NEQ:
    return "inequality operator \'!\'";
  case TOK::GT:
    return "greater than operator \'>\'";
  case TOK::GEQ:
    return "greater or equal operator \'>\'";
  case TOK::LT:
    return "less than operator \'<\'";
  case TOK::LEQ:
    return "less or equal operator \'<\'";
  case TOK::NOT:
    return "logical NOT operator \'!\'";
  case TOK::AND_AND:
    return "logical AND operator \'&&\'";
  case TOK::OR_OR:
    return "logical OR operator \'||\'";
  case TOK::COLON:
    return "colon \':\'";
  case TOK::COMMA:
    return "comma \',\'";
  case TOK::ID:
    return "identifier";
  case TOK::LBRACKET:
    return "left bracket \'[\'";
  case TOK::RBRACKET:
    return "right bracket \']\'";
  case TOK::LPAR:
    return "left parenthesis \'(\'";
  case TOK::RPAR:
    return "right parenthesis \')\'";
  case TOK::LBRACE:
    return "left brace \'{\'";
  case TOK::RBRACE:
    return "right brace \'}\'";
  case TOK::DOT:
    return "dot \'.\'";
  case TOK::SEMICOLON:
    return "semicolon \';\'";
  default:
    assert(0);
  }
  assert(0);
}
