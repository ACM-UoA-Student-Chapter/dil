/*
 * Copyright:  Copyright Dimakopoulos Theodoros 2019
 * License:    $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
 * Authors:    Dimakopoulos Theodoros
 */
#pragma once

#include <cctype>
using std::toupper;
/*
The character-properties map array.
ch_map[c] is the properties of the character c.
The bits of ch_map[c] correspond to it's properties.

ch_map[c] & CM_DIL_CHAR
will be true if c is a DIL character (first bit ON).

ch_map[c] == CM_DIL_CHAR
will be true if only that (only first bit ON).

ch_map[c] == CM_DIL_CHAR | CM_DECIMAL
will be true if c is DIL and a decimal digit
(only therse two bits). To check for a decimal prefer 

ch_map[c] & CM_DECIMAL
because for example 4 is both octal and decimal,
so it's  CM_DIL_CHAR | CM_DECIMAL | CM_OCTAL
*/
// CM for 'C'haracter 'M'ap. This way we avoid namespaces.
enum CM_TYPE {
  CM_NO_PROPERTY = 0,
  CM_DIL_CHAR = 1,        // character allowed in DIL
  CM_BLANK = 1 << 2,      // space, new-line or tab
  CM_IDENTIFIER = 1 << 3, // if could be in an ident
  CM_OCTAL = 1 << 4,      // '0' to '7'
  CM_DECIMAL = 1 << 5,    // '0' to '9'
  CM_HEXADECIMAL = 1 << 6 // '0'-'9', 'a'-'f', 'A'-'F'
};

int ch_map[128] = {}; //     D E F I N I T I O N

// must be called early in runtime. Multiple calls are ok.
void initialize_map() {

  // most first characters are non-printable
  for (int i = 0; i < 32; ++i)
    ch_map[i] = CM_NO_PROPERTY;
  ch_map['\t'] = CM_DIL_CHAR;

  // most characters after 32 are DIL characters
  for (int i = 33; i < 127; ++i)
    ch_map[i] = CM_DIL_CHAR;
  ch_map['\n'] &= ~CM_DIL_CHAR; // this one isn't

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
