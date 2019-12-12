/*
 * Copyright: Copyright nsoul97 (Soulounias Nikolaos) 2019.
 * License:   $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
 * Authors:   nsoul97 (Soulounias Nikolaos)
 */

#ifndef __IDENTIFY_TOKEN_H
#define __IDENTIFY_TOKEN_H

#include "tokens.h"

struct Token {
  TOK kind;
};

void init_isIdChar();
void identify_token(const char *input);
void init_isBlankChar();

#endif
