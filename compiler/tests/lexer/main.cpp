/*
 * Copyright: Copyright nsoul97 (Soulounias Nikolaos) 2019.
 * License:   $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
 * Authors:   nsoul97 (Soulounias Nikolaos)
 */

#include "../../tokens.h"
#include "../../lex.h"
#include <cassert>
#include <cstdio>

extern Token token;

/*
If the global variable token doesn't have its kind member set to the
expected_enum, the macto TEST function stops the program execution stops due to
the assertion.
*/
#define TEST(input_string, expected_enum)                                      \
  {                                                                            \
    identify_token(input_string);                                              \
    assert(token.kind == expected_enum);                                       \
  }

/*
This function is used for testing various input strings as arguments of the
identify_token function.
*/
int main(void) {
  initialize_lexer();

  TEST("", TOK::EOI);
  TEST("int i;", TOK::INT);
  TEST("bool var;", TOK::BOOL);
  TEST("struct Student;", TOK::STRUCT);
  TEST("new int[5];", TOK::NEW);
  TEST("func swap(arr : int[], i, j : int)", TOK::FUNC);
  TEST("if (x>10)", TOK::IF);
  TEST("else{", TOK::ELSE);
  TEST("return x;", TOK::RETURN);
  TEST("while (i<10)", TOK::WHILE);
  TEST("false || true", TOK::FALSE);
  TEST("true||false", TOK::TRUE);

  TEST("01210 + 100", TOK::UNDEFINED);
  TEST("var_name", TOK::UNDEFINED);
  TEST("intvar", TOK::UNDEFINED);
  TEST("function", TOK::UNDEFINED);

  TEST(" int x;", TOK::INT);
  TEST("\t+10;", TOK::PLUS);
  TEST("\nbool b;", TOK::BOOL);
  TEST("\t\n\t\t   while (true) ", TOK::WHILE);

  TEST("== 10", TOK::EQ);
  TEST("==10", TOK::EQ);

  TEST("!= 07", TOK::NEQ);
  TEST("!= 07", TOK::NEQ);

  TEST(">_var", TOK::GT);
  TEST("> -12", TOK::GT);

  TEST(">=_var", TOK::GEQ);
  TEST(">=-12", TOK::GEQ);

  TEST("<_var", TOK::LT);
  TEST("< -12", TOK::LT);

  TEST("<=_var", TOK::LEQ);
  TEST("<= -12", TOK::LEQ);

  TEST("! true", TOK::NOT);
  TEST("!boolvar", TOK::NOT);

  TEST("+ 120", TOK::PLUS);
  TEST("+120", TOK::PLUS);

  TEST("- 0230", TOK::MINUS);
  TEST("-0230", TOK::MINUS);

  TEST("* 0X1021", TOK::MUL);
  TEST("*0X1021", TOK::MUL);

  TEST("/ 0xff10", TOK::DIV);
  TEST("/0xff10", TOK::DIV);

  TEST("% 10", TOK::MOD);
  TEST("%10", TOK::MOD);

  TEST("&& x==10", TOK::AND_AND);
  TEST("&&x==10", TOK::AND_AND);
  TEST("& x==10", TOK::UNDEFINED);
  TEST("&x==10", TOK::UNDEFINED);

  TEST("|| x==10", TOK::OR_OR);
  TEST("||x==10", TOK::OR_OR);
  TEST("| x==10", TOK::UNDEFINED);
  TEST("|x==10", TOK::UNDEFINED);

  TEST(":int", TOK::COLON);
  TEST(": bool", TOK::COLON);

  TEST(", x , y;", TOK::COMMA);
  TEST(",x,y;", TOK::COMMA);

  TEST("[5]", TOK::LBRACKET);
  TEST("[ 5 ]", TOK::LBRACKET);
  TEST("] ", TOK::RBRACKET);
  TEST("]", TOK::RBRACKET);

  TEST("(5)", TOK::LPAR);
  TEST("( 5 )", TOK::LPAR);
  TEST(") ", TOK::RPAR);
  TEST(")", TOK::RPAR);

  TEST("{\treturn 5; }", TOK::LBRACE);
  TEST("{return 5;}", TOK::LBRACE);
  TEST("} ", TOK::RBRACE);
  TEST("}", TOK::RBRACE);

  TEST(".kind", TOK::DOT);
  TEST(";", TOK::SEMICOLON);
  return 0;
}
