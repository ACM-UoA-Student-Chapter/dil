/*
 * Copyright:  Copyright Dimakopoulos Theodoros 2019
 * License:    $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
 * Authors:    Dimakopoulos Theodoros
 */
#pragma once
#include "character_map.h"

#include <stdio.h>

// highly technical function
// to understand the output, check out CharacterMap.h
void ch_map_test() {
  char ch[2] = "#";

  for (int c = 0; c < 127; ++c) {
    ch[0] = static_cast<char>(c);
    printf("%3i) map[ '%s' ] = %i\n", c, ch, ch_map[c]);
  }
}