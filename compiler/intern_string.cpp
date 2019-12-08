#include <string>
#include <vector>
#include <assert.h>

/*
* intern_string is a function which helps keeping only one copy in memory of each 
* specific string.
* intern_string parametre is the string we want to store
* intern_string return value is a pointer
* if we have already used the specific string the function returns the old pointer
* if its a new string we allocate memory and return the new pointer
*/

struct InternedStr {
  char *str;
  size_t len;
};

std::vector<InternedStr> old_strings;

const char *intern_string(const char *string) {
  if (string == NULL) return NULL;

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