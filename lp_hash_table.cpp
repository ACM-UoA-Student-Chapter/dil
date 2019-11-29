/*
* Copyright: Copyright Spyros Trifonidis (@spytfyre) 2019.
* License:   $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
* Authors:   Spyros Trifonidis (@spytfyre)
*/
#include "./lp_hash_table_test.h"
#include <assert.h>
#include <iostream>

int main() {
  std::cout << "Hash Table" << std::endl;
  bool res;
  res = test_hash_table();
  assert(res == true);

  res = test_many_key_insertion();
  assert(res == true);

  res = test_memory_location_functionality();
  assert(res == true);

  std::cout << "\tHash table tests passed!" << std::endl;

  std::cout << "All tests passed!" << std::endl;
  return 0;
}
