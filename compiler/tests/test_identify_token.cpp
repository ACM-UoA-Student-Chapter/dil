/*
 * Copyright: Copyright nsoul97 (Soulounias Nikolaos) 2019.
 * License:   $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
 * Authors:   nsoul97 (Soulounias Nikolaos)
 */

#include "../identify_token.h"
#include "../token_name.h"
#include "../tokens.h"
#include <cassert>
#include <cstdio>

extern Token token;

/*
If the global variable token has its kind member set to the expected_enum, the
function prints a success message. Otherwise, the program execution stops due to
the assertion.
*/
static void test(const char *input, TOK expected_enum) {
  identify_token(input);
  assert(token.kind == expected_enum);
  if (expected_enum != TOK::UNDEFINED)
    printf("SUCCESS: function identify_token(\"%s\") sets token's kind member "
           "to %s token.\n",
           input, token_name(expected_enum));
  else
    printf(
        "SUCCESS: function identify_token(\"%s\") sets token's kind member to "
        "UNDEFINED token.\n\t \"%s\" starts with an integer literal, an "
        "identifier, a blank character or a non-DIL string.\n",
        input, input);
}

/*
This function is used for testing various input strings as arguments of the
identify_token function.
*/
int main(void) {
  init_isIdChar();
  init_isBlankChar();

  test("", TOK::EOI);
  test("int i;", TOK::INT);
  test("bool var;", TOK::BOOL);
  test("struct Student;", TOK::STRUCT);
  test("new int[5];", TOK::NEW);
  test("func swap(arr : int[], i, j : int)", TOK::FUNC);
  test("if (x>10)", TOK::IF);
  test("else{", TOK::ELSE);
  test("return x;", TOK::RETURN);
  test("while (i<10)", TOK::WHILE);
  test("false || true", TOK::FALSE);
  test("true||false", TOK::TRUE);

  test("01210 + 100", TOK::UNDEFINED);
  test("var_name", TOK::UNDEFINED);
  test("intvar", TOK::UNDEFINED);
  test("function", TOK::UNDEFINED);

  test(" int x;", TOK::INT);
  test("\t+10;", TOK::PLUS);
  test("\nbool b;", TOK::BOOL);
  test("\t\n\t\t   while (true) ", TOK::WHILE);

  test("== 10", TOK::EQ);
  test("==10", TOK::EQ);

  test("!= 07", TOK::NEQ);
  test("!= 07", TOK::NEQ);

  test(">_var", TOK::GT);
  test("> -12", TOK::GT);

  test(">=_var", TOK::GEQ);
  test(">=-12", TOK::GEQ);

  test("<_var", TOK::LT);
  test("< -12", TOK::LT);

  test("<=_var", TOK::LEQ);
  test("<= -12", TOK::LEQ);

  test("! true", TOK::NOT);
  test("!boolvar", TOK::NOT);

  test("+ 120", TOK::PLUS);
  test("+120", TOK::PLUS);

  test("- 0230", TOK::MINUS);
  test("-0230", TOK::MINUS);

  test("* 0X1021", TOK::MUL);
  test("*0X1021", TOK::MUL);

  test("/ 0xff10", TOK::DIV);
  test("/0xff10", TOK::DIV);

  test("% 10", TOK::MOD);
  test("%10", TOK::MOD);

  test("&& x==10", TOK::AND_AND);
  test("&&x==10", TOK::AND_AND);
  test("& x==10", TOK::UNDEFINED);
  test("&x==10", TOK::UNDEFINED);

  test("|| x==10", TOK::OR_OR);
  test("||x==10", TOK::OR_OR);
  test("| x==10", TOK::UNDEFINED);
  test("|x==10", TOK::UNDEFINED);

  test(":int", TOK::COLON);
  test(": bool", TOK::COLON);

  test(", x , y;", TOK::COMMA);
  test(",x,y;", TOK::COMMA);

  test("[5]", TOK::LBRACKET);
  test("[ 5 ]", TOK::LBRACKET);
  test("] ", TOK::RBRACKET);
  test("]", TOK::RBRACKET);

  test("(5)", TOK::LPAR);
  test("( 5 )", TOK::LPAR);
  test(") ", TOK::RPAR);
  test(")", TOK::RPAR);

  test("{\treturn 5; }", TOK::LBRACE);
  test("{return 5;}", TOK::LBRACE);
  test("} ", TOK::RBRACE);
  test("}", TOK::RBRACE);

  test(".kind", TOK::DOT);
  test(";", TOK::SEMICOLON);
  return 0;
}
