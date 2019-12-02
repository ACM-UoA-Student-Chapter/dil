#include "./lp_hash_table_test.h"
#include <assert.h>
#include <iostream>

int main() {
  std::cout << "Hash Table" << std::endl;
  bool res = test_hash_table();
  assert(res == true);

  res = test_many_key_insertion();
  assert(res == true);

  std::cout << "\tHash table tests passed!" << std::endl;

  std::cout << "All tests passed!" << std::endl;
  return 0;
}
