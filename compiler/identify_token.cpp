/*
 * Copyright: Copyright nsoul97 (Soulounias Nikolaos) 2019.
 * License:   $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
 * Authors:   nsoul97 (Soulounias Nikolaos)
 */

#include <cstdint>
#include <cstdio>
#include <ctype.h>

uint8_t isIdChar[256];
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
      printf("bool\n");
      return;
    }
    break;
  case 'e':
    if (input[1] == 'l' && input[2] == 's' && input[3] == 'e' &&
        !isIdChar[input[4]]) {
      printf("else\n");
      return;
    }
    break;
  case 'f':
    if (input[1] == 'a' && input[2] == 'l' && input[3] == 's' &&
        input[4] == 'e' && !isIdChar[input[5]]) {
      printf("false\n");
      return;
    }
    if (input[1] == 'u' && input[2] == 'n' && input[3] == 'c' &&
        !isIdChar[input[4]]) {
      printf("func\n");
      return;
    }
    break;
  case 'i':
    if (input[1] == 'f' && !isIdChar[input[2]]) {
      printf("if\n");
      return;
    }
    if (input[1] == 'n' && input[2] == 't' && !isIdChar[input[3]]) {
      printf("int\n");
      return;
    }
    break;
  case 'n':
    if (input[1] == 'e' && input[2] == 'w' && !isIdChar[input[3]]) {
      printf("new\n");
      return;
    }
    break;
  case 'r':
    if (input[1] == 'e' && input[2] == 't' && input[3] == 'u' &&
        input[4] == 'r' && input[5] == 'n' && !isIdChar[input[6]]) {
      printf("return\n");
      return;
    }
    break;
  case 's':
    if (input[1] == 't' && input[2] == 'r' && input[3] == 'u' &&
        input[4] == 'c' && input[5] == 't' && !isIdChar[input[6]]) {
      printf("struct\n");
      return;
    }
    break;
  case 't':
    if (input[1] == 'r' && input[2] == 'u' && input[3] == 'e' &&
        !isIdChar[input[4]]) {
      printf("true\n");
      return;
    }
    break;
  case 'w':
    if (input[1] == 'h' && input[2] == 'i' && input[3] == 'l' &&
        input[4] == 'e' && !isIdChar[input[5]]) {
      printf("while\n");
      return;
    }
    break;
  case '=':
    if (input[1] == '=') {
      printf("==\n");
      return;
    }
    printf("=\n");
    return;
  case '!':
    if (input[1] == '=') {
      printf("!=\n");
      return;
    }
    printf("!\n");
    return;
  case '>':
    if (input[1] == '=') {
      printf(">=\n");
      return;
    }
    printf(">\n");
    return;
  case '<':
    if (input[1] == '=') {
      printf("<=\n");
      return;
    }
    printf("<\n");
    return;
  case '&':
    if (input[1] == '&') {
      printf("&&\n");
      return;
    }
    break;
  case '|':
    if (input[1] == '|') {
      printf("||\n");
      return;
    }
    break;
  case '+':
  case '-':
  case '*':
  case '/':
  case '%':
  case ':':
  case ',':
  case '[':
  case ']':
  case '(':
  case ')':
  case '{':
  case '}':
  case '.':
  case ';':
    printf("%c\n", input[0]);
    return;
  case '\0':
    printf("EOI token\n");
    return;
  }
  printf("Not a keyword token\n");
}
