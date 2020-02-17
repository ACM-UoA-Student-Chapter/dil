/*
 * Copyright: Copyright J1635 (Orestis Giannoukos) 2019.
 * License:   $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
 * Authors:   J1635 (Orestis Giannoukos)
 */

#include <assert.h>
#include <cstring>
#include <vector>

struct InternedStr {
  char *str;
  size_t len;
};

std::vector<InternedStr> old_strings;

/*
 * This function ensures that only one copy of every string is kept in memory.
 * We pass it a string to be saved. If the string is already saved, we return
 * the old pointer. Otherwise, we save it and return the new pointer. This is
 * called interning a string. Params: string = The string to be interned.
 * Returns:
 *    A read-only pointer to a copy of `string`.
 */
const char *intern_string(const char *string) {
  if (string == NULL)
    return NULL;

  size_t len = strlen(string) + 1;

  // check if the string is stored
  for (size_t i = 0; i < old_strings.size(); i++) {
    if (len == old_strings[i].len && !strcmp(string, old_strings[i].str)) {
      return old_strings[i].str;
    }
  }

  // if it isn't stored create a new
  char *new_str = new char[len];
  assert(new_str != NULL);

  strncpy(new_str, string, len);
  InternedStr new_interned_str = {new_str, len};
  old_strings.push_back(new_interned_str);

  return new_str;
}
