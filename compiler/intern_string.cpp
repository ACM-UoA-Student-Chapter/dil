#include <string>
#include <vector>

struct InternedStr {
  char *str;
  size_t len;
};

std::vector<InternedStr> old_strings;

const char *intern_string(const char *string) {
  size_t len = strlen(string) + 1;

  // check if the string is stored
  for (size_t i = 0; i < old_strings.size(); i++) {
    if (len == old_strings[i].len && !strcmp(string, old_strings[i].str)) {
      return old_strings[i].str;
    }
  }

  // if it isn't stored create a new
  char *new_str = new char[len];
  strncpy(new_str, string, len);
  InternedStr new_interned_str = {new_str, len};
  old_strings.push_back(new_interned_str);

  return new_str;
}