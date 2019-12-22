/*
* Copyright: Copyright J1635 (Orestis Giannoukos) 2019.
* License:   $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
* Authors:   J1635 (Orestis Giannoukos)
*/
#include "../../intern_string.h"
#include <assert.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  const char *input_1 = "test";
  const char *input_2 = "test 2";
  const char *input_3 = "";
  const char *input_4 = NULL;
  const char *input_5 = strdup(input_1);

  const char *address_1 = intern_string(input_1);
  const char *address_2 = intern_string(input_2);
  const char *address_3 = intern_string(input_3);
  const char *address_4 = intern_string(input_4);
  
  assert(address_1 != NULL);
  assert(address_2 != NULL);
  assert(address_3 != NULL);
  assert(address_4 == NULL);

  assert(address_1 == intern_string(input_1));
  assert(address_2 == intern_string(input_2));
  assert(address_3 == intern_string(input_3));
  assert(address_1 == intern_string(input_5));
  
  return 0;
}
