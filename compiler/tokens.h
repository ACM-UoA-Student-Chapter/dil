/*
 * Copyright: Copyright nsoul97 (Soulounias Nikolaos) 2019.
 * License:   $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
 * Authors:   nsoul97 (Soulounias Nikolaos)
 */

#ifndef __TOK_ENUMS_HPP
#define __TOK_ENUMS_HPP

/*
Enum class TOK is used to help identify the tokens of DIL language.
Since this is an enum class, enumerator names are local to the TOK enum.
Therefore to use an enumerator name we have to use the scope resolution
operator. e.g. TOK::UNDEFINED
*/
enum class TOK {
  UNDEFINED, // token of undefined kind (i.e. error)
  EOI,       // end of input
  INT_LIT,   // integer literal
  INT,       // int keyword
  STRUCT,    // struct keyword
  BOOL,      // bool keyword
  FUNC,      // func keyword
  RETURN,    // return keyword
  IF,        // if keyword
  ELSE,      // else keyword
  WHILE,     // while keyword
  FALSE,     // false keyword
  TRUE,      // true keyword
  NEW,       // new keyword
  PLUS,      // + operator
  MINUS,     // - operator
  MUL,       // * operator
  DIV,       // / operator
  MOD,       // % operator
  ASSIGN,    // = operator
  EQ,        // == operator
  NEQ,       // != operator
  GT,        // > operator
  GEQ,       // >= operator
  LT,        // < operator
  LEQ,       // <= operator
  NOT,       // ! operator
  AND_AND,   // && operator
  OR_OR,     // || operator
  COLON,     // : token
  COMMA,     // , token
  ID,        // function (e.g. quicksort) or variable (e.g. len) identifiers
  LBRACKET,  // [ token
  RBRACKET,  // ] token
  LPAR,      // ( token
  RPAR,      // ) token
  LBRACE,    // { token
  RBRACE,    // } token
  DOT,       // . token
  SEMICOLON  // ; token
};

const char *token_name(TOK kind);

#endif
