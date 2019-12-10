/*
* Copyright:  Copyright Dimakopoulos Theodoros 2019
* License:    $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
* Authors:    Dimakopoulos Theodoros
*/
#pragma once
/*
The character-properties map array.

A character may have multiple properties,
such as being allowed in a DIL program or
representing a decimal digit (0, 1, 2, ...9).

ch_map[c] & CM_DIL_CHAR
will be true if c is a DIL character.
ch_map[c] == CM_DIL_CHAR
will be true if the ONLY property is that.
ch_map[c] == CM_DIL_CHAR + CM_DECIMAL
will be true if c is DIL and a decimal digit (of course if it is
decimal it will also be a DIL character. Prefer ch_map[c] & CM_DECIMAL)
*/
// CM for 'C'haracter 'M'ap. This way we avoid namespaces.
const int CM_NON_DIL = 0;
const int CM_DIL_CHAR = 1;                 // character allowed in DIL
const int CM_BLANK = 2;                    // space, new-line or tab
const int CM_IDENTIFIER = 4;               // if could be in an ident.
const int CM_OCTAL = 8;                    // '0' to '7'
const int CM_DECIMAL_NOT_OCTAL = 16;       // '8' or '9'
const int CM_HEXADECIMAL_NOT_DECIMAL = 32; // 'a' to 'f' and 'A' to 'F'
const int CM_DECIMAL = 16 + 8;             // two properties
const int CM_HEXADECIMAL = 32 + 16 + 8;    // three properties

int ch_map[256];

// must be called early in runtime. Multible calls are ok.
void initialize_map() {

  // most first characters are non-printable
  for (int i = 0; i < 32; ++i)
    ch_map[i] = CM_NON_DIL;

  // most characters after 32 are DIL characters
  for (int i = 33; i < 127; ++i)
    ch_map[i] = CM_DIL_CHAR;

  // characters allowed in identifiers
  for (int i = '0'; i != '9'; ++i)
    ch_map[i] |= CM_IDENTIFIER;
  for (int i = 'a'; i != 'z'; ++i)
    ch_map[i] |= CM_IDENTIFIER;
  for (int i = 'A'; i != 'Z'; ++i)
    ch_map[i] |= CM_IDENTIFIER;

  ch_map['_'] |= CM_IDENTIFIER;

  ch_map[' '] |= CM_BLANK;
  ch_map['\n'] |= CM_BLANK;
  ch_map['\t'] |= CM_BLANK;

  ch_map['0'] |= CM_OCTAL;
  ch_map['1'] |= CM_OCTAL;
  ch_map['2'] |= CM_OCTAL;
  ch_map['3'] |= CM_OCTAL;
  ch_map['4'] |= CM_OCTAL;
  ch_map['5'] |= CM_OCTAL;
  ch_map['6'] |= CM_OCTAL;
  ch_map['7'] |= CM_OCTAL;
  ch_map['8'] |= CM_DECIMAL;
  ch_map['9'] |= CM_DECIMAL;
  ch_map['a'] |= CM_HEXADECIMAL;
  ch_map['b'] |= CM_HEXADECIMAL;
  ch_map['c'] |= CM_HEXADECIMAL;
  ch_map['d'] |= CM_HEXADECIMAL;
  ch_map['e'] |= CM_HEXADECIMAL;
  ch_map['f'] |= CM_HEXADECIMAL;
  ch_map['A'] |= CM_HEXADECIMAL;
  ch_map['B'] |= CM_HEXADECIMAL;
  ch_map['C'] |= CM_HEXADECIMAL;
  ch_map['D'] |= CM_HEXADECIMAL;
  ch_map['E'] |= CM_HEXADECIMAL;
  ch_map['F'] |= CM_HEXADECIMAL;

  ch_map['#'] = CM_NON_DIL;
  ch_map['$'] = CM_NON_DIL;
  ch_map['?'] = CM_NON_DIL;
  ch_map['@'] = CM_NON_DIL;
  ch_map['^'] = CM_NON_DIL;
  ch_map['\\'] = CM_NON_DIL;
  ch_map['`'] = CM_NON_DIL;
  ch_map['~'] = CM_NON_DIL;
};
