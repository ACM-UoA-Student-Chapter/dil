/*
 * Copyright:  Copyright Dimakopoulos Theodoros 2019
 * License:    $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
 * Authors:    Dimakopoulos Theodoros
 */
#include "character_map.h"
#include "character_map_tester.h"

#include <cctype>
using std::tolower;

#include <assert.h>
 


void ch_map_tester() {

  // sacrificing speed for rigidity.
  for (char c = 0; c < 127; ++c) {
    char lc = tolower(c);

    // "'0' <= c <= '9'" must be as true as "c being decimal"
    assert(('0' <= lc && lc <= '9') == (bool)(ch_map[c] & CM_DECIMAL));
    assert(('0' <= lc && lc <= '7') == (bool)(ch_map[c] & CM_OCTAL));
    assert(('a' <= lc && lc <= 'f' || '0' <= lc && lc <= '9') ==
           (bool)(ch_map[c] & CM_HEXADECIMAL));

    bool is_ident = false; // is c an identifier character?
    if ('0' <= lc && lc <= '9')
      is_ident = true;
    if ('a' <= lc && lc <= 'z')
      is_ident = true;
    if (lc == '_')
      is_ident = true;

    assert(is_ident == (bool)(ch_map[c] & CM_IDENTIFIER));

    // blank characters
    assert((c == ' ' || c == '\t' || c == '\n') ==
           (bool)(ch_map[c] & CM_BLANK));
  }
}