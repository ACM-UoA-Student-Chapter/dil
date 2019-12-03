/*
 * Copyright: Copyright billsioros (Sioros Vasileios) 2019.
 * License:   $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
 * Authors:   billsioros (Sioros Vasileios)
 */

#include "log.hpp"

int main() {
  const char *name = "Vasilis", *surname = "Sioros";

  const int age = 22;

  syntax_error(name, surname, "being", 22, "years old is", age == 22);
  std::printf("\n");

  return 0;
}
