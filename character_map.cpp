/*
 * Copyright:  Copyright Dimakopoulos Theodoros 2019
 * License:    $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
 * Authors:    Dimakopoulos Theodoros
 */
#include "character_map.h"

int ch_map[128] = {};

void initialize_map() {

  // characters allowed in identifiers
  for (int i = '0'; i <= '9'; ++i)
    ch_map[i] |= CM_IDENTIFIER;

  for (int i = 'a'; i <= 'z'; ++i) {
    ch_map[i] |= CM_IDENTIFIER;
    ch_map[toupper(i)] |= CM_IDENTIFIER;
  }
  ch_map['_'] |= CM_IDENTIFIER;

  ch_map[' '] |= CM_BLANK;
  ch_map['\n'] |= CM_BLANK;
  ch_map['\t'] |= CM_BLANK;

  // numericals
  for (int i = '0'; i <= '7'; ++i)
    ch_map[i] |= CM_OCTAL | CM_DECIMAL | CM_HEXADECIMAL;

  for (int i = '8'; i <= '9'; ++i)
    ch_map[i] |= CM_DECIMAL | CM_HEXADECIMAL;

  for (int i = 'a'; i <= 'f'; ++i) {
    ch_map[i] |= CM_HEXADECIMAL;
    ch_map[toupper(i)] |= CM_HEXADECIMAL;
  }
};