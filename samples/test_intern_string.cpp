#include "intern_string.h"
#include <assert.h>

int main(int argc, char const *argv[]) {
  const char *input = "test";

  const char *address = intern_string(input);

  assert(address == intern_string(input));
  return 0;
}
