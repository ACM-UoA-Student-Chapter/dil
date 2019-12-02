#include "intern_string.h"
#include <assert.h>

int main(int argc, char const *argv[]) {
  const char *input_1 = "test";
  const char *input_2 = "test 2";

  const char *address_1 = intern_string(input_1);
  const char *address_2 = intern_string(input_2);
  
  assert(address_1 != NULL);
  assert(address_2 != NULL);

  assert(address_1 == intern_string(input_1));
  assert(address_2 == intern_string(input_2));
  return 0;
}
