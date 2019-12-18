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

ch_map[c] & CM_DECIMAL
will be true if c is a decimal digit.

ch_map[c] == CM_DECIMAL
will be true if the ONLY property of c is that it's
decimal. Use the '==' with great caution!

ch_map[c] & (CM_BLANK | CM_DECIMAL)
will be true if c is either a blank character or a
decimal digit.
*/
// CM for 'C'haracter 'M'ap
enum CM_TYPE {
  CM_NO_PROPERTY = 0,
  CM_BLANK = 1,           // space, new-line or tab
  CM_IDENTIFIER = 1 << 1, // if could be in an ident
  CM_OCTAL = 1 << 2,      // '0' to '7'
  CM_DECIMAL = 1 << 3,    // '0' to '9'
  CM_HEXADECIMAL = 1 << 4 // '0'-'9', 'a'-'f', 'A'-'F'
};
extern int ch_map[128];

// must be called early in runtime. Multiple calls are ok.
void initialize_map();