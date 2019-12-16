/*
 * Copyright:  Copyright Dimakopoulos Theodoros 2019
 * License:    $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
 * Authors:    Dimakopoulos Theodoros
 */
#pragma once
// The character map (ch_map) is in character_map.h

// Takes THE ch_map and returns the first
// problematic character it found, or -1 otherwise
int ch_map_problematic_character(int *);