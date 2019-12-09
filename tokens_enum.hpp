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
  UNDEFINED,   // token of undefined kind (i.e. error)
  EOI,         // end of input
  INT_LIT,     // integer literal
  MAIN,        // main keyword
  INT,         // int keyword
  BOOL,        // bool keyword
  FUNCTION,    // func keyword
  RETURN,      // return keyword
  IF,          // if keyword
  WHILE,       // while keyword
  FALSE,       // false keyword
  TRUE,        // true keyword
  NEW,         // new keyword
  PLUS,        // + operator
  MINUS,       // - operator
  MULT,        // * operator
  DIV,         // / operator
  MOD,         // % operator
  ASSIGN,      // = operator
  EQUAL,       // == operator
  UNEQUAL,     // != operator
  GREATER,     // > operator
  GREQ,        // >= operator
  LESS,        // < operator
  LEQ,         // <= operator
  COLON,       // : token
  COMMA,       // , token
  ID,          // function (e.g. quicksort) or variable (e.g. len) identifiers
  START_ARRAY, // [ token
  END_ARRAY,   // ] token
  START_PAREN, // ( token
  END_PAREN,   // ) token
  START_SCOPE, // { token
  END_SCOPE,   // } token
  SEMICOLON    // ; token
};

#endif
