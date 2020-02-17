/*
 * Copyright: Copyright nsoul97 (Soulounias Nikolaos) 2019.
 * License:   $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
 * Authors:   nsoul97 (Soulounias Nikolaos)
 */

#include "../../lex.h"
#include "../../tokens.h"
#include <cassert>
#include <cstdio>

extern Token token;

/*
If the global variable token doesn't have its kind member set to the
expected_enum, the macto TEST function stops the program execution stops due to
the assertion.
*/
#define TEST(input_string, expected_kind)                                      \
  {                                                                            \
    initialize_lexer(input_string);                                            \
    identify_token(input_string);                                              \
    assert(token.kind == expected_kind);                                       \
  }

#define TEST_INT(input_string, expected_val)                                   \
  {                                                                            \
    initialize_lexer(input_string);                                            \
    identify_token(input_string);                                              \
    assert(token.kind == TOK::INT_LIT);                                        \
    assert(token.val == expected_val);                                         \
  }

/*
This function is used for testing various input strings as arguments of the
identify_token function.
*/
int main(void) {
  TEST_INT("123", 123);
  TEST_INT("0", 0);
  TEST_INT("0x0", 0);
  TEST_INT("0x234", 0x234);
  TEST_INT("0X234", 0X234);
  TEST_INT("0XADF", 0XADF);
  TEST_INT("0234", 0234);
  TEST_INT("2147483647", 2147483647);
  TEST_INT("0x7fffffff", 0x7fffffff);
  // Overflow error
  TEST_INT("0xffffffff", 0);
  TEST_INT("22384623846", 0);
  // Out of base
  TEST_INT("12a", 0);
  TEST_INT("0182", 0);
  // Invalid hex literal
  TEST_INT("0x", 0);
  TEST_INT("0xg", 0);
  // Invalid octal literal
  TEST_INT("0a", 0);

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
